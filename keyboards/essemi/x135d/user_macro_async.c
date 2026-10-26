#include "quantum.h"
#include "send_string.h"
#include "send_string_keycodes.h"
#include "action.h"
#include "dynamic_keymap.h"

#ifdef MACRO_ASYNC_PLAY_ENABLE

#ifndef DYNAMIC_KEYMAP_MACRO_DELAY
// #    define DYNAMIC_KEYMAP_MACRO_DELAY TAP_CODE_DELAY
#    define DYNAMIC_KEYMAP_MACRO_DELAY 1
#endif

/* send_string.c 内部宏，头文件未导出 */
#define PGM_LOADBIT(mem, pos) ((pgm_read_byte(&((mem)[(pos) / 8])) >> ((pos) % 8)) & 0x01)

typedef struct {
    bool     busy; /* 正在播 */
    uint16_t wait; /* 剩余 tick；1 tick = 2ms；0 = 不等 */
    uint16_t pos;  /* 宏缓冲区内偏移 */
    uint8_t  Action;
    char  asscii;
} user_macro_t;

static user_macro_t um;

static uint8_t um_ee(uint16_t off) {
    uint8_t b = 0;
    dynamic_keymap_macro_get_buffer(off, 1, &b);
    return b;
}

static uint16_t um_macro_size(void) {
    return dynamic_keymap_macro_get_buffer_size();
}

/* 无 wait：一次把字符对应的键打完 */
static void um_send_char_nowait(char ascii_code) {
    uint8_t keycode    = pgm_read_byte(&ascii_to_keycode_lut[(uint8_t)ascii_code]);
    bool    is_shifted = PGM_LOADBIT(ascii_to_shift_lut, (uint8_t)ascii_code);
    bool    is_altgred = PGM_LOADBIT(ascii_to_altgr_lut, (uint8_t)ascii_code);
    bool    is_dead    = PGM_LOADBIT(ascii_to_dead_lut, (uint8_t)ascii_code); 

    if (um.Action == 0) {
        if (is_shifted) register_code(KC_LEFT_SHIFT);
        if (is_altgred) register_code(KC_RIGHT_ALT);
        register_code(keycode);
        if (is_dead) {
            register_code(KC_SPACE);
        }
        um.Action = 1;
    } else {
        unregister_code(keycode);
        if (is_altgred) unregister_code(KC_RIGHT_ALT);
        if (is_shifted) unregister_code(KC_LEFT_SHIFT);
        if (is_dead) {
            unregister_code(KC_SPACE);
        }
        um.Action = 0;
    }
}

/* 定位第 id 段宏起点（与 dynamic_keymap_macro_send 相同规则） */
static bool um_seek(uint8_t id, uint16_t *out_pos) {
    uint16_t size = um_macro_size();
    if (id >= dynamic_keymap_macro_get_count()) return false;
    if (size == 0) return false;
    if (um_ee(size - 1) != 0) return false;
    uint16_t p = 0;
    while (id > 0) {
        if (p >= size) return false;
        if (um_ee(p) == 0) --id;
        ++p;
    }
    *out_pos = p;
    um.Action = 0;
    return true;
}

void user_macro_send(uint8_t id) {
    uint16_t pos;
    if (um.busy) return;
    if (!um_seek(id, &pos)) return;
    um.busy = true;
    um.wait = 0;
    um.pos  = pos;
}

static bool um_read(uint8_t *b) {
    if (um.pos >= um_macro_size()) return false;
    *b = um_ee(um.pos++);
    return true;
}

static void um_step_one(void) {
    uint8_t interval = DYNAMIC_KEYMAP_MACRO_DELAY;
    uint8_t b;
    
    if (um.Action == 0) {
        if (!um_read(&b) || b == 0) {
            um.busy = false;
            return;
        }
        um.asscii = b;
    }

    if (b == SS_QMK_PREFIX) {
        um.Action = 0;
        uint8_t code;
        if (!um_read(&code) || code == 0) {
            um.busy = false;
            return;
        }
        if (code == SS_TAP_CODE) {
            uint8_t kc;
            if (!um_read(&kc) || kc == 0) {
                um.busy = false;
                return;
            }
            register_code(kc);
            unregister_code(kc);
            um.wait = interval;
            return;
        }
        if (code == SS_DOWN_CODE) {
            uint8_t kc;
            if (!um_read(&kc) || kc == 0) {
                um.busy = false;
                return;
            }
            register_code(kc);
            um.wait = interval;
            return;
        }
        if (code == SS_UP_CODE) {
            uint8_t kc;
            if (!um_read(&kc) || kc == 0) {
                um.busy = false;
                return;
            }
            unregister_code(kc);
            um.wait = interval;
            return;
        }
        if (code == SS_DELAY_CODE) {
            uint16_t ticks = 0;
            uint8_t  ch;
            while (1) {
                if (!um_read(&ch) || ch == 0) {
                    um.busy = false;
                    return;
                }
                if (ch == '|') break;
                if (ch < '0' || ch > '9') {
                    um.busy = false;
                    return;
                }
                ticks = ticks + (ch - '0');
            }
            um.wait = ticks;
            return;
        }
        um.busy = false;
        return;
    }
    //单按键
    um_send_char_nowait(um.asscii);
    um.wait = interval;
}

void user_macro_task(void) {
    if (!um.busy) return;
    if (um.wait > 0) {
        um.wait--;
        return;
    }
    um_step_one();
}

#endif /* MACRO_ASYNC_PLAY_ENABLE */


