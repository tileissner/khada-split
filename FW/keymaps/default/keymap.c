#include QMK_KEYBOARD_H

enum khada_layers {
	_QWERTZ,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTZ] = LAYOUT(
  KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,          KC_Z,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
  KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,          KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Y,   KC_X,    KC_C,    KC_V,    KC_B,          KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,          
            KC_LALT,KC_LCTRL,KC_LGUI, KC_SPC,  KC_MUTE, 	KC_MUTE, KC_ENT,  KC_RGUI, KC_RCTRL,KC_RALT
),

};
