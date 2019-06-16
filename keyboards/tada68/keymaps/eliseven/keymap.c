#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _MOV 1
#define _NUM 2
#define _GAME 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap _QWERTY: (Base Layer) Default Layer
     * ,----------------------------------------------------------------.
     * | ~ `| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Ins |
     * |----------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
     * |----------------------------------------------------------------|
     * |Ctrl*  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
     * |----------------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
     * |----------------------------------------------------------------|
     * |NUM |Win |Alt |        Space*         |Alt|Win|Ctrl|Lef|Dow|Rig |
     * `----------------------------------------------------------------'
     *
     * - Tap dance Ctrl/Esc
     * - Tap dance MOV/Space
     * - NUM layer in place of LCtrl
     */
    [_QWERTY] = LAYOUT_ansi(
            KC_GRV         , KC_1    , KC_2    , KC_3   , KC_4    , KC_5     , KC_6     , KC_7    , KC_8    , KC_9     , KC_0    , KC_MINS , KC_EQL  , KC_BSPC , KC_INS , \
            KC_TAB         , KC_Q    , KC_W    , KC_E   , KC_R    , KC_T     , KC_Y     , KC_U    , KC_I    , KC_O     , KC_P    , KC_LBRC , KC_RBRC , KC_BSLS , KC_DEL , \
            LCTL_T(KC_ESC) , KC_A    , KC_S    , KC_D   , KC_F    , KC_G     , KC_H     , KC_J    , KC_K    , KC_L     , KC_SCLN , KC_QUOT , KC_ENT  , KC_PGUP , \
            KC_LSFT        , KC_Z    , KC_X    , KC_C   , KC_V    , KC_B     , KC_N     , KC_M    , KC_COMM , KC_DOT   , KC_SLSH , KC_RSFT , KC_UP   , KC_PGDN , \
            MO(_NUM)       , KC_LGUI , KC_LALT ,                      LT(_MOV,KC_SPC)             , KC_RALT , KC_RGUI  , KC_RCTRL , KC_LEFT , KC_DOWN , KC_RGHT) ,

    /* Keymap _MOV: Function Layer
     * ,----------------------------------------------------------------.
     * |   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|       |    |
     * |----------------------------------------------------------------|
     * |     |   |   |   |   |PgU|Cpy|   |   |   |   |   |   |     |    |
     * |----------------------------------------------------------------|
     * | Bksp |Hme|End|Sft|Ctl|PgD|Lft|Dwn|Up |Rgt|Del|   |        |    |
     * |----------------------------------------------------------------|
     * |        |   |   |   |   |   |   |Ent|   |   |   |      |   |    |
     * |----------------------------------------------------------------|
     * |    |    |    |                       |   |   |    |   |   |    |
     * `----------------------------------------------------------------'
     */
    [_MOV] = LAYOUT_ansi(
            _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6        , KC_F7   , KC_F8   , KC_F9    , KC_F10       , KC_F11  , KC_F12  , _______ , _______ , \
            _______ , _______ , _______ , _______ , _______ , KC_PGUP , LCTL(KC_INS) , _______ , _______ , _______  , LSFT(KC_INS) , _______ , _______ , _______ , _______ , \
            KC_BSPC , KC_HOME , KC_END  , KC_LSFT , KC_LCTL , KC_PGDN , KC_LEFT      , KC_DOWN , KC_UP   , KC_RIGHT , KC_DEL       , _______ ,           _______ , _______ , \
            _______ , _______ , _______ , _______ , _______ , _______ , _______      , KC_ENT  , _______ , _______  , _______      , _______ , _______ , _______ , \
            _______ , _______ , _______ ,                _______                                         , _______  , _______ , _______ , _______ , _______ , _______) ,

    /* Keymap _NUM: Function Layer
     * ,----------------------------------------------------------------.
     * |   |   |   |   |   |   |   |   |   |   |  |   |   |        |QWER|
     * |----------------------------------------------------------------|
     * |     |V+ |Mut|V- |   |   |   | 7 | 8 | 9 |   |   |   |     |GAME|
     * |----------------------------------------------------------------|
     * |      |Prv|Ply|Nxt|   |   |Ent| 4 | 5 | 6 |   |   |        |    |
     * |----------------------------------------------------------------|
     * |        |   |   |Blq|   |   |   | 1 | 2 | 3 |   |      |   |    |
     * |----------------------------------------------------------------|
     * |    |    |    |           0           |   |   |    |   |   |    |
     * `----------------------------------------------------------------'
     */
    [_NUM] = LAYOUT_ansi(
            XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , DF(_QWERTY) , \
            XXXXXXX , KC_VOLD , KC_MUTE , KC_VOLU , XXXXXXX , XXXXXXX , XXXXXXX , KC_7    , KC_8    , KC_9    , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , DF(_GAME)  , \
            XXXXXXX , KC_MPRV , KC_MPLY , KC_MNXT , XXXXXXX , XXXXXXX , KC_ENT  , KC_4    , KC_5    , KC_6    , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  , \
            XXXXXXX , XXXXXXX , XXXXXXX , KC_CAPS , XXXXXXX , XXXXXXX , XXXXXXX , KC_1    , KC_2    , KC_3    , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , \
            _______ , XXXXXXX , XXXXXXX ,                        KC_0                     , XXXXXXX , XXXXXXX , _______ , XXXXXXX , XXXXXXX , XXXXXXX) ,

    /* Keymap _GAME: Function Layer
     * ,----------------------------------------------------------------.
     * | ~ `| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Ins |
     * |----------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
     * |----------------------------------------------------------------|
     * |Esc   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
     * |----------------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
     * |----------------------------------------------------------------|
     * |Ctrl|Win |Alt |        Space          |Alt|Win|NUM |Lef|Dow|Rig |
     * `----------------------------------------------------------------'
     *
     * - Gaming layer, moved away Fn buttons as I don't need them.
     */
    [_GAME] = LAYOUT_ansi(
            KC_GRV   , KC_1    , KC_2    , KC_3   , KC_4    , KC_5     , KC_6     , KC_7    , KC_8    , KC_9     , KC_0     , KC_MINS , KC_EQL  , KC_BSPC , KC_INS , \
            KC_TAB   , KC_Q    , KC_W    , KC_E   , KC_R    , KC_T     , KC_Y     , KC_U    , KC_I    , KC_O     , KC_P     , KC_LBRC , KC_RBRC , KC_BSLS , KC_DEL , \
            KC_ESC   , KC_A    , KC_S    , KC_D   , KC_F    , KC_G     , KC_H     , KC_J    , KC_K    , KC_L     , KC_SCLN  , KC_QUOT , KC_ENT  , KC_PGUP , \
            KC_LSFT  , KC_Z    , KC_X    , KC_C   , KC_V    , KC_B     , KC_N     , KC_M    , KC_COMM , KC_DOT   , KC_SLSH  , KC_RSFT , KC_UP   , KC_PGDN , \
            KC_LCTL  , KC_LGUI , KC_LALT ,                      KC_SPC                      , KC_RALT , KC_RGUI  , MO(_NUM) , KC_LEFT , KC_DOWN , KC_RGHT) ,
};
