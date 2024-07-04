#include "tap_dances.h"
#include "macros.h"

tap_dance_action_t tap_dance_actions[] = {
  [TD_COM_MIN] = ACTION_TAP_DANCE_FN_ADVANCED(on_com_min, com_min_finished, com_min_reset),
  [TD_DOT_UND] = ACTION_TAP_DANCE_FN_ADVANCED(on_dot_und, dot_und_finished, dot_und_reset),
  [TD_SLS_EXC] = ACTION_TAP_DANCE_FN_ADVANCED(on_sls_exc, sls_exc_finished, sls_exc_reset),
  [TD_C_COPY] = ACTION_TAP_DANCE_FN_ADVANCED(on_c_copy, c_copy_finished, c_copy_reset),
  [TD_V_PASTE] = ACTION_TAP_DANCE_FN_ADVANCED(on_v_paste, v_paste_finished, v_paste_reset),
  [TD_X_CUT] = ACTION_TAP_DANCE_FN_ADVANCED(on_x_cut, x_cut_finished, x_cut_reset),
  [TD_Z_UNDO] = ACTION_TAP_DANCE_FN_ADVANCED(on_z_undo, z_undo_finished, z_undo_reset),
  [TD_LPRN_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(on_lprn_ctl, lprn_ctl_finished, lprn_ctl_reset),
  [TD_RPRN_ALT] = ACTION_TAP_DANCE_FN_ADVANCED(on_rprn_alt, rprn_alt_finished, rprn_alt_reset),
  [TD_H_QUOTE] = ACTION_TAP_DANCE_FN_ADVANCED(on_h_quote, h_quote_finished, h_quote_reset),
  [TD_Q_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(on_q_caps, q_caps_finished, q_caps_reset),
  [TD_F_SEARCH] = ACTION_TAP_DANCE_FN_ADVANCED(on_f_search, f_search_finished, f_search_reset),
};

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

/* single_hold_or_tap : hold hold_code on single hold, else tap tap_code (if held after tapping, hold tap_code) */
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

/* Method implementations */
void on_com_min(tap_dance_state_t *state, void *user_data) {
    on_single_hold_or_tap(state, KC_COMM);
}

void com_min_finished(tap_dance_state_t *state, void *user_data) {
    single_hold_or_tap_finished(state, KC_COMM, KC_MINS);
}

void com_min_reset(tap_dance_state_t *state, void *user_data) {
    single_hold_or_tap_reset(state, KC_COMM, KC_MINS);
}

void on_dot_und(tap_dance_state_t *state, void *user_data) {
    on_single_hold_or_tap(state, KC_DOT);
}

void dot_und_finished(tap_dance_state_t *state, void *user_data) {
    single_hold_or_tap_finished(state, KC_DOT, KC_UNDS);
}

void dot_und_reset(tap_dance_state_t *state, void *user_data) {
    single_hold_or_tap_reset(state, KC_DOT, KC_UNDS);
}

void on_sls_exc(tap_dance_state_t *state, void *user_data) {
    on_single_hold_or_tap(state, KC_SLSH);
}

void sls_exc_finished(tap_dance_state_t *state, void *user_data) {
    single_hold_or_tap_finished(state, KC_SLSH, KC_EXLM);
}

void sls_exc_reset(tap_dance_state_t *state, void *user_data) {
    single_hold_or_tap_reset(state, KC_SLSH, KC_EXLM);
}

void on_c_copy(tap_dance_state_t *state, void *user_data) {
    on_single_hold_or_tap(state, KC_C);
}

void c_copy_finished(tap_dance_state_t *state, void *user_data) {
    single_hold_or_tap_finished(state, KC_C, C(KC_C));
}

void c_copy_reset(tap_dance_state_t *state, void *user_data) {
    single_hold_or_tap_reset(state, KC_C, C(KC_C));
}

void on_v_paste(tap_dance_state_t *state, void *user_data) {
    on_single_hold_or_tap(state, KC_V);
}

void v_paste_finished(tap_dance_state_t *state, void *user_data) {
    single_hold_or_tap_finished(state, KC_V, C(KC_V));
}

void v_paste_reset(tap_dance_state_t *state, void *user_data) {
    single_hold_or_tap_reset(state, KC_V, C(KC_V));
}

void on_x_cut(tap_dance_state_t *state, void *user_data) {
    on_single_hold_or_tap(state, KC_X);
}

void x_cut_finished(tap_dance_state_t *state, void *user_data) {
    single_hold_or_tap_finished(state, KC_X, C(KC_X));
}

void x_cut_reset(tap_dance_state_t *state, void *user_data) {
    single_hold_or_tap_reset(state, KC_X, C(KC_X));
}

void on_z_undo(tap_dance_state_t *state, void *user_data) {
    on_single_hold_or_tap(state, KC_Z);
}

void z_undo_finished(tap_dance_state_t *state, void *user_data) {
    single_hold_or_tap_finished(state, KC_Z, C(KC_Z));
}

void z_undo_reset(tap_dance_state_t *state, void *user_data) {
    single_hold_or_tap_reset(state, KC_Z, C(KC_Z));
}

void on_lprn_ctl(tap_dance_state_t *state, void *user_data) {
    on_single_hold_or_tap(state, KC_LPRN);
}

void lprn_ctl_finished(tap_dance_state_t *state, void *user_data) {
    single_hold_or_tap_finished(state, KC_LPRN, KC_LCTL);
}

void lprn_ctl_reset(tap_dance_state_t *state, void *user_data) {
    single_hold_or_tap_reset(state, KC_LPRN, KC_LCTL);
}

void on_rprn_alt(tap_dance_state_t *state, void *user_data) {
    on_single_hold_or_tap(state, KC_RPRN);
}

void rprn_alt_finished(tap_dance_state_t *state, void *user_data) {
    single_hold_or_tap_finished(state, KC_RPRN, KC_LALT);
}

void rprn_alt_reset(tap_dance_state_t *state, void *user_data) {
    single_hold_or_tap_reset(state, KC_RPRN, KC_LALT);
}

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

void on_f_search(tap_dance_state_t *state, void *user_data) {
    on_single_hold_or_tap(state, KC_F);
}

void f_search_finished(tap_dance_state_t *state, void *user_data) {
    single_hold_or_tap_finished(state, KC_F, C(KC_F));
}

void f_search_reset(tap_dance_state_t *state, void *user_data) {
    single_hold_or_tap_reset(state, KC_F, C(KC_F));
}
