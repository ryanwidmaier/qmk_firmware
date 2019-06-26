#include QMK_KEYBOARD_H
#include "version.h"
 
#define LINUX 0  // Base Layer for Linux
#define MACOS 1  // Base layer for MacOS
#define NAVNUM 2 // Navigation + Numpad
#define SYMB 3 // Symbol Layer

/////////////////////////////////////////////
// Custom keys 

// Linux
#define L_COPY  LCTL(KC_C)
#define L_CUT   LCTL(KC_X)
#define L_PASTE LCTL(KC_V)
#define L_FIND  LCTL(KC_F)

// Mac-OS
#define M_COPY  LCMD(KC_C)
#define M_CUT   LCMD(KC_X)
#define M_PASTE LCMD(KC_V)
#define M_FIND  LCMD(KC_F)

// Define mac key names for readability
#define LOPT  LALT
#define KC_LOPT KC_LALT
#define KC_ROPT KC_RALT
#define MOD_LOPT MOD_LALT
#define MOD_ROPT MOD_RALT
#define MOD_LCMD MOD_LGUI
#define MOD_RCMD MOD_RGUI

// Works on both
#define TMUX  LCTL(KC_B)


enum custom_keycodes {
  EPRM = SAFE_RANGE,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Linux Base layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |   ~  |           | ` ~  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |  L1  |           |   =  |   Y  |   U  |   I  |   O  |   P  |  \ |   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   +    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ; : | ' /Cmd |
 * |--------+------+------+------+------+------| Ctl  |           | Alt  |------+------+------+------+------+--------|
 * |   (    |   Z  |   X  |   C  |   V  | B /L1|      |           |      | N /L2|   M  |   ,  |   .  |  / ? |    )   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  Cp  |  Cut | Paste| Left | Right|                                       |  Up  | Down | Find | Tmux | Del  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | ???  |      |       |      | ???  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | Shift|Backsp|------|       |------| Enter  |Space |
 *                                 |      |ace   |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[LINUX] = LAYOUT_ergodox(
        // left hand
        KC_ESC,         KC_1,       KC_2,       KC_3,   KC_4,   KC_5,            S(KC_GRV),
        KC_TAB,         KC_Q,       KC_W,       KC_E,   KC_R,   KC_T,            TG(NAVNUM),
        KC_KP_PLUS,     KC_A,       KC_S,       KC_D,   KC_F,   KC_G,
        S(KC_9),        KC_Z,       KC_X,       KC_C,   KC_V,   LT(NAVNUM,KC_B), KC_LCTRL,
        L_COPY,         L_CUT,      L_PASTE,    KC_LEFT,KC_RGHT,
                                                       KC_TRNS,  KC_TRNS,
                                                                 KC_TRNS,
                                               KC_LSHIFT,KC_BSPC,KC_TRNS,
        // right hand  
       KC_GRV,      KC_6,           KC_7,   KC_8,    KC_9,       KC_0,       KC_MINS,
       KC_EQL,      KC_Y,           KC_U,   KC_I,    KC_O,       KC_P,       KC_BSLS,
                    KC_H,           KC_J,   KC_K,    KC_L,       KC_SCLN,    GUI_T(KC_QUOT),
       KC_RALT,     LT(SYMB, KC_N), KC_M,   KC_COMM, KC_DOT,     KC_SLSH,    S(KC_0),
                                    KC_UP,  KC_DOWN, L_FIND,     TMUX,       KC_DELETE,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_ENT, KC_SPC
    ),

/* Keymap 1: Macos Base layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |   ~  |           | ` ~  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |  L1  |           |   =  |   Y  |   U  |   I  |   O  |   P  | \ |    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   +    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ; : | ' /Cmd |
 * |--------+------+------+------+------+------| Cmd  |           | Ctl  |------+------+------+------+------+--------|
 * |   (    |   Z  |   X  |   C  |   V  | B /L1|      |           |      | N /L2|   M  |   ,  |   .  |  / ? |    )   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  Cp  |  Cut | Paste| Left | Right|                                       |  Up  | Down | Find | Tmux | Del  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | ???  |      |       |      | Opt  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | Shift|Backsp|------|       |------| Enter  |Space |
 *                                 |      |ace   |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[MACOS] = LAYOUT_ergodox(
        // left hand
        KC_ESC,             KC_1,       KC_2,       KC_3,   KC_4,   KC_5,            S(KC_GRV),
        KC_TAB,             KC_Q,       KC_W,       KC_E,   KC_R,   KC_T,            TG(NAVNUM),
        KC_KP_PLUS,         KC_A,       KC_S,       KC_D,   KC_F,   KC_G,
        S(KC_9),            KC_Z,       KC_X,       KC_C,   KC_V,   LT(NAVNUM,KC_B), KC_LCMD,
        M_COPY,             M_CUT,      M_PASTE,    KC_LEFT,KC_RGHT,
                                                          KC_TRNS, KC_TRNS,
                                                                   KC_TRNS,
                                               KC_LSHIFT, KC_BSPC, KC_TRNS,
        // right hand  
       KC_GRV,      KC_6,           KC_7,   KC_8,    KC_9,       KC_0,       KC_MINS,
       KC_EQL,      KC_Y,           KC_U,   KC_I,    KC_O,       KC_P,       KC_BSLS,
                    KC_H,           KC_J,   KC_K,    KC_L,       KC_SCLN,    GUI_T(KC_QUOT),
       KC_LCTRL,    LT(SYMB, KC_N), KC_M,   KC_COMM, KC_DOT,     KC_SLSH,    S(KC_0),
                                    KC_UP,  KC_DOWN, M_FIND,     TMUX,       KC_DELETE,
       KC_TRNS,  KC_TRNS,
       KC_TRNS,
       KC_TRNS,  KC_ENT, KC_SPC
    ),

/* Keymap 2: Numpad and navigation
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |   F12  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | Home |  Up  |  End | PgUp |  L0  |           |      |   Up |   7  |   8  |   9  |   /  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Left | Down | Right| PgDn |------|           |------| Down |   4  |   5  |   6  |   *  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |  L0  |      |           |      |      |   1  |   2  |   3  |   -  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |    . |   =  |   +  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
 // Navigation and numpad
[NAVNUM] = LAYOUT_ergodox(
       KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_HOME,  KC_UP,    KC_END,   KC_PGUP,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PGDN,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_F6,   KC_F7,   KC_F8,  KC_F9,   KC_F10,  KC_F11,   KC_F12,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_SLSH,  KC_TRNS,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_ASTR,  KC_TRNS,
       KC_TRNS, KC_TRNS, KC_1,   KC_2,    KC_3,    KC_MINS,  KC_TRNS,
                         KC_0,   KC_DOT,  KC_EQL,  KC_PLUS,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 3: Symbol Layer
 * !@#$%~`^&*-_
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |   F12  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |      |      |           |      |      |   %  |   }  |      |      | L-MACOS|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |    -   |   ^  |   $  |   [  |   ]  |   |  |------|           |------|      |   #  |   ]  |      |      | L-LINUX|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |   _  |   &  |      |      |           |      |  L0  |   $  |   &  |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,  KC_F1,    KC_F2,    KC_F3,       KC_F4,    KC_F5,    KC_TRNS,
       KC_TRNS,  KC_EXLM,  KC_AT,    KC_LCBR,     KC_RCBR,  KC_TRNS,  KC_TRNS,
       KC_MINS,  KC_CIRC,  KC_DLR,   KC_LBRC,     KC_RBRC,  KC_PIPE,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  S(KC_MINS),  KC_AMPR,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_F6,   KC_F7,   KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
       KC_TRNS, KC_TRNS, KC_PERC,  KC_RCBR,  KC_TRNS,  KC_TRNS,  DF(MACOS),
                KC_TRNS, KC_HASH,  KC_RBRC,  KC_TRNS,  KC_TRNS,  DF(LINUX),
       KC_TRNS, KC_TRNS, KC_DLR,   KC_AMPR,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                         KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
)
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
//    [2] = ACTION_LAYER_TAP_TOGGLE(NAVNUM)              // FN2 - Momentary Layer 2 (Navnum)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
