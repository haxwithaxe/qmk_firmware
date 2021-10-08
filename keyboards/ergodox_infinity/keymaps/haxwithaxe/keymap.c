#include QMK_KEYBOARD_H
#include "debug.h"
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
    KC_LGUI, TG(L1),  KC_NO,   TG(LNUM), TG(LFN),
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
                      TG(LFN), KC_NO,   TG(LNUM), TG(L1),  KC_RGUI,
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
    KC_RGUI, TG(L1),  TG(LNUM), KC_NO,   TG(LFN),
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
   	                     TG(LFN), TG(LNUM), KC_NO, TG(L1), KC_LGUI, 
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
     KC_TRNS, KC_TRNS, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT,
     KC_TRNS, KC_TRNS, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_TRNS,
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
     *                                        |     |     |
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
    KC_NO, KC_NO,   KC_NO,   KC_LSFT, KC_4,
                                               KC_TRNS,    KC_TRNS,
                                                           KC_TRNS,
                                      KC_SPC,  MO(LDDCTL), KC_TRNS,
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
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // pad 1 ab2
    KC_PDOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_P0,   KC_TRNS, KC_SLSH, KC_UP,   KC_RIGHT, KC_BSLS, KC_TRNS,
                      KC_LEFT, KC_DOWN, KC_TRNS, KC_TRNS, KC_NO,
    KC_TRNS, KC_TRNS,
    KC_PAUS,  // com zoom
    KC_GRAVE, KC_PPLS, KC_PGUP  //pad 1 lshoulder, com rshoulder and b button
  ),
  [LDDP1] = LAYOUT_ergodox(
    KC_PDOT, KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_NO,   KC_RALT,
    KC_P0,   KC_LEFT, KC_UP,   KC_NO,    KC_NO,  KC_NO,   KC_HOME,
    KC_PMNS, KC_NO,   KC_DOWN, KC_RIGHT, KC_NO,  KC_NO,
    KC_PMNS, KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_NO,   KC_TRNS,
    KC_NO,   KC_NO,   KC_NO,   KC_TRNS,  KC_NO,
                                                 KC_NO,   KC_NO,
                                                          KC_NO,
                                         KC_INS, KC_TRNS, KC_NO,

    KC_TRNS,  KC_NO,   KC_NO,  KC_NO, KC_NO,   KC_NO, KC_NO,
    KC_NO,    KC_NO,   KC_NO,  KC_NO, KC_NO,   KC_NO, KC_NO,
              KC_NO,   KC_NO,  KC_NO, KC_NO,   KC_NO, KC_NO,
    KC_TRNS,  KC_NO,   KC_NO,  KC_NO, KC_NO,   KC_NO, KC_NO,
              KC_SLSH, KC_NO,  KC_NO, KC_BSLS, KC_NO,
    KC_NO,    KC_NO,
    KC_PAUS,
    KC_GRAVE, KC_PPLS, KC_PGUP
  ),
  [LDDP2] = LAYOUT_ergodox(
    KC_PAST, KC_NO, KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_PENT,
    KC_NLCK, KC_P7, KC_PSLS, KC_NO,   KC_NO,  KC_NO,   KC_HOME,
    KC_PMNS, KC_NO, KC_P8,   KC_P9,   KC_NO,  KC_NO,
    KC_PMNS, KC_NO, KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_TRNS,
    KC_NO,   KC_NO, KC_NO,   KC_TRNS, KC_NO,
                                              KC_NO,   KC_SCLN,
                                                       KC_NO,
                                      KC_INS, KC_TRNS, KC_NO,

    KC_TRNS, KC_NO,    KC_NO,  KC_NO, KC_NO,  KC_NO, KC_NO,
    KC_NO,   KC_NO,    KC_NO,  KC_NO, KC_NO,  KC_NO, KC_NO,
             KC_NO,    KC_NO,  KC_NO, KC_NO,  KC_NO, KC_NO,
    KC_TRNS, KC_NO,    KC_NO,  KC_NO, KC_NO,  KC_NO, KC_NO,
             KC_MINS,  KC_NO,  KC_NO, KC_EQL, KC_NO,
    KC_NO,   KC_QUOTE,
    KC_PAUS,
    KC_DEL,  KC_LBRC, KC_PGUP
  ),
  [LDDP3] = LAYOUT_ergodox(
    KC_P6,   KC_NO, KC_NO, KC_NO,   KC_NO,  KC_NO,   KC_RCTL,
    KC_P4,   KC_P1, KC_P5, KC_NO,   KC_NO,  KC_NO,   KC_HOME,
    KC_PMNS, KC_NO, KC_P2, KC_P3,   KC_NO,  KC_NO,
    KC_PMNS, KC_NO, KC_NO, KC_NO,   KC_NO,  KC_NO,   KC_TRNS,
    KC_NO,   KC_NO, KC_NO, KC_TRNS, KC_NO,
                                            KC_NO,   KC_NO,
                                                     KC_NO,
                                    KC_INS, KC_TRNS, KC_NO,

    KC_TRNS, KC_NO,   KC_NO,  KC_NO, KC_NO,   KC_NO, KC_NO,
    KC_NO,   KC_NO,   KC_NO,  KC_NO, KC_NO,   KC_NO, KC_NO,
             KC_NO,   KC_NO,  KC_NO, KC_NO,   KC_NO, KC_NO,
    KC_TRNS, KC_NO,   KC_NO,  KC_NO, KC_NO,   KC_NO, KC_NO,
             KC_DOT,  KC_NO,  KC_NO, KC_COMM, KC_NO,
    KC_NO,   KC_NO,
    KC_PAUS,
    KC_BSPC, KC_RBRC, KC_PGUP
  ),


  [LDDCTL] = LAYOUT_ergodox( // layer 8: Dungeon Defenders Control
    /* left hand
     *    +-------+-----+-----+-----+-----+-----+-----+
     *    |       |     |PAD1 |PAD2 |PAD3 | F1  | TAB |
     *    +-------+-----+-----+-----+-----+-----+-----+
     *    |       |     |     |     |     |     |     |
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
    KC_TRNS, KC_NO,   TG(LDDP1),  TG(LDDP2),  TG(LDDP3),  KC_F1, KC_TAB,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F,    KC_G,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_C,    KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                 KC_TRNS, KC_TRNS,
                                                          KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS,
    /* right hand
     *        +-----+-----+-----+-----+-----+-----+-------+
     *        |     |PAD1 |PAD2 |PAD3 |     |     |       |
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
    KC_TRNS, MO(LDDP1), MO(LDDP2), MO(LDDP3), KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
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
      *      |     |     |NoOp |NoOp |NoOp |
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
     KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,
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
      */j
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                       KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS,
     KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [LTOP] = LAYOUT_ergodox( // Top layer : function layers
    /* left hand
     *    +-------+-----+-----+-----+-----+-----+-----+
     *    |       | LFN |LNUM | DD  |PAD1 |PAD2 |     |
     *    +-------+-----+-----+-----+-----+-----+-----+
     *    |       |PAD3 |DDCTL|LSAFE|     |     |     |
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
    KC_TRNS, TG(LFN),   TG(LNUM),   TG(LDD),   TG(LDDP1), TG(LDDP2), KC_TRNS,
    KC_TRNS, TG(LDDP3), TG(LDDCTL), TG(LSAFE), TG(LTOP),  TG(LTOP),  KC_TRNS,
    KC_TRNS, KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,
    KC_TRNS, KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,
                                                          KC_TRNS, KC_TRNS,
                                                                   KC_TRNS,
                                               KC_TRNS,   KC_TRNS, KC_TRNS,
    /* right hand
     *        +-----+-----+-----+-----+-----+-----+-------+
     *        |     |PAD3 |DDCTL|LSAFE|LTOP |LTOP |       |
     *        +-----+-----+-----+-----+-----+-----+-------+
     *        |     | LFN |LNUM | DD  |PAD1 |PAD2 |       |
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
    KC_TRNS, TG(LDDP3), TG(LDDCTL), TG(LSAFE), TG(LTOP), TG(LTOP), KC_TRNS,
    KC_TRNS, TG(LDD),   TG(LDDP1),  TG(LDDP2), KC_TRNS,  KC_TRNS,  KC_TRNS,
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
