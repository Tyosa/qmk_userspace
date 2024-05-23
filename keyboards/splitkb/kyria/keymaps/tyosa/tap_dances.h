#include "tyosa.h"
#include "tap_dances.h"

// COM_MIN tap dance : single tap comma, hold minus
void on_com_min(tap_dance_state_t *state, void *user_data);
uint8_t com_min_dance_step(tap_dance_state_t *state);
void com_min_finished(tap_dance_state_t *state, void *user_data);
void com_min_reset(tap_dance_state_t *state, void *user_data);

// DOT_UND tap dance : single tap dot, hold underscore
void on_dot_und(tap_dance_state_t *statex, void *user_data);
uint8_t dot_und_dance_step(tap_dance_state_t *state);
void dot_und_finished(tap_dance_state_t *state, void *user_data);
void dot_und_reset(tap_dance_state_t *state, void *user_data);

// SLS_EXC tap dance : single tap slash, hold exclamation point
void on_sls_exc(tap_dance_state_t *statex, void *user_data);
uint8_t sls_exc_dance_step(tap_dance_state_t *state);
void sls_exc_finished(tap_dance_state_t *state, void *user_data);
void sls_exc_reset(tap_dance_state_t *state, void *user_data);
