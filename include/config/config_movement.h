#pragma once

/*********************
 * MOVEMENT SETTINGS *
 *********************/

/**
 * Changes Mario's ground turn radius by making it dependent on the analog stick magnitude and speed.
 */
// #define VELOCITY_BASED_TURN_SPEED

/**
 * Allows Mario to easily side flip when moving forwards at any speed.
 */
// #define SIDE_FLIP_AT_LOW_SPEEDS

/**
 * Allows Mario to aim towards a new direction at the end of turning around,
 * and allows Mario to turn around multiple times in a row.
 */
// #define RESET_DIRECTION_WHEN_TURNING_AROUND

/**
 * Improved hanging:
 * - Doesn't require holding down the A button.
 * - Precise turning control.
 * - Prevents falling from the edges.
 */
// #define BETTER_HANGING

/**
 * Change the movement speed when hanging from a ceiling (the vanilla value is 4.0f, has no effect if BETTER_HANGING is enabled).
 */
#define HANGING_SPEED 4.0f

/**
 * Prevents Mario from falling asleep while idle.
 */
// #define NO_SLEEP

/**
 * Disables fall damage.
 */
#define NO_FALL_DAMAGE

/**
 * Disables the scream that mario makes when falling off a great height (this is separate from actual fall damage).
 */
// #define NO_FALL_DAMAGE_SOUND

/**
 * Fall height for normal fall damage. Vanilla is 1150.0f.
 */
#define FALL_DAMAGE_HEIGHT_SMALL 1150.0f

/**
 * Fall height for double fall damage. Vanilla is 3000.0f.
 */
#define FALL_DAMAGE_HEIGHT_LARGE 3000.0f

/**
 * Disables Mario getting stuck in snow and sand when falling.
 */
// #define NO_GETTING_BURIED

/**
 * Prevents hands-free holding.
 */
// #define HANDS_FREE_HOLDING_FIX

/**
 * Prevents Mario from losing his cap.
 */
// #define PREVENT_CAP_LOSS

/**
 * Uses Shindou's pole behavior.
 */
// #define SHINDOU_POLES

/**
 * If A and Z are pressed on the same frame while running, Mario will long jump instead of ground pound.
 */
// #define EASIER_LONG_JUMPS

/**
 * Enables the ability to hold Z while twirling to descend faster.
 */
// #define Z_TWIRL

/**
 * Disables bonks when ground pounding next to a wall.
 */
#define DISABLE_GROUNDPOUND_BONK

/**
 * Allows Mario to jump kick on steep surfaces that are set to be non slippery, instead of being forced to dive.
 */
#define JUMP_KICK_FIX

/**
 * Allows Mario to grab hangable ceilings from any state.
 */
// #define HANGING_FIX

/**
 * The maximum angle the player can wall kick, in degrees. 0..90. To allow 45 degree wall kicks, you must supply `46` to allow 45 and under.
 */
#define WALL_KICK_DEGREES 45

/**
 * Makes Mario unable to ledge grab steep slopes to prevent false ledge grabs.
 */
#define DONT_LEDGE_GRAB_STEEP_SLOPES

/**
 * Buffers an A input if you jump off a slope during the landing lag
 */
// #define SLOPE_BUFFER

/**
 * Disables BLJs and crushes SimpleFlips's dreams.
 */
// #define DISABLE_BLJ

/**
 * Re-enables upwarping when entering water. Forces you to only enter water from the top.
 */
// #define WATER_PLUNGE_UPWARP

/** 
 * This bug allows mario to move when initiating a dialog,
 * just as long as mario doesn't enter an action that can
 * be interrupted with text
 * Uncomment this to fix this bug, and frustrate speedrunners
 */
#define BUGFIX_DIALOG_TIME_STOP

/**
 * Inertia defines; allow Mario to preserve his momemtum when leaving moving platforms.
 */
#define MARIO_INERTIA_UPWARD
// #define MARIO_INERTIA_LATERAL

/**
 * Use Kaze Emanuar's raycast-style Mario movement step code inspired by UE5 pawn collider.
 * 
 * Note that even without DISABLE_BLJ, BLJs are no longer possible with this enabled.
*/
#define ENABLE_RAYCAST_MARIO_STEP

/**************************
 * IMPROVED STEP SETTINGS *
 **************************/

/* These settings are only used if ENABLE_RAYCAST_MARIO_STEP is enabled. */

// TODO: correct values
// Width of Mario collider
#define MARIOWIDENESS 50.0f
// Height of Mario collider
#define MARIOHEIGHT 160.0f
// negative Y displacement added to make Mario snap to the nearest floor
#define FLOOR_SNAP_OFFSET 78
// additional height added to Mario's collider when on shell or using vanish cap ice
#define ICEFLOWERWALKOFFSTE 25.f
// Minimum speed at which mario can wallkick/bonk a wall rather than slide along it
#define WALLKICK_MIN_VEL 16.0f
// Magnitude in direction of ceiling needed to cause a bonk
#define CEILING_BONK_DOT 0.7071067811f // 1/sqrt(2)
// When grounded, what the angle difference between the wall and Mario's head needs to be for wall collision to occur
// i.e. the angle below which Mario bonks and above which he slides along the wall
#define MAX_ANGLE_DIFF_FOR_WALL_COLLISION_ON_GROUND DEGREES(60)
// When airborne, what the angle difference between the wall and Mario's head needs to be for wall collision to occur
// Tends to be larger as you can't mantle a wall while airborne
#define MAX_ANGLE_DIFF_FOR_WALL_COLLISION_IN_AIR DEGREES(135)
