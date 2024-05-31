#include "tap_dances.h"

tap_dance_action_t tap_dance_actions[] = {
  [TD_COM_MIN] = ACTION_TAP_DANCE_FN_ADVANCED(on_com_min, com_min_finished, com_min_reset),
  [TD_DOT_UND] = ACTION_TAP_DANCE_FN_ADVANCED(on_dot_und, dot_und_finished, dot_und_reset),
  [TD_SLS_EXC] = ACTION_TAP_DANCE_FN_ADVANCED(on_sls_exc, sls_exc_finished, sls_exc_reset),
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
            unregister_code16(hold_code);
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

