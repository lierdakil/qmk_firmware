#include "bm40hsrgb.h"

enum layers {BASE, LOWER, UPPER, CTRL, NAV, NUMS};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT_planck_mit(
        KC_EQL,  KC_Q, KC_W,   KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS,
        KC_TAB,  RGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G, KC_H, LCTL_T(KC_J), LSFT_T(KC_K), LALT_T(KC_L), RGUI_T(KC_SCLN), KC_QUOT,
        KC_LGUI, KC_Z, KC_X,   KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RCTL,
        KC_SLCK, KC_CAPS, KC_GRV, MO(LOWER), LSFT_T(KC_BSPC), LT(NAV,KC_ENT), RSFT_T(KC_SPC), MO(UPPER), KC_LBRC, KC_RBRC, TG(NUMS)
        ),
	[LOWER] = LAYOUT_planck_mit(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,       KC_ASTR,       KC_LPRN, KC_RPRN, KC_BSPC,
        KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,       KC_PLUS,       KC_LCBR, KC_RCBR, KC_PIPE,
        KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  LSFT(KC_NUHS), LSFT(KC_NUBS), KC_HOME, KC_END,  KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(CTRL),      KC_TRNS,       KC_TRNS, KC_TRNS
        ),
	[UPPER] = LAYOUT_planck_mit(
        KC_GRV,  KC_1,    KC_2,    KC_3,     KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_DEL,  KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
        KC_TRNS, KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, MO(CTRL), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),
	[CTRL] = LAYOUT_planck_mit(
        KC_TRNS, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),
	[NAV] = LAYOUT_planck_mit(
    /*  0        1        2        3        4        5        6        7        8        9        10       11       */
        KC_ESC,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_UP,   KC_PGDN, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_END,  KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),
	[NUMS] = LAYOUT_planck_mit(
    /*  0        1        2      3      4        5      6        7        8        9        10     11       */
        KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NLCK, KC_P7, KC_P8,   KC_P9,   KC_PAST, KC_PSLS, KC_NO, KC_NO,
        KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,   KC_P4, KC_P5,   KC_P6,   KC_PPLS, KC_PMNS, KC_NO, KC_NO,
        KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,   KC_P1, KC_P2,   KC_P3,   KC_PEQL, KC_NO,   KC_NO, KC_NO,
        KC_PSCR, KC_PAUS, KC_NO, KC_NO, KC_NO,   KC_P0       ,   KC_PDOT, KC_PENT, KC_NO,   KC_NO, KC_TRNS
        )
};


//layer led colors
#define RC(r,c) (r*12+c)
#define SETC(r,c,col) rgb_matrix_set_color(RC(r,c),col)

void rgb_matrix_indicators_user(void) {
    if (IS_LAYER_ON(NAV)) {
        SETC(0,0,RGB_RED);
        SETC(0,8,RGB_GOLD);
        SETC(1,7,RGB_GOLD);
        SETC(1,8,RGB_GOLD);
        SETC(1,9,RGB_GOLD);
        SETC(2,7,RGB_ORANGE);
        SETC(2,8,RGB_ORANGE);
        SETC(0,7,RGB_CORAL);
        SETC(0,9,RGB_CORAL);
    }
    else if(IS_LAYER_ON(NUMS)) {
        SETC(0,4,RGB_ORANGE);
        SETC(0,5,RGB_GOLD);
        SETC(0,6,RGB_GOLD);
        SETC(0,7,RGB_GOLD);
        SETC(1,5,RGB_GOLD);
        SETC(1,6,RGB_GOLD);
        SETC(1,7,RGB_GOLD);
        SETC(2,5,RGB_GOLD);
        SETC(2,6,RGB_GOLD);
        SETC(2,7,RGB_GOLD);
        SETC(3,5,RGB_GOLD);
        SETC(3,6,RGB_GOLD);
        SETC(3,7,RGB_CORAL);
        SETC(3,0,RGB_CORAL);
        SETC(3,1,RGB_CORAL);
        SETC(0,8,RGB_ORANGE);
        SETC(0,9,RGB_ORANGE);
        SETC(1,8,RGB_ORANGE);
        SETC(1,9,RGB_ORANGE);
        SETC(2,8,RGB_ORANGE);
        SETC(3,8,RGB_ORANGE);
        if (host_keyboard_leds() & (1<<USB_LED_NUM_LOCK)) {
            SETC(0,4, RGB_GREEN);
        }
    }

    //capslock leds

    if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
        SETC(3,1, RGB_ORANGE);
    }

}
