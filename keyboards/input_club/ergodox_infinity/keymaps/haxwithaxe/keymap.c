#include QMK_KEYBOARD_H
#include "version.h"

#define CTL_ESC CTL_T(KC_ESC)
#define NUM_BSPC LT(LNUM, KC_BSPC)
#define NUM_SPC LT(LNUM, KC_SPC)
#define SYM_DEL LT(LSYM, KC_DEL)
#define SYM_ENT LT(LSYM, KC_ENT)

enum custom_layers {
    L0,      // Base layer
    LMIRROR, // Mirror layer for flash derps
    LSYM,    // Symbols and nav layer
    LNUM,    // Numbers and F keys layer
    LGAM,    // Generic Gaming layer
    LDD,     // DunDef Base layer
    LDDP1,   // DunDef DPad1
    LDDP2,   // DunDef DPad2
    LDDP3,   // DunDef DPad3
    LDDCTL,  // DunDef Control
    LUTIL,   // Media/nav layer
    LTOP     // Top control and lock keys layer
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  VRSN,
  RGB_SLD
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [L0] = LAYOUT_ergodox(  // layer 0 : default
    /*
     * left hand
     *    +-------+-----+-----+-----+-----+-----+-----+
     *    |       |     |     |     |     |     |LTOP |
     *    +-------+-----+-----+-----+-----+-----+-----+
     *    |       |  Q  |  W  |  E  |  R  |  T  |CTL/ |
     *    +-------+-----+-----+-----+-----+-----+ ESC |
     *    |       |  A  |  S  |  D  |  F  |  G  +-----+
     *    +-------+-----+-----+-----+-----+-----+ TAB |
     *    |       |  Z  |  X  |  C  |  V  |  B  |     |
     *    +-+-----+-----+-----+-----+-----+-----+-----+
     *      |     | RT  | DN  | UP  | LT  |
     *      +-----+-----+-----+-----+-----+   +-----+------+
     *                                        |LCTRL| LALT |
     *                                  +-----+-----+------+
     *                                  | NUM |SYM  | INS  |
     *                                  | DEL |BSPC +------+
     *                                  |     |     |LSHIFT|
     *                                  +-----+-----+------+
     */
    KC_NO, KC_NO,  KC_NO,   KC_NO, KC_NO,   KC_NO,   TG(LTOP),
    KC_NO, KC_Q,   KC_W,    KC_E,  KC_R,    KC_T,    CTL_ESC,
    KC_NO, KC_A,   KC_S,    KC_D,  KC_F,    KC_G,
    KC_NO, KC_Z,   KC_X,    KC_C,  KC_V,    KC_B,    KC_TAB,
    KC_NO, KC_RGHT,KC_DOWN, KC_UP, KC_LEFT,
                                            KC_LALT, KC_LCTL,
                                                     KC_INS,
                                   SYM_DEL, NUM_BSPC,KC_LSFT,
    /* right hand
     *        +-----+-----+-----+-----+-----+-----+-------+
     *        |LTOP|     |     |     |     |     |       |
     *        +-----+-----+-----+-----+-----+-----+-------+
     *        |  '  |  Y  |  U  |  I  |  O  |  P  |       |
     *        |     +-----+-----+-----+-----+-----+-------+
     *        +-----+  H  |  J  |  K  |  L  |  ;  |       |
     *        |  -  +-----+-----+-----+-----+-----+-------+
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
    TG(LTOP), KC_NO,  KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,
    KC_QUOT,  KC_Y,   KC_U,    KC_I,    KC_O,     KC_P,    KC_NO,
              KC_H,   KC_J,    KC_K,    KC_L,     KC_SCLN, KC_NO,
    KC_MINS,  KC_N,   KC_M,    KC_COMM, KC_DOT,   KC_SLSH, KC_NO,
                      KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,
    KC_RSFT, KC_RCTL,
    KC_RALT,
    MO(LUTIL), NUM_SPC,  SYM_ENT
  ),

  [LMIRROR] = LAYOUT_ergodox(  // layer 1 : Mirror default layer
    // Keeping normal qwerty because other layers aren't mirrored
    /* left hand
     */
    KC_NO,   KC_0,    KC_9,     KC_8,    KC_7,    KC_6,   KC_NO,
    KC_RBRC, KC_P,    KC_O,     KC_I,    KC_U,    KC_Y,   KC_LBRC, 
    KC_QUOT, KC_SCLN, KC_L,     KC_K,    KC_J,    KC_H,
    KC_MINS, KC_SLSH, KC_DOT,   KC_COMM, KC_M,    KC_N,   MO(LTOP),
    KC_RGUI, KC_NO,   KC_NO,    KC_NO,   KC_NO,
            									  KC_RCTL,KC_RSFT,
    	        									      KC_RALT,
                                         KC_ENT,  KC_SPC, MO(LSYM),

    /*
     * right hand
     */
     KC_ESC,   KC_5,     KC_4,    KC_3,     KC_2,  KC_1,   KC_EQL,
     KC_NO,    KC_T,     KC_R,    KC_E,     KC_W,  KC_Q,   KC_BSLS,
               KC_G,     KC_F,    KC_D,     KC_S,  KC_A,   KC_TAB, 
     MO(LTOP), KC_B,     KC_V,    KC_C,     KC_X,  KC_Z,   KC_GRV, 
   	                     KC_NO,   KC_NO,    KC_NO, KC_NO,  KC_LGUI, 
     KC_LALT,  KC_LCTL,
     KC_INS,
     KC_LSFT,  KC_BSPC, KC_DEL
  ),

