from collections import deque
import math
import sys

HAS_EX3_COMMANDS = True
HAS_TRI3 = False
HAS_VTX_PINNING = True

# Current DFS implementation is O(2^n) algo so not to wait forever we limit the amount of triangles to walk through
WALK_LIMIT = 10000

def log_debug(line):
    pass

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
    def __init__(self, req_tris, loaded_vertices=None, rendered_tris=[], banned_vertices=None):
        self._vertices_to_triangle = {}
        self._usage_to_vertices = {}
        self._banned_vertices = set(banned_vertices) if banned_vertices else set()
        self._loaded_vertices = loaded_vertices if loaded_vertices else []

        self._inverse_edges = set()
        for tri in rendered_tris:
            for edge in TriKit._edges_reverse(tri):
                self._inverse_edges.add(edge)

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
        assert False, "need rework"
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
        assert False, "need rework"
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
        for edge in TriKit._edges(tri):
            if edge in self._inverse_edges:
                cost += 500

        return cost

    def _tris_cost(self, tris):
        return sum([self._tri_cost(tri) for tri in tris])

    @staticmethod
    def any(s):
        for val in s:
            break
        return val

    def highest_usage(self):
        highest_usage = max(self._usage_to_vertices.items())
        return self.any(highest_usage[1])

    def completed(self):
        return not self._usage_to_vertices

    def vtx_left(self):
        return len(self._vertices_to_triangle)

class RenderPass:
    def __init__(self, vertices, triangles, snakes):
        self.vertices = vertices
        self.triangles = triangles
        self.snakes = snakes
        if self.snakes:
            log_debug(f"snakes {self.snakes}")

SNAKE_TURN_LEFT = "G_SNAKE_RIGHT"
SNAKE_TURN_RIGHT = "G_SNAKE_LEFT"

class SnakeCommand:
    def __init__(self, vtx = -1, turn = 0):
        self.vtx = vtx
        self.turn = turn
        self.terminal = False

    def __repr__(self):
        return f"{"G_SNAKE_LAST | " if self.terminal else ""}{self.vtx}, {self.turn}"

