/*
Copyright 2019 I/O Keyboards <hello@iokeyboards.eu>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN,
    _MEDIA,
    _DEB
};
enum custom_keycodes{

  nGesc = SAFE_RANGE

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
        case LSFT_T(RALT(KC_7)):
            if (record->tap.count && record->event.pressed) {
                tap_code16(RALT(KC_7)); // Send RALT(KC_7) on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case LCTL_T(RALT(KC_8)):
            if (record->tap.count && record->event.pressed) {
                tap_code16(RALT(KC_8)); // Send RALT(KC_8) on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case RSFT_T(RALT(KC_0)):
            if (record->tap.count && record->event.pressed) {
                tap_code16(RALT(KC_0)); // Send RALT(KC_0) on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case LALT_T(RALT(KC_9)):
            if (record->tap.count && record->event.pressed) {
                tap_code16(RALT(KC_9)); // Send RALT(KC_9) on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case nGesc:
            if( get_mods() && MOD_BIT(KC_LSFT)) {
                unregister_code(KC_LSFT);
                SEND_STRING(SS_TAP(X_GRV));
                register_code(KC_LSFT);
            } else {
                SEND_STRING(SS_TAP(X_ESC));
            }
            return false;
            break;
        }
    return true;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_all(
  KC_F1,  nGesc,            KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_MINS, KC_EQL,            KC_BSPC, KC_BSPC,   KC_INS,
  KC_F2,  KC_TAB,             KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,    KC_LBRC, KC_RBRC,           KC_BSLS,           KC_DEL,
  KC_F3,  KC_CAPS,            KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN, KC_QUOT, KC_BSLS,           KC_ENT,            TG(1),
  KC_F4,  LSFT_T(RALT(KC_7)), KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, RSFT_T(RALT(KC_0)),KC_UP,   AC_TOGG,
  KC_LGUI,LCTL_T(RALT(KC_8)), LALT_T(RALT(KC_9)),                          KC_SPC,                      	       KC_RALT, MO(2),                     KC_LEFT, KC_DOWN, KC_RGHT),

[_FN] = LAYOUT_all(
  KC_F6,  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,  TG(0),
  KC_F7,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           XXXXXXX,
  KC_F8,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           TG(2),
  KC_F9,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           MO(3),
  KC_F10, _______, _______,                                     _______,                       	    _______, _______,          _______, _______, _______),

[_MEDIA] = LAYOUT_all(
  KC_WHOM, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  TG(0),
  KC_CALC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           TG(1),
  KC_MAIL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           XXXXXXX,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU,           MO(3),
  _______, _______, _______,                                     KC_MPLY,                      	     MO(3),   _______,          _______, KC_VOLD, _______),

[_DEB] = LAYOUT_all(
  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  QK_RBT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX,                            XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX)

};
