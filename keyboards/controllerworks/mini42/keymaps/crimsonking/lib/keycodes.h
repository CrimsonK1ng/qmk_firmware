#pragma once

// clang-format off

#include QMK_KEYBOARD_H
#include "layers.h"

// MACROS
enum custom_keycodes {
  // some custom keys
  OSX = SAFE_RANGE,
  // LLOCK,
  WQ,
  CMDGRV,
  CMDTAB,
  ALTTAB,
};

// One shot mods
#define OSMS OSM(MOD_LSFT)
#define OSMC OSM(MOD_LCTL)
#define OSMG OSM(MOD_LGUI)
#define OSMA OSM(MOD_LALT)
#define OSMH OSM(MOD_HYPR)
#define OSMM OSM(MOD_MEH)

#define OSMP OSM(MOD_LGUI | MOD_LCTL)
#define OSMCS OSM(MOD_LSFT | MOD_LCTL)
#define OSMGS OSM(MOD_LSFT | MOD_LGUI)

// TOP RIGHT
#define MOD_J KC_J
#define LAY_U KC_U
#define LAY_Y LT(_BRK, KC_Y)
#define MINS  HYPR_T(KC_MINS)
// MIDDLE
#define MOD_M     RSFT_T(KC_M)
#define MOD_N     RGUI_T(KC_N)
#define MOD_E     RCTL_T(KC_E)
#define MOD_I     LALT_T(KC_I)
#define MOD_O     LT(_SYM, KC_O)
#define QUOT      LT(_BRK, KC_QUOT)
// BOTTOM
#define MOD_SLSH  RGUI_T(KC_SLSH)
#define MOD_DOT   MEH_T(KC_DOT)
#define MOD_COMM  KC_COMM
#define MOD_H     KC_H
#define MOD_K     KC_K
// THUMBS
//      OSMS
#define SPC    LT(_SYM, KC_SPC)//LT(0, KC_SPC)// RCTL_T(KC_SPC)
#define TAB    LT(_NUM, KC_TAB)
// END RIGHT

// TOP LEFT
#define MOD_Q HYPR_T(KC_Q)
#define LAY_W LT(_NAV, KC_W)
#define LAY_F LT(_NUM, KC_F)
#define MOD_B KC_B
// MIDDLE
#define MOD_G   LSFT_T(KC_G)
#define MOD_T   LGUI_T(KC_T)
#define MOD_S   LCTL_T(KC_S)
#define MOD_R   LALT_T(KC_R)
#define MOD_A   LT(_SYM, KC_A)
#define MODLAY  LT(_NAV, KC_BSPC) // outer column 
// BOTTOM
#define NUM_DEL LT(_NUM, KC_DEL)
#define MOD_Z   LGUI_T(KC_Z)
#define MOD_X   MEH_T(KC_X)
#define MOD_C   KC_C
#define MOD_D   KC_D
#define MOD_V   KC_V
// THUMBS
#define COLN   LT(_FUNC, KC_COLN)
#define BSPC   LT(_SYM, KC_BSPC)
#define ENT    LT(_NUM, KC_ENT)
#define SYMO   OSL(_SYM)
// END LEFT

// ----------------------------------

// Stuff
#define GRV     LT(0, KC_GRV)
#define ADJUST  LT(_ADJUST, KC_ESC)
#define FBSPC   LT(_FUNC, KC_BSPC)


// SPECIAL THUMBS
#define C_BSP  C(KC_BSPC)
#define A_BSP  A(KC_BSPC)
#define G_ENT  LGUI_T(KC_ENT)
#define S_ENT  LSFT_T(KC_ENT)
#define C_ENT  LCTL_T(KC_ENT)

// NUMBERS
#define TWO  MT(MOD_LCTL | MOD_LGUI, KC_2)
#define POPZED  MT(MOD_LCTL | MOD_LGUI, KC_0)
#define B_PERC LT(_BRK, KC_PERC)


// shortcuts
#define NXTTAB C(KC_TAB)
#define PRVTAB S(C(KC_TAB))

#define SLASH LT(_FUNC, KC_SLSH)
