#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

#define ___v KC_TRNS  // 'v' like a down arrow, fallthrough to layer below
#define ___x KC_NO    // 'x' means NOOP

// testing preset songs
enum my_music_keycodes {
    MUS_USSR = SAFE_RANGE,
    MUS_CMPL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_5x12(
        KC_ESC , KC_1   , KC_2   , KC_3   , KC_4 , KC_5  , KC_6  , KC_7 , KC_8   , KC_9   , KC_0   , KC_DEL ,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R , KC_T  , KC_Y  , KC_U , KC_I   , KC_O   , KC_P   , KC_MINS,
        KC_BSPC, KC_A   , KC_S   , KC_D   , KC_F , KC_G  , KC_H  , KC_J , KC_K   , KC_L   , KC_SCLN, KC_ENT ,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V , KC_B  , KC_N  , KC_M , KC_COMM, KC_DOT , KC_SLSH, KC_QUOT,
        KC_LCTL, KC_LGUI, KC_LALT, OS_RALT, MO(2), KC_SPC, KC_SPC, MO(4), KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
    ),
    [1] = LAYOUT_ortho_5x12(
        ___v, KC_1, KC_2, KC_3, KC_4, KC_5  , KC_6  , KC_7, KC_8   , KC_9  , KC_0   , ___v,
        ___v, KC_Q, KC_W, KC_F, KC_P, KC_G  , KC_J  , KC_L, KC_U   , KC_Y  , KC_SCLN, ___v,
        ___v, KC_A, KC_R, KC_S, KC_T, KC_B  , KC_M  , KC_N, KC_E   , KC_I  , KC_O   , ___v,
        ___v, KC_Z, KC_X, KC_C, KC_D, KC_V  , KC_K  , KC_H, KC_COMM, KC_DOT, KC_SLSH, ___v,
        ___v, ___v, ___v, ___v, ___v, KC_SPC, KC_SPC, ___v, ___v   , ___v  , ___v   , ___v
    ),
    [2] = LAYOUT_ortho_5x12(
        KC_TILD, KC_MPLY, KC_MPRV, KC_MNXT, KC_BRIU, ___x  , ___x  , KC_PSLS, KC_7   , KC_8   , KC_9   , KC_CALC,
        KC_GRV , KC_MUTE, KC_VOLD, KC_VOLU, KC_BRID, ___x  , ___x  , KC_PAST, KC_4   , KC_5   , KC_6   , ___v   ,
        CW_TOGG, ___x   , ___x   , ___x   , ___x   , ___x  , ___x  , KC_PPLS, KC_1   , KC_2   , KC_3   , ___v   ,
        ___v   , ___x   , ___x   , ___x   , ___x   , ___x  , ___x  , KC_PMNS, KC_EQL , KC_0   , KC_DOT , ___v   ,
        ___v   , ___v   , ___v   , ___v   , ___v   , KC_SPC, KC_SPC, MO(5)  , KC_HOME, KC_PGDN, KC_PGUP, KC_END
    ),
    [4] = LAYOUT_ortho_5x12(
        KC_ESC , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 , ___x   , KC_HOME, KC_PGDN, KC_PGUP, KC_END ,
        KC_TAB , KC_F7 , KC_F8 , KC_F9 , KC_F10, KC_F11, KC_F12, KC_PIPE, KC_PLUS, KC_LCBR, KC_RCBR, KC_PSCR,
        KC_BSPC, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_BSLS, KC_EQL , KC_LBRC, KC_RBRC, ___x   ,
        ___v   , KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24, ___x   , ___x   , ___x   , ___x   , ___x   ,
        ___v   , ___v  , ___v  , ___v  , MO(5) , ___v  , ___v  , ___v   , ___x   , ___x   , ___x   , ___x
    ),
    [5] = LAYOUT_ortho_5x12(
        QK_BOOT, DF(0)   , DF(1)   , ___x, ___x, ___x  , ___x  , ___x, ___x, ___x, ___x, ___x,
        DB_TOGG, ___x    , ___x    , ___x, ___x, ___x  , ___x  , ___x, ___x, ___x, ___x, ___x,
        ___x   , ___x    , ___x    , ___x, ___x, ___x  , ___x  , ___x, ___x, ___x, ___x, ___x,
        ___x   , MUS_CMPL, MUS_USSR, ___x, ___x, ___x  , ___x  , ___x, ___x, ___x, ___x, ___x,
        ___x   , ___x    , ___x    , ___x, ___v, KC_SPC, KC_SPC, ___v, ___x, ___x, ___x, ___x
    )
};

const uint8_t music_map[MATRIX_ROWS][MATRIX_COLS] = LAYOUT_ortho_5x12(
//  Eb      F#  Ab  Bb      C#  Eb      F#  Ab  Bb
//  E5  F5  G5  A5  B5  C6  D6  E6  F6  G6  A6  B6
    20, 99, 23, 25, 27, 99, 30, 32, 99, 35, 37, 39,
    21, 22, 24, 26, 28, 29, 31, 33, 34, 36, 38, 40,

//      Ab  Bb      C#  Eb      F#  Ab  Bb      C#
//  G3  A3  B3  C4  D4  E4  F4  G4  A4  B4  C5  D5
    99,  1,  3, 99,  6,  8, 99, 11, 13, 15, 99, 18,
     0,  2,  4,  5,  7,  9, 10, 12, 14, 16, 17, 19,
    
    99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99
);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MUS_USSR:
        float song_ussr_anthem[][2] = SONG(USSR_ANTHEM);
        PLAY_SONG(song_ussr_anthem);
        return false;
    case MUS_CMPL:
        float song_campanella[][2] = SONG(CAMPANELLA);
        PLAY_SONG(song_campanella);
        return false;
    default:
        return true; // Process all other keycodes normally
  }
}

#undef ___v
#undef ___x