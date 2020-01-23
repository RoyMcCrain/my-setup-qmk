#include QMK_KEYBOARD_H 
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.  Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DVORAK 0
#define _RAISE 1
#define _LOWER 2

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  RAISE,
  LOWER,
};

// Shortcut to make keymap more readable
#define LOWER2 LT(_LOWER, KC_LANG1)
#define RAISE2 LT(_RAISE, KC_LANG2)
#define CTRLE CTL_T(KC_ESC)

// save cmd + s
#define KC_SAVE LGUI(KC_S)
#define UNDO LGUI(KC_Z)
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)
// cmd + enter
#define KC_CENT LGUI(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = LAYOUT(
  //┌--------┬--------┬--------┬--------┬--------┬--------┐                                                ┌--------┬--------┬--------┬--------┬--------┬--------┐
     XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,                                                  XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,
  //├--------┼--------┼--------┼--------┼--------┼--------┼--------┐                            ┌--------┼--------┼--------┼--------┼--------┼--------┼--------┤
     KC_TAB   ,KC_QUOT  ,KC_COMM  ,KC_DOT   ,KC_P     ,KC_Y     ,XXXXXXX  ,                              XXXXXXX  ,KC_F     ,KC_G     ,KC_C     ,KC_R     ,KC_L     ,KC_RALT   ,
  //├--------┼--------┼--------┼--------┼--------┼--------┼--------┤                            ├--------┼--------┼--------┼--------┼--------┼--------┼--------┤
     KC_LGUI  ,KC_A     ,KC_O     ,KC_E     ,KC_U     ,KC_I     ,XXXXXXX  ,                              XXXXXXX  ,KC_D     ,KC_H     ,KC_T     ,KC_N     ,KC_S     ,KC_SAVE  ,
  //├--------┼--------┼--------┼--------┼--------┼--------┼--------┼--------┐        ┌--------┼--------┼--------┼--------┼--------┼--------┼--------┼--------┤
     KC_LSFT  ,KC_SCLN  ,KC_Q     ,KC_J     ,KC_K     ,KC_X     ,XXXXXXX  ,XXXXXXX  ,          XXXXXXX  ,XXXXXXX  ,KC_B     ,KC_M     ,KC_W     ,KC_V     ,KC_Z     ,KC_RSFT  ,
  //├--------┼--------┼--------┼--------┼----┬--┴----┬--┼--------┼--------┤        ├--------┼--------┼---┬----┴--┬---┼--------┼--------┼--------┼--------┤
     KC_LGUI  ,XXXXXXX  ,XXXXXXX  ,CTRLE    ,      LOWER2   ,    KC_SPC   ,XXXXXXX  ,          XXXXXXX  ,KC_ENT   ,     RAISE2   ,     KC_BSPC  ,KC_DOWN  ,KC_UP    ,KC_SAVE 
  //└--------┴--------┴--------┴--------┘    └--------┘  └--------┴--------┘        └--------┴--------┘   └--------┘   └--------┴--------┴--------┴--------┘
  ),

  [_LOWER] = LAYOUT(
  //┌--------┬--------┬--------┬--------┬--------┬--------┐                                                ┌--------┬--------┬--------┬--------┬--------┬--------┐
     XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,                                                  XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,
  //├--------┼--------┼--------┼--------┼--------┼--------┼--------┐                            ┌--------┼--------┼--------┼--------┼--------┼--------┼--------┤
     _______  ,KC_F1    ,KC_F2    ,KC_F3    ,KC_F4    ,KC_F5    ,XXXXXXX  ,                              XXXXXXX  ,KC_F6    ,KC_F7    ,KC_F8    ,KC_F9    ,KC_F10   ,_______  ,
  //├--------┼--------┼--------┼--------┼--------┼--------┼--------┤                            ├--------┼--------┼--------┼--------┼--------┼--------┼--------┤
     _______  ,KC_1     ,KC_2     ,KC_3     ,KC_4     ,KC_5     ,XXXXXXX  ,                              XXXXXXX  ,KC_6     ,KC_7     ,KC_8     ,KC_9     ,KC_0     ,_______  ,
  //├--------┼--------┼--------┼--------┼--------┼--------┼--------┼--------┐        ┌--------┼--------┼--------┼--------┼--------┼--------┼--------┼--------┤
     _______  ,   UNDO  ,   CUT   ,   COPY  ,   PASTE ,KC_LBRC  ,XXXXXXX  ,XXXXXXX  ,          XXXXXXX  ,XXXXXXX  ,KC_RBRC  ,XXXXXXX  ,_______  ,_______  ,XXXXXXX  ,XXXXXXX  ,
  //├--------┼--------┼--------┼--------┼----┬--┴----┬--┼--------┼--------┤        ├--------┼--------┼---┬----┴--┬---┼--------┼--------┼--------┼--------┤
     _______  ,XXXXXXX  ,XXXXXXX  ,CTRLE    ,      LOWER2   ,    KC_SPC   ,XXXXXXX  ,          XXXXXXX  ,KC_CENT  ,     RAISE2   ,     KC_DEL   ,KC_DOWN  ,KC_UP    ,KC_SAVE 
  //└--------┴--------┴--------┴--------┘    └--------┘  └--------┴--------┘        └--------┴--------┘   └--------┘   └--------┴--------┴--------┴--------┘
  ),

  [_RAISE] = LAYOUT(
  //┌--------┬--------┬--------┬--------┬--------┬--------┐                                                ┌--------┬--------┬--------┬--------┬--------┬--------┐
     XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,                                                  XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,
  //├--------┼--------┼--------┼--------┼--------┼--------┼--------┐                            ┌--------┼--------┼--------┼--------┼--------┼--------┼--------┤
     _______  ,KC_EXLM  ,KC_AT    ,KC_HASH  ,KC_DLR   ,KC_PERC  ,XXXXXXX  ,                              XXXXXXX  ,KC_CIRC  ,KC_AMPR  ,KC_ASTR  ,XXXXXXX  ,XXXXXXX  ,_______  ,
  //├--------┼--------┼--------┼--------┼--------┼--------┼--------┤                            ├--------┼--------┼--------┼--------┼--------┼--------┼--------┤
     _______  ,KC_GRV   ,KC_BSLS  ,KC_EQL   ,KC_SLSH  ,KC_MINUS ,XXXXXXX  ,                              XXXXXXX  ,KC_LEFT  ,KC_DOWN  ,KC_UP    ,KC_RIGHT ,KC_UNDS  ,_______  ,
  //├--------┼--------┼--------┼--------┼--------┼--------┼--------┼--------┐        ┌--------┼--------┼--------┼--------┼--------┼--------┼--------┼--------┤
     _______  ,   UNDO  ,   CUT   ,   COPY  ,   PASTE ,KC_LPRN  ,XXXXXXX  ,XXXXXXX  ,          XXXXXXX  ,XXXXXXX  ,KC_RPRN  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,_______  ,
  //├--------┼--------┼--------┼--------┼----┬--┴----┬--┼--------┼--------┤        ├--------┼--------┼---┬----┴--┬---┼--------┼--------┼--------┼--------┤
     _______  ,XXXXXXX  ,XXXXXXX  ,CTRLE    ,      LOWER2   ,    KC_TAB   ,XXXXXXX  ,          XXXXXXX  ,KC_ENT   ,     RAISE2   ,     KC_BSPC  ,KC_DOWN  ,KC_UP    ,KC_SAVE 
  //└--------┴--------┴--------┴--------┘    └--------┘  └--------┴--------┘        └--------┴--------┘   └--------┘   └--------┴--------┴--------┴--------┘
  ),
};
