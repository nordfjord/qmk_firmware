#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _COLEMAK 1
#define _FN 2

enum custom_keycodes {
	LAYOUT_TOGGLE = SAFE_RANGE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = KEYMAP(
		KC_GRV,
        		 KC_1,    KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, 
		KC_TAB,  KC_Q,    KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
		KC_ESC,  KC_A,    KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L,    KC_SCLN, KC_QUOT, 		    KC_ENT, 
		KC_LSFT, KC_TRNS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH,          KC_LSFT, 
		KC_LCTL, KC_LALT, KC_LGUI,          KC_SPC,                          KC_RGUI, MO(_FN),   KC_RALT, KC_RCTL),

	[_COLEMAK] = KEYMAP(
		KC_GRV,
        		 KC_1,    KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, 
		KC_TAB,  KC_Q,    KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,
		KC_ESC,  KC_A,    KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I,    KC_O,    KC_QUOT, 		    KC_ENT, 
		KC_LSFT, KC_TRNS, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT,  KC_SLSH,          KC_LSFT, 
		KC_LCTL, KC_LALT, KC_LGUI,          KC_SPC,                          KC_RGUI, MO(_FN),   KC_RALT, KC_RCTL),

	[_FN] = KEYMAP(
        KC_ESC,
				 KC_F1,	  KC_F2,   KC_F3,   KC_F4,    KC_F5,    KC_F6,    KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  KC_DEL, 
		KC_TRNS, KC_TRNS, KC_BRIU, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PGUP, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, LAYOUT_TOGGLE,
		KC_TRNS, KC_TRNS, KC_BRID, KC_PGDN, RGB_M_P,  RGB_M_B,  KC_LEFT,  KC_DOWN, KC_UP,   KC_RIGHT, KC_HOME, KC_END,           KC_TRNS, 
		KC_TRNS, KC_TRNS, RGB_TOG, RGB_MOD, RGB_RMOD, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, KC_MUTE,  KC_VOLD, KC_VOLU,          KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS,                              KC_TRNS,                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

uint8_t current_layout = _QWERTY;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LAYOUT_TOGGLE:
            if (record->event.pressed) {
                if (current_layout == _QWERTY) {
					current_layout = _COLEMAK;
                    layer_move(_COLEMAK);
                } else {
					current_layout = _QWERTY;
                    layer_move(_QWERTY);
                }
            }
            return false;
        default:
            return true;
    }
}