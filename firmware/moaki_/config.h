// moaki_ config for Ferris Sweep (Helios/RP2040)

#pragma once

// ─── Combos ───────────────────────────────────────────────────────────────────
#define COMBO_COUNT 2

// ─── Tapping ─────────────────────────────────────────────────────────────────
// How long to hold before a mod-tap registers as a modifier (not a tap)
#define TAPPING_TERM 175

// If you press a mod-tap and then another key before releasing,
// treat it as a hold (good for home row mods)
#define PERMISSIVE_HOLD

// Disable tap-then-hold repeating (avoids accidental mod activation
// when typing fast and holding a key for repeat)
#define QUICK_TAP_TERM 0

// ─── Mouse keys ──────────────────────────────────────────────────────────────
#define MOUSEKEY_INTERVAL       16
#define MOUSEKEY_TIME_TO_MAX    40
#define MOUSEKEY_DELAY          100
#define MOUSEKEY_WHEEL_DELAY    100
#define MOUSEKEY_WHEEL_INTERVAL 50
#define MOUSEKEY_WHEEL_TIME_TO_MAX 100
