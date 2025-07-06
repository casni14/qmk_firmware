// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include <stdbool.h>
#include "caps_word.h"
#include "keycodes.h"
#include "process_tap_dance.h"
#include "progmem.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H /* already pulls in key-override header */
#include "print.h"
#include <unicodemap.h>

void keyboard_post_init_user(void) {
    set_unicode_input_mode(UNICODE_MODE_MACOS); // unicode_input_mode = UC_WINC;  // ← Windows 10/11 unicode_input_mode = UC_LNX;   // ← Linux, X11/Wayland
    uprintf("➡️ Debug console ready!\n");
    uprintf("mode %u\\n", get_unicode_input_mode());
}

//≠≠é
#define UNICODE_SELECTED_MODES UNICODE_MODE_MACOS
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
#define ENT_SFT LSFT_T(KC_ENT)

enum unicode_names {
    AE_LOWER,
    AE_UPPER,
    OE_LOWER,
    OE_UPPER,
    AA_LOWER,
    AA_UPPER,
};

const uint32_t PROGMEM unicode_map[] = {
    [AE_LOWER] = 0x00E6, [AE_UPPER] = 0x00C6, [OE_LOWER] = 0x00D8, [OE_UPPER] = 0x00D8, [AA_LOWER] = 0x00D8, [AA_UPPER] = 0x00D8,
};

