#include "bm40hsrgb.h"

enum layers {BASE, LOWER, UPPER, CTRL, NAV, NUMS};

#define MC_A RGUI_T(KC_A)
#define MC_S LALT_T(KC_S)
#define MC_D LSFT_T(KC_D)
#define MC_F LCTL_T(KC_F)
#define MC_J LCTL_T(KC_J)
#define MC_K LSFT_T(KC_K)
#define MC_L LALT_T(KC_L)
#define MC_SCLN RGUI_T(KC_SCLN)
#define LWR LT(LOWER,KC_BSPC)
#define UPR LT(UPPER,KC_SPC)
#define ENT LT(NAV,KC_ENT)
#define DEL LSFT_T(KC_DEL)
#define SPC RSFT_T(KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT_planck_mit(
        KC_Q,    KC_W,    KC_E,    KC_R, KC_T, KC_EQL,     KC_MINS, KC_Y, KC_U, KC_I,    KC_O,   KC_P,
        MC_A,    MC_S,    MC_D,    MC_F, KC_G, KC_TAB,     KC_QUOT, KC_H, MC_J, MC_K,    MC_L,   MC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V, KC_B, KC_LGUI,    KC_RCTL, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
        KC_GRV,  KC_BSLS, KC_CAPS, LWR,  DEL,  ENT               , SPC,  UPR,  TG(NUMS),KC_LBRC,KC_RBRC
        ),
	[LOWER] = LAYOUT_planck_mit(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TILD, KC_BSPC, KC_CIRC, KC_AMPR,       KC_ASTR,       KC_LPRN, KC_RPRN,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_DEL,  KC_PIPE, KC_F6,   KC_UNDS,       KC_PLUS,       KC_LCBR, KC_RCBR,
        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, _______, KC_F12,  LSFT(KC_NUHS), LSFT(KC_NUBS), KC_HOME, KC_END,
        _______, _______, KC_SLCK, _______, _______, _______, _______, MO(CTRL),      _______,       _______, _______
        ),
	[UPPER] = LAYOUT_planck_mit(
        KC_1,    KC_2,    KC_3,     KC_4,    KC_5,    KC_GRV,  KC_BSPC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,   KC_DEL,  KC_BSLS, KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,
        KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  _______, _______, KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN,
        _______, _______, _______, MO(CTRL), _______, _______, _______, _______, _______, _______, _______
        ),
	[CTRL] = LAYOUT_planck_mit(
        _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
        ),
	[NAV] = LAYOUT_planck_mit(
    /*  0        1        2        3        4        5        6        7        8        9        10       11       */
        KC_ESC,  _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_UP,   KC_PGDN, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_END,  _______, _______,
        _______, _______, _______, _______, _______, _______         , _______, _______, _______, _______, _______
        ),
	[NUMS] = LAYOUT_planck_mit(
    /*  0        1        2        3        4        5        6        7        8        9      10       11       */
        _______, _______, _______, _______, _______, _______, _______, KC_PSLS, KC_P7, KC_P8,   KC_P9,   KC_PAST,
        _______, _______, _______, _______, _______, _______, _______, KC_PMNS, KC_P4, KC_P5,   KC_P6,   KC_PPLS,
        _______, _______, _______, _______, _______, _______, _______, KC_NLCK, KC_P1, KC_P2,   KC_P3,   KC_PEQL,
        _______, KC_PSCR, KC_PAUS, _______, _______, _______         , _______, KC_P0, _______, KC_PDOT, KC_PENT
        )
};


//layer led colors
#define RC(r,c) (r*12+c)
#define SETC(r,c,col) rgb_matrix_set_color(RC(r,c),col)

void rgb_matrix_indicators_user(void) {
    if (IS_LAYER_ON(NAV)) {
        SETC(0,0,RGB_RED);
        SETC(0,9,RGB_GOLD);
        SETC(1,8,RGB_GOLD);
        SETC(1,9,RGB_GOLD);
        SETC(1,10,RGB_GOLD);
        SETC(2,8,RGB_ORANGE);
        SETC(2,9,RGB_ORANGE);
        SETC(0,8,RGB_CORAL);
        SETC(0,10,RGB_CORAL);
    }
    else if(IS_LAYER_ON(NUMS)) {
        SETC(2,7,RGB_ORANGE);
        if (host_keyboard_leds() & (1<<USB_LED_NUM_LOCK)) {
            SETC(2,7, RGB_GREEN);
        }

        SETC(0,8,RGB_GOLD);
        SETC(0,9,RGB_GOLD);
        SETC(0,10,RGB_GOLD);
        SETC(1,8,RGB_GOLD);
        SETC(1,9,RGB_GOLD);
        SETC(1,10,RGB_GOLD);
        SETC(2,8,RGB_GOLD);
        SETC(2,9,RGB_GOLD);
        SETC(2,10,RGB_GOLD);
        SETC(3,8,RGB_GOLD);
        SETC(3,9,RGB_RED);
        SETC(3,10,RGB_GOLD);

        SETC(3,1,RGB_CORAL);
        SETC(3,2,RGB_CORAL);

        SETC(0,7,RGB_ORANGE);
        SETC(0,11,RGB_ORANGE);
        SETC(1,7,RGB_ORANGE);
        SETC(1,11,RGB_ORANGE);
        SETC(2,11,RGB_ORANGE);
        SETC(3,11,RGB_CHARTREUSE);
    }

    // status leds
    switch (host_keyboard_leds() & ((1<<USB_LED_CAPS_LOCK) | (1<<USB_LED_SCROLL_LOCK))) {
        case 0b10:
        SETC(3,2, RGB_ORANGE);
        break;
        case 0b100:
        SETC(3,2, RGB_GOLDENROD);
        break;
        case 0b110:
        SETC(3,2, RGB_GREEN);
        break;
    }

}