  [LSYM] = LAYOUT_ergodox( // layer 9 : Left symbol layer
     /* left hand
      *    +-------+-----+-----+-----+-----+-----+-----+
      *    |       |     |     |     |     |     | TOP |
      *    +-------+-----+-----+-----+-----+-----+-----+
      *    |       |     |  [  |  {  |  }  |  ]  |     |
      *    +-------+-----+-----+-----+-----+-----+     |
      *    |       |     |  @  |  #  |  $  |  %  +-----+
      *    +-------+-----+-----+-----+-----+-----+     |
      *    |       |     |  ~  |  `  |  |  |  \  |     |
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
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(LTOP),
     KC_TRNS, KC_NO,   KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, KC_TRNS,
     KC_TRNS, KC_NO,   KC_AT,   KC_HASH, KC_DLR,  KC_PERC,
     KC_TRNS, KC_NO,   KC_TILD, KC_GRV,  KC_PIPE, KC_BSLS, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                  KC_TRNS, KC_TRNS,
                                                           KC_TRNS,
                                         KC_TRNS, KC_TRNS, KC_TRNS,
     /* right hand
      *        +-----+-----+-----+-----+-----+-----+-------+
      *        | TOP |     |     |     |     |     |       |
      *        +-----+-----+-----+-----+-----+-----+-------+
      *        |     |  ;  |  <  |  >  |  :  |     |       |
      *        |     +-----+-----+-----+-----+-----+-------+
      *        +-----+  ^  |  &  |  *  |  !  |     |       |
      *        |     +-----+-----+-----+-----+-----+-------+
      *        |     |  /  |  (  |  )  |  ?  |     |       |
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
     TG(LTOP),KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_SCLN,   KC_LT, KC_GT,   KC_COLN, KC_TRNS, KC_TRNS,
              KC_CIRC, KC_AMPR, KC_ASTR, KC_EXLM, KC_NO,   KC_TRNS,
     KC_TRNS, KC_SLSH, KC_LPRN, KC_RPRN, KC_QUES, KC_TRNS, KC_TRNS,
                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS,
     KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [LNUM] = LAYOUT_ergodox(
    /* Left hand
     *    +-------+-----+-----+-----+-----+-----+-----+
     *    | FLASH | f11 | f12 | f13 | f14 | f15 | TOP |
     *    +-------+-----+-----+-----+-----+-----+-----+
     *    |       | f1  | f2  | f3  | f4  | f5  |     |
     *    +-------+-----+-----+-----+-----+-----+     |
     *    |       |  1  |  2  |  3  |  4  |  5  +-----+
     *    +-------+-----+-----+-----+-----+-----+     |
     *    |       |     |     |     |     |  =  |     |
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
    QK_BOOT, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  TG(LTOP),
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
    KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_EQL,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                 KC_TRNS, KC_TRNS,
                                                          KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS,
    /* right hand
     *        +-----+-----+-----+-----+-----+-----+-------+
     *        | TOP | f16 | f17 | f18 | f19 | f20 | FLASH |
     *        +-----+-----+-----+-----+-----+-----+-------+
     *        |     | f6  | f7  | f8  | f9  | f10 |       |
     *        |     +-----+-----+-----+-----+-----+-------+
     *        +-----+  6  |  7  |  8  |  9  |  0  |       |
     *        |     +-----+-----+-----+-----+-----+-------+
     *        |     |  +  |     |     |     |     |       |
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
    TG(LTOP), KC_F16,  KC_F17,  KC_F18,  KC_F19,   KC_F20,  QK_BOOT,
    KC_TRNS,  KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_TRNS,
              KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_TRNS,
    KC_TRNS,  KC_PLUS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                       KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS,
    KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS
  ),

  [LGAM] = LAYOUT_ergodox( // layer 9 : Gaming layer
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
     KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    TG(LTOP),
     KC_BSLS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RALT,
     KC_TAB,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_MINS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RCTL,
     KC_COMM,  KC_LBRC, KC_RBRC, KC_I,    KC_J,
                                                   KC_TRNS, KC_TRNS,
                                                            KC_TRNS,
                                          KC_DEL,  KC_BSPC, KC_TRNS,
     /* right hand: Leave blank
      * LTOP and LGAM toggles included in case this layer is stuck
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
     TG(LTOP), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS,  KC_TRNS,
     KC_TRNS,
     KC_TRNS,  KC_TRNS, KC_TRNS
  ),

  [LDD] = LAYOUT_ergodox( // layer 3: Dungeon Defenders
    /* left hand
     *    +-------+-----+-----+-----+-----+-----+-----+
     *    |   3   |  6  |  7  |  8  |  9  |  0  |     |
     *    +-------+-----+-----+-----+-----+-----+-----+
     *    |   2   |     |     |     |     |     |  M  |
     *    +-------+-----+-----+-----+-----+-----+     |
     *    |   1   |     |     |     |blank|  X  +-----+
     *    +-------+-----+-----+-----+-----+-----+     |
     *    |   1   |     |blank|blank|     |  5  |     |
     *    +-+-----+-----+-----+-----+-----+-----+-----+
     *      |blank|blank|blank|SHIFT|  4  |
     *      +-----+-----+-----+-----+-----+   +-----+-----+
     *                                        |     | INS |
     *                                  +-----+-----+-----+
     *                                  |     | DD  |     |
     *                                  | SPC | CTL +-----+
     *                                  |     |     |     |
     *                                  +-----+-----+-----+
     */
    KC_3,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,       KC_TRNS,
    KC_2,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_M,
    KC_1,  KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_X,
    KC_1,  KC_TRNS, KC_NO,   KC_NO,   KC_TRNS, KC_5,       KC_TRNS,
    KC_ESC,KC_NO,   KC_NO,   KC_LSFT, KC_4,
                                               KC_TRNS,    KC_INS,
                                                           KC_TRNS,
                                      KC_DEL,  MO(LDDCTL), KC_TRNS,
    /* right hand: Partial gamepad 1
     *        +-----+-----+-----+-----+-----+-----+-------+
     *        |     |     |     |     |     |     |       |
     *        +-----+-----+-----+-----+-----+-----+-------+
     *        |     |     |     |     |     |     |       |
     *        | AB2 +-----+-----+-----+-----+-----+-------+
     *        +-----+     |     |     |     |     |       |
     *        |     +-----+-----+-----+-----+-----+-------+
     *        | AB1 |     |CamLt| Up  |Right|CamRt|       |
     *        +-----+-----+-----+-----+-----+-----+-----+-+
     *                    |Left |Down |     |     |     |
     *    +-----+-----+   +-----+-----+-----+-----+-----+
     *    |     |     |
     *    +-----+-----+-----+
     *    |Zoom |     |     |
     *    +-----+ Att |  B  |
     *    |AltAt|     |     |
     *    +-----+-----+-----+
     */
    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // pad 1 ab2
    KC_PDOT,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
    // pad 1 ab1
    KC_P0,      KC_TRNS, KC_SLSH, KC_UP,   KC_RIGHT, KC_BSLS, KC_TRNS,
                         KC_LEFT, KC_DOWN, KC_TRNS,  KC_TRNS, KC_NO,
    MO(LDDCTL), KC_TRNS,
    KC_PAUS,  // com zoom
    KC_GRAVE, KC_PPLS, KC_PGUP  //pad 1 lshoulder, com rshoulder and b button
  ),

