#include "tap_dances.h"
#include "macros.h"

tap_dance_action_t tap_dance_actions[] = {
  [TD_COM_MIN] = ACTION_TAP_DANCE_FN_ADVANCED(com_min_tap, com_min_finished, com_min_reset),
  [TD_DOT_UND] = ACTION_TAP_DANCE_FN_ADVANCED(dot_und_tap, dot_und_finished, dot_und_reset),
  [TD_SLS_EXC] = ACTION_TAP_DANCE_FN_ADVANCED(sls_exc_tap, sls_exc_finished, sls_exc_reset),
  [TD_C_COPY] = ACTION_TAP_DANCE_FN_ADVANCED(c_copy_tap, c_copy_finished, c_copy_reset),
  [TD_V_PASTE] = ACTION_TAP_DANCE_FN_ADVANCED(v_paste_tap, v_paste_finished, v_paste_reset),
  [TD_X_CUT] = ACTION_TAP_DANCE_FN_ADVANCED(x_cut_tap, x_cut_finished, x_cut_reset),
  [TD_Z_UNDO] = ACTION_TAP_DANCE_FN_ADVANCED(z_undo_tap, z_undo_finished, z_undo_reset),
  [TD_LPRN_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(lprn_ctl_tap, lprn_ctl_finished, lprn_ctl_reset),
  [TD_RPRN_ALT] = ACTION_TAP_DANCE_FN_ADVANCED(rprn_alt_tap, rprn_alt_finished, rprn_alt_reset),
  [TD_H_QUOTE] = ACTION_TAP_DANCE_FN_ADVANCED(on_h_quote, h_quote_finished, h_quote_reset),
  [TD_Q_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(on_q_caps, q_caps_finished, q_caps_reset),
  [TD_F_SEARCH] = ACTION_TAP_DANCE_FN_ADVANCED(f_search_tap, f_search_finished, f_search_reset),
  [TD_L_FF] = ACTION_TAP_DANCE_FN_ADVANCED(l_ff_tap, l_ff_finished, l_ff_reset),
};

/* Typedefs */

typedef enum {
    NONE,
    SINGLE_TAP,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t step;
} td_tap_t;

static td_tap_t dance_state = {
    .is_press_action = true,
    .step = NONE
};

/* Helper method for tap and hold behavior */

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state -> count == 1) {
        if (state -> interrupted || !state -> pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state -> count == 2) {
        if (state -> interrupted) return DOUBLE_SINGLE_TAP;
        else if (state -> pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void on_single_hold_or_tap(tap_dance_state_t *state, uint16_t tap_code) {
    if (state->count == 3) {
        tap_code16(tap_code);
        tap_code16(tap_code);
        tap_code16(tap_code);
    }
    if (state->count > 3) {
        tap_code16(tap_code);
    }
}

void single_hold_or_tap_finished(tap_dance_state_t *state, uint16_t tap_code, uint16_t hold_code) {
    dance_state.step = cur_dance(state);
    switch (dance_state.step) {
        case SINGLE_TAP:
            register_code16(tap_code);
            break;
        case SINGLE_HOLD:
            register_code16(hold_code);
            break;
        case DOUBLE_TAP:
            register_code16(tap_code);
            register_code16(tap_code);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(tap_code);
            register_code16(tap_code);
            break;
        default :
            break;
    }
}

void single_hold_or_tap_reset(tap_dance_state_t *state, uint16_t tap_code, uint16_t hold_code) {
    switch (dance_state.step) {
        case SINGLE_TAP:
            unregister_code16(tap_code);
            break;
        case SINGLE_HOLD:
            unregister_code16(hold_code);
            break;
        case DOUBLE_TAP:
            unregister_code16(tap_code);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(tap_code);
            break;
        default :
            break;
    }
    dance_state.step = NONE;
}

/* Macro to generate every methods used with a simple tap/hold behavior :
 *   - if held it will hold the HOLD keycode
 *   - else it will tap the TAP keycode
 *   - in case of a tap then hold, hold TAP
 */
#define GENERATE_SINGLE_HOLD_OR_TAP(NAME, TAP, HOLD)                       \
    void NAME##_tap(tap_dance_state_t *state, void *user_data) {           \
        on_single_hold_or_tap(state, TAP);                                 \
    }                                                                      \
    void NAME##_finished(tap_dance_state_t *state, void *user_data) {      \
        single_hold_or_tap_finished(state, TAP , HOLD);                    \
    }                                                                      \
    void NAME##_reset(tap_dance_state_t *state, void *user_data) {         \
        single_hold_or_tap_reset(state, TAP , HOLD);                       \
    }

GENERATE_SINGLE_HOLD_OR_TAP(com_min, KC_COMM, KC_MINS)
GENERATE_SINGLE_HOLD_OR_TAP(dot_und, KC_DOT, KC_UNDS)
GENERATE_SINGLE_HOLD_OR_TAP(sls_exc, KC_SLSH, KC_EXLM)
GENERATE_SINGLE_HOLD_OR_TAP(c_copy, KC_C, C(KC_C))
GENERATE_SINGLE_HOLD_OR_TAP(v_paste, KC_V, C(KC_V))
GENERATE_SINGLE_HOLD_OR_TAP(x_cut, KC_X, C(KC_X))
GENERATE_SINGLE_HOLD_OR_TAP(z_undo, KC_Z, C(KC_Z))
GENERATE_SINGLE_HOLD_OR_TAP(lprn_ctl, KC_LPRN, KC_LCTL)
GENERATE_SINGLE_HOLD_OR_TAP(rprn_alt, KC_RPRN, KC_LALT)
GENERATE_SINGLE_HOLD_OR_TAP(f_search, KC_F, C(KC_F))
GENERATE_SINGLE_HOLD_OR_TAP(l_ff, KC_L, C(KC_L))

/* Specific behavior methods */

void on_h_quote(tap_dance_state_t *state, void *user_data) {
    on_single_hold_or_tap(state, KC_H);
}

void h_quote_finished(tap_dance_state_t *state, void *user_data) {
    dance_state.step = cur_dance(state);
    switch (dance_state.step) {
        case SINGLE_TAP:
            register_code16(KC_H);
            break;
        case SINGLE_HOLD:
            function_quick_quote();
            break;
        case DOUBLE_TAP:
            register_code16(KC_H);
            register_code16(KC_H);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_H);
            register_code16(KC_H);
            break;
        default :
            break;
    }
}

void h_quote_reset(tap_dance_state_t *state, void *user_data) {
    switch (dance_state.step) {
        case SINGLE_TAP:
            unregister_code16(KC_H);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_H);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_H);
            break;
        default :
            break;
    }
    dance_state.step = NONE;
}

void on_q_caps(tap_dance_state_t *state, void *user_data) {
    on_single_hold_or_tap(state, KC_Q);
}

void q_caps_finished(tap_dance_state_t *state, void *user_data) {
    single_hold_or_tap_finished(state, KC_Q, KC_CAPS);
}

void q_caps_reset(tap_dance_state_t *state, void *user_data) {
    switch (dance_state.step) {
        case SINGLE_TAP:
            unregister_code16(KC_Q);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_Q);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_Q);
            break;
        default :
            break;
    }
    dance_state.step = NONE;
}

