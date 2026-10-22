/* Copyright 2024 Cornix-port for Ergodox EZ
 * SPDX-License-Identifier: MIT
 *
 * Full-fidelity translation of the ZMK Cornix keymap (config/cornix.keymap)
 * to QMK for the stock Ergodox EZ.
 *
 * Differences from the Cornix (documented in README.md):
 *   - No trackball  -> mouse layers use KC_MS_* cursor/scroll emulation.
 *   - No encoders   -> volume / media / browser-nav moved onto keys.
 *   - 76 keys (vs 54): the extra 22 keys surface numbers, brackets and
 *     navigation onto the base layer so fewer layer trips are needed.
 *
 * Layer indices match the Cornix layer_N numbering exactly:
 *   0 Base      1 Nav        2 ExtNav
 *   3 MacBase   4 MacNav     5 MacExtNav
 *   6 Sym       7 Func       8 MacFunc
 *   9 Mouse    10 MouseExt  11 MSpeed10x  12 MSpeed5x
 */

#include QMK_KEYBOARD_H

enum layers {
    BASE = 0,
    NAV,
    EXTNAV,
    MACBASE,
    MACNAV,
    MACEXTNAV,
    SYM,
    FUNC,
    MACFUNC,
    MOUSE,
    MOUSEEXT,
    MSPEED10X,
    MSPEED5X,
};

enum custom_keycodes {
    // Password / text macros (Cornix m0, m5, m6)
    M_PWD = SAFE_RANGE,  // m0: dummy-password
    M_CSTRUCT,           // m5: "->"
    M_JSLAMBDA,          // m6: "=> {}" + cursor back
    // Select-word / select-line macros (Cornix m1-m4)
    M_WIN_SELWORD,       // m1
    M_WIN_SELLINE,       // m2
    M_MAC_SELWORD,       // m3
    M_MAC_SELLINE,       // m4
    // Mouse-layer naming macros (Cornix m_mouse1-5): types 'MACRO N'
    M_MOUSE1,
    M_MOUSE2,
    M_MOUSE3,
    M_MOUSE4,
    M_MOUSE5,
};

/* ---- Home-row mods -------------------------------------------------------
 * Cornix left hand:  A=Ctrl S=Alt D=Gui F=Shift
 *        right hand: J=Shift K=Gui L=Alt ;=Ctrl
 * QMK mod-tap aliases keep the keymap grid readable. */
#define HL_A LCTL_T(KC_A)
#define HL_S LALT_T(KC_S)
#define HL_D LGUI_T(KC_D)
#define HL_F LSFT_T(KC_F)
#define HR_J RSFT_T(KC_J)
#define HR_K RGUI_T(KC_K)
#define HR_L LALT_T(KC_L)
#define HR_SC RCTL_T(KC_SCLN)

/* macOS base uses the same letters; HRM stay identical (GUI = Cmd). */

/* Convenience shift-symbols already covered by QMK keycodes (KC_LPRN, etc). */

/* ==========================================================================
 * KEYMAP
 *
 * LAYOUT_ergodox_pretty positional order (per physical row, L then R):
 *   row0: 7 + 7   row1: 7 + 7   row2: 6 + 6   row3: 7 + 7   row4: 5 + 5
 *   thumbs: L(2 top) R(2 top) / L(1 mid) R(1 mid) / L(3 bot) R(3 bot)
 *
 * The Cornix is a 6-column split; the Ergodox adds an outer pinky column,
 * a top number row, and a 6-key thumb cluster per side. Cornix keys keep
 * their home positions; the EXTRA Ergodox keys are marked  // +  in comments.
 * ========================================================================== */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE (Cornix layer_0) ----------------------------------------------------
 * Extra keys used: number row 1-0, outer brackets/paren, inner Esc/Enter,
 * and the 6-key thumb clusters carry Space/Bspc/layer-holds + media/browser
 * (the encoder actions that have no home on the EZ). */
