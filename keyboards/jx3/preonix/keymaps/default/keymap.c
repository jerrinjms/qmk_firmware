/* Copyright 2023 Jerrin James
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

/* defines names for use in layer keycodes and the keymap */
enum layers {
    _DEFAULT = 0,
    _LOWER,
    _RAISE
};


 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
    * ,------------------------------------------------------------------------------------------------.
    * |   1  |   2  |   3  |   4  |   5  |   6  |            |   7  |   8  |   9  |   0  |  -/_ |  =/+ |
    * |------+------+------+------+------+------+-------------------+------+------+------+------+------|
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |            |   Y  |   U  |   I  |   O  |   P  | Bksp |
    * |------+------+------+------+------+------+-------------------+------+------+------+------+------|
    * | Esc  |   A  |   S  |   D  |   F  |   G  |            |   H  |   J  |   K  |   L  |   ;  |  "   |
    * |------+------+------+------+------+------+-------------------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   C  |   V  |   B  |            |   N  |   M  |   ,  |   .  |   /  | Enter|
    * |------+------+------+------+------+------+-------------------+------+------+------+------+------|
    * | Ctrl | GUI  |  Alt | CapL |Lower |Space |            |Space |Raise | Left | Down |  Up  |Right |
    * `------------------------------------------------------------------------------------------------'
    */

    [_DEFAULT] = LAYOUT_ortho_5x12(
        KC_1,     KC_2,     KC_3,     KC_4,     KC_5,   KC_6,    KC_7,    KC_8,   KC_9,     KC_0,     KC_MINS, KC_EQL,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,   KC_T,    KC_Y,    KC_U,   KC_I,     KC_O,     KC_P,    KC_BSPC,
        QK_GESC,  KC_A,     KC_S,     KC_D,     KC_F,   KC_G,    KC_H,    KC_J,   KC_K,     KC_L,     KC_SCLN, KC_QUOT,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,   KC_B,    KC_N,    KC_M,   KC_COMM,  KC_DOT,   KC_SLSH, SC_SENT,
        KC_LCTL,  KC_LGUI,  KC_LALT,  KC_CAPS,  TT(1),  KC_SPC,  KC_SPC,  TT(2),  KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT
    ),

    /* Lower
    * ,------------------------------------------------------------------------------------------------.
    * |  Esc |   -  |   -  |   -  |   -  |   -  |            | Num L|   /  |   *  |   -  |   -  | PtSn |
    * |------+------+------+------+------+------+-------------------+------+------+------+------+------|
    * |   -  |   -  |   W  |   E  |   -  |   -  |            |   7  |   8  |   9  |   +  |   -  |  Del |
    * |------+------+------+------+------+------+-------------------+------+------+------+------+------|
    * |   -  |   A  |   S  |   D  |   F  |   -  |            |   4  |   5  |   6  |   ,  |   -  |  -   |
    * |------+------+------+------+------+------+-------------------+------+------+------+------+------|
    * | Shift|   -  |   -  |   -  |   -  |   -  |            |   1  |   2  |   3  |   =  |  Up  | Enter|
    * |------+------+------+------+------+------+-------------------+------+------+------+------+------|
    * | Ctrl |   -  |   -  |  Alt | Lower|   -  |            |   0  |   .  | Enter| Left | Down |Right |
    * `------------------------------------------------------------------------------------------------'
    */

    [_LOWER] = LAYOUT_ortho_5x12(
        KC_ESC,   KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,  KC_NUM, KC_PSLS, KC_PAST,   KC_PMNS,  KC_NO,    KC_PSCR,
        KC_NO,    KC_NO,  KC_W,   KC_E,     KC_NO,    KC_NO,  KC_P7,  KC_P8,   KC_P9,     KC_PPLS,  KC_NO,    KC_DEL,
        KC_NO,    KC_A,   KC_S,   KC_D,     KC_F,     KC_NO,  KC_P4,  KC_P5,   KC_P6,     KC_PCMM,  KC_NO,    KC_NO,
        KC_LSFT,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,  KC_P1,  KC_P2,   KC_P3,     KC_PEQL,  KC_UP,    KC_PENT,
        KC_LCTL,  KC_NO,  KC_NO,  KC_LALT,  KC_TRNS,  KC_NO,  KC_P0,  KC_PDOT,  KC_PENT,  KC_LEFT,  KC_DOWN,  KC_RGHT
    ),

    /* Raise
    * ,------------------------------------------------------------------------------------------------.
    * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |            |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
    * |------+------+------+------+------+------+-------------------+------+------+------+------+------|
    * | Mute | PtSn | ScLk | Pause|   -  |   -  |            |   -  |   -  |   -  |   -  |   -  |   -  |
    * |------+------+------+------+------+------+-------------------+------+------+------+------+------|
    * | Vol+ |  Ins | Home | PgUp |   -  |   -  |            |   -  |   -  |   -  |   -  |   -  |   -  |
    * |------+------+------+------+------+------+-------------------+------+------+------+------+------|
    * | Vol- | Del  |  End | PgDn |   -  |   -  |            |   -  |   -  |   -  |   -  |   -  |   -  |
    * |------+------+------+------+------+------+-------------------+------+------+------+------+------|
    * | Stop |   -  |   -  |   -  |   -  |  -   |            |   -  | Raise|   -  |   -  |   -  |   -  |
    * `------------------------------------------------------------------------------------------------'
    */

    [_RAISE] = LAYOUT_ortho_5x12(
        KC_F1,    KC_F2,   KC_F3,   KC_F4,    KC_F5,  KC_F6,  KC_F7,  KC_F8,    KC_F9,  KC_F10,  KC_F11,  KC_F12,
        KC_MUTE,  KC_PSCR, KC_SCRL, KC_PAUS,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,  KC_NO,   KC_NO,   KC_NO,
        KC_VOLU,  KC_INS,  KC_HOME, KC_PGUP,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,  KC_NO,   KC_NO,   KC_NO,
        KC_VOLD,  KC_DEL,  KC_END,  KC_PGDN,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,  KC_NO,   KC_NO,   KC_NO,
        KC_MSTP,  KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_TRNS,  KC_NO,  KC_NO,   KC_NO,   KC_NO
    )

};
