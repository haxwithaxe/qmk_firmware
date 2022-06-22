#include QMK_KEYBOARD_H
#include "version.h"

/*
 *
 * MIRROR WORLD!
 * This is a mirror image of the haxwithaxe keymap
 *
 *
 */

#define CTL_ESC CTL_T(KC_ESC)
#define NUM_BSPC LT(MNUM, KC_BSPC)
#define NUM_SPC LT(MNUM, KC_SPC)
#define SYM_DEL LT(MSYM, KC_DEL)
#define SYM_ENT LT(MSYM, KC_ENT)

enum custom_layers {
    M0,      // Base layer
    MMIRROR, // Mirror layer for flash derps
    MSYM,    // Symbols and nav layer
    MNUM,    // Numbers and F keys layer
    MGAM,    // Gaming layer (NoOp)
    MUTIL,    // Media/nav layer
    MTOP     // Top control and lock keys layer
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  VRSN,
  RGB_SLD
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [M0] = LAYOUT_ergodox(  // layer 0 : default
    /*
     * left hand
     *    +-------+-----+-----+-----+-----+-----+-----+
     *    |       |     |     |     |     |     | TOP |
     *    +-------+-----+-----+-----+-----+-----+-----+
     *    |CTL/ESC|  Q  |  W  |  E  |  R  |  T  |     |
     *    +-------+-----+-----+-----+-----+-----+     |
     *    |  TAB  |  A  |  S  |  D  |  F  |  G  +-----+
     *    +-------+-----+-----+-----+-----+-----+     |
     *    |       |  Z  |  X  |  C  |  V  |  B  |     |
     *    +-+-----+-----+-----+-----+-----+-----+-----+
     *      |LGUI | RT  | DN  | UP  | LT  |
     *      +-----+-----+-----+-----+-----+   +-----+------+
     *                                        |LCTRL| LALT |
     *                                  +-----+-----+------+
     *                                  | NUM |SYM  | INS  |
     *                                  | DEL |BSPC +------+
     *                                  |     |     |LSHIFT|
     *                                  +-----+-----+------+
     */
    KC_NO, KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   TG(MTOP),
    KC_NO, KC_P,    KC_O,    KC_I,     KC_U,    KC_Y,    KC_QUOT,
    KC_NO, KC_SCLN, KC_L,    KC_K,     KC_J,    KC_H,
    KC_NO, KC_SLSH, KC_DOT,  KC_COMM,  KC_M,    KC_N,    KC_MINS,
    KC_NO, KC_NO,   KC_NO,   KC_NO,    KC_NO,
                                                KC_RCTL, KC_RSFT,
                                                         KC_RALT,
                                       SYM_ENT, NUM_SPC, MO(MUTIL),
    /* right hand
     *        +-----+-----+-----+-----+-----+-----+-------+
     *        | TOP|      |     |     |     |     |       |
     *        +-----+-----+-----+-----+-----+-----+-------+
     *        |     |  Y  |  U  |  I  |  O  |  P  |       |
     *        |     +-----+-----+-----+-----+-----+-------+
     *        +-----+  H  |  J  |  K  |  L  |  ;  | ENT   |
     *        |     +-----+-----+-----+-----+-----+-------+
     *        |     |  N  |  M  |  ,  |  .  |  /  |       |
     *        +-----+-----+-----+-----+-----+-----+-----+-+
     *                    |     |     |     |     | RGUI|
     *    +------+-----+  +-----+-----+-----+-----+-----+
     *    | RALT |RCTRL|
     *    +------+-----+-----+
     *    |RSHIFT| SYM | NUM |
     *    +------+ SPC | ENT |
     *    | FNAV |     |     |
     *    +------+-----+-----+
     */
    TG(MTOP), KC_NO,  KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,
    CTL_ESC,  KC_T,   KC_R,    KC_E,    KC_W,     KC_Q,    KC_NO,
              KC_G,   KC_F,    KC_D,    KC_S,     KC_A,    KC_NO,
    KC_TAB,   KC_B,   KC_V,    KC_C,    KC_X,     KC_Z,    KC_NO,
                      KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,
    KC_LCTL, KC_LALT,
    KC_INS,
    KC_LSFT, NUM_BSPC,  SYM_DEL
  ),

