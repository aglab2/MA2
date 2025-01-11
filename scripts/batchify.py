import sys

class GeoLayout:
    def __init__(self, name):
        self.name = name
        self.contents = []
    
    def __repr__(self):
        return f"GeoLayout({self.name}, {self.contents})"

class DisplayListReference:
    def __init__(self, layer, name):
        self.layer = layer
        self.name = name

    def __repr__(self):
        return f"DisplayListReference({self.layer}, {self.name})"

class GeoNode:
    def __init__(self, subrender):
        self.batched = True
        self.subrender = subrender
    
    def __str__(self):
        return "\t" * (2 + self.subrender)

class SimpleNode(GeoNode):
    def __init__(self, name, subrender):
        super().__init__(subrender)
        self.name = name

    def __repr__(self):
        return f"SimpleNode({self.name})"

    def __str__(self):
        return f"{super().__str__()}{self.name}(),"

class RenderNode(GeoNode):
    def __init__(self, translation, rotation, dl, subrender):
        super().__init__(subrender)
        self.translation = translation
        self.rotation = rotation
        self.dl_reference = dl
        self.subrender = subrender
        self.batched = False

    def __repr__(self):
        return f"RenderNode({self.translation}, {self.rotation}, {self.dl_reference}, {self.subrender})"

    def __str__(self):
        translations = ', '.join(self.translation) if self.translation else None
        rotations = ', '.join(self.rotation) if self.rotation else None
        if self.subrender:
            if translations and rotations:
                return f"{super().__str__()}GEO_BATCH_TRANSLATE_ROTATE({self.dl_reference.layer}, {translations}, {rotations}, {self.dl_reference.name}),"
            if translations and not rotations:
                return f"{super().__str__()}GEO_BATCH_TRANSLATE({self.dl_reference.layer}, {translations}, {self.dl_reference.name}),"
            if not translations and rotations:
                return f"{super().__str__()}GEO_BATCH_ROTATE({self.dl_reference.layer}, {rotations}, {self.dl_reference.name}),"
            if not translations and not rotations:
                return f"{super().__str__()}GEO_BATCH({self.dl_reference.layer}, {self.dl_reference.name}),"
        else:
            assert translations
            if rotations:
                return f"{super().__str__()}GEO_LVL_TRANSLATE_ROTATE({self.dl_reference.layer}, {translations}, {rotations}, {self.dl_reference.name}),"
            else:
                return f"{super().__str__()}GEO_LVL_TRANSLATE_NODE({self.dl_reference.layer}, {translations}, {self.dl_reference.name}),"

class ModelData:
    def __init__(self, decl, data = None, batched = False):
        self.decl = decl
        end = decl.rfind('] = {')
        start = decl.rfind(' ', 0, end)
        self.name = decl[start+1:end-1].strip()
        self.data = data
        if not self.data:
            self.data = []

        self.batched = batched

    def __repr__(self):
        return f"ModelData({self.name}, {self.data})"

class Model:
    def __init__(self):
        self.data: list[ModelData] = []

