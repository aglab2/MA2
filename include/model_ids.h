#ifndef MODEL_IDS_H
#define MODEL_IDS_H

#define MODEL_NONE                             0x00

/* Global models that are loaded for every level */

#define MODEL_MARIO                            0x01        // mario_geo
#define MODEL_LUIGI                            0x02        // unused

/* Various static level geometry, the geo layout differs but terrain object presets treat them the same.*/

#define MODEL_LEVEL_GEOMETRY_03                0x03
#define MODEL_LEVEL_GEOMETRY_04                0x04
#define MODEL_LEVEL_GEOMETRY_05                0x05
#define MODEL_LEVEL_GEOMETRY_06                0x06
#define MODEL_LEVEL_GEOMETRY_07                0x07
#define MODEL_LEVEL_GEOMETRY_08                0x08
#define MODEL_LEVEL_GEOMETRY_09                0x09
#define MODEL_LEVEL_GEOMETRY_0A                0x0A
#define MODEL_LEVEL_GEOMETRY_0B                0x0B
#define MODEL_LEVEL_GEOMETRY_0C                0x0C
#define MODEL_LEVEL_GEOMETRY_0D                0x0D
#define MODEL_LEVEL_GEOMETRY_0E                0x0E
#define MODEL_LEVEL_GEOMETRY_0F                0x0F
#define MODEL_LEVEL_GEOMETRY_10                0x10
#define MODEL_LEVEL_GEOMETRY_11                0x11
#define MODEL_LEVEL_GEOMETRY_12                0x12
#define MODEL_LEVEL_GEOMETRY_13                0x13
#define MODEL_LEVEL_GEOMETRY_14                0x14
#define MODEL_LEVEL_GEOMETRY_15                0x15
#define MODEL_LEVEL_GEOMETRY_16                0x16

#define MODEL_BOB_BUBBLY_TREE                  0x17        // bubbly_tree_geo
#define MODEL_WDW_BUBBLY_TREE                  0x17        // bubbly_tree_geo
#define MODEL_CASTLE_GROUNDS_BUBBLY_TREE       0x17        // bubbly_tree_geo
#define MODEL_WF_BUBBLY_TREE                   0x17        // bubbly_tree_geo
#define MODEL_THI_BUBBLY_TREE                  0x17        // bubbly_tree_geo
#define MODEL_COURTYARD_SPIKY_TREE             0x18        // spiky_tree_geo
#define MODEL_CCM_SNOW_TREE                    0x19        // snow_tree_geo
#define MODEL_SL_SNOW_TREE                     0x19        // snow_tree_geo
#define MODEL_UNKNOWN_TREE_1A                  0x1A        // referenced in special presets, undefined
#define MODEL_SSL_PALM_TREE                    0x1B        // palm_tree_geo
#define MODEL_CASTLE_CASTLE_DOOR_UNUSED        0x1C        // castle_door_geo - unused, original id
#define MODEL_CASTLE_WOODEN_DOOR_UNUSED        0x1D        // wooden_door_geo - unused, original id
#define MODEL_BBH_HAUNTED_DOOR                 0x1D        // haunted_door_geo
#define MODEL_HMC_WOODEN_DOOR                  0x1D        // wooden_door_geo
#define MODEL_UNKNOWN_DOOR_1E                  0x1E        // referenced in special presets, undefined
#define MODEL_HMC_METAL_DOOR                   0x1F        // metal_door_geo
#define MODEL_HMC_HAZY_MAZE_DOOR               0x20        // hazy_maze_door_geo
#define MODEL_UNKNOWN_DOOR_21                  0x21        // referenced in special presets, undefined
#define MODEL_CASTLE_DOOR_0_STARS              0x22        // castle_door_0_star_geo
#define MODEL_CASTLE_DOOR_1_STAR               0x23        // castle_door_1_star_geo
#define MODEL_CASTLE_DOOR_3_STARS              0x24        // castle_door_3_stars_geo
#define MODEL_CASTLE_KEY_DOOR                  0x25        // key_door_geo
#define MODEL_CASTLE_CASTLE_DOOR               0x26        // castle_door_geo - used duplicate
#define MODEL_CASTLE_GROUNDS_CASTLE_DOOR       0x26        // castle_door_geo - used duplicate
#define MODEL_CASTLE_WOODEN_DOOR               0x27        // wooden_door_geo
#define MODEL_COURTYARD_WOODEN_DOOR            0x27        // wooden_door_geo
#define MODEL_CCM_CABIN_DOOR                   0x27        // cabin_door_geo
#define MODEL_UNKNOWN_DOOR_28                  0x28        // referenced in special presets, undefined
#define MODEL_CASTLE_METAL_DOOR                0x29        // metal_door_geo
#define MODEL_CASTLE_GROUNDS_METAL_DOOR        0x29        // metal_door_geo
#define MODEL_UNKNOWN_DOOR_2A                  0x2A        // referenced in special presets, undefined
#define MODEL_UNKNOWN_DOOR_2B                  0x2B        // referenced in special presets, undefined
#define MODEL_WF_TOWER_TRAPEZOID_PLATORM       0x2C        // wf_geo_000AF8 - unused
#define MODEL_WF_TOWER_SQUARE_PLATORM          0x2D        // wf_geo_000B10
#define MODEL_WF_TOWER_SQUARE_PLATORM_UNUSED   0x2E        // wf_geo_000B38 - unused & duplicated
#define MODEL_WF_TOWER_SQUARE_PLATORM_ELEVATOR 0x2F        // wf_geo_000B60 - elevator platorm

// Level model IDs

// bbh
#define MODEL_BBH_STAIRCASE_STEP               0x35        // geo_bbh_0005B0
#define MODEL_BBH_TILTING_FLOOR_PLATFORM       0x36        // geo_bbh_0005C8
#define MODEL_BBH_TUMBLING_PLATFORM            0x37        // geo_bbh_0005E0
#define MODEL_BBH_TUMBLING_PLATFORM_PART       0x38        // geo_bbh_0005F8
#define MODEL_BBH_MOVING_BOOKSHELF             0x39        // geo_bbh_000610
#define MODEL_BBH_MESH_ELEVATOR                0x3A        // geo_bbh_000628
#define MODEL_BBH_MERRY_GO_ROUND               0x3B        // geo_bbh_000640
#define MODEL_BBH_WOODEN_TOMB                  0x3C        // geo_bbh_000658

// ccm
#define MODEL_CCM_ROPEWAY_LIFT                 0x36        // ccm_geo_0003D0
#define MODEL_CCM_SNOWMAN_HEAD                 0x37        // ccm_geo_00040C

// castle
#define MODEL_CASTLE_BOWSER_TRAP               0x35        // castle_geo_000F18
#define MODEL_CASTLE_WATER_LEVEL_PILLAR        0x36        // castle_geo_001940
#define MODEL_CASTLE_CLOCK_MINUTE_HAND         0x37        // castle_geo_001530
#define MODEL_CASTLE_CLOCK_HOUR_HAND           0x38        // castle_geo_001548
#define MODEL_CASTLE_CLOCK_PENDULUM            0x39        // castle_geo_001518

// hmc
#define MODEL_HMC_METAL_PLATFORM               0x36        // hmc_geo_0005A0
#define MODEL_HMC_METAL_ARROW_PLATFORM         0x37        // hmc_geo_0005B8
#define MODEL_HMC_ELEVATOR_PLATFORM            0x38        // hmc_geo_0005D0
#define MODEL_HMC_ROLLING_ROCK                 0x39        // hmc_geo_000548
#define MODEL_HMC_ROCK_PIECE                   0x3A        // hmc_geo_000570 - unused
#define MODEL_HMC_ROCK_SMALL_PIECE             0x3B        // hmc_geo_000588 - unused
#define MODEL_HMC_RED_GRILLS                   0x3C        // hmc_geo_000530

// ssl
#define MODEL_SSL_PYRAMID_TOP                  0x3A        // ssl_geo_000618
#define MODEL_SSL_GRINDEL                      0x36        // ssl_geo_000734
#define MODEL_SSL_SPINDEL                      0x37        // ssl_geo_000764
#define MODEL_SSL_MOVING_PYRAMID_WALL          0x38        // ssl_geo_000794
#define MODEL_SSL_PYRAMID_ELEVATOR             0x39        // ssl_geo_0007AC

// bob
#define MODEL_BOB_CHAIN_CHOMP_GATE             0x36        // bob_geo_000440
#define MODEL_BOB_SEESAW_PLATFORM              0x37        // bob_geo_000458
#define MODEL_BOB_BARS_GRILLS                  0x38        // bob_geo_000470

