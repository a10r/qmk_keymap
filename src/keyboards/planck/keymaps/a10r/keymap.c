#include QMK_KEYBOARD_H

#include "version.h"
#if __has_include("version-override.h")
	#include "version-override.h"
#endif

#include "config.h"
#include "audio.h"
#include "muse.h"

#include "keymap_german.h"
#include "sendstring_german.h"

// Layers with DE_ prefix require setting a german keyboard layout in the OS.
enum planck_layers {
	DE_BASE,
	DE_L1,
	DE_R1,
	ADJUST,
	NAV,
	MOUSE,
	DE_GAME,
	DE_GAME_NUM
};

enum custom_keycodes {
	CUSTOM = SAFE_RANGE,
	MUSIC,
	MARK_LN, // mark entire line
	VERSION,
};

#define MO_L1   MO(DE_L1)
#define MO_R1   MO(DE_R1)
#define MO_MOUS MO(MOUSE)
#define ESC_NAV LT(NAV, KC_ESC)
#define DF_BASE DF(DE_BASE)
#define DF_GAME DF(DE_GAME)
#define G_NUM   MO(DE_GAME_NUM)
#define SFTENT  RSFT_T(KC_ENT) // Hold: Right shift; Tap: Enter


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTZ base layout
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Z  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Esc/Nv|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Y  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |SftEnt|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Win  | Alt  | Mouse|Symbol|    Space    | F/Num| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------' */
[DE_BASE] = LAYOUT_planck_grid(
	KC_TAB,  DE_Q,    DE_W,    DE_E,    DE_R,  DE_T,   DE_Z,   DE_U,  DE_I,    DE_O,    DE_P,    KC_BSPC,
	ESC_NAV, DE_A,    DE_S,    DE_D,    DE_F,  DE_G,   DE_H,   DE_J,  DE_K,    DE_L,    DE_SCLN, DE_QUOT,
	KC_LSFT, DE_Y,    DE_X,    DE_C,    DE_V,  DE_B,   DE_N,   DE_M,  DE_COMM, DE_DOT,  DE_SLSH, SFTENT,
	KC_LCTL, KC_LGUI, KC_LALT, MO_MOUS, MO_L1, KC_SPC, KC_SPC, MO_R1, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Symbols
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   +  |   {  |   }  |   &  |   *  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Del |   ??  |   ??  |   ??  |   ??  |   "  |   =  |   (  |   )  |   _  |   ^  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |   <  |   >  |   ???  |   -  |   [  |   ]  |   :  |   ?  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  <>  |             |      | Home | PgDn | PgUp | End  |
 * `-----------------------------------------------------------------------------------' */
[DE_L1] = LAYOUT_planck_grid(
	DE_TILD, DE_EXLM, DE_AT,   DE_HASH, DE_DLR,  DE_PERC, DE_PLUS, DE_LCBR, DE_RCBR, DE_AMPR, DE_ASTR, KC_BSPC,
	KC_DEL,  DE_ADIA, DE_SS,   DE_ODIA, DE_UDIA, DE_DQUO, DE_EQL,  DE_LPRN, DE_RPRN, DE_UNDS, DE_CIRC, DE_PIPE,
	_______, _______, _______, DE_LABK, DE_RABK, DE_EURO, DE_MINS, DE_LBRC, DE_RBRC, DE_COLN, DE_QUES, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

/* F-keys + Numpad layer
 * ,-----------------------------------------------------------------------------------.
 * |  ??   |  F1  |  F2  |  F3  |  F4  |      |   +  |   7  |   8  |   9  |   *  | Bspc |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |   =  |   4  |   5  |   6  |   0  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |   -  |   1  |   2  |   3  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |  <>  | Mute | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'*/
[DE_R1] = LAYOUT_planck_grid(
	DE_ACUT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, DE_PLUS, DE_7,    DE_8,    DE_9,    DE_ASTR, KC_BSPC,
	_______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, DE_EQL,  DE_4,    DE_5,    DE_6,    DE_0,    DE_BSLS,
	_______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, DE_MINS, DE_1,    DE_2,    DE_3,    DE_SLSH, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust
 * ,-----------------------------------------------------------------------------------.
 * |      |      |Debug | Ver  | MUSIC|      |  RGB |RGBMOD| HUE+ | SAT+ |BRGTH+|  Ins |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Reset |      |MUSmod|Aud on|Audoff| GAME |      |      | HUE- | SAT- |BRGTH-|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CapsLk|Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      | PrtSc| Pause|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  <>  |             |  <>  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'*/
[ADJUST] = LAYOUT_planck_grid(
	_______, _______, DEBUG,   VERSION, MUSIC,   _______, RGB_TOG, RGB_MOD, RGB_HUI,  RGB_SAI, RGB_VAI, KC_INS,
	RESET,   _______, MU_MOD,  AU_ON,   AU_OFF,  DF_GAME, _______, _______, RGB_HUD,  RGB_SAD, RGB_VAD, _______,
	KC_CAPS, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______,  KC_PSCR, KC_PAUS, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* Nav/edit layer (F13-F15 can be used to configure hotkeys)
 * ,-----------------------------------------------------------------------------------.
 * |      |  F13 |  F14 |  F15 |      |      |      | Home |  Up  |  End | PgUp |(Bspc)|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  <>  |  Alt | Shift| Ctrl |      |      |      | Left | Down | Right| PgDn | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  Cut | Copy | Paste|MARKLN|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'*/
[NAV] = LAYOUT_planck_grid(
	_______, KC_F13,  KC_F14,  KC_F15,  _______, _______, _______, KC_HOME, KC_UP,   KC_END,   KC_PGUP, _______,
	_______, KC_LALT, KC_LSFT, KC_LCTL, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT,  KC_PGDN, KC_DEL,
	_______, _______, _______, _______, _______, _______, _______, C(DE_X), C(DE_C), C(DE_V),  MARK_LN, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______
),

/* Mousekeys layer
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      | LClk | MUp  | RClk | WhlUp|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | MLeft| MDown|MRight| WhlDn|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Spd0 | Spd1 | Spd2 |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  <>  |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'*/
[MOUSE] = LAYOUT_planck_grid(
	_______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, _______,
	_______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______,
	_______, _______, _______, _______, _______, _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* QWERTZ base layout for gaming
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Z  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Y  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Win  | Alt  | XXX  |Number|    Space    | XXX  |   /  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------' */
[DE_GAME] = LAYOUT_planck_grid(
	KC_TAB,  DE_Q,    DE_W,    DE_E,    DE_R,  DE_T,   DE_Z,   DE_U,    DE_I,    DE_O,    DE_P,    KC_BSPC,
	KC_ESC,  DE_A,    DE_S,    DE_D,    DE_F,  DE_G,   DE_H,   DE_J,    DE_K,    DE_L,    DE_SCLN, DE_QUOT,
	KC_LSFT, DE_Y,    DE_X,    DE_C,    DE_V,  DE_B,   DE_N,   DE_M,    DE_COMM, DE_DOT,  KC_UP,   KC_ENTER,
	KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX, G_NUM, KC_SPC, KC_SPC, XXXXXXX, DE_SLSH, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Game: Numbers
 * ,-----------------------------------------------------------------------------------.
 * | BASE |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  <>  |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------' */
[DE_GAME_NUM] = LAYOUT_planck_grid(
	DF_BASE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
	return update_tri_layer_state(state, DE_L1, DE_R1, ADJUST);
}

__attribute__((weak)) void play_next_song(void);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
	case MUSIC:
		if (record->event.pressed) {
			play_next_song();
		}
		return true;
	case MARK_LN:
		if (record->event.pressed) {
			register_code(KC_HOME);
			unregister_code(KC_HOME);
			register_code(KC_LSFT);
			register_code(KC_END);
		} else {
			unregister_code(KC_LSFT);
			unregister_code(KC_END);
		}
		return false;
	case VERSION:
		if (record->event.pressed) {
			SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ QMK " QMK_VERSION " (built on: " QMK_BUILDDATE ")");
		}
		return false;
	}
	return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void matrix_scan_user(void) {
	if (muse_mode) {
		if (muse_counter == 0) {
			uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
			if (muse_note != last_muse_note) {
				stop_note(compute_freq_for_midi_note(last_muse_note));
				play_note(compute_freq_for_midi_note(muse_note), 0xF);
				last_muse_note = muse_note;
			}
		}
		muse_counter = (muse_counter + 1) % muse_tempo;
	} else {
		if (muse_counter) {
			stop_all_notes();
			muse_counter = 0;
		}
	}
}

bool music_mask_user(uint16_t keycode) {
	switch (keycode) {
	// TODO Uncommenting these lines causes the keyboard to crash on startup. Absolutely no clue why though.
	// case MO_L1:
	// case MO_R1:
	// case MO_MOUS:
	// 	return false;
	default:
		return true;
	}
}

void matrix_init_user(void) {
	startup_user();
}

float startup_sound[][2] = SONG(STARTUP_SOUND);
float goodbye_sound[][2] = SONG(GOODBYE_SOUND);

float coin[][2] = SONG(COIN_SOUND);
float zelda_puzzle[][2] = SONG(ZELDA_PUZZLE);
float ff_prelude[][2] = SONG(FF_PRELUDE);
float renai_circulation[][2] = SONG(RENAI_CIRCULATION);
float platinum_disco[][2] = SONG(PLATINUM_DISCO);

void play_next_song(void) {
	static int song_index = 0;
	switch (song_index++) {
		case 0: PLAY_SONG(coin); break;
		case 1: PLAY_SONG(zelda_puzzle); break;
		case 2: PLAY_SONG(ff_prelude); break;
		case 3: PLAY_SONG(renai_circulation); break;
		case 4: PLAY_SONG(platinum_disco);
		default: song_index = 0;
	}
};

layer_state_t default_layer_state_set_user(layer_state_t state) {
	switch (get_highest_layer(state)) {
	case DE_GAME:
		PLAY_SONG(zelda_puzzle);
		rgblight_enable_noeeprom();
		rgblight_sethsv_noeeprom(140, 255, 255);
		rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
		break;
	default:
		PLAY_SONG(startup_sound);
		rgblight_reload_from_eeprom();
		break;
	}
	return state;
}

void startup_user()
{
	wait_ms(20); // gets rid of tick
	PLAY_SONG(startup_sound);
}

void shutdown_user()
{
	PLAY_SONG(goodbye_sound);
	wait_ms(150);
	stop_all_notes();
}