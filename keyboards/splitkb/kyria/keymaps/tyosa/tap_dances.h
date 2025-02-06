#pragma once
#include "quantum.h"

enum tap_dance_id {
    TD_COM_MIN,
    TD_DOT_UND,
    TD_SLS_EXC,
    TD_C_COPY,
    TD_V_PASTE,
    TD_X_CUT,
    TD_Z_UNDO,
    TD_LPRN_CTL,
    TD_RPRN_ALT,
    TD_H_QUOTE,
    TD_Q_CAPS,
    TD_F_SEARCH,
    TD_L_FF
};

#define COM_MIN TD(TD_COM_MIN)
#define DOT_UND TD(TD_DOT_UND)
#define SLS_EXC TD(TD_SLS_EXC)
#define  C_COPY TD(TD_C_COPY)
#define V_PASTE TD(TD_V_PASTE)
#define  X_CUTS TD(TD_X_CUT)
#define  Z_UNDO TD(TD_Z_UNDO)
#define  HR_CLP TD(TD_LPRN_CTL)
#define  HR_ARP TD(TD_RPRN_ALT)
#define H_QUOTE TD(TD_H_QUOTE)
#define  Q_CAPS TD(TD_Q_CAPS)
#define F_SEARC TD(TD_F_SEARCH)
#define    L_FF TD(TD_L_FF)

// Actions for the TD_COM_MIN tap dance, comma on press and minus on hold
void com_min_tap(tap_dance_state_t *state, void *user_data);
void com_min_finished(tap_dance_state_t *state, void *user_data);
void com_min_reset(tap_dance_state_t *state, void *user_data);

// Actions for the TD_DOT_UND tap dance, dot on press and underscore on hold
void dot_und_tap(tap_dance_state_t *state, void *user_data);
void dot_und_finished(tap_dance_state_t *state, void *user_data);
void dot_und_reset(tap_dance_state_t *state, void *user_data);

// Actions for the TD_SLS_EXC tap dance, slash on press and exclamation mark on hold
void sls_exc_tap(tap_dance_state_t *state, void *user_data);
void sls_exc_finished(tap_dance_state_t *state, void *user_data);
void sls_exc_reset(tap_dance_state_t *state, void *user_data);

// Actions for the TD_C_COPY tap dance, c on press and Ctrl-C on hold
void c_copy_tap(tap_dance_state_t *state, void *user_data);
void c_copy_finished(tap_dance_state_t *state, void *user_data);
void c_copy_reset(tap_dance_state_t *state, void *user_data);

// Actions for the TD_V_PASTE tap dance, v on press and Ctrl-V on hold
void v_paste_tap(tap_dance_state_t *state, void *user_data);
void v_paste_finished(tap_dance_state_t *state, void *user_data);
void v_paste_reset(tap_dance_state_t *state, void *user_data);

// Actions for the TD_X_CUT tap dance, x on press and Ctrl-X on hold
void x_cut_tap(tap_dance_state_t *state, void *user_data);
void x_cut_finished(tap_dance_state_t *state, void *user_data);
void x_cut_reset(tap_dance_state_t *state, void *user_data);

// Actions for the TD_Z_UNDO tap dance, z on press and Ctrl-Z on hold
void z_undo_tap(tap_dance_state_t *state, void *user_data);
void z_undo_finished(tap_dance_state_t *state, void *user_data);
void z_undo_reset(tap_dance_state_t *state, void *user_data);

// Actions for the TD_LPRN_CTL tap dance, ( on press and Ctrl on hold
void lprn_ctl_tap(tap_dance_state_t *state, void *user_data);
void lprn_ctl_finished(tap_dance_state_t *state, void *user_data);
void lprn_ctl_reset(tap_dance_state_t *state, void *user_data);

// Actions for the TD_RPRN_ALT tap dance, ) on press and Alt on hold
void rprn_alt_tap(tap_dance_state_t *state, void *user_data);
void rprn_alt_finished(tap_dance_state_t *state, void *user_data);
void rprn_alt_reset(tap_dance_state_t *state, void *user_data);

// Actions for the TD_H_QUOTE tap dance, H on press and Quick quotes on hold
void on_h_quote(tap_dance_state_t *state, void *user_data);
void h_quote_finished(tap_dance_state_t *state, void *user_data);
void h_quote_reset(tap_dance_state_t *state, void *user_data);

// Actions for the TD_Q_CAPS tap dance, Q on press and toggle caps lock on hold
void on_q_caps(tap_dance_state_t *state, void *user_data);
void q_caps_finished(tap_dance_state_t *state, void *user_data);
void q_caps_reset(tap_dance_state_t *state, void *user_data);

// Actions for the TD_F_SEARCH tap dance, f on press and Ctrl-F on hold
void f_search_tap(tap_dance_state_t *state, void *user_data);
void f_search_finished(tap_dance_state_t *state, void *user_data);
void f_search_reset(tap_dance_state_t *state, void *user_data);

// Actions for the TD_L_FF tap dance, l on press and Ctrl-L on hold
void l_ff_tap(tap_dance_state_t *state, void *user_data);
void l_ff_finished(tap_dance_state_t *state, void *user_data);
void l_ff_reset(tap_dance_state_t *state, void *user_data);