// sl
#define MODEL_SL_SNOW_TRIANGLE                 0x36        // sl_geo_000390
#define MODEL_SL_CRACKED_ICE                   0x37        // sl_geo_000360 - unused
#define MODEL_SL_CRACKED_ICE_CHUNK             0x38        // sl_geo_000378 - unused

// wdw
#define MODEL_WDW_SQUARE_FLOATING_PLATFORM        0x36        // wdw_geo_000580
#define MODEL_WDW_ARROW_LIFT                      0x37        // wdw_geo_000598
#define MODEL_WDW_WATER_LEVEL_DIAMOND             0x38        // wdw_geo_0005C0
#define MODEL_WDW_HIDDEN_PLATFORM                 0x39        // wdw_geo_0005E8
#define MODEL_WDW_EXPRESS_ELEVATOR                0x3A        // wdw_geo_000610
#define MODEL_WDW_RECTANGULAR_FLOATING_PLATFORM   0x3B        // wdw_geo_000628
#define MODEL_WDW_ROTATING_PLATFORM               0x3C        // wdw_geo_000640

// jrb
#define MODEL_JRB_SHIP_LEFT_HALF_PART             0x35        // jrb_geo_000978
#define MODEL_JRB_SHIP_BACK_LEFT_PART             0x36        // jrb_geo_0009B0
#define MODEL_JRB_SHIP_RIGHT_HALF_PART            0x37        // jrb_geo_0009E8
#define MODEL_JRB_SHIP_BACK_RIGHT_PART            0x38        // jrb_geo_000A00
#define MODEL_JRB_SUNKEN_SHIP                     0x39        // jrb_geo_000990
#define MODEL_JRB_SUNKEN_SHIP_BACK                0x3A        // jrb_geo_0009C8
#define MODEL_JRB_ROCK                            0x3B        // jrb_geo_000930
#define MODEL_JRB_SLIDING_BOX                     0x3C        // jrb_geo_000960
#define MODEL_JRB_FALLING_PILLAR                  0x3D        // jrb_geo_000900
#define MODEL_JRB_FALLING_PILLAR_BASE             0x3E        // jrb_geo_000918
#define MODEL_JRB_FLOATING_PLATFORM               0x3F        // jrb_geo_000948

// thi
#define MODEL_THI_HUGE_ISLAND_TOP                 0x36        // thi_geo_0005B0
#define MODEL_THI_TINY_ISLAND_TOP                 0x37        // thi_geo_0005C8

// ttc
#define MODEL_TTC_ROTATING_CUBE                   0x36        // ttc_geo_000240
#define MODEL_TTC_ROTATING_PRISM                  0x37        // ttc_geo_000258
#define MODEL_TTC_PENDULUM                        0x38        // ttc_geo_000270
#define MODEL_TTC_LARGE_TREADMILL                 0x39        // ttc_geo_000288
#define MODEL_TTC_SMALL_TREADMILL                 0x3A        // ttc_geo_0002A8
#define MODEL_TTC_PUSH_BLOCK                      0x3B        // ttc_geo_0002C8
#define MODEL_TTC_ROTATING_HEXAGON                0x3C        // ttc_geo_0002E0
#define MODEL_TTC_ROTATING_TRIANGLE               0x3D        // ttc_geo_0002F8
#define MODEL_TTC_PIT_BLOCK                       0x3E        // ttc_geo_000310 - has 2 vertical stripes
#define MODEL_TTC_PIT_BLOCK_UNUSED                0x3F        // ttc_geo_000328 - has 3 vertical stripes, unused
#define MODEL_TTC_ELEVATOR_PLATFORM               0x40        // ttc_geo_000340
#define MODEL_TTC_CLOCK_HAND                      0x41        // ttc_geo_000358
#define MODEL_TTC_SPINNER                         0x42        // ttc_geo_000370
#define MODEL_TTC_SMALL_GEAR                      0x43        // ttc_geo_000388
#define MODEL_TTC_LARGE_GEAR                      0x44        // ttc_geo_0003A0

// rr
#define MODEL_RR_SLIDING_PLATFORM                 0x36        // rr_geo_0008C0
#define MODEL_RR_FLYING_CARPET                    0x37        // rr_geo_000848
#define MODEL_RR_OCTAGONAL_PLATFORM               0x38        // rr_geo_0008A8
#define MODEL_RR_ROTATING_BRIDGE_PLATFORM         0x39        // rr_geo_000878
#define MODEL_RR_TRIANGLE_PLATFORM                0x3A        // rr_geo_0008D8 - unused
#define MODEL_RR_CRUISER_WING                     0x3B        // rr_geo_000890
#define MODEL_RR_SEESAW_PLATFORM                  0x3C        // rr_geo_000908
#define MODEL_RR_L_SHAPED_PLATFORM                0x3D        // rr_geo_000940 - unused
#define MODEL_RR_SWINGING_PLATFORM                0x3E        // rr_geo_000860
#define MODEL_RR_DONUT_PLATFORM                   0x3F        // rr_geo_000920
#define MODEL_RR_ELEVATOR_PLATFORM                0x40        // rr_geo_0008F0
#define MODEL_RR_TRICKY_TRIANGLES                 0x41        // rr_geo_000958
#define MODEL_RR_TRICKY_TRIANGLES_FRAME1          0x42        // rr_geo_000970
#define MODEL_RR_TRICKY_TRIANGLES_FRAME2          0x43        // rr_geo_000988
#define MODEL_RR_TRICKY_TRIANGLES_FRAME3          0x44        // rr_geo_0009A0
#define MODEL_RR_TRICKY_TRIANGLES_FRAME4          0x45        // rr_geo_0009B8

// castle grounds

// bitdw
#define MODEL_BITDW_SQUARE_PLATFORM               0x36        // geo_bitdw_000558
#define MODEL_BITDW_SEESAW_PLATFORM               0x37        // geo_bitdw_000540
#define MODEL_BITDW_SLIDING_PLATFORM              0x38        // geo_bitdw_000528
#define MODEL_BITDW_FERRIS_WHEEL_AXLE             0x39        // geo_bitdw_000570
#define MODEL_BITDW_BLUE_PLATFORM                 0x3A        // geo_bitdw_000588
#define MODEL_BITDW_STAIRCASE_FRAME4              0x3B        // geo_bitdw_0005A0
#define MODEL_BITDW_STAIRCASE_FRAME3              0x3C        // geo_bitdw_0005B8
#define MODEL_BITDW_STAIRCASE_FRAME2              0x3D        // geo_bitdw_0005D0
#define MODEL_BITDW_STAIRCASE_FRAME1              0x3E        // geo_bitdw_0005E8
#define MODEL_BITDW_STAIRCASE                     0x3F        // geo_bitdw_000600

// vcutm
#define MODEL_VCUTM_SEESAW_PLATFORM               0x36        // vcutm_geo_0001F0

// bitfs
#define MODEL_BITFS_PLATFORM_ON_TRACK             0x36        // bitfs_geo_000758
#define MODEL_BITFS_TILTING_SQUARE_PLATFORM       0x37        // bitfs_geo_0006C0
#define MODEL_BITFS_SINKING_PLATFORMS             0x38        // bitfs_geo_000770
#define MODEL_BITFS_BLUE_POLE                     0x39        // bitfs_geo_0006A8
#define MODEL_BITFS_SINKING_CAGE_PLATFORM         0x3A        // bitfs_geo_000690
#define MODEL_BITFS_ELEVATOR                      0x3B        // bitfs_geo_000678
#define MODEL_BITFS_STRETCHING_PLATFORMS          0x3C        // bitfs_geo_000708
#define MODEL_BITFS_SEESAW_PLATFORM               0x3D        // bitfs_geo_000788
#define MODEL_BITFS_MOVING_SQUARE_PLATFORM        0x3E        // bitfs_geo_000728
#define MODEL_BITFS_SLIDING_PLATFORM              0x3F        // bitfs_geo_000740
#define MODEL_BITFS_TUMBLING_PLATFORM_PART        0x40        // bitfs_geo_0006D8
#define MODEL_BITFS_TUMBLING_PLATFORM             0x41        // bitfs_geo_0006F0

// sa

