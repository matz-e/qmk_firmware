/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

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

#define DEBUG_ACTION

// #include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xBEEF
#define PRODUCT_ID      0x8080
#define DEVICE_VER      0x0001
#define MANUFACTURER    Me
#define PRODUCT         "The Happy Planck Keyboard"
#define DESCRIPTION     A compact ortholinear keyboard

/* in python2: list(u"whatever".encode('utf-16-le')) */
/*   at most 32 characters or the ugly hack in usb_main.c borks */
#define USBSTR_MANUFACTURER    'T', '\x00', 'M', '\x00', 'K', '\x00', ' ', '\x00'
#define USBSTR_PRODUCT         'I', '\x00', 'n', '\x00', 'f', '\x00', 'i', '\x00', 'n', '\x00', 'i', '\x00', 't', '\x00', 'y', '\x00', ' ', '\x00', 'k', '\x00', 'e', '\x00', 'y', '\x00', 'b', '\x00', 'o', '\x00', 'a', '\x00', 'r', '\x00', 'd', '\x00', '/', '\x00', 'T', '\x00', 'M', '\x00', 'K', '\x00'

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

/* Planck PCB default pin-out */
// #define MATRIX_ROW_PINS { D0, D5, B5, B6 }
// #define MATRIX_COL_PINS { F1, F0, B0, C7, F4, F5, F6, F7, D4, D6, B4, D7 }
// #define UNUSED_PINS

#define AUDIO_VOICES
#define C6_AUDIO

#define BACKLIGHT_PIN B7

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
#define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION
#define RGB_DI_PIN TEENSY_PIN26
#define RGBLED_NUM 10
#define RGBLIGHT_ANIMATIONS
