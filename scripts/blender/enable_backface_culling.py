import bpy

for obj in bpy.context.scene.objects:
    if obj.type == 'MESH':
        for slot_index, material in enumerate(obj.data.materials):
            if not material:
                continue

            f3dMat = material.f3d_mat
            f3dMat.rdp_settings.g_cull_back = True
            material.use_backface_culling = f3dMat.rdp_settings.g_cull_back