  [LDDP1] = LAYOUT_ergodox(
    KC_PDOT, KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_NO,   KC_TRNS,
    KC_P0,   KC_LEFT, KC_UP,   KC_NO,    KC_NO,  KC_NO,   KC_RALT,
    KC_PMNS, KC_NO,   KC_DOWN, KC_RIGHT, KC_NO,  KC_NO,
    KC_PMNS, KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_NO,   KC_HOME,
    KC_NO,   KC_NO,   KC_NO,   KC_TRNS,  KC_NO,
                                                 KC_NO,   KC_NO,
                                                          KC_NO,
                                         KC_INS, KC_TRNS, KC_NO,

    KC_TRNS,  KC_NO,   KC_NO,  KC_NO, KC_NO,   KC_NO, KC_NO,
    KC_NO,    KC_NO,   KC_NO,  KC_NO, KC_NO,   KC_NO, KC_NO,
              KC_NO,   KC_NO,  KC_NO, KC_NO,   KC_NO, KC_NO,
    KC_NO,    KC_NO,   KC_NO,  KC_NO, KC_NO,   KC_NO, KC_NO,
              KC_SLSH, KC_NO,  KC_NO, KC_BSLS, KC_NO,
    KC_TRNS,    KC_NO,
    KC_PAUS,
    KC_GRAVE, KC_PPLS, KC_PGUP
  ),