[BASE] = LAYOUT_ergodox_pretty(
  // left hand                                                              // + top number row
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_ESC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,             // + [
  KC_ESC,  HL_A,    HL_S,    HL_D,    HL_F,    KC_G,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LPRN,             // + (
  KC_LCTL, KC_LGUI, KC_LALT, MO(FUNC),KC_SPC,
                                               KC_MUTE, KC_MPLY,            // + encoder->media
                                                        MO(MOUSE),
                                      MO(FUNC),MO(SYM), MO(NAV),
  // right hand                                                            // + top number row
                    KC_ESC,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
                    KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,  // + ]
                             KC_H,    HR_J,    HR_K,    HR_L,    HR_SC,   KC_QUOT,
                    KC_RPRN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_SLSH,  // + )
                                      KC_LEFT, KC_DOWN, KC_RIGHT,KC_ENT,  KC_BSPC,
                    KC_VOLD, KC_VOLU,                                               // + encoder->volume
                    MO(MOUSE),
                    MO(NAV), MO(SYM), KC_ENT
),

/* NAV (Cornix layer_1) ----------------------------------------------------- */
[NAV] = LAYOUT_ergodox_pretty(
  KC_TAB,  KC_NO,   KC_NO,   M_WIN_SELWORD, M_WIN_SELLINE, KC_NO, KC_NO,
  KC_TAB,  KC_NO,   KC_NO,   M_WIN_SELWORD, M_WIN_SELLINE, KC_NO, KC_NO,
  KC_ESC,  C(KC_A), KC_LSFT, KC_HOME, KC_END,  CW_TOGG,
  KC_LSFT, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), KC_NO,   KC_NO,
  KC_LCTL, KC_LGUI, KC_LALT, KC_NO,   KC_NO,
                                               KC_MUTE, KC_NO,
                                                        KC_NO,
                                      KC_NO,   KC_NO,   MO(EXTNAV),
                    KC_NO,   KC_NO,   KC_BSPC, KC_UP,   KC_DEL,  KC_NO,   KC_NO,
                    KC_NO,   KC_NO,   KC_BSPC, KC_UP,   KC_DEL,  KC_NO,   KC_NO,
                             KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, S(KC_ENT), S(KC_ENT),
                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                      MO(EXTNAV), KC_NO, KC_NO,  KC_NO,   KC_NO,
                    KC_NO,   KC_NO,
                    KC_NO,
                    MO(EXTNAV), KC_NO, KC_NO
),

/* EXTNAV (Cornix layer_2) -------------------------------------------------- */
[EXTNAV] = LAYOUT_ergodox_pretty(
  KC_TAB,  KC_NO,   KC_NO,   M_WIN_SELWORD, M_WIN_SELLINE, KC_NO, KC_NO,
  KC_TAB,  KC_NO,   KC_NO,   M_WIN_SELWORD, M_WIN_SELLINE, KC_NO, KC_NO,
  KC_ESC,  C(KC_A), KC_LSFT, KC_HOME, KC_END,  KC_NO,
  KC_LSFT, C(S(KC_Z)), C(KC_X), C(KC_C), C(KC_V), KC_NO, KC_NO,
  KC_LCTL, KC_LGUI, KC_LALT, KC_NO,   KC_NO,
                                               KC_MUTE, KC_NO,
                                                        KC_NO,
                                      KC_NO,   KC_NO,   KC_NO,
                    KC_NO,   KC_NO,   C(KC_BSPC), KC_PGUP, C(KC_DEL), KC_NO, KC_NO,
                    KC_NO,   KC_NO,   C(KC_BSPC), KC_PGUP, C(KC_DEL), KC_NO, KC_NO,
                             KC_NO,   C(KC_LEFT), KC_PGDN, C(KC_RGHT), KC_ENT, KC_ENT,
                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                    KC_NO,   KC_NO,
                    KC_NO,
                    KC_NO,   KC_NO,   KC_NO
),

