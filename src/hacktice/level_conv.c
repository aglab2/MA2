#include "level_conv.h"
#include "course_table.h"

int LevelConv_toSM64Level(LevelConv_PlainLevels pl)
{
    static const char levels[] = 
    {
        0,
        COURSE_CE,
        COURSE_WC,
        COURSE_PL,
        COURSE_MH,
        COURSE_GF,
        COURSE_PH,
        COURSE_MS,
        COURSE_AQ,
        COURSE_HB,
        COURSE_PC,
        COURSE_DC,
        COURSE_EE,
        COURSE_MHE,
        COURSE_CG,
        COURSE_FR,
        COURSE_SS2,
        COURSE_IG,
        COURSE_DL,
        COURSE_SO,
        COURSE_RH,
        COURSE_EQ,
        COURSE_LC,
        COURSE_WB,
        COURSE_SH,
        COURSE_WJ,
        COURSE_SR,
        COURSE_MSP,
        COURSE_CW,
        COURSE_FC,
        COURSE_SS1,
        COURSE_CCT,
        COURSE_CCE,
        COURSE_CCR,
        COURSE_CCK,
        COURSE_CCS,
        COURSE_LB,
        COURSE_LF,
        COURSE_GH,
        COURSE_CHAO,
        COURSE_GG,
    };

    return levels[(int) pl];
}
