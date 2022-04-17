/* Copyright 2021 DWT
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

// Defines names for use in layer keycodes and the keymap
enum layer_names { _BASE, _FN };

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes
{
    LCBRC = SAFE_RANGE,
    RCBRC,
    CK_EXC,
    CK_AT,
    CK_HASH,
    CK_DOLLAR,
    CK_PERC,
    CK_AMP,
    CK_AST,
    RDP_GTFO
};

#define ____ KC_TRNS

#define _BASE 0
#define _RAISE 1
#define _LOWER 2
#define _GAME 3

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define GAME TG(_GAME)

// so ill still need basic things like the apostrophe, all types of brackets, F keys, and operators
// print screen
// scroll lock?
// insert
// the thing to bring up the context menu maybe?
// how about some slick media controls?

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_6x6(
        KC_ESC,  KC_1, KC_2, KC_3, KC_4, KC_5,                        KC_6, KC_7, KC_8,     KC_9,   KC_0,    KC_BSPC,
        KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,                        KC_Y, KC_U, KC_I,     KC_O,   KC_P,    KC_BSLASH,
        ____,    KC_A, KC_S, KC_D, KC_F, KC_G,    KC_DEL,      GAME,  KC_H, KC_J, KC_K,     KC_L,   KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,   KC_LGUI,      ____,  KC_N, KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSHIFT,
                                                    ____,      ____, 
                         KC_LCTRL, KC_LALT, LOWER, RAISE,      KC_LCTRL,  KC_SPC, KC_ENTER, ____
    ),

    [_RAISE] = LAYOUT_6x6(
        KC_PAUSE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                    KC_F6,   KC_F7,   KC_F8,   KC_F9, ____, ____,
        ____,      ____,  ____,  ____,  ____,  ____,                  KC_PGUP, KC_HOME,   KC_UP,  KC_END, ____, ____,
        ____,      ____,  ____,  ____,  ____,  ____, ____,      ____, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, ____, ____,
        ____,      ____,  ____,  ____,  ____,  ____, ____,      ____,    ____,    ____,    ____,    ____, ____, ____,
                                                     ____,      ____,  
                                 ____,  ____,  ____, ____,      ____,    ____,    ____,    ____
    ),

    [_LOWER] = LAYOUT_6x6(
        ____,  CK_EXC,   CK_AT, CK_HASH, CK_DOLLAR, CK_PERC,                   ____,  CK_AMP,  CK_AST,    ____,    ____, KC_DEL,
        ____,    ____,  KC_F10,  KC_F11,    KC_F12,    ____,                   ____, KC_LPRN, KC_RPRN,  KC_GRV, KC_TILD, ____,
        ____, KC_UNDS, KC_PLUS, KC_MINS,    KC_EQL,    ____, ____,       ____, ____,   LCBRC,   RCBRC, KC_LBRC, KC_RBRC, ____,
        ____,    ____,    ____,    ____,      ____,    ____, ____,       ____, ____,    ____,    ____,    ____,    ____, ____,
                                                             ____,       ____,  
                                   ____,      ____,    ____, ____,       ____, ____,    ____,  ____
    ),

    [_GAME] = LAYOUT_6x6(
        ____, ____, ____, ____,   ____,    ____,                       ____, ____, ____, ____, ____, ____,
        ____, ____, ____, ____,   ____,    ____,                       ____, ____, ____, ____, ____, ____,
        ____, ____, ____, ____,   ____,    ____,     ____,       ____, ____, ____, ____, ____, ____, ____,
        ____, ____, ____, ____,   ____,    ____,     ____,       ____, ____, ____, ____, ____, ____, ____,
                                                     ____,       ____,  
                          ____, KC_SPC, KC_LALT, KC_ENTER,       ____, ____, ____,  ____
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case LCBRC:
                SEND_STRING("{");
                break;
            case RCBRC:
                SEND_STRING("}");
                break;
            case CK_EXC:
                SEND_STRING("!");
                break;
            case CK_AT:
                SEND_STRING("@");
                break;
            case CK_HASH:
                SEND_STRING("#");
                break;
            case CK_DOLLAR:
                SEND_STRING("$");
                break;
            case CK_PERC:
                SEND_STRING("\%");
                break;
            case CK_AMP:
                SEND_STRING("&");
                break;
            case CK_AST:
                SEND_STRING("*");
                break;
            // case RDP_GTFO:
            //     SEND_STRING(SS_LCTL(SS_LALT(48)));
            //     break;
        }
    }
    return true;
}
