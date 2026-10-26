# Ergodox EZ Layout Reference

A QMK firmware port of the Cornix split keymap for the stock Ergodox EZ, featuring dual-OS support, home row mods, dedicated mouse layer, and per-layer RGB indicators.

---

## Features

- **Ergodox EZ** layout (76 keys, no encoders, no trackball)
- **Full-fidelity port** of all 13 Cornix layers, same layer indices
- **Dual-OS support** with separate Windows and macOS layer stacks
- **Home Row Mods** (CAGS) with per-key hold/tap callbacks and Flow Tap
- **Dedicated mouse layer** with IJKL movement and two speed profiles (ACL1/ACL2)
- **RGB matrix** per-layer solid color (Glow units) + 3 right-hand indicator LEDs (binary layer code)
- **Extra Ergodox keys** surface number row, bracket pairs, inner column, and media/navigation keys
- **Built via GitHub Actions** — push to main, download `.hex` from Artifacts, flash with Wally

---

## Layer Overview

| # | Name       | RGB Color (matrix)  | Activated By                          |
|---|------------|---------------------|---------------------------------------|
| 0 | Base       | Off                 | Default                               |
| 1 | Nav        | Electric Blue       | Hold left-thumb Nav                 |
| 2 | ExtNav     | Bright Turquoise    | Hold Nav, then right-thumb ExtNav |
| 3 | MacBase    | Off                 | TO(MACBASE) from Func layer         |
| 4 | MacNav     | Bright Sky Blue     | Hold left-thumb Nav (Mac)           |
| 5 | MacExtNav  | Neon Blue           | Hold MacNav + right-thumb ExtNav      |
| 6 | Sym        | Cantaloupe          | Hold right-thumb Sym                |
| 7 | Func       | Velvet              | Hold left-thumb Func                |
| 8 | MacFunc    | Dusky Pink          | Hold left-thumb Func (Mac)          |
| 9 | Mouse      | Dark Lavender       | Hold right-thumb Mouse              |
|10 | MouseExt   | Dark Lavender       | Hold Mouse, then right-thumb hold   |
|11 | MSpeed10x  | Dark Lavender       | Hold MS_ACL2 on Mouse layer         |
|12 | MSpeed5x   | Dark Lavender       | Hold MS_ACL1 on Mouse layer         |

---

## Ergodox EZ Physical Layout

The Ergodox EZ has 76 keys arranged as follows. The extra keys vs. Cornix are noted with `+`.

```
  +--+  +--+--+--+--+--+--+           +--+--+--+--+--+--+  +--+
  |  |  |  |  |  |  |  |  |           |  |  |  |  |  |  |  |  |
  +--+  +--+--+--+--+--+--+--+     +--+--+--+--+--+--+--+  +--+
         row0                                     row0

 Left half (rows 0-4):                Right half (rows 0-4):
 [L00][L01][L02][L03][L04][L05][L06]  [R00][R01][R02][R03][R04][R05][R06]
 [L07][L08][L09][L10][L11][L12][L13]  [R07][R08][R09][R10][R11][R12][R13]
 [L14][L15][L16][L17][L18][L19]            [R14][R15][R16][R17][R18][R19]
 [L20][L21][L22][L23][L24][L25][L26]  [R20][R21][R22][R23][R24][R25][R26]
 [L27][L28][L29][L30][L31]                      [R27][R28][R29][R30][R31]
                     [L32][L33]            [R32][R33]
                          [L34]            [R34]
                [L35][L36][L37]            [R35][R36][R37]
```

Positions L00 and R00 are the outermost top keys (only on Ergodox). L01-L06 / R01-R06 are the number row.
L14-L19 / R14-R19 are the home row. L27-L31 / R27-R31 are the fifth (bottom) row.
L32-L37 and R32-R37 are the thumb clusters.

---

## Layer 0 — Base (Windows)