/* MACBASE (Cornix layer_3) -- same as BASE; MO targets Mac layers --------- */
[MACBASE] = LAYOUT_ergodox_pretty(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_ESC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,
  KC_ESC,  HL_A,    HL_S,    HL_D,    HL_F,    KC_G,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LPRN,
  KC_LCTL, KC_LGUI, KC_LALT, MO(MACFUNC), KC_SPC,
                                               KC_MUTE, KC_MPLY,
                                                        MO(MOUSE),
                                      MO(MACFUNC), MO(MACNAV), MO(SYM),
                    KC_ESC,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
                    KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
                             KC_H,    HR_J,    HR_K,    HR_L,    HR_SC,   KC_QUOT,
                    KC_RPRN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_SLSH,
                                      KC_LEFT, KC_DOWN, KC_RIGHT,KC_ENT,  KC_BSPC,
                    KC_VOLD, KC_VOLU,
                    MO(MOUSE),
                    MO(SYM), MO(MACFUNC), KC_ENT
),

/* MACNAV (Cornix layer_4) -------------------------------------------------- */
[MACNAV] = LAYOUT_ergodox_pretty(
  KC_TAB,  KC_NO,   KC_NO,   M_MAC_SELWORD, M_MAC_SELLINE, KC_NO, KC_NO,
  KC_TAB,  KC_NO,   KC_NO,   M_MAC_SELWORD, M_MAC_SELLINE, KC_NO, KC_NO,
  KC_ESC,  G(KC_A), KC_LSFT, G(KC_LEFT), G(KC_RGHT), CW_TOGG,
  KC_LSFT, G(KC_Z), G(KC_X), G(KC_C), G(KC_V), KC_NO,   KC_NO,
  KC_LCTL, KC_LGUI, KC_LALT, KC_NO,   KC_NO,
                                               KC_MUTE, KC_NO,
                                                        KC_NO,
                                      KC_NO,   KC_NO,   MO(MACEXTNAV),
                    KC_NO,   KC_NO,   KC_BSPC, KC_UP,   KC_DEL,  KC_NO,   KC_NO,
                    KC_NO,   KC_NO,   KC_BSPC, KC_UP,   KC_DEL,  KC_NO,   KC_NO,
                             KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, S(KC_ENT), S(KC_ENT),
                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                      MO(MACEXTNAV), KC_NO, KC_NO, KC_NO, KC_NO,
                    KC_NO,   KC_NO,
                    KC_NO,
                    MO(MACEXTNAV), KC_NO, KC_NO
),

/* MACEXTNAV (Cornix layer_5) ----------------------------------------------- */
[MACEXTNAV] = LAYOUT_ergodox_pretty(
  KC_TAB,  KC_NO,   KC_NO,   M_MAC_SELWORD, M_MAC_SELLINE, KC_NO, KC_NO,
  KC_TAB,  KC_NO,   KC_NO,   M_MAC_SELWORD, M_MAC_SELLINE, KC_NO, KC_NO,
  KC_ESC,  G(KC_A), KC_LSFT, G(KC_LEFT), G(KC_RGHT), KC_NO,
  KC_LSFT, G(S(KC_Z)), G(KC_X), G(KC_C), G(KC_V), KC_NO, KC_NO,
  KC_LCTL, KC_LGUI, KC_LALT, KC_NO,   KC_NO,
                                               KC_MUTE, KC_NO,
                                                        KC_NO,
                                      KC_NO,   KC_NO,   KC_NO,
                    KC_NO,   KC_NO,   A(KC_BSPC), KC_PGUP, A(KC_DEL), KC_NO, KC_NO,
                    KC_NO,   KC_NO,   A(KC_BSPC), KC_PGUP, A(KC_DEL), KC_NO, KC_NO,
                             KC_NO,   A(KC_LEFT), KC_PGDN, A(KC_RGHT), KC_ENT, KC_ENT,
                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                    KC_NO,   KC_NO,
                    KC_NO,
                    KC_NO,   KC_NO,   KC_NO
),

/* SYM (Cornix layer_6) -----------------------------------------------------
 * Numbers, symbols, and the C/JS macros (m5 "->", m6 "=> {}"). */
