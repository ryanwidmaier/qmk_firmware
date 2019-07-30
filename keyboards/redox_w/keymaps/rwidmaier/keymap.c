#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define LINUX 0
#define MACOS 1
#define SYMBOL 2
#define NAVNUM 3

// enum custom_keycodes {
//   QWERTY = SAFE_RANGE,
//   MACOS,
//   SYMBOL,
//   NAV
// };

// Shortcut to make keymap more readable
#define KC_BKSL KC_BSLASH

// Linux
#define L_COPY  LCTL(KC_C)
#define L_CUT   LCTL(KC_X)
#define L_PASTE LCTL(KC_V)
#define L_FIND  LCTL(KC_F)
#define L_CTL   LCTL_T(KC_HOME)
#define L_ALT   LALT_T(KC_END)


// Mac-OS
#define M_COPY  LCMD(KC_C)
#define M_CUT   LCMD(KC_X)
#define M_PASTE LCMD(KC_V)
#define M_FIND  LCMD(KC_F)
#define M_CMD   LCMD_T(KC_HOME)
#define M_CTL   LCTL_T(KC_END)

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
#define LPAR  S(KC_9)
#define RPAR  S(KC_0) 
#define TILDA S(KC_GRV)
#define LT_B  LT(NAVNUM, KC_B)
#define LT_N  LT(SYMBOL, KC_N)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Linux Base layer
 *
 * ,-------------------------------------------.                         --------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |------.           ,------|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------   ~  |           | ` ~  +------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |------|           |------|   Y  |   U  |   I  |   O  |   P  |  \ |   |
 * |--------+------+------+------+------+------| Home |           |   =  |------+------+------+------+------+--------|
 * |   +    |   A  |   S  |   D  |   F  |   G  |      |           |      |   H  |   J  |   K  |   L  |  ; : | ' /Cmd |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   (    |   Z  |   X  |   C  |   V  | B /L1|------'           `------| N /L2|   M  |   ,  |   .  |  / ? |    )   |
 * `--------+------+------+------+------+-------                         -------+------+------+------+------+--------'
 *   |  Cp  |  Cut | Paste| Left | Right  |                                   |   Up   | Down | Find | Tmux |NAVNUM|
 *   `------------------------------------'                                   `------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Ctl/Hm| Del  |       | Tab  |Alt/En|
 *                                        |------|------|       |------+------|         
 *                                        |      |      |       |      |      |         
 *                                        |Shift | Bksp |       |Enter | Space|         
 *                                        |      |      |       |      |      |         
 *                                        `-------------'       `-------------'         
 */