// bits
#define MODEL_BITS_SLIDING_PLATFORM               0x36        // bits_geo_0005E0
#define MODEL_BITS_TWIN_SLIDING_PLATFORMS         0x37        // bits_geo_0005F8
#define MODEL_BITS_OCTAGONAL_PLATFORM             0x39        // bits_geo_000610
#define MODEL_BITS_BLUE_PLATFORM                  0x3C        // bits_geo_000628
#define MODEL_BITS_FERRIS_WHEEL_AXLE              0x3D        // bits_geo_000640
#define MODEL_BITS_ARROW_PLATFORM                 0x3E        // bits_geo_000658
#define MODEL_BITS_SEESAW_PLATFORM                0x3F        // bits_geo_000670
#define MODEL_BITS_TILTING_W_PLATFORM             0x40        // bits_geo_000688
#define MODEL_BITS_STAIRCASE                      0x41        // bits_geo_0006A0
#define MODEL_BITS_STAIRCASE_FRAME1               0x42        // bits_geo_0006B8
#define MODEL_BITS_STAIRCASE_FRAME2               0x43        // bits_geo_0006D0
#define MODEL_BITS_STAIRCASE_FRAME3               0x44        // bits_geo_0006E8
#define MODEL_BITS_STAIRCASE_FRAME4               0x45        // bits_geo_000700
#define MODEL_BITS_WARP_PIPE                      0x49        // warp_pipe_geo

// lll
#define MODEL_LLL_DRAWBRIDGE_PART                 0x38        // lll_geo_000B20
#define MODEL_LLL_ROTATING_BLOCK_FIRE_BARS        0x3A        // lll_geo_000B38
#define MODEL_LLL_ROTATING_HEXAGONAL_RING         0x3E        // lll_geo_000BB0
#define MODEL_LLL_SINKING_RECTANGULAR_PLATFORM    0x3F        // lll_geo_000BC8
#define MODEL_LLL_SINKING_SQUARE_PLATFORMS        0x40        // lll_geo_000BE0
#define MODEL_LLL_TILTING_SQUARE_PLATFORM         0x41        // lll_geo_000BF8
#define MODEL_LLL_BOWSER_PIECE_1                  0x43        // lll_geo_bowser_puzzle_piece_1
#define MODEL_LLL_BOWSER_PIECE_2                  0x44        // lll_geo_bowser_puzzle_piece_2
#define MODEL_LLL_BOWSER_PIECE_3                  0x45        // lll_geo_bowser_puzzle_piece_3
#define MODEL_LLL_BOWSER_PIECE_4                  0x46        // lll_geo_bowser_puzzle_piece_4
#define MODEL_LLL_BOWSER_PIECE_5                  0x47        // lll_geo_bowser_puzzle_piece_5
#define MODEL_LLL_BOWSER_PIECE_6                  0x48        // lll_geo_bowser_puzzle_piece_6
#define MODEL_LLL_BOWSER_PIECE_7                  0x49        // lll_geo_bowser_puzzle_piece_7
#define MODEL_LLL_BOWSER_PIECE_8                  0x4A        // lll_geo_bowser_puzzle_piece_8
#define MODEL_LLL_BOWSER_PIECE_9                  0x4B        // lll_geo_bowser_puzzle_piece_9
#define MODEL_LLL_BOWSER_PIECE_10                 0x4C        // lll_geo_bowser_puzzle_piece_10
#define MODEL_LLL_BOWSER_PIECE_11                 0x4D        // lll_geo_bowser_puzzle_piece_11
#define MODEL_LLL_BOWSER_PIECE_12                 0x4E        // lll_geo_bowser_puzzle_piece_12
#define MODEL_LLL_BOWSER_PIECE_13                 0x4F        // lll_geo_bowser_puzzle_piece_13
#define MODEL_LLL_BOWSER_PIECE_14                 0x50        // lll_geo_bowser_puzzle_piece_14
#define MODEL_LLL_MOVING_OCTAGONAL_MESH_PLATFORM  0x36        // lll_geo_000B08
#define MODEL_LLL_SINKING_ROCK_BLOCK              0x37        // lll_geo_000DD0
#define MODEL_LLL_ROLLING_LOG                     0x39        // lll_geo_000DE8
#define MODEL_LLL_WOOD_BRIDGE                     0x35        // lll_geo_000B50
#define MODEL_LLL_LARGE_WOOD_BRIDGE               0x3B        // lll_geo_000B68
#define MODEL_LLL_FALLING_PLATFORM                0x3C        // lll_geo_000B80
#define MODEL_LLL_LARGE_FALLING_PLATFORM          0x3D        // lll_geo_000B98
#define MODEL_LLL_VOLCANO_FALLING_TRAP            0x53        // lll_geo_000EA8

// ddd
#define MODEL_DDD_BOWSER_SUB_DOOR                 0x36        // ddd_geo_000478
#define MODEL_DDD_BOWSER_SUB                      0x37        // ddd_geo_0004A0
#define MODEL_DDD_POLE                            0x38        // ddd_geo_000450

// wf
#define MODEL_WF_BREAKABLE_WALL_RIGHT             0x36        // wf_geo_000B78
#define MODEL_WF_BREAKABLE_WALL_LEFT              0x37        // wf_geo_000B90
#define MODEL_WF_KICKABLE_BOARD                   0x38        // wf_geo_000BA8
#define MODEL_WF_TOWER_DOOR                       0x39        // wf_geo_000BE0
#define MODEL_WF_KICKABLE_BOARD_FELLED            0x3A        // wf_geo_000BC8

// ending

// castle grounds
#define MODEL_CASTLE_GROUNDS_VCUTM_GRILL          0x36        // castle_grounds_geo_00070C
#define MODEL_CASTLE_GROUNDS_FLAG                 0x37        // castle_grounds_geo_000660
#define MODEL_CASTLE_GROUNDS_CANNON_GRILL         0x38        // castle_grounds_geo_000724

// pss

// cotmc

// totwc

// bowser 1

// wmotr

// bowser 2
#define MODEL_BOWSER_2_TILTING_ARENA              0x36        // bowser_2_geo_000170

// bowser 3
#define MODEL_BOWSER_3_FALLING_PLATFORM_1         0x36        // bowser_3_geo_000290
#define MODEL_BOWSER_3_FALLING_PLATFORM_2         0x37        // bowser_3_geo_0002A8
#define MODEL_BOWSER_3_FALLING_PLATFORM_3         0x38        // bowser_3_geo_0002C0
#define MODEL_BOWSER_3_FALLING_PLATFORM_4         0x39        // bowser_3_geo_0002D8
#define MODEL_BOWSER_3_FALLING_PLATFORM_5         0x3A        // bowser_3_geo_0002F0
#define MODEL_BOWSER_3_FALLING_PLATFORM_6         0x3B        // bowser_3_geo_000308
#define MODEL_BOWSER_3_FALLING_PLATFORM_7         0x3C        // bowser_3_geo_000320
#define MODEL_BOWSER_3_FALLING_PLATFORM_8         0x3D        // bowser_3_geo_000338
#define MODEL_BOWSER_3_FALLING_PLATFORM_9         0x3E        // bowser_3_geo_000350
#define MODEL_BOWSER_3_FALLING_PLATFORM_10        0x3F        // bowser_3_geo_000368

// ttm
#define MODEL_TTM_ROLLING_LOG                     0x35        // ttm_geo_000730
#define MODEL_TTM_STAR_CAGE                       0x36        // ttm_geo_000710
#define MODEL_TTM_BLUE_SMILEY                     0x37        // ttm_geo_000D14
#define MODEL_TTM_YELLOW_SMILEY                   0x38        // ttm_geo_000D4C
#define MODEL_TTM_STAR_SMILEY                     0x39        // ttm_geo_000D84
#define MODEL_TTM_MOON_SMILEY                     0x3A        // ttm_geo_000DBC

// actor model IDs

// first set of actor bins (0x54-0x63)
// group 1
#define MODEL_BULLET_BILL                 0x54        // bullet_bill_geo
#define MODEL_YELLOW_SPHERE               0x55        // yellow_sphere_geo
#define MODEL_HOOT                        0x56        // hoot_geo
#define MODEL_YOSHI_EGG                   0x57        // yoshi_egg_geo
#define MODEL_THWOMP                      0x58        // thwomp_geo
#define MODEL_HEAVE_HO                    0x59        // heave_ho_geo

// group 2
#define MODEL_BLARGG                      0x54        // blargg_geo
#define MODEL_BULLY                       0x56        // bully_geo
#define MODEL_BULLY_BOSS                  0x57        // bully_boss_geo

// group 3
#define MODEL_WATER_BOMB                  0x54        // water_bomb_geo
#define MODEL_WATER_BOMB_SHADOW           0x55        // water_bomb_shadow_geo
#define MODEL_KING_BOBOMB                 0x56        // king_bobomb_geo

// group 4
#define MODEL_MANTA_RAY                   0x54        // manta_seg5_geo_05008D14
#define MODEL_UNAGI                       0x55        // unagi_geo
#define MODEL_SUSHI                       0x56        // sushi_geo
#define MODEL_DL_WHIRLPOOL                0x57        // whirlpool_seg5_dl_05013CB8
#define MODEL_CLAM_SHELL                  0x58        // clam_shell_geo

