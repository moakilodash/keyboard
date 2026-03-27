// moaki_ keymap for Ferris Sweep (Helios/RP2040)
// Ported from Corne 34-key layout
// Combos: F+J = CapsLock, LShift+RShift = Escape

#include QMK_KEYBOARD_H

// ─── Layer definitions ────────────────────────────────────────────────────────
enum layers {
    _BASE,
    _NAV,
    _SYM,
    _NUM,
};

// ─── Combo definitions ────────────────────────────────────────────────────────
enum combos {
    COMBO_CAPSLOCK,   // F + J = CapsLock
    COMBO_ESCAPE,     // LShift + RShift = Escape
};

// F is LSFT_T(KC_F), J is RSFT_T(KC_J)
// Combos fire on the base keycodes, not the mod-tap wrappers
const uint16_t PROGMEM capslock_combo[] = {LSFT_T(KC_F), RSFT_T(KC_J), COMBO_END};
const uint16_t PROGMEM escape_combo[]   = {RSFT_T(KC_J), RCTL_T(KC_K), COMBO_END};

combo_t key_combos[] = {
    [COMBO_CAPSLOCK] = COMBO(capslock_combo, KC_CAPS),
    [COMBO_ESCAPE]   = COMBO(escape_combo, KC_ESC),
};

// ─── Home row mod aliases ─────────────────────────────────────────────────────
// GACS: GUI / Alt / Ctrl / Shift
#define HM_A    LGUI_T(KC_A)
#define HM_S    LALT_T(KC_S)
#define HM_D    LCTL_T(KC_D)
#define HM_F    LSFT_T(KC_F)
#define HM_J    RSFT_T(KC_J)
#define HM_K    RCTL_T(KC_K)
#define HM_L    RALT_T(KC_L)
#define HM_SCLN RGUI_T(KC_SCLN)

// Layer 1 home row — plain mods on nav layer (no mod-tap on arrows)
#define N1_A    LGUI_T(KC_MINS)
#define N1_S    LALT_T(KC_EQL)

// Layer 2 home row
#define S2_A    LGUI_T(KC_GRV)
#define S2_F    LSFT_T(KC_MINS)
#define S2_J    RSFT_T(KC_EQL)
#define S2_K    RCTL_T(KC_LBRC)
#define S2_L    RALT_T(KC_RBRC)
#define S2_SCLN RGUI_T(KC_QUOT)

// Thumb layer-taps
#define LT_SPC  LT(_NAV, KC_SPC)
#define LT_TAB  LT(_NUM, KC_TAB)
#define LT_ENT  LT(_SYM, KC_ENT)

// ─── Keymap ───────────────────────────────────────────────────────────────────
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // ┌──────┬──────┬──────┬──────┬──────┐   ┌──────┬──────┬──────┬──────┬──────┐
    // │  Q   │  W   │  E   │  R   │  T   │   │  Y   │  U   │  I   │  O   │  P   │
    // ├──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼──────┤
    // │GUI/A │ALT/S │CTL/D │SFT/F │  G   │   │  H   │SFT/J │CTL/K │ALT/L │GUI/; │
    // ├──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼──────┤
    // │  Z   │  X   │  C   │  V   │  B   │   │  N   │  M   │  ,   │  .   │  /   │
    // └──────┴──────┴──────┼──────┼──────┤   ├──────┼──────┼──────┴──────┴──────┘
    //                      │SPC/L1│TAB/L3│   │BSPC  │ENT/L2│
    //                      └──────┴──────┘   └──────┴──────┘
    [_BASE] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        HM_A,    HM_S,    HM_D,    HM_F,    KC_G,       KC_H,    HM_J,    HM_K,    HM_L,    HM_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                LT_SPC,  LT_TAB,     KC_BSPC, LT_ENT
    ),

    // ┌──────┬──────┬──────┬──────┬──────┐   ┌──────┬──────┬──────┬──────┬──────┐
    // │  1   │  2   │  3   │  4   │  5   │   │  6   │  7   │  8   │  9   │  0   │
    // ├──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼──────┤
    // │GUI/- │ALT/= │CTL/D │SFT/F │  G   │   │ ←   │  ↓   │  ↑   │  →  │GUI/; │
    // ├──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼──────┤
    // │  `   │  X   │  C   │  V   │  B   │   │  N   │  M   │  ,   │  .   │  /   │
    // └──────┴──────┴──────┼──────┼──────┤   ├──────┼──────┼──────┴──────┴──────┘
    //                      │ (L1) │TAB/L3│   │ DEL  │ENT/L2│
    //                      └──────┴──────┘   └──────┴──────┘
    [_NAV] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        N1_A,    N1_S,    LCTL_T(KC_D), LSFT_T(KC_F), KC_G,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, HM_SCLN,
        KC_GRV,  KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                KC_TRNS, LT_TAB,     KC_DEL,  LT_ENT
    ),

    // ┌──────┬──────┬──────┬──────┬──────┐   ┌──────┬──────┬──────┬──────┬──────┐
    // │  1   │  2   │  3   │  4   │  5   │   │  6   │  7   │  8   │  9   │  0   │
    // ├──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼──────┤
    // │GUI/` │      │      │SFT/- │      │   │      │SFT/= │CTL/[ │ALT/] │GUI/' │
    // ├──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼──────┤
    // │  \   │      │      │      │      │   │      │      │      │      │  \   │
    // └──────┴──────┴──────┼──────┼──────┤   ├──────┼──────┼──────┴──────┴──────┘
    //                      │SPC/L1│ ESC  │   │      │ (L2) │
    //                      └──────┴──────┘   └──────┴──────┘
    [_SYM] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        S2_A,    KC_TRNS, KC_TRNS, S2_F,    KC_TRNS,    KC_TRNS, S2_J,    S2_K,    S2_L,    S2_SCLN,
        KC_BSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS,
                                LT_SPC,  KC_ESC,     KC_TRNS, KC_TRNS
    ),

    // ┌──────┬──────┬──────┬──────┬──────┐   ┌──────┬──────┬──────┬──────┬──────┐
    // │  F1  │  F2  │  F3  │  F4  │  F5  │   │  F6  │  F7  │  F8  │  F9  │  F10 │
    // ├──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼──────┤
    // │ VOLD │ VOLU │ MUTE │      │ PSCR │   │      │      │      │      │  F11 │
    // ├──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼──────┤
    // │BL_TG │BL_UP │BL_DN │      │      │   │      │      │      │      │  F12 │
    // └──────┴──────┴──────┼──────┼──────┤   ├──────┼──────┼──────┴──────┴──────┘
    //                      │SPC/L1│ (L3) │   │      │ENT/L2│
    //                      └──────┴──────┘   └──────┴──────┘
    [_NUM] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_PSCR,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F11,
        BL_TOGG, BL_UP,   BL_DOWN, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F12,
                                LT_SPC,  KC_TRNS,    KC_TRNS, LT_ENT
    ),
};
