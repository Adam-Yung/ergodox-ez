# Ergodox EZ - Cornix keymap port (QMK)

A full-fidelity port of the ZMK **Cornix** keymap to the stock **Ergodox EZ**,
which runs **QMK** (not ZMK). This is a self-contained
[QMK External Userspace](https://docs.qmk.fm/newbs_external_userspace):
GitHub Actions builds the firmware in the cloud and you flash the resulting
`.hex` with **Wally**.

> This is **not** imported into Oryx. Oryx has no "upload a `keymap.c`" path and
> cannot express the exact home-row-mod timing, the `SEND_STRING` macros, or the
> custom `process_record_user` logic used here. The `.hex` from CI flashes with
> the same Wally app, so you get full fidelity without Oryx.

## Layout

All 13 Cornix layers are preserved 1:1, matching the original `layer_N` numbering:

| # | Layer | # | Layer | # | Layer |
|---|-------|---|-------|---|-------|
| 0 | Base | 5 | MacExtNav | 10 | MouseExt |
| 1 | Nav | 6 | Sym | 11 | MSpeed10x |
| 2 | ExtNav | 7 | Func | 12 | MSpeed5x |
| 3 | MacBase | 8 | MacFunc | | |
| 4 | MacNav | 9 | Mouse | | |

### Home-row mods

Identical to the Cornix (`A/S/D/F` and `J/K/L/;`), implemented with QMK mod-tap:

| Key | Left | Key | Right |
|-----|------|-----|-------|
| A | Ctrl | J | Shift |
| S | Alt | K | Gui |
| D | Gui | L | Alt |
| F | Shift | ; | Ctrl |

Timing is ported from the ZMK `hm_l`/`hm_r` behaviors (see `config.h`):
`tapping-term 280ms`, `quick-tap 175ms`, `require-prior-idle 150ms`,
`balanced` flavor. The prior-idle guard is implemented in
`pre_process_record_user`.

## Hardware differences from the Cornix

The Cornix has 54 keys, two encoders and a trackball. The Ergodox EZ has 76 keys
and neither encoders nor a trackball, so three things change:

1. **No trackball** - the Mouse layers use QMK `KC_MS_*` cursor/scroll emulation.
   The two Cornix "speed" keys become `MS_ACL1` (half speed, ~5x) and `MS_ACL2`
   (max speed, ~10x), held with one hand while moving with the other
   (QMK `MK_COMBINED` mode).
2. **No encoders** - the volume, media and brightness that lived on the Cornix
   encoders move onto keys: volume + media sit on the right thumb cluster, and
   `KC_MUTE` sits on the inner thumb key (where the Cornix had `C_MUTE`).
3. **22 extra keys** - used to flatten frequent layer trips onto the base layer:
   - Top number row -> literal `1`-`0` (no longer Sym-only)
   - Outer pinky columns -> `[` `]` `(` `)`
   - Inner index columns -> `Esc` / `Enter`
   - 6-key thumb clusters -> Space, Bspc, layer-holds, media/volume

### RGB / indicators

Per-layer colors are ported from `config/cornix.conf` of the Cornix repo and
applied to the RGB matrix (on "Glow" EZ units) via `rgb_matrix_indicators_user`,
plus a coarse binary layer code on the three right-hand indicator LEDs. If your
EZ has no RGB matrix, set `RGB_MATRIX_ENABLE = no` in `rules.mk` and the ledmap
compiles out.

## Macros (ported from Cornix)

| QMK | Cornix | Output |
|-----|--------|--------|
| `M_PWD` | m0 | dummy password `wn0rkloveloveF!!!` |
| `M_CSTRUCT` | m5 | `->` |
| `M_JSLAMBDA` | m6 | `+> {}` with cursor between braces |
| `M_WIN_SELWORD` | m1 | select word (Windows) |
| `M_WIN_SELLINE` | m2 | select line (Windows) |
| `M_MAC_SELWORD` | m3 | select word (macOS) |
| `M_MAC_SELLINE` | m4 | select line (macOS) |
| `M_MOUSE1`..`5` | m_mouse1..5 | types `'MACRO N'` |

## Building

### GitHub Actions (recommended)

1. Push this repo to GitHub (see the parent project's final extraction step).
2. In the repo's **Actions** tab, enable workflows.
3. Any push runs `.github/workflows/qmk-build.yml`, which compiles
   `ergodox_ez:cornix` and uploads a **Firmware** artifact containing the `.hex`.

### Locally (optional)

```sh
qmk setup
qmk config user.overlay_dir="$(realpath .)"   # run from this repo's root
qmk compile -kb ergodox_ez -km cornix
```

## Flashing with Wally

1. Download the `.hex` artifact from the Actions run (or the local build output).
2. Open [Wally](https://www.zsa.io/wally/).
3. Press the Ergodox EZ reset button (top-left of the right/active half; use a
   paperclip through the hole).
4. Select the `.hex` in Wally and flash.

No Oryx involved.

## Files

```
qmk.json                                   # userspace build target
.github/workflows/qmk-build.yml            # cloud build
keyboards/ergodox_ez/keymaps/cornix/
    keymap.c                               # 13 layers, macros, HRM, RGB
    config.h                               # tap/hold + mouse + RGB tuning
    rules.mk                               # feature flags
```
