#include "tyosa.h"
#include "tap_dances.h"

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

void on_com_min(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_COMM);
        tap_code16(KC_COMM);
        tap_code16(KC_COMM);
    }
    if(state->count > 3) {
        tap_code16(KC_COMM);
    }
}

void com_min_finished(tap_dance_state_t *state, void *user_data) {
    dance_state.step = cur_dance(state);
    switch (dance_state.step) {
        case SINGLE_TAP:
            register_code16(KC_COMM);
            break;
        case SINGLE_HOLD:
            register_code16(KC_MINS);
            break;
        case DOUBLE_TAP:
            register_code16(KC_COMM);
            register_code16(KC_COMM);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_COMM);
            register_code16(KC_COMM);
            break;
        default :
            break;
    }
}

void com_min_reset(tap_dance_state_t *state, void *user_data) {
    switch (dance_state.step) {
        case SINGLE_TAP:
            unregister_code16(KC_COMM);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_MINS);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_COMM);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_MINS);
            break;
        default :
            break;
    }
    dance_state.step = NONE;
}

void on_dot_und(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
    }
    if(state->count > 3) {
        tap_code16(KC_DOT);
    }
}

void dot_und_finished(tap_dance_state_t *state, void *user_data) {
    dance_state.step = cur_dance(state);
    switch (dance_state.step) {
        case SINGLE_TAP:
            register_code16(KC_DOT);
            break;
        case SINGLE_HOLD:
            register_code16(KC_UNDS);
            break;
        case DOUBLE_TAP:
            register_code16(KC_DOT);
            register_code16(KC_DOT);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_DOT);
            register_code16(KC_DOT);
            break;
        default :
            break;
    }
}

void dot_und_reset(tap_dance_state_t *state, void *user_data) {
    switch (dance_state.step) {
        case SINGLE_TAP:
            unregister_code16(KC_DOT);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_UNDS);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_DOT);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_UNDS);
            break;
        default :
            break;
    }
    dance_state.step = NONE;
}

void on_sls_exc(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SLSH);
        tap_code16(KC_SLSH);
        tap_code16(KC_SLSH);
    }
    if(state->count > 3) {
        tap_code16(KC_SLSH);
    }
}

void sls_exc_finished(tap_dance_state_t *state, void *user_data) {
    dance_state.step = cur_dance(state);
    switch (dance_state.step) {
        case SINGLE_TAP:
            register_code16(KC_SLSH);
            break;
        case SINGLE_HOLD:
            register_code16(KC_EXLM);
            break;
        case DOUBLE_TAP:
            register_code16(KC_SLSH);
            register_code16(KC_SLSH);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_SLSH);
            register_code16(KC_SLSH);
            break;
        default :
            break;
    }
}

void sls_exc_reset(tap_dance_state_t *state, void *user_data) {
    switch (dance_state.step) {
        case SINGLE_TAP:
            unregister_code16(KC_SLSH);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_EXLM);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_SLSH);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_EXLM);
            break;
        default :
            break;
    }
    dance_state.step = NONE;
}

void on_z_tab(tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if (state->count > 3) {
        tap_code16(KC_TAB);
    }
}

void z_tab_finished(tap_dance_state_t *state, void *user_data) {
    dance_state.step = cur_dance(state);
    switch (dance_state.step) {
        case SINGLE_TAP:
            register_code16(KC_TAB);
            break;
        case SINGLE_HOLD:
            register_code(KC_Z);
            break;
        case DOUBLE_TAP:
            register_code16(KC_TAB);
            register_code16(KC_TAB);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_TAB);
            register_code16(KC_TAB);
            break;
        default :
            break;
    }
}

void z_tab_reset(tap_dance_state_t *state, void *user_data) {
    switch (dance_state.step) {
        case SINGLE_TAP:
            unregister_code16(KC_TAB);
            break;
        case SINGLE_HOLD:
            unregister_code(KC_Z);
        case DOUBLE_TAP:
            unregister_code16(KC_TAB);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_TAB);
            break;
        default :
            break;
    }
    dance_state.step = NONE;
}

void on_q_esc(tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code(KC_Q);
        tap_code(KC_Q);
        tap_code(KC_Q);
    }
    if (state->count > 3) {
        tap_code(KC_Q);
    }
}

void q_esc_finished(tap_dance_state_t *state, void *user_data) {
    dance_state.step = cur_dance(state);
    switch (dance_state.step) {
        case SINGLE_TAP:
            register_code(KC_Q);
            break;
        case SINGLE_HOLD:
            register_code16(KC_ESC);
            break;
        case DOUBLE_TAP:
            register_code(KC_Q);
            register_code(KC_Q);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_TAB);
            register_code(KC_Q);
            break;
        default :
            break;
    }
}

void q_esc_reset(tap_dance_state_t *state, void *user_data) {
    switch (dance_state.step) {
        case SINGLE_TAP:
            unregister_code(KC_Q);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_ESC);
        case DOUBLE_TAP:
            unregister_code(KC_Q);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code(KC_Q);
            break;
        default :
            break;
    }
    dance_state.step = NONE;
}
