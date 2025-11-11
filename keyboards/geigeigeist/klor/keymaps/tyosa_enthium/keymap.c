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
#include "nav_timer.h"

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_saegewerk(
    //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
       KC_W,     KC_Y,     KC_O,     KC_U,     KC_EQL,                        KC_F,     KC_L,     KC_D,     KC_P,     KC_X,
       KC_C,     KC_I,     KC_A,     KC_E,     KC_SCLN,                       KC_K,     KC_H,     KC_T,     KC_N,     KC_S,
       QUOT,     KC_MINS,  KC_COMM,  KC_DOT,   KC_SLSH,  KC_MUTE,   KC_MPLY,  KC_J,     KC_M,     KC_G,     KC_B,     KC_V,
                           KC_BSPC,  SPC_HOLD, KC_TAB,                        QK_REP,   KC_R,     KC_ENTER
    ),
    [_SYM] = LAYOUT_saegewerk(
    //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
       _______,  KC_AT,    KC_HASH,  KC_AMPR,  _______,                       _______,  EURO,     KC_DLR,   KC_PERC,  _______,
       CCED,     _______,  AGRV,     EACU,     EGRV,                          _______,  KC_LCBR,  KC_LPRN,  KC_LBRC,  KC_ASTR,
       _______,  KC_EXLM,  _______,  _______,  KC_BSLS,  _______,   _______,  _______,  KC_QUOT,  KC_GRV,   KC_CIRC,  _______,
                           _______,  _______,  _______,                       _______,  _______,  _______
    ),
    [_NAV] = LAYOUT_saegewerk(
    //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
       _______,  _______,  CTL_F,    ALT_TAB,  _______,                       KC_INS,   _______,  _______,  _______,  _______,
       _______,  _______,  _______,  _______,  _______,                       KC_DEL,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,
       CTL_Z  ,  CTL_X,    CTL_C,    CTL_V,    _______,  _______,   _______,  _______,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,
                           _______,  _______,  _______,                       _______,  _______,  _______
    ),
    [_NUM] = LAYOUT_saegewerk(
    //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
       _______,  _______,  _______,  _______,  _______,                       KC_EQUAL, KC_7,     KC_8,     KC_9,     KC_PMNS,
       _______,  _______,  _______,  _______,  _______,                       KC_DOT,   KC_4,     KC_5,     KC_6,     KC_PAST,
       _______,  _______,  _______,  _______,  _______,  _______,   _______,  KC_0,     KC_1,     KC_2,     KC_3,     KC_PSLS,
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
    if (!process_record_nav_timer(keycode, record)) return false;

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
        // case QUOT:
        //     if (record->event.pressed) {
        //         SEND_STRING(SS_TAP(X_QUOTE));
        //         SEND_STRING(SS_TAP(X_SPC));
        //     }
        //     return false;
        case ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            return false;
        default:
            return true;
    }
}

void matrix_scan_user(void) {
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > ALT_TAB_TIMER_MS) {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
}

/*===================================================================================================================*/
/*     ENCODERS                                                                                                      */
/*===================================================================================================================*/
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 1) {
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
    } else if (index == 0) {
        if (clockwise) {
            tap_code(MS_WHLD);
        } else {
            tap_code(MS_WHLU);
        }
    }
    return false;
}

