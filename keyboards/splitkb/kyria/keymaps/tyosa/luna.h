#pragma once
#include "quantum.h"

#define MIN_WALK_SPEED 10
#define MIN_RUN_SPEED 40
#define ANIM_FRAME_DURATION 200
#define ANIM_SIZE 96

extern bool is_sneaking;
extern bool is_barking;

void render_luna(int LUNA_X, int LUNA_Y);
