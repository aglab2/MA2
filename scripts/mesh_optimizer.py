from collections import deque
import sys

HAS_EX3_COMMANDS = True
HAS_TRI3 = False
HAS_VTX_PINNING = True

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
        #self.data = [line]
        self.data = []
        self.optvtx = optvtx

    def add(self, line):
        self.data.append(line)

    def __repr__(self):
        return f"ModelRawOptEntry(name={self.name})"

class ModelVtxEntry(ModelEntry):
    def __init__(self, line):
        super().__init__(line)
        self.vertices = []
        self.used = False
    
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

class RenderPass:
    def __init__(self, vertices, triangles, fanstrips):
        self.vertices = vertices
        self.triangles = triangles
        self.fanstrips = fanstrips
        if self.fanstrips:
            print(f"fanstrips {self.fanstrips}")

class FanStrip:
    def __init__(self, is_strip, vertices):
        self.is_strip = is_strip
        self.vertices = vertices

    def stringify(self):
        name = 'gsSPTriStrip' if self.is_strip else 'gsSPTriFan'
        return f"\t{name}({', '.join(map(str, self.vertices))}),\n"

    def __repr__(self):
        return f"FanStrip(is_strip={self.is_strip}, vertices={self.vertices})"

# Generate a shuffle that pins 'shared' vertices to the first 'len(shared)' indices
def make_shuffle_pinning_shared(glo_to_loc, glo_shared):
    # Pin shared vertices to indices from 0 to len(glo_shared) - 1
    glo_shared_to_loc = {}
    for glo in glo_shared:
        glo_shared_to_loc[glo] = len(glo_shared_to_loc)

    shuffle = {}
    loc_unpinned_start = len(glo_shared)

    for glo in glo_to_loc:
        loc = glo_to_loc[glo]
        if glo in glo_shared_to_loc:
            shuffle[loc] = glo_shared_to_loc[glo]
        else:
            shuffle[loc] = loc_unpinned_start
            loc_unpinned_start += 1

    return shuffle

# Generate a shuffle that pins 'shared' vertices to the first 'len(shared)' indices
# Only the first 'lim' vertices are modified by the shuffle.
def make_shuffle_pinning_shared_limited(glo_to_loc, glo_shared, lim):
    assert lim >= len(glo_shared), "lim must be greater than or equal to len(glo_shared)"
    glo_shared_to_loc = {}
    for glo in glo_shared:
        glo_shared_to_loc[glo] = len(glo_shared_to_loc)

    shuffle = {}
    loc_unpinned_start = len(glo_shared)

    for glo in glo_to_loc:
        loc = glo_to_loc[glo]
        if loc >= lim:
            continue

        if glo in glo_shared_to_loc:
            shuffle[loc] = glo_shared_to_loc[glo]
        else:
            shuffle[loc] = loc_unpinned_start
            loc_unpinned_start += 1

    return shuffle

def apply_shuffle(render_pass: RenderPass, shuffle):
    for glo_vtx in render_pass.vertices:
        loc_vtx = render_pass.vertices[glo_vtx]
        render_pass.vertices[glo_vtx] = shuffle[loc_vtx]
    for tri in render_pass.triangles:
        for i, loc_vtx in enumerate(tri):
            tri[i] = shuffle[loc_vtx]
    for fanstrip in render_pass.fanstrips:
        for i, loc_vtx in enumerate(fanstrip.vertices):
            fanstrip.vertices[i] = -1 if loc_vtx == -1 else shuffle[loc_vtx]

def apply_shuffle_limited(render_pass: RenderPass, shuffle, limit):
    for glo_vtx in render_pass.vertices:
        loc_vtx = render_pass.vertices[glo_vtx]
        if loc_vtx >= limit:
            continue
        render_pass.vertices[glo_vtx] = shuffle[loc_vtx]

    for tri in render_pass.triangles:
        for i, loc_vtx in enumerate(tri):
            if loc_vtx >= limit:
                continue
            tri[i] = shuffle[loc_vtx]

    for fanstrip in render_pass.fanstrips:
        for i, loc_vtx in enumerate(fanstrip.vertices):
            if loc_vtx >= limit:
                continue
            fanstrip.vertices[i] = -1 if loc_vtx == -1 else shuffle[loc_vtx]

