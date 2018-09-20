// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

/* Use this setting with Karabiner Elements
 * https://github.com/oklahomer/dotfiles/blob/master/.config/karabiner/karabiner.json
 *
 * NOTE: Instead of using tap setting such as SFT_T(KC_ESC), use karabiner configuration.
 * Behavior differs slightly.
 * - Ergodox Hold: Press a key for a certain period of time to change input. Affected by TAPPING_TERM value.
 * - Karabiner: Change input when a key is pressed with another key.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   `    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   W  |   E  |   R  |   T  |LAlt+ |           |LGui+ |   Y  |   U  |   I  |   O  |   P  | BkSp   |
 * |--------+------+------+------+------+------| Space|           | Space|------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | Enter  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |  JP  |           |  EN  |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LALT |      |      |      |  L2  |                                       |  L1  |      |      |      | RALT |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,----------------.
 *                                        |      |      |       |        |       |
 *                                ,-------|------|------|       |--------+-------+-------.
 *                                |       |      |      |       |        |       |       |
 *                                | RShift| LGui |------|       |--------| RGui  | Space |
 *                                |       |      |      |       |        |       |       |
 *                                `---------------------'       `------------------------'
 *
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,   KC_1,  KC_2,   KC_3,    KC_4,     KC_5,    KC_NO,
        KC_TAB,   KC_Q,  KC_W,   KC_E,    KC_R,     KC_T,    LALT(KC_SPACE),
        KC_LCTRL, KC_A,  KC_S,   KC_D,    KC_F,     KC_G,
        KC_LSFT,  KC_Z,  KC_X,   KC_C,    KC_V,     KC_B,    KC_LANG1,
        KC_LALT,  KC_NO, KC_NO,  KC_NO,   MO(MDIA),
                                                    KC_NO,   KC_NO,
                                                             KC_NO,
                                          KC_RSFT,  KC_LGUI, KC_NO,
        // right hand
             KC_NO,          KC_6,    KC_7,         KC_8,    KC_9,    KC_0,    KC_GRV,
             LGUI(KC_SPACE), KC_Y,    KC_U,         KC_I,    KC_O,    KC_P,    KC_BSPACE,
                             KC_H,    KC_J,         KC_K,    KC_L,    KC_SCLN, KC_ENT,
             KC_LANG2,       KC_N,    KC_M,         KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                      MO(SYMB),     KC_NO,   KC_NO,   KC_NO,   KC_RALT,
             KC_NO,          KC_NO,
             KC_NO,
             KC_NO,          KC_RGUI, KC_SPACE
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |LGUI+F1 |   1  |   2  |   3  |   4  |   5  |      |           |      |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |  `   |   \  |   "  |      |      |           |      |      |   -  |  =   |  [   |  ]   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      | ESC  |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                        `---------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       M(0),        KC_NO,    KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,
       LGUI(KC_F1), KC_1,     KC_2,    KC_3,    KC_4,     KC_5,    KC_NO,
       KC_TRNS,     KC_NO, KC_GRV,  KC_BSLS, KC_QUOT,  KC_NO,
       KC_TRNS,     KC_NO,    KC_NO,   KC_ESC,  KC_NO,    KC_NO,   KC_NO,
       KC_TRNS,     KC_NO,    KC_NO,   KC_NO,   KC_NO,
                                                          KC_TRNS, KC_TRNS,
                                                                   KC_TRNS,
                                                KC_TRNS,  KC_TRNS, KC_TRNS,
       // right hand
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
       KC_NO,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
                KC_NO,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_TRNS,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,---------------------------------------------------.           ,---------------------------------------------------.
 * |        |  F1   |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |   F8   |  F9  |  F10 |        |
 * |--------+-------+------+------+------+-------------|           |------+------+------+--------+------+------+--------|
 * |        | VolDn | VolUp| Mute |      |      | Prev |           | Next |      | Lclk |  Rclk  |      |  F11 |        |
 * |--------+-------+------+------+------+------|      |           |      |------+------+--------+------+------+--------|
 * |        |       |      |      |      |      |------|           |------|MsLeft|MsDown|  MsUp  |MsRght|  F12 |  Play  |
 * |--------+-------+------+------+------+------|      |           |      |------+------+--------+------+------+--------|
 * |        |       |      |      |      |      |      |           |      |      |      |        |      |      |        |
 * `--------+-------+------+------+------+-------------'           `-------------+------+--------+------+------+--------'
 *   |Reset |       |      |      |      |                                       |      |        |      |      |      |
 *   `-----------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_NO, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_TRNS,
       KC_NO, KC_VOLD, KC_VOLU, KC_MUTE, KC_NO,   KC_NO,    KC_MPRV,
       KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,
       RESET, KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                                  KC_TRNS,  KC_TRNS,
                                                            KC_TRNS,
                                         KC_TRNS, KC_TRNS,  KC_TRNS,
    // right hand
       KC_NO,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_NO,
       KC_MNXT, KC_NO,   KC_BTN1, KC_BTN2, KC_NO,   KC_F11, KC_NO,
                KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_F12, KC_MPLY,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
                         KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
      }
      break;
  }
  return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    // TODO: Make this relevant to the ErgoDox EZ.
    case SYMB:
      ergodox_right_led_1_on();
      break;
    case MDIA:
      ergodox_right_led_2_on();
      break;
    default:
      // none
      break;
  }

};
