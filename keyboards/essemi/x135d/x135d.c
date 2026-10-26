/* Copyright 2023 Finalkey
 * Copyright 2023 LiWenLiu <https://github.com/Linger7857>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "../../lib/rdr_lib/rdr_common.h"

void matrix_io_delay(void) {
}

void matrix_output_select_delay(void) {
}

void matrix_output_unselect_delay(uint8_t line, bool key_pressed) {
}

led_config_t g_led_config = { {
	{ 0        , 1        , 2        , 3        , 4        , 5        , 6        , 7        , 8        , 9        , 10       , 11       , 12       , 13       , 14       , 15        },
    { 20       , 21       , 22       , 23       , 24       , 25       , 26       , 27       , 28       , 29       , 30       , 31       , 32       , 33       , 17       , NO_LED    },
    { 38       , 39       , 40       , 41       , 42       , 43       , 44       , 45       , 46       , 47       , 48       , 49       , 50       , 51       , 16       , NO_LED    },
    { 56       , 57       , 58       , 59       , 60       , 61       , 62       , 63       , 64       , 65       , 66       , 67       , NO_LED   , 68       , 18       , 19        },
    { 72       , NO_LED   , 73       , 74       , 75       , 76       , 77       , 78       , 79       , 80       , 81       , 82       , NO_LED   , 83       , 84       , 85        },
    { 89       , 90       , 91       , NO_LED   , NO_LED   , 92       , NO_LED   , NO_LED   , NO_LED   , 93       , 94       , 95       , 96       , 97       , 98       , 99        },
    { 34       , 35       , 36       , 37       , 52       , 53       , 54       , 69       , 70       , 71       , 55       , 86       , 87       , 100      , 101      , 88       }
}, {
    { 0, 10},  { 20, 10},  { 30, 10}, { 40, 10}, { 50, 10}, { 65, 10},  { 75, 10},  { 85, 10},  { 95, 10},  { 110, 10}, { 120, 10}, { 130, 10}, { 140, 10},             { 155, 10}, { 165, 10}, { 175, 10},  { 190, 10}, { 200, 10}, { 210, 10}, { 220, 10},
    { 0, 20},  { 10, 20},  { 20, 20}, { 30, 20}, { 40, 20}, { 50, 20},  { 60, 20},  { 70, 20},  { 80, 20},  { 90, 20},  { 100, 20}, { 110, 20}, { 120, 20}, { 135, 20},                                      { 190, 20}, { 200, 20}, { 210, 20}, { 220, 20},
    { 2, 30},  { 13, 30},  { 23, 30}, { 33, 30}, { 43, 30}, { 53, 30},  { 63, 30},  { 73, 30},  { 83, 30},  { 93, 30},  { 103, 30}, { 113, 30}, { 125, 30}, { 137, 30},                                      { 190, 30}, { 200, 30}, { 210, 30}, { 220, 30},
    { 4, 40},  { 15, 40},  { 25, 40}, { 35, 40}, { 45, 40}, { 55, 40},  { 65, 40},  { 75, 40},  { 85, 40},  { 95 , 40}, { 105, 40}, { 115, 40}, { 123, 40},                                                  { 190, 40}, { 200, 40}, { 210, 40},
    { 6, 50},              { 20, 50}, { 30, 50}, { 40, 50}, { 50, 50},  { 60, 50},  { 70, 50},  { 80, 50},  { 90,  50}, { 100, 50}, { 110, 50}, { 120, 50},                         { 165, 50},              { 190, 50}, { 200, 50}, { 210, 50}, { 220, 50},
    { 0, 60},  { 15, 60},  { 25, 60},                                   { 64, 60},                          { 100, 60}, { 115, 60}, { 130, 60}, { 140, 60},             { 155, 60}, { 165, 60},  { 175, 60}, { 195, 60}, { 210, 60},

    { 255, 64}, { 255, 64}, { 255, 64},  { 255, 64}, { 255, 64}, { 255, 64}, { 255, 64}, { 255, 64},  { 255, 64}, { 255, 64}, { 255, 64}, { 255, 64},
    { 255, 64}, { 255, 64}, { 255, 64},  { 255, 64}, { 255, 64}, { 255, 64}, { 255, 64}, { 255, 64},  { 255, 64}, { 255, 64}, { 255, 64}, { 255, 64},

    { 255, 64}, { 255, 64}, { 255, 64},  { 255, 64},

    { 255, 64}, { 255, 64}, { 255, 64},  { 255, 64}, { 255, 64},
    { 255, 64}, { 255, 64}, { 255, 64},  { 255, 64}, { 255, 64}
}, {
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,      1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,              1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,              1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,                  1,  1,  1,
    1,      1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,          1,      1,  1,  1,  1,
    1,  1,  1,              1,          1,  1,  1,  1,      1,  1,  1,  1,  1,

    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,

    0,  0,  0,  0,

    0,  0,  0,  0,  0,
    0,  0,  0,  0,  0
} };

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    User_Led_Show();
    return false;
}

void notify_usb_device_state_change_user(enum usb_device_state usb_device_state)  {
    if (Keyboard_Info.Key_Mode == QMK_USB_MODE) {
        if(usb_device_state == USB_DEVICE_STATE_CONFIGURED) {
            Usb_If_Ok_Led = true;
        } else {
            Usb_If_Ok_Led = false;
        }
    } else {
        Usb_If_Ok_Led = false;
    }
}

void housekeeping_task_user(void) {
#ifdef MACRO_ASYNC_PLAY_ENABLE
    if (Macro_Play_Falg == true) {
        Macro_Play_Falg = false;
        user_macro_task(); /* 内部用 timer 控制间隔，不依赖 housekeeping 频率 */
    }
#endif
    User_Keyboard_Reset();
    es_chibios_user_idle_loop_hook();
}

void board_init(void) {
    User_Keyboard_Init();
}

void keyboard_post_init_user(void) {
    User_Keyboard_Post_Init();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {   /*键盘只要有按键按下就会调用此函数*/
    Usb_Change_Mode_Delay = 0;                                      /*只要有按键就不会进入休眠*/
    Usb_Change_Mode_Wakeup = false;

    if (Test_Led) {
        if ((keycode != KC_SPC) && (keycode != MO(2)) && (keycode != MO(3)) && (keycode != KC_LCTL)) {
            Test_Led = false;
        }
    }

    switch (keycode) {
        default:    return Key_Value_Dispose(keycode, record); // Process all other keycodes normally
    }
}
