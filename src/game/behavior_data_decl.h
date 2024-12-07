#pragma once

#define OBJECT_FIELDS_INDEX_DIRECTLY

#include "game/object_list_processor.h"
#include "types.h"
#include "make_const_nonconst.h"
#include "behavior_data.h"

#define BC_B(a) _SHIFTL(a, 24, 8)
#define BC_BB(a, b) (_SHIFTL(a, 24, 8) | _SHIFTL(b, 16, 8))
#define BC_BBBB(a, b, c, d) (_SHIFTL(a, 24, 8) | _SHIFTL(b, 16, 8) | _SHIFTL(c, 8, 8) | _SHIFTL(d, 0, 8))
#define BC_BBH(a, b, c) (_SHIFTL(a, 24, 8) | _SHIFTL(b, 16, 8) | _SHIFTL(c, 0, 16))
#define BC_B0H(a, b) (_SHIFTL(a, 24, 8) | _SHIFTL(b, 0, 16))
#define BC_H(a) _SHIFTL(a, 16, 16)
#define BC_HH(a, b) (_SHIFTL(a, 16, 16) | _SHIFTL(b, 0, 16))
#define BC_W(a) ((uintptr_t)(u32)(a))
#define BC_PTR(a) ((uintptr_t)(a))
#define BC_BPTR(a, b) (_SHIFTL(a, 24, 8) + OS_K0_TO_PHYSICAL(b))

enum BehaviorCommands {
    /*0x00*/ BHV_CMD_BEGIN,
    /*0x01*/ BHV_CMD_DELAY,
    /*0x02*/ BHV_CMD_CALL,
    /*0x03*/ BHV_CMD_RETURN,
    /*0x04*/ BHV_CMD_GOTO,
    /*0x05*/ BHV_CMD_BEGIN_REPEAT,
    /*0x06*/ BHV_CMD_END_REPEAT,
    /*0x07*/ BHV_CMD_END_REPEAT_CONTINUE,
    /*0x08*/ BHV_CMD_BEGIN_LOOP,
    /*0x09*/ BHV_CMD_END_LOOP,
    /*0x0A*/ BHV_CMD_BREAK,
    /*0x0B*/ BHV_CMD_BREAK_UNUSED,
    /*0x0C*/ BHV_CMD_CALL_NATIVE,
    /*0x0D*/ BHV_CMD_ADD_FLOAT,
    /*0x0E*/ BHV_CMD_SET_FLOAT,
    /*0x0F*/ BHV_CMD_ADD_INT,
    /*0x10*/ BHV_CMD_SET_INT,
    /*0x11*/ BHV_CMD_OR_INT,
    /*0x12*/ BHV_CMD_OR_LONG,
    /*0x13*/ BHV_CMD_BIT_CLEAR,
    /*0x14*/ BHV_CMD_SET_INT_RAND_RSHIFT,
    /*0x15*/ BHV_CMD_SET_RANDOM_FLOAT,
    /*0x16*/ BHV_CMD_SET_RANDOM_INT,
    /*0x17*/ BHV_CMD_ADD_RANDOM_FLOAT,
    /*0x18*/ BHV_CMD_ADD_INT_RAND_RSHIFT,
    /*0x19*/ BHV_CMD_NOP_1,
    /*0x1A*/ BHV_CMD_NOP_2,
    /*0x1B*/ BHV_CMD_SET_MODEL,
    /*0x1C*/ BHV_CMD_SPAWN_CHILD,
    /*0x1D*/ BHV_CMD_DEACTIVATE,
    /*0x1E*/ BHV_CMD_DROP_TO_FLOOR,
    /*0x1F*/ BHV_CMD_SUM_FLOAT,
    /*0x20*/ BHV_CMD_SUM_INT,
    /*0x21*/ BHV_CMD_BILLBOARD,
    /*0x22*/ BHV_CMD_HIDE,
    /*0x23*/ BHV_CMD_SET_HITBOX,
    /*0x24*/ BHV_CMD_NOP_4,
    /*0x25*/ BHV_CMD_DELAY_VAR,
    /*0x26*/ BHV_CMD_BEGIN_REPEAT_UNUSED,
    /*0x27*/ BHV_CMD_LOAD_ANIMATIONS,
    /*0x28*/ BHV_CMD_ANIMATE,
    /*0x29*/ BHV_CMD_SPAWN_CHILD_WITH_PARam,
    /*0x2A*/ BHV_CMD_LOAD_COLLISION_DATA,
    /*0x2B*/ BHV_CMD_SET_HITBOX_WITH_OFFSet,
    /*0x2C*/ BHV_CMD_SPAWN_OBJ,
    /*0x2D*/ BHV_CMD_SET_HOME,
    /*0x2E*/ BHV_CMD_SET_HURTBOX,
    /*0x2F*/ BHV_CMD_SET_INTERACT_TYPE,
    /*0x30*/ BHV_CMD_SET_OBJ_PHYSICS,
    /*0x31*/ BHV_CMD_SET_INTERACT_SUBTYPE,
    /*0x32*/ BHV_CMD_SCALE,
    /*0x33*/ BHV_CMD_PARENT_BIT_CLEAR,
    /*0x34*/ BHV_CMD_ANIMATE_TEXTURE,
    /*0x35*/ BHV_CMD_DISABLE_RENDERING,
    /*0x36*/ BHV_CMD_SET_INT_UNUSED,
    /*0x37*/ BHV_CMD_SPAWN_WATER_DROPLET,
    