  [LDDP2] = LAYOUT_ergodox(
    KC_PAST, KC_NO, KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_TRNS,
    KC_NUM,  KC_P7, KC_PSLS, KC_NO,   KC_NO,  KC_NO,   KC_PENT,
    KC_PMNS, KC_NO, KC_P8,   KC_P9,   KC_NO,  KC_NO,
    KC_PMNS, KC_NO, KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_HOME,
    KC_NO,   KC_NO, KC_NO,   KC_TRNS, KC_NO,
                                              KC_NO,   KC_SCLN,
                                                       KC_NO,
                                      KC_INS, KC_TRNS, KC_NO,

    KC_TRNS, KC_NO,    KC_NO,  KC_NO, KC_NO,  KC_NO, KC_NO,
    KC_NO,   KC_NO,    KC_NO,  KC_NO, KC_NO,  KC_NO, KC_NO,
             KC_NO,    KC_NO,  KC_NO, KC_NO,  KC_NO, KC_NO,
    KC_TRNS, KC_NO,    KC_NO,  KC_NO, KC_NO,  KC_NO, KC_NO,
             KC_MINS,  KC_NO,  KC_NO, KC_EQL, KC_NO,
    KC_TRNS,   KC_QUOTE,
    KC_PAUS,
    KC_DEL,  KC_LBRC, KC_PGUP
  ),

