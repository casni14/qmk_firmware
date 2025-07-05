// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keycodes.h"
#include QMK_KEYBOARD_H /* already pulls in key-override header */
#include "print.h"
#include "keymap_danish.h"

void keyboard_post_init_user(void) {
    uprintf("➡️ Debug console ready!\n");
}

// Left hand home row mods
#define CTL_A LCTL_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define GUI_D LGUI_T(KC_D)
#define SFT_F LSFT_T(KC_F)

// Right hand home row mods
#define SFT_J RSFT_T(KC_J)
#define GUI_K RGUI_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define CTL_SCLN LCTL_T(KC_SCLN)

enum layers {
    _BASE,
    _DANISH,
    _FN1,
    _FN2,
    _FN3,
    _FN4,
    _FN5,
    _FN6,
    _FN7,
    _FN8,
};
//
enum custom_keycodes {
    TMUX_1 = SAFE_RANGE,
    TMUX_2,
    TMUX_3,
    TMUX_4,
    TMUX_5,
    TMUX_6,
    TMUX_7,
    TMUX_8,
    TMUX_9,
    TMUX_0,
    OS_SH_L1,
    OS_SH_L2,
    CMD_DANISH
};

const uint16_t PROGMEM danish_combo[] = { CTL_A, ALT_S, GUI_D, SFT_F, COMBO_END };

