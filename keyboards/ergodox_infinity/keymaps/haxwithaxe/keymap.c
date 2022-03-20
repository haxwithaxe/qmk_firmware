#include QMK_KEYBOARD_H
//#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "common.h"


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [L0] = LAYOUT_ergodox(  // layer 0 : default
    /*
     * left hand
     *    +-------+-----+-----+-----+-----+-----+-----+
     *    |   =   |  0  |  2  |  3  |  4  |  5  | ESC |
     *    +-------+-----+-----+-----+-----+-----+-----+
     *    |   \   |  Q  |  W  |  E  |  R  |  T  |LCK-1|
     *    +-------+-----+-----+-----+-----+-----+     |
     *    |  TAB  |  A  |  S  |  D  |  F  |  G  +-----+
     *    +-------+-----+-----+-----+-----+-----+ f1  |
     *    |   `   |  Z  |  X  |  C  |  V  |  B  |     |
     *    +-+-----+-----+-----+-----+-----+-----+-----+
     *      |LGUI |     |     |     |FNAV |
     *      +-----+-----+-----+-----+-----+   +-----+------+
     *                                        |LCTRL| LALT |
     *                                  +-----+-----+------+
     *                                  |     |     | INS  |
     *                                  |BKSPC| DEL +------+
     *                                  |     |     |LSHIFT|
     *                                  +-----+-----+------+
     */
    KC_EQL,  KC_1,   KC_2,    KC_3,     KC_4,    KC_5,    KC_ESC,
    KC_BSLS, KC_Q,   KC_W,    KC_E,     KC_R,    KC_T,    TG(LTOP),
    KC_TAB,  KC_A,   KC_S,    KC_D,     KC_F,    KC_G,
    KC_GRV,  KC_Z,   KC_X,    KC_C,     KC_V,    KC_B,    MO(LTOP),
    KC_LGUI, KC_NO,  KC_NO,   KC_NO,    KC_NO,
                                                 KC_LCTL, KC_LALT,
                                                          KC_INS,
                                        KC_DEL,  KC_BSPC, KC_LSFT,
    /* right hand
     *        +-----+-----+-----+-----+-----+-----+-------+
     *        |LCK-2|  6  |  7  |  8  |  9  |  0  |   -   |
     *        +-----+-----+-----+-----+-----+-----+-------+
     *        |  [  |  Y  |  U  |  I  |  O  |  P  |   ]   |
     *        |     +-----+-----+-----+-----+-----+-------+
     *        +-----+  H  |  J  |  K  |  L  |  ;  |   '   |
     *        | f1  +-----+-----+-----+-----+-----+-------+
     *        |     |  N  |  M  |  ,  |  .  |  /  | RSHIFT|
     *        +-----+-----+-----+-----+-----+-----+-----+-+
     *                    |FNAV |     |LNUM |     | RGUI|
     *    +------+-----+  +-----+-----+-----+-----+-----+
     *    | RALT |RCTRL|
     *    +------+-----+-----+
     *    |RSHIFT|     |     |
     *    +------+ ENT | SPC |
     *    | FNAV |     |     |
     *    +------+-----+-----+
     */
    KC_LOCK,  KC_6,   KC_7,    KC_8,    KC_9,     KC_0,    KC_MINS,
    KC_LBRC,  KC_Y,   KC_U,    KC_I,    KC_O,     KC_P,    KC_RBRC,
              KC_H,   KC_J,    KC_K,    KC_L,     KC_SCLN, KC_QUOT,
    MO(LTOP), KC_N,   KC_M,    KC_COMM, KC_DOT,   KC_SLSH, KC_NO,
                      TG(LFN), KC_NO,   TG(LNUM), KC_NO,   KC_RGUI,
    KC_RSFT, KC_RCTL,
    KC_RALT,
    MO(LFN), KC_SPC,  KC_ENT
  ),

  [LMIRROR] = LAYOUT_ergodox(  // layer 1 : Mirror default layer
    /* left hand
     */
    KC_MINS, KC_0,    KC_9,     KC_8,    KC_7,    KC_6, KC_LOCK,
    KC_RBRC, KC_P,    KC_O,     KC_I,    KC_U,    KC_Y, KC_LBRC, 
    KC_QUOT, KC_SCLN, KC_L,     KC_K,    KC_J,    KC_H,
    KC_NO,   KC_SLSH, KC_DOT,   KC_COMM, KC_M,    KC_N, MO(LTOP),
    KC_RGUI, TG(LMIRROR),  TG(LNUM), KC_NO,   TG(LFN),
    									 KC_RCTL, KC_RSFT,
    										      KC_RALT,
                                KC_ENT,  KC_SPC,  MO(LFN),

    /*
     * right hand
     */
     KC_ESC,   KC_5,     KC_4,    KC_3,     KC_2,  KC_1,   KC_EQL,
     TG(LTOP), KC_T,     KC_R,    KC_E,     KC_W,  KC_Q,   KC_BSLS,
               KC_G,     KC_F,    KC_D,     KC_S,  KC_A,   KC_TAB, 
     MO(LTOP), KC_B,     KC_V,    KC_C,     KC_X,  KC_Z,   KC_GRV, 
   	                     TG(LFN), TG(LNUM), KC_NO, TG(LMIRROR), KC_LGUI, 
     KC_LALT,  KC_LCTL,
     KC_INS,
     KC_LSFT,  KC_BSPC, KC_DEL
  ),

  [LFN] = LAYOUT_ergodox( // layer 2 : Function/nav layer
     /* left hand
      *    +-------+-----+-----+-----+-----+-----+-----+
      *    |       | f1  | f2  | f3  | f4  | f5  | f11 |
      *    +-------+-----+-----+-----+-----+-----+-----+
      *    |       |     |     |     |     |     |     |
      *    +-------+-----+-----+-----+-----+-----+     |
      *    |       |     |Left | Up  |Down |Right+-----+
      *    +-------+-----+-----+-----+-----+-----+     |
      *    |       |     |Home |PgUp |PgDn | End |     |
      *    +-+-----+-----+-----+-----+-----+-----+-----+
      *      |     |     |     |     |     |
      *      +-----+-----+-----+-----+-----+   +-----+-----+
      *                                        |     |     |
      *                                  +-----+-----+-----+
      *                                  |     |     |     |
      *                                  |     |     +-----+
      *                                  |     |     |     |
      *                                  +-----+-----+-----+
      */
     KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_RGHT, KC_UP,   KC_DOWN, KC_LEFT,
     KC_TRNS, KC_TRNS, KC_END,  KC_PGUP, KC_PGDN, KC_HOME,  KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                  KC_TRNS, KC_TRNS,
                                                           KC_TRNS,
                                         KC_TRNS, KC_TRNS, KC_TRNS,
     /* right hand
      *        +-----+-----+-----+-----+-----+-----+-------+
      *        | f12 | f6  | f7  | f8  | f9  | f10 |       |
      *        +-----+-----+-----+-----+-----+-----+-------+
      *        |     |     |     |     |     |     |       |
      *        |     +-----+-----+-----+-----+-----+-------+
      *        +-----+Left |Down | Up  |Right|     |       |
      *        |     +-----+-----+-----+-----+-----+-------+
      *        |     |Home |PgDn |PgUp | End |     |       |
      *        +-----+-----+-----+-----+-----+-----+-----+-+
      *                    |     |     |     |     |     |
      *    +-----+-----+   +-----+-----+-----+-----+-----+
      *    |     |     |
      *    +-----+-----+-----+
      *    |     |     |     |
      *    +-----+     |     |
      *    |     |     |     |
      *    +-----+-----+-----+
      */
     KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
              KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS, KC_TRNS,
                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS,
     KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [LNUM] = LAYOUT_ergodox(
    /* Left hand
     *    +-------+-----+-----+-----+-----+-----+-----+
     *    | FLASH |     |     |     |     |     |     |
     *    +-------+-----+-----+-----+-----+-----+-----+
     *    |       |     |     |     |     |     |     |
     *    +-------+-----+-----+-----+-----+-----+     |
     *    |       |     |     |     |     |     +-----+
     *    +-------+-----+-----+-----+-----+-----+     |
     *    |       |     |     |     |     |     |     |
     *    +-+-----+-----+-----+-----+-----+-----+-----+
     *      |     |     |     |     |     |
     *      +-----+-----+-----+-----+-----+   +-----+-----+
     *                                        |     |     |
     *                                  +-----+-----+-----+
     *                                  |     |     |     |
     *                                  |     |     +-----+
     *                                  |     |     |     |
     *                                  +-----+-----+-----+
     */
    RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS,
                                                 KC_TRNS,
                               KC_TRNS, KC_TRNS, KC_TRNS,
    /* right hand
     *        +-----+-----+-----+-----+-----+-----+-------+
     *        |     |NMLCK| P/  | P*  | P-  |     | FLASH |
     *        +-----+-----+-----+-----+-----+-----+-------+
     *        |     | P7  | P8  | P9  | P+  |     |       |
     *        |     +-----+-----+-----+-----+-----+-------+
     *        +-----+ P4  | P5  | P6  | P+  |     |       |
     *        |     +-----+-----+-----+-----+-----+-------+
     *        |     | P1  | P2  | P3  |     |     |       |
     *        +-----+-----+-----+-----+-----+-----+-----+-+
     *                    | P0  | P.  |     |     |     |
     *    +-----+-----+   +-----+-----+-----+-----+-----+
     *    |     |     |
     *    +-----+-----+-----+
     *    |     |     |     |
     *    +-----+     |PENT |
     *    |     |     |     |
     *    +-----+-----+-----+
     */
    KC_TRNS, KC_TRNS, KC_SLASH, KC_ASTERISK, KC_MINUS, KC_TRNS, RESET,
    KC_TRNS, KC_7,    KC_8,     KC_9,        KC_PLUS,  KC_TRNS, KC_TRNS,
             KC_4,    KC_5,     KC_6,        KC_PLUS,  KC_TRNS, KC_TRNS,
    KC_TRNS, KC_1,    KC_2,     KC_3,        KC_TRNS,  KC_TRNS, KC_TRNS,
                      KC_0,     KC_DOT,      KC_TRNS,  KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_KP_ENTER
  ),

  [LSAFE] = LAYOUT_ergodox( // layer 9 : Gaming safe layer
     /* left hand
      *    +-------+-----+-----+-----+-----+-----+-----+
      *    |       |     |     |     |     |     |     |
      *    +-------+-----+-----+-----+-----+-----+-----+
      *    |       |     |     |     |     |     |     |
      *    +-------+-----+-----+-----+-----+-----+     |
      *    |       |     |     |     |     |     +-----+
      *    +-------+-----+-----+-----+-----+-----+     |
      *    |       |     |     |     |     |     |     |
      *    +-+-----+-----+-----+-----+-----+-----+-----+
      *      |     |     |NoOp |NoOp |LCTL |
      *      +-----+-----+-----+-----+-----+   +-----+-----+
      *                                        |     |     |
      *                                  +-----+-----+-----+
      *                                  |     |     |     |
      *                                  |     |     +-----+
      *                                  |     |     |     |
      *                                  +-----+-----+-----+
      */
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_LCTL,
                                                  KC_TRNS, KC_TRNS,
                                                           KC_TRNS,
                                         KC_TRNS, KC_TRNS, KC_TRNS,
     /* right hand
      *        +-----+-----+-----+-----+-----+-----+-------+
      *        |     |     |     |     |     |     |       |
      *        +-----+-----+-----+-----+-----+-----+-------+
      *        |     |     |     |     |     |     |       |
      *        |     +-----+-----+-----+-----+-----+-------+
      *        +-----+     |     |     |     |     |       |
      *        |     +-----+-----+-----+-----+-----+-------+
      *        |     |     |     |     |     |     |       |
      *        +-----+-----+-----+-----+-----+-----+-----+-+
      *                    |NoOp |NoOp |NoOp |     |     |
      *    +-----+-----+   +-----+-----+-----+-----+-----+
      *    |     |     |
      *    +-----+-----+-----+
      *    |     |     |     |
      *    +-----+     |     |
      *    |     |     |     |
      *    +-----+-----+-----+
      */
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                       KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_TRNS,
     KC_TRNS, KC_TRNS,
     KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [LTOP] = LAYOUT_ergodox( // Top layer : function layers
    /* left hand
     *    +-------+-----+-----+-----+-----+-----+-----+
     *    |LMIRROR| LFN |LNUM |LSAFE|     |LTOP |     |
     *    +-------+-----+-----+-----+-----+-----+-----+
     *    |       |     |     |     |     |     |     |
     *    +-------+-----+-----+-----+-----+-----+     |
     *    |       |     |     |     |     |     +-----+
     *    +-------+-----+-----+-----+-----+-----+     |
     *    |       |     |     |     |     |     |     |
     *    +-+-----+-----+-----+-----+-----+-----+-----+
     *      |     |     |     |     |     |
     *      +-----+-----+-----+-----+-----+   +-----+-----+
     *                                        |     |     |
     *                                  +-----+-----+-----+
     *                                  |     |     |     |
     *                                  |     |     +-----+
     *                                  |     |     |     |
     *                                  +-----+-----+-----+
     */
    TG(LMIRROR), TG(LFN),   TG(LNUM),   TG(LSAFE), KC_TRNS,   TG(LTOP), KC_TRNS,
    KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,
    KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,
    KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,
    KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,
                                                              KC_TRNS, KC_TRNS,
                                                                       KC_TRNS,
                                                   KC_TRNS,   KC_TRNS, KC_TRNS,
    /* right hand
     *        +-----+-----+-----+-----+-----+-----+-------+
     *        |     |LTOP |     |LSAFE|LNUM | LFN |LMIRROR|
     *        +-----+-----+-----+-----+-----+-----+-------+
     *        |     |     |     |     |     |     |       |
     *        |     +-----+-----+-----+-----+-----+-------+
     *        +-----+     |     |     |     |     |       |
     *        |     +-----+-----+-----+-----+-----+-------+
     *        |     |     |     |     |     |     |       |
     *        +-----+-----+-----+-----+-----+-----+-----+-+
     *                    |     |     |     |     |     |
     *    +-----+-----+   +-----+-----+-----+-----+-----+
     *    |     |     |
     *    +-----+-----+-----+
     *    |     |     |     |
     *    +-----+     |     |
     *    |     |     |     |
     *    +-----+-----+-----+
     */
    KC_TRNS, TG(LTOP),  KC_TRNS,    TG(LSAFE), TG(LNUM), TG(LFN),  TG(LMIRROR),
    KC_TRNS, KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,
             KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS, KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,
                        KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS,   KC_TRNS
  ),

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
    if (record->event.pressed) {
      SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
    }
    break;
    case 1:
    if (record->event.pressed) { // For resetting EEPROM
      eeconfig_init();
    }
    break;
  }
  return MACRO_NONE;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
    /*case STACK_XXX:
      if (record->event.pressed) {
        register_press(KC_XXX);
        register_press(KC_SPC);
        register_release(KC_XXX);
        register_release(KC_SPC);
      }
      return false;
      break;*/
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

}


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    // TODO: Make this relevant to the ErgoDox EZ.
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    default:
      // none
      break;
  }

}
