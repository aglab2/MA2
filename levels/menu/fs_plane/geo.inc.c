#include "src/game/envfx_snow.h"

const GeoLayout fs_plane_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, fs_plane_fs_plane_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
