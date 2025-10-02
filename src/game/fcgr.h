#define FCGR_CONTINUE 0
#define FCGR_LAND 1
#define FCGR_BREAK_AIR 2
#define FCGR_BREAK_LAND 3

int fcgr_spin(struct MarioState *m);

struct FcgrHitbox
{
    f32 x;
    f32 y;
    f32 z;
    f32 r;
    f32 h;
};
void fcgr_hitbox_xform(struct FcgrHitbox*);
