// Define lists for list of level for macros. Each of the following fields are described:
// Argument 1: Internal ROM name of the level.
// Argument 2: Level enumerator for enum used to identify the level ID.
// Argument 3: Course enumerator for enum used to identify the course ID.
// Argument 4: Shorthand name of the level which should be the name of the levels/ folder of the level.
// Argument 5: The shared texture bin used.
// Argument 6: Acoustic reaches for each levels.
// Argument 7, 8, 9: Echo levels for individual areas.  < Clueless hackers should change these for their levels btw
// Argument 10: Specify dynamic music tables for levels, if specified. _ for none.
// Argument 11: Specify level camera table, if specified. _ for none.

// NOTE: Be sure to edit sZoomOutAreaMasks in camera.c, as there isnt a good way to macro those right now.
// TODO: Figure something out for sZoomOutAreaMasks?

DEFINE_LEVEL("OW2 IN CASTLE", LEVEL_CASTLE, COURSE_NONE, castle_inside, inside, 20000, 0x20, 0x20, 0x30, _, sCamCastle) 
DEFINE_LEVEL("CE", LEVEL_CE, COURSE_CE, ce, generic, 20000, 0x00, 0x00, 0x00, _, sCamCe) 
DEFINE_LEVEL("WC", LEVEL_WC, COURSE_WC, wc, generic, 20000, 0x00, 0x00, 0x00, _, sCamWc) 
DEFINE_LEVEL("PL", LEVEL_PL, COURSE_PL, pl, generic, 20000, 0x00, 0x00, 0x00, _, sCamPl) 
DEFINE_LEVEL("MH", LEVEL_MH, COURSE_MH, mh, generic, 20000, 0x00, 0x00, 0x00, _, sCamMh) 
DEFINE_LEVEL("GF", LEVEL_GF, COURSE_GF, gf, generic, 20000, 0x00, 0x00, 0x00, _, sCamGf) 
DEFINE_LEVEL("PH", LEVEL_PH, COURSE_PH, ph, generic, 20000, 0x00, 0x00, 0x00, _, sCamPh) 
DEFINE_LEVEL("MS", LEVEL_MS, COURSE_MS, ms, generic, 20000, 0x00, 0x00, 0x00, _, sCamMs) 
DEFINE_LEVEL("AQ", LEVEL_AQ, COURSE_AQ, aq, generic, 20000, 0x00, 0x00, 0x00, _, sCamAq) 
DEFINE_LEVEL("HB", LEVEL_HB, COURSE_HB, hb, generic, 20000, 0x00, 0x00, 0x00, _, sCamHb) 
DEFINE_LEVEL("PC", LEVEL_PC, COURSE_PC, pc, generic, 20000, 0x00, 0x00, 0x00, _, sCamPc) 
DEFINE_LEVEL("DC", LEVEL_DC, COURSE_DC, dc, generic, 20000, 0x00, 0x00, 0x00, _, sCamDc) 
DEFINE_LEVEL("EE", LEVEL_EE, COURSE_EE, ee, generic, 20000, 0x00, 0x00, 0x00, _, sCamEe) 
DEFINE_LEVEL("MHE", LEVEL_MHE, COURSE_MHE, mhe, generic, 20000, 0x00, 0x00, 0x00, _, sCamMhe) 
DEFINE_LEVEL("CG", LEVEL_CG, COURSE_CG, cg, generic, 20000, 0x00, 0x00, 0x00, _, sCamCg) 
DEFINE_LEVEL("FR", LEVEL_FR, COURSE_FR, fr, generic, 20000, 0x00, 0x00, 0x00, _, sCamFr) 
DEFINE_LEVEL("SS2", LEVEL_SS2, COURSE_SS2, ss2, generic, 20000, 0x00, 0x00, 0x00, _, sCamSs2) 
DEFINE_LEVEL("IG", LEVEL_IG, COURSE_IG, ig, generic, 20000, 0x00, 0x00, 0x00, _, sCamIg) 
DEFINE_LEVEL("DL", LEVEL_DL, COURSE_DL, dl, generic, 20000, 0x00, 0x00, 0x00, _, sCamDl) 
DEFINE_LEVEL("SO", LEVEL_SO, COURSE_SO, so, generic, 20000, 0x00, 0x00, 0x00, _, sCamSo) 
DEFINE_LEVEL("RH", LEVEL_RH, COURSE_RH, rh, generic, 20000, 0x00, 0x00, 0x00, _, sCamRh) 
DEFINE_LEVEL("EQ", LEVEL_EQ, COURSE_EQ, eq, generic, 20000, 0x00, 0x00, 0x00, _, sCamEq) 
DEFINE_LEVEL("LC", LEVEL_LC, COURSE_LC, lc, generic, 20000, 0x00, 0x00, 0x00, _, sCamLc) 
DEFINE_LEVEL("WB", LEVEL_WB, COURSE_WB, wb, generic, 20000, 0x00, 0x00, 0x00, _, sCamWb) 
DEFINE_LEVEL("SH", LEVEL_SH, COURSE_SH, sh, generic, 20000, 0x00, 0x00, 0x00, _, sCamSh) 
DEFINE_LEVEL("WJ", LEVEL_WJ, COURSE_WJ, wj, generic, 20000, 0x00, 0x00, 0x00, _, sCamWj) 
DEFINE_LEVEL("SR", LEVEL_SR, COURSE_SR, sr, generic, 20000, 0x00, 0x00, 0x00, _, sCamSr) 
DEFINE_LEVEL("MSP", LEVEL_MSP, COURSE_MSP, msp, generic, 20000, 0x00, 0x00, 0x00, _, sCamMsp) 
DEFINE_LEVEL("CW", LEVEL_CW, COURSE_CW, cw, generic, 20000, 0x00, 0x00, 0x00, _, sCamCw) 
DEFINE_LEVEL("FC", LEVEL_FC, COURSE_FC, fc, generic, 20000, 0x00, 0x00, 0x00, _, sCamFc) 
DEFINE_LEVEL("SS1", LEVEL_SS1, COURSE_SS1, ss1, generic, 20000, 0x00, 0x00, 0x00, _, sCamSs1) 
DEFINE_LEVEL("CCT", LEVEL_CCT, COURSE_CCT, cct, generic, 20000, 0x00, 0x00, 0x00, _, sCamCct) 
DEFINE_LEVEL("CCE", LEVEL_CCE, COURSE_CCE, cce, generic, 20000, 0x00, 0x00, 0x00, _, sCamCce) 
DEFINE_LEVEL("CCR", LEVEL_CCR, COURSE_CCR, ccr, generic, 20000, 0x00, 0x00, 0x00, _, sCamCcr) 
DEFINE_LEVEL("CCK", LEVEL_CCK, COURSE_CCK, cck, generic, 20000, 0x00, 0x00, 0x00, _, sCamCck) 
DEFINE_LEVEL("CCS", LEVEL_CCS, COURSE_CCS, ccs, generic, 20000, 0x00, 0x00, 0x00, _, sCamCcs) 
DEFINE_LEVEL("BOB", LEVEL_BOB, COURSE_NONE, bob, generic, 20000, 0x00, 0x00, 0x00, _, sCamBOB) 
DEFINE_LEVEL("PRELUDE", LEVEL_PRELUDE, COURSE_NONE, prelude, generic, 20000, 0x00, 0x00, 0x00, _, sCamPrelude) 
DEFINE_LEVEL("END", LEVEL_END, COURSE_NONE, end, generic, 20000, 0x00, 0x00, 0x00, _, sCamEnd) 
DEFINE_LEVEL("END CAKE", LEVEL_ENDING, COURSE_CAKE_END, ending, generic, 20000, 0x00, 0x00, 0x00, _, _) 
DEFINE_LEVEL("OW1 C GROUNDS", LEVEL_CASTLE_GROUNDS, COURSE_NONE, castle_grounds, outside, 20000, 0x00, 0x00, 0x00, _, sCamCastleGrounds) 
DEFINE_LEVEL("OW3 C COURTYD", LEVEL_CASTLE_COURTYARD, COURSE_NONE, castle_courtyard, outside, 20000, 0x00, 0x00, 0x00, _, sCamCastleCourtyard) 
DEFINE_LEVEL("B BATTLE1", LEVEL_BOWSER_1, COURSE_NONE, bowser_1, generic, 60000, 0x40, 0x40, 0x40, _, _) 
DEFINE_LEVEL("B BATTLE2", LEVEL_BOWSER_2, COURSE_NONE, bowser_2, fire, 60000, 0x40, 0x40, 0x40, _, _) 
DEFINE_LEVEL("B BATTLE3", LEVEL_BOWSER_3, COURSE_NONE, bowser_3, generic, 60000, 0x40, 0x40, 0x40, _, _) 
DEFINE_LEVEL("LB", LEVEL_LB, COURSE_LB, lb, generic, 20000, 0x00, 0x00, 0x00, _, sCamLb) 