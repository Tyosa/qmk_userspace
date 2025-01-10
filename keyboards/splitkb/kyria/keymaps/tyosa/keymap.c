#include "quantum.h"
#include "tyosa.h"
#include "encoder.h"
#include "tap_dances.h"
#include "macros.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK_DH] = LAYOUT(
            XXXXXXX,  Q_CAPS,    KC_W, F_SEARC,    KC_P,    KC_B,                                        KC_J,    L_FF,    KC_U,    KC_Y, KC_SCLN, XXXXXXX,
            XXXXXXX,   HR_GA,   HR_AR,   HR_CS,   HR_ST,    KC_G,                                        KC_M,   HR_SN,   HR_CE,   HR_AI,   HR_GO, XXXXXXX,
            XXXXXXX,  Z_UNDO,  X_CUTS,  C_COPY,    KC_D, V_PASTE,     NUM, KC_LENC, KC_RENC,     NAV,    KC_K, H_QUOTE, COM_MIN, DOT_UND, SLS_EXC,  KC_DEL,
                                       KC_BTN2, KC_BTN1,  KC_ESC, MEH_SPC,  KC_TAB,  KC_ENT, KC_BSPC,     SYM, XXXXXXX, XXXXXXX
            ),
    [_SYM] = LAYOUT(
            XXXXXXX, KC_PERC,   KC_AT, KC_HASH,  KC_DLR, XXXXXXX,                                      KC_INS, KC_AMPR, KC_ASTR,  KC_GRV, KC_CIRC, XXXXXXX,
            XXXXXXX, QC_AGRV, QC_EGRV, QC_EAIG, KC_LSFT, XXXXXXX,                                     XXXXXXX,  HR_SLB,  HR_CLP,  HR_ARP,  HR_GRB, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, QC_CCED, XXXXXXX, XXXXXXX,     NUM, KC_LENC, KC_RENC,     NAV, KC_BSLS, KC_QUOT, KC_LCBR, KC_RCBR,     NAV,  KC_DEL,
                                       _______, _______,  KC_ESC, COLEMAK,  KC_TAB,  KC_ENT, KC_BSPC,     NUM, XXXXXXX, XXXXXXX
            ),
    [_NAV] = LAYOUT(
            XXXXXXX, XXXXXXX, KC_BTN3, KC_BTN2, KC_BTN1, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                                     KC_HOME, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_END,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     NUM, KC_LENC, KC_RENC, COLEMAK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_DEL,
                                       _______, _______,  KC_ESC, COLEMAK,  KC_TAB,  KC_ENT, KC_BSPC,     SYM, XXXXXXX, XXXXXXX
            ),
    [_NUM] = LAYOUT(
            XXXXXXX,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,                                     KC_ASTR,    KC_7,    KC_8,    KC_9, KC_MINS, XXXXXXX,
            XXXXXXX,  HR_GF5,  HR_AF6,  HR_CF7,  HR_SF8, XXXXXXX,                                      KC_DOT,   HR_S4,   HR_C5,   HR_A6,  HR_GEQ, XXXXXXX,
            XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX, COLEMAK, KC_LENC, KC_RENC,     NAV,    KC_0,    KC_1,    KC_2,    KC_3,     NAV,  KC_DEL,
                                       _______, _______,  KC_ESC, COLEMAK,  KC_TAB,  KC_ENT, KC_BSPC,     SYM, XXXXXXX, XXXXXXX
            ),
};

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch (keycode) {
        case QC_EAIG:
            if (record->event.pressed) {
                function_e_aig(mod_state);
            }
            return true;
        case QC_EGRV:
            if (record->event.pressed) {
                function_e_grv(mod_state);
            }
            return true;
        case QC_AGRV:
            if (record->event.pressed) {
                function_a_grv(mod_state);
            }
            return true;
        case QC_CCED:
            if (record->event.pressed) {
                function_c_ced();
            }
            return true;
        case KC_LENC:
            if (record->tap.count && record->event.pressed) {
                left_encoder_click();
            } else if (record->event.pressed) {
                left_encoder_hold();
            }
            return false;
        case KC_RENC:
            if (record->tap.count && record->event.pressed) {
                right_encoder_click();
            } else if (record->event.pressed) {
                right_encoder_hold();
            }
            return false;
    }
    return true;
};

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 750) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