  [MMIRROR] = LAYOUT_ergodox(  // layer 1 : Mirror default layer
    // Keeping normal qwerty because other layers aren't mirrored
    /* left hand
     */
    KC_EQL,  KC_1,    KC_2,    KC_3,  KC_4,    KC_5, KC_ESC,
    KC_BSLS, KC_Q,    KC_W,    KC_E,  KC_R,    KC_T, KC_NO, 
    KC_TAB,  KC_A,    KC_S,    KC_D,  KC_F,    KC_G,
    KC_ENT,  KC_Z,    KC_X,    KC_C,  KC_V,    KC_B, MO(MTOP),
    KC_RGUI, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
    								           KC_LCTL, KC_LALT,
    										            KC_INS,
                                      KC_DEL,  KC_BSPC, KC_LSFT,

    /*
     * right hand
     */
     KC_NO,    KC_6,     KC_7,    KC_8,     KC_9,  KC_0,    KC_MINS,
     KC_LBRC,  KC_Y,     KC_U,    KC_I,     KC_O,  KC_P,    KC_RBRC,
               KC_H,     KC_J,    KC_K,     KC_L,  KC_SCLN, KC_QUOT, 
     MO(MTOP), KC_N,     KC_M,    KC_COMM,  KC_DOT,KC_SLSH, KC_NO, 
   	                     KC_LEFT, KC_DOWN,  KC_UP, KC_RGHT, KC_LGUI, 
     KC_RSFT,  KC_RCTL,
     KC_RALT,
     MO(MSYM),  KC_SPC, KC_ENT
  ),
  
  /* MIRRORED!! */
  [MSYM] = LAYOUT_ergodox( // layer 9 : Left symbol layer
     /* left hand
      *    +-------+-----+-----+-----+-----+-----+-----+
      *    |       |     |     |     |     |     | TOP |
      *    +-------+-----+-----+-----+-----+-----+-----+
      *    |       |  !  |  @  |  #  |  $  |  %  | SYM |
      *    +-------+-----+-----+-----+-----+-----+     |
      *    |       |  =  |  [  |  {  |  }  |  ]  +-----+
      *    +-------+-----+-----+-----+-----+-----+ NUM |
      *    |       |  +  |  ~  |  `  |  |  |  \  |     |
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
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(MTOP),
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(MSYM),
     KC_TRNS, KC_RPRN, KC_LPRN, KC_ASTR, KC_AMPR, KC_CIRC,
     KC_TRNS, KC_TRNS, KC_GT,   KC_UNDS, KC_MINS, KC_LT,   TG(MNUM),
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                  KC_TRNS, KC_TRNS,
                                                           KC_TRNS,
                                         KC_TRNS, KC_TRNS, KC_TRNS,
     /* right hand
      *        +-----+-----+-----+-----+-----+-----+-------+
      *        | TOP |     |     |     |     |     |       |
      *        +-----+-----+-----+-----+-----+-----+-------+
      *        | SYM |     |     |     |     |     |       |
      *        |     +-----+-----+-----+-----+-----+-------+
      *        +-----+  ^  |  &  |  *  |  (  |  )  |       |
      *        | NUM +-----+-----+-----+-----+-----+-------+
      *        |     |  <  |  -  |  _  |  >  |     |       |
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
     TG(MTOP),KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     TG(MSYM),KC_RBRC, KC_RCBR, KC_LCBR, KC_LBRC, KC_EQL,  KC_TRNS,
              KC_PERC, KC_DLR,  KC_HASH, KC_AT,   KC_EXLM, KC_TRNS,
     TG(MNUM),KC_BSLS, KC_PIPE, KC_GRV,  KC_TILD, KC_PLUS, KC_TRNS,
                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS,
     KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [MNUM] = LAYOUT_ergodox(
    /* Left hand
     *    +-------+-----+-----+-----+-----+-----+-----+
     *    | FLASH | f11 | f12 | f13 | f14 | f15 | TOP |
     *    +-------+-----+-----+-----+-----+-----+-----+
     *    |       | f1  | f2  | f3  | f4  | f5  |     |
     *    +-------+-----+-----+-----+-----+-----+     |
     *    |       |  1  |  2  |  3  |  4  |  5  +-----+
     *    +-------+-----+-----+-----+-----+-----+     |
     *    |       |LGUI |LSFT |LALT |LCTL |  ,  |     |
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
    RESET,   KC_F20,  KC_F19,  KC_F18,  KC_F17,  KC_F16,  TG(MTOP),
    KC_TRNS, KC_F10,  KC_F9,   KC_F8,   KC_F7,   KC_F6,   TG(MSYM),
    KC_TRNS, KC_0,    KC_9,    KC_8,    KC_7,    KC_6,
    KC_TRNS, KC_RGUI, KC_RSFT, KC_RALT, KC_RCTL, KC_DOT,  TG(MNUM),
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                 KC_TRNS, KC_TRNS,
                                                          KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS,
    /* right hand
     *        +-----+-----+-----+-----+-----+-----+-------+
     *        | TOP | f16 | f17 | f18 | f19 | f20 | FLASH |
     *        +-----+-----+-----+-----+-----+-----+-------+
     *        | SYM | f6  | f7  | f8  | f9  | f10 |       |
     *        |     +-----+-----+-----+-----+-----+-------+
     *        +-----+  6  |  7  |  8  |  9  |  0  |       |
     *        | NUM +-----+-----+-----+-----+-----+-------+
     *        |     |  .  |RCTL |RALT |RSFT |RGUI |       |
     *        +-----+-----+-----+-----+-----+-----+-----+-+
     *                    |     |    |     |     |     |
     *    +-----+-----+   +-----+-----+-----+-----+-----+
     *    |     |     |
     *    +-----+-----+-----+
     *    |     |     |     |
     *    +-----+     |     |
     *    |     |     |     |
     *    +-----+-----+-----+
     */
    TG(MTOP), KC_F15,  KC_F14,  KC_F13,  KC_F12,   KC_F11,  RESET,
    TG(MSYM), KC_F5,   KC_F4,   KC_F3,   KC_F2,    KC_F1,   KC_TRNS,
              KC_5,    KC_4,    KC_3,    KC_2,     KC_1,    KC_TRNS,
    TG(MNUM), KC_COMM, KC_LCTL, KC_LALT, KC_LSFT,  KC_LGUI, KC_TRNS,
                       KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS,
    KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS
  ),

