#include "src/game/envfx_snow.h"

const GeoLayout mhe_meteobig_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, mhe_meteobig_mhe_meteobig_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, (s16)131.75000190734863, (s16)195.5000114440918, (s16)29.749999046325684, mhe_meteobig_001_object_00D3D64C_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, mhe_meteobig_002_object_00D3D484_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
