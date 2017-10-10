#include "gh60.h"
#include "action_layer.h"
#include "rgblight.h"

#define _DEFAULT 0
#define _FN 1
#define _WASD 2
#define _SFX 3

#define NUCLEAR MT(MOD_LCTL, KC_ESC)

//bool esc_led_on;

enum planck_keycodes {
  DEFAULT = SAFE_RANGE
};

// Fillers to make layering more clear
#define ______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty gui/alt/space/alt/gui
 * ,-----------------------------------------------------------------------------------------.
 * | `   |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  |     |
 * |-----------------------------------------------------------------------------------------+
 * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |  Bksp  |
 * |-----------------------------------------------------------------------------------------+
 * | Ctrl    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
 * |-----------------------------------------------------------------------------------------+
 * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | RShift          |
 * |-----------------------------------------------------------------------------------------+
 * | LAlt  |LGUI | Func  |               Space                | RAlt   |    |    |   RCTL    |
 * `-----------------------------------------------------------------------------------------'
 */
  [_DEFAULT] = KEYMAP_HHKB( /* Basic QWERTY */
      KC_GRV,  KC_1,    KC_2,    KC_3, KC_4, KC_5,   KC_6, KC_7, KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, ______, \
      KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R, KC_T,   KC_Y, KC_U, KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,  \
      NUCLEAR, KC_A,    KC_S,    KC_D, KC_F, KC_G,   KC_H, KC_J, KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  \
      KC_LSFT, KC_Z,    KC_X,    KC_C, KC_V, KC_B,   KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, ______, \
      KC_LALT, KC_LGUI, MO(_FN),             KC_SPC,             KC_RALT, ______, ______,  KC_RCTL \
      ),

/* Vim-inspired FN Layer
 * ,-----------------------------------------------------------------------------------------.
 * |     | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |     |     |
 * |-----------------------------------------------------------------------------------------+
 * |        |     | Play|     |     |     |     | PgUp|     |     |     |     |     |        |
 * |-----------------------------------------------------------------------------------------+
 * |         | Prev|Pause| Next|     |     |Left | Up  |Down |Right|     |     |     |       |
 * |-----------------------------------------------------------------------------------------+
 * | CAPS      |Vol- |Mute |Vol+|     |     |     | PgDn       |    |     |     CAPS         |
 * |-----------------------------------------------------------------------------------------+
 *         |       |       |                                 |       |       |
 *         `-----------------------------------------------------------------'
 */
  [_FN] = KEYMAP_HHKB( /* Layer 1 */
      KC_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12, ______,  ______, \
      ______, ______,  KC_MPLY,  ______,  ______, ______, ______, KC_PGUP, ______, ______, ______, ______,  ______, KC_DEL,  \
      ______,  KC_MPRV, KC_PAUS, KC_MNXT, ______, ______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, ______, ______, ______,   \
      KC_CAPS,  KC_VOLD, KC_MUTE, KC_VOLU, ______, ______, KC_PGDN, ______, ______, ______, ______, KC_CAPS, ______,  \
      ______,  ______,  ______,                   TG(_WASD),                   ______, ______,  ______,  ______ \
      ),

/* WASD Layer
 * ,-----------------------------------------------------------------------------------------.
 * |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----------------------------------------------------------------------------------------+
 * |        |     | Up  |     |     |     |     |     |     |     |     |     |     |        |
 * |-----------------------------------------------------------------------------------------+
 * |         | Left| Down|Right|     |     |     |     |     |     |     |     |             |
 * |-----------------------------------------------------------------------------------------+
 * |           |     |     |     |     |     |     |     |      |    |     |           |     |
 * |-----------------------------------------------------------------------------------------+
 *         |       |       |                                 |       |       |
 *         `-----------------------------------------------------------------'
 */
  [_WASD] = KEYMAP_HHKB( /* Layer 2 */
      ______,   ______,  ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,  ______, \
      ______,   ______,  KC_UP,  ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,  \
      ______,   KC_LEFT, KC_DOWN,KC_RGHT,______, ______, ______, ______, ______, ______, ______, ______, ______,   \
      ______,   ______,  ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,______,  \
      ______,   ______,  ______,                ______,                 ______, ______, ______, ______ \
      ),

