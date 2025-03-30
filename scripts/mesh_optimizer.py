from collections import deque
import sys

def get_args(line):
    bracket_open = line.find('(')
    bracket_close = line.rfind(')')
    return [arg.strip() for arg in line[bracket_open+1:bracket_close].split(',') ]

class ModelEntry:
    def __init__(self, line):
        self.raw_name = line
        self.name = line.split(']')[0].split('=')[0].strip().split('[')[-2].split(' ')[-1]

    def __repr__(self):
        return f"Entry(name={self.name})"

class ModelRawEntry(ModelEntry):
    def __init__(self, line):
        super().__init__(line)
        self.data = [line]

    def add(self, line):
        self.data.append(line)

    def __repr__(self):
        return f"ModelRawEntry(name={self.name})"

class ModelVtxEntry(ModelEntry):
    def __init__(self, line):
        super().__init__(line)
        self.vertices = []
    
    def add(self, vertex):
        self.vertices.append(vertex)

    def __repr__(self):
        return f"ModelVtxEntry(name={self.name})"

class UsagePricer:
    def __init__(self, req_tris):
        self._vertices_to_triangle = {}
        self._usage_to_vertices = {}
        self._banned_vertices = set()

        if not req_tris:
            return

        for tri in req_tris:
            for vtx in tri:
                if vtx not in self._vertices_to_triangle:
                    self._vertices_to_triangle[vtx] = set()
                self._vertices_to_triangle[vtx].add(tuple(tri))

        for vtx, tris in self._vertices_to_triangle.items():
            usage = self._tris_cost(tris)
            if usage not in self._usage_to_vertices:
                self._usage_to_vertices[usage] = set()
            self._usage_to_vertices[usage].add(vtx)

    def vtx_to_tris(self, vtx):
        return self._vertices_to_triangle[vtx]

    def add(self, tri):
        # Add vtx for the given triangle and rescale the usage
        for vtx in tri:
            if vtx in self._banned_vertices:
                continue

            if vtx not in self._vertices_to_triangle:
                self._vertices_to_triangle[vtx] = set()

            old_usage = self._tris_cost(self._vertices_to_triangle[vtx])
            self._vertices_to_triangle[vtx].add(tuple(tri))
            new_usage = self._tris_cost(self._vertices_to_triangle[vtx])

            assert new_usage
            assert old_usage != new_usage

            if new_usage not in self._usage_to_vertices:
                self._usage_to_vertices[new_usage] = set()
            self._usage_to_vertices[new_usage].add(vtx)

            if old_usage in self._usage_to_vertices:
                self._usage_to_vertices[old_usage].remove(vtx)
                if not self._usage_to_vertices[old_usage]:
                    del self._usage_to_vertices[old_usage]

    def remove(self, tri):
        # Remove vtx for the given triangle and rescale the usage
        for vtx in tri:
            if vtx not in self._vertices_to_triangle:
                continue
            if vtx in self._banned_vertices:
                continue

            old_usage = self._tris_cost(self._vertices_to_triangle[vtx])
            self._vertices_to_triangle[vtx].remove(tuple(tri))
            if not self._vertices_to_triangle[vtx]:
                del self._vertices_to_triangle[vtx]
                new_usage = 0
            else:
                new_usage = self._tris_cost(self._vertices_to_triangle[vtx])

            assert old_usage != new_usage

            if new_usage != 0:
                if new_usage not in self._usage_to_vertices:
                    self._usage_to_vertices[new_usage] = set()
                self._usage_to_vertices[new_usage].add(vtx)

            self._usage_to_vertices[old_usage].remove(vtx)
            if not self._usage_to_vertices[old_usage]:
                del self._usage_to_vertices[old_usage]

    def ban(self, vtx):
        # Admittedly this is a pretty simplistic approach but it is so simple that it should be fine as is
        affected_triangles = []
        if vtx in self._vertices_to_triangle:
            affected_triangles = list(self._vertices_to_triangle[vtx])

        for tri in affected_triangles:
            self.remove(tri)

        self._banned_vertices.add(vtx)

        for tri in affected_triangles:
            # If all vertices are banned then we can skip this triangle
            if 0 == self._tri_cost(tri):
                continue

            self.add(tri)

    def _tri_cost(self, tri):
        return len([vtx for vtx in tri if vtx not in self._banned_vertices])

    def _tris_cost(self, tris):
        return sum([self._tri_cost(tri) for tri in tris])

    @staticmethod
    def any(s):
        for val in s:
            break
        return val

    def highest_usage(self):
        sorted_keys = sorted(self._usage_to_vertices.items(), reverse=True)
        for highest_usage, highest_usage_vtxs in sorted_keys:
            for highest_usage_vtx in highest_usage_vtxs:
                yield highest_usage, highest_usage_vtx

    def completed(self):
        return not self._usage_to_vertices