/*===================================================================================================================*/
/*     KEY OVERRIDES                                                                                                 */
/*===================================================================================================================*/
const key_override_t bracket_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, KC_RBRC);
const key_override_t curly_bracket_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LCBR, KC_RCBR);
const key_override_t parenthesis_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_RPRN);
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&bracket_key_override,
	&curly_bracket_key_override,
	&parenthesis_key_override,
	&delete_key_override
};

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_BSPC:
        case QUOT:
            return true;
        default:
            return false;
    }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch (keycode) {
        case KC_BSPC:
            register_code16((!shifted) ? KC_BSPC : KC_DEL);
            break;
        case QUOT:
            if (shifted) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
            SEND_STRING(SS_TAP(X_QUOTE));
            SEND_STRING(SS_TAP(X_SPC));
            break;
        default:
            if (shifted) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

enum combos {
    ESC,
    RING_CAPSWORD,
    Z,
    Q,
    GUI_LEFT,
    GUI_RIGHT,
    ALT_LEFT,
    ALT_RIGHT,
    CTL_LEFT,
    CTL_RIGHT,
    GUI_ALT_LEFT,
    GUI_ALT_RIGHT,
    ALT_CTL_LEFT,
    ALT_CTL_RIGHT,
    GUI_CTL_LEFT,
    GUI_CTL_RIGHT,
    ALL_MODS_LEFT,
    ALL_MODS_RIGHT,
    THUMB_BASE,
    LX_NAV,
    MID_SYM,
    WX_FN,
    DP_NUMWORD
};

const uint16_t PROGMEM esc_combo[] = {KC_U, KC_L, COMBO_END};
const uint16_t PROGMEM capsword_combo[] = {KC_C, KC_S, COMBO_END};
const uint16_t PROGMEM z_combo[] = {KC_MINS,KC_COMM,COMBO_END};
const uint16_t PROGMEM q_combo[] = {KC_G,KC_B,COMBO_END};
const uint16_t PROGMEM gui_left_combo[] = {KC_C,KC_I,COMBO_END};
const uint16_t PROGMEM gui_right_combo[] = {KC_N,KC_S,COMBO_END};
const uint16_t PROGMEM alt_left_combo[] = {KC_I,KC_A,COMBO_END};
const uint16_t PROGMEM alt_right_combo[] = {KC_T,KC_N,COMBO_END};
const uint16_t PROGMEM ctl_left_combo[] = {KC_A,KC_E,COMBO_END};
const uint16_t PROGMEM ctl_right_combo[] = {KC_H,KC_T,COMBO_END};
const uint16_t PROGMEM gui_alt_left_combo[] = {KC_C,KC_I,KC_A,COMBO_END};
const uint16_t PROGMEM gui_alt_right_combo[] = {KC_T,KC_N,KC_S,COMBO_END};
const uint16_t PROGMEM alt_ctl_left_combo[] = {KC_I,KC_A,KC_E,COMBO_END};
const uint16_t PROGMEM alt_ctl_right_combo[] = {KC_H,KC_T,KC_N,COMBO_END};
const uint16_t PROGMEM gui_ctl_left_combo[] = {KC_C,KC_E,COMBO_END};
const uint16_t PROGMEM gui_ctl_right_combo[] = {KC_H,KC_S,COMBO_END};
const uint16_t PROGMEM all_mods_left_combo[] = {KC_C,KC_I,KC_A,KC_E,COMBO_END};
const uint16_t PROGMEM all_mods_right_combo[] = {KC_H,KC_T,KC_N,KC_S,COMBO_END};
const uint16_t PROGMEM thumb_base_combo[] = {SPC_HOLD,KC_R,COMBO_END};
const uint16_t PROGMEM lx_nav_combo[] = {KC_L,KC_X,COMBO_END};
const uint16_t PROGMEM mid_sym_combo[] = {KC_A,KC_T,COMBO_END};
const uint16_t PROGMEM wx_fn_combo[] = {KC_W,KC_X,COMBO_END};
const uint16_t PROGMEM dp_numword_combo[] = {KC_D,KC_P,COMBO_END};

combo_t key_combos[] = {
  [ESC] = COMBO(esc_combo, KC_ESC),
  [RING_CAPSWORD] = COMBO(capsword_combo, CW_TOGG),
  [Z] = COMBO(z_combo, KC_Z),
  [Q] = COMBO(q_combo, KC_Q),
  [GUI_LEFT] = COMBO(gui_left_combo, KC_LGUI),
  [GUI_RIGHT] = COMBO(gui_right_combo, KC_LGUI),
  [ALT_LEFT] = COMBO(alt_left_combo, KC_LALT),
  [ALT_RIGHT] = COMBO(alt_right_combo, KC_LALT),
  [CTL_LEFT] = COMBO(ctl_left_combo, KC_LCTL),
  [CTL_RIGHT] = COMBO(ctl_right_combo, KC_LCTL),
  [GUI_ALT_LEFT] = COMBO(gui_alt_left_combo, A(KC_LGUI)),
  [GUI_ALT_RIGHT] = COMBO(gui_alt_right_combo, A(KC_LGUI)),
  [ALT_CTL_LEFT] = COMBO(alt_ctl_left_combo, A(KC_LCTL)),
  [ALT_CTL_RIGHT] = COMBO(alt_ctl_right_combo, A(KC_LCTL)),
  [GUI_CTL_LEFT] = COMBO(gui_ctl_left_combo, C(KC_LGUI)),
  [GUI_CTL_RIGHT] = COMBO(gui_ctl_right_combo, C(KC_LGUI)),
  [ALL_MODS_LEFT] = COMBO(all_mods_left_combo, C(A(KC_LGUI))),
  [ALL_MODS_RIGHT] = COMBO(all_mods_right_combo, C(A(KC_LGUI))),
  [THUMB_BASE] = COMBO(thumb_base_combo, BASE),
  [LX_NAV] = COMBO(lx_nav_combo, NAVTIMER),
  [MID_SYM] = COMBO(mid_sym_combo, SYM),
  [WX_FN] = COMBO(wx_fn_combo, FN),
  [DP_NUMWORD] = COMBO(dp_numword_combo, NUMWORD)
};
