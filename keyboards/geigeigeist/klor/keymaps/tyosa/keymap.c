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
#include <stdint.h>
#include "keycodes.h"
#include "keymap_us.h"
#include "process_combo.h"
#include "progmem.h"
#include "quantum.h"
#include "klor.h"
#include "quantum_keycodes.h"

enum layers {
    _COLEMAK=0,
    _SYM,
    _NAV,
    _NUM,
    _FN,
};

enum custom_keys {
    CCED=SAFE_RANGE, // ç
    EACU,            // é
    EGRV,            // è
    AGRV,            // à
    EURO,            // €
    QUOT,            // Quick quote
};

// Layer navigation
#define BASE  TO(_COLEMAK)
#define SYM   TO(_SYM)
#define SPC_NAV LT(_NAV, KC_SPC)
#define NUM   TO(_NUM)
#define FN    TO(_FN)

// Left hand home-row mods
#define GUI_A MT(MOD_LGUI, KC_A)
#define ALT_R MT(MOD_LALT, KC_R)
#define CTL_S MT(MOD_LCTL, KC_S)
#define SHT_T MT(MOD_LSFT, KC_T)
#define MEH_G MT(MOD_MEH, KC_G)

// Right hand home-row mods
#define MEH_M MT(MOD_MEH, KC_M)
#define SHT_N MT(MOD_RSFT, KC_N)
#define CTL_E MT(MOD_LCTL, KC_E)
#define ALT_I MT(MOD_LALT, KC_I)
#define GUI_O MT(MOD_LGUI, KC_O)

/*
   [_TEMPLATE] = LAYOUT_saegewerk(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
    _______,  _______,  _______,  _______,  _______,                       _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,                       _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,
                        _______,  _______,  _______,                       _______,  _______,  _______
 ),
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_saegewerk(
    //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
       KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,                          KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,
       GUI_A,    ALT_R,    CTL_S,    SHT_T,    MEH_G,                         MEH_M,    SHT_N,    CTL_E,    ALT_I,    GUI_O,
       KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,     KC_MUTE,   KC_MPLY,  KC_K,     KC_H,     KC_COMMA, KC_DOT,   KC_SLASH,
                           KC_TAB,   QK_AREP,  SPC_NAV,                       KC_BSPC,  QK_REP,   KC_ENTER
    ),
    [_SYM] = LAYOUT_saegewerk(
    //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
       _______,  _______,  KC_AT,    KC_PERC,  _______,                       KC_AMPR,  _______,  KC_GRV,   KC_CIRC,  _______,
       AGRV,     EGRV,     EACU,     KC_LSFT,  _______,                       _______,  KC_LSFT,  _______,  _______,  KC_ASTR,
       _______,  _______,  CCED,     KC_DLR,   EURO,     _______,   _______,  KC_QUOT,  KC_HASH,  _______,  KC_EXLM,  KC_BSLS,
                           _______,  _______,  BASE,                          _______,  _______,  _______
    ),
    [_NAV] = LAYOUT_saegewerk(
    //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
       _______,  _______,  _______,  _______,  _______,                       KC_INS,   KC_LBRC,  KC_LPRN,  KC_RPRN,  KC_RBRC,
       _______,  _______,  _______,  _______,  _______,                       KC_DEL,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,
       _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  KC_HOME,  KC_LCBR,  KC_RCBR,  KC_END,
                           _______,  _______,  _______,                       _______,  _______,  _______
    ),
    [_NUM] = LAYOUT_saegewerk(
    //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
       _______,  _______,  _______,  _______,  _______,                       KC_EQUAL, KC_7,     KC_8,     KC_9,     KC_MINUS,
       _______,  _______,  _______,  _______,  _______,                       KC_DOT,   KC_4,     KC_5,     KC_6,     KC_ASTR,
       _______,  _______,  _______,  _______,  _______,  _______,   _______,  KC_0,     KC_1,     KC_2,     KC_3,     KC_SLASH,
                           _______,  _______,  BASE,                          _______,  _______,  _______
    ),
    [_FN] = LAYOUT_saegewerk(
    //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
       _______,  _______,  _______,  _______,  _______,                       _______,  KC_F9,    KC_F10,   KC_F11,   KC_F12,
       _______,  _______,  _______,  _______,  _______,                       _______,  KC_F5,    KC_F6,    KC_F7,    KC_F8,
       _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,
                           _______,  _______,  BASE,                       _______,  _______,  _______
    ),
};


uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
        default:
            return true;
    }
}

enum combos {
    PL_ESC,
    GUI_CAPS,
    EI_QUOT,
    HCOMM_MIN,
    COMMDOT_UNDS,
    CTL_SYM,
    SHT_NUM,
};

const uint16_t PROGMEM pl_esc_combo[] = {KC_P, KC_L, COMBO_END};
const uint16_t PROGMEM gui_caps_combo[] = {GUI_A, GUI_O, COMBO_END};
const uint16_t PROGMEM ei_quot_combo[] = {CTL_E, ALT_I, COMBO_END};
const uint16_t PROGMEM hcomm_min_combo[] = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM commdot_unds_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM ctl_sym[] = {CTL_E, CTL_S, COMBO_END};
const uint16_t PROGMEM sht_num[] = {SHT_T, SHT_N, COMBO_END};

combo_t key_combos[] = {
    [PL_ESC] = COMBO(pl_esc_combo, KC_ESC),
    [GUI_CAPS] = COMBO(gui_caps_combo, CW_TOGG),
    [EI_QUOT] = COMBO(ei_quot_combo, QUOT),
    [HCOMM_MIN] = COMBO(hcomm_min_combo, KC_MINUS),
    [COMMDOT_UNDS] = COMBO(commdot_unds_combo, KC_UNDERSCORE),
    [CTL_SYM] = COMBO(ctl_sym, SYM),
    [SHT_NUM] = COMBO(sht_num, NUM),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_saegewerk(
        'L', 'L', 'L', 'L', 'L',            'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L',            'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
                  'L', 'L', 'L',            'R', 'R', 'R'
    );