[SYM] = LAYOUT_ergodox_pretty(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NO,
  KC_BSPC, KC_1,    KC_2,    KC_3,    M_CSTRUCT, M_JSLAMBDA, KC_NO,
  KC_SPC,  KC_4,    KC_5,    KC_6,    KC_MINS, KC_EQL,
  KC_LSFT, KC_7,    KC_8,    KC_9,    KC_BSLS, KC_PIPE, KC_NO,
  KC_LCTL, KC_0,    KC_DOT,  KC_NO,   KC_LSFT,
                                               KC_MUTE, KC_NO,
                                                        KC_NO,
                                      KC_LSFT, KC_NO,   KC_NO,
                    KC_NO,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
                    KC_GRV,  KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_NO,   KC_BSPC,
                             KC_PLUS, KC_COMM, KC_DOT,  KC_QUES, KC_SLSH, KC_BSLS,
                    KC_AMPR, KC_ASTR, KC_CIRC, KC_PERC, KC_HASH, KC_DLR,  KC_NO,
                                      KC_NO,   KC_SCLN, KC_EXLM, KC_AT,   KC_NO,
                    KC_NO,   KC_NO,
                    KC_NO,
                    KC_NO,   KC_NO,   KC_NO
),

/* FUNC (Cornix layer_7) ----------------------------------------------------
 * F-keys, Bluetooth-on-ZMK had BT_SEL/BT_CLR; on a USB EZ those have no
 * meaning, so those positions hold the m0 password macro, bootloader
 * (QK_BOOT), and OS-base toggles TO(BASE)/TO(MACBASE). */
[FUNC] = LAYOUT_ergodox_pretty(
  KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   M_PWD,   KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   QK_BOOT, KC_NO,   KC_NO,   TO(BASE),
                                               KC_MUTE, KC_NO,
                                                        KC_NO,
                                      KC_NO,   TO(MACBASE), KC_NO,
                    KC_NO,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_F12,
                             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                    KC_NO,   KC_NO,
                    KC_NO,
                    KC_NO,   KC_NO,   KC_NO
),

/* MACFUNC (Cornix layer_8) -- identical to FUNC on a USB EZ --------------- */
[MACFUNC] = LAYOUT_ergodox_pretty(
  KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   M_PWD,   KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   QK_BOOT, KC_NO,   KC_NO,   TO(BASE),
                                               KC_MUTE, KC_NO,
                                                        KC_NO,
                                      KC_NO,   TO(MACBASE), KC_NO,
                    KC_NO,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_F12,
                             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                    KC_NO,   KC_NO,
                    KC_NO,
                    KC_NO,   KC_NO,   KC_NO
),

/* MOUSE (Cornix layer_9) ---------------------------------------------------
 * Trackball replacement: left thumb area holds buttons + speed-layer holds,
 * right hand does cursor movement (ZMK used &mmv; here KC_MS_*). The five
 * M_MOUSE* macros (type "MACRO N") sit on the top-left row as in Cornix. */
[MOUSE] = LAYOUT_ergodox_pretty(
  KC_NO,   M_MOUSE1, M_MOUSE2, M_MOUSE3, M_MOUSE4, M_MOUSE5, KC_NO,
  KC_NO,   M_MOUSE1, M_MOUSE2, M_MOUSE3, M_MOUSE4, M_MOUSE5, KC_NO,
  KC_NO,   MS_ACL2, MS_ACL1, MS_BTN2, MS_BTN1, KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_LSFT, MS_ACL1,
                                               KC_MUTE, KC_NO,
                                                        KC_NO,
                                      KC_NO,   MO(MOUSEEXT), KC_NO,
                    KC_NO,   KC_NO,   MS_BTN4, MS_UP, MS_BTN5, KC_NO,   KC_NO,
                    KC_NO,   KC_NO,   MS_BTN4, MS_UP, MS_BTN5, KC_NO,   KC_NO,
                             KC_NO,   MS_LEFT, MS_DOWN, MS_RGHT, KC_NO,   KC_NO,
                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                    KC_NO,   KC_NO,
                    MO(MOUSEEXT),
                    KC_NO,   KC_NO,   KC_NO
),