class ModelMeshEntry(ModelEntry):
    def __init__(self, line, next_line, model):
        super().__init__(line)
        self._model = model

        vtx_args = get_args(next_line)
        vtx_arg = vtx_args[0]
        vtx_arg_split = vtx_arg.split(' ')

        self._base_vertices_model_name = vtx_arg_split[0]
        self._base_vertices_model_index, self._base_vertices_model_entry = model.find(self._base_vertices_model_name)
        assert '+' == vtx_arg_split[1], "offset must be 0"
        assert '0' == vtx_arg_split[2], "offset must be 0"

        self._vertices = []
        self._vertices_lookup = {}
        self._triangles = []
        self._triangles_lookup = set()

        self._parser_vertices_model_name = None
        self._parser_vbo = []
        for i in range(64):
            self._parser_vbo.append(None)

    def _vtx(self, vertex):
        assert vertex
        if vertex in self._vertices_lookup:
            return self._vertices_lookup[vertex]
        else:
            self._vertices.append(vertex)
            idx = len(self._vertices) - 1
            self._vertices_lookup[vertex] = idx
            return idx

    @staticmethod
    def _tri_trivial(tri):
        return tri[0] == tri[1] or tri[0] == tri[2] or tri[1] == tri[2]

    def _tri(self, tri_indices):
        if self._tri_trivial(tri_indices):
            return

        tri = [ self._vtx(self._parser_vbo[i]) for i in tri_indices ]
        if self._tri_trivial(tri):
            return

        assert tuple(tri) not in self._triangles_lookup, "duplicate triangle found"
        self._triangles.append(tri)
        self._triangles_lookup.add(tuple(tri))

    def add(self, data):
        if 'gsSPVertex' in data:
            args = get_args(data)
            vtx_arg = args[0]
            vtx_arg_split = vtx_arg.split(' ')
            assert '+' == vtx_arg_split[1], "incorrect vtx declaration"

            vertices_model_name = vtx_arg_split[0]
            if self._parser_vertices_model_name != vertices_model_name:
                self._parser_vertices_model_name = vertices_model_name
                if self._base_vertices_model_name == vertices_model_name:
                    self._parser_vertices_model_entry = self._base_vertices_model_entry 
                else:
                    # Consume the entry - those will end up being filled in the base entry model
                    model_index, model_entry = self._model.find(vertices_model_name)
                    model.erase(model_index)
                    self._parser_vertices_model_entry = model_entry

            vtx_offset = int(vtx_arg_split[2])
            num = int(args[1])
            vbo_offset = int(args[2])
            for i in range(num):
                self._parser_vbo[vbo_offset + i] = self._parser_vertices_model_entry.vertices[vtx_offset + i]

            return

        if 'gsSP2Triangles' in data:
            args = get_args(data)
            self._tri([ int(args[0]), int(args[1]), int(args[2]) ])
            self._tri([ int(args[4]), int(args[5]), int(args[6]) ])
            return

        if 'gsSP1Triangle' in data:
            args = get_args(data)
            self._tri([ int(args[0]), int(args[1]), int(args[2]) ])
            return

        if 'gsSPEndDisplayList' in data:
            return
        if '};\n' == data:
            return

        assert False, f"unknown command: {data}"

    def compile(self):
        dl_entry = ModelRawEntry(self.raw_name)

        # Mangle the raw_name - we will likely modify the vertices size so need to just use var sized array instead
        self._base_vertices_model_entry.raw_name = f"""Vtx {self._base_vertices_model_entry.name}[] = {{\n"""

        vtx_entry = self._base_vertices_model_entry

        # For a grand majority of cases "just draw" will be good enough - that's when all vertices fit in the buffer
        if len(self._vertices) < 56:
            # Place vertices as is
            vtx_entry.vertices = self._vertices[:]
            vtx_entry.vertices.append("};\n")

            # Make a basic dl that just draws the vertices
            dl_entry.data.append(f"\tgsSPVertex({vtx_entry.name}, {len(self._vertices)}, 0),\n")
            triangles = deque(self._triangles)
            while triangles:
                if 1 == len(triangles):
                    tri = triangles.popleft()
                    dl_entry.data.append(f"\tgsSP1Triangle({tri[0]}, {tri[1]}, {tri[2]}, 0),\n")
                else:
                    tri0 = triangles.popleft()
                    tri1 = triangles.popleft()
                    dl_entry.data.append(f"\tgsSP2Triangles({tri0[0]}, {tri0[1]}, {tri0[2]}, 0, {tri1[0]}, {tri1[1]}, {tri1[2]}, 0),\n")
        else:
            # This is a primitive greedy algorithm for drawing vertices
            loaded_vertices = {}
            loaded_vertex_buffer = []
            rendered_triangles = []
            start_offset = 0
            total_pricer = UsagePricer(self._triangles)
            vtx_entry.vertices = []

            while True:
                if total_pricer.completed() or len(loaded_vertices) >= 54:
                    # Flush vertices
                    cur_vtx_start_offset = start_offset
                    cur_vtx_load_amount = len(loaded_vertex_buffer)
                    for vertex in loaded_vertex_buffer:
                        vtx_entry.vertices.append(vertex)
                        start_offset += 1

                    dl_entry.data.append(f"\tgsSPVertex({vtx_entry.name} + {cur_vtx_start_offset}, {cur_vtx_load_amount}, 0),\n")
                    triangles = deque(rendered_triangles)
                    while triangles:
                        if 1 == len(triangles):
                            tri = triangles.popleft()
                            dl_entry.data.append(f"\tgsSP1Triangle({tri[0]}, {tri[1]}, {tri[2]}, 0),\n")
                        else:
                            tri0 = triangles.popleft()
                            tri1 = triangles.popleft()
                            dl_entry.data.append(f"\tgsSP2Triangles({tri0[0]}, {tri0[1]}, {tri0[2]}, 0, {tri1[0]}, {tri1[1]}, {tri1[2]}, 0),\n")

                    loaded_vertices = {}
                    loaded_vertex_buffer = []
                    rendered_triangles = []

                if total_pricer.completed():
                    break

                highest_usage, highest_usage_vtx = next(total_pricer.highest_usage())
                loaded_vertex_buffer.append(self._vertices[highest_usage_vtx])
                loaded_vertices[highest_usage_vtx] = len(loaded_vertex_buffer) - 1

                candidate_to_load_pricer = UsagePricer(None)
                candidate_vtxs = set()
                candidate_tris = set()
                while True:
                    # print(f"{loaded_vertices}")
                    candidate_to_load_pricer.ban(highest_usage_vtx)
                    highest_usage_vtx_triangles = list(total_pricer.vtx_to_tris(highest_usage_vtx))
                    for tri in highest_usage_vtx_triangles:
                        loaded_tri = [ loaded_vertices.get(vtx) for vtx in tri ]
                        # print(f"{tri} -> {loaded_tri}")
                        if not None in loaded_tri:
                            # print(f"render {tri} as {loaded_tri}")
                            rendered_triangles.append(loaded_tri)
                            candidate_to_load_pricer.remove(tri)
                            total_pricer.remove(tri)
                            continue
                    
                        for i, loaded_idx in enumerate(loaded_tri):
                            if loaded_idx is not None:
                                continue

                            candidate_vtx = tri[i]
                            if candidate_vtx in candidate_vtxs:
                                continue

                            candidate_vtxs.add(candidate_vtx)
                            candidate_vtx_tris = total_pricer.vtx_to_tris(candidate_vtx)
                            for candidate_tri in candidate_vtx_tris:
                                if tuple(candidate_tri) in candidate_tris:
                                    continue

                                candidate_tris.add(tuple(candidate_tri))
                                candidate_to_load_pricer.add(candidate_tri)

                    if candidate_to_load_pricer.completed() or len(loaded_vertices) == 56:
                        break

                    highest_usage, highest_usage_vtx = next(candidate_to_load_pricer.highest_usage())
                    loaded_vertex_buffer.append(self._vertices[highest_usage_vtx])
                    loaded_vertices[highest_usage_vtx] = len(loaded_vertex_buffer) - 1

            vtx_entry.vertices.append("};\n")

        dl_entry.data.append(f"\tgsSPEndDisplayListHint(4),\n")
        dl_entry.data.append("};\n")
        # this function is not reentrant so make sure we will crash next time we this
        self._base_vertices_model_entry = None
        return dl_entry

    def __repr__(self):
        return f"ModelRenderEntry(name={self.name})"