// group 5
#define MODEL_POKEY_HEAD                  0x54        // pokey_head_geo
#define MODEL_POKEY_BODY_PART             0x55        // pokey_body_part_geo
#define MODEL_TWEESTER                    0x56        // tweester_geo
#define MODEL_KLEPTO                      0x57        // klepto_geo
#define MODEL_EYEROK_LEFT_HAND            0x58        // eyerok_left_hand_geo
#define MODEL_EYEROK_RIGHT_HAND           0x59        // eyerok_right_hand_geo

// group 6
#define MODEL_DL_MONTY_MOLE_HOLE          0x54        // monty_mole_hole_seg5_dl_05000840
#define MODEL_MONTY_MOLE                  0x55        // monty_mole_geo
#define MODEL_UKIKI                       0x56        // ukiki_geo
#define MODEL_FWOOSH                      0x57        // fwoosh_geo

// group 7
#define MODEL_SPINDRIFT                   0x54        // spindrift_geo
#define MODEL_MR_BLIZZARD_HIDDEN          0x55        // mr_blizzard_hidden_geo
#define MODEL_MR_BLIZZARD                 0x56        // mr_blizzard_geo
#define MODEL_PENGUIN                     0x57        // penguin_geo

// group 8
#define MODEL_CAP_SWITCH_EXCLAMATION      0x54        // cap_switch_exclamation_seg5_dl_05002E00
#define MODEL_CAP_SWITCH                  0x55        // cap_switch_geo
#define MODEL_CAP_SWITCH_BASE             0x56        // cap_switch_base_seg5_dl_05003120

// group 9
#define MODEL_BETA_BOO_KEY                0x55        // small_key_geo
#define MODEL_HAUNTED_CHAIR               0x56        // haunted_chair_geo
#define MODEL_MAD_PIANO                   0x57        // mad_piano_geo
#define MODEL_BOOKEND_PART                0x58        // bookend_part_geo
#define MODEL_BOOKEND                     0x59        // bookend_geo
#define MODEL_HAUNTED_CAGE                0x5A        // haunted_cage_geo

// group 10
#define MODEL_BIRDS                       0x54        // birds_geo
#define MODEL_YOSHI                       0x55        // yoshi_geo

// group 11
#define MODEL_ENEMY_LAKITU                0x54        // enemy_lakitu_geo
#define MODEL_SPINY_BALL                  0x55        // spiny_ball_geo
#define MODEL_SPINY                       0x56        // spiny_geo
#define MODEL_WIGGLER_HEAD                0x57        // wiggler_head_geo
#define MODEL_WIGGLER_BODY                0x58        // wiggler_body_geo
#define MODEL_BUBBA                       0x59        // bubba_geo

// referenced in macro presets. Unknown usage.
#define MODEL_UNKNOWN_54                  0x54
#define MODEL_UNKNOWN_58                  0x58

// second set of actor bins, (0x64-0x73)
// group 12
#define MODEL_BOWSER                      0x64        // bowser_geo
#define MODEL_BOWSER_BOMB_CHILD_OBJ       0x65        // bowser_bomb_geo - Spawns as a chill object in bowser's behavior command, causing an explosion if it touches a bomb
#define MODEL_BOWSER_SMOKE                0x66        // bowser_impact_smoke_geo
#define MODEL_BOWSER_FLAMES               0x67        // bowser_flames_geo
#define MODEL_BOWSER_WAVE                 0x68        // invisible_bowser_accessory_geo
#define MODEL_BOWSER_NO_SHADOW            0x69        // bowser_geo_no_shadow

// group 13
#define MODEL_BUB                         0x64        // cheep_cheep_geo
#define MODEL_TREASURE_CHEST_BASE         0x65        // treasure_chest_base_geo
#define MODEL_TREASURE_CHEST_LID          0x66        // treasure_chest_lid_geo
#define MODEL_CYAN_FISH                   0x67        // cyan_fish_geo
#define MODEL_WATER_RING                  0x68        // water_ring_geo
#define MODEL_SKEETER                     0x69        // skeeter_geo

// group 14
#define MODEL_PIRANHA_PLANT               0x64        // piranha_plant_geo
#define MODEL_WHOMP                       0x67        // whomp_geo
#define MODEL_KOOPA_WITH_SHELL            0x68        // koopa_with_shell_geo
#define MODEL_METALLIC_BALL               0x65        // metallic_ball_geo
#define MODEL_CHAIN_CHOMP                 0x66        // chain_chomp
#define MODEL_KOOPA_FLAG                  0x6A        // koopa_flag_geo
#define MODEL_WOODEN_POST                 0x6B        // wooden_post_geo

// group 15
#define MODEL_MIPS                        0x64        // mips_geo
#define MODEL_BOO_CASTLE                  0x65        // boo_castle_geo
#define MODEL_LAKITU                      0x66        // lakitu_geo

// group 16
#define MODEL_CHILL_BULLY                 0x64        // chilly_chief_geo
#define MODEL_BIG_CHILL_BULLY             0x65        // chilly_chief_big_geo
#define MODEL_MONEYBAG                    0x66        // moneybag_geo

// group 17
#define MODEL_SWOOP                       0x64        // swoop_geo
#define MODEL_SCUTTLEBUG                  0x65        // scuttlebug_geo
#define MODEL_MR_I_IRIS                   0x66        // mr_i_iris_geo
#define MODEL_MR_I_BODY                   0x67        // mr_i_geo
#define MODEL_MR_I MODEL_MR_I_BODY // backwards compatibility
#define MODEL_DORRIE                      0x68        // dorrie_geo

