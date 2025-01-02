BOOTLOADER=rp2040
CONVERT_TO=promicro_rp2040

OLED_ENABLE = yes
ENCODER_ENABLE = yes
EXTRAFLAGS += -flto=auto
LTO_ENABLE = yes
WPM_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes
# TAP_DANCE_ENABLE = yes
MOUSEKEY_ENABLE = yes

# Inclusions
SRC += tyosa.c
SRC += encoder.c
SRC += oled.c
SRC += luna.c
# SRC += tap_dances.c
SRC += macros.c

# AVR optimizations
RGB_MATRIX_ENABLE = no
CONSOLE_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
RGBLIGHT_ENABLE = no
UNICODE_ENABLE = no
COMMAND_ENABLE = no
LEADER_ENABLE = no
MUSIC_ENABLE = no