```
+-------+-----+-----+-----+-----+-----+-------+         +-------+-----+-----+-----+-----+-----+-------+
|   `   |  1  |  2  |  3  |  4  |  5  |  Esc  |         |  Esc  |  6  |  7  |  8  |  9  |  0  |   -   |
+-------+-----+-----+-----+-----+-----+-------+         +-------+-----+-----+-----+-----+-----+-------+
|  Tab  |  Q  |  W  |  E  |  R  |  T  |   [   |         |   ]   |  Y  |  U  |  I  |  O  |  P  | Bksp  |
+-------+-----+-----+-----+-----+-----+       |         |       +-----+-----+-----+-----+-----+-------+
|  Esc  |  A  |  S  |  D  |  F  |  G  +-------+         +-------+  H  |  J  |  K  |  L  |  ;  |   '   |
|       |Ctrl |Alt  |GUI  |Shift|     |                           |     |Shift|GUI  |Alt  |Ctrl |       |
+-------+-----+-----+-----+-----+-----+-------+         +-------+-----+-----+-----+-----+-----+-------+
|Shift  |  Z  |  X  |  C  |  V  |  B  |   (   |         |   )   |  N  |  M  |  ,  |  .  | Up  |   /   |
+-------+-----+-----+-----+-----+-----+-------+         +-------+-----+-----+-----+-----+-----+-------+
| Ctrl  | GUI | Alt |Func |Space|                                       |Left |Down |Right| Ent | Bksp  |
+-------+-----+-----+-----+-----+                                       +-----+-----+-----+-----+-------+
                                 +-------+-------+  +-------+-------+
                                 | Mute  | Play  |  | VolDn | VolUp |
                          +------+-------+-------+  +-------+-------+------+
                          |      |       | Mouse |  | Mouse |       |      |
                          | Func | Sym   +-------+  +-------+ Nav   | Ent  |
                          |      |       |  Nav  |  |  Sym  |       |      |
                          +------+-------+-------+  +-------+-------+------+
```

**Home Row Mods** (tap for letter, hold for modifier — 280ms tapping term):
- Left: A=Ctrl, S=Alt, D=GUI, F=Shift
- Right: J=Shift, K=GUI, L=Alt, ;=Ctrl
- Flow Tap (150ms prior-idle) prevents accidental mod activation during fast typing

**Extra Ergodox keys used on Base:**
- Number row (`1-0`, `-`, `` ` ``) always visible — no Sym layer trip for numbers
- Outer bracket row (`[`, `]`) and paren row (`(`, `)`)
- Right-hand bottom row: cursor arrows (`Left`, `Up`, `Down`, `Right`), `Enter`, `Bksp`
- Top inner keys: additional `Esc` on each side
- Thumb clusters carry `Func`, `Sym`, `Nav`, `Mouse`, `Space`, `Enter`, `Mute`, `Play/Pause`, `VolDn`, `VolUp`

**Thumb cluster (left):**
- Top pair: `Mute`, `Play/Pause`
- Mid: `Mouse` (MO 9)
- Bottom: `Func` (MO 7), `Sym` (MO 6), `Nav` (MO 1)

**Thumb cluster (right):**
- Top pair: `VolDn`, `VolUp`
- Mid: `Mouse` (MO 9)
- Bottom: `Nav` (MO 1), `Sym` (MO 6), `Enter`

---

## Layer 1 — Nav

```
+-------+-----+-----+-------+-------+-----+-------+         +-------+-----+-----+-----+-----+-----+-------+
|  Tab  |     |     | SelWd | SelLn |     |       |         |       |     |     |     |     |     |       |
+-------+-----+-----+-------+-------+-----+-------+         +-------+-----+-----+-----+-----+-----+-------+
|  Tab  |     |     | SelWd | SelLn |     |       |         |       |     |Bksp | Up  | Del |     |       |
+-------+-----+-----+-------+-------+-----+       |         |       +-----+-----+-----+-----+-----+-------+
|  Esc  |Ct+A |Shift| Home  |  End  |CapsW+-------+         +-------+     |Left |Down |Right|S+Ret|S+Ret  |
+-------+-----+-----+-------+-------+-----+-------+         +-------+-----+-----+-----+-----+-----+-------+
|Shift  |Undo | Cut | Copy  | Paste |     |       |         |       |     |     |     |     |     |       |
+-------+-----+-----+-------+-------+-----+-------+         +-------+-----+-----+-----+-----+-----+-------+
| Ctrl  | GUI | Alt |       |       |                                       |ExtNv|     |     |     |       |
+-------+-----+-----+-------+-------+                                       +-----+-----+-----+-----+-------+
                                 +-------+-------+  +-------+-------+
                                 | Mute  |       |  |       |       |
                          +------+-------+-------+  +-------+-------+------+
                          |      |       |       |  |       |       |      |
                          |      |       +-------+  +-------+ExtNav |      |
                          |      |       |ExtNav |  |       |       |      |
                          +------+-------+-------+  +-------+-------+------+
```