// other models
#define MODEL_YELLOW_COIN                 0x74        // yellow_coin_geo
#define MODEL_YELLOW_COIN_NO_SHADOW       0x75        // yellow_coin_no_shadow_geo
#define MODEL_BLUE_COIN                   0x76        // blue_coin_geo
#define MODEL_BLUE_COIN_NO_SHADOW         0x77        // blue_coin_no_shadow_geo
#define MODEL_HEART                       0x78        // heart_geo
#define MODEL_TRANSPARENT_STAR            0x79        // transparent_star_geo
#define MODEL_STAR                        0x7A        // star_geo
#define MODEL_TTM_SLIDE_EXIT_PODIUM       0x7B        // ttm_geo_000DF4
#define MODEL_WOODEN_SIGNPOST             0x7C        // wooden_signpost_geo
#define MODEL_UNKNOWN_7D                  0x7D        // referenced in macro presets. Unknown usage
// find me
#define MODEL_CANNON_BARREL               0x7F        // cannon_barrel_geo
#define MODEL_CANNON_BASE                 0x80        // cannon_base_geo
#define MODEL_BREAKABLE_BOX               0x81        // breakable_box_geo
#define MODEL_BREAKABLE_BOX_NO_SHADOW     0x82        // breakable_box_no_shadow_geo
#define MODEL_BREAKABLE_BOX_SMALL MODEL_BREAKABLE_BOX_NO_SHADOW // backwards compatibility
#define MODEL_EXCLAMATION_BOX_OUTLINE     0x83        // exclamation_box_outline_geo
#define MODEL_EXCLAMATION_POINT           0x84        // exclamation_point_seg8_dl_08025F08
#define MODEL_MARIOS_WINGED_METAL_CAP     0x85        // marios_winged_metal_cap_geo
#define MODEL_MARIOS_METAL_CAP            0x86        // marios_metal_cap_geo
#define MODEL_MARIOS_WING_CAP             0x87        // marios_wing_cap_geo
#define MODEL_MARIOS_CAP                  0x88        // marios_cap_geo
#define MODEL_EXCLAMATION_BOX             0x89        // exclamation_box_geo
#define MODEL_DIRT_ANIMATION              0x8A        // dirt_animation_geo
#define MODEL_CARTOON_STAR                0x8B        // cartoon_star_geo
#define MODEL_BLUE_COIN_SWITCH            0x8C        // blue_coin_switch_geo
// find me
#define MODEL_MIST                        0x8E        // mist_geo
#define MODEL_SPARKLES_ANIMATION          0x8F        // sparkles_animation_geo
#define MODEL_RED_FLAME                   0x90        // red_flame_geo
#define MODEL_BLUE_FLAME                  0x91        // blue_flame_geo
// find me
// find me
#define MODEL_BURN_SMOKE                  0x94        // burn_smoke_geo
#define MODEL_SPARKLES                    0x95        // sparkles_geo
#define MODEL_SMOKE                       0x96        // smoke_geo
// find me
// find me
// find me
// find me
// find me
#define MODEL_BURN_SMOKE_UNUSED           0x9C        // burn_smoke_geo - unused & duplicated
// find me
#define MODEL_WHITE_PARTICLE_DL           0x9E        // white_particle_dl
#define MODEL_SAND_DUST                   0x9F        // sand_seg3_dl_particle
#define MODEL_WHITE_PARTICLE              0xA0        // white_particle_dl
#define MODEL_PEBBLE                      0xA1        // pebble_seg3_dl_0301CB00
#define MODEL_LEAVES                      0xA2        // leaves_geo
#define MODEL_WAVE_TRAIL                  0xA3        // wave_trail_geo
#define MODEL_WHITE_PARTICLE_SMALL        0xA4        // white_particle_small_dl
#define MODEL_SMALL_WATER_SPLASH          0xA5        // small_water_splash_geo
#define MODEL_IDLE_WATER_WAVE             0xA6        // idle_water_wave_geo
#define MODEL_WATER_SPLASH                0xA7        // water_splash_geo
#define MODEL_BUBBLE                      0xA8        // bubble_geo
// find me
#define MODEL_PURPLE_MARBLE               0xAA        // purple_marble_geo
// find me
#define MODEL_UNKNOWN_AC                  0xAC        // according to an special preset, it was the original id of the castle floor trap
#define MODEL_WF_SLIDING_PLATFORM         0xAD        // wf_geo_000A98
#define MODEL_WF_SMALL_BOMP               0xAE        // wf_geo_000A00
#define MODEL_WF_ROTATING_WOODEN_PLATFORM 0xAF        // wf_geo_000A58
#define MODEL_WF_TUMBLING_BRIDGE_PART     0xB0        // wf_geo_000AB0
#define MODEL_WF_LARGE_BOMP               0xB1        // wf_geo_000A40
#define MODEL_WF_TUMBLING_BRIDGE          0xB2        // wf_geo_000AC8
#define MODEL_BOWSER_BOMB                 0xB3        // bowser_bomb_geo
#define MODEL_WATER_MINE                  0xB3        // water_mine_geo
#define MODEL_BOWLING_BALL                0xB4        // bowling_ball_geo
#define MODEL_TRAMPOLINE                  0xB5        // springboard_top_geo (unused)
#define MODEL_TRAMPOLINE_CENTER           0xB6        // springboard_spring_geo (unused)
#define MODEL_TRAMPOLINE_BASE             0xB7        // springboard_bottom_geo (unused)
#define MODEL_UNKNOWN_B8                  0xB8        // referenced in special presets as a static object. Unknown usage
#define MODEL_FISH                        0xB9        // fish_geo - fish without shadow, used
#define MODEL_FISH_SHADOW                 0xBA        // fish_shadow_geo - fish with shadow, unused
#define MODEL_BUTTERFLY                   0xBB        // butterfly_geo
#define MODEL_BLACK_BOBOMB                0xBC        // black_bobomb_geo
// find me
#define MODEL_KOOPA_SHELL                 0xBE        // koopa_shell_geo
#define MODEL_KOOPA_WITHOUT_SHELL         0xBF        // koopa_without_shell_geo
#define MODEL_GOOMBA                      0xC0        // goomba_geo
#define MODEL_SEAWEED                     0xC1        // seaweed_geo
#define MODEL_AMP                         0xC2        // dAmpGeo
#define MODEL_BOBOMB_BUDDY                0xC3        // bobomb_buddy_geo
// find me
// find me
// find me
#define MODEL_SSL_TOX_BOX                 0xC7        // ssl_geo_000630
#define MODEL_BOWSER_KEY_CUTSCENE         0xC8        // bowser_key_cutscene_geo
#define MODEL_DL_CANNON_LID               0xC9        // cannon_closed_seg8_dl_080048E0
#define MODEL_CHECKERBOARD_PLATFORM       0xCA        // checkerboard_platform_geo
#define MODEL_RED_FLAME_SHADOW            0xCB        // red_flame_shadow_geo
#define MODEL_BOWSER_KEY                  0xCC        // bowser_key_geo
#define MODEL_EXPLOSION                   0xCD        // explosion_geo
#define MODEL_PURPLE_SWITCH               0xCF        // purple_switch_geo
#define MODEL_CASTLE_STAR_DOOR_30_STARS   0xD0        // castle_geo_000F00
#define MODEL_CASTLE_STAR_DOOR_50_STARS   0xD1        // castle_geo_000F00
#define MODEL_CCM_SNOWMAN_BASE            0xD2        // ccm_geo_0003F0
// find me
#define MODEL_1UP                         0xD4        // mushroom_1up_geo
#define MODEL_CASTLE_STAR_DOOR_8_STARS    0xD5        // castle_geo_000F00
#define MODEL_CASTLE_STAR_DOOR_70_STARS   0xD6        // castle_geo_000F00
#define MODEL_RED_COIN                    0xD7        // red_coin_geo
#define MODEL_RED_COIN_NO_SHADOW          0xD8        // red_coin_no_shadow_geo
#define MODEL_METAL_BOX                   0xD9        // metal_box_geo
#define MODEL_METAL_BOX_DL                0xDA        // metal_box_dl
#define MODEL_NUMBER                      0xDB        // number_geo
#define MODEL_FLYGUY                      0xDC        // shyguy_geo
#define MODEL_TOAD                        0xDD        // toad_geo
#define MODEL_PEACH                       0xDE        // peach_geo
#define MODEL_CHUCKYA                     0xDF        // chuckya_geo
#define MODEL_WHITE_PUFF                  0xE0        // white_puff_geo
#define MODEL_TRAJECTORY_MARKER_BALL      0xE1        // bowling_ball_track_geo - duplicate used in SSL Pyramid small sized and as a track ball

#ifdef IA8_30FPS_COINS
#define MODEL_SILVER_COIN                 0xE2        // silver_coin_geo
#define MODEL_SILVER_COIN_NO_SHADOW       0xE3        // silver_coin_no_shadow_geo
#endif

// Menu Models (overwrites Level Geometry IDs)
#define MODEL_MAIN_MENU_MARIO_SAVE_BUTTON         MODEL_LEVEL_GEOMETRY_03   // main_menu_geo_0001D0
#define MODEL_MAIN_MENU_RED_ERASE_BUTTON          MODEL_LEVEL_GEOMETRY_04   // main_menu_geo_000290
#define MODEL_MAIN_MENU_BLUE_COPY_BUTTON          MODEL_LEVEL_GEOMETRY_05   // main_menu_geo_0002B8
#define MODEL_MAIN_MENU_YELLOW_FILE_BUTTON        MODEL_LEVEL_GEOMETRY_06   // main_menu_geo_0002E0
#define MODEL_MAIN_MENU_GREEN_SCORE_BUTTON        MODEL_LEVEL_GEOMETRY_07   // main_menu_geo_000308
#define MODEL_MAIN_MENU_MARIO_SAVE_BUTTON_FADE    MODEL_LEVEL_GEOMETRY_08   // main_menu_geo_000200
#define MODEL_MAIN_MENU_MARIO_NEW_BUTTON          MODEL_LEVEL_GEOMETRY_09   // main_menu_geo_000230
#define MODEL_MAIN_MENU_MARIO_NEW_BUTTON_FADE     MODEL_LEVEL_GEOMETRY_0A   // main_menu_geo_000260
#define MODEL_MAIN_MENU_PURPLE_SOUND_BUTTON       MODEL_LEVEL_GEOMETRY_0B   // main_menu_geo_000330
#define MODEL_MAIN_MENU_GENERIC_BUTTON            MODEL_LEVEL_GEOMETRY_0C   // main_menu_geo_000358

// level model aliases to level geometry IDs. Possibly a relic from an older level
// format that used to rely on level geometry objects. (seen in WF, LLL, etc)
#define MODEL_LLL_ROTATING_HEXAGONAL_PLATFORM     MODEL_LEVEL_GEOMETRY_09   // lll_geo_000A78
#define MODEL_WF_GIANT_POLE                       MODEL_LEVEL_GEOMETRY_0D   // wf_geo_000AE0
#define MODEL_WF_ROTATING_PLATFORM                MODEL_LEVEL_GEOMETRY_10   // wf_geo_0009B8
#define MODEL_BITDW_WARP_PIPE                     0xf8   // warp_pipe_geo
#define MODEL_VCUTM_WARP_PIPE                     0xf8   // warp_pipe_geo
#define MODEL_CASTLE_GROUNDS_WARP_PIPE            0xf8   // warp_pipe_geo

