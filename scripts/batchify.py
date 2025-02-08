import os
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
                return f"{super().__str__()}GEO_LVL_BATCH_TRANSLATE_ROTATE({self.dl_reference.layer}, {translations}, {rotations}, {self.dl_reference.name}),"
            else:
                if not self.dl_reference:
                    return f"{super().__str__()}GEO_LVL_TRANSLATE_NODE(LAYER_OPAQUE, {translations}),"
                else:
                    return f"{super().__str__()}GEO_LVL_BATCH_TRANSLATE_NODE({self.dl_reference.layer}, {translations}, {self.dl_reference.name}),"

class ModelEntry:
    def __init__(self, decl, data = None, batched = False):
        self.decl = decl
        end = decl.rfind('] = {')
        end = decl.rfind('[', 0, end)
        start = decl.rfind(' ', 0, end)
        self.name = decl[start+1:end].strip()
        assert not '[' in self.name
        assert not ']' in self.name

        self.data = data
        if not self.data:
            self.data = []

        self.batched = batched

    def __repr__(self):
        return f"ModelEntry({self.name}, {self.data})"

class Model:
    def __init__(self):
        self.entries: list[ModelEntry] = []

def peek_line(f):
    pos = f.tell()
    line = f.readline()
    f.seek(pos)
    return line

def get_args(line):
    bracket_open = line.find('(')
    bracket_close = line.rfind(')')
    return [arg.replace('(s16)', '(f32)').strip() for arg in line[bracket_open+1:bracket_close].split(',') ]

def parse_geo(geo_path):
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

        def rotate(self, layer, rx, ry, rz, name):
            dl_ref = DisplayListReference(layer, name)
            # For purposes of culling non subrendered objects must have a translation
            self._make_render_object(('0', '0', '0'), (rx, ry, rz), dl_ref)

        def translate_empty(self, layer, x, y, z):
            self._make_render_object((x, y, z), None, None)

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
                if 'GEO_ROTATION_NODE_WITH_DL(' in line:
                    area_geolayout_parser.rotate(*get_args(line))
                    continue
                if 'GEO_TRANSLATE_NODE(' in line:
                    translate_line = line
                    line = peek_line(f_geo)
                    if 'GEO_OPEN_NODE(' in line:
                        area_geolayout_parser.translate_empty(*get_args(translate_line))

                    continue
                if 'GEO_RETURN(' in line:
                    curr_geolayout = None
                    area_geolayout_parser = None
                    continue
                if 'GEO_ASM(' in line:
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
    curr_entry: ModelEntry = None
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
                curr_entry = None
                continue

            if '] = {' in line:
                assert curr_entry is None
                if curr_want_align:
                    line = 'ALIGNED8 ' + line
                    curr_want_align = False

                curr_entry = ModelEntry(line)
                model.entries.append(curr_entry)
            else:
                curr_entry.data.append(line)

    return model

class BatchedTexture:
    def __init__(self, name: str, idx: str):
        self.name = name
        self.idx = idx

    def __repr__(self):
        return f"BatchedTexture({self.name}, {self.idx})"

def append_dl(data_from, data_to):
    # dl data at end looks like gsSPEndDisplayList(); }; so we need to strip the last two lines
    assert '};\n' in data_to.data[-1]
    del data_to.data[-1]
    assert 'gsSPEndDisplayList' in data_to.data[-1]
    del data_to.data[-1]
    # Now we can safely just append the data
    data_to.data.extend(data_from.data)

# Handles requests to convert dl referenced name to its model data
class ModelIndexer:
    def __init__(self, model):
        self._model = model
        self._model_indexed = self._indexize(model)

    def lookup(self, name):
        idx = self._model_indexed[name]
        return idx, self._model.entries[idx]

    def delete(self, name, idx = None):
        idx = idx if idx else self._model_indexed[name]
        self._model.entries[idx] = None
        del self._model_indexed[name]

    def insert(self, new_data):
        self._model_indexed[new_data.name] = len(self._model.entries)
        self._model.entries.append(new_data)

    @staticmethod
    def _indexize(model):
        indices = {}
        for i, entry in enumerate(model.entries):
            indices[entry.name] = i

        return indices

