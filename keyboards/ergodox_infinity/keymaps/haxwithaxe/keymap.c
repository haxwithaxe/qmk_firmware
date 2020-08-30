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

enum dd_macros {
  STACK_MM = 0,
  STACK_FT,
  STACK_MB,
  STACK_LT,
  STACK_DST
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
     *    | LSHIFT|  Z  |  X  |  C  |  V  |  B  |     |
     *    +-+-----+-----+-----+-----+-----+-----+-----+
     *      |LGUI |  `  |  \  |LEFT |RIGHT|
     *      +-----+-----+-----+-----+-----+   +-----+-----+
     *                                        |LCTRL| LALT|
     *                                  +-----+-----+-----+
     *                                  |     |     | HOME|
     *                                  |BKSPC| DEL +-----+
     *                                  |     |     | END |
     *                                  +-----+-----+-----+
     */
    KC_EQL,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5, KC_ESC,
    KC_BSLS, KC_Q,   KC_W,    KC_E,    KC_R,    KC_T, TG(LTOP),
    KC_TAB,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,
    KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, MO(LTOP),
    KC_LGUI, KC_GRV, KC_BSLS, KC_LEFT, KC_RGHT,
                                                KC_LCTL, KC_LALT,
                                                         KC_HOME,
                                       KC_BSPC, KC_DEL,  KC_END,
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
     *                    |LEFT |DOWN | UP  |RIGHT| RGUI|
     *    +-----+-----+   +-----+-----+-----+-----+-----+
     *    | RALT|RCTRL|
     *    +-----+-----+-----+
     *    | PGUP|     |     |
     *    +-----+ ENT | SPC |
     *    | PGDN|     |     |
     *    +-----+-----+-----+
     */
    KC_LOCK,  KC_6,   KC_7,    KC_8,    KC_9,   KC_0,     KC_MINS,
    KC_LBRC, KC_Y,   KC_U,    KC_I,    KC_O,   KC_P,     KC_RBRC,
             KC_H,   KC_J,    KC_K,    KC_L,   KC_SCLN,  KC_QUOT,
    MO(LTOP),KC_N,   KC_M,    KC_COMM, KC_DOT, KC_SLSH,  KC_RSFT,
                     KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, KC_RGUI,
    KC_RALT, KC_RCTL,
    KC_PGUP,
    KC_PGDN, KC_ENT, KC_SPC
  ),

  [L1] = LAYOUT_ergodox( // layer 1 : function layers
     /* left hand
      *    +-------+-----+-----+-----+-----+-----+-----+
      *    |       | f1  | f2  | f3  | f4  | f5  | f11 |
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
     KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
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
     KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS,
     KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [L2] = LAYOUT_ergodox(
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
     *        |     |     |NMLCK| P/  | P*  | P-  |       |
     *        +-----+-----+-----+-----+-----+-----+-------+
     *        |     |     | P7  | P8  | P9  | P+  |       |
     *        |     +-----+-----+-----+-----+-----+-------+
     *        +-----+     | P4  | P5  | P6  | P+  |       |
     *        |     +-----+-----+-----+-----+-----+-------+
     *        |     |     | P1  | P2  | P3  |PENT |       |
     *        +-----+-----+-----+-----+-----+-----+-----+-+
     *                    |     |     | P.  |PENT |     |
     *    +-----+-----+   +-----+-----+-----+-----+-----+
     *    |     |     |
     *    +-----+-----+-----+
     *    |     |     |     |
     *    +-----+     | P0  |
     *    |     |     |     |
     *    +-----+-----+-----+
     */
    KC_TRNS, KC_TRNS, KC_NUMLOCK, KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS, RESET,
    KC_TRNS, KC_TRNS, KC_KP_7,    KC_KP_8,     KC_KP_9,        KC_KP_PLUS,  KC_TRNS,
             KC_TRNS, KC_KP_4,    KC_KP_5,     KC_KP_6,        KC_KP_PLUS,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_KP_1,    KC_KP_2,     KC_KP_3,        KC_KP_ENTER, KC_TRNS,
                      KC_TRNS,    KC_TRNS,     KC_KP_DOT,      KC_KP_ENTER, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_KP_0
  ),

  [L3] = LAYOUT_ergodox( // layer 3: Dungeon Defenders
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
     *      |     |     |     |     |     |
     *      +-----+-----+-----+-----+-----+   +-----+-----+
     *                                        |     |     |
     *                                  +-----+-----+-----+
     *                                  |     |     |     |
     *                                  |     |     +-----+
     *                                  |     |     |     |
     *                                  +-----+-----+-----+
     */
    KC_3,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
    KC_2,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_M,
    KC_1,  KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_X,
    KC_1,  KC_TRNS, KC_NO,   KC_NO,   KC_TRNS, KC_5,    KC_TRNS,
    KC_NO, KC_NO,   KC_NO,   KC_LSFT, KC_4,
                                               KC_TRNS, KC_INS,
                                                        KC_TRNS,
                                      KC_SPC,  MO(L7),  KC_TRNS,
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
     *                    |     |     |     |     |     |
     *    +-----+-----+   +-----+-----+-----+-----+-----+
     *    |     |     |
     *    +-----+-----+-----+
     *    |     |     |     |
     *    +-----+     |     |
     *    |     |     |     |
     *    +-----+-----+-----+
     */
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // pad 1 ab2
    KC_PDOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // pad 1 ab1, noop, pad 1 cam left, noop, pad 1 cam right
    KC_P0,   KC_TRNS, KC_SLSH, KC_UP,   KC_RIGHT, KC_BSLS, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_PAUS,  // com zoom
    KC_GRAVE, KC_PPLS, KC_PGUP  //pad 1 lshoulder, com rshoulder and b button
  ),


  [L4] = LAYOUT_ergodox(
      KC_PDOT, KC_NO,   KC_NO,   KC_NO,    KC_NO, KC_NO, KC_RALT,
      KC_P0,   KC_LEFT, KC_UP,   KC_NO,    KC_NO, KC_NO, KC_HOME,
      KC_PMNS, KC_NO,   KC_DOWN, KC_RIGHT, KC_NO, KC_NO,
      KC_PMNS, KC_NO,   KC_NO,   KC_NO,    KC_NO, KC_NO, KC_TRNS,
      KC_NO,   KC_NO,   KC_NO,   KC_TRNS,  KC_NO,
                                                         KC_NO,   KC_NO,
                                                                  KC_NO,
                                                 KC_INS, KC_TRNS, KC_NO,

      KC_TRNS, KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,      KC_NO,
      KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,      KC_NO,
               KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,      KC_NO,
      KC_TRNS, KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,      KC_NO,
               KC_SLSH, KC_NO,    KC_NO,   KC_BSLS, KC_NO,
      KC_NO,   KC_NO,
      KC_PAUS,
      KC_GRAVE,  KC_PPLS, KC_PGUP
  ),
  [L5] = LAYOUT_ergodox(
      KC_PAST, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_CAPS,
      KC_NLCK, KC_P7,   KC_PSLS, KC_NO,   KC_NO,   KC_NO, KC_HOME,
      KC_PMNS, KC_NO,   KC_P8,   KC_P9,   KC_NO,   KC_NO,
      KC_PMNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_TRNS,
      KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_NO,
                                                           KC_NO,   KC_SCLN,
                                                                    KC_NO,
                                                   KC_INS, KC_TRNS, KC_NO,

      KC_TRNS, KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,      KC_NO,
      KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,      KC_NO,
               KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,      KC_NO,
      KC_TRNS, KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,      KC_NO,
               KC_MINS, KC_NO,  KC_NO, KC_EQL, KC_NO,
      KC_NO,   KC_QUOTE,
      KC_PAUS,
      KC_DEL,  KC_PPLS, KC_PGUP
  ),
  [L6] = LAYOUT_ergodox(
      KC_P6, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_SLCK,
      KC_P4, KC_P1, KC_P5, KC_NO,   KC_NO,   KC_NO,      KC_HOME,
      KC_PMNS, KC_NO,   KC_P2, KC_P3, KC_NO,   KC_NO,
      KC_PMNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_TRNS,
      KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_NO,
                                                   KC_NO,      KC_NO,
                                                               KC_NO,
                                                   KC_INS, KC_TRNS, KC_NO,

      KC_TRNS, KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,      KC_NO,
      KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,      KC_NO,
               KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,      KC_NO,
      KC_TRNS, KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,      KC_NO,
               KC_DOT, KC_NO,  KC_NO, KC_COMM, KC_NO,
      KC_NO,   KC_NO,
      KC_PAUS,
      KC_BSPC,  KC_PPLS, KC_PGUP
  ),

  [L7] = LAYOUT_ergodox( // layer 8: Dungeon Defenders Control
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
     *      |     |     |     |     |     |
     *      +-----+-----+-----+-----+-----+   +-----+-----+
     *                                        |     |     |
     *                                  +-----+-----+-----+
     *                                  |     |     |     |
     *                                  |     |     +-----+
     *                                  |     |     |     |
     *                                  +-----+-----+-----+
     */
    KC_TRNS, KC_NO,   TG(L4),  TG(L5),  TG(L6),  KC_TRNS, KC_TRNS,
    KC_F1,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TAB,  KC_TRNS, KC_TRNS, KC_TRNS, KC_F,    KC_G,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_C,    KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
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
     *                    |     |     |     |     |     |
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
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [LTOP] = LAYOUT_ergodox( // layer 1 : function layers
    /* left hand
     *    +-------+-----+-----+-----+-----+-----+-----+
     *    |       |LCK-1|LCK-2|LCK-3|LCK-4|LCK-5|     |
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
    KC_TRNS, TG(L1),  TG(L2),  TG(L3),  TG(L4),  TG(L5),  KC_TRNS,
    KC_TRNS, TG(L11), TG(L12), TG(L13), TG(L14), TG(L15), KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                  KC_TRNS, KC_TRNS,
                                                           KC_TRNS,
                                         KC_TRNS, KC_TRNS, KC_TRNS,
    /* right hand
     *        +-----+-----+-----+-----+-----+-----+-------+
     *        |     |LCK-6|LCK-7|LCK-8|LCK-9|LCK-10|      |
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
    KC_TRNS, TG(L6),  TG(L7),  TG(L8),  TG(L9),  TG(L10), KC_TRNS,
    KC_TRNS, TG(L16), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
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