  [LDDP3] = LAYOUT_ergodox(
    KC_P6,   KC_NO, KC_NO, KC_NO,   KC_NO,  KC_NO,   KC_TRNS,
    KC_P4,   KC_P1, KC_P5, KC_NO,   KC_NO,  KC_NO,   KC_RCTL,
    KC_PMNS, KC_NO, KC_P2, KC_P3,   KC_NO,  KC_NO,
    KC_PMNS, KC_NO, KC_NO, KC_NO,   KC_NO,  KC_NO,   KC_HOME,
    KC_NO,   KC_NO, KC_NO, KC_TRNS, KC_NO,
                                            KC_NO,   KC_NO,
                                                     KC_NO,
                                    KC_INS, KC_TRNS, KC_NO,

    KC_TRNS, KC_NO,   KC_NO,  KC_NO, KC_NO,   KC_NO, KC_NO,
    KC_NO,   KC_NO,   KC_NO,  KC_NO, KC_NO,   KC_NO, KC_NO,
             KC_NO,   KC_NO,  KC_NO, KC_NO,   KC_NO, KC_NO,
    KC_TRNS, KC_NO,   KC_NO,  KC_NO, KC_NO,   KC_NO, KC_NO,
             KC_DOT,  KC_NO,  KC_NO, KC_COMM, KC_NO,
    KC_TRNS,   KC_NO,
    KC_PAUS,
    KC_BSPC, KC_RBRC, KC_PGUP
  ),

