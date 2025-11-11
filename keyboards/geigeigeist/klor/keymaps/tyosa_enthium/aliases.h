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
    NAVTIMER,
    ALT_TAB,
};

enum layers {
    _BASE = 0,
    _SYM,
    _NAV,
    _NUM,
    _FN
};

// Layer navigation
#define BASE    TO(_BASE)
#define SPC_HOLD MT(MOD_LSFT, KC_SPC)
#define SYM     OSL(_SYM)
#define FN      OSL(_FN)

// Keys that send their value on tap and send Ctrl+their value on hold
#define CTL_Z   C(KC_Z)
#define CTL_X   C(KC_X)
#define CTL_C   C(KC_C)
#define CTL_V   C(KC_V)
#define CTL_F   C(KC_F)
