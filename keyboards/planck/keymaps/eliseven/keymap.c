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

extern keymap_config_t keymap_config;

enum planck_layers {
    _QWERTY,
    _COLEMAK,
    _GAME,
    _LOWER,
    _RAISE,
    _ADJUST,
    _MOV,
    _NUM
};

enum planck_keycodes {
    QWERTY,
    COLEMAK,
    GAME
};

#define SPCMOV LT(_MOV, KC_SPC)
#define TABNUM LT(_NUM, KC_TAB)
#define RAISE LT(_RAISE, KC_ENT)
#define LOWER MO(_LOWER)
#define NUM MO(_NUM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * | Tab* |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Ctrl*|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ;:  |  '"  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |  ,<  |  .>  |  /?  | Shift|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | HYPR | Shift| GUI  | Alt  |Lower | Bksp |Space*|Raise*| RAlt | RGui | RCtrl| MEH  |
     * `-----------------------------------------------------------------------------------'
     *
     * - Tap dance Ctrl/Esc
     * - Tap dance MOV/Space
     * - Tap dance NUM/Tab
     * - Tap dance Raise/Enter
     */
    [_QWERTY] = LAYOUT_ortho_4x12(
            TABNUM        , KC_Q    , KC_W    , KC_E    , KC_R  , KC_T   , KC_Y   , KC_U  , KC_I    , KC_O    , KC_P    , KC_BSPC,
            LCTL_T(KC_ESC), KC_A    , KC_S    , KC_D    , KC_F  , KC_G   , KC_H   , KC_J  , KC_K    , KC_L    , KC_SCLN , KC_QUOT,
            KC_LSFT       , KC_Z    , KC_X    , KC_C    , KC_V  , KC_B   , KC_N   , KC_M  , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT,
            KC_HYPR       , KC_LSFT , KC_LGUI , KC_LALT , LOWER , KC_BSPC, SPCMOV , RAISE , KC_ALGR , KC_RGUI , KC_RCTL , KC_MEH
            ),

    /* Colemak
     * ,-----------------------------------------------------------------------------------.
     * | Tab* |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Ctrl*|   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '"  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  | Shift|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | HYPR | Shift| GUI  | Alt  |Lower*| Bksp |Space*|Raise*| RAlt | RGui | RCtrl| MEH  |
     * `-----------------------------------------------------------------------------------'
     *
     * - Tap dance Ctrl/Esc
     * - Tap dance MOV/Space
     * - Tap dance NUM/Tab
     * - Tap dance Raise/Enter
     */
    [_COLEMAK] = LAYOUT_ortho_4x12(
            TABNUM         , KC_Q    , KC_W    , KC_F    , KC_P  , KC_G   , KC_J   , KC_L  , KC_U    , KC_Y    , KC_SCLN , KC_BSPC,
            LCTL_T(KC_ESC) , KC_A    , KC_R    , KC_S    , KC_T  , KC_D   , KC_H   , KC_N  , KC_E    , KC_I    , KC_O    , KC_QUOT,
            KC_LSFT        , KC_Z    , KC_X    , KC_C    , KC_V  , KC_B   , KC_K   , KC_M  , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT,
            KC_HYPR        , KC_LSFT , KC_LGUI , KC_LALT , LOWER , KC_BSPC, SPCMOV , RAISE , KC_ALGR , KC_RGUI , KC_RCTL , KC_MEH
            ),

    /* GAME
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ;:  |  '"  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |  ,<  |  .>  |  /?  | Shift|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl | HYPR |  GUI |  Alt | Lower|Space |Space |Raise*| RAlt | RGui | RCtrl| MEH  |
     * `-----------------------------------------------------------------------------------'
     *
     * This layer is supposed to be used for gaming, you normally cant Ctrl on
     * it's normal position and Space acting as normal. I moved NUM modifier to
     * where Shift is in the base layer. This is mainly thought for LoL as I can
     * have numbers and F keys close to my thumb.
     *
     * */
    [_GAME] = LAYOUT_ortho_4x12(
            KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R  , KC_T    , KC_Y    , KC_U   , KC_I    , KC_O    , KC_P    , KC_BSPC,
            KC_ESC  , KC_A    , KC_S    , KC_D    , KC_F  , KC_G    , KC_H    , KC_J   , KC_K    , KC_L    , KC_SCLN , KC_QUOT,
            KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V  , KC_B    , KC_N    , KC_M   , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT,
            KC_RCTL , KC_HYPR , KC_LGUI , KC_LALT , LOWER , KC_SPC  , KC_SPC  , RAISE  , KC_ALGR , KC_RGUI , KC_RCTL , KC_MEH
            ),

    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |      |      |      |      |   \  |   -  |   =  |   [  |   ]  |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      | **** |      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_ortho_4x12(
            KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSPC ,
            _______ , _______ , _______ , _______ , _______ , _______ , KC_BSLS , KC_MINS , KC_EQL  , KC_LBRC , KC_RBRC , _______ ,
            _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
            _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
            ),

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |      |      |      |      |   |  |   _  |   +  |   {  |   }  |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      | **** |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_ortho_4x12(
            KC_TILD , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC , KC_AMPR   , KC_ASTR    , KC_LPRN , KC_RPRN , KC_BSPC ,
            _______ , _______ , _______ , _______ , _______ , _______ , KC_PIPE , KC_UNDS   , KC_PLUS    , KC_LCBR , KC_RCBR , _______ ,
            _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______   , _______    , _______ , _______ , _______ ,
            _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______   , _______    , _______ , _______ , _______
            ),

    /* Adjust (Lower + Raise)
     * ,-----------------------------------------------------------------------------------.
     * | Reset|Qwerty| RGB+ | Bri+ |      |      |      | Vol- | Play | Vol+ | Mute | Game |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      | RGB- | Bri- | MOUS1| MOUS2| MOUSL| MOUSD| MOUSU| MOUSR|      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |BLtogg|BLstep|Colemk|      |      |      | ACC0 | ACC1 | ACC2 |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      | **** |      |      | **** |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_ortho_4x12(
            RESET   , QWERTY  , RGB_VAI , KC_BRIU , _______ , _______ , _______ , KC_VOLD, KC_MPLY, KC_VOLU, KC_MUTE, GAME   ,
            _______ , _______ , RGB_VAD , KC_BRID , KC_BTN1 , KC_BTN2 , KC_MS_L , KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
            _______ , RGB_TOG , RGB_MOD , COLEMAK , _______ , _______ , _______ , KC_ACL0, KC_ACL1, KC_ACL2, _______, _______,
            _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______, _______, _______, _______, _______
            ),

    /* MOV
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      | PgUp | CIns |      |      |      | SIns |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Bksp | Home | End  | Shift| Ctrl |PgDown| Left | Down |  Up  | Right| Del  |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |******| Enter|      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     *
     * - Y outputs Control + Insert
     * - P outputs Shift + Insert
     */
    [_MOV] = LAYOUT_ortho_4x12(
            XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_PGUP , C(KC_INS) , XXXXXXX , XXXXXXX , XXXXXXX  , S(KC_INS) , XXXXXXX,
            KC_BSPC , KC_HOME , KC_END  , KC_LSFT , KC_LCTL , KC_PGDN , KC_LEFT   , KC_DOWN , KC_UP   , KC_RIGHT , KC_DEL    , XXXXXXX,
            _______ , XXXXXXX , XXXXXXX , KC_CAPS , XXXXXXX , XXXXXXX , XXXXXXX   , XXXXXXX , XXXXXXX , XXXXXXX  , XXXXXXX   , _______,
            _______ , _______ , _______ , _______ , XXXXXXX , _______ , _______   , KC_ENT  , _______ , _______  , _______   , _______
            ),

    /* NUM
     * ,-----------------------------------------------------------------------------------.
     * | **** |  F1  |  F2  |  F3  |  F4  |  F5  |      |   7  |   8  |   9  |   *  | Del  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |  F6  |  F7  |  F8  |  F9  |  F10 | Bksp |   4  |   5  |   6  |   +  |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |  F11 |  F12 | Enter|   1  |   2  |   3  |   -  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |   0  |   ,  |   .  |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_NUM] = LAYOUT_ortho_4x12(
            _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , XXXXXXX , KC_7 , KC_8    , KC_9    , KC_PAST , KC_DEL  ,
            XXXXXXX , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_BSPC , KC_4 , KC_5    , KC_6    , KC_PPLS , XXXXXXX ,
            XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_F11  , KC_F12  , KC_ENT  , KC_1 , KC_2    , KC_3    , KC_PMNS , XXXXXXX ,
            XXXXXXX , XXXXXXX , XXXXXXX , _______ , XXXXXXX , XXXXXXX , _______ , KC_0 , KC_COMM ,KC_DOT   , XXXXXXX , XXXXXXX
            )

};

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
            break;
        case GAME:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAME);
            }
            return false;
            break;
    }
    return true;
}
