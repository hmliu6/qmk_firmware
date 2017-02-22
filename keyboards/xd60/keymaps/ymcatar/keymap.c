#include "xd60.h"
#include "action_layer.h"

enum {
  A = 0
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [A]  = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_ESC)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // 0: Base Layer
  KEYMAP(
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSLS,  KC_GRV,    \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC,           KC_BSPC,   \
      TD(A),   KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_NO,             KC_ENT,    \
      KC_LSPO, KC_NO,   KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_TRNS, KC_UP,    KC_DEL,    \
      MO(1),   KC_LALT, KC_LGUI,                          KC_SPC,                          MO(1),   KC_RSPC,  KC_LEFT, KC_DOWN,  KC_RIGHT),

  // 1: Function Layer
  KEYMAP(
      RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,   KC_F7,  KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  KC_F13,   KC_F14,    \
      KC_CAPS, KC_P7,   KC_P8,   KC_P9,   KC_NO,  KC_NO,  KC_NO,   KC_NO,  KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,             KC_DEL,    \
      KC_NO,   KC_P4,   KC_P5,   KC_P6,   KC_NO,  KC_NO,  KC_LEFT, KC_UP,  KC_DOWN, KC_RIGHT, KC_NO,   KC_NO,   KC_NO,             KC_NO,    \
      KC_NO,   KC_NO,   KC_P1,   KC_P2,   KC_P3,  KC_NO,  KC_NO,   KC_NO,  KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_MPLY, KC_VOLU,  KC_INS,    \
      KC_TRNS, KC_NO,   KC_P0,                            KC_NO,                              KC_TRNS, KC_NO,   KC_MPRV, KC_VOLD,  KC_MNXT),

  // 2: RGB Layer
  KEYMAP(
      KC_NO,   BL_TOGG, BL_STEP, KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO,    \
      KC_NO,   RGB_TOG, RGB_MOD, KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,    KC_NO,             KC_NO,    \
      KC_NO,   RGB_HUI, RGB_SAI, RGB_VAI, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,    KC_NO,             KC_NO,    \
      KC_NO,   KC_NO,   RGB_HUD, RGB_SAD, RGB_VAD,KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,    F(1),    KC_NO,    KC_NO,    \
      KC_NO,   KC_NO,   KC_NO,                            KC_NO,                           KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO),

};

// Custom Actions
const uint16_t PROGMEM fn_actions[] = {};

// Macros
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {

  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) { register_code(KC_RSFT); }
      else { unregister_code(KC_RSFT); }
      break;
  }

  return MACRO_NONE;
};

// Loop
void matrix_scan_user(void) {
  // Empty
};
