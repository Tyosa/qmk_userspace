#pragma once
#include "quantum.h"

#define  KC_LENC    LT(0, KC_LEFT_ENC_MODE)     // Left encoder
#define  KC_RENC    LT(0, KC_RIGHT_ENC_MODE)    // Right encoder

void left_encoder_click(void);
void left_encoder_hold(void);
void left_encoder_oled(void);

void right_encoder_click(void);
void right_encoder_hold(void);
void right_encoder_oled(void);

