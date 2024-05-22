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
    QC_UGRV,                    // ù
    KC_LEFT_ENC_MODE,           // left encoder mode
    KC_RIGHT_ENC_MODE,          // right encoder mode
    QC_QUOT,                    // non-dead quotes
};

enum tap_dance_codes {
    COM_MIN, // , -
    DOT_UND, // . _
    SLS_EXC, // / !
};

typedef struct _master_to_slave_t {
    bool is_sneaking;
    bool is_barking;
} master_to_slave_t;

// Custom actions
//todo reuse copy,paste,cut,redo,undo ? on nav layer ?
#define     COPY    LCTL(KC_C)
#define    PASTE    LCTL(KC_V)
#define      CUT    LCTL(KC_X)
#define     REDO    LCTL(KC_Y)
#define     UNDO    LCTL(KC_Z)
#define  KC_LENC    LT(0, KC_LEFT_ENC_MODE)     // Left encoder
#define  KC_RENC    LT(0, KC_RIGHT_ENC_MODE)    // Right encoder
#define     PTAB    LCTL(LSFT(KC_TAB))          // Previous tab
#define     NTAB    LCTL(KC_TAB)                // Next tab
#define     PREV    LALT(KC_LEFT)               // Previous page
#define     NEXT    LALT(KC_RIGHT)              // Next page

// Mods
#define    HR_GA    LGUI_T(KC_A)
#define    HR_AR    LALT_T(KC_R)
#define    HR_CS    LCTL_T(KC_S)
#define    HR_ST    LSFT_T(KC_T)
#define    HR_SN    LSFT_T(KC_N)
#define    HR_CE    LCTL_T(KC_E)
#define    HR_AI    LALT_T(KC_I)
#define    HR_GO    LGUI_T(KC_O)
#define  OS_LSFT    OSM(MOD_LSFT)
#define  OS_LCTL    OSM(MOD_LCTL)
#define  MEH_SPC    MT(MOD_MEH, KC_SPC)

// Layer toggle
#define   QC_NAV    TG(_NAV)
#define  COLEMAK    TO(_COLEMAK_DH)
#define      SYM    TO(_SYM)
#define      NUM    TO(_NUM)
#define      NAV    TO(_NAV)

extern bool is_alt_tab_active;
extern uint16_t alt_tab_timer;