class TriKit:
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
        return TriKit._tri_rotate(tri, vtx)

    @staticmethod
    def _tris_rotate(tris, vtx):
        return [ TriKit._tri_rotate(tri, vtx) for tri in tris ]

    @staticmethod
    def _tri_index_next(idx):
        return (idx + 1) % 3

    @staticmethod
    def _edges(tri):
        yield (tri[0], tri[1])
        yield (tri[1], tri[2])
        yield (tri[2], tri[0])
    
    @staticmethod
    def _edges_reverse(tri):
        yield (tri[1], tri[0])
        yield (tri[2], tri[1])
        yield (tri[0], tri[2])

    @staticmethod
    def _v_in_triA_not_in_triB(triA, triB):
        # Such routine is very helpful for strips because it is common that vtx needed to be outputted in index buffer
        # is the exact vertex that is not in the next triangle.
        return [v for v in triA if v not in triB].pop()

    @staticmethod
    def _strip_can_be_rendered(path):
        # EX3 is unable to support every strip setup. Only strip where 3rd vertex is not shared with 1st vertex can work
        # A tri setup like this can work:
        #   2 - 4 - 6 ..
        #  / \ / \ /  ..
        # 1 - 3 - 5 - ..

        # ... but its symmetric flip cannot work - the 3rd tri will be v4-v2-v5 but only v3-v4-v5 can be rendered
        # 1 - 2 - 5 ..
        #  \ / \ /  ..
        #   3 - 4 - 6 - ..
        v1 = TriKit._v_in_triA_not_in_triB(path[0], path[1])
        t1 = TriKit._tri_rotate(path[0], v1)
        v2 = t1[1]
        return v2 not in path[2]

    @staticmethod
    def _strip_can_continue(path, ntri):
        if len(path) < 3:
            return True

        # Check if ntri can be a valid next triangle in the strip
        # Construct the last strip edge...
        v_last1 = TriKit._v_in_triA_not_in_triB(path[-1], path[-2])
        v_last2 = TriKit._v_in_triA_not_in_triB(path[-2], path[-3])
        t_last = path[-1]
        t_last_rot = TriKit._tri_rotate(t_last, v_last2)
        if t_last_rot[1] == v_last1:
            edge_next = (v_last1, v_last2)
        else:
            assert t_last_rot[2] == v_last1, "v_last1 must be in t_last"
            edge_next = (v_last2, v_last1)

        # ...and check that edge is actually present in the next triangle
        can = edge_next in TriKit._edges(ntri)
        return can

    @staticmethod
    def stripify(triangles):
            rendered_triangles = triangles[:]
            if not HAS_EX3_COMMANDS:
                return rendered_triangles, []

            rendered_fan_strips = []

            # Build the strips tree. The way it is built is using a temporary edge->tri mapping to link the tree...
            edge_to_tris = {}
            for tri in rendered_triangles:
                # Mind that edge is flipped here because the next tri in strip will have the edge in reverse order
                for edge in TriKit._edges_reverse(tri):
                    if edge not in edge_to_tris:
                        edge_to_tris[edge] = []
                    edge_to_tris[edge].append(tri)

            strip_tri_to_tris = {}
            # ...and iterating the triangles again linking the triangles
            for tri in rendered_triangles:
                for edge in TriKit._edges(tri):
                    if edge not in edge_to_tris:
                        continue

                    for ntri in edge_to_tris[edge]:
                        if ntri not in strip_tri_to_tris:
                            strip_tri_to_tris[ntri] = set()
                        strip_tri_to_tris[ntri].add(tri)

            del edge_to_tris

            # This provides us with doubly linked triangles list for strips generation.
            # Try to find the best start of the strip - the "loneliest" triangle with the least amount of neighbours
            neighbour_count_to_tri = {}
            for tri in strip_tri_to_tris:
                neighbour_count = len(strip_tri_to_tris[tri])
                if neighbour_count not in neighbour_count_to_tri:
                    neighbour_count_to_tri[neighbour_count] = set()
                neighbour_count_to_tri[neighbour_count].add(tri)

            if not neighbour_count_to_tri or max(neighbour_count_to_tri.keys()) < 2:
                # Not enough neighbours to form any kind of strip
                return rendered_triangles, []

            dfs_tri_traverse_order = []
            for count in sorted(neighbour_count_to_tri.keys()):
                dfs_tri_traverse_order.extend(list(neighbour_count_to_tri[count]))
            
            del neighbour_count_to_tri

            strip_scraps = []
            tri_to_strip_scrap = {}
            
            # This is a convenient mapping for fan generation, we will use it later...
            edge_to_tris = {}

            def remove_tri(tri):
                rendered_triangles.remove(tri)

                if edge_to_tris:
                    for edge in TriKit._edges(tri):
                        edge_to_tris[edge].remove(tri)
                        if not edge_to_tris[edge]:
                            del edge_to_tris[edge]

                scraps_to_remove = []
                if tri in tri_to_strip_scrap:
                    scraps_to_remove = tri_to_strip_scrap[tri]

                for scrap in scraps_to_remove:
                    strip_scraps.remove(scrap)
                    for scrap_tri in scrap:
                        tri_to_strip_scrap[scrap_tri].remove(scrap)
                        if not tri_to_strip_scrap[scrap_tri]:
                            del tri_to_strip_scrap[scrap_tri]

                    # Try to salvage the scrap if it was of length 4 and had beginning or ending cut
                    salvaged_scrap = None
                    if len(scrap) == 4:
                        if scrap[0] == tri:
                            salvaged_scrap = scrap[1:]
                        if scrap[-1] == tri:
                            salvaged_scrap = scrap[:-1]
                    
                    if salvaged_scrap:
                        strip_scraps.append(salvaged_scrap)
                        for salv_tri in salvaged_scrap:
                            if salv_tri not in tri_to_strip_scrap:
                                tri_to_strip_scrap[salv_tri] = []
                            tri_to_strip_scrap[salv_tri].append(salvaged_scrap)

                assert tri not in tri_to_strip_scrap, "tri must not be in tri_to_strip_scrap"

            # Now we need to dfs through each triangle to find the strips
            # Start with lighest triangles that have the least amount of neighbours
            # Because each render pass is by amount of vertices, we can just dfs each triangle without too much cost.
            for tri in dfs_tri_traverse_order:
                # Check if it was already rendered as part of a strip
                if tri not in strip_tri_to_tris:
                    continue

                stack = [(tri, [tri])]
                longest_path = [tri]
                while stack:
                    curr, path = stack.pop()
                    # Note that dfs is allowed to do 'strip_tri_to_tris[curr]' because it is doubly linked
                    # Conveniently we will get an exception is something went wrong in 'strip_tri_to_tris' generation
                    for ntri in strip_tri_to_tris[curr]:
                        if ntri not in path and TriKit._strip_can_continue(path, ntri):
                            new_path = path + [ntri]
                            if len(new_path) > len(longest_path):
                                longest_path = new_path

                            stack.append((ntri, new_path))

                # We got the path, evict all triangles that are in the path
                for tri in longest_path:
                    if not tri in strip_tri_to_tris:
                        continue
                    for ntri in strip_tri_to_tris.pop(tri):
                        strip_tri_to_tris[ntri].remove(tri)
                        if not strip_tri_to_tris[ntri]:
                            del strip_tri_to_tris[ntri]

                # Do not consider tiny strips (quads really), they will be handled nicely by regular TRI2 command
                while len(longest_path) > 3:
                    path_to_render = None
                    if len(longest_path) <= 5:
                        path_to_render = longest_path
                        longest_path = []
                    elif len(longest_path) == 9:
                        # Special handling is required for 9 triangles to avoid situation where 4 len strips cannot be rendered
                        # Thankfully, we can just render either 5+4 or 4+5 triangles explicitly always renderable strip.
                        if TriKit._strip_can_be_rendered(longest_path):
                            path_to_render = longest_path[:4]
                            longest_path = longest_path[4:]
                        else:
                            path_to_render = longest_path[:5]
                            longest_path = longest_path[5:]
                    else:
                        path_to_render = longest_path[:5]
                        longest_path = longest_path[5:]

                    # It is possible to convert unsupported strip by reversing the order of triangles for odd length.
                    if not TriKit._strip_can_be_rendered(path_to_render):
                        if len(path_to_render) % 2 == 1:
                            path_to_render.reverse()
                        else:
                            # Terrible fate occured - we have to trim down the strip but it will become renderable :)
                            assert not longest_path
                            assert len(path_to_render) == 4
                            longest_path = path_to_render
                            break # Fall down to fan logic

                    # We will render longest_path as strips so remove it from 'rendered_triangles'
                    for tri in path_to_render:
                        remove_tri(tri)

                    # Now we can render the strip - kickstart the strip with the first triangle
                    # Strip is defined as v1-v2-v3, v3-v2-v4, v3-v4-v5, v5-v4-v6, v5-v6-v7
                    # Find out the rotation of the first triangle - v1 must only be used in 1st but not 2nd triangle
                    tri_prev = TriKit._tri_rotate(path_to_render[0], TriKit._v_in_triA_not_in_triB(path_to_render[0], path_to_render[1]))
                    assert tri_prev[1] not in path_to_render[2], "v2 must not be in t2"
                    strip_vs = list(tri_prev)
                    for tri_curr in path_to_render[1:]:
                        strip_vs.append(TriKit._v_in_triA_not_in_triB(tri_curr, tri_prev))
                        tri_prev = tri_curr

                    while len(strip_vs) < 7:
                        strip_vs.append(-1)
                    rendered_fan_strips.append(FanStrip(is_strip=True, vertices=strip_vs))

                if 3 == len(longest_path) or 4 == len(longest_path):
                    strip_scrap = longest_path
                    strip_scraps.append(strip_scrap)
                    for tri in strip_scrap:
                        if tri not in tri_to_strip_scrap:
                            tri_to_strip_scrap[tri] = list()
                        tri_to_strip_scrap[tri].append(strip_scrap)

                # ...rest, if left, will be rendered as triangles (or maybe fans?)

            # For fans a lookup from vtx to triangles is convenient to have vtx->tri mapping, declaration is on top so 'remove_tri' can see it
            for tri in rendered_triangles:
                for edge in TriKit._edges(tri):
                    if edge not in edge_to_tris:
                        edge_to_tris[edge] = set()
                    edge_to_tris[edge].add(tri)

            def scrap_properly_rotated(scrap):
                v1 = [v for v in scrap[0] if v in scrap[1] and v in scrap[2]].pop()
                v2 = TriKit._v_in_triA_not_in_triB(scrap[0], scrap[1])
                proper = (v1, v2) in TriKit._edges(scrap[0])
                assert proper or (v2, v1) in TriKit._edges(scrap[0]), "v1 and v2 must be in the first triangle"
                return proper

            while strip_scraps:
                strip_scrap = strip_scraps[0]

                if len(strip_scrap) == 4:
                    # Fan can be continue by either 3rd or 4th triangle. Choose that is continuable
                    scrap_choice0 = strip_scrap[:3]
                    if not scrap_properly_rotated(scrap_choice0):
                        scrap_choice0.reverse()
                        assert scrap_properly_rotated(scrap_choice0)

                    scrap_choice1 = strip_scrap[1:]
                    if not scrap_properly_rotated(scrap_choice1):
                        scrap_choice1.reverse()
                        assert scrap_properly_rotated(scrap_choice1)

                    v1_choice0 = [v for v in scrap_choice0[0] if v in scrap_choice0[1] and v in scrap_choice0[2]].pop()
                    v5_choice0 = TriKit._v_in_triA_not_in_triB(scrap_choice0[2], scrap_choice0[1])
                    v1_choice1 = [v for v in scrap_choice1[0] if v in scrap_choice1[1] and v in scrap_choice1[2]].pop()
                    v5_choice1 = TriKit._v_in_triA_not_in_triB(scrap_choice1[2], scrap_choice1[1])
                    v5_tris_choice0 = edge_to_tris.get((v1_choice0, v5_choice0), [])
                    v5_tris_choice1 = edge_to_tris.get((v1_choice1, v5_choice1), [])
                    if len(v5_tris_choice0) >= len(v5_tris_choice1):
                        strip_scrap = scrap_choice0
                    else:
                        strip_scrap = scrap_choice1

                assert len(strip_scrap) == 3, "strip scrap must be 3 triangles long"

                # Special case for 3 triangles - try to continue as a fan
                # Remove from renders
                for tri in strip_scrap:
                    remove_tri(tri)

                if not scrap_properly_rotated(strip_scrap):
                    strip_scrap.reverse()
                    assert scrap_properly_rotated(strip_scrap)

                # Strip notation: Fan notation:
                #   2 - 4            3 - 4
                #  / \ / \          / \ / \ 
                # 1 - 3 - 5        2 - 1 - 5

                # This guaranteed to exist due to the structure of the strip - pivot vertex v1
                v1 = [v for v in strip_scrap[0] if v in strip_scrap[1] and v in strip_scrap[2]].pop()
                v2 = TriKit._v_in_triA_not_in_triB(strip_scrap[0], strip_scrap[1])
                v3 = TriKit._v_in_triA_not_in_triB(strip_scrap[1], strip_scrap[2])
                v4 = TriKit._v_in_triA_not_in_triB(strip_scrap[1], strip_scrap[0])
                v5 = TriKit._v_in_triA_not_in_triB(strip_scrap[2], strip_scrap[1])
                v6 = -1
                v7 = -1

                e5 = (v1, v5)
                if e5 in edge_to_tris:
                    tri3 = next(iter(edge_to_tris[e5]))
                    remove_tri(tri3)
                    v6 = TriKit._v_in_triA_not_in_triB(tri3, strip_scrap[2])
                    e6 = (v1, v6)
                    if e6 in edge_to_tris:
                        tri4 = next(iter(edge_to_tris[e6]))
                        remove_tri(tri4)
                        v7 = TriKit._v_in_triA_not_in_triB(tri4, tri3)

                fan_vertices = [ v1, v2, v3, v4, v5, v6, v7 ]
                rendered_fan_strips.append(FanStrip(is_strip=False, vertices=fan_vertices))

            # We are converting tri to list because vtx load optimizer will want to mangle tri/fanstrip vertices
            # We will never need to compare the triangles so this is fine
            return rendered_triangles, rendered_fan_strips