def parse_geo(geo_path):
    def get_args(line):
        bracket_open = line.find('(')
        bracket_close = line.rfind(')')
        return [arg.replace('(s16)', '(f32)').strip() for arg in line[bracket_open+1:bracket_close].split(',') ]

    class AreaGeoLayoutParser:
        def __init__(self, geolayout):
            self._geolayout: GeoLayout = geolayout
            self._subrender = 0

        def _make_render_object(self, translation, rotation, dl_ref):
            self._geolayout.contents.append(RenderNode(translation, rotation, dl_ref, self._subrender))

        def _make_generic_node(self, name):
            self._geolayout.contents.append(SimpleNode(name, self._subrender))

        # This special cases handle nested translated render objects, with one indirection layer
        def enter(self):
            self._make_generic_node("GEO_OPEN_NODE")
            self._subrender += 1

        def exit(self):
            self._subrender -= 1
            self._make_generic_node("GEO_CLOSE_NODE")

        def dl(self, layer, name):
            dl_ref = DisplayListReference(layer, name)
            # For purposes of culling non subrendered objects must have a translation
            # It is not a gigantic perf cost because those cases barely ever appear
            translation = None if self._subrender else ('0', '0', '0')
            self._make_render_object(translation, None, dl_ref)

        def translate(self, layer, x, y, z, name):
            dl_ref = DisplayListReference(layer, name)
            self._make_render_object((x, y, z), None, dl_ref)

        def translate_rotate(self, layer, x, y, z, rx, ry, rz, name):
            dl_ref = DisplayListReference(layer, name)
            self._make_render_object((x, y, z), (rx, ry, rz), dl_ref)

    geo: GeoLayout = None
    area: GeoLayout = None

    with open(geo_path, "r") as f_geo:
        curr_geolayout: GeoLayout = None
        area_geolayout_parser: AreaGeoLayoutParser = None
        while True:
            line = f_geo.readline()
            if not line:
                break

            if curr_geolayout is None:
                # Search for the first geolayout
                if not 'const GeoLayout' in line:
                    continue

                name = line.split(' ')[2].strip()
                curr_geolayout = GeoLayout(name)
                if '_geo' in name:
                    area_geolayout_parser = AreaGeoLayoutParser(curr_geolayout)
                    geo = curr_geolayout
                    f_geo.readline() #	GEO_NODE_START(),
                    f_geo.readline() # 	GEO_OPEN_NODE(),
                else:
                    area = curr_geolayout
            else:
                if not area_geolayout_parser:
                    # just dump entries for area geolayout
                    if not 'GEO_' in line:
                        curr_geolayout = None
                        continue

                    curr_geolayout.contents.append(line)
                    continue

                if 'GEO_OPEN_NODE()' in line:
                    area_geolayout_parser.enter()
                    continue
                if 'GEO_CLOSE_NODE()' in line:
                    area_geolayout_parser.exit()
                    continue
                if 'GEO_DISPLAY_LIST(' in line:
                    area_geolayout_parser.dl(*get_args(line))
                    continue
                if 'GEO_TRANSLATE_NODE_WITH_DL(' in line:
                    area_geolayout_parser.translate(*get_args(line))
                    continue
                if 'GEO_TRANSLATE_ROTATE_WITH_DL(' in line:
                    area_geolayout_parser.translate_rotate(*get_args(line))
                    continue
                if 'GEO_RETURN(' in line:
                    curr_geolayout = None
                    area_geolayout_parser = None
                    continue

                raise Exception(f"Unknown geo node: {line}")

    return geo, area

def parse_header(header_path):
    header = []
    with open(header_path, "r") as f_header:
        while True:
            line = f_header.readline()
            if not line:
                break

            header.append(line)

    return header

def parse_model(model_path):
    model = Model()
    curr_data: ModelData = None
    curr_want_align = False
    with open(model_path, "r") as f_model:
        while True:
            line = f_model.readline()
            if not line:
                break

            if 'aligner[] = {' in line:
                curr_want_align = True
                continue
        
            if line == '\n':
                curr_data = None
                continue

            if '] = {' in line:
                assert curr_data is None
                if curr_want_align:
                    line = 'ALIGNED8 ' + line
                    curr_want_align = False

                curr_data = ModelData(line)
                model.data.append(curr_data)
            else:
                curr_data.data.append(line)

    return model

def indexize_model(model):
    indices = {}
    for i, data in enumerate(model.data):
        indices[data.name] = i

    return indices

class BatchedTexture:
    def __init__(self, layer: str, name: str):
        self.name = name
        self.idx = f"LVL_BATCH_{layer}_{name.upper()}"

    def __repr__(self):
        return f"BatchedTexture({self.name}, {self.idx})"