# Handles deduplication of materials for same dls
class MatDeduper:
    def __init__(self, model_indexer):
        self._dedup_data_to_mat = {}
        self._dedup_mat_to_real_mat = {}
        self._model_indexer = model_indexer

    def dedup(self, mat_dl):
        if mat_dl in self._dedup_mat_to_real_mat:
            return self._dedup_mat_to_real_mat[mat_dl]

        mat_dl_idx, mat_dl_entry = self._model_indexer.lookup(mat_dl)
        # For hash lookup purposes we have to convert to tuple
        # Mats are currently assumed to never change so this should be safe
        mat_data = tuple(mat_dl_entry.data)
        if mat_data in self._dedup_data_to_mat:
            # Duplicate definition, delete the current mat and link to the "real" one (will be done in batch step)
            mat_real_dl = self._dedup_data_to_mat[mat_data]
            self._dedup_mat_to_real_mat[mat_dl] = mat_real_dl
            self._model_indexer.delete(mat_dl, mat_dl_idx)
            self._model_indexer.delete(f"mat_revert_{mat_dl[4:]}")
            return mat_real_dl
        else:
            # It is the first time we see this material, register and return itself
            self._dedup_data_to_mat[mat_data] = mat_dl
            self._dedup_mat_to_real_mat[mat_dl] = mat_dl
            return mat_dl

# Generic variant of 'MatDeduper' that perform dedupes without assuming mat structure
class ContentDeduper:
    def __init__(self):
        self._dedup_data_to_mat = {}
        self._dedup_mat_to_real_mat = {}
        self.deduped_names = {}

    def dedup(self, mat_dl_entry):
        mat_dl = mat_dl_entry.name
        if mat_dl in self._dedup_mat_to_real_mat:
            return self._dedup_mat_to_real_mat[mat_dl]

        mat_data = tuple(mat_dl_entry.data)
        if mat_data in self._dedup_data_to_mat:
            mat_real_dl = self._dedup_data_to_mat[mat_data]
            self._dedup_mat_to_real_mat[mat_dl] = mat_real_dl
            self.deduped_names[mat_dl] = mat_real_dl
            return mat_real_dl
        else:
            self._dedup_data_to_mat[mat_data] = mat_dl
            self._dedup_mat_to_real_mat[mat_dl] = mat_dl
            return mat_dl

    def keep(self, mat_dl_entry):
        return mat_dl_entry.name == self.dedup(mat_dl_entry)

# Tracks the current index for batched textures for a given layer
class BatchIndexAllocator:
    def __init__(self, batches, batches_indexed, layer, repeating_names):
        self._batches = batches
        self._batches_indexed = batches_indexed
        self._layer = layer
        self._repeating_names = repeating_names

    def allocate(self, dl, entry):
        idx = self._batches_indexed.get(dl)
        if idx is None:
            idx = len(self._batches)
            self._batches_indexed[dl] = idx

            # Stripping the mat_ prefix
            name = dl[4:]
            tex_name = self._get_tex_name(name, entry)
            batch_idx = self._make_batch_name(self._layer, tex_name)
            batch_idx_unique = self._uniquealize_tex_name(batch_idx)
            self._batches.append(BatchedTexture(name, batch_idx_unique))

        return idx

    def _get_tex_name(self, name, entry):
        tex_name = None
        for line in entry.data:
            if 'gsDPSetTextureImage(' in line:
                tex_name = get_args(line)[3]
                break
 
        if not tex_name:
            tex_name = name

        return tex_name

    def _make_batch_name(self, layer, tex_name):
        return f"LVL_BATCH_{layer}_{tex_name.upper()}"

    def _uniquealize_tex_name(self, val):
        if val in self._repeating_names:
            self._repeating_names[val] += 1
            return f"{val}_{self._repeating_names[val]}"
        else:
            self._repeating_names[val] = 0
            return val

    def get_batch(self, idx):
        return self._batches[idx]

class LayeredBatchIndexAllocator:
    def __init__(self, layered_batches):
        self._layered_batches = layered_batches
        self._layered_batches_indexed = {}
        self._layered_repeating_names = {}

    def get_batch_allocator(self, layer):
        batches = self._layered_batches.setdefault(layer, [])
        batches_indexed = self._layered_batches_indexed.setdefault(layer, {})
        repeating_names = self._layered_repeating_names.setdefault(layer, {})
        return BatchIndexAllocator(batches, batches_indexed, layer, repeating_names)

