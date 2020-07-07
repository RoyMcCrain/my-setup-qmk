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

#include QMK_KEYBOARD_H


enum planck_layers {
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  DVORAK = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  ENTC,
  CTRLE
};

// save cmd + s
#define KC_SAVE LGUI(KC_S)
#define UNDO LGUI(KC_Z)
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PSTE LGUI(KC_V)
// cmd + enter
#define KC_CENT LGUI(KC_ENT)
// cmd + h
#define KC_CH LGUI(KC_H)
// cmd + q
#define KC_CQ LGUI(KC_Q)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * |   "  |   ,  |   .  |   P  |   Y  |      |      |   F  |   G  |   C  |   R  |   L  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |   O  |   E  |   U  |   I  |      |      |   D  |   H  |   T  |   N  |   S  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ;  |   Q  |   J  |   K  |   X  |      |      |   B  |   M  |   W  |   V  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | GUI  | Alt  | Ctrl |Lower |Space |      |      | ENT  | Raise| BCSP |  SFT | Save |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_planck_grid(
    KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,   KC_TAB,  KC_BSPC,  KC_F,    KC_G,    KC_C,    KC_R,    KC_L,
    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,   KC_ESC,  KC_ESC,   KC_D,    KC_H,    KC_T,    KC_N,    KC_S,
    KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,   KC_LEFT, KC_RIGHT, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,
    KC_LGUI, KC_LALT, CTRLE,   LOWER,   KC_SPC, KC_SPC,  ENTC,     ENTC,    RAISE,   KC_BSPC, KC_RSFT, KC_SAVE
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |  F6  |  F7  |  F8  |  F9  | F10  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   1  |   2  |   3  |   4  |   5  |      |      |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | UNDO | CUT  | COPY | PSTE |   (  |      |      |   )  |cmd+h |cmd+q |   *  |   +  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |CMDENT|      | DEL  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,     KC_8,    KC_9,    KC_0,
    UNDO,    CUT,     COPY,    PSTE,    KC_LPRN, _______, _______, KC_RPRN, KC_CH,    KC_CQ,  KC_ASTR, KC_PLUS,
    _______, _______, _______, _______, _______, _______, KC_CENT, KC_CENT, _______,  KC_DEL,  _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |      |      |   ^  |   &  |   *  |   *  |  )   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   \  |   =  |   /  |   -  |      |      |  ←  |  ↓  |  ↑  |  →  |  _   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |   [  |      |      |   ]  | CMD  | CMD  | CMD  | CMD  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | TAB  |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_GRV,  KC_BSLS, KC_EQL,  KC_SLSH, KC_MINUS, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_UNDS,
    UNDO,    CUT,     COPY,    PSTE,    KC_LBRC,  _______, _______, KC_RBRC, KC_RGUI, KC_RGUI, KC_RGUI, KC_RGUI,
    _______, _______, _______, _______, KC_TAB,   KC_TAB,  _______, _______, _______, _______, _______, _______ 
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |       |      |      |      |      |      |      |      |      |      |      |      |
 * |-------+------+------+------+------+------+------+------+------+------+------+------|
 * |       |      |CLICK2|CLICK |      |      |      |  ←  |  ↓  |  ↑  |  →  |      |
 * |-------+------+------+------+------+------+------+------+------+------+------+------|
 * |       |      |      |      |      |      |      |      |      |      |      |      |
 * |-------+------+------+------+------+------+------+------+------+------+------+------|
 * |       |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_BTN2, KC_BTN1, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

static bool lower_pressed = false;
static uint16_t lower_pressed_time = 0;
static bool raise_pressed = false;
static uint16_t raise_pressed_time = 0;
static bool ctrl_pressed = false;
static uint16_t ctrl_pressed_time = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DVORAK:
      if (record->event.pressed) {
        default_layer_set(_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        lower_pressed = true;
        lower_pressed_time = record->event.time;
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        if (lower_pressed && (TIMER_DIFF_16(record->event.time, lower_pressed_time) < TAPPING_TERM)) { 
          register_code(KC_LANG2);
          unregister_code(KC_LANG2);
        }
        lower_pressed = false;
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        raise_pressed = true;
        raise_pressed_time = record->event.time;
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        if (raise_pressed && (TIMER_DIFF_16(record->event.time, raise_pressed_time) < TAPPING_TERM)) { 
          register_code(KC_LANG1);
          unregister_code(KC_LANG1);
        }
        raise_pressed = false;
      }
      return false;
      break;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;
    case ENTC:
        if (record->event.pressed) {
            ctrl_pressed = true;
            ctrl_pressed_time = record->event.time;
        } else {
          unregister_code(KC_LCTL);
          if (ctrl_pressed && (TIMER_DIFF_16(record->event.time, ctrl_pressed_time) < TAPPING_TERM)) { 
              tap_code(KC_ENT);
          }
          ctrl_pressed = false;
        }
        return false;
        break;
    case CTRLE:
        if (record->event.pressed) {
            ctrl_pressed = true;
            ctrl_pressed_time = record->event.time;
        } else {
          unregister_code(KC_LCTL);
          if (ctrl_pressed && (TIMER_DIFF_16(record->event.time, ctrl_pressed_time) < TAPPING_TERM)) { 
              tap_code(KC_ESC);
              tap_code(KC_LANG2);
          }
          ctrl_pressed = false;
        }
        return false;
        break;
    default:
        if (record->event.pressed) {
            if (ctrl_pressed) {
              register_code(KC_LCTL);
            } else {
              ctrl_pressed = false;
            }
            // reset the flag
            lower_pressed = false;
            raise_pressed = false;
        }
        break;
  }
  return true;
}