class ModelMeshEntry(TriKit):
    def __init__(self, next_line, model):
        self._model = model

        vtx_args = get_args(next_line)
        vtx_arg = vtx_args[0]
        vtx_arg_split = vtx_arg.split(' ')

        _, vtx = model.find(vtx_arg_split[0])
        vtx.used = True

        self._base_vertices_model_entry = ModelVtxEntry(f'static Vtx {vtx_arg_split[0]}_vtxopt[] = {{\n')
        assert '+' == vtx_arg_split[1], "offset must be 0"
        if '0' != vtx_arg_split[2]:
            orig_name = self._base_vertices_model_entry.name
            self._base_vertices_model_entry.name = self._base_vertices_model_entry.name + f"_{vtx_arg_split[2]}"
            self._base_vertices_model_entry.raw_name = self._base_vertices_model_entry.raw_name.replace(orig_name, self._base_vertices_model_entry.name)

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

    @staticmethod
    def _make_render_pass(triangles, vertices):
        triangles, fanstrips = TriKit.stripify(triangles)
        return RenderPass(vertices, [ list(tri) for tri in triangles ], fanstrips)

    def compile(self):
        assert self._base_vertices_model_entry, "compile() called twice"
        assert not self._base_vertices_model_entry.used
        self._base_vertices_model_entry.used = True
        draws = []
        vtx_entry = self._base_vertices_model_entry

        # Step 1: Generate render passes for each vertex set
        render_passes = []

        # For a grand majority of cases "just draw" will be good enough - that's when all vertices fit in the buffer
        if len(self._vertices) < 56:
            passthru_vertices = {}
            for i in range(len(self._vertices)):
                passthru_vertices[i] = i

            render_pass = self._make_render_pass(self._triangles, passthru_vertices)
            render_passes.append(render_pass)
        else:
            # This is a primitive greedy algorithm for drawing vertices
            loaded_vertices = {}
            def load_vertex(vtx):
                loaded_vertices[vtx] = len(loaded_vertices)
                print(f"load vertex {vtx} -> {len(loaded_vertices) - 1}")
                return len(loaded_vertices) - 1

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
            highest_usage = 0
            # We flush when 'loaded_vertices' becomes 49 somewhat arbitrarily - we need to consume at most 7 for a fan/strip

            while True:
                if not total_pricer.completed():
                    highest_usage, highest_usage_vtx = next(total_pricer.highest_usage())

                if (len(loaded_vertices) and total_pricer.completed()) or len(loaded_vertices) >= 56:
                    # Flush vertices
                    fanstrip_tri_check()
                    print("+ flush +")

                    render_pass = self._make_render_pass([ self._tri_normalize(tri) for tri in rendered_triangles ], loaded_vertices.copy())
                    render_passes.append(render_pass)

                    loaded_vertices.clear()
                    rendered_triangles = []

                if total_pricer.completed():
                    break

                highest_usage, highest_usage_vtx = next(total_pricer.highest_usage())
                highest_usage_vtx_triangles = list(total_pricer.vtx_to_tris(highest_usage_vtx))

                # Strip of fan requires to have a vertex that has at least 4 triangles
                if HAS_EX3_COMMANDS and len(highest_usage_vtx_triangles) >= 4 and len(loaded_vertices) < 49:
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
                        rendered_triangles.append([ loaded_fan_vertices[0], loaded_fan_vertices[1], loaded_fan_vertices[2] ])
                        rendered_triangles.append([ loaded_fan_vertices[0], loaded_fan_vertices[2], loaded_fan_vertices[3] ])
                        rendered_triangles.append([ loaded_fan_vertices[0], loaded_fan_vertices[3], loaded_fan_vertices[4] ])
                        rendered_triangles.append([ loaded_fan_vertices[0], loaded_fan_vertices[4], loaded_fan_vertices[5] ])
                        if fan_vertices[6] is not None:
                            rendered_triangles.append([ loaded_fan_vertices[0], loaded_fan_vertices[5], loaded_fan_vertices[6] ])

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
                        rendered_triangles.append([ loaded_strip_vertices[0], loaded_strip_vertices[1], loaded_strip_vertices[2] ])
                        rendered_triangles.append([ loaded_strip_vertices[2], loaded_strip_vertices[1], loaded_strip_vertices[3] ])
                        rendered_triangles.append([ loaded_strip_vertices[2], loaded_strip_vertices[3], loaded_strip_vertices[4] ])
                        if strip_vertices[5] is not None:
                            rendered_triangles.append([ loaded_strip_vertices[4], loaded_strip_vertices[3], loaded_strip_vertices[5] ])
                        if strip_vertices[6] is not None:
                            rendered_triangles.append([ loaded_strip_vertices[4], loaded_strip_vertices[5], loaded_strip_vertices[6] ])

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
                banned_vertices = set(loaded_vertices.keys())
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
                            candidate_tris.remove(tri)
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

        # Step 2: Find common vertices across render passes and pin them to the left side of the buffer
        render_pass_vtx_load_offsets = []
        prev_render_pass = None
        pinned_vertices_left = None
        altered_render_passes = []
        for i, render_pass in enumerate(render_passes):
            curr_vertices = set(render_pass.vertices.keys())
            print(f"render pass {i} -> {curr_vertices}")
            if prev_render_pass:
                prev_vertices = prev_render_pass.vertices
                common_vertices = set(prev_vertices.keys()).intersection(curr_vertices)
                if common_vertices:
                    print(f"common vertices {common_vertices}, length {len(common_vertices)}")
                    if not pinned_vertices_left:
                        # Perform the first shuffling and pin the common vertices on the left vbo
                        common_vertices = list(common_vertices)
                        altered_render_passes.append(prev_render_pass)
                        altered_render_passes.append(render_pass)
                        for altered_render_pass in altered_render_passes:
                            shuffle = make_shuffle_pinning_shared(altered_render_pass.vertices, common_vertices)
                            print(f"apply shuffle {shuffle}")
                            print(f"render pass vtx before shuffle {altered_render_pass.vertices}")
                            apply_shuffle(altered_render_pass, shuffle)
                            print(f"render pass vtx after shuffle -> {altered_render_pass.vertices}")

                        pinned_vertices_left = common_vertices
                    else:
                        # There is already a pinned buffer on the left side.
                        # We might be able to reuse some of the common vertices, all other vertices
                        # can be repinned to the right side of the buffer.
                        repinned_vertices_left = common_vertices.intersection(pinned_vertices_left)
                        unpinned_vertices_right = common_vertices.difference(pinned_vertices_left)
                        print(f"repinned vertices left {repinned_vertices_left}")
                        if repinned_vertices_left:
                            # Shrink the left buffer to only contain the common vertices...

                            # Make the sub-shuffle of length 'len(pinned_vertices_left)' that spans across all 'altered_render_passes'
                            # Remember that shuffle must be applied to all altered render passes and it must be exactly the same shuffle
                            shuffle = make_shuffle_pinning_shared_limited(altered_render_passes[0].vertices, repinned_vertices_left, len(pinned_vertices_left))
                            print(f"apply pinning limited shuffle {shuffle}")
                            for altered_render_pass in altered_render_passes:
                                print(f"render pass vtx before pinning limited shuffle {altered_render_pass.vertices}")
                                apply_shuffle_limited(altered_render_pass, shuffle, len(pinned_vertices_left))
                                print(f"render pass vtx after pinning limited shuffle {altered_render_pass.vertices}")

                            pinned_vertices_left = list(repinned_vertices_left)

                            shuffle = make_shuffle_pinning_shared(render_pass.vertices, pinned_vertices_left)
                            print(f"apply pinning shuffle {shuffle}")
                            print(f"render pass vtx before pinning shuffle {render_pass.vertices}")
                            apply_shuffle(render_pass, shuffle)
                            print(f"render pass vtx after pinning shuffle {render_pass.vertices}")
                            altered_render_passes.append(render_pass)
                        else:
                            # There is nothing else left to repin, drop left buffer
                            pinned_vertices_left = None
                            altered_render_passes = []
                        # ...and potentially pin the right buffer to the right side of the buffer - todo!
                else:
                    pinned_vertices_left = None
                    altered_render_passes = []

            render_pass_vtx_load_offsets.append(0 if not pinned_vertices_left else len(pinned_vertices_left))
            prev_render_pass = render_pass

        # Step 3: Generate the display lists rendering the render passes
        vtx_entry.vertices = []
        start_offset = 0
        for render_pass, vtx_load_offset in zip(render_passes, render_pass_vtx_load_offsets):
            cur_vtx_start_offset = start_offset
            if not HAS_VTX_PINNING:
                vtx_load_offset = 0

            print(f"render pass out {render_pass.vertices} at {vtx_load_offset}")
            cur_vtx_load_amount = len(render_pass.vertices) - vtx_load_offset

            for _ in range(cur_vtx_load_amount):
                vtx_entry.vertices.append(None)
            for vtx in render_pass.vertices:
                if render_pass.vertices[vtx] < vtx_load_offset:
                    continue

                glo = start_offset + render_pass.vertices[vtx] - vtx_load_offset
                assert not vtx_entry.vertices[glo], f"vtx_entry is reused at {glo} for {vtx}"
                vtx_entry.vertices[glo] = self._vertices[vtx]

            assert None not in vtx_entry.vertices[start_offset:start_offset + cur_vtx_load_amount], "vtx_entry is not filled correctly"
            start_offset += cur_vtx_load_amount

            if cur_vtx_load_amount:
                if 1 == len(render_passes):
                    draws.append(f"\tgsSPVertex({vtx_entry.name}, {cur_vtx_load_amount}, {vtx_load_offset}),\n")
                else:
                    draws.append(f"\tgsSPVertex({vtx_entry.name} + {cur_vtx_start_offset}, {cur_vtx_load_amount}, {vtx_load_offset}),\n")

            triangles = deque(render_pass.triangles)
            while triangles:
                if HAS_TRI3:
                    if 1 == len(triangles):
                        tri = triangles.popleft()
                        draws.append(f"\tgsSP1Triangle({tri[0]}, {tri[1]}, {tri[2]}, 0),\n")
                    elif 2 == len(triangles):
                        tri0 = triangles.popleft()
                        tri1 = triangles.popleft()
                        draws.append(f"\tgsSP2Triangles({tri0[0]}, {tri0[1]}, {tri0[2]}, 0, {tri1[0]}, {tri1[1]}, {tri1[2]}, 0),\n")
                    elif 4 == len(triangles):
                        # 4 triangles is better presented as 2xTRI2 commands - same amount of commands but less RSP work
                        tri0 = triangles.popleft()
                        tri1 = triangles.popleft()
                        tri2 = triangles.popleft()
                        tri3 = triangles.popleft()
                        draws.append(f"\tgsSP2Triangles({tri0[0]}, {tri0[1]}, {tri0[2]}, 0, {tri1[0]}, {tri1[1]}, {tri1[2]}, 0),\n")
                        draws.append(f"\tgsSP2Triangles({tri2[0]}, {tri2[1]}, {tri2[2]}, 0, {tri3[0]}, {tri3[1]}, {tri3[2]}, 0),\n")
                    else:
                        tri0 = triangles.popleft()
                        tri1 = triangles.popleft()
                        tri2 = triangles.popleft()
                        draws.append(f"\tgsSP3Triangles({tri0[0]}, {tri0[1]}, {tri0[2]}, {tri1[0]}, {tri1[1]}, {tri1[2]}, {tri2[0]}, {tri2[1]}, {tri2[2]}),\n")
                else:
                    if 1 == len(triangles):
                        tri = triangles.popleft()
                        draws.append(f"\tgsSP1Triangle({tri[0]}, {tri[1]}, {tri[2]}, 0),\n")
                    else:
                        tri0 = triangles.popleft()
                        tri1 = triangles.popleft()
                        draws.append(f"\tgsSP2Triangles({tri0[0]}, {tri0[1]}, {tri0[2]}, 0, {tri1[0]}, {tri1[1]}, {tri1[2]}, 0),\n")

            for fanstrip in render_pass.fanstrips:
                draws.append(fanstrip.stringify())

        vtx_entry.vertices.append("};\n")

        #dl_entry.data.append(f"\tgsSPEndDisplayListHint(4),\n")
        #dl_entry.data.append("};\n")
        # this function is not reentrant so make sure we will crash next time we this
        self._base_vertices_model_entry = None
        return draws, vtx_entry

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

