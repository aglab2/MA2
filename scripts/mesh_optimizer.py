from collections import deque
import sys

HAS_EX3_COMMANDS = False

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

class ModelRawOptEntry(ModelEntry):
    def __init__(self, line, optvtx):
        super().__init__(line)
        self.data = [line]
        self.optvtx = optvtx

    def add(self, line):
        self.data.append(line)

    def __repr__(self):
        return f"ModelRawOptEntry(name={self.name})"

class ModelVtxEntry(ModelEntry):
    def __init__(self, line):
        super().__init__(line)
        self.vertices = []
    
    def add(self, vertex):
        self.vertices.append(vertex)

    def __repr__(self):
        return f"ModelVtxEntry(name={self.name})"

class UsagePricer:
    def __init__(self, req_tris, loaded_vertices, banned_vertices):
        self._vertices_to_triangle = {}
        self._usage_to_vertices = {}
        self._banned_vertices = banned_vertices
        self._loaded_vertices = loaded_vertices

        if not req_tris:
            return

        for tri in req_tris:
            for vtx in tri:
                if vtx in self._banned_vertices:
                    continue

                if vtx not in self._vertices_to_triangle:
                    self._vertices_to_triangle[vtx] = set()
                self._vertices_to_triangle[vtx].add(tri)

        for vtx, tris in self._vertices_to_triangle.items():
            usage = self._tris_cost(tris)
            if usage not in self._usage_to_vertices:
                self._usage_to_vertices[usage] = set()
            self._usage_to_vertices[usage].add(vtx)

    def vtx_to_tris(self, vtx):
        return self._vertices_to_triangle[vtx]

    def vtx_to_tris_optional(self, vtx):
        return self._vertices_to_triangle.get(vtx)

    def add(self, tri):
        # Add vtx for the given triangle and rescale the usage
        for vtx in tri:
            if vtx in self._banned_vertices:
                continue

            if vtx not in self._vertices_to_triangle:
                self._vertices_to_triangle[vtx] = set()

            old_usage = self._tris_cost(self._vertices_to_triangle[vtx])
            self._vertices_to_triangle[vtx].add(tri)
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
            if vtx in self._banned_vertices:
                continue
            if not self._banned_vertices:
                assert vtx in self._vertices_to_triangle
            else:
                if vtx not in self._vertices_to_triangle:
                    continue

            old_usage = self._tris_cost(self._vertices_to_triangle[vtx])
            self._vertices_to_triangle[vtx].remove(tri)
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
            if all(vtx in self._banned_vertices for vtx in tri):
                continue

            self.add(tri)

    def _vtx_cost(self, vtx):
        return 100 if vtx in self._loaded_vertices else 1

    def _tri_cost(self, tri):
        cost = sum([self._vtx_cost(vtx) for vtx in tri])
        return cost

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

        self._base_vertices_model_entry = ModelVtxEntry(f'static Vtx {self.name}_vtxopt[] = {{\n')
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

    @staticmethod
    def _tri_rotate(tri, vtx):
        if tri[0] == vtx:
            return tri[0], tri[1], tri[2]
        if tri[1] == vtx:
            return tri[1], tri[2], tri[0]
        if tri[2] == vtx:
            return tri[2], tri[0], tri[1]

        assert False, "triangle does not contain the vertex"

    @staticmethod
    def _tri_normalize(tri):
        # There is a single representation of a 'tri' if minimal vertex is the first one
        # This will allow to have a convenient lookups in sets
        vtx = min(tri)
        return ModelMeshEntry._tri_rotate(tri, vtx)

    @staticmethod
    def _tris_rotate(tris, vtx):
        return [ ModelMeshEntry._tri_rotate(tri, vtx) for tri in tris ]

    def _tri(self, tri_indices):
        if self._tri_trivial(tri_indices):
            return

        tri = self._tri_normalize([ self._vtx(self._parser_vbo[i]) for i in tri_indices ])
        if self._tri_trivial(tri):
            return
    
        if tri in self._triangles_lookup:
            return

        self._triangles.append(tri)
        self._triangles_lookup.add(tri)

    @staticmethod
    def _tri_index_next(idx):
        return (idx + 1) % 3

    @staticmethod
    def _longest_link(links, links_end):
        starting_vtxs     = [ vtx for vtx in links if vtx not in links_end ]
        intermediate_vtxs = [ vtx for vtx in links if vtx     in links_end ]

        # Fire DFS search preferring 'starting_vtxs' and 'intermediate_vtxs'
        # Note that at most recursion can go 5 levels so doing something like this is fine
        def dfs(vtx, visited_links):
            if len(visited_links) == 5:
                return visited_links
            if vtx not in links:
                return visited_links

            for vtx_next in links[vtx]:
                link = vtx, vtx_next
                if link in visited_links:
                    continue

                visited_links_copy = visited_links[:]
                visited_links_copy.append(link)
                new_visited_links = dfs(vtx_next, visited_links_copy)
                if new_visited_links:
                    return new_visited_links

            return visited_links

        longest_link = []
        for vtx in starting_vtxs:
            link = dfs(vtx, [])
            if len(link) > len(longest_link):
                longest_link = link
            if 5 == len(longest_link):
                return longest_link

        for vtx in intermediate_vtxs:
            link = dfs(vtx, [])
            if len(link) > len(longest_link):
                longest_link = link
            if 5 == len(longest_link):
                return longest_link

        return longest_link


    def add(self, data):
        if 'gsSPVertex' in data:
            args = get_args(data)
            vtx_arg = args[0]
            vtx_arg_split = vtx_arg.split(' ')
            assert '+' == vtx_arg_split[1], "incorrect vtx declaration"

            vertices_model_name = vtx_arg_split[0]
            if self._parser_vertices_model_name != vertices_model_name:
                self._parser_vertices_model_name = vertices_model_name
                _, model_entry = self._model.find(vertices_model_name)
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
        assert self._base_vertices_model_entry, "compile() called twice"
        dl_entry = ModelRawOptEntry(self.raw_name, self._base_vertices_model_entry)
        vtx_entry = self._base_vertices_model_entry

        # For a grand majority of cases "just draw" will be good enough - that's when all vertices fit in the buffer
        if len(self._vertices) < 56:
            # Place vertices as is
            vtx_entry.vertices = self._vertices[:]
            vtx_entry.vertices.append("};\n")

            # Make a basic dl that just draws the vertices
            if (len(self._vertices)):
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
            def load_vertex(vtx):
                loaded_vertex_buffer.append(self._vertices[vtx])
                loaded_vertices[vtx] = len(loaded_vertex_buffer) - 1
                print(f"load vertex {vtx} -> {len(loaded_vertex_buffer) - 1}")
                return len(loaded_vertex_buffer) - 1

            def load_or_find_vertex(vtx):
                if vtx in loaded_vertices:
                    return loaded_vertices[vtx]
                else:
                    return load_vertex(vtx)

            # Currently UsagePricer is agnostic to currently loaded weights for performance reasons - sync needs to be done for changed tris
            # It does not matter in case of !HAS_EX3_COMMANDS but will matter for HAS_EX3_COMMANDS
            # assert not HAS_EX3_COMMANDS
            total_pricer = UsagePricer(self._triangles, set(), set())
            fanstrip_vtx_to_check = []

            def fanstrip_tri_check():
                nonlocal fanstrip_vtx_to_check
                rendered = False
                # This is needed when there were loads for fans and strips
                # There might be triangles that we can render relatively "for free" by using existing loaded vertices
                for fanstrip_vtx in fanstrip_vtx_to_check:
                    fanstrip_tris = total_pricer.vtx_to_tris_optional(fanstrip_vtx)
                    if not fanstrip_tris:
                        continue

                    for tri in list(fanstrip_tris):
                        loaded_tri = [ loaded_vertices.get(vtx) for vtx in tri ]
                        if None in loaded_tri:
                            continue

                        print(f"fanstrip tri check -> render {tri} as {loaded_tri}")
                        rendered_triangles.append(loaded_tri)
                        total_pricer.remove(tri)
                        rendered = True

                fanstrip_vtx_to_check = []
                print(f"fanstrip_tri_check -> {rendered}")
                return rendered
            
            def load_or_find_fanstrip_vtx(vtx):
                if vtx in loaded_vertices:
                    return loaded_vertices[vtx]
                else:
                    print(f"load fanstrip vertex {vtx}")
                    fanstrip_vtx_to_check.append(vtx)
                    return load_vertex(vtx)

            rendered_triangles = []
            rendered_fan_strips = []
            start_offset = 0
            vtx_entry.vertices = []
            highest_usage = 0
            # We flush when 'loaded_vertices' becomes 49 somewhat arbitrarily - we need to consume at most 7 for a fan/strip

            while True:
                if not total_pricer.completed():
                    highest_usage, highest_usage_vtx = next(total_pricer.highest_usage())

                limit = 52 if highest_usage < 4 else 48
                if (len(loaded_vertices) and total_pricer.completed()) or len(loaded_vertices) > limit:
                    # Flush vertices
                    fanstrip_tri_check()
                    print("+ flush +")
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

                    for fanstrip in rendered_fan_strips:
                        dl_entry.data.append(fanstrip)

                    loaded_vertices.clear()
                    loaded_vertex_buffer = []
                    rendered_triangles = []
                    rendered_fan_strips = []

                if total_pricer.completed():
                    break

                highest_usage, highest_usage_vtx = next(total_pricer.highest_usage())
                highest_usage_vtx_triangles = list(total_pricer.vtx_to_tris(highest_usage_vtx))

                # Strip of fan requires to have a vertex that has at least 4 triangles
                if HAS_EX3_COMMANDS and len(highest_usage_vtx_triangles) >= 4:
                    # Try to represent as fan or as strip
                    # Both require at least 3 triangles to be worth it and looks like this:
                    #   3 - 4
                    #  / \ / \ 
                    # 2 - 1 - 5
                    # In my case greedily assume that 1 is the highest_usage_vtx.
                    # This means we need to find the path that looks like 2 -> 3 -> 4 -> 5.
                    rotated_vtx_triangles = self._tris_rotate(highest_usage_vtx_triangles, highest_usage_vtx)
                    links = {}
                    links_end = set()
                    for tri in rotated_vtx_triangles:
                        if tri[1] not in links:
                            links[tri[1]] = []

                        links[tri[1]].append(tri[2])
                        links_end.add(tri[2])
                    
                    longest_link = self._longest_link(links, links_end)
                    if len(longest_link) >= 4:
                        # Yield a fan command and break - we have depleted the triangles from "highest_usage_vtx"
                        # Arrangement is v1-v2-v3, v1-v3-v4, v1-v4-v5, v1-v5-v6, v1-v6-v7
                        fan_vertices = [ highest_usage_vtx, longest_link[0][0], longest_link[0][1], longest_link[1][1], longest_link[2][1], longest_link[3][1], longest_link[4][1] if len(longest_link) == 5 else None ]
                        loaded_fan_vertices = [load_or_find_fanstrip_vtx(vtx) if vtx is not None else -1 for vtx in fan_vertices]
                        total_pricer.remove(self._tri_normalize([ fan_vertices[0], fan_vertices[1], fan_vertices[2] ]))
                        total_pricer.remove(self._tri_normalize([ fan_vertices[0], fan_vertices[2], fan_vertices[3] ]))
                        total_pricer.remove(self._tri_normalize([ fan_vertices[0], fan_vertices[3], fan_vertices[4] ]))
                        total_pricer.remove(self._tri_normalize([ fan_vertices[0], fan_vertices[4], fan_vertices[5] ]))
                        if fan_vertices[6] is not None:
                            total_pricer.remove(self._tri_normalize([ fan_vertices[0], fan_vertices[5], fan_vertices[6] ]))

                        print(f"fan {fan_vertices} -> {loaded_fan_vertices}")
                        rendered_fan_strips.append(f"\tgsSPTriFan({', '.join(map(str, loaded_fan_vertices))}),\n")
                        continue
                    
                    if len(longest_link) == 3:
                        # Yield a strip command while attempting to continue the steep, greedily
                        # Arrangement is v1-v2-v3, v3-v2-v4, v3-v4-v5, v5-v4-v6, v5-v6-v7
                        strip_vertices = [ longest_link[0][0], longest_link[0][1], highest_usage_vtx, longest_link[1][1], longest_link[2][1], None, None ]

                        # Try to continue the strip by triangles 5->4->6 and 5->6->7
                        # Because both of those have vertex '5', we can just do a single query to total_pricer:
                        v5_tris = total_pricer.vtx_to_tris(strip_vertices[4])

                        # Now try find a triangle that has v4 that we can render. Mind that it must be _after_ v5
                        # TODO: We can dfs this by 2 triangles but I cannot care enough to do that. I am not even sure it matters
                        v5_tri = None
                        for tri in v5_tris:
                            v5_tri_index = tri.index(strip_vertices[4])
                            assert -1 != v5_tri_index, "v5 not in v5_tris?"
                            v4_tri_index = self._tri_index_next(v5_tri_index)
                            if tri[v4_tri_index] == strip_vertices[3]:
                                v5_tri = tri
                                strip_vertices[5] = tri[self._tri_index_next(v4_tri_index)]
                                break

                        # Technically v6_tri is useless but it is convenient for debugging
                        v6_tri = None
                        if v5_tri:
                            # We have a triangle that has v5 and v4, now we need to find the last vertex
                            # We can do this by just checking if we have a triangle that has v5 and v6
                            for tri in v5_tris:
                                v5_tri_index = tri.index(strip_vertices[4])
                                v6_tri_index = self._tri_index_next(v5_tri_index)
                                if tri[v6_tri_index] == strip_vertices[5]:
                                    v6_tri = tri
                                    strip_vertices[6] = tri[self._tri_index_next(v6_tri_index)]
                                    break

                        loaded_strip_vertices = [load_or_find_fanstrip_vtx(vtx) if vtx is not None else -1 for vtx in strip_vertices]

                        total_pricer.remove(self._tri_normalize([ strip_vertices[0], strip_vertices[1], strip_vertices[2] ]))
                        total_pricer.remove(self._tri_normalize([ strip_vertices[2], strip_vertices[1], strip_vertices[3] ]))
                        total_pricer.remove(self._tri_normalize([ strip_vertices[2], strip_vertices[3], strip_vertices[4] ]))
                        if strip_vertices[5] is not None:
                            total_pricer.remove(self._tri_normalize([ strip_vertices[4], strip_vertices[3], strip_vertices[5] ]))
                        if strip_vertices[6] is not None:
                            total_pricer.remove(self._tri_normalize([ strip_vertices[4], strip_vertices[5], strip_vertices[6] ]))                            

                        print(f"strip {strip_vertices} -> {loaded_strip_vertices}")
                        rendered_fan_strips.append(f"\tgsSPTriStrip({', '.join(map(str, loaded_strip_vertices))}),\n")
                        continue

                # Explicitly check for fanstrip vertices here - needed because algo expects no matching vertices
                # Mind that if any vertex were written by 'fanstrip_tri_check', highest_usage_vtx might become invalid hence 'continue'
                if fanstrip_tri_check():
                    continue

                # Classic algorithm that finds the best triangles that match given
                # highest_usage_vtx might already exist if fan or strip has loaded it already
                load_or_find_vertex(highest_usage_vtx)

                # Explicitly check for vertices that might have become active
                # 'candidate_to_load_pricer' will be empty so need to do this explicitly
                # TODO: Ideally total_pricer should consider vertices currently loaded in and raise the usage...
                for tri in list(total_pricer.vtx_to_tris(highest_usage_vtx)):
                    loaded_tri = [ loaded_vertices.get(vtx) for vtx in tri ]
                    if None in loaded_tri:
                        continue

                    print(f"pre render {tri} as {loaded_tri}")
                    rendered_triangles.append(loaded_tri)
                    total_pricer.remove(tri)
                
                # It might just happen that this operation will use literally all tris for 'highest_usage_vtx'
                # In that case we can just break and continue with the next highest usage vertex
                if not total_pricer.vtx_to_tris_optional(highest_usage_vtx):
                    continue

                candidate_vtxs = set()
                candidate_tris = set()
                banned_vertices = set()
                print("")
                while True:
                    print(f"{loaded_vertices}")
                    banned_vertices.add(highest_usage_vtx)
                    highest_usage_vtx_triangles = list(total_pricer.vtx_to_tris(highest_usage_vtx))
                    for tri in highest_usage_vtx_triangles:
                        loaded_tri = [ loaded_vertices.get(vtx) for vtx in tri ]
                        print(f"{tri} -> {loaded_tri}")
                        if not None in loaded_tri:
                            print(f"render {tri} as {loaded_tri}")
                            rendered_triangles.append(loaded_tri)
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
                                if candidate_tri in candidate_tris:
                                    continue

                                candidate_tris.add(candidate_tri)

                    candidate_to_load_pricer = UsagePricer(candidate_tris, loaded_vertices, banned_vertices)
                    if candidate_to_load_pricer.completed() or len(loaded_vertices) == 56:
                        break

                    highest_usage, highest_usage_vtx = next(candidate_to_load_pricer.highest_usage())
                    load_vertex(highest_usage_vtx)

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
                continue
            
            if isinstance(entry, ModelRawOptEntry):
                entry_vertices = entry.optvtx
                f_model.write(entry_vertices.raw_name)
                for line in entry_vertices.vertices:
                    f_model.write(line)
                f_model.write('\n')

            for line in entry.data:
                f_model.write(line)

            f_model.write('\n')

def patch_header(header_path, header_patched_path):
    with open(header_path, "r") as f_header:
        lines = f_header.readlines()

    with open(header_patched_path, "w") as f_header:
        for line in lines:
            if 'Vtx' in line:
                continue
            f_header.write(line)

if '__main__' in __name__:
    path = f"{sys.argv[1]}/visual"
    slash_idx = sys.argv[1].rfind('/')
    name = sys.argv[1][slash_idx+1:]

    header_path = f"{path}/header_lvl.inc.h"
    header_patched_path = f"{path}/header_lvlopt.inc.h"
    model_path = f"{path}/model_lvl.inc.c"   
    model_patched_path = f"{path}/model_lvlopt.inc.c"
 
    model = load_model(model_path)
    optimize_model(model)
    serialize_model(model, model_patched_path)

    patch_header(header_path, header_patched_path)

    a = 0
