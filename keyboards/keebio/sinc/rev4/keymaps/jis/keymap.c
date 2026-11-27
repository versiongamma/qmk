#include "config.h"
#include QMK_KEYBOARD_H
#include "keymap_japanese.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEFAULT_LAYER] = LAYOUT_80_iso(
        KC_ESC,         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,           KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  TG(MACOS_LAYER),  _______,
        JP_ZKHK,        JP_1,    JP_2,    JP_3,    JP_4,    JP_5,    JP_6,            JP_7,    JP_8,    JP_9,    JP_0,    JP_MINS, JP_CIRC, JP_YEN,  KC_BSPC, KC_DEL,
        KC_TAB,         JP_Q,    JP_W,    JP_E,    JP_R,    JP_T,    JP_Y,            JP_U,    JP_I,    JP_O,    JP_P,    JP_AT,   JP_LBRC,                   KC_PGUP,
        LCTL_T(KC_ESC), JP_A,    JP_S,    JP_D,    JP_F,    JP_G,                     JP_H,    JP_J,    JP_K,    JP_L,    JP_SCLN, JP_COLN, JP_RBRC, KC_ENT,  KC_PGDN,
        KC_LSFT,        JP_BSLS, JP_Z,    JP_X,    JP_C,    JP_V,    JP_B,            JP_N,    JP_M,    JP_COMM, JP_DOT,  JP_SLSH, KC_LSFT, KC_UP,            MO(FN_LAYER),
        KC_LCTL,        KC_LGUI, KC_LALT, JP_MHEN, KC_SPC,  KC_SPC,                   KC_SPC,  KC_SPC,  JP_HENK, JP_KANA, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [MACOS_LAYER] = LAYOUT_80_iso(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        LGUI_T(KC_ESC), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_LALT, KC_LGUI, KC_LNG2, _______, _______,          _______, _______, KC_LNG1, _______, _______, _______, _______, _______
    ),
    [FN_LAYER] = LAYOUT_80_iso(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    tap_code(clockwise ? MS_WHLR : MS_WHLL);
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

    if (is_caps_word_on() || host_keyboard_led_state().caps_lock) {
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
