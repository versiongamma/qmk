#include "config.h"
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEFAULT_LAYER] = LAYOUT_80(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  TG(MACOS_LAYER),  _______,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,        KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  _______, KC_BSPC, KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,        KC_U,    KC_I,    KC_O,    KC_P,             KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
        CW_TOGG, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,        KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                   KC_ENT,  KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,             KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   MO(FN_LAYER),
        KC_LCTL, KC_LGUI, KC_LALT, KC_NO,   _______, KC_SPC,  _______,     KC_SPC,                    KC_NO,   KC_NO,   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [MACOS_LAYER] = LAYOUT_80(
        _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, KC_LALT, KC_LGUI, _______, _______, _______,              _______, _______,          _______, _______, _______, _______, _______, _______
    ),
    [FN_LAYER] = LAYOUT_80(
      _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,          _______, _______,
      _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,
      _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,          _______,
      _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______,          _______,          _______,
      _______,          _______, _______, _______, _______, _______,     _______, _______,          _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,              _______, _______,          _______, _______, _______, _______, _______, _______
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
            layer_on(MACOS_LAYER);
            break;
        case OS_WINDOWS:
        case OS_LINUX:
        case OS_UNSURE:
        default:
            break;
    }

    return true;
}

/** Setup RGB */

void keyboard_post_init_user(void) {
    rgb_matrix_enable_noeeprom();
}

bool rgb_matrix_indicators_user(void) {
    uint8_t currentMode = rgb_matrix_get_mode();

    if (is_caps_word_on()) {
         if (currentMode != CAPS_WORD_STATE_RGB_MODE) {
            rgb_matrix_mode_noeeprom(CAPS_WORD_STATE_RGB_MODE);
            rgb_matrix_sethsv_noeeprom(CAPS_WORD_STATE_RGB_MODE_HSV);
         }
        return true;
    }

    switch (get_highest_layer(layer_state | default_layer_state)) {
        case DEFAULT_LAYER:
        default:
            if (currentMode != DEFAULT_RGB_MODE) {
                rgb_matrix_mode_noeeprom(DEFAULT_RGB_MODE);
            }
            rgb_matrix_sethsv_noeeprom(DEFAULT_RGB_MODE_HSV);
            rgb_matrix_set_speed_noeeprom(DEFAULT_RGB_MODE_SPEED);
            break;

        case MACOS_LAYER:
            if (currentMode != MACOS_RGB_MODE) {
                rgb_matrix_mode_noeeprom(MACOS_RGB_MODE);
            }
            rgb_matrix_sethsv_noeeprom(MACOS_RGB_MODE_HSV);
            rgb_matrix_set_speed_noeeprom(MACOS_RGB_MODE_SPEED);
            break;

        case FN_LAYER:
            if (currentMode != FN_RGB_MODE) {
                rgb_matrix_mode_noeeprom(FN_RGB_MODE);
            }
            rgb_matrix_sethsv_noeeprom(FN_RGB_MODE_HSV);
            break;
    }
    return true;
}
