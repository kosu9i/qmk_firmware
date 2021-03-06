/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include"keymap_jp.h"

//#define TAPPING_TERM 200

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  SECRET
};

// NOTE: To define macros that has sensitive information is supremely bad idea!!
//#define SECRETSTR "xxxxxxxxxxxxx"

// cf. https://github.com/qmk/qmk_firmware/blob/master/quantum/keymap_extras/keymap_jp.h
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT_split_3x6_3(
  //[0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    JP_Q,    JP_W,    JP_E,    JP_R,    JP_T,                         JP_Y,    JP_U,    JP_I,    JP_O,   JP_P,  JP_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    JP_A,    JP_S,    JP_D,    JP_F,    JP_G,                         JP_H,    JP_J,    JP_K,    JP_L, JP_SCLN, JP_COLN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    JP_Z,    JP_X,    JP_C,    JP_V,    JP_B,                         JP_N,    JP_M, JP_COMM,  JP_DOT, JP_SLSH, KC_LSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   LOWER,  KC_SPC,     KC_ENT,   RAISE, KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [L_LOWER] = LAYOUT_split_3x6_3(
  //[2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    JP_1,    JP_2,    JP_3,    JP_4,    JP_5,                         JP_6,    JP_7,    JP_8,    JP_9,    JP_0, JP_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, JP_PLUS, JP_ASTR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  JP_SLSH, KC_LSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [L_RAISE] = LAYOUT_split_3x6_3(
  //[1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, JP_EXLM, JP_DQUO, JP_HASH,  JP_DLR, JP_PERC,                      JP_AMPR, JP_LPRN, JP_RPRN, JP_CIRC,  JP_YEN, JP_MINS,  
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, JP_DQUO, JP_QUOT, JP_GRV,  XXXXXXX,                      KC_BSPC, JP_LBRC, JP_RBRC, JP_TILD,   JP_AT, JP_PIPE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       JP_EQL, JP_LCBR, JP_RCBR,  JP_DOT, JP_SLSH, JP_UNDS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [L_ADJUST] = LAYOUT_split_3x6_3(
  //[3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      RGB_TOG, RGB_M_P, RGB_M_B, RGB_M_R,RGB_M_SW,RGB_M_SN,                      RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, EEP_RST,   RESET,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,                      KC_BSPC, KC_VOLD, KC_VOLU, KC_MUTE, XXXXXXX, XXXXXXX, 
  //|--------+--------+--------+--------+--------+-                            |--------+--------+--------+--------+--------+--------|
      KC_LSFT,RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,                      XXXXXXX, KC_SLCK, KC_PAUS, XXXXXXX, XXXXXXX,  SECRET,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )

};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_master) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }
    return rotation;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_master) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//  if (record->event.pressed) {
//    set_keylog(keycode, record);
//  }
//  return true;
//}

#endif // OLED_DRIVER_ENABLE

//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//  if (record->event.pressed) {
//    set_keylog(keycode, record);
//  }
//  switch (keycode) {
//#ifdef SECRETSTR
//    case SECRET:
//      if (record->event.pressed) {
//        // when keycode QMKBEST is pressed
//          SEND_STRING(SECRETSTR"\n");
//        } //else {
//          // when keycode QMKBEST is released
//        //}
//      break;
//#endif // SECRETSTR
//    default:
//      break;
//  }
//  return true;
//}

// cf. https://gist.github.com/okapies/5d13a174cbb13ce34dbd9faede9d0b71#file-keymap-c-L99-L164
// https://okapies.hateblo.jp/entry/2019/02/02/133953

static bool lower_pressed = false;
static uint16_t lower_pressed_time = 0;
static bool raise_pressed = false;
static uint16_t raise_pressed_time = 0;

// cf. https://blog.magcho.com/2020/4/qmk_firmware%E3%81%A7ctrl%E3%81%A8%E3%81%AE%E5%90%8C%E6%99%82%E6%8A%BC%E3%81%97%E3%82%92%E3%82%AB%E3%82%B9%E3%82%BF%E3%83%9E%E3%82%A4%E3%82%BA%E3%81%99%E3%82%8B/
static bool ctrl_pressed = false;
static bool exceptionaly_ctrl_layer_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_DRIVER_ENABLE
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
#endif // OLED_DRIVER_ENABLE
    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                lower_pressed = true;
                lower_pressed_time = record->event.time;

                layer_on(L_LOWER);
                update_tri_layer(L_LOWER, L_RAISE, L_ADJUST);
            } else {
                layer_off(L_LOWER);
                update_tri_layer(L_LOWER, L_RAISE, L_ADJUST);

                if (lower_pressed) {
                //if (lower_pressed && (TIMER_DIFF_16(record->event.time, lower_pressed_time) < TAPPING_TERM)) {
                    register_code(KC_LANG2); // for macOS
                    //register_code(KC_MHEN);
                    //unregister_code(KC_MHEN);
                    unregister_code(KC_LANG2);
                }
                lower_pressed = false;
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                raise_pressed = true;
                raise_pressed_time = record->event.time;

                layer_on(L_RAISE);
                update_tri_layer(L_LOWER, L_RAISE, L_ADJUST);
            } else {
                layer_off(L_RAISE);
                update_tri_layer(L_LOWER, L_RAISE, L_ADJUST);

                if (raise_pressed) {
                //if (raise_pressed && (TIMER_DIFF_16(record->event.time, raise_pressed_time) < TAPPING_TERM)) {
                    register_code(KC_LANG1); // for macOS
                    //register_code(KC_HENK);
                    //unregister_code(KC_HENK);
                    unregister_code(KC_LANG1);
                }
                raise_pressed = false;
            }
            return false;
            break;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(L_ADJUST);
            } else {
                layer_off(L_ADJUST);
            }
            return false;
            break;
        case KC_LCTRL:
            if (record->event.pressed) {
                ctrl_pressed = true;
            } else {
                ctrl_pressed = false;
            }
            break;
#ifdef SECRETSTR
        case SECRET:
            if (record->event.pressed) {
                // when keycode is pressed
                    SEND_STRING(SECRETSTR);
                } //else {
                    // when keycode is released
                //}
            break;
#endif // SECRETSTR
        default:
            if (ctrl_pressed || exceptionaly_ctrl_layer_pressed) {
                switch (keycode) {
                    case KC_H:
                        if (record->event.pressed) {
                            unregister_code(KC_LCTRL);
                            register_code(KC_BSPACE);
                            exceptionaly_ctrl_layer_pressed = true;
                        } else {
                            unregister_code(KC_BSPACE);
                            if (ctrl_pressed) {
                                register_code(KC_LCTRL);
                            }
                            exceptionaly_ctrl_layer_pressed = false;
                        }
                        return false;
                        break;
                }
            }
            if (record->event.pressed) {
                // reset the flags
                lower_pressed = false;
                raise_pressed = false;
            }
            break;
    }
    return true;
}
