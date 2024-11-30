import bpy

# Iterate over all objects in the current scene
for obj in bpy.context.scene.objects:
    # Example: Check if it's a mesh object and print its vertices
    if obj.type == 'MESH':
        mesh = obj.data
        try:
            num = int(obj.name.split('_')[0])
            print(num)
            if num < 2376:
                obj.ignore_collision = True
                obj.ignore_render = False
            else:
                obj.ignore_collision = False   
                obj.ignore_render = True 
			obj.use_f3d_culling = False
        except:
            pass
