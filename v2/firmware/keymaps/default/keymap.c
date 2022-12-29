#include QMK_KEYBOARD_H

const key_override_t LPRN_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_RPRN);
const key_override_t LCBR_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_LCBR, KC_RCBR);
const key_override_t LABK_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_LABK, KC_RABK);
const key_override_t LBRC_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, KC_RBRC);

const key_override_t** key_overrides = (const key_override_t*[]){
    &LPRN_key_override,
    &LCBR_key_override,
    &LABK_key_override,
    &LBRC_key_override,
    NULL
};

enum tapdances {
	TD_A_AE,
	TD_O_OE,
	TD_U_UE,
	
	TD_SCLN_CLN,
	TD_SPC_DOT
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_A_AE] = ACTION_TAP_DANCE_DOUBLE(KC_A, RALT(KC_Q)),
    [TD_O_OE] = ACTION_TAP_DANCE_DOUBLE(KC_O, RALT(KC_P)),
    [TD_U_UE] = ACTION_TAP_DANCE_DOUBLE(KC_U, RALT(KC_Y)),
    
    [TD_SCLN_CLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, LSFT(KC_SCLN)),
    [TD_SPC_DOT] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_DOT)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT(
  KC_TAB,   XXXXXXX,   KC_Q,    KC_D,    TD(TD_O_OE),    XXXXXXX,          	KC_J,    KC_R,    TD(TD_U_UE),    KC_Y,   XXXXXXX,    KC_ESC,
  KC_LSFT,  TD(TD_A_AE),   KC_S,    KC_E,    KC_T,    KC_F,          KC_G,    KC_N,    KC_I,    KC_L,   KC_H, 	KC_QUOT,
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_SLSH,          	KC_P,    KC_M,    KC_W, KC_B, KC_K, KC_LGUI,          
  KC_LALT, MO(1),   KC_ENT,  KC_BSPC,  KC_F5, S(C(KC_M)), 		KC_MUTE, KC_F20, KC_TAB, KC_SPC,  MO(2),  KC_RALT
),

[1] = LAYOUT(
  KC_TAB,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,             	KC_6,   KC_7,    KC_8,   KC_9,    KC_0,  KC_ESC,
  KC_LSFT,  XXXXXXX,RALT(KC_S), XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX,KC_LPRN, KC_LCBR,KC_LABK, KC_LBRC, XXXXXXX,
  KC_LCTL,  XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          	XXXXXXX,XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,          
  KC_LALT,  _______, KC_ENT, _______, KC_F5,  S(C(KC_M)), 	   	KC_MUTE, KC_F20, KC_TAB,  KC_DOT,  MO(3),  KC_RALT
),

[2] = LAYOUT(
  KC_TAB,   XXXXXXX, XXXXXXX, KC_ASTR, KC_MINUS, XXXXXXX,      	XXXXXXX, XXXXXXX,   KC_UP,  XXXXXXX, XXXXXXX, KC_ESC,
  KC_LSFT,  KC_BSLS, TD(TD_SCLN_CLN), KC_COMM, KC_EQL, KC_EXLM,      KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT,  KC_END,XXXXXXX,
  KC_LCTL,  KC_NUHS,  KC_DLR, KC_AMPR, KC_AT, KC_PERC,      	XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,XXXXXXX,          
  KC_LALT,   MO(3),   KC_ENT, KC_DEL, KC_F5, S(C(KC_M)), 		KC_MUTE, KC_F20, KC_TAB,  KC_SPC, _______, KC_RALT
)
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise){


    if (index == 0) {
    	switch (get_highest_layer(layer_state)) {
    	
		case 0:
			if (clockwise) {
    				tap_code16(KC_PGDN);
    			} else {
    				tap_code16(KC_PGUP);
    			}
    			break;
			
		case 2:
			if (clockwise) {
				tap_code16(C(KC_Y));
			} else {
				tap_code16(C(KC_Z));
			}
			break;
    	} 
    }
    else if (index == 1) {
	switch (get_highest_layer(layer_state)) {
	
		case 0:
			if (clockwise) {
	    			tap_code16(C(KC_RIGHT));
    			} else {
	    			tap_code16(C(KC_LEFT));
    			}
    			break;
			
		case 1:
			if (clockwise) {
				tap_code16(S(C(KC_RIGHT)));
			} else {
				tap_code16(S(C(KC_LEFT)));
			}
			break;
    	}
    }
    return true;
}
#endif
