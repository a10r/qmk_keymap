#include QMK_KEYBOARD_H

#include "config.h"
#include "audio.h"
#include "muse.h"
#include "keymap_german.h"

// Layers with DE_ prefix require setting a german keyboard layout in the OS.
enum planck_layers {
	DE_BASE,
	DE_LOWER,
	DE_RAISE,
	ADJUST,
	NAV
};

enum custom_keycodes {
	CUSTOM = SAFE_RANGE,
	MUSIC
};

#define LOWER MO(DE_LOWER)
#define RAISE MO(DE_RAISE)

// Hold: Right shift; Tap: Enter
#define ENT_RSF RSFT_T(KC_ENT)

// Capital umlauts
#define CAP_AE S(DE_ADIA)
#define CAP_OE S(DE_ODIA)
#define CAP_UE S(DE_UDIA)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTZ base layout
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Z  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Y  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |EntRSf|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | XXX  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------' */
[DE_BASE] = LAYOUT_planck_grid(
	KC_TAB,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    KC_BSPC,
	KC_ESC,  DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    DE_H,    DE_J,    DE_K,    DE_L,    DE_SCLN, DE_QUOT,
	KC_LSFT, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_SLSH, ENT_RSF,
	KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ä  |   ö  |   ü  |  NAV |   "  |   €  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   Ä  |   Ö  |   Ü  |   ß  |      |      |   :  |   <  |   >  |   ?  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  <>  |             |      | Home | PgUp | PgDn | End  |
 * `-----------------------------------------------------------------------------------' */
[DE_LOWER] = LAYOUT_planck_grid(
	DE_TILD, DE_EXLM, DE_AT,   DE_HASH, DE_DLR,  DE_PERC, DE_CIRC, DE_AMPR,  DE_ASTR, DE_LPRN, DE_RPRN, KC_DEL,
	_______, DE_ADIA, DE_ODIA, DE_UDIA, MO(NAV), DE_DQUO, DE_EURO, DE_UNDS,  DE_PLUS, DE_LCBR, DE_RCBR, DE_PIPE,
	_______, CAP_AE,  CAP_OE,  CAP_UE,  DE_SS,   _______, _______, DE_COLN,  DE_LABK, DE_RABK, DE_QUES, _______,
	_______, _______, _______, _______, _______, _______, _______, _______,  KC_HOME, KC_PGUP, KC_PGDN, KC_END
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |  <>  | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------' */
[DE_RAISE] = LAYOUT_planck_grid(
	DE_ACUT, DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    KC_BSPC,
	_______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   DE_MINS, DE_EQL,  DE_LBRC, DE_RBRC, DE_BSLS,
	_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |Debug |      | MUSIC|      |  RGB |RGBMOD| HUE+ | SAT+ |BRGTH+|  Ins |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Reset |      |MUSmod|Aud on|Audoff|      |      |      | HUE- | SAT- |BRGTH-|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  <>  |             |  <>  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'*/
[ADJUST] = LAYOUT_planck_grid(
	_______, _______, DEBUG,   _______, MUSIC,   _______, RGB_TOG, RGB_MOD, RGB_HUI,  RGB_SAI, RGB_VAI, KC_INS,
	RESET,   _______, MU_MOD,  AU_ON,   AU_OFF,  _______, _______, _______,   RGB_HUD,  RGB_SAD, RGB_VAD, _______,
	_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* Nav
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      | Home |  Up  |  End | PgUp |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  <>  |      |      | Left | Down | Right| PgDn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  <>  |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'*/
[NAV] = LAYOUT_planck_grid(
	_______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______,
	_______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
	return update_tri_layer_state(state, DE_LOWER, DE_RAISE, ADJUST);
}

__attribute__((weak)) void play_next_song(void);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
	case MUSIC:
		if (record->event.pressed) {
			play_next_song();
		}
		return true;
	}
	return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
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
#endif
}

bool music_mask_user(uint16_t keycode) {
	switch (keycode) {
	case RAISE:
	case LOWER:
		return false;
	default:
		return true;
	}
}

void matrix_init_user(void) {
	#ifdef AUDIO_ENABLE
		startup_user();
	#endif
}

#ifdef AUDIO_ENABLE
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
#endif