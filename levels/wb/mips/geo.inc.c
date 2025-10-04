// 0x0D000448
const GeoLayout mips_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0x96, 100),
   GEO_OPEN_NODE(),
      GEO_SCALE(0x00, 16384),
      GEO_OPEN_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, wb_chao_001_object_00071374_001_mesh_layer_1), // body
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 64, 0, 0, wb_chao_016_object_0006F84C_001_mesh_layer_1), // head
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 52, -24, -32, NULL),
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, wb_chao_010_object_00070134_001_mesh_layer_1), // ear
                     GEO_OPEN_NODE(),
                        GEO_ANIMATED_PART(LAYER_OPAQUE, 79, 0, 0, NULL), // ear2
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 52, -24, 32, NULL),
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, wb_chao_003_object_00070DC4_001_mesh_layer_1), // ear
                     GEO_OPEN_NODE(),
                        GEO_ANIMATED_PART(LAYER_OPAQUE, 79, 0, 0, NULL), // ear2
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, -31, 4, -39, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL), // leg1
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 45, 0, 0, NULL), // leg2
                     GEO_OPEN_NODE(),
                        GEO_ANIMATED_PART(LAYER_OPAQUE, 52, 0, 0, wb_chao_013_object_0006FC8C_001_mesh_layer_1), // foot
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, -31, 4, 40, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL), // leg1
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 45, 0, 0, NULL), // leg2
                     GEO_OPEN_NODE(),
                        GEO_ANIMATED_PART(LAYER_OPAQUE, 52, 0, 0, wb_chao_006_object_0007091C_001_mesh_layer_1), // foot
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

UNUSED static const u64 mips_unused_1 = 0;
