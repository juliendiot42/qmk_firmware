/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

//#define SSD1306OLED

#define USE_SERIAL_PD2

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200

#ifdef RGBLIGHT_ENABLE
#    undef RGBLED_NUM
#    define RGBLIGHT_ANIMATIONS
#    define RGBLED_NUM       54 // Number of LEDs
// I had to redefine GBLED_SPLIT in crkbd/rev1/config.h
#    define RGBLIGHT_LAYERS
#    define RGBLIGHT_DEFAULT_HUE 0
//#    define RGBLIGHT_DEFAULT_SAT UINT8_MAX
#    define RGBLIGHT_DEFAULT_SAT 0
#    define RGBLIGHT_LIMIT_VAL 120
#    define RGBLIGHT_HUE_STEP 5
#    define RGBLIGHT_SAT_STEP 5
#    define RGBLIGHT_VAL_STEP 5
#endif

#define OLED_FONT_H "keyboards/crkbd/keymaps/juliendiot42/glcdfont.c"
#define OLED_DISABLE_TIMEOUT
