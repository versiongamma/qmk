#pragma once

#define DEFAULT_LAYER 0
#define MACOS_LAYER 1
#define NEW_LAYER 2
#define FN_LAYER 3

/** RGB Matrix settings for Layers */
// Default Layer
#define DEFAULT_RGB_MODE RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define DEFAULT_RGB_MODE_HSV 184, 255, 255
#define DEFAULT_RGB_MODE_SPEED 52 // Gradient Size

// MacOS Layer
#define MACOS_RGB_MODE RGB_MATRIX_GRADIENT_UP_DOWN
#define MACOS_RGB_MODE_HSV 217, 255, 255
#define MACOS_RGB_MODE_SPEED 56 // Gradient Size

// New Layer
#define NEW_RGB_MODE RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define NEW_RGB_MODE_HSV 0, 255, 119
#define NEW_RGB_MODE_SPEED 52

// FN Layer
#define FN_RGB_MODE RGB_MATRIX_SOLID_COLOR
#define FN_RGB_MODE_HSV 21, 255, 255

// FN Layer
#define FN_RGB_MODE RGB_MATRIX_SOLID_COLOR
#define FN_RGB_MODE_HSV 21, 255, 255

/** RGB Matrix settings for Keyboard States (will override all layer RGB settings) */
// Caps Word State
#define CAPS_WORD_STATE_RGB_MODE RGB_MATRIX_SOLID_COLOR
#define CAPS_WORD_STATE_RGB_MODE_HSV HSV_RED