**Right-hand navigation (IJKL-style):** `U`=Bksp, `I`=Up, `O`=Del, `J`=Left, `K`=Down, `L`=Right
**Left-hand editing:** `A`=Select All, `S`=Shift, `D`=Home, `F`=End, `E`/`R`=Select Word/Line, `G`=Caps Word
**Enter:** `S+Ret` on both `;` position and right pinky (Shift+Enter without stretching)
- `SelWd` (M_WIN_SELWORD) = Ctrl+Left, Shift+Ctrl+Right
- `SelLn` (M_WIN_SELLINE) = Home, Shift+End
- `ExtNav` = MO(EXTNAV) on right thumb and bottom-right

---

## Layer 2 — ExtNav

```
+-------+-----+-----+-------+-------+-----+-------+         +-------+-----+--------+-------+--------+-----+-------+
|  Tab  |     |     | SelWd | SelLn |     |       |         |       |     |        |       |        |     |       |
+-------+-----+-----+-------+-------+-----+-------+         +-------+-----+--------+-------+--------+-----+-------+
|  Tab  |     |     | SelWd | SelLn |     |       |         |       |     | Ct+Bksp| PgUp  | Ct+Del |     |       |
+-------+-----+-----+-------+-------+-----+       |         |       +-----+--------+-------+--------+-----+-------+
|  Esc  |Ct+A |Shift| Home  |  End  |     +-------+         +-------+     | Ct+Lft | PgDn  | Ct+Rgt |Enter|Enter  |
+-------+-----+-----+-------+-------+-----+-------+         +-------+-----+--------+-------+--------+-----+-------+
|Shift  |C+S+Z| Cut | Copy  | Paste |     |       |         |       |     |        |       |        |     |       |
+-------+-----+-----+-------+-------+-----+-------+         +-------+-----+--------+-------+--------+-----+-------+
| Ctrl  | GUI | Alt |       |       |                                       |       |       |       |     |       |
+-------+-----+-----+-------+-------+                                       +-------+-------+-------+-----+-------+
```

Extended navigation with word-jump (`Ctrl+Left/Right`), page up/down, and word-delete (`Ctrl+Bksp/Del`).
`C+S+Z` = Ctrl+Shift+Z (Redo on Windows).

---

## Layer 3 — MacBase

Identical to Base. MO targets switch to Mac variants:
- Left-thumb bottom: `Func`=MO(MACFUNC), `MacNav`=MO(MACNAV), `Sym`=MO(SYM)
- Right-thumb bottom: `MacNav`=MO(MACNAV), `Func`=MO(MACFUNC), `Ent`
- Home row mods identical (GUI = Cmd on macOS)

---

## Layer 4 — MacNav

```
+-------+-----+-----+-------+-------+-----+-------+         +-------+-----+-----+-----+-----+-----+-------+
|  Tab  |     |     | SelWd | SelLn |     |       |         |       |     |     |     |     |     |       |
+-------+-----+-----+-------+-------+-----+-------+         +-------+-----+-----+-----+-----+-----+-------+
|  Tab  |     |     | SelWd | SelLn |     |       |         |       |     |Bksp | Up  | Del |     |       |
+-------+-----+-----+-------+-------+-----+       |         |       +-----+-----+-----+-----+-----+-------+
|  Esc  |Cmd+A|Shift|Cmd+Lft|Cmd+Rgt|CapsW+-------+         +-------+     |Left |Down |Right|S+Ret|S+Ret  |
+-------+-----+-----+-------+-------+-----+-------+         +-------+-----+-----+-----+-----+-----+-------+
|Shift  |Cmd+Z|Cmd+X|Cmd+C  |Cmd+V  |     |       |         |       |     |     |     |     |     |       |
+-------+-----+-----+-------+-------+-----+-------+         +-------+-----+-----+-----+-----+-----+-------+
| Ctrl  | GUI | Alt |       |       |                                       |MxExt|     |     |     |       |
+-------+-----+-----+-------+-------+                                       +-----+-----+-----+-----+-------+
```

