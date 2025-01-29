// == dialog ==
// (defines en_dialog_table etc.)

#include "game/ingame_menu.h"

#undef DEFINE_DIALOG
#define DEFINE_DIALOG(id, _1, _2, _3, _4, str) \
    static const char dialog_text_ ## id[] = { str };

#include DIALOG_FILE

#undef DEFINE_DIALOG
#define DEFINE_DIALOG(id, voice, linesPerBox, leftOffset, width, _) \
    static const struct DialogEntry dialog_entry_ ## id = { \
        voice, linesPerBox, leftOffset, width, dialog_text_ ## id \
    };

#include DIALOG_FILE

#undef DEFINE_DIALOG
#define DEFINE_DIALOG(id, _1, _2, _3, _4, _5) &dialog_entry_ ## id,

const struct DialogEntry *const DIALOG_TABLE[] = {
#include DIALOG_FILE
    NULL
};


// == courses ==
// (defines en_course_name_table etc.)
// The game duplicates this in levels/menu/leveldata.c in EU, so we split
// it out into a separate include file.

#include "define_courses.inc.c"
