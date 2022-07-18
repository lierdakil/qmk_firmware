/* Copyright 2018 'Masayuki Sunahara'
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

enum layers {BASE, LOWER, UPPER, CTR, NAV};

#define MC_A RGUI_T(KC_A)
#define MC_S LALT_T(KC_S)
#define MC_D LSFT_T(KC_D)
#define MC_F LCTL_T(KC_F)
#define MC_J LCTL_T(KC_J)
#define MC_K LSFT_T(KC_K)
#define MC_L LALT_T(KC_L)
#define MC_SCLN RGUI_T(KC_SCLN)
#define LWR LT(LOWER,KC_DEL)
#define UPR LT(UPPER,KC_SPC)
#define ENT LT(NAV,KC_ENT)
#define BSPC LSFT_T(KC_BSPC)
#define SPC RSFT_T(KC_SPC)

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x7_4(
        KC_EQL , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_LPRN,    KC_RPRN, KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS,
        KC_TAB , MC_A   , MC_S   , MC_D   , MC_F   , KC_G   , KC_LBRC,    KC_RBRC, KC_H   , MC_J   , MC_K   , MC_L   , MC_SCLN, KC_QUOT,
        KC_GRV , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_CAPS,    ENT    , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_BSLS ,
                                   KC_LEFT, KC_RGHT, BSPC   , LWR    ,    UPR    , SPC    , KC_UP  , KC_DOWN
    ),
    [LOWER] = LAYOUT_split_3x7_4(
        KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_HOME,    KC_END , KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        _______, _______, _______, _______, _______, _______, KC_PGUP,    KC_PGDN, _______, _______, _______, KC_MINS, KC_EQL , _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______,    MO(CTR), _______, _______, _______
    ),
    [UPPER] = LAYOUT_split_3x7_4(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_HOME,    KC_END , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
        _______, _______, _______, _______, _______, _______, KC_PGUP,    KC_PGDN, _______, _______, _______, KC_MINS, KC_EQL , _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, MO(CTR), _______,    _______, _______, _______, _______
    ),
    [CTR] = LAYOUT_split_3x7_4(
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,    KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                                   RESET  , _______, _______, _______,    _______, _______, _______, _______
    ),
    [NAV] = LAYOUT_split_3x7_4(
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, KC_PGUP, KC_UP,   KC_PGDN, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, KC_HOME, KC_END,  _______, _______, _______,
                                   _______, _______, _______, _______,    _______, _______, _______, _______
    )
    // [NAV] = LAYOUT_split_3x7_4(
    //     _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    //                                _______, _______, _______, _______,    _______, _______, _______, _______
    // )
};
