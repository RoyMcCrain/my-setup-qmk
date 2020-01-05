#include QMK_KEYBOARD_H 
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.  Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _RAISE 1
#define _LOWER 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  RAISE,
  LOWER,
};

// Shortcut to make keymap more readable
#define LOWER2 LT(_LOWER, KC_LANG2)
#define RAISE2 LT(_RAISE, KC_LANG1)

// save cmd + s
#define KC_SAVE LGUI(KC_S)
// save cmd + z
#define KC_UNDO LGUI(KC_Z)
// save cmd + x
#define KC_CUT LGUI(KC_X)
// save cmd + c
#define KC_COPY LGUI(KC_C)
// save cmd + v
#define KC_PASTE LGUI(KC_V)
// cmd + enter
#define KC_CENT LGUI(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌--------┬--------┬--------┬--------┬--------┬--------┐                                                ┌--------┬--------┬--------┬--------┬--------┬--------┐
     XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,                                                  XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,
  //├--------┼--------┼--------┼--------┼--------┼--------┼--------┐                            ┌--------┼--------┼--------┼--------┼--------┼--------┼--------┤
     KC_LALT  ,KC_Q     ,KC_W     ,KC_E     ,KC_R     ,KC_T     ,XXXXXXX  ,                              XXXXXXX  ,KC_Y     ,KC_U     ,KC_I     ,KC_O     ,KC_P     ,KC_ESC   ,
  //├--------┼--------┼--------┼--------┼--------┼--------┼--------┤                            ├--------┼--------┼--------┼--------┼--------┼--------┼--------┤
     KC_LGUI  ,KC_A     ,KC_S     ,KC_D     ,KC_F     ,KC_G     ,KC_LBRC  ,                              KC_RBRC  ,KC_H     ,KC_J     ,KC_K     ,KC_L     ,KC_SCLN  ,KC_SAVE  ,
  //├--------┼--------┼--------┼--------┼--------┼--------┼--------┼--------┐        ┌--------┼--------┼--------┼--------┼--------┼--------┼--------┼--------┤
     KC_LSFT  ,KC_Z     ,KC_X     ,KC_C     ,KC_V     ,KC_B     ,XXXXXXX  ,XXXXXXX  ,          XXXXXXX  ,XXXXXXX  ,KC_N     ,KC_M     ,KC_COMM  ,KC_DOT   ,KC_SLSH  ,KC_RSFT  ,
  //├--------┼--------┼--------┼--------┼----┬--┴----┬--┼--------┼--------┤        ├--------┼--------┼---┬----┴--┬---┼--------┼--------┼--------┼--------┤
     KC_LGUI  ,XXXXXXX  ,XXXXXXX  ,KC_BSPC  ,      LOWER2   ,    KC_SPC   ,XXXXXXX  ,          XXXXXXX  ,KC_ENT   ,     RAISE2   ,     KC_RCTL  ,KC_DOWN  ,KC_UP    ,KC_SAVE 
  //└--------┴--------┴--------┴--------┘    └--------┘  └--------┴--------┘        └--------┴--------┘   └--------┘   └--------┴--------┴--------┴--------┘
  ),

  [_LOWER] = LAYOUT(
  //┌--------┬--------┬--------┬--------┬--------┬--------┐                                                ┌--------┬--------┬--------┬--------┬--------┬--------┐
     XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,                                                  XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,
  //├--------┼--------┼--------┼--------┼--------┼--------┼--------┐                            ┌--------┼--------┼--------┼--------┼--------┼--------┼--------┤
     _______  ,KC_F1    ,KC_F2    ,KC_F3    ,KC_F4    ,KC_F5    ,XXXXXXX  ,                              XXXXXXX  ,KC_F6    ,KC_F7    ,KC_F8    ,KC_F9    ,KC_F10   ,_______  ,
  //├--------┼--------┼--------┼--------┼--------┼--------┼--------┤                            ├--------┼--------┼--------┼--------┼--------┼--------┼--------┤
     _______  ,KC_1     ,KC_2     ,KC_3     ,KC_4     ,KC_5     ,KC_LBRC  ,                              KC_RBRC  ,KC_6     ,KC_7     ,KC_8     ,KC_9     ,KC_0     ,_______  ,
  //├--------┼--------┼--------┼--------┼--------┼--------┼--------┼--------┐        ┌--------┼--------┼--------┼--------┼--------┼--------┼--------┼--------┤
     _______  ,KC_UNDO  ,KC_CUT   ,KC_COPY  ,KC_PASTE ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,          XXXXXXX  ,XXXXXXX  ,KC_LEFT  ,KC_DOWN  ,KC_UP    ,KC_RIGHT ,XXXXXXX  ,_______  ,
  //├--------┼--------┼--------┼--------┼----┬--┴----┬--┼--------┼--------┤        ├--------┼--------┼---┬----┴--┬---┼--------┼--------┼--------┼--------┤
     _______  ,XXXXXXX  ,XXXXXXX  ,KC_BSPC  ,      LOWER2   ,    KC_SPC   ,XXXXXXX  ,          XXXXXXX  ,KC_CENT  ,     RAISE2   ,     KC_RCTL  ,KC_DOWN  ,KC_UP    ,KC_SAVE 
  //└--------┴--------┴--------┴--------┘    └--------┘  └--------┴--------┘        └--------┴--------┘   └--------┘   └--------┴--------┴--------┴--------┘
  ),

  [_RAISE] = LAYOUT(
  //┌--------┬--------┬--------┬--------┬--------┬--------┐                                                ┌--------┬--------┬--------┬--------┬--------┬--------┐
     XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,                                                  XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,
  //├--------┼--------┼--------┼--------┼--------┼--------┼--------┐                            ┌--------┼--------┼--------┼--------┼--------┼--------┼--------┤
     _______  ,KC_EXLM  ,KC_AT    ,KC_HASH  ,KC_DLR   ,KC_PERC  ,XXXXXXX  ,                              XXXXXXX  ,KC_CIRC  ,KC_AMPR  ,KC_ASTR  ,XXXXXXX  ,XXXXXXX  ,_______  ,
  //├--------┼--------┼--------┼--------┼--------┼--------┼--------┤                            ├--------┼--------┼--------┼--------┼--------┼--------┼--------┤
     _______  ,KC_GRV   ,KC_BSLS  ,KC_EQL   ,KC_QUOT  ,KC_MINUS ,KC_LPRN  ,                              KC_RPRN  ,KC_LEFT  ,KC_DOWN  ,KC_UP    ,KC_RIGHT ,KC_UNDS  ,_______  ,
  //├--------┼--------┼--------┼--------┼--------┼--------┼--------┼--------┐        ┌--------┼--------┼--------┼--------┼--------┼--------┼--------┼--------┤
     _______  ,KC_UNDO  ,KC_CUT   ,KC_COPY  ,KC_PASTE ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,          XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,_______  ,
  //├--------┼--------┼--------┼--------┼----┬--┴----┬--┼--------┼--------┤        ├--------┼--------┼---┬----┴--┬---┼--------┼--------┼--------┼--------┤
     _______  ,XXXXXXX  ,XXXXXXX  ,KC_DEL   ,      LOWER2   ,    KC_TAB   ,XXXXXXX  ,          XXXXXXX  ,KC_ENT   ,     RAISE2   ,     KC_RCTL  ,KC_DOWN  ,KC_UP    ,KC_SAVE 
  //└--------┴--------┴--------┴--------┘    └--------┘  └--------┴--------┘        └--------┴--------┘   └--------┘   └--------┴--------┴--------┴--------┘
  ),
};
