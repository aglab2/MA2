#include "src/game/envfx_snow.h"

const GeoLayout fight_plat_shadow_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, fight_plat_shadow_Plane_001_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, fight_plat_shadow_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