// MA globals
#define MODEL_GOAL 0xff
#define MODEL_CHECKPOINT 0xfe
#define MODEL_SPRING 0xfd
#define MODEL_SPEEDER 0xfc
#define MODEL_RAMP 0xfb
#define MODEL_ROCKET 0xfa
#define MODEL_ROCKET_SPAWNER 0xf9
#define MODEL_THI_WARP_PIPE                       0xf8   // warp_pipe_geo
#define MODEL_BOO                         0xf7
#define MODEL_SNUFIT 0xf6

#define MODEL_BOOSTER MODEL_SPEEDER

// MA course specifics
#define MODEL_CE_HAMMER MODEL_LEVEL_GEOMETRY_03
#define MODEL_CE_CAR1 MODEL_LEVEL_GEOMETRY_04
#define MODEL_CE_CAR2 MODEL_LEVEL_GEOMETRY_05
#define MODEL_CE_CAR3 MODEL_LEVEL_GEOMETRY_06
#define MODEL_CE_CAR4 MODEL_LEVEL_GEOMETRY_07
#define MODEL_CE_CAR5 MODEL_LEVEL_GEOMETRY_08

#define MODEL_WC_BOX MODEL_LEVEL_GEOMETRY_03
#define MODEL_WC_BOX_BROKEN MODEL_LEVEL_GEOMETRY_04
#define MODEL_WC_FAN_BRIGHT MODEL_LEVEL_GEOMETRY_05
#define MODEL_WC_FAN_DARK MODEL_LEVEL_GEOMETRY_06
#define MODEL_WC_FANBASE_BRIGHT MODEL_LEVEL_GEOMETRY_07
#define MODEL_WC_FANBASE_DARK MODEL_LEVEL_GEOMETRY_08
#define MODEL_WC_ROCK MODEL_LEVEL_GEOMETRY_09
#define MODEL_WC_ROCK_BREAK MODEL_LEVEL_GEOMETRY_0A
#define MODEL_WC_STONEHEAD MODEL_LEVEL_GEOMETRY_0B
#define MODEL_WC_STONEHEAD_PATH MODEL_LEVEL_GEOMETRY_0C

#define MODEL_PL_ELV MODEL_LEVEL_GEOMETRY_03
#define MODEL_PL_ROLL MODEL_LEVEL_GEOMETRY_04
#define MODEL_PL_CAGE MODEL_LEVEL_GEOMETRY_05
#define MODEL_PL_BOMBE MODEL_LEVEL_GEOMETRY_06
#define MODEL_PL_BOMBE_BREAK MODEL_LEVEL_GEOMETRY_07
#define MODEL_PL_BOMBE_BREAKB MODEL_LEVEL_GEOMETRY_08
#define MODEL_PL_CAGE2 MODEL_LEVEL_GEOMETRY_09
#define MODEL_PL_MLIFT MODEL_LEVEL_GEOMETRY_0A
#define MODEL_PL_TANK MODEL_LEVEL_GEOMETRY_0B
#define MODEL_PL_TANK_BREAKA MODEL_LEVEL_GEOMETRY_0C

#define MODEL_GF_VINE MODEL_LEVEL_GEOMETRY_03
#define MODEL_GF_GAKE_A MODEL_LEVEL_GEOMETRY_04
#define MODEL_GF_GAKE_B MODEL_LEVEL_GEOMETRY_05
#define MODEL_GF_GAKE_C MODEL_LEVEL_GEOMETRY_06
#define MODEL_GF_GAKE_D MODEL_LEVEL_GEOMETRY_07
#define MODEL_GF_GAKE_E MODEL_LEVEL_GEOMETRY_08
#define MODEL_GF_GAKE_F MODEL_LEVEL_GEOMETRY_09

#define MODEL_PH_DRUM MODEL_LEVEL_GEOMETRY_03
#define MODEL_PH_DRUM_BREAK MODEL_LEVEL_GEOMETRY_04
#define MODEL_PH_SHED MODEL_LEVEL_GEOMETRY_05
#define MODEL_PH_SHED_BREAK MODEL_LEVEL_GEOMETRY_06
#define MODEL_PH_TERMINAL MODEL_LEVEL_GEOMETRY_07

#define MODEL_MS_HAMMER MODEL_LEVEL_GEOMETRY_03
#define MODEL_MS_BUFFER MODEL_LEVEL_GEOMETRY_04
#define MODEL_MS_BUFFER_BREAK MODEL_LEVEL_GEOMETRY_05
#define MODEL_MS_BREAK MODEL_LEVEL_GEOMETRY_06
#define MODEL_MS_SLANE_BREAK MODEL_LEVEL_GEOMETRY_07

#define MODEL_AQ_MILKIN_DOOR MODEL_LEVEL_GEOMETRY_03
#define MODEL_AQ_DRMCN MODEL_LEVEL_GEOMETRY_04
#define MODEL_AQ_DRMCN_BREAK MODEL_LEVEL_GEOMETRY_05
#define MODEL_AQ_MILATTI MODEL_LEVEL_GEOMETRY_06
#define MODEL_AQ_MILIFT MODEL_LEVEL_GEOMETRY_07
#define MODEL_AQ_MITRUCK MODEL_LEVEL_GEOMETRY_08
#define MODEL_AQ_MITRUCK_BREAK MODEL_LEVEL_GEOMETRY_09
#define MODEL_AQ_PIC MODEL_LEVEL_GEOMETRY_0A
#define MODEL_AQ_UKIASIBA MODEL_LEVEL_GEOMETRY_0B
#define MODEL_AQ_WATER MODEL_LEVEL_GEOMETRY_0C

#define MODEL_HB_BLOCK MODEL_LEVEL_GEOMETRY_03
#define MODEL_HB_BLOCK_BREAK MODEL_LEVEL_GEOMETRY_04
#define MODEL_HB_HASHIRA MODEL_LEVEL_GEOMETRY_05
#define MODEL_HB_HASHIRA_BREAK MODEL_LEVEL_GEOMETRY_06
#define MODEL_HB_VASE MODEL_LEVEL_GEOMETRY_07
#define MODEL_HB_VASE_BREAK MODEL_LEVEL_GEOMETRY_08
#define MODEL_HB_WALL MODEL_LEVEL_GEOMETRY_09
#define MODEL_HB_WALL_BREAK MODEL_LEVEL_GEOMETRY_0A
#define MODEL_HB_HASHIRA_PLATFORM MODEL_LEVEL_GEOMETRY_0B
#define MODEL_HB_UPDOWN MODEL_LEVEL_GEOMETRY_0C
#define MODEL_HB_UPDOWN_BRIGHT MODEL_LEVEL_GEOMETRY_0D

#define MODEL_PC_BLOCK MODEL_LEVEL_GEOMETRY_03
#define MODEL_PC_DOOR_B MODEL_LEVEL_GEOMETRY_04
#define MODEL_PC_DOOR_G MODEL_LEVEL_GEOMETRY_05
#define MODEL_PC_DOOR_R MODEL_LEVEL_GEOMETRY_06
#define MODEL_PC_DOOR_N MODEL_LEVEL_GEOMETRY_07
#define MODEL_PC_KEY_BLUE MODEL_LEVEL_GEOMETRY_08
#define MODEL_PC_KEY_GREEN MODEL_LEVEL_GEOMETRY_09
#define MODEL_PC_KEYDOOR_BLUE MODEL_LEVEL_GEOMETRY_0A
#define MODEL_PC_KEYDOOR_GREEN MODEL_LEVEL_GEOMETRY_0B
#define MODEL_PC_WALLTYPE MODEL_LEVEL_GEOMETRY_0C
#define MODEL_PC_WINDMILL MODEL_LEVEL_GEOMETRY_0D
#define MODEL_PC_SANDGLASS_ENDS MODEL_LEVEL_GEOMETRY_0E
#define MODEL_PC_SANDGLASS_GLASS MODEL_LEVEL_GEOMETRY_0F
#define MODEL_PC_SANDGLASS_SAND MODEL_LEVEL_GEOMETRY_10
#define MODEL_PC_SANDGLASS_SANDF MODEL_LEVEL_GEOMETRY_11
#define MODEL_PC_SANDGLASS_SPRING MODEL_LEVEL_GEOMETRY_12
#define MODEL_PC_MOVE MODEL_LEVEL_GEOMETRY_13