/* SFX Layer
 * ,-----------------------------------------------------------------------------------------.
 * |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----------------------------------------------------------------------------------------+
 * |        | BL- | BL+ | BL  |     |     |     |     |     |     |     |     |     |        |
 * |-----------------------------------------------------------------------------------------+
 * |         | RGBT| RGBM|     |     |     |     |     |     |     |     |     |             |
 * |-----------------------------------------------------------------------------------------+
 * |           | Hue+| Hue-| Sat+| Sat-| Val+| Val-|     |      |    |     |           |     |
 * |-----------------------------------------------------------------------------------------+
 *         |       |       |                                 |       |       |
 *         `-----------------------------------------------------------------'
 */
  [_SFX] = KEYMAP_HHKB(
      ______,   ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, \
      ______,   ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,  \
      ______,   F(0),   F(1),   ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,   \
      ______,   F(2),   F(3),   F(4),   F(5),   F(6),   F(7),   ______, ______, ______, ______, ______, ______,  \
      ______,   ______, ______,                 ______,                 ______, ______, ______, ______ \
      )
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  return MACRO_NONE;
};

enum function_id {
    RGBLED_TOGGLE,
    RGBLED_STEP_MODE,
    RGBLED_INCREASE_HUE,
    RGBLED_DECREASE_HUE,
    RGBLED_INCREASE_SAT,
    RGBLED_DECREASE_SAT,
    RGBLED_INCREASE_VAL,
    RGBLED_DECREASE_VAL
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(RGBLED_TOGGLE),
  [1]  = ACTION_FUNCTION(RGBLED_STEP_MODE),
  [2]  = ACTION_FUNCTION(RGBLED_INCREASE_HUE),
  [3]  = ACTION_FUNCTION(RGBLED_DECREASE_HUE),
  [4]  = ACTION_FUNCTION(RGBLED_INCREASE_SAT),
  [5]  = ACTION_FUNCTION(RGBLED_DECREASE_SAT),
  [6]  = ACTION_FUNCTION(RGBLED_INCREASE_VAL),
  [7]  = ACTION_FUNCTION(RGBLED_DECREASE_VAL)
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
    case RGBLED_TOGGLE:
      if (record->event.pressed) {
        rgblight_toggle();
      }
      break;
    case RGBLED_INCREASE_HUE:
      if (record->event.pressed) {
        rgblight_increase_hue();
      }
      break;
    case RGBLED_DECREASE_HUE:
      if (record->event.pressed) {
        rgblight_decrease_hue();
      }
      break;
    case RGBLED_INCREASE_SAT:
      if (record->event.pressed) {
        rgblight_increase_sat();
      }
      break;
    case RGBLED_DECREASE_SAT:
      if (record->event.pressed) {
        rgblight_decrease_sat();
      }
      break;
    case RGBLED_INCREASE_VAL:
      if (record->event.pressed) {
        rgblight_increase_val();
      }
      break;
    case RGBLED_DECREASE_VAL:
      if (record->event.pressed) {
        rgblight_decrease_val();
      }
      break;
    case RGBLED_STEP_MODE:
      if (record->event.pressed) {
        rgblight_step();
      }
      break;
  }
}

void matrix_scan_user(void) {
    uint32_t layer = layer_state;

    if (layer & (1<<1)) {
        gh60_fn_led_on();
    } else {
        gh60_fn_led_off();
    }

    if (layer & (1<<2)) {
        gh60_wasd_leds_on();
    } else {
        gh60_wasd_leds_off();
    }

    if (layer & (1<<3)) {
        gh60_esc_led_on();
    } else {
        gh60_esc_led_off();
    }
};