class Snake:
    def __init__(self, vertices, turns):
        self.vertices = vertices
        self.turns = turns

    def stringify_x(self):
        boot_tri = self.vertices[:3]
        vertices = self.vertices[3:]
        commands = [SnakeCommand(vtx, turn) for vtx, turn in zip(vertices, self.turns)]
        commands[-1].terminal = True

        if len(commands) <= 4:
            commands += [SnakeCommand()] * (4 - len(commands))
            yield f"\tgsSPTriSnake({', '.join(map(str, boot_tri))}, {', '.join(map(str, commands))}),\n"
        else:
            yield f"\tgsSPTriSnake({', '.join(map(str, boot_tri))}, {', '.join(map(str, commands[:4]))}),\n"
            for i in range(4, len(commands), 8):
                end = min(i + 8, len(commands))
                next_commands = commands[i:end] + [SnakeCommand()] * (8 - (end - i))
                yield f"\tgsSPContinueSnake({', '.join(map(str, next_commands))}),\n"

    def __repr__(self):
        return f"Snake({self.vertices} + {self.turns})"

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
    for snake in render_pass.snakes:
        for i, loc_vtx in enumerate(snake.vertices):
            snake.vertices[i] = -1 if loc_vtx == -1 else shuffle[loc_vtx]

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

    for snake in render_pass.snakes:
        for i, loc_vtx in enumerate(snake.vertices):
            if loc_vtx >= limit:
                continue
            snake.vertices[i] = -1 if loc_vtx == -1 else shuffle[loc_vtx]

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
    def tri_rotate_to(tri, index):
        if index == 0:
            return tri[0], tri[1], tri[2]
        if index == 1:
            return tri[1], tri[2], tri[0]
        if index == 2:
            return tri[2], tri[0], tri[1]

        assert False, "index must be 0, 1 or 2"

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
        arr = [v for v in triA if v not in triB]
        if not arr:
            return -1
        return arr.pop()

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
        # Not currently supported triangle rendered on top of each other flipped - some algos break badly
        if path[-1][0] == ntri[0] and path[-1][1] == ntri[2] and path[-1][2] == ntri[1]:
            return False

        if len(path) < 2:
            return True

        ptri = path[-1]
        pptri = path[-2]
        v = TriKit._v_in_triA_not_in_triB(ptri, pptri)
        # Only very awful triangles will not satisfy this condition - edge of a tri is going shared between 3 triangles
        return v in ntri

    @staticmethod
    def build_strip_tri_to_tris(tris, can_link=None):
        # Build the strips tree. The way it is built is using a temporary edge->tri mapping to link the tree...
        edge_to_tris = {}
        for tri in tris:
            # Mind that edge is flipped here because the next tri in strip will have the edge in reverse order
            for edge in TriKit._edges_reverse(tri):
                if edge not in edge_to_tris:
                    edge_to_tris[edge] = []
                edge_to_tris[edge].append(tri)

        strip_tri_to_tris = {}
        # ...and iterating the triangles again linking the triangles
        for tri in tris:
            for edge in TriKit._edges(tri):
                if edge not in edge_to_tris:
                    continue

                for ntri in edge_to_tris[edge]:
                    if can_link and not can_link(tri, ntri):
                        continue

                    if ntri not in strip_tri_to_tris:
                        strip_tri_to_tris[ntri] = set()
                    strip_tri_to_tris[ntri].add(tri)

        return strip_tri_to_tris

    @staticmethod
    def build_traverse_order(strip_tri_to_tris):
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
            return None

        dfs_tri_traverse_order = []
        for count in sorted(neighbour_count_to_tri.keys()):
            dfs_tri_traverse_order.extend(list(neighbour_count_to_tri[count]))
        
        return dfs_tri_traverse_order

    @staticmethod
    def stripify(triangles):
            rendered_triangles = triangles[:]
            if not HAS_EX3_COMMANDS:
                return rendered_triangles, []

            rendered_snakes = []
            strip_tri_to_tris = TriKit.build_strip_tri_to_tris(rendered_triangles)
            dfs_tri_traverse_order = TriKit.build_traverse_order(strip_tri_to_tris)
            if not dfs_tri_traverse_order:
                return rendered_triangles, []

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

            def remove_tri(tri):
                rendered_triangles.remove(tri)

            # Now we need to dfs through each triangle to find the strips
            # Start with lighest triangles that have the least amount of neighbours
            # Because each render pass is by amount of vertices, we can just dfs each triangle without too much cost.
            for tri in dfs_tri_traverse_order:
                # Check if it was already rendered as part of a strip
                if tri not in strip_tri_to_tris:
                    continue

                stack = [(tri, [tri])]
                longest_path = [tri]
                limit = WALK_LIMIT
                print(f"\nDFS: Starting with triangle {tri} for len {len(strip_tri_to_tris)}")
                while stack and limit:
                    limit -= 1
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

                if len(longest_path) > 2:
                    # Trim the snake tail - there is no point to store 1 triangle at the end of the strip
                    # because they can easily be expressed as regular triangles without perf cost 
                    longest_path_tail = (len(longest_path) - 5) % 8
                    if len(longest_path) > 5 and longest_path_tail == 1:
                        longest_path.pop()

                    for tri in longest_path:
                        remove_tri(tri)

                    # Need to figure out the first turn. It depends on the first 3 triangles in the path
                    t1 = longest_path[0]
                    t2 = longest_path[1]
                    t3 = longest_path[2]

                    # The pivot point is the vertex that is shared between all 3 triangles

                    # The v_pivot based options are the following:
                    #   2 - 4
                    #  / \ / \   LEFT
                    # 1 - 3 - 5
                    #
                    # 1 - 2 - 5
                    #  \ / \ /   RIGHT
                    #   3 - 4

                    # In my case pivots are 3 and 2. The difference is the 3rd triangle - it will be rendered as either 345 or 254
                    # so we need to find the vertex that belongs to t2 but not to t3 while having t1 rotated to vtx not belonging to t2:
                    v1 = TriKit._v_in_triA_not_in_triB(t1, t2)
                    t1 = TriKit._tri_rotate(t1, v1)
                    v2_or_3 = TriKit._v_in_triA_not_in_triB(t2, t3)

                    # We can tell apart left or right turns by checking where exactly v2 is in t1 - it is either in one or other side of the edge:
                    right = v2_or_3 == t1[1]
                    left  = v2_or_3 == t1[2]
                    assert left or right, "v2 must be in t1"

                    # Now we need to prepare the loops so align t1 in such a way where we can easily calculate the next turn.
                    # The bootstrapping vertex must look like the following:
                    #  LEFT     RIGHT
                    # 4 - 3      3 - 4
                    #  \ / \    / \ /
                    #   2 - 1  2 - 1
                    #           VVVVVV
                    #            2 - 4
                    #           / \ /
                    #          1 - 3

                    boot_tri = t1 if left else TriKit._tri_rotate(t1, t1[2])
                    boot_turn = SNAKE_TURN_RIGHT if right else SNAKE_TURN_LEFT

                    vertices = list(boot_tri)
                    vertices.append(TriKit._v_in_triA_not_in_triB(t2, t1))
                    turns = [boot_turn]

                    # With previous pptri + ptri, they will make a rhombus like shape (bottom pic) with '1' being on the top
                    ptri = TriKit._tri_rotate(t2, TriKit._v_in_triA_not_in_triB(t2, t1))

                    for tri in longest_path[2:]:
                        # vtx can be either on right or left side of the triangle
                        #  LEFT     RIGHT
                        # 4 - 1      1 - 4
                        #  \ / \    / \ /
                        #   3 - 2  3 - 2
                        #    \ /    \ /
                        #     x      x
                        v1 = ptri[0]
                        v4 = TriKit._v_in_triA_not_in_triB(tri, ptri)
                        left  = (v4, v1) in TriKit._edges(tri)
                        right = (v1, v4) in TriKit._edges(tri)
                        assert left or right, "edge must be in ptri"

                        turn = SNAKE_TURN_LEFT if left else SNAKE_TURN_RIGHT
                        turns.append(turn)
                        vertices.append(v4)

                        ptri = TriKit._tri_rotate(tri, v4)

                    rendered_snakes.append(Snake(vertices, turns))
                    a = 0

                # ...rest, if left, will be rendered as triangles (or maybe fans?)

            # We are converting tri to list because vtx load optimizer will want to mangle tri vertices
            # We will never need to compare the triangles so this is fine
            return rendered_triangles, rendered_snakes

