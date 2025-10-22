// Copyright 2023 Danny Nguyen (danny@keeb.io)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "config.h"
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DEFAULT_LAYER] = LAYOUT_80(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           TG(1),   _______,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  _______, KC_BSPC, KC_DEL,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,             KC_LBRC, KC_RBRC, KC_BSLS, KC_INS,
    CW_TOGG, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                   KC_ENT,  KC_PGUP,
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,             KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
    KC_LCTL, KC_LGUI, KC_LALT,          KC_SPC, KC_SPC,   KC_SPC,  KC_SPC,  KC_SPC,           KC_RALT, MO(2),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [MAC_OS_LAYER] = LAYOUT_80(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, KC_LALT, KC_LGUI,          _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______
  ),
  [FN_LAYER] = LAYOUT_80(
    _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, _______, _______, _______, _______, QK_RBT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          QK_BOOT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
    _______,          _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
    _______, _______, _______,          _______, _______, _______, _______, _______,          _______, _______, KC_SLEP, _______, _______, _______
  ),
};


bool encoder_update_user(uint8_t index, bool clockwise) {
    tap_code(clockwise ? MS_WHLL : MS_WHLR);
    return false;
}

bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            layer_on(MAC_OS_LAYER);
            break;
        case OS_WINDOWS:
        case OS_LINUX:
        case OS_UNSURE:
            break;
    }

    return true;
}

void keyboard_post_init_user(void) {
    rgb_matrix_enable_noeeprom();
}

bool rgb_matrix_indicators_user(void) {
    uint8_t currentMode = rgb_matrix_get_mode();

    if (is_caps_word_on()) {
         if (currentMode != CAPS_WORD_MODE) {
            rgb_matrix_mode_noeeprom(CAPS_WORD_MODE);
            rgb_matrix_sethsv(CAPS_WORD_HSV);
         }
        return true;
    }

    switch (get_highest_layer(layer_state | default_layer_state)) {
        case DEFAULT_LAYER:
        default:
            if (currentMode != DEFAULT_MODE) {
                rgb_matrix_sethsv_noeeprom(DEFAULT_HSV);
                rgb_matrix_set_speed_noeeprom(DEFAULT_SPEED);
                rgb_matrix_mode_noeeprom(DEFAULT_MODE);
            }
            break;

        case MAC_OS_LAYER:
            if (currentMode != MACOS_MODE) {
                rgb_matrix_sethsv_noeeprom(MACOS_HSV);
                rgb_matrix_set_speed_noeeprom(MACOS_SPEED);
                rgb_matrix_mode_noeeprom(MACOS_MODE);
            }
            break;

        case FN_LAYER:
            if (currentMode != FN_MODE) {
                rgb_matrix_sethsv_noeeprom(FN_HSV);
                rgb_matrix_set_speed_noeeprom(FN_SPEED);
                rgb_matrix_mode_noeeprom(FN_MODE);
            }
            break;
    }
    return true;
}