#define MODEL_DC_BOX_BLUE MODEL_LEVEL_GEOMETRY_03
#define MODEL_DC_BOX_BLUE_BREAK MODEL_LEVEL_GEOMETRY_04
#define MODEL_DC_BOX_GREEN MODEL_LEVEL_GEOMETRY_05
#define MODEL_DC_BOX_GREEN_BREAK MODEL_LEVEL_GEOMETRY_06
#define MODEL_DC_BOX_RED MODEL_LEVEL_GEOMETRY_07
#define MODEL_DC_BOX_RED_BREAK MODEL_LEVEL_GEOMETRY_08
#define MODEL_DC_DOOR_B MODEL_LEVEL_GEOMETRY_09
#define MODEL_DC_DOOR_G MODEL_LEVEL_GEOMETRY_0A
#define MODEL_DC_DOOR_N MODEL_LEVEL_GEOMETRY_0B
#define MODEL_DC_DOOR_R MODEL_LEVEL_GEOMETRY_0C
#define MODEL_DC_TREASURE_BLUE MODEL_LEVEL_GEOMETRY_0D
#define MODEL_DC_SANDGLASS_ENDS MODEL_LEVEL_GEOMETRY_0E
#define MODEL_DC_SANDGLASS_GLASS MODEL_LEVEL_GEOMETRY_0F
#define MODEL_DC_SANDGLASS_SAND MODEL_LEVEL_GEOMETRY_10
#define MODEL_DC_SANDGLASS_SANDF MODEL_LEVEL_GEOMETRY_11
#define MODEL_DC_SANDGLASS_SPRING MODEL_LEVEL_GEOMETRY_12
#define MODEL_DC_TREASURE_BLUE_BREAK MODEL_LEVEL_GEOMETRY_13
#define MODEL_DC_TREASURE_GREEN MODEL_LEVEL_GEOMETRY_14
#define MODEL_DC_TREASURE_GREEN_BREAK MODEL_LEVEL_GEOMETRY_15
#define MODEL_DC_TREASURE_RED MODEL_LEVEL_GEOMETRY_16
#define MODEL_DC_TREASURE_RED_BREAK 0x17
#define MODEL_GREEN_FLAME 0x18

#define MODEL_EE_SHUTTER_BASE MODEL_LEVEL_GEOMETRY_03
#define MODEL_EE_SHUTTER_LEFT MODEL_EE_SHUTTER_BASE
#define MODEL_EE_SHUTTER_RIGHT (MODEL_EE_SHUTTER_BASE + 1)
#define MODEL_EE_TANK MODEL_LEVEL_GEOMETRY_05
#define MODEL_EE_TANK_BREAK MODEL_LEVEL_GEOMETRY_06

#define MODEL_MHE_FIREBALL MODEL_LEVEL_GEOMETRY_03
#define MODEL_MHE_FIREBALL_BREAK MODEL_LEVEL_GEOMETRY_04
#define MODEL_MHE_TANK MODEL_LEVEL_GEOMETRY_05
#define MODEL_MHE_TANK_BREAK MODEL_LEVEL_GEOMETRY_06
#define MODEL_MHE_SHUT MODEL_LEVEL_GEOMETRY_07
#define MODEL_MHE_SHUT_BREAK MODEL_LEVEL_GEOMETRY_08

#define MODEL_CG_SHUTTER_BASE MODEL_LEVEL_GEOMETRY_03
#define MODEL_CG_SHUTTER_LEFT MODEL_CG_SHUTTER_BASE
#define MODEL_CG_SHUTTER_RIGHT (MODEL_CG_SHUTTER_BASE + 1)

#define MODEL_OW_CE MODEL_LEVEL_GEOMETRY_03
#define MODEL_OW_WC MODEL_LEVEL_GEOMETRY_04
#define MODEL_OW_PL MODEL_LEVEL_GEOMETRY_05
#define MODEL_OW_MH MODEL_LEVEL_GEOMETRY_06
#define MODEL_OW_GF MODEL_LEVEL_GEOMETRY_07
#define MODEL_OW_PH MODEL_LEVEL_GEOMETRY_08
#define MODEL_OW_MS MODEL_LEVEL_GEOMETRY_09
#define MODEL_OW_AM MODEL_LEVEL_GEOMETRY_0A
#define MODEL_OW_HB MODEL_LEVEL_GEOMETRY_0B
#define MODEL_OW_PC MODEL_LEVEL_GEOMETRY_0C
#define MODEL_OW_DC MODEL_LEVEL_GEOMETRY_0D
#define MODEL_OW_EE MODEL_LEVEL_GEOMETRY_0E
#define MODEL_OW_MHE MODEL_LEVEL_GEOMETRY_0F
#define MODEL_OW_CG MODEL_LEVEL_GEOMETRY_10
#define MODEL_OW_FR MODEL_LEVEL_GEOMETRY_11
#define MODEL_OW_LOCK MODEL_LEVEL_GEOMETRY_12
#define MODEL_OW_NUMBER MODEL_LEVEL_GEOMETRY_13
#define MODEL_OW_CLEAR MODEL_LEVEL_GEOMETRY_14

#define MODEL_IG_BOMB MODEL_LEVEL_GEOMETRY_03
#define MODEL_IG_BOMB_BREAK MODEL_LEVEL_GEOMETRY_04
#define MODEL_IG_LIFT MODEL_LEVEL_GEOMETRY_05
#define MODEL_IG_SHELF MODEL_LEVEL_GEOMETRY_06
#define MODEL_IG_SIREN MODEL_LEVEL_GEOMETRY_07

#define MODEL_DL_VASE_BREAK MODEL_LEVEL_GEOMETRY_03
#define MODEL_DL_VASE MODEL_LEVEL_GEOMETRY_04
#define MODEL_DL_CRATE_BREAK MODEL_LEVEL_GEOMETRY_05
#define MODEL_DL_CRATE MODEL_LEVEL_GEOMETRY_06
#define MODEL_DL_CRATEDARK_BREAK MODEL_LEVEL_GEOMETRY_07
#define MODEL_DL_CRATEDARK MODEL_LEVEL_GEOMETRY_08

#define MODEL_SO_ASHIBA MODEL_LEVEL_GEOMETRY_03
#define MODEL_SO_ASHIBA2 MODEL_LEVEL_GEOMETRY_04
#define MODEL_SO_ASHIBA3 MODEL_LEVEL_GEOMETRY_05
#define MODEL_SO_ASHIBAF MODEL_LEVEL_GEOMETRY_06
#define MODEL_SO_ASHIBAF2 MODEL_LEVEL_GEOMETRY_07
#define MODEL_SO_ASHIBAF3 MODEL_LEVEL_GEOMETRY_08
#define MODEL_SO_HAKO MODEL_LEVEL_GEOMETRY_09
#define MODEL_SO_HAKO_BREAK MODEL_LEVEL_GEOMETRY_0A
#define MODEL_SO_KAITEN MODEL_LEVEL_GEOMETRY_0B
#define MODEL_SO_PILLAR MODEL_LEVEL_GEOMETRY_0C
#define MODEL_SO_PILLAR_BASE MODEL_LEVEL_GEOMETRY_0D
#define MODEL_SO_PILLAR_BREAK MODEL_LEVEL_GEOMETRY_0E
#define MODEL_SO_TSUBO MODEL_LEVEL_GEOMETRY_0F
#define MODEL_SO_TSUBO_BREAK MODEL_LEVEL_GEOMETRY_10

#define MODEL_RH_HAMMER MODEL_LEVEL_GEOMETRY_03
#define MODEL_RH_CONE MODEL_LEVEL_GEOMETRY_04
// #define MODEL_RH_BUFFER_BREAK MODEL_LEVEL_GEOMETRY_05
#define MODEL_RH_SLANE MODEL_LEVEL_GEOMETRY_06
#define MODEL_RH_SLANE_BREAK MODEL_LEVEL_GEOMETRY_07

#define MODEL_EQ_TREASURE_BLUE MODEL_LEVEL_GEOMETRY_03
#define MODEL_EQ_TREASURE_BLUE_BREAK MODEL_LEVEL_GEOMETRY_04
#define MODEL_EQ_TREASURE_GREEN MODEL_LEVEL_GEOMETRY_05
#define MODEL_EQ_TREASURE_GREEN_BREAK MODEL_LEVEL_GEOMETRY_06
#define MODEL_EQ_TREASURE_RED MODEL_LEVEL_GEOMETRY_07
#define MODEL_EQ_TREASURE_RED_BREAK MODEL_LEVEL_GEOMETRY_08
#define MODEL_EQ_COFFIN_BLUE MODEL_LEVEL_GEOMETRY_09
#define MODEL_EQ_COFFIN_BLUE_BREAK MODEL_LEVEL_GEOMETRY_0A
#define MODEL_EQ_COFFIN_GREEN MODEL_LEVEL_GEOMETRY_0B
#define MODEL_EQ_COFFIN_GREEN_BREAK MODEL_LEVEL_GEOMETRY_0C
#define MODEL_EQ_COFFIN_RED MODEL_LEVEL_GEOMETRY_0D
#define MODEL_EQ_COFFIN_RED_BREAK MODEL_LEVEL_GEOMETRY_0E
#define MODEL_EQ_VASE MODEL_LEVEL_GEOMETRY_0F

