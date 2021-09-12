/**
 * Copyright 2021 Rob Hilgefort <@rjhilgefort>
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
#include "version.h"


enum custom_layers {
    BASEMAC, // Base Mac Layer
    BASELNX, // Base Linux Layer
    SYMB,    // Symbols Layer
    MANMAC,  // Media Numbers Mac Layer
    MANLNX,  // Media Numbers Linux Layer
    EXA,     // Extra Layer
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  VRSN,
};

#define ALT_ESC ALT_T(KC_ESC)
#define CTL_ESC CTL_T(KC_ESC)
#define GUI_ESC GUI_T(KC_ESC)
#define HYPER LGUI(LSFT(KC_LALT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Base (Mac)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ct/Esc |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |Ctrl/;|   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Shift  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |Ctrl//| Enter  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |Shift | Tab  | ↑ L3 |Alt/Ec|                                       | ↑ L2 |Hyper |   '  |Enter |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------+------+------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | LGui | Bksp |------|       |------|  Bksp  | Spc  |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASEMAC] = LAYOUT_ergodox(
    // left hand
    _______, _______, _______, _______,    _______, _______, _______,
    KC_TAB,  KC_Q,    KC_W,    KC_E,       KC_R,    KC_T,    _______,
    CTL_ESC, KC_A,    KC_S,    KC_D,       KC_F,    KC_G,
    KC_LSFT, KC_Z,    KC_X,    KC_C,       KC_V,    KC_B,    _______,
    _______, KC_LSFT, KC_TAB,  MO(MANMAC), ALT_ESC,
                                                    _______, _______,
                                                             _______,
                                           KC_LGUI, KC_BSPC, _______,
    // right hand
    _______, _______, _______,  _______, _______, _______,        _______,
    _______, KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,           KC_BSPC,
             KC_H,    KC_J,     KC_K,    KC_L,    CTL_T(KC_SCLN), KC_QUOT,
    _______, KC_N,    KC_M,     KC_COMM, KC_DOT,  CTL_T(KC_SLSH), KC_ENTER,
                      MO(SYMB), HYPER,   KC_QUOT, KC_ENTER,       _______,
    _______, _______,
    _______,
    _______, KC_BSPC, KC_SPC
),

/* Keymap 1: Base (Linux)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ct/Esc |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |Ctrl/;|   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Shift  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |Ctrl//| Enter  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |Shift | Tab  | ↑ L4 |Gui/Ec|                                       | ↑ L2 | Hyper|   '  |Enter |      |
 *   `-----------------------------------'                                      `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------+------+------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | Ctrl | Bksp |------|       |------|  Bksp  | Spc  |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASELNX] = LAYOUT_ergodox(
    // left hand
    _______, _______, _______, _______,    _______, _______, _______,
    KC_TAB,  KC_Q,    KC_W,    KC_E,       KC_R,    KC_T,    _______,
    ALT_ESC, KC_A,    KC_S,    KC_D,       KC_F,    KC_G,
    KC_LSFT, KC_Z,    KC_X,    KC_C,       KC_V,    KC_B,    _______,
    _______, KC_LSFT, KC_TAB,  MO(MANLNX), GUI_ESC,
                                                    _______, _______,
                                                             _______,
                                          KC_LCTRL, KC_BSPC, _______,
    // right hand
    _______, _______, _______,  _______, _______, _______,        _______,
    _______, KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,           KC_BSPC,
             KC_H,    KC_J,     KC_K,    KC_L,    CTL_T(KC_SCLN), KC_QUOT,
    _______, KC_N,    KC_M,     KC_COMM, KC_DOT,  CTL_T(KC_SLSH), KC_ENTER,
                      MO(SYMB), HYPER,   KC_QUOT, KC_ENTER,       _______,
    _______, _______,
    _______,
    _______, KC_BSPC, KC_SPC
),

/* Keymap 2: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   \  |   /  |   [  |   ]  |   ~  |      |           |      |   |  |   =  |   +  |   -  |   _  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   {  |   }  |   (  |   )  |   `  |------|           |------|   ←  |   ↓  |   ↑  |   →  |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   !  |   @  |   #  |   $  |   %  |      |           |      |   ^  |   &  |   *  |   (  |   )  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      | ↑ L5 |      |                                       | TRNS |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------+------+------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      | Del  |------|       |------| Del  |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
    // left hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, KC_BSLS, KC_SLSH, KC_LBRC, KC_RBRC, KC_TILD, _______,
    _______, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_GRV,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,
    _______, _______, _______, MO(EXA), _______,
                                                 _______, _______,
                                                          _______,
                                        _______, KC_DEL,  _______,
    // right hand
    _______, _______, _______, _______, _______,  _______, _______,
    _______, KC_PIPE, KC_EQL,  KC_PLUS, KC_MINS,  KC_UNDS, _______,
             KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
    _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,  KC_RPRN, _______,
                      KC_TRNS, _______, _______,  _______, _______,
    _______, _______,
    _______,
    _______, KC_DEL,  _______
),

/* Keymap 3: Media & Numbers (MAC)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |Scrn -| Vol+ |Scrn +|      |      |           |      |      |   7  |   8  |   9  |   *  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |VolMut|Trak ←|Ply/Ps|Trak →|      |------|           |------|      |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      | Vol- |      |      |      |           |      |      |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | TRNS |      |                                       | ↑ L5 |   0  |   .  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------+------+------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |   0  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MANMAC] = LAYOUT_ergodox(
    // left hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_BRMD, KC_VOLU, KC_BRMU, _______, _______,
    _______, KC_MUTE, KC_MRWD, KC_MPLY, KC_MFFD, _______,
    _______, _______, _______, KC_VOLD, _______, _______, _______,
    _______, _______, _______, KC_TRNS, _______,
                                                 _______, _______,
                                                          _______,
                                        _______, _______, _______,
    // right hand
    _______,  _______, _______, _______, _______, _______, _______,
    _______,  _______,    KC_7,    KC_8,    KC_9, KC_ASTR, _______,
              _______,    KC_4,    KC_5,    KC_6, KC_PLUS, _______,
    _______,  _______,    KC_1,    KC_2,    KC_3, KC_BSLS, _______,
                       MO(EXA),    KC_0,  KC_DOT,  KC_EQL, _______,
    _______, _______,
    _______,
    _______, _______, KC_0
),

/* Keymap 4: Media & Numbers (Linux)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |Scrn -| Vol+ |Scrn +|      |      |           |      |      |   7  |   8  |   9  |   *  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |VolMut|Trak ←|Ply/Ps|Trak →|      |------|           |------|      |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      | Vol- |      |      |      |           |      |      |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | TRNS |      |                                       | ↑ L5 |   0  |   .  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------+------+------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |   0  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MANLNX] = LAYOUT_ergodox(
    // left hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_BRID, KC_VOLU, KC_BRIU, _______, _______,
    _______, KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT, _______,
    _______, _______, _______, KC_VOLD, _______, _______, _______,
    _______, _______, _______, KC_TRNS, _______,
                                                 _______, _______,
                                                          _______,
                                        _______, _______, _______,
    // right hand
    _______,  _______, _______, _______, _______, _______, _______,
    _______,  _______,    KC_7,    KC_8,    KC_9, KC_ASTR, _______,
              _______,    KC_4,    KC_5,    KC_6, KC_PLUS, _______,
    _______,  _______,    KC_1,    KC_2,    KC_3, KC_BSLS, _______,
                       MO(EXA),    KC_0,  KC_DOT,  KC_EQL, _______,
    _______, _______,
    _______,
    _______, _______, KC_0
),

/* Keymap 5: Extra
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | → L0 | → L1 |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| Home | PGDN | PGUP | End  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | TRNS |      |                                       | TRNS |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------+------+       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[EXA] = LAYOUT_ergodox(
    // left hand
    _______, _______,     _______,     _______, _______, _______, _______,
    _______, DF(BASEMAC), DF(BASELNX), _______, _______, _______, _______,
    _______, _______,     _______,     _______, _______, _______,
    _______, _______,     _______,     _______, _______, _______, _______,
    _______, _______,     _______,     KC_TRNS, _______,
                                                         _______, _______,
                                                                  _______,
                                                _______, _______, _______,
    // right hand
    _______,  _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______, _______,
              KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
    _______,  _______, _______, _______, _______, _______, _______,
                       KC_TRNS, _______, _______, _______, _______,
    _______, _______,
    _______,
    _______, _______, _______
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
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_3_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            break;
        default:
            // none
            break;
    }

};

/*
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------+------+       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
/*
 * [EXTRA] = LAYOUT_ergodox(
 *     // left hand
 *     _______, _______, _______, _______, _______, _______, _______,
 *     _______, _______, _______, _______, _______, _______, _______,
 *     _______, _______, _______, _______, _______, _______,
 *     _______, _______, _______, _______, _______, _______, _______,
 *     _______, _______, _______, _______, _______,
 *                                                  _______, _______,
 *                                                           _______,
 *                                         _______, _______, _______,
 *     // right hand
 *     _______,  _______, _______, _______, _______, _______, _______,
 *     _______,  _______, _______, _______, _______, _______, _______,
 *               _______, _______, _______, _______, _______, _______,
 *     _______,  _______, _______, _______, _______, _______, _______,
 *     _______,  _______, _______, _______, _______, _______, _______,
 *                        _______, _______, _______, _______, _______,
 *     _______, _______,
 *     _______,
 *     _______, _______, _______
 * ),
 */