Uses `Cmd` (GUI) for macOS shortcuts. `SelWd`/`SelLn` use Alt-based word selection (M_MAC_SELWORD/LINE).
`Cmd+Left`/`Cmd+Right` = Start/End of line on macOS.

---

## Layer 5 — MacExtNav

```
+-------+-----+-----+-------+-------+-----+-------+         +-------+-----+--------+-------+--------+-----+-------+
|  Tab  |     |     | SelWd | SelLn |     |       |         |       |     |        |       |        |     |       |
+-------+-----+-----+-------+-------+-----+-------+         +-------+-----+--------+-------+--------+-----+-------+
|  Tab  |     |     | SelWd | SelLn |     |       |         |       |     | Al+Bksp| PgUp  | Al+Del |     |       |
+-------+-----+-----+-------+-------+-----+       |         |       +-----+--------+-------+--------+-----+-------+
|  Esc  |Cmd+A|Shift|Cmd+Lft|Cmd+Rgt|     +-------+         +-------+     | Al+Lft | PgDn  | Al+Rgt |Enter|Enter  |
+-------+-----+-----+-------+-------+-----+-------+         +-------+-----+--------+-------+--------+-----+-------+
|Shift  |C+S+Z|Cmd+X|Cmd+C  |Cmd+V  |     |       |         |       |     |        |       |        |     |       |
+-------+-----+-----+-------+-------+-----+-------+         +-------+-----+--------+-------+--------+-----+-------+
```

Extended navigation for macOS. `Alt+Left/Right` = word-jump. `Alt+Bksp/Del` = word-delete.

---

## Layer 6 — Sym (Symbols)

```
+-------+-----+-----+-----+-----+-----+-------+         +-------+-----+-----+-----+-----+-----+-------+
|   `   |  1  |  2  |  3  |  4  |  5  |       |         |       |  6  |  7  |  8  |  9  |  0  |   -   |
+-------+-----+-----+-----+-----+-----+-------+         +-------+-----+-----+-----+-----+-----+-------+
| Bksp  |  1  |  2  |  3  |  -> | =>{} |      |         |   `   |  (  |  )  |  [  |  ]  |     | Bksp  |
+-------+-----+-----+-----+-----+-----+       |         |       +-----+-----+-----+-----+-----+-------+
| Space |  4  |  5  |  6  |  -  |  =  +-------+         +-------+  +  |  ,  |  .  |  ?  |  /  |   \   |
+-------+-----+-----+-----+-----+-----+-------+         +-------+-----+-----+-----+-----+-----+-------+
|Shift  |  7  |  8  |  9  |  \  |  |  |       |         |       |  &  |  *  |  ^  |  %  |  #  |   $   |
+-------+-----+-----+-----+-----+-----+-------+         +-------+-----+-----+-----+-----+-----+-------+
| Ctrl  |  0  |  .  |     |Shift|                                       |     |  ;  |  !  |  @  |       |
+-------+-----+-----+-----+-----+                                       +-----+-----+-----+-----+-------+
                                 +-------+-------+  +-------+-------+
                                 | Mute  |       |  |       |       |
                          +------+-------+-------+  +-------+-------+------+
                          |      |       |       |  |       |       |      |
                          |Shift |       +-------+  +-------+       |      |
                          |      |       |       |  |       |       |      |
                          +------+-------+-------+  +-------+-------+------+
```

