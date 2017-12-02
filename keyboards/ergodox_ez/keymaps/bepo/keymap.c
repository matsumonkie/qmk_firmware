#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

// CONSTANTS

enum {
  BASE,
  EDIT,
  SYMB,
  MDIA,
  NUMB,
};

enum {
  SWITCH_APP,
  SWITCH_INNER_APP,
  SWITCH_TAB,
  SWITCH_PREVIOUS_TAB,
  SWITCH_BUFFER,
  SHIFT_TAB,
  TOGGLE_SYMB_LAYER,
  LESS,
  MORE,
  PLUS,
  QUESTION,
  DQUOTE, // "
  BEG_LINE,
  END_LINE,
};

// LAYOUTS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |  Esc   |   1  |   2  |   3  |   4  |   5  | Del  |           | Bspc |   6  |   7  |   8  |   9  |   0  |  Lock  |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |  CAPS  |   B  |   K  |   P  |   O  |   ,  | EDIT |           | SYMB |   Y  |   V  |   D  |   L  |   J  |NumLock |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |  EDIT  |   A  |   U  |   I  |   E  |   .  |------|           |------|   C  |   T  |   S  |   R  |   N  |  EDIT  |
   * |--------+------+------+------+------+------| MDIA |           | MDIA |------+------+------+------+------+--------|
   * |  SYMB  |Shift |   X  |   B  |   W  |   F  |      |           |      |   M  |   Q  |   G  |   H  |RShift|  SYMB  |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      | RCtl | LCtl | LGUI |                                       | RGUI | RCtl | RAlt |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        | App  | LGui |       | Alt  |C-Esc |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      | Home |       | PgUp |      |      |
   *                                 |Space | Cmd  |------|       |------| Cmd  |Enter |
   *                                 |      |      | End  |       | PgDn |      |      |
   *                                 `--------------------'       `--------------------'
   */
  [BASE] =
  KEYMAP(
         KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_DEL,
         KC_CAPS, KC_B, KC_K, KC_P, KC_O, KC_COMM, TG(EDIT),
         MO(EDIT), KC_A, KC_U, KC_I, KC_E, KC_DOT,
         MO(SYMB), KC_LSFT, KC_X, KC_Z, KC_W, KC_F, MO(MDIA),
         KC_DOT, KC_DOT, KC_LALT, KC_LCTL, KC_LGUI,
         ALT_T(KC_APP), KC_LGUI,
         KC_HOME,
         KC_ENT, KC_LGUI, KC_END,

         KC_BSPC, KC_6, KC_7, KC_8, KC_9, KC_0, HYPR(KC_L),
         TG(SYMB), KC_Y, KC_V, KC_D, KC_L, KC_J, TG(NUMB),
         KC_C, KC_T, KC_S, KC_R, KC_N, MO(EDIT),
         MO(MDIA), KC_M, KC_Q, KC_G, KC_H, KC_RSFT, MO(SYMB),
         KC_RGUI, KC_RCTL, KC_RALT, KC_DOT, KC_DOT,
         KC_LALT, CTL_T(KC_ESC),
         KC_PGUP,
         KC_PGDN, KC_RGUI, KC_SPC
         ),

  /*
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      | DW → | DW ← |C-tab |      |      |           |      |      |CS-Tab| Home | End  |      |   F12  |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      | DC → | DC ← |A-tab | Tab  |------|           |------|      |  ←   |  ↑   |  ↓   |   →  |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      | DL ← | DL ← |H-tab |      |      |           |      |      |      |  C ← | C →  |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |      |      |      |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 |  '   |      |------|       |------|      |  "   |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  [EDIT] =
  KEYMAP(
         KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS,
         KC_TRNS, KC_NO, LSFT(KC_HOME), LSFT(KC_END), M(SWITCH_TAB), KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS, KC_DELT, KC_BSPC, M(SWITCH_APP), KC_TAB,
         KC_TRNS, KC_TRNS, LCTL(KC_DEL), LCTL(KC_BSPC), M(SWITCH_INNER_APP), KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LALT,
         KC_TRNS, KC_TRNS,
         KC_TRNS,
         KC_QUOTE, KC_TRNS, KC_TRNS,

         KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
         KC_TRNS, KC_TRNS, M(SWITCH_PREVIOUS_TAB), M(BEG_LINE), M(END_LINE), KC_NO, KC_TRNS,
         M(SHIFT_TAB), KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS, LCTL(KC_LEFT), LCTL(KC_RIGHT), KC_TRNS, KC_TRNS,
         KC_RALT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS,
         KC_TRNS,
         KC_TRNS, KC_TRNS, M(DQUOTE)
         ),

  /*
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      |  ~   |  ;   |  #   |  %   |      |           |      |  `   |  =   |  [   |  ]   |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |  &   |  \   |   /  |  -   |  @   |------|           |------|  :   |  _   |  (   |  )   |  !   |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |  <   |   >  |  *   |  ?   |      |           |      |  $   |  ^   |  {   |  }   |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |      |      |      |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 |  +   |      |------|       |------|      |  |   |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  [SYMB] =
  KEYMAP(
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TILD, KC_SCOLON, KC_HASH, KC_PERC, KC_TRNS,
         KC_NO, KC_AMPR, KC_BSLASH, KC_SLASH, KC_MINS, KC_AT,
         KC_TRNS, KC_TRNS, M(LESS), M(MORE), KC_ASTR, M(QUESTION), KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS,
         KC_TRNS,
         M(PLUS), KC_TRNS, KC_TRNS,

         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_TRNS, KC_GRAVE, KC_EQL, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS,
         KC_COLN, KC_UNDS, KC_LPRN, KC_RPRN, KC_EXLM, KC_NO,
         KC_TRNS, KC_DLR, KC_CIRC,  KC_LCBR,  KC_RCBR, KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS,
         KC_TRNS,
         KC_TRNS, KC_TRNS, KC_PIPE
         ),

  /*
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |           |      |      |      |ImpScr|Power | Wake | Sleep  |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |Hyper1|Hyper2|Hyper3|Hyper4|Hyper5|      |           |      |      |      | Mute |PausePlay|   |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |Hyper6|Hyper7|Hyper8|Hyper9|Hyper0|------|           |------|      | Prev | Vol+ | Vol- | Next |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |      |      |      |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 |      |      |------|       |------|      |      |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  [MDIA] =
  KEYMAP(
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_TRNS, HYPR(KC_A), HYPR(KC_B), HYPR(KC_C), HYPR(KC_D), HYPR(KC_E), KC_TRNS,
         KC_TRNS, HYPR(KC_F), HYPR(KC_G), HYPR(KC_H), HYPR(KC_I), HYPR(KC_J),
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS,
         KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS,

         KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_POWER, KC_WAKE, KC_SYSTEM_SLEEP,
         KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_MPLY, KC_TRNS, KC_TRNS,
         KC_TRNS, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_TRNS,
         KC_TRNS, KC_AMPR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS,
         KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS
         ),

  /*
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |  1   |  2   |  3   |  4   |   5  |------|           |------|  6   |  7   |  8   |  9   |  0   |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |      |      |      |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 |      |      |------|       |------|      |      |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  [NUMB] =
  KEYMAP(
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5,
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS,
         KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS,

         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS,
         KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS
         ),

  /*
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |      |      |      |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 |      |      |------|       |------|      |      |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   * /
   [EMPTY] =
   KEYMAP(
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
   KC_TRNS, KC_TRNS,
   KC_TRNS,
   KC_TRNS, KC_TRNS, KC_TRNS,

   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
   KC_TRNS, KC_TRNS,
   KC_TRNS,
   KC_TRNS, KC_TRNS, KC_TRNS
   ),
  */

};

