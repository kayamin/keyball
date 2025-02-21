/*
 * Copyright 2022 @Yowkees
 * Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)
 * Copyright 2023 kamidai (@d_kamiichi)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * -------------------------------------------------------------------
 *
 * 参考文献：
 * - リポジトリ：
 *   https://github.com/kamiichi99/keyball/tree/main/qmk_firmware/keyboards/keyball/keyball39/keymaps/kamidai
 *
 * - keyballの販売ページ
 *   https://shirogane-lab.com/collections/all
 *
 * コード表：
 * - 公式ファームウェアのキーコード：
 *   KBC_RST(0x5DA5): Keyball 設定のリセット
 *   KBC_SAVE(0x5DA6): 現在の Keyball 設定を EEPROM に保存します
 *   CPI_I100(0x5DA7): CPI を 100 増加させます(最大:12000)
 *   CPI_D100(0x5DA8): CPI を 100 減少させます(最小:100)
 *   CPI_I1K(0x5DA9): CPI を 1000 増加させます(最大:12000)
 *   CPI_D1K(0x5DAA): CPI を 1000 減少させます(最小:100)
 *   SCRL_TO(0x5DAB): タップごとにスクロールモードの ON/OFF を切り替えます
 *   SCRL_MO(0x5DAC): キーを押している間、スクロールモードになります
 *   SCRL_DVI(0x5DAD): スクロール除数を１つ上げます(max D7 = 1/128)← 最もスクロール遅い
 *   SCRL_DVD(0x5DAE): スクロール除数を１つ下げます(min D0 = 1/1)← 最もスクロール速い
 *
 * - オリジナルのキーコード：
 *   KC_BACK_TO_LAYER0_BTN1(0x5DAF): レイヤー0に遷移できるBTN1
 *   KC_DOUBLE_CLICK_BTN1(0x5DB0): 1タップでダブルクリックできるBTN1
 *   KC_TRIPLE_CLICK_BTN1(0x5DB1): 1タップでトリプルクリックできるBTN1
 */

#include QMK_KEYBOARD_H
#include "quantum.h"

#include "features/macro_keys.h"
#include "features/combo.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default
  [0] = LAYOUT_universal(
    KC_Q   , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    OPT_T(KC_A)     , CTL_T(KC_S)     , SFT_T(KC_D), CMD_T(KC_F)   , KC_G,                 KC_H     , CMD_T(KC_J), SFT_T(KC_K) , CTL_T(KC_L)    , LT(3,KC_QUOTE)    ,
    KC_Z     , KC_X     , KC_C     ,KC_V    , KC_B,                                 KC_N     , KC_M     , KC_COMMA , KC_DOT   , LT(2,KC_QUESTION) ,
    KC_LSFT,_______,KC_LOPT,KC_TAB,LT(3,KC_SPACE),KC_MS_BTN1,     KC_BACKSPACE,LT(1,KC_ENT),_______,_______,_______,KC_LSFT
  ),

  [1] = LAYOUT_universal(
    KC_GRAVE  ,KC_0,KC_1,KC_2,KC_3,                                     KC_CIRCUMFLEX, KC_AMPERSAND, KC_MINUS, KC_EQUAL, KC_ASTERISK,
    KC_AT ,KC_EXCLAIM	,SFT_T(KC_4) ,CMD_T(KC_5) ,KC_6  ,                _______, KC_PRNTHS_CURSOR_LEFT, _______, LSFT(KC_SEMICOLON), KC_SEMICOLON,
    KC_DOLLAR, KC_HASH	, KC_7  , KC_8  ,KC_9,                               KC_CBRACKET_CURSOR_LEFT, KC_SBRACKET_CURSOR_LEFT, _______ , KC_PERCENT, KC_BACKSLASH,
    _______, _______, _______ , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , _______  , _______
  ),
  
  [2] = LAYOUT_universal(
    _______  , KC_F10  , KC_F1     , KC_F2     , KC_F3  ,                            _______  , SCRL_DVD , CPI_I100  , _______  ,_______ ,
    _______  , KC_F11  , KC_F4     , KC_F5     , KC_F6  ,                            _______  , SCRL_DVI  , CPI_D100    , _______     ,_______  ,
    _______  , KC_F12  , KC_F7     , KC_F8   , KC_F9  ,                    _______, _______ , _______     , _______     , _______  ,
    LSFT(LCMD(KC_S))  , KC_F13  , _______  , _______  , _______  , _______  ,      _______  , _______ , _______  , _______  , _______  , _______  
  ),

  [3] = LAYOUT_universal(
    _______  , KC_MISSION_CONTROL, LCTL(KC_LEFT), LCTL(KC_RIGHT), _______  ,                                    _______  , _______, KC_UP, _______, LCMD(KC_LEFT_BRACKET),
    LCTL(KC_A)  ,LCTL(KC_E) , _______, _______, _______  ,                                                       _______  , KC_LEFT  , KC_DOWN, KC_RIGHT, LCMD(KC_RIGHT_BRACKET),
     _______  , LCTL(LCMD(KC_DOT)), LCTL(LCMD(KC_LEFT)), LCTL(LCMD(KC_RIGHT)), LCTL(LCMD(KC_ENT)),                  _______  , LOPT(KC_LEFT) , _______  , LOPT(KC_RIGHT)  , _______  ,
    KC_LSFT, _______  , _______  , _______  , _______  , _______  ,                                                _______  , _______  , _______  , _______  , _______  , _______  
  ),

  [4] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  , 
    _______  , _______  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , _______  , _______  
   ),

  [5] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  ,                            _______  , SCRL_DVI , CPI_I100 , _______  , RGB_TOG  ,
    _______  , _______  , _______  , _______  , _______  ,                            SCRL_DVD , CPI_D100 , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,      _______  , KBC_RST  , _______  , _______  , _______  , _______  
  ),

  [6] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    KC_LALT  , KC_LSFT  , _______  ,KC_MS_BTN1, _______ ,                            _______  ,KC_MS_BTN1, _______ ,KC_MS_BTN2, _______  ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    LSFT(LCMD(KC_4)) , _______  , KC_LOPT , KC_MS_BTN1 , _______  , KC_LCMD  ,      _______  , _______  , _______  , _______  , _______  , _______  
  ) 
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
  // レイヤーが1または3の場合、スクロールモードが有効になる
  keyball_set_scroll_mode(get_highest_layer(state) == 1 || get_highest_layer(state) == 3);
  // keyball_set_scroll_mode(get_highest_layer(state) == 1);

  return state;
}

#ifdef OLED_ENABLE

#include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
  // デバッグ用に変数を表示する
  // oled_write_P(PSTR("Debug:"), false);
  // oled_write(get_u8_str(xxx, ' '), false);

  keyball_oled_render_keyinfo();   // キー情報を表示
  keyball_oled_render_ballinfo();  // トラックボール情報を表示

  // <Layer>を表示する
  oled_write_P(PSTR("Layer:"), false);
  oled_write(get_u8_str(get_highest_layer(layer_state), ' '), false);
}
#endif