#define MODEL_LC_SHUTTER_BASE MODEL_LEVEL_GEOMETRY_03
#define MODEL_LC_SHUTTER_LEFT MODEL_LC_SHUTTER_BASE
#define MODEL_LC_SHUTTER_RIGHT (MODEL_LC_SHUTTER_BASE + 1)
#define MODEL_LC_STEP MODEL_LEVEL_GEOMETRY_05

#define MODEL_WB_FIG_AI2 MODEL_LEVEL_GEOMETRY_03
#define MODEL_WB_FIG_AI MODEL_LEVEL_GEOMETRY_04
#define MODEL_WB_CONT MODEL_LEVEL_GEOMETRY_05
#define MODEL_WB_CONT_BREAK MODEL_LEVEL_GEOMETRY_06
#define MODEL_WB_CONT_B MODEL_LEVEL_GEOMETRY_07
#define MODEL_WB_CONT_C MODEL_LEVEL_GEOMETRY_08
#define MODEL_WB_CONT_C_STAND MODEL_LEVEL_GEOMETRY_09
#define MODEL_WB_SHUT MODEL_LEVEL_GEOMETRY_0A
#define MODEL_WB_SHUT_BREAK MODEL_LEVEL_GEOMETRY_0B
#define MODEL_WB_SHUTS MODEL_LEVEL_GEOMETRY_0C
#define MODEL_WB_SHUTS_BREAK MODEL_LEVEL_GEOMETRY_0D

#define MODEL_SH_BOMBE MODEL_LEVEL_GEOMETRY_03
#define MODEL_SH_BOMBE_BREAK MODEL_LEVEL_GEOMETRY_04
#define MODEL_SH_FUN MODEL_LEVEL_GEOMETRY_05
#define MODEL_SH_LR MODEL_LEVEL_GEOMETRY_06
#define MODEL_SH_LY MODEL_LEVEL_GEOMETRY_07
#define MODEL_SH_LB MODEL_LEVEL_GEOMETRY_08
#define MODEL_SH_RR MODEL_LEVEL_GEOMETRY_09
#define MODEL_SH_RY MODEL_LEVEL_GEOMETRY_0A
#define MODEL_SH_RB MODEL_LEVEL_GEOMETRY_0B
#define MODEL_SH_TANK MODEL_LEVEL_GEOMETRY_0C
#define MODEL_SH_TANK_BREAK MODEL_LEVEL_GEOMETRY_0D

#define MODEL_WJ_VINE MODEL_LEVEL_GEOMETRY_03
#define MODEL_WJ_PLATFORM MODEL_LEVEL_GEOMETRY_05
#define MODEL_WJ_UP_VINE MODEL_LEVEL_GEOMETRY_06
#define MODEL_WJ_UP_HOOK MODEL_LEVEL_GEOMETRY_07
#define MODEL_WJ_SIDE_VINE MODEL_LEVEL_GEOMETRY_08
#define MODEL_WJ_SIDE_HOOK MODEL_LEVEL_GEOMETRY_09

#define MODEL_SR_DRUM MODEL_LEVEL_GEOMETRY_03
#define MODEL_SR_DRUM_BREAK MODEL_LEVEL_GEOMETRY_04
#define MODEL_SR_PNP MODEL_LEVEL_GEOMETRY_05
#define MODEL_SR_PNP_GROUND MODEL_LEVEL_GEOMETRY_06
#define MODEL_SR_PNP_LIMIT MODEL_LEVEL_GEOMETRY_07

#define MODEL_MSP_ORE MODEL_LEVEL_GEOMETRY_03
#define MODEL_MSP_ORE_BREAK MODEL_LEVEL_GEOMETRY_04
#define MODEL_MSP_ORE_B MODEL_LEVEL_GEOMETRY_05
#define MODEL_MSP_ORE_B_BREAK MODEL_LEVEL_GEOMETRY_06

#define MODEL_CW_METEO MODEL_LEVEL_GEOMETRY_03
#define MODEL_CW_METEO_BREAK MODEL_LEVEL_GEOMETRY_04
#define MODEL_CW_METEO_B MODEL_LEVEL_GEOMETRY_05
#define MODEL_CW_METEO_B_BREAK MODEL_LEVEL_GEOMETRY_06
#define MODEL_CW_METEO_LAVA MODEL_LEVEL_GEOMETRY_07
#define MODEL_CW_METEO_LAVA_BREAK MODEL_LEVEL_GEOMETRY_08
#define MODEL_CW_UP_DOWN MODEL_LEVEL_GEOMETRY_09

#define MODEL_SS1_SPACE MODEL_LEVEL_GEOMETRY_03
#define MODEL_SS1_BOO MODEL_LEVEL_GEOMETRY_04
#define MODEL_SS1_GOLEM MODEL_LEVEL_GEOMETRY_05
#define MODEL_SS1_FLY MODEL_LEVEL_GEOMETRY_06
#define MODEL_SS1_SHADOW MODEL_LEVEL_GEOMETRY_07
#define MODEL_SS1_BOO_BOO MODEL_LEVEL_GEOMETRY_08
#define MODEL_SS1_GOLEM_GEO MODEL_LEVEL_GEOMETRY_09

// Common blocks across CC levels - T/E/R/K/S types
#define MODEL_CC_TIMESTOP MODEL_LEVEL_GEOMETRY_03
#define MODEL_CC_BLOCK  MODEL_LEVEL_GEOMETRY_04

#define MODEL_CCT_TIMESTOP MODEL_CC_TIMESTOP
#define MODEL_CCT_GATE MODEL_LEVEL_GEOMETRY_04
#define MODEL_CCT_GATE_BREAKA MODEL_LEVEL_GEOMETRY_05
#define MODEL_CCT_GATE_BREAKB MODEL_LEVEL_GEOMETRY_06
#define MODEL_CCT_GATE_BREAKC MODEL_LEVEL_GEOMETRY_07
#define MODEL_CCT_GATE_HIT MODEL_LEVEL_GEOMETRY_08
#define MODEL_CCT_GATE_HIT_BREAK MODEL_LEVEL_GEOMETRY_09
#define MODEL_CCT_SHUTTER_BASE MODEL_LEVEL_GEOMETRY_0A
#define MODEL_CCT_SHUTTER_LEFT MODEL_CCT_SHUTTER_BASE
#define MODEL_CCT_SHUTTER_RIGHT (MODEL_CCT_SHUTTER_BASE + 1)
#define MODEL_CCT_PLATFORM_BIG MODEL_LEVEL_GEOMETRY_0C
#define MODEL_CCT_PLATFORM MODEL_LEVEL_GEOMETRY_0D

#define MODEL_CCE_TIMESTOP MODEL_CC_TIMESTOP
#define MODEL_CCE_BLOCK MODEL_CC_BLOCK
#define MODEL_CCE_GATE MODEL_LEVEL_GEOMETRY_05
#define MODEL_CCE_GATE_HIT MODEL_LEVEL_GEOMETRY_06
#define MODEL_CCT_STEP MODEL_LEVEL_GEOMETRY_07
#define MODEL_CCE_SHUTTER_BASE MODEL_LEVEL_GEOMETRY_08
#define MODEL_CCE_SHUTTER_LEFT MODEL_CCE_SHUTTER_BASE
#define MODEL_CCE_SHUTTER_RIGHT (MODEL_CCE_SHUTTER_BASE + 1)

#define MODEL_CCR_TIMESTOP MODEL_CC_TIMESTOP
#define MODEL_CCR_BLOCK MODEL_CC_BLOCK
#define MODEL_CCR_SWITCH MODEL_LEVEL_GEOMETRY_05
#define MODEL_CCR_SWITCH2 MODEL_LEVEL_GEOMETRY_06
#define MODEL_CCR_CAPSULE MODEL_LEVEL_GEOMETRY_07
#define MODEL_CCR_PLATFORM MODEL_LEVEL_GEOMETRY_08
#define MODEL_CCR_CAPSULE_OPEN MODEL_LEVEL_GEOMETRY_09
#define MODEL_CCR_CAPSULE_ANIM MODEL_LEVEL_GEOMETRY_0A
#define MODEL_CCR_RISING MODEL_LEVEL_GEOMETRY_0B

#endif // MODEL_IDS_H