class ModelMeshEntryList(ModelEntry):
    def __init__(self, line):
        super().__init__(line)
        self.data = [line]
        self.opvtxs = []

def _is_tri(line):
    return 'gsSP2Triangles' in line or 'gsSP1Triangle' in line

def _is_draw(line, nline):
    if _is_tri(line):
        return True
    if 'gsSPVertex' in line:
        return _is_tri(nline)

    return False

def optimize_model(model):
    for model_entry_idx in range(len(model.entries)):
        old_entry = model.entries[model_entry_idx]
        if not isinstance(old_entry, ModelRawEntry):
            continue
        if not 'Gfx' in old_entry.data[0]:
            continue

        mlist = ModelMeshEntryList(old_entry.data[0])
        entry = None

        for i in range(1, len(old_entry.data)):
            line = old_entry.data[i]
            nline = old_entry.data[i+1] if i + 1 < len(old_entry.data) else None
            if not _is_draw(line, nline):
                if entry:
                    draws, vtxopt = entry.compile()
                    mlist.data.extend(draws)
                    mlist.opvtxs.append(vtxopt)

                    entry = None
                mlist.data.append(line)
                continue
            else:
                if not entry:
                    entry = ModelMeshEntry(line, model)
                entry.add(line)

        model.entries[model_entry_idx] = mlist
        #entry = ModelMeshEntry(old_entry.data[0], old_entry.data[1], model)
        #for i in range(1, len(old_entry.data)):
        #    entry.add(old_entry.data[i])

        #model.entries[model_entry_idx] = entry.compile()

