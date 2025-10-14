#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"

#include "make_const_nonconst.h"


#include "levels/credits/leveldata.inc.c"

#include "credits.h"
#define SEQ_LEVEL_GRASS 0x51

#define TOP_ROW 130
#define BTM_ROW 110

#define MID_COL 160
#define LEF_COL 120
#define RIG_COL 200
#define FLEF_COL 80
#define FRIG_COL 240
#define MLEF_COL 90
#define MRIG_COL 210

static const CreditsEntry sHackers[] = {
	{ MID_COL, TOP_ROW, "Made with HackerSM64" },
	{ MID_COL, BTM_ROW, "using fast64 x SAIO Blender" },
	{},
};

static const CreditsEntry sOriginalGames[] = {
	{ MID_COL, TOP_ROW + 10, "Original Games" },
	{ MID_COL, BTM_ROW + 10, "Super Mario 64 by Nintendo" },
	{ MID_COL, BTM_ROW - 10, "Sonic Adventure 2 by SEGA" },
	{},
};

static const CreditsEntry sTesters[] = {
	{ MID_COL, TOP_ROW, "Testers" },
	{ LEF_COL, BTM_ROW, "Mushie64" },
	{ RIG_COL, BTM_ROW, "Nobbie" },
	{},
};

static const CreditsEntry sHackerMaint[] = {
	{ MID_COL, TOP_ROW, "HackerSM64 Maintainers" },
	{ FLEF_COL, BTM_ROW, "Arthurtilly" },
	{ FRIG_COL, BTM_ROW, "ArcticJaguar" },

	{},
};

static const CreditsEntry sMusic[] = {
	{ MID_COL, TOP_ROW, "MIDIs" },
	{ LEF_COL, BTM_ROW, "VGMusic" },
	{ RIG_COL, BTM_ROW, "Miditechx" },
	{},
};

static const CreditsEntry sMusic2[] = {
	{ MID_COL, TOP_ROW, "Extra instruments" },
	{ FLEF_COL, BTM_ROW, "DNVIC" },
	{ MID_COL, BTM_ROW, "PC HQ Sounds" },
	{ FRIG_COL, BTM_ROW, "bicycle soda" },
	{},
};

static const CreditsEntry sEmuDev[] = {
	{ MID_COL, TOP_ROW, "Emulator Development" },
	{ LEF_COL, BTM_ROW, "gonetz" },
	{ RIG_COL, BTM_ROW, "falcobuster" },

	{},
};

static const CreditsEntry sMicrocode[] = {
	{ MID_COL, TOP_ROW, "Base F3DEX3 Microcode" },
	{ MID_COL, BTM_ROW, "sauraen" },
	{},
};

static const CreditsEntry sAlgorithms[] = {
	{ MLEF_COL, TOP_ROW + 10, "N64 Wizardry" },
	{ MLEF_COL, BTM_ROW + 10, "Rasky" },
	{ MLEF_COL, BTM_ROW - 10, "Fazana" },

	{ MRIG_COL, BTM_ROW + 10 + 5, "n64-libc + arith64" },
	{ MRIG_COL, TOP_ROW + 10 + 5, "Libraries used" },
	{ MRIG_COL, BTM_ROW - 10 + 5, "LZ4(T)" },
	{ MRIG_COL, BTM_ROW - 30 + 5, "PostgreSQL pairing heap" },
	{},
};

static const CreditsEntry sExtras1[] = {
	{ MLEF_COL, TOP_ROW - 30, "Camera collision" },
	{ MLEF_COL, BTM_ROW - 30, "Reonu" },

	{ MRIG_COL, TOP_ROW - 30, "Better swimming" },
	{ MRIG_COL, BTM_ROW - 30, "thecozies" },

	{ MID_COL, TOP_ROW + 30, "Mario Model" },
	{ MID_COL, BTM_ROW + 30, "Yoshi Milkman" },

	{},
};

static const CreditsEntry sExtras2[] = {
	{ MLEF_COL, TOP_ROW, "EABI libultra" },
	{ MLEF_COL, BTM_ROW, "Wiseguy" },

	{ MRIG_COL, TOP_ROW, "GCC Patches" },
	{ MRIG_COL, BTM_ROW, "Thar0" },

	{},
};

static const CreditsEntry sInspired[] = {
	{ MID_COL, TOP_ROW + 10, "Inspired by" },
	{ MID_COL, BTM_ROW + 10, "I Wanna Take Another Look Inside by Arzztt" },
	{ MID_COL, BTM_ROW - 10, "1000 Star Hack by someone2639/CowQuack" },
	{},
};

const CreditsEntry* gCredits[] = {
	sHackers,
	sOriginalGames,
	sTesters,
	sHackerMaint,
	sMusic,
	sMusic2,
	sEmuDev,
	sMicrocode,
	sAlgorithms,
	sExtras1,
	sExtras2,
	sInspired,

	NULL,
};