combo_t key_combos[] = {
    COMBO(danish_combo, CMD_DANISH),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌─────────────────────┬───────┬───────┬───────┬──────────┬──────────┐               ┌──────────┬──────────┬───────┬───────┬──────────┬──────┐
//    │         esc         │   q   │   w   │   e   │    r     │    t     │               │    y     │    u     │   i   │   o   │    p     │ bspc │
//    ├─────────────────────┼───────┼───────┼───────┼──────────┼──────────┤               ├──────────┼──────────┼───────┼───────┼──────────┼──────┤
//    │         tab         │ CTL_A │ ALT_S │ GUI_D │  SFT_F   │    g     │               │    h     │  SFT_J   │ GUI_K │ ALT_L │ CTL_SCLN │  '   │
//    ├─────────────────────┼───────┼───────┼───────┼──────────┼──────────┤               ├──────────┼──────────┼───────┼───────┼──────────┼──────┤
//    │ QK_CAPS_WORD_TOGGLE │   z   │   x   │   c   │    v     │    b     │               │    n     │    m     │   ,   │   .   │    /     │ esc  │
//    └─────────────────────┴───────┴───────┴───────┼──────────┼──────────┼─────┐   ┌─────┼──────────┼──────────┼───────┴───────┴──────────┴──────┘
//                                                  │ MO(_FN6) │ OS_SH_L2 │ spc │   │ ent │ OS_SH_L1 │ MO(_FN4) │
//                                                  └──────────┴──────────┴─────┘   └─────┴──────────┴──────────┘
[_BASE] = LAYOUT_split_3x6_3(
  KC_ESC              , KC_Q  , KC_W  , KC_E  , KC_R     , KC_T     ,                       KC_Y     , KC_U     , KC_I    , KC_O   , KC_P     , KC_BSPC,
  KC_TAB              , CTL_A , ALT_S , GUI_D , SFT_F    , KC_G     ,                       KC_H     , SFT_J    , GUI_K   , ALT_L  , CTL_SCLN , KC_QUOT,
  QK_CAPS_WORD_TOGGLE , KC_Z  , KC_X  , KC_C  , KC_V     , KC_B     ,                       KC_N     , KC_M     , KC_COMM , KC_DOT , KC_SLSH  , KC_ESC ,
                                                MO(_FN6) , OS_SH_L2 , KC_SPC ,     KC_ENT , OS_SH_L1 , MO(_FN4)
),

//    ┌──────┬───────┬───────┬───────┬──────────┬──────────┐               ┌──────────┬──────────┬───────┬───────┬───────┬─────────┐
//    │ esc  │   q   │   w   │   e   │    r     │    t     │               │    y     │    u     │   i   │   o   │   p   │ DK_ARNG │
//    ├──────┼───────┼───────┼───────┼──────────┼──────────┤               ├──────────┼──────────┼───────┼───────┼───────┼─────────┤
//    │ tab  │ CTL_A │ ALT_S │ GUI_D │  SFT_F   │    g     │               │    h     │  SFT_J   │ GUI_K │ ALT_L │ DK_AE │ DK_OSTR │
//    ├──────┼───────┼───────┼───────┼──────────┼──────────┤               ├──────────┼──────────┼───────┼───────┼───────┼─────────┤
//    │ lsft │   z   │   x   │   c   │    v     │    b     │               │    n     │    m     │   ,   │   .   │   /   │  bspc   │
//    └──────┴───────┴───────┴───────┼──────────┼──────────┼─────┐   ┌─────┼──────────┼──────────┼───────┴───────┴───────┴─────────┘
//                                   │ MO(_FN6) │ MO(_FN2) │ spc │   │ ent │ OS_SH_L1 │ MO(_FN4) │
//                                   └──────────┴──────────┴─────┘   └─────┴──────────┴──────────┘
[_DANISH] = LAYOUT_split_3x6_3(
  KC_ESC  , KC_Q  , KC_W  , KC_E  , KC_R     , KC_T     ,                       KC_Y     , KC_U     , KC_I    , KC_O   , KC_P    , DK_ARNG,
  KC_TAB  , CTL_A , ALT_S , GUI_D , SFT_F    , KC_G     ,                       KC_H     , SFT_J    , GUI_K   , ALT_L  , DK_AE   , DK_OSTR,
  KC_LSFT , KC_Z  , KC_X  , KC_C  , KC_V     , KC_B     ,                       KC_N     , KC_M     , KC_COMM , KC_DOT , KC_SLSH , KC_BSPC,
                                    MO(_FN6) , MO(_FN2) , KC_SPC ,     KC_ENT , OS_SH_L1 , MO(_FN4)
),

//    ┌──────┬────┬────┬──────┬──────┬──────────┐               ┌──────┬──────┬────┬──────┬────┬──────┐
//    │ tab  │ 1  │ 2  │  3   │  4   │    5     │               │  6   │  7   │ 8  │  9   │ 0  │ bspc │
//    ├──────┼────┼────┼──────┼──────┼──────────┤               ├──────┼──────┼────┼──────┼────┼──────┤
//    │ lctl │ no │ no │ pgdn │ pgup │    no    │               │ left │ down │ up │ rght │ no │  no  │
//    ├──────┼────┼────┼──────┼──────┼──────────┤               ├──────┼──────┼────┼──────┼────┼──────┤
//    │ lsft │ no │ no │  no  │  no  │    no    │               │  no  │  no  │ no │  no  │ no │  no  │
//    └──────┴────┴────┴──────┼──────┼──────────┼─────┐   ┌─────┼──────┼──────┼────┴──────┴────┴──────┘
//                            │ lgui │ MO(_FN3) │ spc │   │ ent │      │ ralt │
//                            └──────┴──────────┴─────┘   └─────┴──────┴──────┘
[_FN1] = LAYOUT_split_3x6_3(
  KC_TAB  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5     ,                       KC_6    , KC_7    , KC_8    , KC_9     , KC_0    , KC_BSPC,
  KC_LCTL , XXXXXXX , XXXXXXX , KC_PGDN , KC_PGUP , XXXXXXX  ,                       KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , XXXXXXX , XXXXXXX,
  KC_LSFT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  ,                       XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  , XXXXXXX , XXXXXXX,
                                          KC_LGUI , MO(_FN3) , KC_SPC ,     KC_ENT , _______ , KC_RALT
),

//    ┌──────┬────┬────┬────┬──────┬─────┐               ┌──────────┬──────────┬───┬───┬───┬──────┐
//    │ tab  │ !  │ @  │ #  │  $   │  %  │               │    ^     │    &     │ * │ ( │ ) │ bspc │
//    ├──────┼────┼────┼────┼──────┼─────┤               ├──────────┼──────────┼───┼───┼───┼──────┤
//    │ lctl │ no │ no │ no │  no  │ no  │               │    -     │    =     │ [ │ ] │ \ │  `   │
//    ├──────┼────┼────┼────┼──────┼─────┤               ├──────────┼──────────┼───┼───┼───┼──────┤
//    │ lsft │ no │ no │ no │  no  │ no  │               │    _     │    +     │ { │ } │ | │  ~   │
//    └──────┴────┴────┴────┼──────┼─────┼─────┐   ┌─────┼──────────┼──────────┼───┴───┴───┴──────┘
//                          │ lgui │     │ spc │   │ ent │ MO(_FN3) │ MO(_FN5) │
//                          └──────┴─────┴─────┘   └─────┴──────────┴──────────┘
[_FN2] = LAYOUT_split_3x6_3(
  KC_TAB  , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC ,                       KC_CIRC  , KC_AMPR  , KC_ASTR , KC_LPRN , KC_RPRN , KC_BSPC,
  KC_LCTL , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                       KC_MINS  , KC_EQL   , KC_LBRC , KC_RBRC , KC_BSLS , KC_GRV ,
  KC_LSFT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                       KC_UNDS  , KC_PLUS  , KC_LCBR , KC_RCBR , KC_PIPE , KC_TILD,
                                          KC_LGUI , _______ , KC_SPC ,     KC_ENT , MO(_FN3) , MO(_FN5)
),

//    ┌─────────┬──────┬──────┬────┬──────┬─────┐               ┌─────┬──────────┬─────┬─────┬────┬────┐
//    │ QK_BOOT │ bRMD │ bRMU │ no │  no  │ no  │               │ f9  │   f10    │ f11 │ f12 │ no │ no │
//    ├─────────┼──────┼──────┼────┼──────┼─────┤               ├─────┼──────────┼─────┼─────┼────┼────┤
//    │   no    │  no  │  no  │ no │  no  │ no  │               │ no  │    no    │ no  │ no  │ no │ no │
//    ├─────────┼──────┼──────┼────┼──────┼─────┤               ├─────┼──────────┼─────┼─────┼────┼────┤
//    │   no    │  no  │  no  │ no │  no  │ no  │               │ no  │    no    │ no  │ no  │ no │ no │
//    └─────────┴──────┴──────┴────┼──────┼─────┼─────┐   ┌─────┼─────┼──────────┼─────┴─────┴────┴────┘
//                                 │ lgui │     │ spc │   │ ent │     │ MO(_FN5) │
//                                 └──────┴─────┴─────┘   └─────┴─────┴──────────┘
[_FN3] = LAYOUT_split_3x6_3(
  QK_BOOT , KC_BRMD , KC_BRMU , XXXXXXX , XXXXXXX , XXXXXXX ,                       KC_F9   , KC_F10   , KC_F11  , KC_F12  , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                       XXXXXXX , XXXXXXX  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                       XXXXXXX , XXXXXXX  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
                                          KC_LGUI , _______ , KC_SPC ,     KC_ENT , _______ , MO(_FN5)
),

//    ┌────────────┬─────────┬─────────┬─────────┬──────────┬──────────┐               ┌─────────┬─────────┬─────────┬─────────┬─────────┬────────────┐
//    │ LALT(esc)  │ LALT(q) │ LALT(w) │ LALT(e) │ LALT(r)  │ LALT(t)  │               │ LALT(y) │ LALT(u) │ LALT(i) │ LALT(o) │ LALT(p) │ LALT(bspc) │
//    ├────────────┼─────────┼─────────┼─────────┼──────────┼──────────┤               ├─────────┼─────────┼─────────┼─────────┼─────────┼────────────┤
//    │ LALT(tab)  │ LALT(a) │ LALT(s) │ LALT(d) │ LALT(f)  │ LALT(g)  │               │ LALT(h) │ LALT(j) │ LALT(k) │ LALT(l) │ LALT(;) │  LALT(')   │
//    ├────────────┼─────────┼─────────┼─────────┼──────────┼──────────┤               ├─────────┼─────────┼─────────┼─────────┼─────────┼────────────┤
//    │ LALT(lsft) │ LALT(z) │ LALT(x) │ LALT(c) │ LALT(v)  │ LALT(b)  │               │ LALT(n) │ LALT(m) │ LALT(,) │ LALT(.) │ LALT(/) │ LALT(esc)  │
//    └────────────┴─────────┴─────────┴─────────┼──────────┼──────────┼─────┐   ┌─────┼─────────┼─────────┼─────────┴─────────┴─────────┴────────────┘
//                                               │ MO(_FN8) │ MO(_FN5) │ spc │   │ ent │   no    │         │
//                                               └──────────┴──────────┴─────┘   └─────┴─────────┴─────────┘
[_FN4] = LAYOUT_split_3x6_3(
  LALT(KC_ESC)  , LALT(KC_Q) , LALT(KC_W) , LALT(KC_E) , LALT(KC_R) , LALT(KC_T) ,                       LALT(KC_Y) , LALT(KC_U) , LALT(KC_I)    , LALT(KC_O)   , LALT(KC_P)    , LALT(KC_BSPC),
  LALT(KC_TAB)  , LALT(KC_A) , LALT(KC_S) , LALT(KC_D) , LALT(KC_F) , LALT(KC_G) ,                       LALT(KC_H) , LALT(KC_J) , LALT(KC_K)    , LALT(KC_L)   , LALT(KC_SCLN) , LALT(KC_QUOT),
  LALT(KC_LSFT) , LALT(KC_Z) , LALT(KC_X) , LALT(KC_C) , LALT(KC_V) , LALT(KC_B) ,                       LALT(KC_N) , LALT(KC_M) , LALT(KC_COMM) , LALT(KC_DOT) , LALT(KC_SLSH) , LALT(KC_ESC) ,
                                                         MO(_FN8)   , MO(_FN5)   , KC_SPC ,     KC_ENT , XXXXXXX    , _______
),

//    ┌─────┬─────────┬─────────┬─────────┬─────────┬─────────┐               ┌─────────┬─────────┬─────────┬─────────┬─────────┬────┐
//    │ esc │ LALT(1) │ LALT(2) │ LALT(3) │ LALT(4) │ LALT(5) │               │ LALT(6) │ LALT(7) │ LALT(8) │ LALT(9) │ LALT(0) │ no │
//    ├─────┼─────────┼─────────┼─────────┼─────────┼─────────┤               ├─────────┼─────────┼─────────┼─────────┼─────────┼────┤
//    │ no  │   no    │   no    │   no    │   no    │   no    │               │   no    │   no    │   no    │   no    │   no    │ no │
//    ├─────┼─────────┼─────────┼─────────┼─────────┼─────────┤               ├─────────┼─────────┼─────────┼─────────┼─────────┼────┤
//    │ no  │   no    │   no    │   no    │   no    │   no    │               │   no    │   no    │   no    │   no    │   no    │ no │
//    └─────┴─────────┴─────────┴─────────┼─────────┼─────────┼─────┐   ┌─────┼─────────┼─────────┼─────────┴─────────┴─────────┴────┘
//                                        │  lgui   │         │ spc │   │ spc │   no    │         │
//                                        └─────────┴─────────┴─────┘   └─────┴─────────┴─────────┘
[_FN5] = LAYOUT_split_3x6_3(
  KC_ESC  , LALT(KC_1) , LALT(KC_2) , LALT(KC_3) , LALT(KC_4) , LALT(KC_5) ,                       LALT(KC_6) , LALT(KC_7) , LALT(KC_8) , LALT(KC_9) , LALT(KC_0) , XXXXXXX,
  XXXXXXX , XXXXXXX    , XXXXXXX    , XXXXXXX    , XXXXXXX    , XXXXXXX    ,                       XXXXXXX    , XXXXXXX    , XXXXXXX    , XXXXXXX    , XXXXXXX    , XXXXXXX,
  XXXXXXX , XXXXXXX    , XXXXXXX    , XXXXXXX    , XXXXXXX    , XXXXXXX    ,                       XXXXXXX    , XXXXXXX    , XXXXXXX    , XXXXXXX    , XXXXXXX    , XXXXXXX,
                                                   KC_LGUI    , _______    , KC_SPC ,     KC_SPC , XXXXXXX    , _______
),

//    ┌────────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                     ┌──────────┬──────────┬─────────┬─────────┬─────────┬────────────┐
//    │ LGUI(esc)  │ LGUI(q) │ LGUI(w) │ LGUI(e) │ LGUI(r) │ LGUI(t) │                     │ LGUI(y)  │ LGUI(u)  │ LGUI(i) │ LGUI(o) │ LGUI(p) │ LGUI(bspc) │
//    ├────────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                     ├──────────┼──────────┼─────────┼─────────┼─────────┼────────────┤
//    │ LGUI(tab)  │ LGUI(a) │ LGUI(s) │ LGUI(d) │ LGUI(f) │ LGUI(g) │                     │ LGUI(h)  │ LGUI(j)  │ LGUI(k) │ LGUI(l) │ LGUI(;) │  LGUI(')   │
//    ├────────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                     ├──────────┼──────────┼─────────┼─────────┼─────────┼────────────┤
//    │ LGUI(lsft) │ LGUI(z) │ LGUI(x) │ LGUI(c) │ LGUI(v) │ LGUI(b) │                     │ LGUI(n)  │ LGUI(m)  │ LGUI(,) │ LGUI(.) │ LGUI(/) │ LGUI(esc)  │
//    └────────────┴─────────┴─────────┴─────────┼─────────┼─────────┼─────┐   ┌───────────┼──────────┼──────────┼─────────┴─────────┴─────────┴────────────┘
//                                               │         │   no    │ spc │   │ LGUI(spc) │ MO(_FN7) │ MO(_FN8) │
//                                               └─────────┴─────────┴─────┘   └───────────┴──────────┴──────────┘
[_FN6] = LAYOUT_split_3x6_3(
  LGUI(KC_ESC)  , LGUI(KC_Q) , LGUI(KC_W) , LGUI(KC_E) , LGUI(KC_R) , LGUI(KC_T) ,                             LGUI(KC_Y) , LGUI(KC_U) , LGUI(KC_I)    , LGUI(KC_O)   , LGUI(KC_P)    , LGUI(KC_BSPC),
  LGUI(KC_TAB)  , LGUI(KC_A) , LGUI(KC_S) , LGUI(KC_D) , LGUI(KC_F) , LGUI(KC_G) ,                             LGUI(KC_H) , LGUI(KC_J) , LGUI(KC_K)    , LGUI(KC_L)   , LGUI(KC_SCLN) , LGUI(KC_QUOT),
  LGUI(KC_LSFT) , LGUI(KC_Z) , LGUI(KC_X) , LGUI(KC_C) , LGUI(KC_V) , LGUI(KC_B) ,                             LGUI(KC_N) , LGUI(KC_M) , LGUI(KC_COMM) , LGUI(KC_DOT) , LGUI(KC_SLSH) , LGUI(KC_ESC) ,
                                                         _______    , XXXXXXX    , KC_SPC ,     LGUI(KC_SPC) , MO(_FN7)   , MO(_FN8)
),

//    ┌────────────┬─────────┬─────────┬─────────┬─────────┬─────────┐               ┌─────────┬─────────┬─────────┬─────────┬─────────┬────────────┐
//    │ LGUI(esc)  │ LGUI(1) │ LGUI(2) │ LGUI(3) │ LGUI(4) │ LGUI(5) │               │ LGUI(6) │ LGUI(7) │ LGUI(8) │ LGUI(9) │ LGUI(0) │ LGUI(bspc) │
//    ├────────────┼─────────┼─────────┼─────────┼─────────┼─────────┤               ├─────────┼─────────┼─────────┼─────────┼─────────┼────────────┤
//    │ LGUI(tab)  │ LGUI(a) │ LGUI(s) │ LGUI(d) │ LGUI(f) │ LGUI(g) │               │ LGUI(h) │ LGUI(j) │ LGUI(k) │ LGUI(l) │ LGUI(;) │  LGUI(')   │
//    ├────────────┼─────────┼─────────┼─────────┼─────────┼─────────┤               ├─────────┼─────────┼─────────┼─────────┼─────────┼────────────┤
//    │ LGUI(lsft) │ LGUI(z) │ LGUI(x) │ LGUI(c) │ LGUI(v) │ LGUI(b) │               │ LGUI(n) │ LGUI(m) │ LGUI(,) │ LGUI(.) │ LGUI(/) │ LGUI(esc)  │
//    └────────────┴─────────┴─────────┴─────────┼─────────┼─────────┼─────┐   ┌─────┼─────────┼─────────┼─────────┴─────────┴─────────┴────────────┘
//                                               │         │   no    │ spc │   │ ent │         │   no    │
//                                               └─────────┴─────────┴─────┘   └─────┴─────────┴─────────┘
[_FN7] = LAYOUT_split_3x6_3(
  LGUI(KC_ESC)  , LGUI(KC_1) , LGUI(KC_2) , LGUI(KC_3) , LGUI(KC_4) , LGUI(KC_5) ,                       LGUI(KC_6) , LGUI(KC_7) , LGUI(KC_8)    , LGUI(KC_9)   , LGUI(KC_0)    , LGUI(KC_BSPC),
  LGUI(KC_TAB)  , LGUI(KC_A) , LGUI(KC_S) , LGUI(KC_D) , LGUI(KC_F) , LGUI(KC_G) ,                       LGUI(KC_H) , LGUI(KC_J) , LGUI(KC_K)    , LGUI(KC_L)   , LGUI(KC_SCLN) , LGUI(KC_QUOT),
  LGUI(KC_LSFT) , LGUI(KC_Z) , LGUI(KC_X) , LGUI(KC_C) , LGUI(KC_V) , LGUI(KC_B) ,                       LGUI(KC_N) , LGUI(KC_M) , LGUI(KC_COMM) , LGUI(KC_DOT) , LGUI(KC_SLSH) , LGUI(KC_ESC) ,
                                                         _______    , XXXXXXX    , KC_SPC ,     KC_ENT , _______    , XXXXXXX
),

//    ┌────────────┬─────────┬─────────┬─────────┬─────────┬─────────┐               ┌─────────┬─────────┬─────────┬─────────┬─────────┬───────────┐
//    │ LGUI(esc)  │ TMUX_1  │ TMUX_2  │ TMUX_3  │ TMUX_4  │ TMUX_5  │               │ TMUX_6  │ TMUX_7  │ TMUX_8  │ TMUX_9  │ TMUX_0  │   bspc    │
//    ├────────────┼─────────┼─────────┼─────────┼─────────┼─────────┤               ├─────────┼─────────┼─────────┼─────────┼─────────┼───────────┤
//    │ LGUI(tab)  │ LGUI(a) │ LGUI(s) │ LGUI(d) │ LGUI(f) │ LGUI(g) │               │ LGUI(h) │ LGUI(j) │ LGUI(k) │ LGUI(l) │ LGUI(;) │  LGUI(')  │
//    ├────────────┼─────────┼─────────┼─────────┼─────────┼─────────┤               ├─────────┼─────────┼─────────┼─────────┼─────────┼───────────┤
//    │ LGUI(lsft) │ LGUI(z) │ LGUI(x) │ LGUI(c) │ LGUI(v) │ LGUI(b) │               │ LGUI(n) │ LGUI(m) │ LGUI(,) │ LGUI(.) │ LGUI(/) │ LGUI(esc) │
//    └────────────┴─────────┴─────────┴─────────┼─────────┼─────────┼─────┐   ┌─────┼─────────┼─────────┼─────────┴─────────┴─────────┴───────────┘
//                                               │         │   no    │ spc │   │ ent │   no    │         │
//                                               └─────────┴─────────┴─────┘   └─────┴─────────┴─────────┘
[_FN8] = LAYOUT_split_3x6_3(
  LGUI(KC_ESC)  , TMUX_1     , TMUX_2     , TMUX_3     , TMUX_4     , TMUX_5     ,                       TMUX_6     , TMUX_7     , TMUX_8        , TMUX_9       , TMUX_0        , KC_BSPC      ,
  LGUI(KC_TAB)  , LGUI(KC_A) , LGUI(KC_S) , LGUI(KC_D) , LGUI(KC_F) , LGUI(KC_G) ,                       LGUI(KC_H) , LGUI(KC_J) , LGUI(KC_K)    , LGUI(KC_L)   , LGUI(KC_SCLN) , LGUI(KC_QUOT),
  LGUI(KC_LSFT) , LGUI(KC_Z) , LGUI(KC_X) , LGUI(KC_C) , LGUI(KC_V) , LGUI(KC_B) ,                       LGUI(KC_N) , LGUI(KC_M) , LGUI(KC_COMM) , LGUI(KC_DOT) , LGUI(KC_SLSH) , LGUI(KC_ESC) ,
                                                         _______    , XXXXXXX    , KC_SPC ,     KC_ENT , XXXXXXX    , _______
)
};

