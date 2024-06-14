#pragma once
#include QMK_KEYBOARD_H

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

// Home-row mods
#define    HR_GA    LGUI_T(KC_A)
#define    HR_AR    LALT_T(KC_R)
#define    HR_CS    LCTL_T(KC_S)
#define    HR_ST    LSFT_T(KC_T)
#define    HR_SN    LSFT_T(KC_N)
#define    HR_CE    LCTL_T(KC_E)
#define    HR_AI    LALT_T(KC_I)
#define    HR_GO    LGUI_T(KC_O)
#define   HR_GF5    LGUI_T(KC_F5)
#define   HR_AF6    LALT_T(KC_F6)
#define   HR_CF7    LCTL_T(KC_F7)
#define   HR_SF8    LSFT_T(KC_F8)
#define    HR_S4    LSFT_T(KC_4)
#define    HR_C5    LCTL_T(KC_5)
#define    HR_A6    LALT_T(KC_6)
#define   HR_GEQ    LGUI_T(KC_EQL)
#define   HR_SLB    LSFT_T(KC_LBRC)
#define   HR_GRB    LGUI_T(KC_RBRC)

// Thumb modifiers
#define  MEH_SPC    MT(MOD_MEH, KC_SPC)
#define    TH_ST    LSFT_T(KC_TAB)
#define    TH_CE    LCTL_T(KC_ENT)
#define    TH_AB    LALT_T(KC_BSPC)

// Layer toggle
#define  COLEMAK    TO(_COLEMAK_DH)
#define      SYM    TO(_SYM)
#define      NUM    TO(_NUM)
#define      NAV    TO(_NAV)

extern bool is_alt_tab_active;
extern uint16_t alt_tab_timer;

