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