**Left side — Numpad (same as Cornix):**
- Spatial 3x3 grid: QWE=123, ASD=456, ZXC=789, GUI/Alt=0/.
- `->` (M_CSTRUCT) and `=> {}` (M_JSLAMBDA) on left index column
- Arithmetic `- =` on home-row index/middle fingers

**Right side — Symbols by group:**
- **Row 0 — Brackets:** `` ` ( ) [ ] ``
- **Row 1 — Everyday punctuation:** `+ , . ? / \`
- **Row 2 — Bitwise/math:** `& * ^ % # $`
- **Row 3 — Statement enders:** `; ! @`

**Special keys:**
- `->` (M_CSTRUCT) = Types `->` (C struct arrow)
- `=> {}` (M_JSLAMBDA) = Types `=> {}` then moves cursor inside braces
- `Space` = Space character for convenience while in Sym layer

---

## Layer 7 — Func (Windows)

```
+-------+-----+-----+-----+-----+-----+-------+         +-------+-----+-----+-----+-----+-----+-------+
|       |  F1 |  F2 |  F3 |  F4 |  F5 |       |         |       |  F6 |  F7 |  F8 |  F9 | F10 |  F11  |
+-------+-----+-----+-----+-----+-----+-------+         +-------+-----+-----+-----+-----+-----+-------+
|       |     |     |     |M_PWD|     |       |         |       |     |     |     |     |     |  F12  |
+-------+-----+-----+-----+-----+-----+       |         |       +-----+-----+-----+-----+-----+-------+
|       |     |     |     |     |     +-------+         +-------+     |     |     |     |     |       |
+-------+-----+-----+-----+-----+-----+-------+         +-------+-----+-----+-----+-----+-----+-------+
| Boot  |     |     |     |     |     |       |         |       |     |     |     |     |     |       |
+-------+-----+-----+-----+-----+-----+-------+         +-------+-----+-----+-----+-----+-----+-------+
|       | Boot|     |     |TO(0)|                                       |     |     |     |     |       |
+-------+-----+-----+-----+-----+                                       +-----+-----+-----+-----+-------+
                                 +-------+-------+  +-------+-------+
                                 | Mute  |       |  |       |       |
                          +------+-------+-------+  +-------+-------+------+
                          |      |       |       |  |       |       |      |
                          |      |TO(Mac)+-------+  +-------+       |      |
                          |      |       |       |  |       |       |      |
                          +------+-------+-------+  +-------+-------+------+
```

**LED color: Velvet (RGB matrix) — indicates Windows mode**

**Key assignments:**
- `M_PWD` (F position, row 1) = Types stored password macro
- `TO(0)` = Switch to Base (Windows) mode
- `TO(Mac)` = Switch to MacBase (macOS) mode (left mid-thumb)
- `Boot` = QK_BOOT — enter bootloader for flashing (both halves have it)
- F1–F12 across rows 0-1

> **Note:** ZMK had BT_SEL/BT_CLR here. The Ergodox EZ is USB-only, so those positions are replaced with the password macro and OS-switch keys.

---

## Layer 8 — MacFunc

Identical to Func. The different LED color (Dusky Pink vs. Velvet) confirms you are in macOS mode.

---

## Layer 9 — Mouse

```
+-------+--------+--------+--------+--------+--------+-------+         +-------+-----+-----+------+-----+-----+-------+
|       | Mcro1  | Mcro2  | Mcro3  | Mcro4  | Mcro5  |       |         |       |     |     |      |     |     |       |
+-------+--------+--------+--------+--------+--------+-------+         +-------+-----+-----+------+-----+-----+-------+
|       | Mcro1  | Mcro2  | Mcro3  | Mcro4  | Mcro5  |       |         |       |     |Back | M.Up | Fwd |     |       |
+-------+--------+--------+--------+--------+--------+       |         |       +-----+-----+------+-----+-----+-------+
|       | Spd10x | Spd5x  | RClk   | LClk   |        +-------+         +-------+     |M.Lt |M.Dn  |M.Rt |     |       |
+-------+--------+--------+--------+--------+--------+-------+         +-------+-----+-----+------+-----+-----+-------+
|       |        |        |        |        |        |       |         |       |     |     |      |     |     |       |
+-------+--------+--------+--------+--------+--------+-------+         +-------+-----+-----+------+-----+-----+-------+
|       |        |        | Shift  | Spd5x  |                                         |     |      |     |     |       |
+-------+--------+--------+--------+--------+                                         +-----+------+-----+-----+-------+
                                 +-------+-------+  +-------+-------+
                                 | Mute  |       |  |       |       |
                          +------+-------+-------+  +-------+-------+------+
                          |      |       |       |  |MoExt  |       |      |
                          |      |MoExt  +-------+  +-------+       |      |
                          |      |       |       |  |       |       |      |
                          +------+-------+-------+  +-------+-------+------+
```

