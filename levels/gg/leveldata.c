#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"
#include "dialog_ids.h"

#include "make_const_nonconst.h"


#include "levels/gg/leveldata.inc.c"
#include "levels/gg/gg_skybox/model.inc.c"

const char gGGNote0[] = R"(
Thank you a lot for playing my hack!

This project idea has been in my head since HackerSM64
was released and fast64 showed its potential.
The earliest mention of Mario Adventure 2 was around
the time when HackCast Season 2 Episode 2 aired.
I jokingly said that MA2 is to be released at the end of
2023, and here we are in 2025, it finally came true.
I tried my best to contribute to the project to get
HackerSM64 to the state that can be used for a project
of this size, and in 2024 I believed it became possible...
)";

const char gGGNote1[] = R"(
I was toying with the idea to use SAIO Blender + fast64
to have very accurate collision and level geometry
ported over from SA2. I was mostly playing with
Python scripting to get material conversion done, and
around November 2024 I managed to get City Escape
to be playable in SM64 with proper collision!

It was around this time when I realized this project can
be more than just a thought experiment, and I started
working on Hero Story full time. Would it not make for
a silly joke to release the hack on April 1st as a
grand reference to a 1000 star hack...
)";

const char gGGNote2[] = R"(
Admittedly City Escape was running at a glorious 10 FPS
even on my NASA PC, so I had to heavily optimize the
engine and figure out how to stuff in gigantic levels
into N64's limited memory. As it turned out to be,
my optimizations were not only viable for emulators, but
even console compatibility was possible!

I underestimated the amount of work I needed to do
to even get the basics done, and by the time April 1st
came around I only had Hero Story done.
This still worked in my favor, as I released MA2 demo
(MA2D vs SA2B :p) on April 1st and got positive feedback.
)";

const char gGGNote3[] = R"(
Fast forward to October 2025, I finally got all 1000
stars working and polished the hack enough to be
released. I hope you enjoyed playing it as much as
I enjoyed making it!

If you strive for more content, consider playing
Mario Adventure 35, which features SA2 Kart Racing.

But for now... Rest easy, heroes.
)";

const char gRollsStr[] = R"(
Mario Adventure 2
Made by aglab2

Original Games
SEGA
Nintendo

Testers
Mushie64
Nobbie

Proofreading
Mushie64

HackerSM64 Maintainers
Arthurtilly
ArcticJaguar

MIDIs
VGMusic
Miditechx

Extra instruments
DNVIC
PC HQ Sounds
bicycle soda

Emulator Development
gonetz
falcobuster

Base F3DEX3 Microcode
sauraen

N64 Wizardry
Rasky
Fazana

Libraries used
n64-libc + arith64
LZ4(T)
PostgreSQL pairing heap

Camera collision
Reonu

Better swimming
thecozies

Mario Model
Yoshi Milkman

VNs read
Tsukihime Remake + OG
Kagetsu Tohya
Katawa Shoujo

EABI libultra
Wiseguy

GCC Patches
Thar0

Special Thanks
Arzztt
someone2639
CowQuack
)";

const char gClearText[] = "Thank you for playing!";