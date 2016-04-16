#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "constants.h"

const uint16_t PROGMEM fn_actions[] = {
  //[1] = ACTION_LAYER_TAP_KEY(SYMB, KC_B),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {

  case SWITCH_APP:
    if (record->event.pressed) {
      return MACRO(D(LALT), T(TAB), END);
    }
    break;

  case SWITCH_TAB:
    if (record->event.pressed) {
      return MACRO(D(LCTL), T(TAB), END);
    }
    break;

  case DQUOTE:
    if (record->event.pressed) {
      return MACRO(D(LSFT), T(QUOTE), U(LSFT), END);
    }
    break;

  case LESS:
    if (record->event.pressed) {
      return MACRO(D(LSFT), T(COMMA), U(LSFT), END);
    }
    break;

  case MORE:
    if (record->event.pressed) {
      return MACRO(D(LSFT), T(DOT), U(LSFT), END);
    }
    break;

  case QUESTION:
    if (record->event.pressed) {
      return MACRO(D(LSFT), T(SLASH), U(LSFT), END);
    }
    break;

  case PLUS:
    if (record->event.pressed) {
      return MACRO(D(LSFT), T(EQL), U(LSFT), END);
    }
    break;
  }

  return MACRO_NONE;
};