// A little flag to remember if the last key pressed was MO(1)
static bool    other_was_mo1     = false;
static bool    first_was_shift   = false;
static bool    first_was_command = false;
static bool    other_was_command = false;
static uint8_t keys_down         = 0;

static uint16_t os_timer;  // for OS_SH_L1 tap/hold timing

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    uprintf("PRE  code:0x%04X %s\n", keycode, record->event.pressed ? "DOWN" : "UP");
    if (keycode == MO(_FN1)) {
        other_was_mo1 = record->event.pressed;
        uprintf("  → other_was_mo1 = %u\n", other_was_mo1);
    }
    if (keycode == GUI_D || keycode == GUI_K) {
        other_was_command = record->event.pressed;
    }
    if (record->event.pressed) {
        // about to go from N→N+1 down-keys
        if (keys_down == 0) {
            // this really _is_ the first key in the chord
            first_was_shift   = (keycode == SFT_F || keycode == SFT_J);
            first_was_command = (keycode == GUI_D || keycode == GUI_K);
        }
        keys_down++;
    } else {
        // key-release: count goes down
        if (keys_down) keys_down--;
        // when everyone’s up, clear for next chord
        if (keys_down == 0) {
            first_was_shift   = false;
            first_was_command = false;
        }
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        // ────── TMUX session shortcuts ──────
        case TMUX_1:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "1");
            }
            return false;
        case TMUX_2:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "2");
            }
            return false;
        case TMUX_3:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "3");
            }
            return false;
        case TMUX_4:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "4");
            }
            return false;
        case TMUX_5:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "5");
            }
            return false;
        case TMUX_6:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "6");
            }
            return false;
        case TMUX_7:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "7");
            }
            return false;
        case TMUX_8:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "8");
            }
            return false;
        case TMUX_9:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "9");
            }
            return false;
        case TMUX_0:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "0");
            }
            return false;

        // ────── Tap = One-shot Shift, Hold = Layer 1 ──────
        case OS_SH_L1:
            if (record->event.pressed) {
                // Key-down: start timer and activate layer
                os_timer = timer_read();
                layer_on(_FN1);
            } else {
                // Key-up: decide tap vs hold
                if (timer_elapsed(os_timer) < TAPPING_TERM
                    && !record->tap.interrupted) {
                    // It was a tap: cancel layer and set one-shot Shift
                    layer_off(_FN1);
                    set_oneshot_mods(MOD_LSFT);
                } else {
                    // It was a hold: just turn layer off
                    layer_off(_FN1);
                }
            }
            return false;
        case OS_SH_L2:
            if (record->event.pressed) {
                // Key-down: start timer and activate layer
                os_timer = timer_read();
                layer_on(_FN2);
            } else {
                // Key-up: decide tap vs hold
                if (timer_elapsed(os_timer) < TAPPING_TERM
                    && !record->tap.interrupted) {
                    // It was a tap: cancel layer and set one-shot Shift
                    layer_off(_FN2);
                    set_oneshot_mods(MOD_LSFT);
                } else {
                    // It was a hold: just turn layer off
                    layer_off(_FN2);
                }
            }
            return false;
        case CMD_DANISH:
            if (record->event.pressed) {
                default_layer_set(_DANISH);
            }
            return false;

        default:
            return true;  // process all other keycodes normally
    }
}



uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    uint16_t term;
    switch (keycode) {
        case SFT_F:
        case SFT_J:
            term = TAPPING_TERM + 50;
            break;
        case CTL_A:
        case CTL_SCLN:
        case ALT_S:
        case ALT_L:
        case GUI_D:
        case GUI_K:
            term = TAPPING_TERM - 50;
            break;
        default:
            term = TAPPING_TERM;
    }
    if (record->event.pressed) {
        uprintf("TERM  code:0x%04X → %u\n", keycode, term);
    }
    return term;
}

#ifdef CHORDAL_HOLD
bool get_chordal_hold(uint16_t tap_hold_kc, keyrecord_t *tap_hold_rec, uint16_t other_kc, keyrecord_t *other_rec) {
    switch (tap_hold_kc) {
        case SFT_F:
        case SFT_J:
            return get_chordal_hold_default(tap_hold_rec, other_rec);
        default:
            return false; // same-hand OK for all others
    }
}
#endif

#ifdef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    if (!other_was_mo1 && !other_was_command) return false; // only special-case MO(1)

    if (other_was_mo1) {
        switch (keycode) {
            /* non-shift home-row mods */
            case ALT_L:
                register_mods(MOD_BIT(KC_LALT));
                return true;
            case CTL_A:
                register_mods(MOD_BIT(KC_LCTL));
                return true;
            case CTL_SCLN:
                register_mods(MOD_BIT(KC_LCTL));
                return true;
            case ALT_S:
                register_mods(MOD_BIT(KC_LALT));
                return true;
            case GUI_D:
                register_mods(MOD_BIT(KC_LGUI));
                return true;
            case GUI_K:
                register_mods(MOD_BIT(KC_RGUI));
                return true;
            default:
                return false; // Shifts & others
        }
    } else if (other_was_command) {
        switch (keycode) {
            /* non-shift home-row mods */
            case KC_V:
                register_mods(MOD_BIT(KC_LGUI));
                return true;
            default:
                return false; // Shifts & others
        }
    }
    return false;
}
#endif

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) return; // only care about key-up

    switch (keycode) {
        case ALT_L:
            unregister_mods(MOD_BIT(KC_LALT));
            break;
        case CTL_A:
            unregister_mods(MOD_BIT(KC_LCTL));
            break;
        case CTL_SCLN:
            unregister_mods(MOD_BIT(KC_LCTL));
            break;
        case ALT_S:
            unregister_mods(MOD_BIT(KC_LALT));
            break;
        case GUI_D:
            unregister_mods(MOD_BIT(KC_LGUI));
            break;
        case GUI_K:
            unregister_mods(MOD_BIT(KC_RGUI));
            break;
    }
}

#ifdef PERMISSIVE_HOLD_PER_KEY
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /* Disable early-hold on the four non-shift home-row mods */
        case CTL_A:
        case ALT_S:
        case CTL_SCLN:
        case ALT_L:
            return false; // treat as tap unless actually held past TAPPING_TERM
        /* Keep current special-case rules for Shift / ⌘ */
        case SFT_F:
        case SFT_J:
            return first_was_shift ? false : true;
        case GUI_D:
        case GUI_K:
            return first_was_command ? true : true;
        default:
            return true; // default permissive-hold behaviour
    }
}
#endif
