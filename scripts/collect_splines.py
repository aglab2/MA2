import os
import sys

def deduce_level_name(name):
    idx = name.rfind('/')
    return name[idx + 1:]

def get_args(line):
    bracket_open = line.find('(')
    bracket_close = line.rfind(')')
    return [arg.strip() for arg in line[bracket_open+1:bracket_close].split(',') ]

if '__main__' in __name__:
    lvl_path = sys.argv[1]
    lvl_name = deduce_level_name(lvl_path)

    areas = []
    areas_count = 0
    have_rails = False
    have_springs = False
    for i in range(1, 16):
        area_path = f"{lvl_path}/area_{i}"
        area_spline_path = f"{area_path}/spline.inc.c"
        if not os.path.exists(area_spline_path):
            break

        area_rails = []
        area_springs = []
        area_loops = []

        prev_traj_pos = None
        area_spline_lines = []

        with open(area_spline_path, 'r') as f:
            while True:
                line = f.readline()
                if not line:
                    break

                area_spline_lines.append(line)

                if 'TRAJECTORY_POS' in line:
                    args = get_args(line)
                    pos = args[1:4]
                    if '-1' != args[0] and prev_traj_pos and pos == prev_traj_pos:
                        # Do not allow duplicate trajectory positions, it will break the game
                        area_spline_lines.pop()

                    prev_traj_pos = pos
                    continue

                prev_traj_pos = None
                if 'Trajectory' not in line:
                    continue

                spline_name = line.split(' ')[2].strip().strip('[]')
                if 'Rail' in spline_name:
                    area_rails.append(spline_name)
                    continue
                elif 'Spring' in spline_name:
                    area_springs.append(spline_name)
                    continue
                elif 'Loop' in spline_name:
                    area_loops.append(spline_name)
                    continue
                else:
                    assert False, f"Unknown spline type: {spline_name}"

        with open(area_spline_path, 'w') as f:
            for line in area_spline_lines:
                f.write(line)

        area = {}
        if area_rails:
            area['rails'] = area_rails
            have_rails = True
        if area_springs:
            area['springs'] = area_springs
            have_springs = True
        if area_loops:
            area['loops'] = area_loops
            have_rails = True

        if area:
            areas.append((i, area))

        areas_count = max(areas_count, i)

    areas_rails_path = f'{lvl_path}/rails.inc.c'
    with open(areas_rails_path, 'w') as f:
        generated_names = set()
        for i, area in areas:
            if 'springs' in area:
                springs = area['springs']
                name = f"spring_area{i}"
                generated_names.add(name)

                f.write(f"static const SpringDesc {name}[] = {{\n")
                for spring in springs:
                    f.write(f"\t{spring},\n")
                f.write("\tNULL\n")
                f.write("};\n\n")

            if 'rails' in area or 'loops' in area:
                rails = area['rails'] if 'rails' in area else []
                loops = area['loops'] if 'loops' in area else []
                name = f"rails_area{i}"
                generated_names.add(name)

                f.write(f"static const RailDesc {name}[] = {{\n")
                for rail in rails:
                    f.write(f"\tRAIL_TRAJ({rail}),\n")
                for loop in loops:
                    f.write(f"\tLOOP_TRAJ({loop}, loop_desc_{loop}),\n")
                f.write("\tRAIL_END\n")
                f.write("};\n\n")

        if have_springs:
            f.write(f"const SpringDesc* spring_descs_{lvl_name}[] = {{\n")
            for i in range(1, areas_count + 1):
                name = f"spring_area{i}"
                if name in generated_names:
                    f.write(f"\t{name},\n")
                else:
                    f.write(f"\tNULL,\n")

            f.write("};\n\n")

        if have_rails:
            f.write(f"const RailDesc* rail_descs_{lvl_name}[] = {{\n")
            for i in range(1, areas_count + 1):
                name = f"rails_area{i}"
                if name in generated_names:
                    f.write(f"\t{name},\n")
                else:
                    f.write(f"\tNULL,\n")

            f.write("};\n\n")