  [LDDCTL] = LAYOUT_ergodox( // layer 8: Dungeon Defenders Control
    /* left hand
     *    +-------+-----+-----+-----+-----+-----+-----+
     *    |       |     |PAD1 |PAD2 |PAD3 | F1  |     |
     *    +-------+-----+-----+-----+-----+-----+-----+
     *    |       |     |" off|" off|" off|     | TAB |
     *    +-------+-----+-----+-----+-----+-----+     |
     *    |       |     |     |     |  F  |  G  +-----+
     *    +-------+-----+-----+-----+-----+-----+     |
     *    |       |     |     |  C  |     |     |     |
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
    KC_TRNS, KC_NO,   TG(LDDP1), TG(LDDP2), TG(LDDP3), KC_F1, KC_TRNS,
    KC_TRNS, KC_TRNS, TO(LDDP1), TO(LDDP2), TO(LDDP3), KC_TRNS, KC_TAB,
    KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_F,      KC_G,
    KC_TRNS, KC_TRNS, KC_TRNS,   KC_C,      KC_TRNS,   KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
                                                       KC_TRNS, KC_TRNS,
                                                                KC_TRNS,
                                            KC_TRNS,   KC_TRNS, KC_TRNS,
    /* right hand
     *        +-----+-----+-----+-----+-----+-----+-------+
     *        |     | F1  |PAD1 |PAD2 |PAD3 |     |       |
     *        +-----+-----+-----+-----+-----+-----+-------+
     *        | TAB |     |" off|" off|" off|     |       |
     *        |     +-----+-----+-----+-----+-----+-------+
     *        +-----+  G  |  F  |     |     |     |       |
     *        |     +-----+-----+-----+-----+-----+-------+
     *        |     |     |     |  C  |     |     |       |
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
    KC_TRNS, KC_F1,   TG(LDDP3), TG(LDDP2), TG(LDDP1), KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, TO(LDDP3), TO(LDDP2), TO(LDDP1), KC_TRNS, KC_TRNS,
             KC_G,    KC_F,      KC_TRNS,   KC_TRNS,   KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,   KC_C,      KC_TRNS,   KC_TRNS, KC_TRNS,
                      KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
  ),


  [LUTIL] = LAYOUT_ergodox( // layer 9 : Media layer
     /* left hand
      *    +-------+-----+-----+-----+-----+-----+-----+
      *    |       |     |     |     |     |     | TOP |
      *    +-------+-----+-----+-----+-----+-----+-----+
      *    |       |     |     |Mute | V+  |     |     |
      *    +-------+-----+-----+-----+-----+-----+     |
      *    |       |     |     | Rw  |Play | FF  +-----+
      *    +-------+-----+-----+-----+-----+-----+     |
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
     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(LTOP),
     KC_TRNS,  KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLU, KC_TRNS, KC_TRNS,
     KC_TRNS,  KC_TRNS, KC_TRNS, KC_MRWD, KC_MPLY, KC_MFFD,
     KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_VOLD, KC_MNXT, KC_TRNS,
     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                   KC_TRNS, KC_TRNS,
                                                            KC_TRNS,
                                          KC_TRNS, KC_TRNS, KC_TRNS,
     /* right hand: Leave blank
      *        +-----+-----+-----+-----+-----+-----+-------+
      *        | TOP |     |     |     |     |     |       |
      *        +-----+-----+-----+-----+-----+-----+-------+
      *        |     |     |     |     |     |     |       |
      *        |     +-----+-----+-----+-----+-----+-------+
      *        +-----+LEFT |DOWN | UP  |RGHT |     |       |
      *        |     +-----+-----+-----+-----+-----+-------+
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
     TG(LTOP), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
               KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_UNDS, KC_TRNS,
     KC_TRNS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_MINS, KC_TRNS,
                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS,  KC_TRNS,
     KC_TRNS,
     KC_TRNS,  KC_TRNS, KC_TRNS
  ),

  [LTOP] = LAYOUT_ergodox( // Top layer : function layers
    /* left hand
     *    +-------+-----+-----+-----+-----+-----+-----+
     *    |MIRROR |     |     |     |     |     | TOP |
     *    +-------+-----+-----+-----+-----+-----+-----+
     *    |       |CAPLK|SCRLK|NUMLK|     |PRTSC|     |
     *    +-------+-----+-----+-----+-----+-----+     |
     *    |       |     |GAME |UTIL | NUM | SYM +-----+
     *    +-------+-----+-----+-----+-----+-----+     |
     *    |       |     |LGUI |LSFT |LALT |LCTL |     |
     *    +-+-----+-----+-----+-----+-----+-----+-----+
     *      | LDD |LDDP1|LDDP2|LDDP3|LDDCTL|
     *      +-----+-----+-----+-----+------+  +-----+-----+
     *                                        |     |     |
     *                                  +-----+-----+-----+
     *                                  |     |     |     |
     *                                  |     |     +-----+
     *                                  |     |     |     |
     *                                  +-----+-----+-----+
     */
    TG(LMIRROR), KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,  TG(LTOP),
    KC_TRNS,     KC_TRNS,   KC_CAPS,    KC_SCRL,   KC_NUM,    KC_PSCR,  KC_TRNS,
    KC_TRNS,     KC_TRNS,   TG(LGAM),   TG(LUTIL), TG(LNUM),  TG(LSYM),
    KC_TRNS,     KC_TRNS,   KC_LGUI,    KC_LSFT,   KC_LALT,   KC_LCTL,  KC_TRNS,
    TG(LDD),     TG(LDDP1), TG(LDDP2),  TG(LDDP3), TG(LDDCTL),
                                                              KC_TRNS,  KC_TRNS,
                                                                        KC_TRNS,
                                                   KC_TRNS,   KC_TRNS,  KC_TRNS,
    /* right hand
     *        +-----+-----+-----+-----+-----+-----+-------+
     *        | TOP |     |     |     |     |     |MIRROR |
     *        +-----+-----+-----+-----+-----+-----+-------+
     *        |     |PRTSC|NUMLK|SCRLK|CAPLK|     |       |
     *        |     +-----+-----+-----+-----+-----+-------+
     *        +-----+ SYM | NUM |UTIL |GAME |     |       |
     *        |     +-----+-----+-----+-----+-----+-------+
     *        |     |RCTL |RALT |RSFT |RGUI |     |       |
     *        +-----+-----+-----+-----+-----+-----+-----+-+
     *                   |LDDCTL|LDDP3|LDDP2|LDDP1| LDD |
     *    +-----+-----+  +------+-----+-----+-----+-----+
     *    |     |     |
     *    +-----+-----+-----+
     *    |     |     |     |
     *    +-----+     |     |
     *    |     |     |     |
     *    +-----+-----+-----+
     */
    TG(LTOP), KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,  TG(LMIRROR),
    KC_TRNS,  KC_PSCR,   KC_NUM,     KC_SCRL,   KC_CAPS,  KC_TRNS,  KC_TRNS,
              TG(LSYM),  TG(LNUM),   TG(LUTIL), TG(LGAM), KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_RCTL,   KC_RALT,    KC_RSFT,   KC_RGUI,  KC_TRNS,  KC_TRNS,
                         TG(LDDCTL), TG(LDDP3), TG(LDDP2),TG(LDDP1),TG(LDD),
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