    /*0x08*/ BHV_CMD_CALL_INDEXED,
};

// Defines the start of the behavior script as well as the object list the object belongs to.
// Has some special behavior for certain objects.
#define BEGIN(objList) \
    BC_BB(BHV_CMD_BEGIN, objList)

// Delays the behavior script for a certain number of frames.
#define DELAY(num) \
    BC_B0H(BHV_CMD_DELAY, num)

// Jumps to a new behavior command and stores the return address in the object's stack.
#define CALL(addr) \
    BC_B(BHV_CMD_CALL), \
    BC_PTR(addr)

// Jumps back to the behavior command stored in the object's stack.
#define RETURN() \
    BC_B(BHV_CMD_RETURN)

// Jumps to a new behavior script without saving anything.
#define GOTO(addr) \
    BC_B(BHV_CMD_GOTO), \
    BC_PTR(addr)

// Marks the start of a loop that will repeat a certain number of times.
#define BEGIN_REPEAT(count) \
    BC_B0H(BHV_CMD_BEGIN_REPEAT, count)

// Marks the end of a repeating loop.
#define END_REPEAT() \
    BC_B(BHV_CMD_END_REPEAT)

// Also marks the end of a repeating loop, but continues executing commands following the loop on the same frame.
#define END_REPEAT_CONTINUE() \
    BC_B(BHV_CMD_END_REPEAT_CONTINUE)

// Marks the beginning of an infinite loop.
#define BEGIN_LOOP() \
    BC_B(BHV_CMD_BEGIN_LOOP)

#define CALL_COLLISION() \
    BC_BBH(BHV_CMD_CALL_INDEXED, 0, 0)

// Marks the end of an infinite loop.
#define END_LOOP() \
    BC_B(BHV_CMD_END_LOOP)

// Exits the behavior script.
// Often used to end behavior scripts that do not contain an infinite loop.
#define BREAK() \
    BC_B(BHV_CMD_BREAK)

// Exits the behavior script, unused.
#define BREAK_UNUSED() \
    BC_B(BHV_CMD_BREAK_UNUSED)

// Executes a native game function.
#define CALL_NATIVE(func) \
    BC_BPTR(BHV_CMD_CALL_NATIVE, func)

// Adds a float to the specified field.
#define ADD_FLOAT(field, value) \
    BC_BBH(BHV_CMD_ADD_FLOAT, field, value)

// Sets the specified field to a float.
#define SET_FLOAT(field, value) \
    BC_BBH(BHV_CMD_SET_FLOAT, field, value)

// Adds an integer to the specified field.
#define ADD_INT(field, value) \
    BC_BBH(BHV_CMD_ADD_INT, field, value)

// Sets the specified field to an integer.
#define SET_INT(field, value) \
    BC_BBH(BHV_CMD_SET_INT, field, value)

// Performs a bitwise OR with the specified field and the given integer.
// Usually used to set an object's flags.
#define OR_INT(field, value) \
    BC_BBH(BHV_CMD_OR_INT, field, value)

