#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _BASE = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  BASE = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST
};


// Layer Mode aliases
#define CTRLE CTL_T(KC_TAB)
#define KC_CENT LGUI(KC_ENT)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT( \
  //,---------------------------------------------.                 ,--------------------------------------------.
       KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,                      KC_F,    KC_G,    KC_C,    KC_R,    KC_L,\
  //|---------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------|
          KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                      KC_D,    KC_H,    KC_T,    KC_N,    KC_S,\
  //|---------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------|
       KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,                      KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,\
  //|---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
       KC_LSFT, KC_LALT,   CTRLE,   LOWER,  KC_SPC, KC_LGUI, KC_PSCR,  KC_ENT,   RAISE, KC_BSPC, KC_DOWN,   KC_UP \
  //|---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  ),

  [_LOWER] = LAYOUT(
  //,---------------------------------------------.                 ,--------------------------------------------.
         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,\
  //|---------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------|
          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,\
  //|---------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------|
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN,                   KC_RPRN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
       KC_LSFT, KC_LALT,   CTRLE,   LOWER,  KC_SPC, KC_LGUI, KC_PSCR, KC_CENT,   RAISE,  KC_DEL, KC_DOWN,   KC_UP \
  //|---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  ),

  [_RAISE] = LAYOUT(
  //,---------------------------------------------.                 ,--------------------------------------------.
       KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,\
  //|---------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------|
        KC_GRV, KC_BSLS,  KC_EQL, KC_SLSH,KC_MINUS,                   KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_UNDS,\
  //|---------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------|
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC,                   KC_RBRC, XXXXXXX, _______, _______, XXXXXXX,\
  //|---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
       KC_LSFT, KC_LALT,   CTRLE,   LOWER,  KC_SPC, KC_LGUI, KC_PSCR,  KC_ENT,   RAISE, KC_BSPC, KC_DOWN,   KC_UP \
  //|---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  ),

  [_ADJUST] = LAYOUT(
  //,---------------------------------------------.                 ,--------------------------------------------.
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|---------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------|
       XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2,                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,\
  //|---------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------|
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
       KC_LSFT, KC_LALT,   CTRLE,   LOWER,  KC_SPC, KC_LGUI, KC_PSCR,  KC_ENT,   RAISE,  KC_DEL, KC_DOWN,   KC_UP \
  //|---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  )
};

static bool lower_pressed = false;
static bool raise_pressed = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BASE:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_BASE);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        lower_pressed = true;
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        if (lower_pressed) { 
          register_code(KC_ESC);
          unregister_code(KC_ESC);
        }
        lower_pressed = false;
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        raise_pressed = true;
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        if (raise_pressed) { 
          register_code(KC_LCTL);
          register_code(KC_SPC);
          unregister_code(KC_SPC);
          unregister_code(KC_LCTL);
        }
        raise_pressed = false;
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
    default: // (3)
        if (record->event.pressed) {
            // reset the flag
            lower_pressed = false;
            raise_pressed = false;
        }
        break;
  }
  return true;
}
