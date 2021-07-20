#pragma once

// Enable all RGB backlight animations
#define RGBLIGHT_ANIMATIONS

#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(PLANCK_SOUND)
// #define STARTUP_SONG SONG(NO_SOUND)
#endif

// MIDI notes can be sent when in Music mode is on
#define MIDI_BASIC