**Design:** Right-hand IJKL-style cursor movement. Left-hand holds speed or click modifiers. No trackball on the EZ — all mouse movement is emulated via QMK MOUSEKEY.

**Movement (right hand):**
- `U`=Back (MB4), `I`=Mouse Up, `O`=Fwd (MB5)
- `J`=Mouse Left, `K`=Mouse Down, `L`=Mouse Right
- Clicks: `D`=Right Click (MS_BTN2), `F`=Left Click (MS_BTN1)

**Speed modifiers (QMK MK_COMBINED mode):**
- `A` (Spd10x) = `MS_ACL2` held — max acceleration profile (~10x speed)
- `S` (Spd5x) = `MS_ACL1` held — half acceleration profile (~5x speed)
- Hold while moving for boosted speed; release to return to base precision

**Other:**
- `Mcro1`–`Mcro5` = Placeholder macros (type `'MACRO 1'` through `'MACRO 5'`)
- `Shift` = Shift modifier (enables shift+click and shift+drag)
- `MoExt` = MO(MOUSEEXT) — hold for scroll wheel mode

---

## Layer 10 — MouseExt (Scroll + Browser Nav)

```
+-------+-----+-----+-----+-----+-----+-------+         +-------+-----+------+------+------+-----+-------+
|  (.)  | (.) | (.) | (.) | (.) | (.) |  (.)  |         |  (.)  | (.) |  (.) |  (.) |  (.) | (.) |  (.)  |
+-------+-----+-----+-----+-----+-----+-------+         +-------+-----+------+------+------+-----+-------+
|  (.)  | (.) | (.) | (.) | (.) | (.) |  (.)  |         |  (.)  | (.) | Back |Scr Up| Fwd  | (.) |  (.)  |
+-------+-----+-----+-----+-----+-----+       |         |       +-----+------+------+------+-----+-------+
|  (.)  | (.) | (.) | (.) | (.) | (.) +-------+         +-------+ (.) |Scr Lt|Scr Dn|Scr Rt| (.) |  (.)  |
+-------+-----+-----+-----+-----+-----+-------+         +-------+-----+------+------+------+-----+-------+
|  (.)  | (.) | (.) | (.) | (.) | (.) |  (.)  |         |  (.)  | (.) |  (.) |  (.) |  (.) | (.) |  (.)  |
+-------+-----+-----+-----+-----+-----+-------+         +-------+-----+------+------+------+-----+-------+
|  (.)  | (.) | (.) | (.) | (.) |                                       | (.) |  (.) |  (.) | (.) |  (.)  |
+-------+-----+-----+-----+-----+                                       +-----+------+------+-----+-------+
```

`(.)` = transparent — falls through to Mouse layer. All movement, clicks, speed keys, and Shift remain active.

**Scroll overrides (right-hand IJKL positions):**
- `U` = MB4 (Back), `I` = Scroll Up, `O` = MB5 (Fwd)
- `J` = Scroll Left, `K` = Scroll Down, `L` = Scroll Right

---

## Layers 11–12 — Speed Modifier Layers

These are fully transparent (`KC_TRNS`) layers. On the Cornix they used `zip_xy_scaler` input processors on dedicated layers. On the EZ, speed is controlled by holding `MS_ACL1`/`MS_ACL2` directly on the Mouse layer (QMK MK_COMBINED mode), so these layers exist for structural parity with Cornix numbering but are not separately activated.

