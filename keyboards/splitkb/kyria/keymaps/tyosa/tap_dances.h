#pragma once
#include "tyosa.h"

enum tap_dance_id {
    TD_COM_MIN,
    TD_DOT_UND,
    TD_SLS_EXC,
    TD_Z_TAB,
    TD_Q_ESC,
    TD_J_ENT,
    TD_M_BSP,
    TD_V_DEL,
};

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

// Actions for the TD_Z_TAB tap dance, tab on press and z on hold
void on_z_tab(tap_dance_state_t *state, void *user_data);
void z_tab_finished(tap_dance_state_t *state, void *user_data);
void z_tab_reset(tap_dance_state_t *state, void *user_data);

// Actions for the TD_Q_ESC tap dance, q on press and escape on hold
void on_q_esc(tap_dance_state_t *state, void *user_data);
void q_esc_finished(tap_dance_state_t *state, void *user_data);
void q_esc_reset(tap_dance_state_t *state, void *user_data);

// Actions for the TD_J_ENT tap dance, j on press and enter on hold
void on_j_ent(tap_dance_state_t *state, void *user_data);
void j_ent_finished(tap_dance_state_t *state, void *user_data);
void j_ent_reset(tap_dance_state_t *state, void *user_data);

// Actions for the TD_M_BSP tap dance, m on press and backspace on hold
void on_m_bsp(tap_dance_state_t *state, void *user_data);
void m_bsp_finished(tap_dance_state_t *state, void *user_data);
void m_bsp_reset(tap_dance_state_t *state, void *user_data);

// Actions for the TD_V_DEL tap dance, v on press and delete on hold
void on_v_del(tap_dance_state_t *state, void *user_data);
void v_del_finished(tap_dance_state_t *state, void *user_data);
void v_del_reset(tap_dance_state_t *state, void *user_data);
