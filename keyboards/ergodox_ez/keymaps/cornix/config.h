#pragma once

/* ---------------------------------------------------------------------------
 * Home-row-mod / tap-hold tuning
 *
 * Ported from the ZMK Cornix hold-tap behaviors (hm_l / hm_r):
 *   flavor                 = "balanced"
 *   tapping-term-ms        = 280
 *   quick-tap-ms           = 175
 *   require-prior-idle-ms  = 150
 *   hold-trigger-on-release
 *   hold-trigger-key-positions (opposite hand + same-hand HRM keys)
 *
 * QMK equivalents:
 *   TAPPING_TERM                      <- tapping-term-ms
 *   QUICK_TAP_TERM                    <- quick-tap-ms (double-tap-to-repeat window)
 *   PERMISSIVE_HOLD + HOLD_ON_OTHER_KEY_PRESS approximate "balanced"
 *   require-prior-idle-ms             <- custom get_tapping_term + a prior-idle
 *                                        guard in process_record_user (see keymap.c)
 *   hold-trigger-key-positions        <- Achordion (opposite-hand) handling in keymap.c
 * ------------------------------------------------------------------------- */

#define TAPPING_TERM 280
#define TAPPING_TERM_PER_KEY

#define QUICK_TAP_TERM 175
#define QUICK_TAP_TERM_PER_KEY

/* "balanced" flavor: prefer hold when another key is fully tapped inside the
 * term, but still allow fast rolls to register as taps. */
#define PERMISSIVE_HOLD
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

/* require-prior-idle-ms = 150: if a key was tapped <150ms ago, treat the
 * mod-tap as a tap (prevents accidental mods during fast typing). Implemented
 * via last-keypress timestamp tracking in process_record_user. */
#define REQUIRE_PRIOR_IDLE_MS 150

/* CAPS WORD: idle timeout roughly matching a word boundary. */
#define CAPS_WORD_IDLE_TIMEOUT 3000

/* MOUSE KEYS (trackball replacement) ---------------------------------------
 * The ZMK config disabled acceleration (acceleration-exponent = 0) for a
 * constant-speed trackball feel, with separate 5x / 10x "speed" layers.
 * QMK's MK_COMBINED lets us switch acceleration profiles per layer via
 * KC_ACL0 / KC_ACL1 / KC_ACL2, which we map on the speed layers. */
#define MK_COMBINED
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MAX_SPEED 6
#define MOUSEKEY_TIME_TO_MAX 0
#define MOUSEKEY_WHEEL_DELAY 0

/* RGB MATRIX: start dim (the ZMK widget used a /16 brightness divisor). */
#ifdef RGB_MATRIX_ENABLE
#  define RGB_MATRIX_DEFAULT_VAL 60
#  define RGB_MATRIX_KEYPRESSES
#endif
