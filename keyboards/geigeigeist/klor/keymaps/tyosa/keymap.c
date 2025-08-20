/* Copyright 2025 Tyosa
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "quantum.h"
#include "klor.h"
#include "aliases.h"
#include "num_word.h"
#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_saegewerk(
    //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
       KC_Q,     KC_W,     CTL_F,    KC_P,     KC_B,                          KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,
       GUI_A,    ALT_R,    CTL_S,    SHT_T,    MEH_G,                         MEH_M,    SHT_N,    CTL_E,    ALT_I,    GUI_O,
       CTL_Z,    CTL_X,    CTL_C,    KC_D,     CTL_V,     KC_MUTE,   KC_MPLY, KC_K,     KC_H,     KC_COMMA, KC_DOT,   KC_SLASH,
                           KC_TAB,   SPC_NAV,  QK_REP,                        QK_REP,   KC_BSPC,  KC_ENTER
    ),
    [_SYM] = LAYOUT_saegewerk(
    //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
       _______,  KC_AT,    KC_HASH,  KC_PERC,  _______,                       _______,  KC_AMPR,  _______,  KC_GRV,   KC_CIRC,
       AGRV,     EGRV,     EACU,     KC_LSFT,  _______,                       _______,  KC_LSFT,  _______,  _______,  KC_ASTR,
       _______,  _______,  CCED,     KC_DLR,   EURO,     _______,   _______,  KC_QUOT,  _______,  _______,  KC_EXLM,  KC_BSLS,
                           _______,  _______,  _______,                       _______,  _______,  _______
    ),
    [_NAV] = LAYOUT_saegewerk(
    //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
       _______,  _______,  _______,  _______,  _______,                       KC_INS,   KC_LBRC,  KC_LPRN,  KC_RPRN,  KC_RBRC,
       _______,  _______,  _______,  _______,  _______,                       KC_DEL,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,
       _______,  _______,  _______,  _______,  _______,  _______,   _______,  XXXXXXX,  KC_HOME,  KC_LCBR,  KC_RCBR,  KC_END,
                           _______,  _______,  _______,                       _______,  _______,  _______
    ),
    [_NUM] = LAYOUT_saegewerk(
    //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
       _______,  _______,  _______,  _______,  _______,                       KC_EQUAL, KC_7,     KC_8,     KC_9,     KC_MINUS,
       _______,  _______,  _______,  _______,  _______,                       KC_DOT,   KC_4,     KC_5,     KC_6,     KC_ASTR,
       _______,  _______,  _______,  _______,  _______,  _______,   _______,  KC_0,     KC_1,     KC_2,     KC_3,     KC_SLASH,
                           _______,  _______,  _______,                       _______,  _______,  _______
    ),
    [_FN] = LAYOUT_saegewerk(
    //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
       _______,  _______,  _______,  _______,  _______,                       _______,  KC_F9,    KC_F10,   KC_F11,   KC_F12,
       _______,  _______,  _______,  _______,  _______,                       _______,  KC_F5,    KC_F6,    KC_F7,    KC_F8,
       _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,
                           _______,  _______,  _______,                       _______,  _______,  _______
    ),
};

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // First try processing numword, and return false only if numword returned false, else go on
    if (!process_record_num_word(keycode, record)) return false;

    // Misc keycode handling
    mod_state = get_mods();
    switch (keycode) {
        case CCED:
            if (record->event.pressed) {
                register_code(KC_RALT);
                SEND_STRING(",");
                unregister_code(KC_RALT);
            }
            return true;
        case EACU:
            if (record->event.pressed) {
                del_mods(MOD_MASK_SHIFT);
                SEND_STRING(SS_TAP(X_QUOTE));
                set_mods(mod_state);
                SEND_STRING("e");
            }
            return true;
        case EGRV:
            if (record->event.pressed) {
                del_mods(MOD_MASK_SHIFT);
                SEND_STRING(SS_TAP(X_GRV));
                set_mods(mod_state);
                SEND_STRING("e");
            }
            return true;
        case AGRV:
            if (record->event.pressed) {
                del_mods(MOD_MASK_SHIFT);
                SEND_STRING(SS_TAP(X_GRV));
                set_mods(mod_state);
                SEND_STRING("a");
            }
            return true;
        case EURO:
            if (record->event.pressed) {
                clear_mods();
                register_code(KC_RALT);
                SEND_STRING("5");
                unregister_code(KC_RALT);
                set_mods(mod_state);
            }
            return false;
        case QUOT:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_QUOTE));
                SEND_STRING(SS_TAP(X_SPC));
            }
            return false;
        case LT(0,KC_X):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_X)); // Intercept hold function to send Ctrl-X
                return false;
            }
            return true;
        case LT(0,KC_C):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_C)); // Intercept hold function to send Ctrl-C
                return false;
            }
            return true;
        case LT(0,KC_V):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_V)); // Intercept hold function to send Ctrl-V
                return false;
            }
            return true;
        case LT(0,KC_Z):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_Z)); // Intercept hold function to send Ctrl-Z
                return false;
            }
            return true;
        case LT(0,KC_F):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_F)); // Intercept hold function to send Ctrl-F
                return false;
            }
            return true;
        default:
            return true;
    }
}

/*===================================================================================================================*/
/*     ENCODERS                                                                                                      */
/*===================================================================================================================*/
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (IS_LAYER_ON(_NAV)) {
            if (clockwise) {
                tap_code(KC_MNXT);
            } else {
                tap_code(KC_MPRV);
            }
        } else {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(MS_WHLD);
        } else {
            tap_code(MS_WHLU);
        }
    }
    return false;
}

/*===================================================================================================================*/
/*     TAP-HOLD                                                                                                      */
/*===================================================================================================================*/
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_saegewerk(
        'L', 'L', 'L', 'L', 'L',            'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L',            'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
                  'L', 'L', 'L',            'R', 'R', 'R'
    );

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GUI_A:
        case GUI_O:
            return TAPPING_TERM + 500;
        default:
            return TAPPING_TERM;
    }
}

