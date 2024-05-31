#pragma once
#include QMK_KEYBOARD_H
#include "tap_dances.h"

enum layers {
    _COLEMAK_DH = 0,
    _NAV,
    _SYM,
    _NUM
};

enum custom_keycodes {
    QC_EGRV = SAFE_RANGE,       // è
    QC_EAIG,                    // é
    QC_AGRV,                    // à
    QC_CCED,                    // ç
    KC_LEFT_ENC_MODE,           // left encoder mode
    KC_RIGHT_ENC_MODE,          // right encoder mode
    QC_QUOT,                    // non-dead quotes
};

// Mods
#define    HR_GA    LGUI_T(KC_A)
#define    HR_AR    LALT_T(KC_R)
#define    HR_CS    LCTL_T(KC_S)
#define    HR_ST    LSFT_T(KC_T)
#define    HR_SN    LSFT_T(KC_N)
#define    HR_CE    LCTL_T(KC_E)
#define    HR_AI    LALT_T(KC_I)
#define    HR_GO    LGUI_T(KC_O)
#define  MEH_SPC    MT(MOD_MEH, KC_SPC)

// Layer toggle
#define  COLEMAK    TO(_COLEMAK_DH)
#define      SYM    TO(_SYM)
#define      NUM    TO(_NUM)
#define      NAV    TO(_NAV)

extern bool is_alt_tab_active;
extern uint16_t alt_tab_timer;