// MACROS

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {

  case SWITCH_APP:
    if (record->event.pressed) {
      return MACRO(D(LGUI), T(TAB), END);
    }
    break;

  case SWITCH_INNER_APP:
    if (record->event.pressed) {
      return MACRO(D(LGUI), T(GRV), END);
    }
    break;

  case SWITCH_TAB:
    if (record->event.pressed) {
      return MACRO(D(LCTL), T(TAB), END);
    }
    break;

  case SWITCH_PREVIOUS_TAB:
    if (record->event.pressed) {
      return MACRO(D(LCTL), D(LSFT), T(TAB), U(LSFT), U(LCTL), END);
    }
    break;

  case SHIFT_TAB:
    if (record->event.pressed) {
      return MACRO(D(LSFT), T(TAB), U(LSFT), END);
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

  case BEG_LINE:
    if (record->event.pressed) {
      return MACRO(D(LGUI), T(LEFT), U(LGUI), END);
    }
    break;

  case END_LINE:
    if (record->event.pressed) {
      return MACRO(D(LGUI), T(RIGHT), U(LGUI), END);
    }
    break;

  }

  return MACRO_NONE;
};

// run on start
void matrix_init_user(void) {
  for (int i = 0; i < 5; i++) {
    ergodox_blink_all_leds();
  }
};

// runs constantly in the background, in a loop.
void matrix_scan_user(void) {

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
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    break;

  default:
    break;
  }

  if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
    ergodox_right_led_1_on();
    ergodox_right_led_3_on();
  }

};