enum layers {
    _BASE,
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
    TMUX_C,
    TMUX_X,
    OS_SH_L1,
    OS_SH_L2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌─────────────────────┬───────┬───────┬───────┬──────────┬──────────┐                   ┌──────────┬──────────┬───────┬───────┬──────────┬──────┐
//    │         esc         │   q   │   w   │   e   │    r     │    t     │                   │    y     │    u     │   i   │   o   │    p     │ bspc │
//    ├─────────────────────┼───────┼───────┼───────┼──────────┼──────────┤                   ├──────────┼──────────┼───────┼───────┼──────────┼──────┤
//    │         tab         │ CTL_A │ ALT_S │ GUI_D │  SFT_F   │    g     │                   │    h     │  SFT_J   │ GUI_K │ ALT_L │ CTL_SCLN │  '   │
//    ├─────────────────────┼───────┼───────┼───────┼──────────┼──────────┤                   ├──────────┼──────────┼───────┼───────┼──────────┼──────┤
//    │ QK_CAPS_WORD_TOGGLE │   z   │   x   │   c   │    v     │    b     │                   │    n     │    m     │   ,   │   .   │    /     │ esc  │
//    └─────────────────────┴───────┴───────┴───────┼──────────┼──────────┼─────┐   ┌─────────┼──────────┼──────────┼───────┴───────┴──────────┴──────┘
//                                                  │ MO(_FN6) │ OS_SH_L2 │ spc │   │ ENT_SFT │ OS_SH_L1 │ MO(_FN4) │
//                                                  └──────────┴──────────┴─────┘   └─────────┴──────────┴──────────┘
[_BASE] = LAYOUT_split_3x6_3(
  KC_ESC              , KC_Q  , KC_W  , KC_E  , KC_R     , KC_T     ,                        KC_Y     , KC_U     , KC_I    , KC_O   , KC_P     , KC_BSPC,
  KC_TAB              , CTL_A , ALT_S , GUI_D , SFT_F    , KC_G     ,                        KC_H     , SFT_J    , GUI_K   , ALT_L  , CTL_SCLN , KC_QUOT,
  QK_CAPS_WORD_TOGGLE , KC_Z  , KC_X  , KC_C  , KC_V     , KC_B     ,                        KC_N     , KC_M     , KC_COMM , KC_DOT , KC_SLSH  , KC_ESC ,
                                                MO(_FN6) , OS_SH_L2 , KC_SPC ,     ENT_SFT , OS_SH_L1 , MO(_FN4)
),

//    ┌──────┬────┬────┬─────────┬─────────┬──────────┐               ┌──────┬──────┬────┬──────┬──────┬──────┐
//    │ tab  │ 1  │ 2  │    3    │    4    │    5     │               │  6   │  7   │ 8  │  9   │  0   │ bspc │
//    ├──────┼────┼────┼─────────┼─────────┼──────────┤               ├──────┼──────┼────┼──────┼──────┼──────┤
//    │ lctl │ no │ no │ LALT(w) │   no    │    no    │               │ left │ down │ up │ rght │ pgup │  no  │
//    ├──────┼────┼────┼─────────┼─────────┼──────────┤               ├──────┼──────┼────┼──────┼──────┼──────┤
//    │ lsft │ no │ no │ LGUI(c) │ LGUI(v) │    no    │               │  no  │  no  │ no │  no  │ pgdn │  no  │
//    └──────┴────┴────┴─────────┼─────────┼──────────┼─────┐   ┌─────┼──────┼──────┼────┴──────┴──────┴──────┘
//                               │  lgui   │ MO(_FN3) │ spc │   │ ent │      │ ralt │
//                               └─────────┴──────────┴─────┘   └─────┴──────┴──────┘
[_FN1] = LAYOUT_split_3x6_3(
  KC_TAB  , KC_1    , KC_2    , KC_3       , KC_4       , KC_5     ,                       KC_6    , KC_7    , KC_8    , KC_9     , KC_0    , KC_BSPC,
  KC_LCTL , XXXXXXX , XXXXXXX , LALT(KC_W) , XXXXXXX    , XXXXXXX  ,                       KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , KC_PGUP , XXXXXXX,
  KC_LSFT , XXXXXXX , XXXXXXX , LGUI(KC_C) , LGUI(KC_V) , XXXXXXX  ,                       XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  , KC_PGDN , XXXXXXX,
                                             KC_LGUI    , MO(_FN3) , KC_SPC ,     KC_ENT , _______ , KC_RALT
),

//    ┌──────┬────┬────────────────────────┬────────────────────────┬────────────────────────┬─────┐               ┌──────────┬──────────┬───┬───┬───┬──────┐
//    │ tab  │ !  │           @            │           #            │           $            │  %  │               │    ^     │    &     │ ( │ ) │ * │ bspc │
//    ├──────┼────┼────────────────────────┼────────────────────────┼────────────────────────┼─────┤               ├──────────┼──────────┼───┼───┼───┼──────┤
//    │ lctl │ no │ UP(AE_LOWER, AE_UPPER) │ UP(OE_LOWER, OE_UPPER) │ UP(AA_LOWER, AA_UPPER) │ no  │               │    -     │    =     │ [ │ ] │ \ │  `   │
//    ├──────┼────┼────────────────────────┼────────────────────────┼────────────────────────┼─────┤               ├──────────┼──────────┼───┼───┼───┼──────┤
//    │ lsft │ no │           no           │         TMUX_C         │           no           │ no  │               │    _     │    +     │ { │ } │ | │  ~   │
//    └──────┴────┴────────────────────────┴────────────────────────┼────────────────────────┼─────┼─────┐   ┌─────┼──────────┼──────────┼───┴───┴───┴──────┘
//                                                                  │          lgui          │     │ spc │   │ ent │ MO(_FN3) │ MO(_FN5) │
//                                                                  └────────────────────────┴─────┴─────┘   └─────┴──────────┴──────────┘
[_FN2] = LAYOUT_split_3x6_3(
  KC_TAB  , KC_EXLM , KC_AT                  , KC_HASH                , KC_DLR                 , KC_PERC ,                       KC_CIRC  , KC_AMPR  , KC_LPRN , KC_RPRN , KC_ASTR , KC_BSPC,
  KC_LCTL , XXXXXXX , UP(AE_LOWER, AE_UPPER) , UP(OE_LOWER, OE_UPPER) , UP(AA_LOWER, AA_UPPER) , XXXXXXX ,                       KC_MINS  , KC_EQL   , KC_LBRC , KC_RBRC , KC_BSLS , KC_GRV ,
  KC_LSFT , XXXXXXX , XXXXXXX                , TMUX_C                 , XXXXXXX                , XXXXXXX ,                       KC_UNDS  , KC_PLUS  , KC_LCBR , KC_RCBR , KC_PIPE , KC_TILD,
                                                                        KC_LGUI                , _______ , KC_SPC ,     KC_ENT , MO(_FN3) , MO(_FN5)
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

//    ┌────────────┬─────────┬─────────┬─────────┬─────────┬─────────┐               ┌─────────┬─────────┬─────────┬─────────┬─────────┬───────────┐
//    │    esc     │ HYPR(1) │ HYPR(2) │ HYPR(3) │ HYPR(4) │ HYPR(5) │               │ HYPR(6) │ HYPR(7) │ HYPR(8) │ HYPR(9) │ HYPR(0) │    no     │
//    ├────────────┼─────────┼─────────┼─────────┼─────────┼─────────┤               ├─────────┼─────────┼─────────┼─────────┼─────────┼───────────┤
//    │ HYPR(tab)  │ HYPR(a) │ HYPR(s) │ HYPR(d) │ HYPR(f) │ HYPR(g) │               │ HYPR(h) │ HYPR(j) │ HYPR(k) │ HYPR(l) │ HYPR(;) │  HYPR(')  │
//    ├────────────┼─────────┼─────────┼─────────┼─────────┼─────────┤               ├─────────┼─────────┼─────────┼─────────┼─────────┼───────────┤
//    │ HYPR(lsft) │ HYPR(z) │ HYPR(x) │ HYPR(c) │ HYPR(v) │ HYPR(b) │               │ HYPR(n) │ HYPR(m) │ HYPR(,) │ HYPR(.) │ HYPR(/) │ HYPR(esc) │
//    └────────────┴─────────┴─────────┴─────────┼─────────┼─────────┼─────┐   ┌─────┼─────────┼─────────┼─────────┴─────────┴─────────┴───────────┘
//                                               │  lgui   │         │ spc │   │ spc │   no    │         │
//                                               └─────────┴─────────┴─────┘   └─────┴─────────┴─────────┘
[_FN5] = LAYOUT_split_3x6_3(
  KC_ESC        , HYPR(KC_1) , HYPR(KC_2) , HYPR(KC_3) , HYPR(KC_4) , HYPR(KC_5) ,                       HYPR(KC_6) , HYPR(KC_7) , HYPR(KC_8)    , HYPR(KC_9)   , HYPR(KC_0)    , XXXXXXX      ,
  HYPR(KC_TAB)  , HYPR(KC_A) , HYPR(KC_S) , HYPR(KC_D) , HYPR(KC_F) , HYPR(KC_G) ,                       HYPR(KC_H) , HYPR(KC_J) , HYPR(KC_K)    , HYPR(KC_L)   , HYPR(KC_SCLN) , HYPR(KC_QUOT),
  HYPR(KC_LSFT) , HYPR(KC_Z) , HYPR(KC_X) , HYPR(KC_C) , HYPR(KC_V) , HYPR(KC_B) ,                       HYPR(KC_N) , HYPR(KC_M) , HYPR(KC_COMM) , HYPR(KC_DOT) , HYPR(KC_SLSH) , HYPR(KC_ESC) ,
                                                         KC_LGUI    , _______    , KC_SPC ,     KC_SPC , XXXXXXX    , _______
),

//    ┌──────┬───┬───┬───┬──────┬────┐               ┌──────────┬──────────┬───┬───┬───┬──────┐
//    │ esc  │ q │ w │ e │  r   │ t  │               │    y     │    u     │ i │ o │ p │ bspc │
//    ├──────┼───┼───┼───┼──────┼────┤               ├──────────┼──────────┼───┼───┼───┼──────┤
//    │ tab  │ a │ s │ d │  f   │ g  │               │    h     │    j     │ k │ l │ ; │  '   │
//    ├──────┼───┼───┼───┼──────┼────┤               ├──────────┼──────────┼───┼───┼───┼──────┤
//    │ lsft │ z │ x │ c │  v   │ b  │               │    n     │    m     │ , │ . │ / │ esc  │
//    └──────┴───┴───┴───┼──────┼────┼─────┐   ┌─────┼──────────┼──────────┼───┴───┴───┴──────┘
//                       │ lgui │ no │ spc │   │ spc │ MO(_FN7) │ MO(_FN8) │
//                       └──────┴────┴─────┘   └─────┴──────────┴──────────┘
[_FN6] = LAYOUT_split_3x6_3(
  KC_ESC  , KC_Q , KC_W , KC_E , KC_R    , KC_T    ,                       KC_Y     , KC_U     , KC_I    , KC_O   , KC_P    , KC_BSPC,
  KC_TAB  , KC_A , KC_S , KC_D , KC_F    , KC_G    ,                       KC_H     , KC_J     , KC_K    , KC_L   , KC_SCLN , KC_QUOT,
  KC_LSFT , KC_Z , KC_X , KC_C , KC_V    , KC_B    ,                       KC_N     , KC_M     , KC_COMM , KC_DOT , KC_SLSH , KC_ESC ,
                                 KC_LGUI , XXXXXXX , KC_SPC ,     KC_SPC , MO(_FN7) , MO(_FN8)
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
//    │ LGUI(lsft) │ LGUI(z) │ TMUX_X  │ TMUX_C  │ LGUI(v) │ LGUI(b) │               │ LGUI(n) │ LGUI(m) │ LGUI(,) │ LGUI(.) │ LGUI(/) │ LGUI(esc) │
//    └────────────┴─────────┴─────────┴─────────┼─────────┼─────────┼─────┐   ┌─────┼─────────┼─────────┼─────────┴─────────┴─────────┴───────────┘
//                                               │         │   no    │ spc │   │ ent │   no    │         │
//                                               └─────────┴─────────┴─────┘   └─────┴─────────┴─────────┘
[_FN8] = LAYOUT_split_3x6_3(
  LGUI(KC_ESC)  , TMUX_1     , TMUX_2     , TMUX_3     , TMUX_4     , TMUX_5     ,                       TMUX_6     , TMUX_7     , TMUX_8        , TMUX_9       , TMUX_0        , KC_BSPC      ,
  LGUI(KC_TAB)  , LGUI(KC_A) , LGUI(KC_S) , LGUI(KC_D) , LGUI(KC_F) , LGUI(KC_G) ,                       LGUI(KC_H) , LGUI(KC_J) , LGUI(KC_K)    , LGUI(KC_L)   , LGUI(KC_SCLN) , LGUI(KC_QUOT),
  LGUI(KC_LSFT) , LGUI(KC_Z) , TMUX_X     , TMUX_C     , LGUI(KC_V) , LGUI(KC_B) ,                       LGUI(KC_N) , LGUI(KC_M) , LGUI(KC_COMM) , LGUI(KC_DOT) , LGUI(KC_SLSH) , LGUI(KC_ESC) ,
                                                         _______    , XXXXXXX    , KC_SPC ,     KC_ENT , XXXXXXX    , _______
)
};

// A little flag to remember if the last key pressed was MO(1)
static bool    other_was_mo1     = false;
static bool    first_was_shift   = false;
static bool    first_was_command = false;
static bool    other_was_command = false;
static uint8_t keys_down         = 0;

static uint16_t os_timer; // for OS_SH_L1 tap/hold timing

layer_state_t layer_state_set_user(layer_state_t state) {
    // Check if FN6 is active
    if (get_highest_layer(state) == _FN6) {
        add_mods(MOD_BIT(KC_LGUI));  // Simulate holding Shift
    } else {
        del_mods(MOD_BIT(KC_LGUI));  // Release Shift when leaving FN6
    }
   return state;
}

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == MO(_FN1)) {
        other_was_mo1 = record->event.pressed;
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
        case TMUX_C:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "c");
            }
            return false;
        case TMUX_X:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "x");
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
                if (timer_elapsed(os_timer) < TAPPING_TERM && !record->tap.interrupted) {
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
                if (timer_elapsed(os_timer) < TAPPING_TERM && !record->tap.interrupted) {
                    // It was a tap: cancel layer and set one-shot Shift
                    layer_off(_FN2);
                    caps_word_toggle();
                } else {
                    // It was a hold: just turn layer off
                    layer_off(_FN2);
                }
            }
            return false;

        default:
            return true; // process all other keycodes normally
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
//    uprintf("mode (post) %u\n", get_unicode_input_mode());
    // if (record->event.pressed) return; // only care about key-up
    //
    // switch (keycode) {
    //     case ALT_L:
    //         unregister_mods(MOD_BIT(KC_LALT));
    //         break;
    //     case CTL_A:
    //         unregister_mods(MOD_BIT(KC_LCTL));
    //         break;
    //     case CTL_SCLN:
    //         unregister_mods(MOD_BIT(KC_LCTL));
    //         break;
    //     case ALT_S:
    //         unregister_mods(MOD_BIT(KC_LALT));
    //         break;
    //     case GUI_D:
    //         unregister_mods(MOD_BIT(KC_LGUI));
    //         break;
    //     case GUI_K:
    //         unregister_mods(MOD_BIT(KC_RGUI));
    //         break;
    // }
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
            return first_was_command ? true : false;
        default:
            return true; // default permissive-hold behaviour
    }
}
#endif
