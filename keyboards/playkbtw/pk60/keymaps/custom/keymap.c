#include QMK_KEYBOARD_H

#include"keymap_jp.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_minila(
        KC_ESC,  KC_1,    KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    JP_MINS, JP_CIRC, JP_YEN, KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    JP_AT, JP_LBRC, JP_RBRC,
        KC_LCTL, KC_A,    KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    JP_SCLN, JP_COLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,     KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    JP_COMM, JP_DOT,  JP_SLSH, JP_BSLS, KC_UP,   KC_LSFT,
        MO(1),   KC_LALT, KC_LGUI,  KC_LANG2,                           KC_SPC,  KC_LANG1, KC_RCTL, MO(2),  KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    [1] = LAYOUT_minila(
        RESET,   KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
        _______, RGB_TOG,  RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, _______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______,
        _______, RGB_MOD,  _______, _______, RGB_VAI, RGB_VAD, KC_BSPC, KC_4,    KC_5,    KC_6,    _______, _______, _______,
        _______, RGB_RMOD, _______, BL_DEC,  BL_TOGG, BL_INC,  _______, KC_1,    KC_2,    KC_3,    _______, KC_MUTE, KC_VOLU, _______,
        _______, _______,  _______, _______,                            _______, KC_0, KC_PDOT,    _______, KC_SLCK, KC_VOLD, KC_PAUS 
    ),

    [2] = LAYOUT_minila(
        _______, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
        _______, RGB_TOG,  RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______, _______,
        _______, RGB_MOD,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, RGB_RMOD, _______, BL_DEC,  BL_TOGG, BL_INC,  _______, _______, _______, _______, _______, _______, KC_PGUP, _______,
        _______, _______,  _______, _______,                            _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END 
    ),
};
