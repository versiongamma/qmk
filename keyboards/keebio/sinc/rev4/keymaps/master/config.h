#pragma once

#define DEFAULT_LAYER 0
#define MAC_OS_LAYER 1
#define FN_LAYER 2

// Default Lighting Settings
#define DEFAULT_MODE RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define DEFAULT_HSV 184, 255, 255
#define DEFAULT_SPEED 52 // Gradient Size

// Mac OS Layer Lighting Settings
#define MACOS_MODE RGB_MATRIX_GRADIENT_UP_DOWN
#define MACOS_HSV 217, 255, 255
#define MACOS_SPEED 56

// Caps Word State Lighting Settings
#define CAPS_WORD_MODE RGB_MATRIX_SOLID_COLOR
#define CAPS_WORD_HSV HSV_RED

#define FN_MODE RGB_MATRIX_BREATHING
#define FN_HSV 21, 255, 255
#define FN_SPEED 255