class Vec3:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def __sub__(self, other):
        return Vec3(self.x - other.x, self.y - other.y, self.z - other.z)

    def __add__(self, other):
        return Vec3(self.x + other.x, self.y + other.y, self.z + other.z)

    def __mul__(self, other):
        if isinstance(other, Vec3):
            return self.x * other.x + self.y * other.y + self.z * other.z
        else:
            return Vec3(self.x * other, self.y * other, self.z * other)

    def __xor__(self, other):
        # Cross product
        return Vec3(
            self.y * other.z - self.z * other.y,
            self.z * other.x - self.x * other.z,
            self.x * other.y - self.y * other.x
        )

    def __repr__(self):
        return f"Vec3({self.x}, {self.y}, {self.z})"

class Vtx:
    def __init__(self, line):
        ls = [ tok.replace('{', '').replace('}', '').strip() for tok in line.split(',') ]
        ls = [ int(tok) for tok in ls if tok ]
        self.pos = Vec3(ls[0], ls[1], ls[2])
        self.uv = [ ls[4], ls[5] ]
        self.color = [ ls[6], ls[7], ls[8], ls[9] ]

    def __repr__(self):
        return f"Vtx(pos={self.pos}, uv={self.uv}, color={self.color})"

class BaryPreCalc:
    def __init__(self, tri):
        diffs = [ e[0].pos - e[1].pos for e in TriKit._edges(tri) ]
        diffs_length = [ diff*diff for diff in diffs ]
        diffs_min_idx = diffs_length.index(min(diffs_length))
        self.tri = TriKit.tri_rotate_to(tri, diffs_min_idx)
        self.r = [ v.pos for v in self.tri ]
        self.dr = [ e[0] - e[1] for e in TriKit._edges(self.r) ]
        self.tv = (self.r[0] - self.r[2]) ^ (self.r[1] - self.r[2])

    def try_conv(self, vtx):
        dr2 = vtx - self.r[2]
        # For barycentric coordinates to work, we must check that vtx is coplanar with the triangle
        mul = dr2 * self.tv
        len = math.sqrt((dr2 * dr2) * (self.tv * self.tv))
        if abs(mul) > len * 1e-2:
            return None

        lv0 = dr2 ^ self.dr[1]
        lv1 = dr2 ^ self.dr[2]
        dr0 = vtx - self.r[0]
        lv2 = dr0 ^ self.dr[0]

        l0 = lv0 * self.tv
        l1 = lv1 * self.tv
        l2 = lv2 * self.tv

        return l0, l1, l2

    def __repr__(self):
        return f"BaryPreCalc(t={self.t}, r={self.r}, dr={self.dr}, tv={self.tv}, tl={self.tl})"

