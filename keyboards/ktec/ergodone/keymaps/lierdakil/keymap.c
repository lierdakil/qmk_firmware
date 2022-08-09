#include QMK_KEYBOARD_H

enum layers {BASE, CTR};

#define MC_A RGUI_T(KC_A)
#define MC_S LALT_T(KC_S)
#define MC_D LSFT_T(KC_D)
#define MC_F LCTL_T(KC_F)
#define MC_J LCTL_T(KC_J)
#define MC_K LSFT_T(KC_K)
#define MC_L LALT_T(KC_L)
#define MC_SCLN RGUI_T(KC_SCLN)
#define BSPC LSFT_T(KC_BSPC)
#define SPC RSFT_T(KC_SPC)
#define MC_DEL LT(0, KC_DEL)
#define MC_CSF LT(0, KC_SPC)
#define KC_CTLT LT(CTR, KC_NO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_ergodox(
  // left hand
  KC_GRV, KC_1,    KC_2,    KC_3,   KC_4, KC_5, KC_PLUS,
  KC_EQL, KC_Q,    KC_W,    KC_E,   KC_R, KC_T, KC_LBRC,
  KC_TAB, MC_A,    MC_S,    MC_D,   MC_F, KC_G,
  KC_LGUI,KC_Z,    KC_X,    KC_C,   KC_V, KC_B, KC_NO,
  KC_NO,  KC_CAPS, KC_INS,  KC_LEFT,KC_RGHT,
          KC_HOME, KC_END,
                   KC_NO,
  BSPC,   MC_DEL,  KC_NO,
  // right hand
  KC_PIPE,  KC_6,   KC_7,  KC_8,   KC_9,   KC_0,    KC_BSLS,
  KC_RBRC,  KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,    KC_MINS,
            KC_H,   MC_J,  MC_K,   MC_L,   MC_SCLN, KC_QUOT,
  KC_NO,    KC_N,   KC_M,  KC_COMM,KC_DOT, KC_SLSH, KC_RCTL,
                    KC_UP, KC_DOWN,KC_LBRC,KC_RBRC, KC_CTLT,
  KC_RALT,  KC_ENT,
  KC_PGUP,
  KC_PGDN,  MC_CSF, SPC
  ),
[CTR] = LAYOUT_ergodox(
  // left hand
  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,    KC_F12,
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
  RESET  , _______, _______, _______, _______,
           _______, _______,
                    _______,
  _______, _______, _______,
  // right hand
  _______, KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_PSCR, KC_SCLN, KC_PAUS,  _______, _______, _______, _______,
           _______, _______,  _______, _______, _______, _______,
  _______, _______, _______,  _______, _______, _______, _______,
                    _______,  _______, _______, _______, _______,
  _______, _______,
  _______,
  _______, _______, _______
  )
// [CTL] = LAYOUT_ergodox(  // layer 0 : default
//   // left hand
//   _______, _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______,
//            _______, _______,
//                     _______,
//   _______, _______, _______,
//   // right hand
//   _______, _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______, _______,
//            _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______, _______,
//                     _______, _______, _______, _______, _______,
//   _______, _______
//   _______,
//   _______, _______, _______
//   ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MC_CSF:
        case MC_DEL:
            if (!record->tap.count) {
                if (record->event.pressed) {
                    register_code(KC_INT1);
                } else {
                    unregister_code(KC_INT1);
                }
                return false;
            }
            return true;
    }
    return true;
}
