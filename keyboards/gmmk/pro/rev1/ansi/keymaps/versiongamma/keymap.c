#include <stdint.h>
#include QMK_KEYBOARD_H

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right

    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  MO(2),            TG(2),
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_INS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGUP,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(3),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    // MacOS
    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, KC_LALT, KC_LGUI,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    // Num
    [2] = LAYOUT(
        _______, KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_P5,   KC_P6,   KC_P7,   KC_P8,   KC_P9,   KC_P0,   _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    // Fn
    [3] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_MUTE, KC_VOLD, KC_VOLU, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, QK_BOOT, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),
};
// clang-format on

#ifdef OS_DETECTION_ENABLE
bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            layer_on(1);
            break;
        case OS_WINDOWS:
        case OS_LINUX:
        case OS_UNSURE:

            break;
    }

    return true;
}
#endif

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(MS_WHLL, MS_WHLR)},
    [1] = {ENCODER_CCW_CW(MS_WHLL, MS_WHLR)},
    [2] = {ENCODER_CCW_CW(MS_WHLL, MS_WHLR)},
    [3] = {ENCODER_CCW_CW(MS_WHLL, MS_WHLR)},
};
#endif

#ifdef RGB_MATRIX_ENABLE

#define ORANGE 255, 100, 0
#define PURPLE 125, 0, 255

const int NUM_RGB_KEYCODES[] =  { 7, 13, 19, 24, 29, 35, 40, 45, 51, 57 };

const int FN_RGB_KEYCODES[] = { 32, 50, 56, 61, 66 };
const int FN_RGB_KEYCODES_OFF[] = { 27, 31, 37, 38 };

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color_all(RGB_RED);
        return true;
    }

    rgb_matrix_set_color_all(PURPLE);

    switch (get_highest_layer(layer_state | default_layer_state)) {
        case 2:
            // rgb_matrix_set_color_all(RGB_BLACK);
            for (uint8_t code_index = 0; code_index < sizeof(NUM_RGB_KEYCODES) / sizeof(NUM_RGB_KEYCODES[0]); ++code_index) {
                rgb_matrix_set_color(NUM_RGB_KEYCODES[code_index], RGB_GREEN);
            }
            break;
        case 3:
            // rgb_matrix_set_color_all(RGB_BLACK);
            for (uint8_t code_index = 0; code_index < sizeof(FN_RGB_KEYCODES_OFF) / sizeof(FN_RGB_KEYCODES_OFF[0]); ++code_index) {
                rgb_matrix_set_color(FN_RGB_KEYCODES_OFF[code_index], RGB_BLACK);
            }
            for (uint8_t code_index = 0; code_index < sizeof(FN_RGB_KEYCODES) / sizeof(FN_RGB_KEYCODES[0]); ++code_index) {
                rgb_matrix_set_color(FN_RGB_KEYCODES[code_index], RGB_GREEN);
            }
            break;
    }

    return true;
}
#endif
