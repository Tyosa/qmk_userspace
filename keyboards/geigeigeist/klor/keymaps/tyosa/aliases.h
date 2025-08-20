#pragma once

#include "quantum_keycodes.h"
enum custom_keys {
    CCED=SAFE_RANGE, // ç
    EACU,            // é
    EGRV,            // è
    AGRV,            // à
    EURO,            // €
    QUOT,            // Quick quote
    NUMWORD,
};

enum layers {
    _COLEMAK = 0,
    _SYM,
    _NAV,
    _NUM,
    _FN
};

// Layer navigation
#define BASE    TO(_COLEMAK)
#define SPC_NAV LT(_NAV, KC_SPC)
#define SYM     OSL(_SYM)
#define FN      OSL(_FN)
#define NUM     TO(_NUM)
#define NAV     TO(_NAV)

// Left hand home-row mods
#define GUI_A   MT(MOD_LGUI, KC_A)
#define ALT_R   MT(MOD_LALT, KC_R)
#define CTL_S   MT(MOD_LCTL, KC_S)
#define SHT_T   MT(MOD_LSFT, KC_T)
#define MEH_G   MT(MOD_MEH, KC_G)

// Right hand home-row mods
#define MEH_M   MT(MOD_MEH, KC_M)
#define SHT_N   MT(MOD_RSFT, KC_N)
#define CTL_E   MT(MOD_LCTL, KC_E)
#define ALT_I   MT(MOD_LALT, KC_I)
#define GUI_O   MT(MOD_LGUI, KC_O)

// Keys that send their value on tap and send Ctrl+their value on hold
#define CTL_Z   LT(0, KC_Z)
#define CTL_X   LT(0, KC_X)
#define CTL_C   LT(0, KC_C)
#define CTL_V   LT(0, KC_V)
#define CTL_F   LT(0, KC_F)