# This procedure parses dls and converts them into batched textures
# It also deduplicates the materials, currently on dl definition level
def batchify(geo, model, header):
    # The main product of this function is the layered_batches
    layered_batches = {}

    model_indexer = ModelIndexer(model)
    layered_batch_index_allocator = LayeredBatchIndexAllocator(layered_batches)
    mat_deduper = MatDeduper(model_indexer)

    for content in geo.contents:
        if content.batched:
            continue

        # Currently only render nodes are batched, so we can safely cast
        node: RenderNode = content

        curr_batched_data: list[str] = []
        dl_ref = node.dl_reference
        if not dl_ref:
            continue

        model_to_convert_idx, model_to_convert = model_indexer.lookup(dl_ref.name)
        if model_to_convert.batched:
            continue

        batch_allocator = layered_batch_index_allocator.get_batch_allocator(dl_ref.layer)

        curr_seen_batches = {}
        curr_attached_batch_idx = None        
        for data in model_to_convert.data:
            if 'gsSPDisplayList(' in data:
                dl = get_args(data)[0]
                if dl.startswith('mat_'):
                    mat_dl = dl
                    revert = mat_dl.startswith('mat_revert_')
                    if revert:
                        continue

                    mat_real_dl = mat_deduper.dedup(mat_dl)
                    _, mat_entry = model_indexer.lookup(mat_real_dl)
                    curr_attached_batch_idx = batch_allocator.allocate(mat_real_dl, mat_entry)
                else:
                    assert curr_attached_batch_idx is not None
                    if curr_attached_batch_idx not in curr_seen_batches:
                        curr_seen_batches[curr_attached_batch_idx] = dl
                        batch = batch_allocator.get_batch(curr_attached_batch_idx)
                        curr_batched_data.append(f"\tBATCH_DL({batch.idx}, {dl}),\n")
                    else:
                        # Append the dl to the batch that has been already seen, then clear it out
                        seen_dl = curr_seen_batches[curr_attached_batch_idx]
                        dl_idx, dl_entry = model_indexer.lookup(dl)
                        append_dl(dl_entry, model_indexer.lookup(seen_dl)[1])
                        model_indexer.delete(dl, dl_idx)

                continue
            if 'gsSPEndDisplayList()' in data or 'gsDPPipeSync(' in data:
                break

            raise Exception(f"Unknown dl: {data}")

        # Delete the old dl entry and link in new batched data
        model_indexer.delete(dl_ref.name, model_to_convert_idx)

        curr_batched_data.append(f"\tBATCH_END(),\n")
        curr_batched_data.append('};\n')

        batched_decl = f'u32 {model_to_convert.name}[] = {{\n'
        new_data = ModelEntry(batched_decl, curr_batched_data, True)
        model_indexer.insert(new_data)

        # Patch the header will the new name - switch Gfx for u32
        replaced = False
        for i, line in enumerate(header):
            if model_to_convert.name + '[' in line:
                assert not replaced    
                header[i] = line.replace('Gfx', 'u32')
                replaced = True

        assert replaced

    return layered_batches

def deduce_level_name(name):
    idx = name.find('_')
    return name[0:idx]

def serialize_geo(geo, area, path, has_flipbooks, has_skybox):
    lvl_name = deduce_level_name(geo.name)
    with open(path, "w") as f_geo:
        f_geo.write('''#include "src/game/envfx_snow.h"\n\n''')
        f_geo.write(f'''const GeoLayout {geo.name} = {{\n''')
        if has_flipbooks:
            f_geo.write(f'''\tGEO_BATCH_NODE_START_WITH_FLIPBOOK(batch_lvl_dls_{lvl_name}, {lvl_name}_flipbooks),\n''')
        else:
            f_geo.write(f'''\tGEO_BATCH_NODE_START(batch_lvl_dls_{lvl_name}),\n''')

        f_geo.write('''\tGEO_OPEN_NODE(),\n''')
        if has_skybox:
            f_geo.write('''\t\tGEO_ASM(0, geo_render_backdrop),\n''')    

        for content in geo.contents:
            f_geo.write(f"{content}\n")

        f_geo.write('''\tGEO_RETURN(),\n''')
        f_geo.write('''};\n\n''')

        f_geo.write(f'''const GeoLayout {area.name} = {{\n''')
        for content in area.contents:
            f_geo.write(content)

        f_geo.write('''};\n\n''')