def serialize_model(model, path):
    with open(path, "w") as f_model:
        model.entries = [entry for entry in model.entries if entry]

        for entry in model.entries:
            if isinstance(entry, ModelVtxEntry):
                if not entry.used:
                    f_model.write(entry.raw_name)
                    for line in entry.vertices:
                        f_model.write(line)
                    f_model.write('\n')

                continue


            if isinstance(entry, ModelMeshEntryList):
                for entry_vertices in entry.opvtxs:
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

class ModelVtxIndexer(TriKit):
    def __init__(self):
        self._reset()

    def _reset(self):
        self._triangles_lookup = set()
        self._triangles = []

    def tri(self, tri):
        if self._tri_trivial(tri):
            return

        tri = self._tri_normalize(tri)
        if tri in self._triangles_lookup:
            return

        self._triangles.append(tri)
        self._triangles_lookup.add(tri)
    
    def flush(self, f_model):
        if not self._triangles:
            return

        triangles, strips = TriKit.stripify(self._triangles)
        self._reset()

        triangles = deque(triangles)
        while triangles:
            if HAS_TRI3:
                if 1 == len(triangles):
                    tri = triangles.popleft()
                    f_model.write(f"\tgsSP1Triangle({tri[0]}, {tri[1]}, {tri[2]}, 0),\n")
                elif 2 == len(triangles):
                    tri0 = triangles.popleft()
                    tri1 = triangles.popleft()
                    f_model.write(f"\tgsSP2Triangles({tri0[0]}, {tri0[1]}, {tri0[2]}, 0, {tri1[0]}, {tri1[1]}, {tri1[2]}, 0),\n")
                elif 4 == len(triangles):
                    # 4 triangles is better presented as 2xTRI2 commands - same amount of commands but less RSP work
                    tri0 = triangles.popleft()
                    tri1 = triangles.popleft()
                    tri2 = triangles.popleft()
                    tri3 = triangles.popleft()
                    f_model.write(f"\tgsSP2Triangles({tri0[0]}, {tri0[1]}, {tri0[2]}, 0, {tri1[0]}, {tri1[1]}, {tri1[2]}, 0),\n")
                    f_model.write(f"\tgsSP2Triangles({tri2[0]}, {tri2[1]}, {tri2[2]}, 0, {tri3[0]}, {tri3[1]}, {tri3[2]}, 0),\n")
                else:
                    tri0 = triangles.popleft()
                    tri1 = triangles.popleft()
                    tri2 = triangles.popleft()
                    f_model.write(f"\tgsSP3Triangles({tri0[0]}, {tri0[1]}, {tri0[2]}, {tri1[0]}, {tri1[1]}, {tri1[2]}, {tri2[0]}, {tri2[1]}, {tri2[2]}),\n")
            else:
                if 1 == len(triangles):
                    tri = triangles.popleft()
                    f_model.write(f"\tgsSP1Triangle({tri[0]}, {tri[1]}, {tri[2]}, 0),\n")
                else:
                    tri0 = triangles.popleft()
                    tri1 = triangles.popleft()
                    f_model.write(f"\tgsSP2Triangles({tri0[0]}, {tri0[1]}, {tri0[2]}, 0, {tri1[0]}, {tri1[1]}, {tri1[2]}, 0),\n")

        for strip in strips:
            f_model.write(strip.stringify())

