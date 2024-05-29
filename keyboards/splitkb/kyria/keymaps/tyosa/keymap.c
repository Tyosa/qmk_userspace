#include "quantum.h"
#include "tyosa.h"
#include "encoder.h"
#include "tap_dances.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK_DH] = LAYOUT(
             KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                        KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_ENT,
             KC_TAB,   HR_GA,   HR_AR,   HR_CS,   HR_ST,    KC_G,                                        KC_M,   HR_SN,   HR_CE,   HR_AI,   HR_GO, KC_BSPC,
            XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, XXXXXXX, KC_LENC, KC_RENC, XXXXXXX,    KC_K,    KC_H, COM_MIN, DOT_UND, SLS_EXC,  KC_DEL,
                                       XXXXXXX, XXXXXXX, XXXXXXX, MEH_SPC, OS_LSFT, OS_LCTL,     SYM, XXXXXXX, XXXXXXX, XXXXXXX
            ),
    [_SYM] = LAYOUT(
             KC_ESC, KC_PERC,   KC_AT, KC_HASH,  KC_DLR, XXXXXXX,                                     XXXXXXX, KC_AMPR, KC_ASTR,  KC_GRV, KC_CIRC,  KC_ENT,
             KC_TAB, QC_AGRV, QC_EGRV, QC_EAIG, XXXXXXX, XXXXXXX,                                     XXXXXXX, KC_LBRC, KC_LPRN, KC_RPRN, KC_RBRC, KC_BSPC,
            XXXXXXX, XXXXXXX, XXXXXXX, QC_CCED, XXXXXXX, XXXXXXX, XXXXXXX, KC_LENC, KC_RENC, XXXXXXX, QC_QUOT, KC_BSLS, KC_LCBR, KC_RCBR,     NAV,  KC_DEL,
                                       XXXXXXX, XXXXXXX, XXXXXXX, COLEMAK, OS_LSFT, KC_RALT,     NUM, XXXXXXX, XXXXXXX, XXXXXXX
            ),
    [_NAV] = LAYOUT(
             KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX,    PREV,    PTAB,    NTAB,    NEXT,  KC_ENT,
             KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_BSPC,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LENC, KC_RENC, XXXXXXX, XXXXXXX, KC_HOME, XXXXXXX, XXXXXXX,  KC_END,  KC_DEL,
                                       XXXXXXX, XXXXXXX, XXXXXXX, COLEMAK, KC_LSFT, KC_RCTL,     SYM, XXXXXXX, XXXXXXX, XXXXXXX
            ),
    [_NUM] = LAYOUT(
             KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     KC_PAST,    KC_7,    KC_8,    KC_9, KC_MINS,  KC_ENT,
             KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     KC_PDOT,    KC_4,    KC_5,    KC_6,  KC_EQL,  KC_BSPC,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LENC, KC_RENC, XXXXXXX,    KC_0,    KC_1,    KC_2,    KC_3,     NAV,  KC_DEL,
                                       XXXXXXX, XXXXXXX, XXXXXXX, COLEMAK, OS_LSFT, OS_LCTL,     SYM, XXXXXXX, XXXXXXX, XXXXXXX
            ),
};

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch (keycode) {
        case QC_EAIG:
            if (record->event.pressed) {
                del_mods(MOD_MASK_SHIFT);
                SEND_STRING(SS_TAP(X_QUOTE));
                set_mods(mod_state);
                SEND_STRING("e");
            }
            return true;
        case QC_EGRV:
            if (record->event.pressed) {
                del_mods(MOD_MASK_SHIFT);
                SEND_STRING(SS_TAP(X_GRV));
                set_mods(mod_state);
                SEND_STRING("e");
            }
            return true;
        case QC_AGRV:
            if (record->event.pressed) {
                del_mods(MOD_MASK_SHIFT);
                SEND_STRING(SS_TAP(X_GRV));
                set_mods(mod_state);
                SEND_STRING("a");
            }
            return true;
        case QC_CCED:
            if (record->event.pressed) {
                register_code(KC_RALT);
                SEND_STRING(",");
                unregister_code(KC_RALT);
            }
            return true;
        case KC_LENC:
            if (record->tap.count && record->event.pressed) {
                left_encoder_click();
            } else if (record->event.pressed) {
                left_encoder_hold();
            }
            return false;
        case KC_RENC:
            if (record->tap.count && record->event.pressed) {
                right_encoder_click();
            } else if (record->event.pressed) {
                right_encoder_hold();
            }
            return false;
        case QC_QUOT: //TODO double press the quote and put cursor between them ?
            if (record -> event.pressed) {
                SEND_STRING(SS_TAP(X_QUOTE));
                SEND_STRING(SS_TAP(X_SPC));
            }
            return false;
    }
    return true;
};

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 750) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
  if (get_highest_layer(layer_state) != _COLEMAK_DH) {
      if (last_input_activity_elapsed() > LAYER_TIMEOUT) {
          layer_move(_COLEMAK_DH);
      }
  }
}

tap_dance_action_t tap_dance_actions[] = {
  [TD_COM_MIN] = ACTION_TAP_DANCE_FN_ADVANCED(on_com_min, com_min_finished, com_min_reset),
  [TD_DOT_UND] = ACTION_TAP_DANCE_FN_ADVANCED(on_dot_und, dot_und_finished, dot_und_reset),
  [TD_SLS_EXC] = ACTION_TAP_DANCE_FN_ADVANCED(on_sls_exc, sls_exc_finished, sls_exc_reset),
  [TD_Z_TAB] = ACTION_TAP_DANCE_FN_ADVANCED(on_z_tab, z_tab_finished, z_tab_reset),
  [TD_Q_ESC] = ACTION_TAP_DANCE_FN_ADVANCED(on_q_esc, q_esc_finished, q_esc_reset),
  [TD_J_ENT] = ACTION_TAP_DANCE_FN_ADVANCED(on_j_ent, j_ent_finished, j_ent_reset),
  [TD_M_BSP] = ACTION_TAP_DANCE_FN_ADVANCED(on_m_bsp, m_bsp_finished, m_bsp_reset),
  [TD_V_DEL] = ACTION_TAP_DANCE_FN_ADVANCED(on_v_del, v_del_finished, v_del_reset),
};

