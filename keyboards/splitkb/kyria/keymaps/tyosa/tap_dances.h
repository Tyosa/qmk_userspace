#pragma once
#include "quantum.h"

enum tap_dance_id {
    TD_COM_MIN,
    TD_DOT_UND,
    TD_SLS_EXC,
};

#define  COM_MIN    TD(TD_COM_MIN)
#define  DOT_UND    TD(TD_DOT_UND)
#define  SLS_EXC    TD(TD_SLS_EXC)

// Actions for the TD_COM_MIN tap dance, comma on press and minus on hold
void on_com_min(tap_dance_state_t *state, void *user_data);
void com_min_finished(tap_dance_state_t *state, void *user_data);
void com_min_reset(tap_dance_state_t *state, void *user_data);

// Actions for the TD_DOT_UND tap dance, dot on press and underscore on hold
void on_dot_und(tap_dance_state_t *state, void *user_data);
void dot_und_finished(tap_dance_state_t *state, void *user_data);
void dot_und_reset(tap_dance_state_t *state, void *user_data);

// Actions for the TD_SLS_EXC tap dance, slash on press and exclamation mark on hold
void on_sls_exc(tap_dance_state_t *state, void *user_data);
void sls_exc_finished(tap_dance_state_t *state, void *user_data);
void sls_exc_reset(tap_dance_state_t *state, void *user_data);