def indexize_model(model_path, model_patched_path):
    with open(model_path, "r") as f_model:
        lines = f_model.readlines()

    indexer = ModelVtxIndexer()
    with open(model_patched_path, "w") as f_model:
        for line in lines:
            if 'gsSP2Triangles' in line:
                args = get_args(line)
                indexer.tri([ int(args[0]), int(args[1]), int(args[2]) ])
                indexer.tri([ int(args[4]), int(args[5]), int(args[6]) ])
            elif 'gsSP1Triangle' in line:
                args = get_args(line)
                indexer.tri([ int(args[0]), int(args[1]), int(args[2]) ])
            else:
                indexer.flush(f_model)
                f_model.write(line)

def make_opt_name(path):
    extensions = [ '.inc.c', '.inc.h', '.h', '.c' ]
    for ext in extensions:
        if path.endswith(ext):
            return path[:-len(ext)] + 'opt' + ext

    assert False, f"unknown extension for {path}"

if '__main__' in __name__:
    model_path = sys.argv[1]
    model_patched_path = make_opt_name(model_path)

    if len(sys.argv) >= 3:
        header_path = sys.argv[2]
        header_patched_path = make_opt_name(header_path)

        model = load_model(model_path)
        optimize_model(model)
        serialize_model(model, model_patched_path)
        patch_header(header_path, header_patched_path)
    else:
        indexize_model(model_path, model_patched_path)