class ModelMeshEntry(TriKit):
    def __init__(self, next_line, model, vtxopt_name):
        self._model = model
        self._name = vtxopt_name

        vtx_args = get_args(next_line)
        vtx_arg = vtx_args[0]
        vtx_arg_split = vtx_arg.split(' ')

        self._base_vertices_model_entry = ModelVtxEntry(f'static Vtx {vtxopt_name}_vtxopt[] = {{\n')
        if len(vtx_arg_split) > 1:
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

            vertices_model_name = vtx_arg_split[0]
            if self._parser_vertices_model_name != vertices_model_name:
                self._parser_vertices_model_name = vertices_model_name
                _, model_entry = self._model.find(vertices_model_name)
                self._parser_vertices_model_entry = model_entry

            if len(vtx_arg_split) > 1:
                assert '+' == vtx_arg_split[1], "incorrect vtx declaration"
                vtx_offset = int(vtx_arg_split[2])
            else:
                vtx_offset = 0

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
        triangles, snakes = TriKit.stripify(triangles)
        return RenderPass(vertices, [ list(tri) for tri in triangles ], snakes)

    def compile(self):
        assert self._base_vertices_model_entry, "compile() called twice"
        assert not self._base_vertices_model_entry.used
        self._base_vertices_model_entry.used = True
        draws = []
        vtx_entry = self._base_vertices_model_entry

        triangles_altered = False
        if True: # "cck_dl_0040_object_013EC7E4_mesh_layer_1_tri_3" in vtx_entry.name:

            # Step 0: Merge coplanar vertices
            vtx_values = [ Vtx(vtx) for vtx in self._vertices ]
            triangles = self._triangles[:]
            bary_precals = { tri: BaryPreCalc([ vtx_values[vtx] for vtx in tri ]) for tri in triangles }

            def add_tri(tri):
                print(f"Adding triangle: {tri}")
                assert not TriKit._tri_trivial(tri)
                tri = TriKit._tri_normalize(tri)
                triangles.append(tri)

            def check_barylink(tri, ntri):
                nvtx = TriKit._v_in_triA_not_in_triB(ntri, tri)
                if nvtx == -1:
                    return False

                bary_precalc = bary_precals[tri]
                nvtx_v = vtx_values[nvtx]
                bary_coords = bary_precalc.try_conv(nvtx_v.pos)
                if not bary_coords:
                    return False

                bary_total = sum(bary_coords)
                tri_weighted = list(zip(bary_coords, bary_precalc.tri))
                u_expected = sum([ w * t.uv[0]    for w, t in tri_weighted ])
                v_expected = sum([ w * t.uv[1]    for w, t in tri_weighted ])
                r_expected = sum([ w * t.color[0] for w, t in tri_weighted ])
                g_expected = sum([ w * t.color[1] for w, t in tri_weighted ])
                b_expected = sum([ w * t.color[2] for w, t in tri_weighted ])
                a_expected = sum([ w * t.color[3] for w, t in tri_weighted ])

                #u_weighted = u_expected / bary_total
                #v_weighted = v_expected / bary_total
                #r_weighted = r_expected / bary_total
                #g_weighted = g_expected / bary_total
                #b_weighted = b_expected / bary_total
                #a_weighted = a_expected / bary_total

                u_actual = nvtx_v.uv[0] * bary_total
                v_actual = nvtx_v.uv[1] * bary_total
                r_actual = nvtx_v.color[0] * bary_total
                g_actual = nvtx_v.color[1] * bary_total
                b_actual = nvtx_v.color[2] * bary_total
                a_actual = nvtx_v.color[3] * bary_total

                color_err = bary_total * 3
                uv_err    = bary_total * 10
                
                u_ok = abs(u_expected - u_actual) < uv_err
                v_ok = abs(v_expected - v_actual) < uv_err
                r_ok = abs(r_expected - r_actual) < color_err
                g_ok = abs(g_expected - g_actual) < color_err
                b_ok = abs(b_expected - b_actual) < color_err
                a_ok = abs(a_expected - a_actual) < color_err

                return u_ok and v_ok and r_ok and g_ok and b_ok and a_ok

            strip_tri_to_tris = TriKit.build_strip_tri_to_tris(self._triangles, check_barylink)
            tri_traverse_order = TriKit.build_traverse_order(strip_tri_to_tris)
            if tri_traverse_order:
                for tri in tri_traverse_order:
                    # Check if it was already rendered as part of a strip
                    if tri not in strip_tri_to_tris:
                        continue

                    ngon = list(tri)
                    ngon_tris = set()
                    ngon_tris.add(tri)

                    # Instead of DFS, use BFS for improved quality for generated ngon
                    stack = deque() 
                    stack.appendleft(tri)
                    while stack:
                        curr = stack.pop()
                        if not curr in strip_tri_to_tris:
                            continue
                        for ntri in strip_tri_to_tris[curr]:
                            if ntri in ngon_tris:
                                continue

                            # Can continue?
                            nvtx = TriKit._v_in_triA_not_in_triB(ntri, curr)
                            ntrir = TriKit._tri_rotate(ntri, nvtx)
                            try:
                                e1i = ngon.index(ntrir[1])
                            except ValueError:
                                assert False

                            e2i = e1i - 1 if e1i > 0 else len(ngon) - 1
                            e2 = ngon[e2i]
                            assert e2 == ntrir[2]

                            # Is sane continuation? - does not work as expected atm
                            #fail = False
                            #for ngon_tri in ngon_tris:
                            #    bary_calc = bary_precals[ngon_tri]
                            #    bary_coords = bary_calc.try_conv(vtx_values[nvtx].pos)
                            #    assert bary_coords, "barycentric coordinates must be valid"
                            #    # If all barycentric coordinates are positive, then the triangle is inside the ngon - we cannot allow that for continuation
                            #    if (bary_coords[0] >= 0 and bary_coords[1] >= 0 and bary_coords[2] >= 0) or \
                            #       (bary_coords[0] <= 0 and bary_coords[1] <= 0 and bary_coords[2] <= 0):
                            #        fail = True
                            #        break
                            #
                            #if fail:
                            #    continue

                            assert nvtx not in ngon
                            ngon.insert(e2i + 1, nvtx)
                            ngon_tris.add(ntri)
                            stack.appendleft(ntri)

                    bary_tri = bary_precals[tri]
                    pivot = bary_tri.dr[0]
                    pivot_dir = bary_tri.tv
                    pivot_maxdir = pivot ^ pivot_dir

                    # Mark tris as used
                    for tri in ngon_tris:
                        if not tri in strip_tri_to_tris:
                            continue
                        for ntri in strip_tri_to_tris.pop(tri):
                            if ntri in strip_tri_to_tris:
                                strip_tri_to_tris[ntri].discard(tri)
                                if not strip_tri_to_tris[ntri]:
                                    del strip_tri_to_tris[ntri]

                    # Try to reduce amount of vertices in ngon
                    if len(ngon) <= 4:
                        continue

                    print(ngon)
                    changed = False
                    ngon_values = [ vtx_values[vtx] for vtx in ngon ]
                    iter = 1
                    # TODO: iter must be also ==len(ngon) to handle the last vertex
                    while iter <= len(ngon):
                        vp = ngon_values[iter - 2]
                        vc = ngon_values[iter - 1]
                        vn = ngon_values[0 if iter == len(ngon) else iter]

                        dvp = vp.pos - vc.pos
                        dvpl = dvp * dvp
                        dvn = vn.pos - vc.pos
                        dvnl = dvn * dvn

                        dvx = dvp ^ dvn
                        dvxl = dvx * dvx * 100
                        if dvxl < dvpl * dvnl:
                            changed = True
                            del ngon[iter - 1]
                            del ngon_values[iter - 1]
                        else:
                            iter += 1

                    if not changed:
                        continue

                    # Get rid of all triangles that are were part of the ngon...
                    triangles_altered = True
                    for tri in ngon_tris:
                        del triangles[triangles.index(tri)]

                    # ...and retriangulate the ngon.
                    # Calculate the angle cache for all edges of the ngonx
                    #angle_edge_cache = {}
                    #def angle_cached(i1, i2):
                    #    pp = ngon[i1]
                    #    pc = ngon[i2]
                    #    if (pp, pc) in angle_edge_cache:
                    #        return angle_edge_cache[(pp, pc)]
                    #    pvp = ngon_values[i1].pos
                    #    pvc = ngon_values[i2].pos
                    #    ev = pvc - pvp
                    #    angle = math.acos(pivot * ev / math.sqrt((ev * ev) * (pivot * pivot)))
                    #    angle_edge_cache[(pp, pc)] = angle
                    #    return angle

                    while len(ngon) > 4:
                        # For this find convex hull of the ngon first

                        # Find the first point that has the largest distance from the pivot
                        max_point = ngon_values[0].pos
                        max_i = 0
                        for i, tri in enumerate(ngon_values[1:]):
                            dp = max_point - tri.pos
                            mul = dp * pivot_maxdir
                            if mul > 0:
                                max_point = tri.pos
                                max_i = i + 1

                        # Start builing the convex hull with the max point
                        # !!! Mind that indices in 'hull' are indices in 'ngon' !!!
                        hull_by_ngon_indices = [max_i]
                        hull_cur_vec = pivot
                        hull_cur = max_point
                        while True:
                            print(f"Current hull: {hull_by_ngon_indices} ~> {[ngon[i] for i in hull_by_ngon_indices]}")
                            max_i = -1
                            max_a = -2
                            for i, vc in enumerate(ngon_values):
                                if i == hull_by_ngon_indices[-1]:
                                    continue

                                dv = vc.pos - hull_cur
                                # only consider positive turns.... - pointless because points are selected carefully already
                                #dvm = dv ^ hull_cur_vec
                                #print(f"Turn between {hull[-1]} and {i}: {dvm} and {dvm * pivot_dir}")
                                #if dvm * pivot_dir < 0:
                                #    continue

                                # ...and pick the one with the largest angle (will be between -1 and 1)
                                dva = (dv * hull_cur_vec) / (math.sqrt(dv*dv) * math.sqrt(hull_cur_vec*hull_cur_vec))
                                print(f"Angle between {ngon[hull_by_ngon_indices[-1]]} and {ngon[i]}: {dva}")
                                if dva > max_a:
                                    max_a = dva
                                    max_i = i
                                    max_point = vc.pos
                            
                            if max_i == hull_by_ngon_indices[0]:
                                break

                            hull_by_ngon_indices.append(max_i)
                            hull_cur_vec = max_point - hull_cur
                            hull_cur = max_point

                        # Setify the hull to know which edges are part of ears
                        ears_indices = []
                        for i in range(len(hull_by_ngon_indices)):
                            i_p = hull_by_ngon_indices[i-1]
                            i_c = hull_by_ngon_indices[i+0]
                            i_n = hull_by_ngon_indices[(i+1) % len(hull_by_ngon_indices)]

                            i_pexp = (i_c + 1) % len(ngon)
                            i_nexp = (i_c - 1 + len(ngon)) % len(ngon)

                            if i_pexp == i_p and i_nexp == i_n:
                                ears_indices.append(i_c)

                        assert len(ears_indices) >= 2, "there must be at least two ears in the ngon"
                        if len(ears_indices) == len(ngon):
                            fan = [ ngon[0], ngon[1], ngon[2] ]
                            add_tri(tuple(fan))
                            for vtx in ngon[3:]:
                                fan[1] = fan[2]
                                fan[2] = vtx
                                add_tri(tuple(fan))
                            ngon = []
                            break
                        else:
                            # TODO: This is inefficient, vertices are already sorted properly so we have to just check for the sides
                            #       The painful part is the checks on the very ends that must be carefully addressed
                            banned_indices = set()
                            filtered_ears = []
                            for index in sorted(ears_indices):
                                if index in banned_indices:
                                    continue

                                banned_indices.add((index - 1 + len(ngon)) % len(ngon))
                                banned_indices.add((index + 1) % len(ngon))
                                filtered_ears.append(index)

                            ear_diff = 0
                            for ear_undiff in filtered_ears:
                                if len(ngon) <= 4:
                                    break

                                ear = ear_undiff - ear_diff
                                add_tri((ngon[(ear - 1)], ngon[ear], ngon[(ear + 1) % len(ngon)]))
                                del ngon[ear]
                                del ngon_values[ear]
                                ear_diff += 1
                    
                    if len(ngon) == 3:
                        add_tri(tuple(ngon))
                        pass
                    elif len(ngon) == 4:
                        pass
                        add_tri(tuple(ngon[:3]))
                        add_tri((ngon[0], ngon[2], ngon[3]))
                    elif len(ngon) == 0:
                        pass
                    else:
                        assert False, "ngon must be 3 or 4 vertices long"

        if triangles_altered:
            #self._triangles = [ triangles[0], triangles[1], triangles[2] ]
            self._triangles = triangles

        # Step 1: Generate render passes for each vertex set
        render_passes = []

        # For a grand majority of cases "just draw" will be good enough - that's when all vertices fit in the buffer
        if len(self._vertices) <= 56:
            passthru_vertices = {}
            for i in range(len(self._vertices)):
                passthru_vertices[i] = i

            render_passes.append(self._make_render_pass(self._triangles, passthru_vertices))
        else:
            # This is a primitive greedy algorithm for loading vertices with weights
            total_pricer = UsagePricer(self._triangles)
            while not total_pricer.completed():
                loaded_vertices = {}
                rendered_triangles = []

                # TODO: When 2nd condition triggers, it usually means that the pool of vertices has depleted and it is better to stop 
                while not total_pricer.completed() and len(loaded_vertices) < 56:
                    highest_usage_vtx = total_pricer.highest_usage()
                    loaded_vertices[highest_usage_vtx] = len(loaded_vertices)

                    candidate_vtxs = set()
                    candidate_tris = set()
                    banned_vertices = set(loaded_vertices.keys())
                    log_debug("")
                    while True:
                        log_debug(f"{loaded_vertices}")
                        banned_vertices.add(highest_usage_vtx)
                        highest_usage_vtx_triangles = list(total_pricer.vtx_to_tris(highest_usage_vtx))
                        for tri in highest_usage_vtx_triangles:
                            loaded_tri = [ loaded_vertices.get(vtx) for vtx in tri ]
                            log_debug(f"{tri} -> {loaded_tri}")
                            if not None in loaded_tri:
                                log_debug(f"render {tri} as {loaded_tri}")
                                rendered_triangles.append(tuple(loaded_tri))
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

                        candidate_to_load_pricer = UsagePricer(candidate_tris, loaded_vertices, rendered_triangles, banned_vertices)
                        if candidate_to_load_pricer.completed() or len(loaded_vertices) == 56:
                            break

                        highest_usage_vtx = candidate_to_load_pricer.highest_usage()
                        loaded_vertices[highest_usage_vtx] = len(loaded_vertices)

                render_passes.append(self._make_render_pass(rendered_triangles, loaded_vertices))

        # Step 2: Find common vertices across render passes and pin them to the left side of the buffer
        render_pass_vtx_load_offsets = []
        prev_render_pass = None
        pinned_vertices_left = None
        altered_render_passes = []
        for i, render_pass in enumerate(render_passes):
            curr_vertices = set(render_pass.vertices.keys())
            log_debug(f"render pass {i} -> {curr_vertices}")
            if prev_render_pass:
                prev_vertices = prev_render_pass.vertices
                common_vertices = set(prev_vertices.keys()).intersection(curr_vertices)
                if common_vertices:
                    log_debug(f"common vertices {common_vertices}, length {len(common_vertices)}")
                    if not pinned_vertices_left:
                        # Perform the first shuffling and pin the common vertices on the left vbo
                        common_vertices = list(common_vertices)
                        altered_render_passes.append(prev_render_pass)
                        altered_render_passes.append(render_pass)
                        for altered_render_pass in altered_render_passes:
                            shuffle = make_shuffle_pinning_shared(altered_render_pass.vertices, common_vertices)
                            log_debug(f"apply shuffle {shuffle}")
                            log_debug(f"render pass vtx before shuffle {altered_render_pass.vertices}")
                            apply_shuffle(altered_render_pass, shuffle)
                            log_debug(f"render pass vtx after shuffle -> {altered_render_pass.vertices}")

                        pinned_vertices_left = common_vertices
                    else:
                        # There is already a pinned buffer on the left side.
                        # We might be able to reuse some of the common vertices, all other vertices
                        # can be repinned to the right side of the buffer.
                        repinned_vertices_left = common_vertices.intersection(pinned_vertices_left)
                        unpinned_vertices_right = common_vertices.difference(pinned_vertices_left)
                        log_debug(f"repinned vertices left {repinned_vertices_left}")
                        if repinned_vertices_left:
                            # Shrink the left buffer to only contain the common vertices...

                            # Make the sub-shuffle of length 'len(pinned_vertices_left)' that spans across all 'altered_render_passes'
                            # Remember that shuffle must be applied to all altered render passes and it must be exactly the same shuffle
                            shuffle = make_shuffle_pinning_shared_limited(altered_render_passes[0].vertices, repinned_vertices_left, len(pinned_vertices_left))
                            log_debug(f"apply pinning limited shuffle {shuffle}")
                            for altered_render_pass in altered_render_passes:
                                log_debug(f"render pass vtx before pinning limited shuffle {altered_render_pass.vertices}")
                                apply_shuffle_limited(altered_render_pass, shuffle, len(pinned_vertices_left))
                                log_debug(f"render pass vtx after pinning limited shuffle {altered_render_pass.vertices}")

                            pinned_vertices_left = list(repinned_vertices_left)

                            shuffle = make_shuffle_pinning_shared(render_pass.vertices, pinned_vertices_left)
                            log_debug(f"apply pinning shuffle {shuffle}")
                            log_debug(f"render pass vtx before pinning shuffle {render_pass.vertices}")
                            apply_shuffle(render_pass, shuffle)
                            log_debug(f"render pass vtx after pinning shuffle {render_pass.vertices}")
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

            log_debug(f"render pass out {render_pass.vertices} at {vtx_load_offset}")
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

            for snake in render_pass.snakes:
                draws.extend(snake.stringify_x())

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
            if line.startswith('//'):
                continue

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

        num = 0
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
                    entry = ModelMeshEntry(line, model, f'{mlist.name}_{num}')
                    num += 1 
                entry.add(line)
                
                if 'gsSPVertex' in line:
                    vtx_args = get_args(line)
                    vtx_arg = vtx_args[0]
                    vtx_arg_split = vtx_arg.split(' ')
                    _, vtx = model.find(vtx_arg_split[0])
                    vtx.used = True

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
            for line in strip.stringify_x():
                f_model.write(line)

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