/* MOUSEEXT (Cornix layer_10) -- scroll wheel; transparent elsewhere ------- */
[MOUSEEXT] = LAYOUT_ergodox_pretty(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, MS_BTN4, MS_WHLU, MS_BTN5, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, MS_BTN4, MS_WHLU, MS_BTN5, KC_TRNS, KC_TRNS,
                             KC_TRNS, MS_WHLL, MS_WHLD, MS_WHLR, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS,
                    KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS
),

/* MSPEED10X (Cornix layer_11) -- fast cursor: acceleration profile 2 ------ */
[MSPEED10X] = LAYOUT_ergodox_pretty(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, MS_BTN4, MS_UP, MS_BTN5, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, MS_BTN4, MS_UP, MS_BTN5, KC_TRNS, KC_TRNS,
                             KC_TRNS, MS_LEFT, MS_DOWN, MS_RGHT, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS,
                    KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS
),

/* MSPEED5X (Cornix layer_12) -- medium cursor: acceleration profile 1 ----- */
[MSPEED5X] = LAYOUT_ergodox_pretty(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, MS_BTN4, MS_UP, MS_BTN5, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, MS_BTN4, MS_UP, MS_BTN5, KC_TRNS, KC_TRNS,
                             KC_TRNS, MS_LEFT, MS_DOWN, MS_RGHT, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS,
                    KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS
),

};  // end keymaps

/* ==========================================================================
 * Home-row-mod tap/hold callbacks
 *
 * require-prior-idle-ms is handled by core Flow Tap (FLOW_TAP_TERM in
 * config.h), so no custom pre_process_record_user is needed here.
 * ========================================================================== */

static bool is_cornix_hrm(uint16_t keycode) {
    switch (keycode) {
        case HL_A: case HL_S: case HL_D: case HL_F:
        case HR_J: case HR_K: case HR_L: case HR_SC:
            return true;
        default:
            return false;
    }
}

/* Per-key tapping term: HRM keep 280; everything else uses the default too,
 * but this hook is where you'd lengthen/shorten individual keys later. */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    if (is_cornix_hrm(keycode)) {
        return TAPPING_TERM;  // 280
    }
    return TAPPING_TERM;
}

/* "balanced" flavor: allow hold-on-other-key-press for the HRM keys so that
 * mod + key chords on the opposite hand register as holds. Fast same-hand
 * rolls favor taps via Flow Tap (FLOW_TAP_TERM in config.h). */
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    if (is_cornix_hrm(keycode)) {
        return true;
    }
    return false;
}

/* Quick-tap (double-tap-to-repeat) window = 175ms, matching quick-tap-ms. */
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    if (is_cornix_hrm(keycode)) {
        return QUICK_TAP_TERM;  // 175
    }
    return QUICK_TAP_TERM;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    /* --- custom macros (ported from Cornix m0-m6 + m_mouse1-5) --- */
    if (!record->event.pressed) {
        return true;
    }
    switch (keycode) {
        case M_PWD:  // m0: dummy-password. Cornix taps W N0 R K L O V E L O V E
                     // (unshifted -> lowercase) then LS(F) LS(N1)x3 -> F!!!
            SEND_STRING("wn0rkloveloveF!!!");
            return false;
        case M_CSTRUCT:  // m5: "->"
            SEND_STRING("->");
            return false;
        case M_JSLAMBDA:  // m6: Cornix sends LS(EQUAL)->'+' LS(DOT)->'>' space
                          // LS(LBKT)->'{' LS(RBKT)->'}' LEFT (cursor in braces)
            SEND_STRING("+> {}" SS_TAP(X_LEFT));
            return false;
        case M_WIN_SELWORD:  // m1: Ctrl+Left, Shift+Ctrl+Right (select word)
            SEND_STRING(SS_LCTL(SS_TAP(X_LEFT))
                        SS_LSFT(SS_LCTL(SS_TAP(X_RIGHT))));
            return false;
        case M_WIN_SELLINE:  // m2: Home, Shift+End (select line)
            SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)));
            return false;
        case M_MAC_SELWORD:  // m3: Alt+Left, Shift+Alt+Right (select word)
            SEND_STRING(SS_LALT(SS_TAP(X_LEFT))
                        SS_LSFT(SS_LALT(SS_TAP(X_RIGHT))));
            return false;
        case M_MAC_SELLINE:  // m4: Gui+Left, Shift+Gui+Right (select line)
            SEND_STRING(SS_LGUI(SS_TAP(X_LEFT))
                        SS_LSFT(SS_LGUI(SS_TAP(X_RIGHT))));
            return false;
        case M_MOUSE1: SEND_STRING("'MACRO 1'"); return false;
        case M_MOUSE2: SEND_STRING("'MACRO 2'"); return false;
        case M_MOUSE3: SEND_STRING("'MACRO 3'"); return false;
        case M_MOUSE4: SEND_STRING("'MACRO 4'"); return false;
        case M_MOUSE5: SEND_STRING("'MACRO 5'"); return false;
    }
    return true;
}