def batchify(geo, model, header):
    def get_args(line):
        bracket_open = line.find('(')
        bracket_close = line.rfind(')')
        return [arg.strip() for arg in line[bracket_open+1:bracket_close].split(',') ]

    model_indexed = indexize_model(model)
    layered_batches = {}
    layered_batches_indexed = {}

    for content in geo.contents:
        if content.batched:
            continue

        # Currently only render nodes are batched, so we can safely cast
        node: RenderNode = content

        curr_batched_data: list[str] = []
        dl_ref = node.dl_reference
        model_to_convert_idx = model_indexed[dl_ref.name]
        model_to_convert = model.data[model_to_convert_idx]
        if model_to_convert.batched:
            continue

        layer = dl_ref.layer
        batches = layered_batches.setdefault(layer, [])
        batches_indexed = layered_batches_indexed.setdefault(layer, {})
        for data in model_to_convert.data:
            if 'gsSPDisplayList(' in data:
                dl = get_args(data)[0]
                if dl.startswith('mat_'):
                    revert = dl.startswith('mat_revert_')
                    if revert:
                        continue

                    idx = batches_indexed.get(dl)
                    if idx is None:
                        idx = len(batches)
                        batches_indexed[dl] = idx
                        # Stripping the mat_ prefix
                        batches.append(BatchedTexture(layer, dl[4:]))

                    batch = batches[idx]
                    curr_batched_data.append(f"\tBATCH_SET_TEXTURE({batch.idx}),\n")
                else:
                    curr_batched_data.append(f"\tBATCH_LOAD_DL({dl}),\n")

                continue
            if 'gsSPEndDisplayList()' in data or 'gsDPPipeSync(' in data:
                break

            raise Exception(f"Unknown dl: {data}")

        # Delete the old dl entry and link in new batched data
        model.data[model_to_convert_idx] = None
        del model_indexed[dl_ref.name]

        curr_batched_data.append(f"\tBATCH_END(),\n")
        curr_batched_data.append('};\n')

        batched_decl = f'u32 {model_to_convert.name}[] = {{\n'
        new_data = ModelData(batched_decl, curr_batched_data, True)
        model_indexed[new_data.name] = len(model.data)
        model.data.append(new_data)

        # Patch the header will the new name - switch Gfx for u32
        replaced = False
        for i, line in enumerate(header):
            if model_to_convert.name + '[' in line:
                assert not replaced    
                header[i] = line.replace('Gfx', 'u32')
                replaced = True

        assert replaced

    return layered_batches

def serialize_geo(geo, area, path):
    with open(path, "w") as f_geo:
        f_geo.write('''#include "src/game/envfx_snow.h"\n\n''')
        f_geo.write(f'''const GeoLayout {geo.name}[] = {{\n''')
        f_geo.write('''\tGEO_NODE_START(),\n''')
        f_geo.write('''\tGEO_OPEN_NODE(),\n''')
        for content in geo.contents:
            f_geo.write(f"{content}\n")

        f_geo.write('''\tGEO_RETURN(),\n''')
        f_geo.write('''};\n\n''')

        f_geo.write(f'''const GeoLayout {area.name}[] = {{\n''')
        for content in area.contents:
            f_geo.write(content)

def deduce_level_name(name):
    idx = name.find('_')
    return name[0:idx]

def serialize_header(header, layered_batches, path):
    with open(path, "w") as f_header:
        for data in header:
            f_header.write(data)

        name = None
        for layer, batches in layered_batches.items():
            for i, batch in enumerate(batches):
                f_header.write(f"#define {batch.idx} {i}\n")

            name = deduce_level_name(batches[0].name)

        f_header.write(f'extern struct BatchDisplayLists* batch_descs_{name}[LAYER_COUNT];\n')

def serialize_model(model, layered_batches, path):
    with open(path, "w") as f_model:
        for data in model.data:
            if data:
                f_model.write(data.decl)
                for line in data.data:
                    f_model.write(line)

                f_model.write('\n')

        name = None
        for layer, batches in layered_batches.items():
            f_model.write(f"static struct BatchDisplayLists batch_desc_{layer}[] = {{\n")
            for batch in batches:
                f_model.write(f"\t{{ {{mat_{batch.name}}}, {{mat_revert{batch.name}}} }},\n")
            f_model.write('};\n\n')
            name = deduce_level_name(batches[0].name)

        f_model.write(f'struct BatchDisplayLists* batch_descs_{name}[LAYER_COUNT] = {{\n')
        for layer, batches in layered_batches.items():
            f_model.write(f"\t[ {layer} ] = batch_desc_{layer},\n")
        f_model.write('};\n')

if '__main__' in __name__:
    path = sys.argv[1]
    geo_path = f"{path}/geo.inc.c"
    header_path = f"{path}/header.inc.h"
    model_path = f"{path}/model.inc.c"
    
    geo, area = parse_geo(geo_path)
    header = parse_header(header_path)
    model = parse_model(model_path)

    layered_batches = batchify(geo, model, header)

    geo_patched_path = f"{path}/geo_patch.inc.c"
    header_patched_path = f"{path}/header_patch.inc.h"
    model_patched_path = f"{path}/model_patch.inc.c"

    serialize_geo(geo, area, geo_patched_path)
    serialize_header(header, layered_batches, header_patched_path)
    serialize_model(model, layered_batches, model_patched_path)
