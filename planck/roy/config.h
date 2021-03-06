#pragma once

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

// #define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200

// AUTO_SHIFT
#define AUTO_SHIFT_TIMEOUT 200
#define NO_AUTO_SHIFT_NUMERIC

// MOUSEKEY
#define MOUSEKEY_DELAY 100
#define MOUSEKEY_INTERVAL 32
// ホイールの加速無効
#define MOUSEKEY_WHEEL_TIME_TO_MAX 0
#define MOUSEKEY_WHEEL_MAX_SPEED 20