// Performs a bitwise OR with the specified field and the given (32 bit) integer.
// Usually used to set an object's flags which use values above 16 bits.
#define OR_LONG(field, value) \
    BC_BB(BHV_CMD_OR_LONG, field), \
    BC_W(value)

// Performs a bit clear with the specified short. Unused in favor of the 32-bit version.
#define BIT_CLEAR(field, value) \
    BC_BBH(BHV_CMD_BIT_CLEAR, field, value)

// TODO: this one needs a better name / labelling
// Gets a random short, right shifts it the specified amount and adds min to it, then sets the specified field to that value.
#define SET_INT_RAND_RSHIFT(field, min, rshift) \
    BC_BBH(BHV_CMD_SET_INT_RAND_RSHIFT, field, min), \
    BC_H(rshift)

// Sets the specified field to a random float in the given range.
#define SET_RANDOM_FLOAT(field, min, range) \
    BC_BBH(BHV_CMD_SET_RANDOM_FLOAT, field, min), \
    BC_H(range)

// Sets the specified field to a random integer in the given range.
#define SET_RANDOM_INT(field, min, range) \
    BC_BBH(BHV_CMD_SET_RANDOM_INT, field, min), \
    BC_H(range)

// Adds a random float in the given range to the specified field.
#define ADD_RANDOM_FLOAT(field, min, range) \
    BC_BBH(BHV_CMD_ADD_RANDOM_FLOAT, field, min), \
    BC_H(range)

// TODO: better name (unused anyway)
// Gets a random short, right shifts it the specified amount and adds min to it, then adds the value to the specified field. Unused.
#define ADD_INT_RAND_RSHIFT(field, min, rshift) \
    BC_BBH(BHV_CMD_ADD_INT_RAND_RSHIFT, field, min), \
    BC_H(rshift)

// No operation. Unused.
#define CMD_NOP_1(field) \
    BC_BB(BHV_CMD_NOP_1, field)

// No operation. Unused.
#define CMD_NOP_2(field) \
    BC_BB(BHV_CMD_NOP_2, field)

// Sets the current model ID of the object.
#define SET_MODEL(modelID) \
    BC_B0H(BHV_CMD_SET_MODEL, modelID)

// Spawns a child object with the specified model and behavior.
#define SPAWN_CHILD(modelID, behavior) \
    BC_B(BHV_CMD_SPAWN_CHILD), \
    BC_W(modelID), \
    BC_PTR(behavior)

// Exits the behavior script and despawns the object.
// Often used to end behavior scripts that do not contain an infinite loop.
#define DEACTIVATE() \
    BC_B(BHV_CMD_DEACTIVATE)

// Finds the floor triangle directly under the object and moves the object down to it.
#define DROP_TO_FLOOR() \
    BC_B(BHV_CMD_DROP_TO_FLOOR)

// Sets the destination float field to the sum of the values of the given float fields.
#define SUM_FLOAT(fieldDst, fieldSrc1, fieldSrc2) \
    BC_BBBB(BHV_CMD_SUM_FLOAT, fieldDst, fieldSrc1, fieldSrc2)

// Sets the destination integer field to the sum of the values of the given integer fields. Unused.
#define SUM_INT(fieldDst, fieldSrc1, fieldSrc2) \
    BC_BBBB(BHV_CMD_SUM_INT, fieldDst, fieldSrc1, fieldSrc2)

// Billboards the current object, making it always face the camera.
#define BILLBOARD() \
    BC_B(BHV_CMD_BILLBOARD)

// Hides the current object.
#define HIDE() \
    BC_B(BHV_CMD_HIDE)

// Sets the size of the object's cylindrical hitbox.
#define SET_HITBOX(radius, height) \
    BC_B(BHV_CMD_SET_HITBOX), \
    BC_HH(radius, height)

// No operation. Unused.
#define CMD_NOP_4(field, value) \
    BC_BBH(BHV_CMD_NOP_4, field, value)

// Delays the behavior script for the number of frames given by the value of the specified field.
#define DELAY_VAR(field) \
    BC_BB(BHV_CMD_DELAY_VAR, field)