/* ==========================================================================
 * Mouse speed layers
 *
 * ZMK used zip_xy_scaler 5x / 10x on dedicated layers. QMK's MK_COMBINED
 * controls constant speed by HOLDING an acceleration key, so the Cornix
 * "speed" keys map directly to MS_ACL1 (half / ~5x) and MS_ACL2 (max / ~10x)
 * on the MOUSE layer -- hold with one hand while moving the cursor with the
 * other. The MSPEED5X / MSPEED10X layers are kept transparent for structural
 * parity with the Cornix layer numbering but are not separately activated.
 * ========================================================================== */

/* ==========================================================================
 * Per-layer RGB indicator (WS2812 widget replacement)
 *
 * Colors ported from config/cornix.conf (0xRRGGBB). The stock EZ has 3
 * discrete right-hand LEDs plus (on Glow units) an RGB matrix. We light the
 * RGB matrix a solid per-layer color and mirror a coarse layer code on the
 * 3 indicator LEDs, matching the Cornix color scheme.
 * ========================================================================== */
#ifdef RGB_MATRIX_ENABLE
typedef struct {
    uint8_t r, g, b;
} layer_rgb_t;

static const layer_rgb_t PROGMEM layer_colors[] = {
    [BASE]      = {0x00, 0x00, 0x00},  // Off
    [NAV]       = {0x9A, 0xFE, 0xFF},  // Electric Blue
    [EXTNAV]    = {0x16, 0xE2, 0xF5},  // Bright Turquoise
    [MACBASE]   = {0x00, 0x00, 0x00},  // Off
    [MACNAV]    = {0x00, 0xBF, 0xFF},  // Bright Sky
    [MACEXTNAV] = {0x15, 0x89, 0xFF},  // Neon Blue
    [SYM]       = {0xFF, 0xA6, 0x2F},  // Cantaloupe
    [FUNC]      = {0x7D, 0x05, 0x52},  // Velvet
    [MACFUNC]   = {0xCC, 0x7A, 0x8B},  // Dusky Pink
    [MOUSE]     = {0x73, 0x4F, 0x96},  // Dark Lavender
    [MOUSEEXT]  = {0x73, 0x4F, 0x96},
    [MSPEED10X] = {0x73, 0x4F, 0x96},
    [MSPEED5X]  = {0x73, 0x4F, 0x96},
};

bool rgb_matrix_indicators_user(void) {
    uint8_t layer = get_highest_layer(layer_state);
    if (layer >= (sizeof(layer_colors) / sizeof(layer_colors[0]))) {
        return false;
    }
    uint8_t r = pgm_read_byte(&layer_colors[layer].r);
    uint8_t g = pgm_read_byte(&layer_colors[layer].g);
    uint8_t b = pgm_read_byte(&layer_colors[layer].b);
    /* Divide brightness to mimic the Cornix /16 brightness divisor. */
    rgb_matrix_set_color_all(r / 4, g / 4, b / 4);
    return false;
}
#endif  // RGB_MATRIX_ENABLE

/* Coarse 3-LED binary layer code on the right-hand indicator LEDs. */
layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    if (layer & 0b001) ergodox_right_led_1_on();
    if (layer & 0b010) ergodox_right_led_2_on();
    if (layer & 0b100) ergodox_right_led_3_on();
    return state;
}