  [MGAM] = LAYOUT_ergodox( // layer 9 : Gaming layer
     /* left hand
      *    +-------+-----+-----+-----+-----+-----+-----+
      *    |  ESC  |  1  | 2   | 3   | 4   | 5   | TOP |
      *    +-------+-----+-----+-----+-----+-----+-----+
      *    | LALT  |     |     |     |     |     |RALT |
      *    +-------+-----+-----+-----+-----+-----+     |
      *    | LCTL  |     |     |     |     |     +-----+
      *    +-------+-----+-----+-----+-----+-----+RCTL |
      *    |   .   |     |     |     |     |     |     |
      *    +-+-----+-----+-----+-----+-----+-----+-----+
      *      |  ,  |  [  |  ]  |  '  | -   |
      *      +-----+-----+-----+-----+-----+   +-----+-----+
      *                                        |     |GAME |
      *                                  +-----+-----+-----+
      *                                  |     |     |     |
      *                                  | DEL |BSPC +-----+
      *                                  |     |     |     |
      *                                  +-----+-----+-----+
      */
     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(MTOP),
     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                   KC_TRNS, KC_TRNS,
                                                            KC_TRNS,
                                          KC_TRNS, KC_TRNS, KC_TRNS,
     /* right hand: Leave blank
      * LTOP and LGAME toggles included in case this layer is stuck
      *        +-----+-----+-----+-----+-----+-----+-------+
      *        |     |     |     |     |     |     |       |
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
     TG(MTOP),KC_5,    KC_4,    KC_3,    KC_2,    KC_1,    KC_ESC,
     KC_RALT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS,
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TAB,
     KC_RCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS,
                       KC_J,    KC_I,    KC_RBRC, KC_LBRC, KC_COMM,
     KC_TRNS, KC_TRNS,
     KC_TRNS,
     KC_TRNS, KC_BSPC, KC_DEL
  ),

  [MUTIL] = LAYOUT_ergodox( // layer 9 : Media/nav layer
     /* left hand
      *    +-------+-----+-----+-----+-----+-----+-----+
      *    |       |     |     |     |     |UTIL | TOP |
      *    +-------+-----+-----+-----+-----+-----+-----+
      *    |       |     |     |Mute | V+  |     | SYM |
      *    +-------+-----+-----+-----+-----+-----+     |
      *    |       |     |     | Rw  |Play | FF  +-----+
      *    +-------+-----+-----+-----+-----+-----+ NUM |
      *    |       |     |     | <Sk |  V- | Sk> |     |
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
     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(MTOP),
     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(MSYM),
     KC_TRNS,  KC_TRNS, KC_RGHT, KC_UP,   KC_DOWN, KC_LEFT,
     KC_TRNS,  KC_TRNS, KC_END,  KC_PGUP, KC_PGDN, KC_HOME, TG(MNUM),
     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                   KC_TRNS,  KC_TRNS,
                                                             KC_TRNS,
                                          KC_TRNS, KC_TRNS,  KC_TRNS,
     /* right hand
      *        +-----+-----+-----+-----+-----+-----+-------+
      *        | TOP |     |     |     |     |     |       |
      *        +-----+-----+-----+-----+-----+-----+-------+
      *        | SYM |     |     |     |     |     |       |
      *        +-----+LEFT |DOWN | UP  |RGHT |     |       |
      *        | NUM +-----+-----+-----+-----+-----+-------+
      *        |     |HOME |PGDN |PGUP | END |     |       |
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
     TG(MTOP), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     TG(MSYM), KC_TRNS, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS,
               KC_MFFD, KC_MPLY, KC_MRWD, KC_TRNS, KC_TRNS, KC_TRNS,
     TG(MNUM), KC_MNXT, KC_VOLD, KC_MPRV, KC_TRNS, KC_TRNS, KC_TRNS,
                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS,  KC_TRNS,
     KC_TRNS,
     KC_TRNS,  KC_TRNS, KC_TRNS
  ),

  [MTOP] = LAYOUT_ergodox( // Top layer : function layers
    /* left hand
     *    +-------+-----+-----+-----+-----+-----+-----+
     *    |MIRROR |     |     |     |     |     | TOP |
     *    +-------+-----+-----+-----+-----+-----+-----+
     *    |       |CAPLK|SCRLK|NUMLK|     |PRTSC| SYM |
     *    +-------+-----+-----+-----+-----+-----+     |
     *    |       |     |GAME |UTIL | NUM | SYM +-----+
     *    +-------+-----+-----+-----+-----+-----+ NUM |
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
    TG(MMIRROR), KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,  TG(MTOP),
    KC_TRNS,     KC_TRNS,   KC_CAPS,    KC_SCRL,   KC_NUM,    KC_PSCR,  TG(MSYM),
    KC_TRNS,     KC_TRNS,   TG(MGAM),   TG(MUTIL),  TG(MNUM),  TG(MSYM),
    KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,  TG(MNUM),
    KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,
                                                              KC_TRNS,  KC_TRNS,
                                                                        KC_TRNS,
                                                   KC_TRNS,   KC_TRNS,  KC_TRNS,
    /* right hand
     *        +-----+-----+-----+-----+-----+-----+-------+
     *        | TOP |     |     |     |     |     |MIRROR |
     *        +-----+-----+-----+-----+-----+-----+-------+
     *        | SYM |PRTSC|NUMLK|SCRLK|CAPLK|     |       |
     *        |     +-----+-----+-----+-----+-----+-------+
     *        +-----+ SYM | NUM |UTIL |GAME |     |       |
     *        | NUM +-----+-----+-----+-----+-----+-------+
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
    TG(MTOP), KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,  TG(MMIRROR),
    TG(MSYM), KC_PSCR,   KC_NUM,     KC_SCRL,   KC_CAPS,  KC_TRNS,  KC_TRNS,
              TG(MSYM),  TG(MNUM),   TG(MUTIL), TG(MGAM), KC_TRNS,  KC_TRNS,
    TG(MNUM), KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,
                         KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS,   KC_TRNS
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
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
  }
  return true;
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
