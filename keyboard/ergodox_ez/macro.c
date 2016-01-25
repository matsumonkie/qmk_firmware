#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "constants.h"

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
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

  case DELETE_END_LINE:
    if (record->event.pressed) {
      return MACRO(D(LSFT), T(END), U(LSFT), T(DEL), END);
    }
    break;

  case DELETE_BEG_LINE:
    if (record->event.pressed) {
      return MACRO(D(LSFT), T(HOME), U(LSFT), T(BSPC), END);
    }
    break;


  }

  return MACRO_NONE;
};
