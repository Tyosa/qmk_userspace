#include "macros.h"
#include "quantum.h"

void function_quick_quote(void) {
    SEND_STRING(SS_TAP(X_QUOTE));
    SEND_STRING(SS_TAP(X_SPC));
}

void function_c_ced(void) {
    register_code(KC_RALT);
    SEND_STRING(",");
    unregister_code(KC_RALT);
}

void function_a_grv(uint8_t mod_state) {
    del_mods(MOD_MASK_SHIFT);
    SEND_STRING(SS_TAP(X_GRV));
    set_mods(mod_state);
    SEND_STRING("a");
}

void function_e_grv(uint8_t mod_state) {
    del_mods(MOD_MASK_SHIFT);
    SEND_STRING(SS_TAP(X_GRV));
    set_mods(mod_state);
    SEND_STRING("e");
}

void function_e_aig(uint8_t mod_state) {
    del_mods(MOD_MASK_SHIFT);
    SEND_STRING(SS_TAP(X_QUOTE));
    set_mods(mod_state);
    SEND_STRING("e");
}
