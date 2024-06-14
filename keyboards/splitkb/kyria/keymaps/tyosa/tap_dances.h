#pragma once
#include "quantum.h"

enum tap_dance_id {
    TD_COM_MIN,
    TD_DOT_UND,
    TD_SLS_EXC,
    TD_C_COPY,
    TD_V_PASTE,
    TD_X_CUT,
    TD_Z_UNDO
};

#define  COM_MIN    TD(TD_COM_MIN)
#define  DOT_UND    TD(TD_DOT_UND)
#define  SLS_EXC    TD(TD_SLS_EXC)
#define   C_COPY    TD(TD_C_COPY)
#define  V_PASTE    TD(TD_V_PASTE)
#define   X_CUTS    TD(TD_X_CUT)
#define   Z_UNDO    TD(TD_Z_UNDO)

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

// Actions for the TD_C_COPY tap dance, c on press and Ctrl-C on hold
void on_c_copy(tap_dance_state_t *state, void *user_data);
void c_copy_finished(tap_dance_state_t *state, void *user_data);
void c_copy_reset(tap_dance_state_t *state, void *user_data);

// Actions for the TD_V_PASTE tap dance, v on press and Ctrl-V on hold
void on_v_paste(tap_dance_state_t *state, void *user_data);
void v_paste_finished(tap_dance_state_t *state, void *user_data);
void v_paste_reset(tap_dance_state_t *state, void *user_data);

// Actions for the TD_X_CUT tap dance, x on press and Ctrl-X on hold
void on_x_cut(tap_dance_state_t *state, void *user_data);
void x_cut_finished(tap_dance_state_t *state, void *user_data);
void x_cut_reset(tap_dance_state_t *state, void *user_data);

// Actions for the TD_Z_UNDO tap dance, z on press and Ctrl-Z on hold
void on_z_undo(tap_dance_state_t *state, void *user_data);
void z_undo_finished(tap_dance_state_t *state, void *user_data);
void z_undo_reset(tap_dance_state_t *state, void *user_data);
