#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "constants.h"

// Runs just one time when the keyboard initializes.
void * matrix_init_user(void) {

  for (int i = 0; i < 5; i++) {
    ergodox_blink_all_leds();
  }
};
