from mesh_optimizer import *
import os

if '__main__' in __name__:
    lvl_path = sys.argv[1]
    model_path = lvl_path + '/visual/model_lvl.inc.c'

    model_patched_path = make_opt_name(model_path)
    header_path = lvl_path + '/visual/header_lvl.inc.h'
    header_patched_path = make_opt_name(header_path)

    model = load_model(model_path)
    optimize_model(model)
    serialize_model(model, model_patched_path)
    patch_header(header_path, header_patched_path)
