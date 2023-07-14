/* Copyright 2021 @ Keychron (https://www.keychron.com)
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
#include "action_code.h"
#include "action_util.h"
#include "quantum.h"

#include QMK_KEYBOARD_H
#include "lib/keycodes.h"
#include <stdio.h>

#ifdef TAP_DANCE_ENABLE
#    include "lib/tapdance.h"
#endif
#ifdef COMBO_ENABLE
#    include "g/keymap_combo.h"
#endif

bool is_gui_tab_active = false; // ADD this near the begining of keymap.c
uint16_t alt_tab_timer = 0;     // we will be using them soon.
// END ALT TAB Timer
uint16_t timer;

// clang-format off

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_69(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  MOD_Q,   LAY_W,    LAY_F,    KC_R,   MOD_B,   MOD_J,     KC_L,   LAY_U,   LAY_Y,    MINS,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        KC_CAPS, MOD_A,   MOD_R,    MOD_S,   MOD_T,   MOD_G,             MOD_M,   MOD_N,   MOD_E,   MOD_I,       MOD_O,  KC_QUOT,  KC_ENT,           KC_HOME,
        KC_LSFT,           MOD_Z,   MOD_X,   MOD_C,   MOD_D,   MOD_V,    MOD_V,   MOD_K,   MOD_H,MOD_COMM,     MOD_DOT, MOD_SLSH,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LOPT,  KC_LCMD,           BSPC,              ENT,     OSMS,         SPC,            TAB,            KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_BASE] = LAYOUT_ansi_69(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        KC_CAPS, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,              KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,           KC_HOME,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,     KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LWIN,  KC_LALT,           KC_SPC,           ENT, OSMS,         KC_SPC,            KC_RALT,            KC_LEFT, KC_DOWN, KC_RGHT),

    [_SYM] = LAYOUT_ansi_69(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        RGB_TOG, TD_TILDA,  KC_SLSH,  KC_COLN, KC_PLUS,      WQ, KC_PIPE,  KC_AMPR, KC_ASTR, KC_QUES, KC_MINS,  _______,  _______,  _______,          _______,
        KC_PIPE,    KC_AT, KC_PERC,  KC_EXLM,  KC_EQL, KC_PIPE,           KC_COLN,  KC_EQL,  KC_DQT, KC_UNDS,  KC_SCLN,  KC_BSLS,  _______,          _______,
        _______,           _______,      GRV, KC_HASH, KC_BSLS,TD_UPDIR, TD_UPDIR, KC_CIRC,  KC_DLR,  KC_DOT,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),

    [_BRK] = LAYOUT_ansi_69(
        _______,_______,  _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          RGB_TOG,
        KC_MINS,   KC_LT,    KC_GT,  KC_LCBR, KC_RCBR, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, _______,  KC_LPRN,  KC_RPRN,   KC_LT,   KC_GT,           _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,           _______,  KC_LBRC, KC_RBRC, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),

    [_NAV] = LAYOUT_ansi_69(
        _______,_______,  _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          RGB_TOG,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, RGB_RMOD, RGB_VAD,  RGB_HUD, RGB_SAD, RGB_SPD,           _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),

    [_NUM] = LAYOUT_ansi_69(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        _______, _______,  _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, _______,  _______,  _______, _______, _______,           _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),

    [_FUNC] = LAYOUT_ansi_69(
        KC_TILD, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          _______,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, RGB_RMOD, RGB_VAD,  RGB_HUD, RGB_SAD, RGB_SPD,           _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),

    [_ADJUST] = LAYOUT_ansi_69(
        KC_TILD, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          _______,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, RGB_RMOD, RGB_VAD,  RGB_HUD, RGB_SAD, RGB_SPD,           _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______)
};

// clang-format on
#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_SYM]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [_BRK]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [_NAV]   = {ENCODER_CCW_CW(_______, _______)},
    [_NUM]   = {ENCODER_CCW_CW(_______, _______)},
    [_FUNC]   = {ENCODER_CCW_CW(_______, _______)},
    [_ADJUST]   = {ENCODER_CCW_CW(_______, _______)}
};
#endif // ENCODER_MAP_ENABLE
