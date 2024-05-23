#include "tyosa.h"
#include "quantum.h"

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

uint8_t com_min_dance_step(tap_dance_state_t *state) {
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

void com_min_finished(tap_dance_state_t *state, void *user_data) {
    dance_state.step = com_min_dance_step(state);
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

tap_dance_action_t tap_dance_actions[] = {
  [COM_MIN] = ACTION_TAP_DANCE_FN_ADVANCED(on_com_min, com_min_finished, com_min_reset),
};
