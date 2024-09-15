// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include QMK_KEYBOARD_H
#include "print.h"

enum custom_layer {
    _MAIN,
    _FN1,
    _FN2,
    _FN3,
};

enum custom_keys {
   B_CAPS = QK_KB_0,
   MACRO_GLHF,
   MACRO_GG,
   B_TEST,
   OSM_RALT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MAIN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     B_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_HOME,          KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, TL_LOWR, KC_SPC,                    KC_ENT,  TL_UPPR, KC_LALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FN1] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PGUP,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRV,  _______, KC_UP,   _______, QK_BOOT, B_TEST,                             _______, KC_P7,   KC_P8,   KC_P9,   KC_P0,   KC_PGDN,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_NONUS_BACKSLASH,                            KC_RBRC, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, EE_CLR,  _______, DB_TOGG, _______, LSFT(KC_NONUS_BACKSLASH), MACRO_GLHF,       MACRO_GG,KC_RCBR, KC_P1,   KC_P2,   KC_P3,   KC_MINS, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_DEL,                    KC_DEL,  _______, KC_P0
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FN2] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, QK_BOOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_UNDS,                            KC_EQL,  KC_HOME, RGB_HUI, RGB_SAI, RGB_VAI, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, KC_LPRN,          _______, KC_PLUS, KC_END,  RGB_HUD, RGB_SAD, RGB_VAD, EE_CLR,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, OSM_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FN3] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

static uint8_t cur_index;

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
	static uint16_t last_caps_press_time = 0;
	static int8_t caps_press_count = 0;
	static bool caps_pressed = false;
	static bool caps_used_as_lctl = false;
	switch (keycode) {
		case B_CAPS:
			if (record->event.pressed) {
				caps_pressed = true;
				if (timer_elapsed(last_caps_press_time) > 200 || caps_used_as_lctl) {
					caps_press_count = 0;
					caps_used_as_lctl = false;
				}
				switch (caps_press_count) {
					case 0:
						register_code(KC_LCTL);
						break;
					case 1:
						SEND_STRING(">");
						break;
					default:
						break;
				}
				caps_press_count++;
				last_caps_press_time = timer_read();
			} else {
				caps_pressed = false;
				switch (caps_press_count) {
					case 1:
						unregister_code(KC_LCTL);
						if (timer_elapsed(last_caps_press_time) <= 200 && !caps_used_as_lctl) {
							tap_code(KC_ESC);
						}
						break;
					default:
						caps_press_count = 0;
						break;
				}
			}
			return true;
		case MACRO_GLHF:
			if (record->event.pressed) {
				SEND_STRING(SS_LSFT("\n") SS_DELAY(20) "gl hf\n");
			}
			return false;
		case MACRO_GG:
			if (record->event.pressed) {
				SEND_STRING(SS_LSFT("\n") SS_DELAY(20) "gg\n");
			}
			return false;
		case B_TEST:
			if (record->event.pressed) {
				cur_index++;
				printf("%u\n", cur_index);
			}
			return false;
		case OSM_RALT:
			if (record->event.pressed) {
				if (get_oneshot_mods() & MOD_BIT(KC_RALT)) {
					clear_oneshot_mods();
				} else {
					set_oneshot_mods(MOD_BIT(KC_RALT));
				}
			}
			return true;
		default:
			if (record->event.pressed && caps_pressed == true && caps_press_count == 1) {
				caps_used_as_lctl = true;
			}
			return true;
	}
}

#define MAX_VAL 50

enum my_color {
	M_NONE,
	M_GREEN,
	M_RED,
	M_BLUE,
	M_YELLOW,
	M_CYAN,
	M_MAGENTA,
	M_WHITE,
	M_BLACK,
};

static bool ralt_pressed;
static uint8_t bound_leds[4][64];
static uint8_t bound_led_indices[4];


