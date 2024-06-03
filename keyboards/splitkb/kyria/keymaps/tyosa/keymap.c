#include "quantum.h"
#include "tyosa.h"
#include "encoder.h"
#include "tap_dances.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK_DH] = LAYOUT(
            XXXXXXX,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                        KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, XXXXXXX,
            XXXXXXX,   HR_GA,   HR_AR,   HR_CS,   HR_ST,    KC_G,                                        KC_M,   HR_SN,   HR_CE,   HR_AI,   HR_GO, XXXXXXX,
            XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, XXXXXXX, KC_LENC, KC_RENC, XXXXXXX,    KC_K,    KC_H, COM_MIN, DOT_UND, SLS_EXC,  KC_DEL,
                                       XXXXXXX, XXXXXXX,  KC_ESC, MEH_SPC,  KC_TAB,  KC_ENT, KC_BSPC,     SYM, XXXXXXX, XXXXXXX
            ),
    [_SYM] = LAYOUT(
            XXXXXXX, KC_PERC,   KC_AT, KC_HASH,  KC_DLR, XXXXXXX,                                     XXXXXXX, KC_AMPR, KC_ASTR,  KC_GRV, KC_CIRC, XXXXXXX,
            XXXXXXX, QC_AGRV, QC_EGRV, QC_EAIG, XXXXXXX, XXXXXXX,                                     XXXXXXX, KC_LBRC, KC_LPRN, KC_RPRN, KC_RBRC, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, QC_CCED, XXXXXXX, XXXXXXX, XXXXXXX, KC_LENC, KC_RENC, XXXXXXX, QC_QUOT, KC_BSLS, KC_LCBR, KC_RCBR,     NAV,  KC_DEL,
                                       XXXXXXX, XXXXXXX,  KC_ESC, COLEMAK,  TH_ST,  TH_CE, TH_AB,     NUM, XXXXXXX, XXXXXXX
            ),
    [_NAV] = LAYOUT(
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LENC, KC_RENC, XXXXXXX, XXXXXXX, KC_HOME, XXXXXXX, XXXXXXX,  KC_END,  KC_DEL,
                                       XXXXXXX, XXXXXXX,  KC_ESC, COLEMAK,  TH_ST,  TH_CE, TH_AB,     SYM, XXXXXXX, XXXXXXX
            ),
    [_NUM] = LAYOUT(
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     KC_PAST,    KC_7,    KC_8,    KC_9, KC_MINS, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     KC_PDOT,    KC_4,    KC_5,    KC_6,  KC_EQL, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LENC, KC_RENC, XXXXXXX,    KC_0,    KC_1,    KC_2,    KC_3,     NAV,  KC_DEL,
                                       XXXXXXX, XXXXXXX,  KC_ESC, COLEMAK,  TH_ST,  TH_CE, TH_AB,     SYM, XXXXXXX, XXXXXXX
            ),
};

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch (keycode) {
        case QC_EAIG:
            if (record->event.pressed) {
                del_mods(MOD_MASK_SHIFT);
                SEND_STRING(SS_TAP(X_QUOTE));
                set_mods(mod_state);
                SEND_STRING("e");
            }
            return true;
        case QC_EGRV:
            if (record->event.pressed) {
                del_mods(MOD_MASK_SHIFT);
                SEND_STRING(SS_TAP(X_GRV));
                set_mods(mod_state);
                SEND_STRING("e");
            }
            return true;
        case QC_AGRV:
            if (record->event.pressed) {
                del_mods(MOD_MASK_SHIFT);
                SEND_STRING(SS_TAP(X_GRV));
                set_mods(mod_state);
                SEND_STRING("a");
            }
            return true;
        case QC_CCED:
            if (record->event.pressed) {
                register_code(KC_RALT);
                SEND_STRING(",");
                unregister_code(KC_RALT);
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
        case QC_QUOT:
            if (record -> event.pressed) {
                SEND_STRING(SS_TAP(X_QUOTE));
                SEND_STRING(SS_TAP(X_SPC));
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
  if (get_highest_layer(layer_state) != _COLEMAK_DH) {
      if (last_input_activity_elapsed() > LAYER_TIMEOUT) {
          layer_move(_COLEMAK_DH);
      }
  }
}