| Layer | Name      | QMK Speed Key | Effect                          |
|-------|-----------|---------------|---------------------------------|
|  11   | MSpeed10x | MS_ACL2 held  | Max speed profile (~10x base)   |
|  12   | MSpeed5x  | MS_ACL1 held  | Half speed profile (~5x base)   |

---

## Home Row Mods — Quick Reference

```
Left hand:                          Right hand:
+-----+-----+-----+-----+          +-----+-----+-----+-----+
|  A  |  S  |  D  |  F  |          |  J  |  K  |  L  |  ;  |
|Ctrl |Alt  |GUI  |Shift|          |Shift|GUI  |Alt  |Ctrl |
+-----+-----+-----+-----+          +-----+-----+-----+-----+
```

**Timing (matches Cornix exactly):**
- Tapping term: 280ms (hold longer to activate modifier)
- Quick-tap: 175ms (fast double-tap repeats the letter instead of the mod)
- Flow Tap prior-idle: 150ms (must pause 150ms before HRM can activate — prevents misfires in fast typing)
- Hold-on-other-key-press: enabled for HRM keys (chord with opposite hand activates modifier)

---

## Macros

| Name         | Key Position         | Output / Action                                  |
|--------------|----------------------|--------------------------------------------------|
| M_PWD        | Func layer, F pos    | Types `wn0rkloveloveF!!!` (password placeholder) |
| M_CSTRUCT    | Sym layer, R pos     | Types `->` (C struct arrow operator)             |
| M_JSLAMBDA   | Sym layer, T pos     | Types `=> {}` then moves cursor inside braces    |
| M_WIN_SELWORD| Nav/ExtNav E pos     | Ctrl+Left, Shift+Ctrl+Right (select word, Win)   |
| M_WIN_SELLINE| Nav/ExtNav R pos     | Home, Shift+End (select line, Win)               |
| M_MAC_SELWORD| MacNav/ExtNav E pos  | Alt+Left, Shift+Alt+Right (select word, Mac)     |
| M_MAC_SELLINE| MacNav/ExtNav R pos  | Cmd+Left, Shift+Cmd+Right (select line, Mac)     |
| M_MOUSE1–5   | Mouse layer row 0/1  | Types `'MACRO 1'` through `'MACRO 5'`            |

---

## RGB / LED Indicator System

### RGB Matrix (Glow units — full keyboard backlight)

Solid per-layer color, matching the Cornix left-side indicator colors exactly:

| Layer      | Color Name       | Hex       |
|------------|------------------|-----------|
| Base       | Off              | `#000000` |
| Nav        | Electric Blue    | `#9AFEFF` |
| ExtNav     | Bright Turquoise | `#16E2F5` |
| MacBase    | Off              | `#000000` |
| MacNav     | Bright Sky Blue  | `#00BFFF` |
| MacExtNav  | Neon Blue        | `#1589FF` |
| Sym        | Cantaloupe       | `#FFA62F` |
| Func       | Velvet           | `#7D0552` |
| MacFunc    | Dusky Pink       | `#CC7A8B` |
| Mouse      | Dark Lavender    | `#734F96` |
| MouseExt   | Dark Lavender    | `#734F96` |
| MSpeed10x  | Dark Lavender    | `#734F96` |
| MSpeed5x   | Dark Lavender    | `#734F96` |

> Colors are rendered at 1/4 brightness (matching Cornix `/16` brightness divisor) via `RGB_MATRIX_DEFAULT_VAL 60`.

### Right-Hand Indicator LEDs (3 LEDs — all Ergodox EZ units)

The 3 right-hand LEDs display the current layer as a 3-bit binary code (LED1 = bit 0, LED2 = bit 1, LED3 = bit 2):