void set_color(uint8_t index, enum my_color color) {
	switch (color) {
		case M_NONE:
			break;
		case M_GREEN:
			rgb_matrix_set_color(index, 0, MAX_VAL, 0);
			break;
		case M_RED:
			rgb_matrix_set_color(index, MAX_VAL, 0, 0);
			break;
		case M_BLUE:
			rgb_matrix_set_color(index, 0, 0, MAX_VAL);
			break;
		case M_YELLOW:
			rgb_matrix_set_color(index, MAX_VAL, MAX_VAL, 0);
			break;
		case M_CYAN:
			rgb_matrix_set_color(index, 0, MAX_VAL, MAX_VAL);
			break;
		case M_MAGENTA:
			rgb_matrix_set_color(index, MAX_VAL, 0, MAX_VAL);
			break;
		case M_WHITE:
			rgb_matrix_set_color(index, MAX_VAL, MAX_VAL, MAX_VAL);
			break;
		case M_BLACK:
			rgb_matrix_set_color(index, 0, 0, 0);
			break;
		default:
			break;
	}
}

void keyboard_post_init_user(void) {
	ralt_pressed = false;
	memset(bound_leds, 0, 4*64);
	memset(bound_led_indices, 0, 4);
}

void oneshot_mods_changed_user(uint8_t mods) {
	if (mods & MOD_BIT(KC_RALT)) {
		ralt_pressed = true;
	} else {
		ralt_pressed = false;
	}
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
	uint8_t layer = get_highest_layer(layer_state);
	if (layer > 0) {
		for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
			for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
				uint8_t index = g_led_config.matrix_co[row][col];

				if (index >= led_min && index < led_max && index != NO_LED) {
					if (keymap_key_to_keycode(layer, (keypos_t){col, row}) > KC_TRNS) {
						set_color(index, layer);
					} else {
						set_color(index, M_BLACK);
					}
				}
			}
		}
	}

	if (ralt_pressed) {
		set_color(63, M_MAGENTA);
	}

	for (uint8_t i = 0; i < bound_led_indices[0]; i++) {
		static bool p = true;
		if (p) {
			p = false;
			printf("Setting led %u at %u\n", bound_leds[0][i], i);
		}
		set_color(bound_leds[0][i], M_MAGENTA);
	}

	// set_color(cur_index, M_MAGENTA);

  	return false;
} 

bool caps_word_press_user(uint16_t keycode) {
	switch (keycode) {
		case KC_A ... KC_Z:
		case KC_LBRC:
		case KC_QUOT:
		case KC_SCLN:
		case KC_SLSH:
			add_weak_mods(MOD_BIT(KC_LSFT));
			return true;
		case KC_1 ... KC_0:
		case KC_BSPC:
		case KC_QUES:
			return true;

		default:
			return false;
	}
}

enum command {
	CLEAR_BINDINGS,
	SET_BINDINGS
};

static bool find_keycode(uint16_t keycode, uint8_t row, uint8_t col) {
		for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
			for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
				uint16_t key = keymaps[0][row][col];

				if (key == keycode) {
					printf("Keycode %u found at row %u, col %u\n", keycode, row, col);
					uint8_t index = g_led_config.matrix_co[row][col];
					if (index == NO_LED) {
						continue;
					}

					uint8_t i = bound_led_indices[0]++;
					printf("Adding led %u to %u\n", index, i);
					bound_leds[0][i] = index;
				}
			}
		}
		return false;
}

void raw_hid_receive_kb(uint8_t *data, uint8_t length) {
	if (data[0] == 0xE0) {
		switch (data[1]) {
			case CLEAR_BINDINGS:
				memset(bound_leds, 0, 4*64);
				memset(bound_led_indices, 0, 4);
				break;
			case SET_BINDINGS:
				for (int i = 2; i < 128; i += 2) {
					uint16_t keycode = (uint16_t)(data[i]) | ((uint16_t)(data[i + 1]) << 8);
					printf("Keycode %u\n", keycode);
					if (keycode == 0) {
						break;
					}

					find_keycode(keycode, 0, 0);
				}
				break;
		}
	}
}
