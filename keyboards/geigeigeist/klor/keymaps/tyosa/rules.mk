BOOTLOADER=rp2040
CONVERT_TO=rp2040_ce

COMBO_ENABLE=yes
REPEAT_KEY_ENABLE=yes
CAPS_WORD_ENABLE=yes

EXTRAFLAGS += -flto=auto
LTO_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes
