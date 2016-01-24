#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "constants.h"

// Runs constantly in the background, in a loop.
void * matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  switch (layer) {

  case EDIT:
    ergodox_right_led_1_on();
    break;

  case SYMB:
    ergodox_right_led_2_on();
    break;

  case MDIA:
    ergodox_right_led_3_on();
    break;

  case NUMB:
    ergodox_right_led_2_on();
    break;

  default:
    break;
  }

};
