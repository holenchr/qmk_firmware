// ADJUSTED TO SWISS MAC OS KEYBOARD (holenchr 2025-03-04)

#include QMK_KEYBOARD_H
#include "version.h"
#include "sendstring_swiss_de.h"

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
};

enum custom_keycodes {
	MACRO_BRCT = SAFE_RANGE,
	MACRO_CBRC,
	MACRO_PRNT,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Layer 0: Base
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Caps  |      |      |      |      |      |  [   |           |   ]  |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   []   |  Q   |  W   |  E   |  R   |  T   |      |           |      |   Z  |   U  |   I  |   O  |   P  |   {}   |
 * |--------+------+------+------+------+------|  {   |           |   }  |------+------+------+------+------+--------|
 * |  BSPC  |  A   |  S   |  D   |  F   |  G   |------|           |------|   H  |   J  |   K  |   L  |   ¨  |   ()   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |  Y   |  X   |  C   |  V   |  B   |  (   |           |   )  |   N  |   M  |   ,  |   .  |   -  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LAlt |      |      |      |      |                                       |      |      |      |      |  RAlt|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |left  | down |       |  up  | Right|
 *                                 ,------|------|------|       |------+------+------.
 *                                 | Esc  | TAB  |      |       |      |      |      |
 *                                 | LCmd |LCtrl |------|       |------| Enter| Space|
 *                                 |      |      | TT1  | 	    |  TT1 |      |      |
 *                                 `--------------------'       `--------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
	// Left hand                                                                                    right hand
	KC_CAPS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      CH_LBRC,                CH_RBRC,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
	MACRO_BRCT, KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       CH_LCBR,                CH_RCBR,    CH_Z,       KC_U,       KC_I,       KC_O,       KC_P,       MACRO_CBRC,
	KC_BSPC,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                                           KC_H,       KC_J,       KC_K,       KC_L,       CH_DIAE,    MACRO_PRNT,
	KC_LSFT,	CH_Y,       KC_X,       KC_C,       KC_V,       KC_B,       CH_LPRN,                CH_RPRN,    KC_N,       KC_M,       KC_COMM,    KC_DOT,     CH_MINS,    KC_RSFT,
	KC_LALT,	KC_NO,      KC_NO,      KC_NO,      KC_NO,                                                                  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_RALT,

                                                                KC_LEFT,    KC_DOWN,                KC_UP,      KC_RGHT,
                                                                            KC_NO,                  KC_NO,
								  	    CMD_T(KC_ESC),     CTL_T(KC_TAB),   TT(SYMB),               TT(SYMB),   KC_ENT,     KC_SPC
),
/* Layer 1: Symbols/Numbers
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |  [   |           |   ]  |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |    @   |  #   |  %   |  &   |  |   |  /   |      |           |      |   \  |   ~  |   '  |   "  |   `  |    ^   |
 * |--------+------+------+------+------+------|  {   |           |   }  |------+------+------+------+------+--------|
 * |  BSPC  |  1   |  2   |  3   |  4   |  5   |------|           |------|   6  |   7  |   8  |   9  |   0  |    $   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |  <   |  >   |  =   |  +   |  *   |  (   |           |   )  |   !  |   ?  |   ,  |   .  |   -  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Alt  |      |      |      |      |                                       |      |      |      |      |  RAlt|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |left  | down |       |  up  | Right|
 *                                 ,------|------|------|       |------+------+------.
 *                                 | Esc  | TAB  |      |       |      |      |      |
 *                                 | LCmd |LCtrl |------|       |------| Enter| Space|
 *                                 |      |      | TT1  | 	    |  TT1 |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox_pretty(
	// Left hand                                                                                    right hand
	KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      CH_LBRC,                CH_RBRC,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
	CH_AT,      CH_HASH,    CH_PERC,    CH_AMPR,    CH_PIPE,    CH_SLSH,    CH_LCBR,                CH_RCBR,    CH_BSLS,    CH_TILD,    CH_QUOT,    CH_DQUO,    CH_GRV,     CH_CIRC,
	KC_BSPC,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                                           KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       CH_DLR, 
	KC_LSFT,	CH_LABK,    CH_RABK,    CH_EQL,     CH_PLUS,    CH_ASTR,    CH_LPRN,                CH_RPRN,    CH_EXLM,    CH_QUES,    KC_COMM,    KC_DOT,     CH_MINS,    KC_RSFT,
	KC_LALT,	KC_NO,      KC_NO,      KC_NO,      KC_NO,                                                                  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_RALT,

                                                                KC_LEFT,    KC_DOWN,                KC_UP,      KC_RGHT,
                                                                            KC_NO,                  KC_NO,
									    CMD_T(KC_ESC),    CTL_T(KC_TAB),    TT(SYMB),               TT(SYMB),   KC_ENT,     KC_SPC
)
};

bool caps = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case KC_CAPS:
			if (record->event.pressed) {
				if (caps) {
					rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
					caps = false;
					break;
				}
				rgblight_mode(RGBLIGHT_MODE_BREATHING);
				caps = true;
			}
			break;
		case CMD_T(KC_ESC):
			if (record->event.pressed) {
				//VIM: If caps lock is on set it off before entering normal mode
				if (caps) {
					SEND_STRING(SS_TAP(X_CAPS));
					rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
					caps = false;
				}
			}
			break;
		case MACRO_BRCT:
			if (record->event.pressed) {
				SEND_STRING("[]" SS_TAP(X_LEFT));
			}
			break;
		case MACRO_CBRC:
			if (record->event.pressed) {
				SEND_STRING("{}" SS_TAP(X_LEFT));
			}
			break;
		case MACRO_PRNT:
			if (record->event.pressed) {
				SEND_STRING("()" SS_TAP(X_LEFT));
			}
			break;
	}
	return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
	
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(1);

	if (caps) {
		rgblight_mode(RGBLIGHT_MODE_BREATHING);
	}

    switch (layer) {
    	case BASE:
    		rgblight_sethsv_noeeprom(HSV_BLUE);
			break;
    	case SYMB:
    		rgblight_sethsv_noeeprom(HSV_GREEN);
    		break;
    }
    return state;
  return state;
}

void keyboard_post_init_user(void) {
	layer_state_set_user(layer_state);
}