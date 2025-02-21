/* Copyright 2023 kamidai (@d_kamiichi)
 *
 * 参考ページ
 * 公式：https://docs.qmk.fm/#/ja/feature_combo?id=%e3%82%b3%e3%83%b3%e3%83%9c
 *
 * 注意： 以下の設定が必要です
 * rules.mk: COMBO_ENABLE = yes
 * config.h: #define COMBO_COUNT 2（=実際に設定するコンボ数）
 */

const uint16_t PROGMEM combo_ESC[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_CLICK[] = {KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM combo_RCLICK[] = {KC_COMMA, KC_DOT, COMBO_END};
// const uint16_t PROGMEM combo_CTRL_A[] = {KC_A, KC_S, COMBO_END};
// const uint16_t PROGMEM combo_CTRL_E[] = {KC_A, KC_R, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_ESC, KC_ESC),
    COMBO(combo_CLICK, KC_MS_BTN1),
    COMBO(combo_RCLICK, KC_MS_BTN2),
    // COMBO(combo_CTRL_A, LCTL(KC_A)),
    // COMBO(combo_CTRL_E, LCTL(KC_E)),
};
