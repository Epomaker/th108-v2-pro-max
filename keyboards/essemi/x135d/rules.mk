# Build Options
#   change yes to no to disable
#
# Board: it should exist either in <chibios>/os/hal/boards/
#  or <this_dir>/boards
BOARD = FS026
EEPROM_CUSTOM = custom
NO_USB_STARTUP_CHECK = yes
BLUETOOTH_CUSTOM = yes

# ENCODER_MAP_ENABLE = yes    # Enable ENCODER MAP
DEBOUNCE_TYPE = asym_eager_defer_pk

SRC += user_macro_async.c
OPT_DEFS += -DMACRO_ASYNC_PLAY_ENABLE

# 新版宏录制，使用QMK官方自带的六键/全键无冲算法
OPT_DEFS += -DES_QMK_STANDARD_NKRO