// Unused. Marks the start of a loop that will repeat a certain number of times.
// Uses a u8 as the argument, instead of a s16 like the other version does.
#define BEGIN_REPEAT_UNUSED(count) \
    BC_BB(BHV_CMD_BEGIN_REPEAT_UNUSED, count)

// Loads the animations for the object. <field> is always set to oAnimations.
#define LOAD_ANIMATIONS(field, anims) \
    BC_BB(BHV_CMD_LOAD_ANIMATIONS, field), \
    BC_PTR(anims)

// Begins animation and sets the object's current animation index to the specified value.
#define ANIMATE(animIndex) \
    BC_BB(BHV_CMD_ANIMATE, animIndex)

// Spawns a child object with the specified model and behavior, plus a behavior param.
#define SPAWN_CHILD_WITH_PARAM(bhvParam, modelID, behavior) \
    BC_B0H(BHV_CMD_SPAWN_CHILD_WITH_PARam, bhvParam), \
    BC_W(modelID), \
    BC_PTR(behavior)

// Loads collision data for the object.
#define LOAD_COLLISION_DATA(collisionData) \
    BC_B(BHV_CMD_LOAD_COLLISION_DATA), \
    BC_PTR(collisionData)

// Sets the size of the object's cylindrical hitbox, and applies a downwards offset.
#define SET_HITBOX_WITH_OFFSET(radius, height, downOffset) \
    BC_B(BHV_CMD_SET_HITBOX_WITH_OFFSet), \
    BC_HH(radius, height), \
    BC_H(downOffset)

// Spawns a new object with the specified model and behavior.
#define SPAWN_OBJ(modelID, behavior) \
    BC_B(BHV_CMD_SPAWN_OBJ), \
    BC_W(modelID), \
    BC_PTR(behavior)

// Sets the home position of the object to its current position.
#define SET_HOME() \
    BC_B(BHV_CMD_SET_HOME)

// Sets the size of the object's cylindrical hurtbox.
#define SET_HURTBOX(radius, height) \
    BC_B(BHV_CMD_SET_HURTBOX), \
    BC_HH(radius, height)

// Sets the object's interaction type.
#define SET_INTERACT_TYPE(type) \
    BC_B(BHV_CMD_SET_INTERACT_TYPE), \
    BC_W(type)

// Sets various parameters that the object uses for calculating physics.
#define SET_OBJ_PHYSICS(wallHitboxRadius, gravity, bounciness, dragStrength, friction, buoyancy, unused1, unused2) \
    BC_B(BHV_CMD_SET_OBJ_PHYSICS), \
    BC_HH(wallHitboxRadius, gravity), \
    BC_HH(bounciness, dragStrength), \
    BC_HH(friction, buoyancy), \
    BC_HH(unused1, unused2)

// Sets the object's interaction subtype. Unused.
#define SET_INTERACT_SUBTYPE(subtype) \
    BC_B(BHV_CMD_SET_INTERACT_SUBTYPE), \
    BC_W(subtype)

// Sets the object's size to the specified percentage.
#define SCALE(unusedField, percent) \
    BC_BBH(BHV_CMD_SCALE, unusedField, percent)

// Performs a bit clear on the object's parent's field with the specified value.
// Used for clearing active particle flags fron Mario's object.
#define PARENT_BIT_CLEAR(field, flags) \
    BC_BB(BHV_CMD_PARENT_BIT_CLEAR, field), \
    BC_W(flags)

// Animates an object using texture animation. <field> is always set to oAnimState.
#define ANIMATE_TEXTURE(field, rate) \
    BC_BBH(BHV_CMD_ANIMATE_TEXTURE, field, rate)

// Disables rendering for the object.
#define DISABLE_RENDERING() \
    BC_B(BHV_CMD_DISABLE_RENDERING)

// Unused. Sets the specified field to an integer. Wastes 4 bytes of space for no reason at all.
#define SET_INT_UNUSED(field, value) \
    BC_BB(BHV_CMD_SET_INT_UNUSED, field), \
    BC_HH(0, value)

// Spawns a water droplet with the given parameters.
#define SPAWN_WATER_DROPLET(dropletParams) \
    BC_BPTR(BHV_CMD_SPAWN_WATER_DROPLET, dropletParams)