def serialize_header(header, layered_batches, replacements, path, has_flipbooks):
    with open(path, "w") as f_header:
        for data in header:
            if data.startswith('extern Gfx mat_'):
                continue

            f_header.write(data)

        name = None
        for layer, batches in layered_batches.items():
            for i, batch in enumerate(batches):
                f_header.write(f"#define {batch.idx} {i}\n")

            name = deduce_level_name(batches[0].name)

        f_header.write(f'extern struct BatchLevelDisplayLists batch_lvl_dls_{name}[LAYER_COUNT];\n')

        for k, v in replacements.items():
            f_header.write(f"#define {k} {v}\n")

        if has_flipbooks:
            f_header.write(f'extern const struct FlipbookLayer {name}_flipbooks[LAYER_COUNT];\n')

def serialize_model(model, layered_batches, path):
    replacemenets = {}
    with open(path, "w") as f_model:
        model.entries = [entry for entry in model.entries if entry]
        for _ in range(10):
            content_deduper = ContentDeduper()
            model.entries = [entry for entry in model.entries if content_deduper.keep(entry)]
            if not content_deduper.deduped_names:
                break

            replacemenets.update(content_deduper.deduped_names)

            # We are not relying on 'defines' here for sole purpose of deduping again on the next cycle
            # Current deduper is very primitive - it cannot known about the defined names - string must match exactly
            for k, v in content_deduper.deduped_names.items():
                for entry in model.entries:
                    for i, line in enumerate(entry.data):
                        entry.data[i] = line.replace(k, v)

        for entry in model.entries:
            mark_static = False
            f_model.write(("UNUSED static " if mark_static else "") + entry.decl)
            for line in entry.data:
                f_model.write(line.replace("gsSPEndDisplayList()", "gsSPEndDisplayListHint(4)"))

            f_model.write('\n')

        name = None
        for layer, batches in layered_batches.items():
            f_model.write(f"static struct BatchDisplayLists batch_lvl_dls_{layer}[] = {{\n")
            for batch in batches:
                f_model.write(f"\t[{batch.idx}] = {{ mat_{batch.name}, mat_revert_{batch.name}, DL_HINT(mat_{batch.name}), DL_HINT(mat_revert_{batch.name}), }},\n")
            f_model.write('};\n\n')
            name = deduce_level_name(batches[0].name)

        f_model.write(f'struct BatchLevelDisplayLists batch_lvl_dls_{name}[LAYER_COUNT] = {{\n')
        for layer, batches in layered_batches.items():
            f_model.write(f"\t[ {layer} ] = {{ {len(batches)}, batch_lvl_dls_{layer} }},\n")
        f_model.write('};\n')

    return replacemenets

if '__main__' in __name__:
    path = f"{sys.argv[1]}/visual"
    slash_idx = sys.argv[1].rfind('/')
    name = sys.argv[1][slash_idx+1:]
    geo_path = f"{path}/geo.inc.c"
    header_path = f"{path}/header.inc.h"
    model_path = f"{path}/model.inc.c"
    
    geo, area = parse_geo(geo_path)
    header = parse_header(header_path)
    model = parse_model(model_path)

    layered_batches = batchify(geo, model, header)

    geo_patched_path = f"{path}/geo_lvl.inc.c"
    header_patched_path = f"{path}/header_lvl.inc.h"
    model_patched_path = f"{path}/model_lvl.inc.c"

    has_flipbooks = os.path.exists(f"{sys.argv[1]}/flipbook.inc.c")
    has_skybox = os.path.exists(f"{sys.argv[1]}/{name}_skybox")

    serialize_geo(geo, area, geo_patched_path, has_flipbooks, has_skybox)
    replacements = serialize_model(model, layered_batches, model_patched_path)
    serialize_header(header, layered_batches, replacements, header_patched_path, has_flipbooks)
