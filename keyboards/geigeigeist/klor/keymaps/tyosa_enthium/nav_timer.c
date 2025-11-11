#include "nav_timer.h"

static uint16_t nav_timer = 0;
static bool is_nav_timer_on = false;

bool is_nav_timer_enabled(void) {
  return is_nav_timer_on;
}

void enable_nav_timer(void) {
  if (is_nav_timer_on) return;
  is_nav_timer_on = true;
  layer_on(_NAV);
}

void disable_nav_timer(void) {
  if (!is_nav_timer_on) return;
  is_nav_timer_on = false;
  layer_off(_NAV);  
}

void toggle_nav_timer(void) {
  if (is_nav_timer_on) {
    disable_nav_timer();
  } else {
    enable_nav_timer();
  }
}

bool should_terminate_nav_timer(uint16_t keycode, const keyrecord_t *record) {
  switch (keycode) {
    // Nav-related keys
    case KC_INS:
    case KC_DEL:
    case KC_LEFT:
    case KC_DOWN:
    case KC_UP:
    case KC_RIGHT:
    case KC_HOME:
    case KC_END:
    case KC_PGDN:
    case KC_PGUP:
    case ALT_TAB:
    // Ctl+ZXCV. Ignore Ctl+F as it's used to search some text so we want to go to BASE.
    case CTL_Z:
    case CTL_X:
    case CTL_C:
    case CTL_V:
      return false;
      
    default:
      return record->event.pressed;
  }
  return false; // Unreachable
}

bool process_record_nav_timer(uint16_t keycode, const keyrecord_t *record) {
  // If nothing happened for more than NAV_TIMER_MS, disable it
  if (is_nav_timer_on && timer_elapsed(nav_timer) > NAV_TIMER_MS) {
    disable_nav_timer();
    return true;
  }

  // Handle returning to the base layer with a combo on both thumbs
  if (keycode == BASE) {
    if (record->event.pressed) {
      disable_nav_timer();
      return false;
    }
  }

  // Handle the custom keycode that goes with this feature
  if (keycode == NAVTIMER) {
    if (record->event.pressed) {
      toggle_nav_timer();
      if (is_nav_timer_on) {
        nav_timer = timer_read();
        return false;
      }
    }
  }

  // Other than the custom keycodes, nothing else in this feature will
  // activate if the behavior is not on, so allow QMK to handle the
  // event as usual
  if (!is_nav_timer_on) return true;

  // Nothing else acts on key release, either
  if (!record->event.pressed) {
    return true;
  }

  // Get the base keycode of a mod or layer tap key
  switch (keycode) {
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
    case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
    case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
      // Earlier return if this has not been considered tapped yet
      if (record->tap.count == 0)
        return true;
      keycode = keycode & 0xFF;
      break;
    default:
      break;
  }

  if (should_terminate_nav_timer(keycode, record)) {
    disable_nav_timer();
  } else {
    nav_timer = timer_read();
  }
  return true;
}
