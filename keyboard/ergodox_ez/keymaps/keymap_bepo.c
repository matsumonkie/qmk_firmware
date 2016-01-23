#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "constants.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|   '    |
   * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
   * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
   *                                 ,------|------|------|       |------+--------+------.
   *                                 |      |      | Home |       | PgUp |        |      |
   *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
   *                                 |      |ace   | End  |       | PgDn |        |      |
   *                                 `--------------------'       `----------------------'
   */
  [BASE] = KEYMAP(
                  // left hand
                  KC_EQL, KC_1, KC_2, KC_3, KC_4, KC_5, KC_LEFT,
                  KC_DELT, MO(SYMB), KC_E, KC_P, KC_O, KC_COMM, KC_T,
                  MO(EDIT), KC_A, KC_U, KC_I, KC_E, KC_DOT,
                  KC_LSFT, KC_LSFT, KC_X, KC_C, KC_W, KC_F, ALL_T(KC_NO),
                  KC_QUOT, KC_QUOT, LALT(KC_LSFT), KC_LEFT,KC_RGHT,
                  ALT_T(KC_APP), KC_LGUI,
                  KC_HOME,
                  KC_SPC,KC_BSPC,KC_END,
                  // right hand
                  KC_RGHT, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
                  KC_Y, KC_Y, KC_V, KC_D, MO(SYMB), KC_J, KC_BSLS,
                  KC_C, KC_T, KC_S, KC_R, KC_N, MO(EDIT),
                  MEH_T(KC_NO), KC_N, KC_M, KC_COMM, KC_RSFT, KC_RSFT, CTL_T(KC_SLSH),
                  KC_UP, KC_DOWN, KC_LBRC, KC_RBRC, KC_FN1,
                  KC_LALT, CTL_T(KC_ESC),
                  KC_PGUP,
                  KC_PGDN,KC_TAB, KC_ENT
                  ),

  /*
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 |      |      |------|       |------|      |      |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  [EDIT] = KEYMAP(
                  // left hand
                  KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS,
                  KC_TRNS, KC_EXLM, LCTL(KC_DEL), LCTL(KC_BSPC), M(SWITCH_TAB), KC_PIPE, KC_TRNS,
                  KC_TRNS, KC_HASH, KC_DEL, KC_BSPC, M(SWITCH_APP), KC_BSPC,
                  KC_TRNS, KC_PERC, M(DELETE_END_LINE), M(DELETE_BEG_LINE), KC_RBRC,KC_TILD,KC_TRNS,
                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                  KC_TRNS, KC_TRNS,
                  KC_TRNS,
                  KC_TRNS, KC_TRNS, KC_TRNS,
                  // right hand
                  KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
                  KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_END, KC_TRNS, KC_TRNS,
                  KC_TRNS, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_TRNS,
                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                  KC_TRNS, KC_TRNS,
                  KC_TRNS,
                  KC_TRNS, KC_TRNS, KC_TRNS
                  ),

  /*
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 |      |      |------|       |------|      |      |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  [SYMB] = KEYMAP(
                  // left hand
                  KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
                  KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
                  KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
                  KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
                  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                  KC_TRNS,KC_TRNS,
                  KC_TRNS,
                  KC_TRNS,KC_TRNS,KC_TRNS,
                  // right hand
                  KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
                  KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                  KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
                  KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                  KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
                  KC_TRNS, KC_TRNS,
                  KC_TRNS,
                  KC_TRNS, KC_TRNS, KC_TRNS
                  ),

};

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
      return MACRO(D(LSFT), T(END), U(LSFT), T(BSPC), END);
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

// Runs just one time when the keyboard initializes.
void * matrix_init_user(void) {

  for (int i = 0; i < 5; i++) {
    ergodox_blink_all_leds();
  }
};

// Runs constantly in the background, in a loop.
void * matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  switch (layer) {
  case 1:
    ergodox_right_led_1_on();
    break;
  case 2:
    ergodox_right_led_2_on();
    break;
  default:
    break;
  }

};