| LED pattern  | Layer # | Layer Name        |
|:------------:|---------|-------------------|
| `· · ·`      |   0     | Base / MacBase    |
| `● · ·`      |   1     | Nav               |
| `· ● ·`      |   2     | ExtNav            |
| `● ● ·`      |   3     | MacBase (alt)     |
| `· · ●`      |   4     | MacNav            |
| `● · ●`      |   5     | MacExtNav         |
| `· ● ●`      |   6     | Sym               |
| `● ● ●`      |   7     | Func / MacFunc    |
| `· · ·` +1   |   8     | MacFunc (wrap)    |
| `● · ·` +1   |   9     | Mouse             |
| `· ● ·` +1   |  10     | MouseExt          |
| `● ● ·` +1   |  11     | MSpeed10x         |
| `· · ●` +1   |  12     | MSpeed5x          |

> `●` = LED on, `·` = LED off. LED1 is the bottom LED, LED3 is the top (rightmost side).

---

## Differences from Cornix

| Feature               | Cornix (ZMK)                        | Ergodox EZ (QMK)                      |
|-----------------------|-------------------------------------|---------------------------------------|
| Key count             | 54 keys + 2 encoders                | 76 keys, no encoders                  |
| Pointing device       | Trackball (physical)                | MOUSEKEY emulation (MS_* keycodes)    |
| Mouse movement        | `&mmv MOVE_*` input processor       | `MS_UP/DOWN/LEFT/RGHT` keycodes       |
| Mouse speed           | `zip_xy_scaler 5x/10x` on layers   | `MS_ACL1/ACL2` held on Mouse layer    |
| Scroll                | `&msc SCRL_*` input processor       | `MS_WHLU/D/L/R` keycodes              |
| Encoder L (Vol)       | Rotate = Vol Up/Down                | `VolUp`/`VolDn` on right thumb top    |
| Encoder L (Mute)      | Press = Mute                        | `Mute` on left thumb top              |
| Encoder R (Play)      | Press = Play/Pause                  | `Play` on left thumb top              |
| Encoder R (Bri)       | Rotate = Brightness Up/Down         | Not ported (no brightness keys)       |
| Encoder R (Nav)       | Rotate = Browser Fwd/Back           | `MB4`/`MB5` on Mouse layer U/O pos   |
| Encoder R (Track)     | Rotate = Next/Prev track            | Not ported (available to add)         |
| BT profiles           | BT_SEL 0/1/2 + BT_CLR              | USB only — replaced by TO(0)/TO(Mac)  |
| LED (left indicator)  | Per-layer solid color widget        | RGB matrix solid color                |
| LED (right indicator) | BT status (connect/advert/disconnect)| 3-LED binary layer code              |
| HRM prior-idle        | `require-prior-idle-ms=150` (ZMK)   | `FLOW_TAP_TERM 150` (QMK, built-in)  |
| HRM flavor            | `balanced` hold-tap                 | `PERMISSIVE_HOLD` + `HOLD_ON_OTHER`   |
| Extra keys on Base    | None (54 keys, all needed for layers)| Number row, brackets, cursor arrows   |

---

## Building & Flashing

### Build (GitHub Actions)

1. Push to `main` — the `qmk-build.yml` workflow builds automatically
2. Go to **Actions** → latest run → **Firmware** artifact
3. Download and unzip to get `ergodox_ez_base_cornix.hex`

### Flash with Wally

1. Install [Wally](https://ergodox-ez.com/pages/wally) from ZSA
2. Open Wally, select the `.hex` file
3. On the keyboard, press the reset button (small hole on the right half underside)
4. Wally detects the keyboard and flashes automatically

### Local Build (optional)

```sh
git clone https://github.com/qmk/qmk_firmware
cd qmk_firmware && python3 -m pip install -r requirements.txt
qmk setup -H "$(pwd)"
cd ..
qmk config user.overlay_dir="$(pwd)"
qmk userspace-compile -p
```

---

## Switching Between Windows and macOS

From any base layer, enter the Func layer and press:
- **Left thumb `TO(0)`** = Switch to Windows mode (Base)
- **Left mid-thumb `TO(Mac)`** = Switch to macOS mode (MacBase)

The RGB matrix color confirms the mode when Func is held:
- **Velvet** (`#7D0552`) = Windows
- **Dusky Pink** (`#CC7A8B`) = macOS
