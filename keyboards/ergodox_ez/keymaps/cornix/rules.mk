# Cornix-port keymap build options for the Ergodox EZ
#
# This mirrors the feature set used by the ZMK Cornix keymap:
#   - home-row mods (mod-tap)   -> core, no flag needed
#   - layer switching           -> core
#   - mouse emulation (trackball replacement)
#   - caps word
#   - per-layer RGB matrix colors (WS2812 widget replacement)

MOUSEKEY_ENABLE   = yes    # KC_MS_* cursor/scroll emulation (replaces trackball)
EXTRAKEY_ENABLE   = yes    # media + volume keys (replaces encoders)
CAPS_WORD_ENABLE  = yes    # &caps_word

# RGB: the EZ ships with the "Glow" RGB matrix on many units. If you have a
# non-Glow EZ, set RGB_MATRIX_ENABLE = no and the ledmap code compiles out.
RGB_MATRIX_ENABLE = yes
RGBLIGHT_ENABLE   = no

# Keep the firmware small enough for older 32KB EZ boards.
LTO_ENABLE        = yes
CONSOLE_ENABLE    = no
COMMAND_ENABLE    = no
