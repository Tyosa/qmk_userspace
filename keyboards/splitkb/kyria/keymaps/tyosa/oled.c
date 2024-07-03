#include "tyosa.h"
#include "luna.h"
#include "encoder.h"


static const char LAYER_BASE[3][80] PROGMEM = {
    {252,252,252,252, 60, 60, 60, 60, 60, 60, 60, 60,192,192,192,192,  0,  0,  0,  0,192,192,192,192, 60, 60, 60, 60, 60, 60, 60, 60,192,192,192,192,  0,  0,  0,  0,192,192,192,192, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,  0,  0,  0,  0,252,252,252,252, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,  0,  0,  0,  0},
    {255,255,255,255, 60, 60, 60, 60, 60, 60, 60, 60,195,195,195,195,  0,  0,  0,  0,255,255,255,255, 60, 60, 60, 60, 60, 60, 60, 60,255,255,255,255,  0,  0,  0,  0,  3,  3,  3,  3, 60, 60, 60, 60, 60, 60, 60, 60,192,192,192,192,  0,  0,  0,  0,255,255,255,255, 60, 60, 60, 60, 60, 60, 60, 60,  0,  0,  0,  0,  0,  0,  0,  0},
    {63, 63, 63, 63, 60, 60, 60, 60, 60, 60, 60, 60,  3,  3,  3,  3,  0,  0,  0,  0, 63, 63, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0, 63, 63, 63, 63,  0,  0,  0,  0, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,  3,  3,  3,  3,  0,  0,  0,  0, 63, 63, 63, 63, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,  0,  0,  0,  0}
};

static const char LAYER_NAV[3][56] PROGMEM = {
    {252,252,252,252,192,192,192,192,  0,  0,  0,  0,252,252,252,252,  0,  0,  0,  0,192,192,192,192, 60, 60, 60, 60, 60, 60, 60, 60,192,192,192,192,  0,  0,  0,  0,252,252,252,252,  0,  0,  0,  0,  0,  0,  0,  0,252,252,252,252},
    {255,255,255,255,  3,  3,  3,  3, 60, 60, 60, 60,255,255,255,255,  0,  0,  0,  0,255,255,255,255, 60, 60, 60, 60, 60, 60, 60, 60,255,255,255,255,  0,  0,  0,  0, 63, 63, 63, 63,192,192,192,192,192,192,192,192, 63, 63, 63, 63},
    {63, 63, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0, 63, 63, 63, 63,  0,  0,  0,  0, 63, 63, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0, 63, 63, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0, 63, 63, 63, 63, 63, 63, 63, 63,  0,  0,  0,  0}
};

static const char LAYER_SYM[3][56] PROGMEM = {
    {192,192,192,192, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,  0,  0,  0,  0,252,252,252,252,  0,  0,  0,  0,  0,  0,  0,  0,252,252,252,252,  0,  0,  0,  0,252,252,252,252,192,192,192,192,192,192,192,192,252,252,252,252},
    {3,  3,  3,  3, 60, 60, 60, 60, 60, 60, 60, 60,192,192,192,192,  0,  0,  0,  0,  3,  3,  3,  3, 60, 60, 60, 60,252,252,252,252,  3,  3,  3,  3,  0,  0,  0,  0,255,255,255,255, 63, 63, 63, 63, 63, 63, 63, 63,255,255,255,255},
    {60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,  3,  3,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 63, 63, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0, 63, 63, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0, 63, 63, 63, 63}
};

static const char LAYER_NUM[3][56] PROGMEM = {
    {252,252,252,252,192,192,192,192,  0,  0,  0,  0,252,252,252,252,  0,  0,  0,  0,252,252,252,252,  0,  0,  0,  0,  0,  0,  0,  0,252,252,252,252,  0,  0,  0,  0,252,252,252,252,  0,  0,  0,  0,  0,  0,  0,  0,252,252,252,252},
    {255,255,255,255,  3,  3,  3,  3, 60, 60, 60, 60,255,255,255,255,  0,  0,  0,  0,255,255,255,255,  0,  0,  0,  0,  0,  0,  0,  0,255,255,255,255,  0,  0,  0,  0,255,255,255,255, 63, 63, 63, 63, 63, 63, 63, 63,255,255,255,255},
    {63, 63, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0, 63, 63, 63, 63,  0,  0,  0,  0, 63, 63, 63, 63, 60, 60, 60, 60, 60, 60, 60, 60, 63, 63, 63, 63,  0,  0,  0,  0, 63, 63, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0, 63, 63, 63, 63}
};

/**
 * Clear the zone used by the layer display
 */
void oled_clear_layer(void) {
    oled_set_cursor(0, 0);
    oled_advance_page(true);
    oled_advance_page(true);
    oled_advance_page(true);
    oled_set_cursor(0, 0);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_clear_layer();
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _COLEMAK_DH:
                oled_write("    ", false);
                oled_write_raw_P(LAYER_BASE[0], 80);
                oled_advance_page(false);
                oled_write("    ", false);
                oled_write_raw_P(LAYER_BASE[1], 80);
                oled_advance_page(false);
                oled_write("    ", false);
                oled_write_raw_P(LAYER_BASE[2], 80);
                oled_advance_page(false);
                break;
            case _NAV:
                oled_write("      ", false);
                oled_write_raw_P(LAYER_NAV[0], 56);
                oled_advance_page(false);
                oled_write("      ", false);
                oled_write_raw_P(LAYER_NAV[1], 56);
                oled_advance_page(false);
                oled_write("      ", false);
                oled_write_raw_P(LAYER_NAV[2], 56);
                oled_advance_page(false);
                break;
            case _SYM:
                oled_write("      ", false);
                oled_write_raw_P(LAYER_SYM[0], 56);
                oled_advance_page(false);
                oled_write("      ", false);
                oled_write_raw_P(LAYER_SYM[1], 56);
                oled_advance_page(false);
                oled_write("      ", false);
                oled_write_raw_P(LAYER_SYM[2], 56);
                oled_advance_page(false);
                break;
            case _NUM:
                oled_write("      ", false);
                oled_write_raw_P(LAYER_NUM[0], 56);
                oled_advance_page(false);
                oled_write("      ", false);
                oled_write_raw_P(LAYER_NUM[1], 56);
                oled_advance_page(false);
                oled_write("      ", false);
                oled_write_raw_P(LAYER_NUM[2], 56);
                oled_advance_page(false);
                break;
            default:
                break;
        }

        oled_write_P(PSTR("Left: "), false);
        left_encoder_oled();

        oled_write_P(PSTR("Right: "), false);
        right_encoder_oled();

    } else {
        render_luna(0,1);
        oled_set_cursor(0,6);
        oled_write_P(PSTR("       WPM: "), false);
        oled_write(get_u8_str(get_current_wpm(), ' '), false);
    }
    return false;
}