[LINUX] = LAYOUT(
  //┌──────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC    ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINUS,
  //├──────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB    ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,TILDA   ,                          KC_GRV  ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSLS ,
  //├──────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_KP_PLUS,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_HOME ,                          KC_EQL  ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,GUI_T(KC_QUOT),
  //├──────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     LPAR      ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,LT_B    ,L_CTL   ,KC_DELETE,       KC_TAB  ,L_ALT   ,LT_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH , RPAR   ,
  //├──────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     L_COPY    ,L_CUT   ,L_PASTE ,KC_LEFT ,     KC_RGHT ,    KC_LSHIFT,KC_BSPC,        KC_ENT  ,KC_SPC  ,    KC_UP   ,     KC_DOWN ,L_FIND  ,TMUX    ,TG(NAVNUM) 
  //└──────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

/* Keymap 1: Macos Base layer
 *
 * ,-------------------------------------------.                         --------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |------.           ,------|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------   ~  |           | ` ~  +------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |------|           |------|   Y  |   U  |   I  |   O  |   P  | \ |    |
 * |--------+------+------+------+------+------| Home |           |   =  |------+------+------+------+------+--------|
 * |   +    |   A  |   S  |   D  |   F  |   G  |      |           |      |   H  |   J  |   K  |   L  |  ; : | ' /Cmd |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   (    |   Z  |   X  |   C  |   V  | B /L1|------'           `------| N /L2|   M  |   ,  |   .  |  / ? |    )   |
 * `--------+------+------+------+------+------'                         `------+------+------+------+------+--------'
 *   |  Cp  |  Cut | Paste| Left | Right|                                       |  Up  | Down | Find | Tmux | Del  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Cmd/Hm| Del  |       | Tab  |Ctl/En|
 *                                        |------|------|       |------+------|       
 *                                        |      |      |       |      |      |       
 *                                        |Shift | Bksp |       |Enter |Space |       
 *                                        |      |      |       |      |      |       
 *                                        --------------'       `-------------'        
 */

[MACOS] = LAYOUT(
  //┌──────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC    ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINUS,
  //├──────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB    ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,TILDA   ,                          KC_GRV  ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSLS ,
  //├──────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_KP_PLUS,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_HOME ,                          KC_EQL  ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,GUI_T(KC_QUOT),
  //├──────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     LPAR      ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,LT_B    ,M_CMD   ,KC_DELETE,       KC_TAB  ,M_CTL   ,LT_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH , RPAR   ,
  //├──────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     M_COPY    ,M_CUT   ,M_PASTE ,KC_LEFT ,     KC_RGHT ,    KC_LSHIFT,KC_BSPC,        KC_ENT  ,KC_SPC  ,    KC_UP   ,     KC_DOWN ,M_FIND  ,TMUX    ,TG(NAVNUM) 
  //└──────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

/* Keymap 2: Numpad and navigation
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |------.           ,------|  F7  |  F8  |  F9  |  F10 |  F11 |   F12  |
 * |--------+------+------+------+------+------|      |           |  F6  +------+------+------+------+------+--------|
 * |        |      | Home |  Up  |  End | PgUp |------|           |------|   Up |   7  |   8  |   9  |   /  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Left | Down | Right| PgDn |      |           |      | Down |   4  |   5  |   6  |   *  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |  L0  |------'           `------|      |   1  |   2  |   3  |   -  |        |
 * `--------+------+------+------+------+------'                         `------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |    . |   =  |   +  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                        |------|------|       |------+------+       
 *                                        |      |      |       |      |      |       
 *                                        |      |      |       |      |      |       
 *                                        |      |      |       |      |      |       
 *                                        `-------------'       `--------------       
 */
 // Navigation and numpad
[NAVNUM] = LAYOUT(
  //┌──────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______   ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,
  //├──────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______   ,_______ ,KC_HOME ,KC_UP   ,KC_END  ,KC_PGUP ,_______ ,                         KC_F6    ,KC_UP   ,KC_7    ,KC_8    ,KC_9    ,KC_SLSH ,_______ ,
  //├──────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______   ,_______ ,KC_LEFT ,KC_DOWN ,KC_RGHT ,KC_PGDN ,_______ ,                          _______ ,KC_DOWN ,KC_4    ,KC_5    ,KC_6    ,KC_ASTR ,_______ ,
  //├──────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______   ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,        _______ ,_______ ,_______ ,KC_1    ,KC_2    ,KC_3    ,KC_MINS ,_______ ,
  //├──────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______   ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    KC_0    ,     KC_DOT  ,KC_EQL  ,KC_PLUS ,_______ 
  //└──────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

/* Keymap 3: Symbol Layer
 * !@#$%~`^&*-_
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |------.           ,------|  F7  |  F8  |  F9  |  F10 |  F11 |   F12  |
 * |--------+------+------+------+------+------|      |           |  F6  +------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |      |------|           |------|      |   %  |   }  |      |      | L-MACOS|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |    -   |   ^  |   $  |   [  |   ]  |   |  |      |           |      |      |   #  |   ]  |      |      | L-LINUX|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |   _  |   &  |      |------'           `------|  L0  |   $  |   &  |      |      |        |
 * `--------+------+------+------+------+------'                         `------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                        |------|------|       |------+------|       
 *                                        |      |      |       |      |      |       
 *                                        |      |      |       |      |      |       
 *                                        |      |      |       |      |      |       
 *                                        `-------------'       `-------------'       
 */
// SYMBOLS
[SYMBOL] = LAYOUT(
  //┌──────────┬────────┬────────┬──────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______   ,KC_F1   ,KC_F2   ,KC_F3     ,KC_F4   ,KC_F5   ,                                            KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,
  //├──────────┼────────┼────────┼──────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______   ,KC_EXLM ,KC_AT   ,KC_LCBR   ,KC_RCBR ,_______ ,_______ ,                          _______ ,_______ ,KC_PERC ,KC_RCBR ,_______ ,_______ ,DF(MACOS),
  //├──────────┼────────┼────────┼──────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MINS   ,KC_CIRC ,KC_DLR  ,KC_LBRC   ,KC_RBRC ,KC_PIPE ,_______ ,                          _______ ,_______ ,KC_HASH ,KC_RBRC ,_______ ,_______ ,DF(LINUX),
  //├──────────┼────────┼────────┼──────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______   ,_______ ,_______ ,S(KC_MINS),KC_AMPR ,_______ ,_______ ,_______ ,        _______ ,_______ ,_______ ,KC_DLR  ,KC_AMPR ,_______ ,_______ ,_______ ,
  //├──────────┼────────┼────────┼──────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______   ,_______ ,_______ ,_______   ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______ 
  //└──────────┴────────┴────────┴──────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )
};

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    switch (layer) {
        case LINUX:
            set_led_off;
            break;
        case MACOS:
            set_led_red;
            break;
        case SYMBOL:
            set_led_blue;
            break;
        case NAVNUM:
            set_led_green;
            break;
        default:
            break;
    }
};


