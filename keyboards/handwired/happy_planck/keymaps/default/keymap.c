/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "happy_planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _COLEMAK,
  _QWERTY,
  _NUM_FUN,
  _WIN_FUN,
  _ALT_FUN,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  NUM_FUN,
  LOWER,
  RAISE,
  BACKLIT,
};

#define MY_ENT MT(MOD_RSFT, KC_ENT)
#define MY_ALT MT(MOD_LALT, KC_LCTL)

#define WIN_FUN MO(_WIN_FUN)
#define ALT_FUN MO(_ALT_FUN)

#define W_LEFT  LGUI(KC_LEFT)
#define W_RIGHT LGUI(KC_RIGHT)
#define W_DOWN  LGUI(KC_DOWN)
#define W_UP    LGUI(KC_UP)

#define CA_LEFT LCA(KC_LEFT)
#define CA_RGHT LCA(KC_RIGHT)
#define CA_DOWN LCA(KC_DOWN)
#define CA_UP   LCA(KC_UP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = LAYOUT_planck_grid(
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
  KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MY_ENT,
  _______, _______, WIN_FUN, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   MY_ALT,  ALT_FUN, _______, _______
),

[_QWERTY] = LAYOUT_planck_grid(
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MY_ENT ,
  _______, _______, WIN_FUN, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   MY_ALT,  ALT_FUN, _______, _______
),

[_NUM_FUN] = LAYOUT_planck_grid(
  _______, KC_7   , KC_8   , KC_9   , XXXXXXX, XXXXXXX, XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______,
  _______, KC_4   , KC_5   , KC_6   , XXXXXXX, XXXXXXX, XXXXXXX, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______,
  _______, KC_1   , KC_2   , KC_3   , XXXXXXX, XXXXXXX, XXXXXXX, KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,
  _______, _______, KC_0   , _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_WIN_FUN] = LAYOUT_planck_grid(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, XXXXXXX, W_LEFT , W_UP   , W_RIGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, XXXXXXX, XXXXXXX, W_DOWN , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_ALT_FUN] = LAYOUT_planck_grid(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, XXXXXXX, CA_LEFT, CA_UP  , CA_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, XXXXXXX, XXXXXXX, CA_DOWN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_LOWER] = LAYOUT_planck_grid(
  KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR   , KC_ASTR   , KC_LPRN, KC_RPRN, KC_DEL ,
  _______, XXXXXXX, KC_HOME, KC_PGUP, KC_END , XXXXXXX, XXXXXXX, KC_UNDS   , KC_PLUS   , KC_LCBR, KC_RCBR, KC_PIPE,
  _______, XXXXXXX, KC_VOLD, KC_PGDN, KC_VOLU, KC_MUTE, XXXXXXX, S(KC_NUHS), S(KC_NUBS), KC_QUOT, KC_PIPE , _______,
  _______, _______, _______, _______, _______, KC_ESC , KC_ESC , _______   , _______   , KC_VOLD, KC_VOLU, KC_MPLY
),

[_RAISE] = LAYOUT_planck_grid(
  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL ,
  _______, XXXXXXX, KC_LEFT, KC_UP  , KC_RGHT, XXXXXXX, XXXXXXX, KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, KC_BSLS,
  _______, XXXXXXX, XXXXXXX, KC_DOWN, XXXXXXX, XXXXXXX, XXXXXXX, KC_NUHS, KC_NUBS, S(KC_QUOT), KC_BSLS, _______,
  _______, _______, _______, _______, _______, KC_BSPC, KC_BSPC, _______, _______, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise) */
[_ADJUST] = LAYOUT_planck_grid(
  _______, RESET  , DEBUG  , _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
  _______, _______, MU_MOD , AU_ON  , AU_OFF , AG_NORM, AG_SWAP, QWERTY , COLEMAK, NUM_FUN, _______, _______,
  _______, MUV_DE , MUV_IN , MU_ON  , MU_OFF , MI_ON  , MI_OFF , _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case NUM_FUN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_NUM_FUN);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
  }
  return true;
}
