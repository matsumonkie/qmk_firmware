#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "constants.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |  Esc   |   1  |   2  |   3  |   4  |   5  | Del  |           | Bspc |   6  |   7  |   8  |   9  |   0  |  Lock  |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |  Tab   |SYMB/B|   K  |   P  |   O  |   ,  | EDIT |           | SYMB |   Y  |   V  |   D  |   L  |SYMB/J|        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |  EDIT  |   A  |   U  |   I  |   E  |   .  |------|           |------|   C  |   T  |   S  |   R  |   N  |  EDIT  |
   * |--------+------+------+------+------+------| MDIA |           | MDIA |------+------+------+------+------+--------|
   * |  Caps  |Shift |   X  |   B  |   W  |   F  |      |           |      |   M  |   Q  |   G  |   H  |RShift|NumLock |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |AltShf| LAlt | LCtl |                                       | RCtl | LAlt |      |      |      |
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
         KC_TAB, KC_FN1, KC_K, KC_P, KC_O, KC_COMM, TG(EDIT),
         MO(EDIT), KC_A, KC_U, KC_I, KC_E, KC_DOT,
         KC_CAPS, KC_LSFT, KC_X, KC_Z, KC_W, KC_F, MO(MDIA),
         KC_DOT, KC_DOT, KC_DOT, KC_LALT, KC_LCTL,
         ALT_T(KC_APP), KC_LGUI,
         KC_HOME,
         KC_ENT, KC_LGUI, KC_END,

         KC_BSPC, KC_6, KC_7, KC_8, KC_9, KC_0, HYPR(KC_L),
         TG(SYMB), KC_Y, KC_V, KC_D, KC_L, KC_FN2, KC_TRNS,
         KC_C, KC_T, KC_S, KC_R, KC_N, MO(EDIT),
         MO(MDIA), KC_M, KC_Q, KC_G, KC_H, KC_RSFT, TG(NUMB),
         KC_RCTL, KC_RALT, KC_DOT, KC_DOT, KC_DOT,
         KC_LALT, CTL_T(KC_ESC),
         KC_PGUP,
         KC_PGDN, KC_RGUI, KC_SPC
         ),

  /*
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      | DW → | DW ← |C-tab |      |      |           |      |      |      | Home | End  |      |   F12  |
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
   *                                 |      |      |------|       |------|      |      |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  [EDIT] =
  KEYMAP(
         KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS,
         KC_TRNS, KC_NO, LSFT(KC_HOME), LSFT(KC_END), M(SWITCH_TAB), KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS, KC_DEL, KC_BSPC, M(SWITCH_APP), KC_TAB,
         KC_TRNS, KC_TRNS, LCTL(KC_DEL), LCTL(KC_BSPC), HYPR(KC_B), KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS,
         KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS,

         KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
         KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_END, KC_NO, KC_TRNS,
         KC_TRNS, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS, LCTL(KC_LEFT), LCTL(KC_RIGHT), KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS,
         KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS
         ),

  /*
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      |  ~   |  ;   |  #   |  %   |      |           |      |  `   | =/+  | [/{  | ]\}  |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |  &   |  \   |  /   |  '   |  @   |------|           |------|  :   | -/_  |  (   |  )   |  !   |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |  *   |      |      |      |      |           |      |  $   |  ^   |  <   |  >   |      |        |
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
  [SYMB] =
  KEYMAP(
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TILD, KC_SCOLON, KC_HASH, KC_PERC, KC_TRNS,
         KC_NO, KC_AMPR, KC_BSLASH, KC_SLASH, KC_QUOTE, KC_AT,
         KC_TRNS, KC_TRNS, KC_ASTR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS,
         KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS,

         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_TRNS, KC_GRAVE, KC_EQL, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS,
         KC_COLN, KC_MINS, KC_LPRN, KC_RPRN, KC_EXLM, KC_NO,
         KC_TRNS, KC_DLR, KC_CIRC, M(LESS), M(MORE), KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS,
         KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS
         ),

  /*
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |           |      |      |      |ImpScr|Power | Wake | Sleep  |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |Hyper1|Hyper2|Hyper3|Hyper4|      |      |           |      |      |      | Mute |PausePlay|   |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |Hyper5|Hyper6|Hyper7|Hyper8|      |------|           |------|      | Prev | Vol+ | Vol- | Next |        |
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
         KC_TRNS, HYPR(KC_1), HYPR(KC_2), HYPR(KC_3), HYPR(KC_4), KC_TRNS, KC_TRNS,
         KC_TRNS, HYPR(KC_5), HYPR(KC_6), HYPR(KC_7), HYPR(KC_8), KC_TRNS,
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