class Model:
    def __init__(self):
        self.entries = []
        self._entries_lookup = {}
    
    def add(self, entry):
        self.entries.append(entry)
        self._entries_lookup[entry.name] = len(self.entries) - 1

    def find(self, line):
        idx = self._entries_lookup[line]
        return idx, self.entries[idx]

    def erase(self, num):
        self.entries[num] = None

def peek_line(f):
    pos = f.tell()
    line = f.readline()
    f.seek(pos)
    return line

def load_model(model_path):
    model = Model()
    curr_entry: ModelEntry = None
    with open(model_path, "r") as f_model:
        while True:
            line = f_model.readline()
            if not line:
                break

            if line == '\n':
                curr_entry = None
                continue
            else:
                if not curr_entry:
                    assert '] = {' in line
                    if 'Vtx' in line:
                        curr_entry = ModelVtxEntry(line)
                    else:
                        curr_entry = ModelRawEntry(line)

                    model.add(curr_entry)
                else:
                    curr_entry.add(line)

    return model

def optimize_model(model):
    for model_entry_idx in range(len(model.entries)):
        old_entry = model.entries[model_entry_idx]
        if not isinstance(old_entry, ModelRawEntry):
            continue
        if not 'Gfx' in old_entry.data[0] or not 'gsSPVertex' in old_entry.data[1]:
            continue

        entry = ModelMeshEntry(old_entry.data[0], old_entry.data[1], model)
        for i in range(1, len(old_entry.data)):
            entry.add(old_entry.data[i])

        model.entries[model_entry_idx] = entry.compile()

def serialize_model(model, path):
    with open(path, "w") as f_model:
        model.entries = [entry for entry in model.entries if entry]

        for entry in model.entries:
            if isinstance(entry, ModelVtxEntry):
                f_model.write(entry.raw_name)
                for line in entry.vertices:
                    f_model.write(line)
            else:
                for line in entry.data:
                    f_model.write(line)

            f_model.write('\n')

if '__main__' in __name__:
    path = f"{sys.argv[1]}/visual"
    slash_idx = sys.argv[1].rfind('/')
    name = sys.argv[1][slash_idx+1:]

    header_path = f"{path}/header_lvl.inc.h"
    model_path = f"{path}/model_lvl.inc.c"   
    model_patched_path = f"{path}/model_lvlopt.inc.c"
 
    model = load_model(model_path)
    optimize_model(model)
    serialize_model(model, model_patched_path)

    a = 0
