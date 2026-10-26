/*用户自己的一些宏定义数据*/
#pragma once

#include "debounce.h"
#include "quantum.h"
#include "usb_descriptor.h"
#include "usb_main.h"
#include "raw_hid.h"
#include "action_util.h"

#define USER_EMI_COMMAND	    0XBB
#define USER_KEYBOARD_COMMAND	0X0A
#define USER_KEYBOARD_LENGTH    (64)

#define USER_SWITCH_2P4G_MODE	0X00
#define USER_SWITCH_BLE_1_MODE	0X01
#define USER_SWITCH_BLE_2_MODE	0X02
#define USER_SWITCH_BLE_3_MODE	0X03
#define USER_SWITCH_2P4G_PAIR	0X04
#define USER_SWITCH_BLE_1_PAIR	0X05
#define USER_SWITCH_BLE_2_PAIR	0X06
#define USER_SWITCH_BLE_3_PAIR	0X07
#define USER_SWITCH_USB_MODE	0X08

#define USER_KEYBOARD_SLEEP		0X09
#define USER_KEYBOARD_WAKEUP	0X0A

#define USER_KEY_BYTE_DATA		0X0B
#define USER_KEY_BIT_DATA		0X0C
#define USER_MOUSE_DATA			0X0D
#define USER_CONSUMER_DATA		0X0E
#define USER_SYSTEM_DATA		0X0F

#define USER_BATTERY_DATA		0X10

#define USER_GET_RF_STATUS	    0X11

#define USER_BLE1_WRITE_NAME	0X12
#define USER_BLE2_WRITE_NAME    0X13
#define USER_BLE3_WRITE_NAME    0X14

#define USER_SLEEP_TIME_WRITE   0X15       // 一级休眠时间
#define USER_DSLEEP_TIME_WRITE  0X16       // 二级休眠时间
#define USER_CLEAR_WL_ID        0X17

#define USER_KEY_BYTE_LENGTH	0X08
#define USER_KEY_BIT_LENGTH		0X0F
#define USER_MOUSE_LENGTH		0X08
#define USER_CONSUMER_LENGTH	0X03
#define USER_SYSTEM_LENGTH		0X03
#define USER_BATTERY_LENGTH		0X02

#define KB_REPORT_ID            0x06    // Extend keyboard report ID.
#define SYS_REPORT_ID     	    0x03    // Extend System   report ID.
#define CON_REPORT_ID     	    0x04    // Extend Consumer report ID.
#define MOUSE_REPORT_ID  	    0x02    // Extend mouse	   report ID.

#define KEY_LED_NUM                     (102) // 按键led数量
#define LOGO_LED_ENABLE         (1)
#define SIDE_LED_ENABLE         (1)
/***************************全局变量***************************/
bool Usb_If_Ok_Led;
bool Usb_If_Ok;
uint16_t Usb_If_Ok_Delay;

uint16_t Usb_Change_Mode_Delay;
bool Usb_Change_Mode_Wakeup;
bool Mode_Synchronization_Signal;

unsigned int Debounce_Delay;

extern uint8_t Led_Point_Count;
extern uint8_t Systick_Led_Count;
extern bool Test_Led;
#ifdef MACRO_ASYNC_PLAY_ENABLE
extern bool Macro_Play_Falg;
#endif

bool User_Led_Show(void);
void User_Keyboard_Reset(void);
void User_Keyboard_Init(void);
void User_Keyboard_Post_Init(void);
void es_chibios_user_idle_loop_hook(void);
bool Key_Value_Dispose(uint16_t keycode, keyrecord_t *record);

void add_key_to_report(uint8_t key);
void General_Key_Reorder(uint8_t Spot_Index);
void del_key_from_report(uint8_t key);
void User_send_6kro_report(void);
void User_send_nkro_report(void);
void User_Clear_Board(void);
void User_Send_Key(uint8_t Code, bool Status);

void Save_Flash_Set(void);
void Uart_While_Send_Commad(uint8_t Command, uint8_t Busy);
void Uart_Key_Mode_Key_Scan(uint16_t Code, bool Press);
/**************************************************************/


#define LCD_GO_HOME_TIME        (500)   //unit 10ms

#define USER_DEFINE_KEY         (QK_KB)
enum Custom_Keycodes {
    QMK_KB_MODE_2P4G = USER_DEFINE_KEY,
    QMK_KB_MODE_BLE1,
    QMK_KB_MODE_BLE2,
    QMK_KB_MODE_BLE3,
    QMK_KB_MODE_USB,
    QMK_BATT_NUM,
    QMK_WIN_LOCK,
    QMK_KB_SIX_N_CH,
    QMK_TEST_COLOUR,
	IOS_SIRI,
    RGB_RTOG,
    U_EE_CLR,
    QMK_DEBOUNCE,
    QMK_TIME_SET,
    QMK_DTIME_SET,
    HOME_MODE,
    KEY_MODE,
    GIF_MODE,
    LOOP_RMODE,
    LOOP_LMODE,
    GIF_CHAGE,
    LVGL_SHUTDOWN,
    LVGL_BOOT,
    LVGL_RESET_BOOT,
    LVGL_OPEN,
#if LOGO_LED_ENABLE
    LOGO_TOG,
    LOGO_MOD,
    LOGO_RMOD,
    LOGO_HUI,
    LOGO_HUD,
    LOGO_SAI,
    LOGO_SAD,
    LOGO_VAI,
    LOGO_VAD,
    LOGO_SPI,
    LOGO_SPD,
#endif
#if SIDE_LED_ENABLE
    SIDE_TOG,
    SIDE_MOD,
    SIDE_RMOD,
    SIDE_HUI,
    SIDE_HUD,
    SIDE_SAI,
    SIDE_SAD,
    SIDE_VAI,
    SIDE_VAD,
    SIDE_SPI,
    SIDE_SPD,
#endif
    QMK_KB_2P4G_PAIR,
    QMK_KB_BLE1_PAIR,
    QMK_KB_BLE2_PAIR,
    QMK_KB_BLE3_PAIR,
    WHEEL_LEFT_SET,      //屏幕逻辑操作左移
    WHEEL_RIGHT_SET,     //屏幕逻辑操作右移
    WHEEL_DOWN_SET,      //屏幕逻辑操作确认
    LVGL_NEXT,
    LVGL_PREV,
    LVGL_ENT,
    LOOP_MODE
};

enum Custom_KeyModes {
    QMK_BLE_MODE = 0,
    QMK_2P4G_MODE,
    QMK_USB_MODE
};

enum Custom_BleChannels {
    QMK_BLE_CHANNEL_1 = 1,
    QMK_BLE_CHANNEL_2,
    QMK_BLE_CHANNEL_3
};

enum Custom_Spi_Ack_S {
    SPI_NACK,
    SPI_ACK
};

enum Custom_Spi_Busy_S {
    SPI_BUSY,
    SPI_IDLE
};

enum Custom_Ble_24G_Status_S {
    BLE_24G_NONE,
    BLE_24G_PIAR,
    BLE_24G_RETURN
};

typedef struct {
    uint8_t Key_Mode;               // 键盘工作模式
    uint8_t Ble_Channel;            // 蓝牙通道
    uint8_t Batt_Number;            // 电池电量
    uint8_t Nkro;                   // 六键全键无冲
    uint8_t Mac_Win_Mode;           // MAC系统WIN系统
    uint8_t Win_Lock;               // 锁WIN
    uint8_t Led_On_Off;             // 背光开关
    uint8_t Debounce_Delay;         // 按键消抖
    uint32_t User_Sleep_Time;       // 一级休眠
    uint32_t User_DSleep_Time;      // 二级休眠

    uint8_t Gif_Count_Init;         // 屏幕GIF动画同步
    uint8_t User_Info_Lcd_Mode;     // 屏幕工作模式
    uint8_t User_Info_Lcd_Power;    // 默认打开屏幕
    uint8_t User_Info_Lcd_Language; // 默认语言
    uint8_t User_Info_Lcd_Gif;      // 默认GIF图片
    uint8_t User_Info_Lcd_Usb;      // USB枚举
    uint8_t User_Info_Backlight;    // 背光亮度
    uint8_t User_Info_Led_Color;    // 背光颜色
    uint8_t User_Info_Side_Color;   // 侧灯颜色
    uint8_t User_Info_Date_Mode;    // 日期格式
    uint8_t User_Info_Time_Mode;    // 时间格式
#if LOGO_LED_ENABLE
    uint8_t Logo_On_Off;            // LOGO灯光开关
    uint8_t Logo_Mode;              // LOGO灯光模式
    uint8_t Logo_Colour;            // LOGO灯光颜色
    uint8_t Logo_Saturation;        // LOGO灯光饱和度
    uint8_t Logo_Brightness;        // LOGO灯光亮度
    uint8_t Logo_Speed;             // LOGO灯光速度
#endif
#if SIDE_LED_ENABLE
    uint8_t Side_On_Off;            // 测灯灯光开关
    uint8_t Side_Mode;              // 测灯灯光模式
    uint8_t Side_Colour;            // 测灯灯光颜色
    uint8_t Side_Colour_Lcd;            // 测灯灯光颜色
    uint8_t Side_Saturation;        // 测灯灯光饱和度
    uint8_t Side_Brightness;        // 测灯灯光亮度
    uint8_t Side_Speed;             // 测灯灯光速度
#endif
} Keyboard_Info_t;

extern Keyboard_Info_t Keyboard_Info;

typedef struct {
    uint8_t System_Work_Status;     // 系统状态
    uint8_t System_Work_Mode;       // 工作模式
    uint8_t System_Work_Channel;    // 工作通道
    uint8_t System_Connect_Status;  // 连接状态
    uint8_t System_Led_Status;      // 系统指示灯
    uint8_t System_Sleep_Mode;      // 系统休眠
} Keyboard_Status_t;

typedef enum {
    KB_MODE_CONNECT_OK,  	        //连接成功
    KB_MODE_CONNECT_PAIR,	        //配对
    KB_MODE_CONNECT_RETURN,	        //回连
} keyboard_System_state_e;

typedef enum {
    USER_SLEEP_PASS,	            //休眠成功
    USER_SLEEP_FIAL,	            //休眠失败
} keyboard_System_Sleep_Status_s;

typedef enum {
    Func_Mode_Led_Mode = 0,
    Func_Mode_Led_Colour,
    Func_Mode_Led_Light,
    Func_Mode_Led_Speed,
    Func_Mode_Led_Saturation,
    Func_Mode_Side_Mode,
    Func_Mode_Side_Colour,
    Func_Mode_Volume,
    Func_Mode_Language,
    Func_Mode_Date,
	Func_Mode_Time,
    Func_Mode_System,
    Func_Mode_Gif_1,
    Func_Mode_Gif_2,
} Func_Layer_E;

enum Enter_Layer_Color_E {
    Color_RGB = 0,
    Color_Red,
    Color_Orange,
    Color_Yellow,
    Color_Green,
    Color_Cyan,
    Color_Blue,
    Color_Purple,
    Color_White,
};

typedef struct {
    uint8_t  Home_Mov_Layer;         //当前逻辑层
    uint8_t  Home_Mov_Layer1_Switch; //逻辑层1选择界面
    uint8_t  Home_Mov_Layer2_Switch; //逻辑层2选择界面
    uint8_t  Home_Mov_Layer3_Switch; //逻辑层3选择界面
    uint8_t  Home_Mov_Gif_Flg;       //逻辑层Gif显示
    uint8_t  Home_Mov_Flag;          //逻辑层界面开始显示
    uint16_t Home_Mov_3S_Count;      //逻辑层界面显示3S之后不动则返回主界面
} Lvgl_Home_Mov_Type;

#define INIT_WORK_MODE              (QMK_USB_MODE)                                          // 默认工作模式
#define INIT_BLE_CHANNEL            (QMK_BLE_CHANNEL_1)                                     // 默认蓝牙通道
#define INIT_BATT_NUMBER            (50)                                                    // 上电的默认电池电量

#define INIT_SIX_KEY                (0)                                                     // 六键
#define INIT_ALL_KEY                (1)                                                     // 全键
#define INIT_ALL_SIX_KEY            (INIT_ALL_KEY)                                          // 全键

#define INIT_WIN_MODE               (0)                                                     // Windows
#define INIT_MAC_MODE               (1)                                                     // Mac
#define INIT_WIN_MAC_MODE           (INIT_WIN_MODE)                                         // Windows

#define INIT_WIN_NLOCK              (0)                                                     // 不锁WIN
#define INIT_WIN_LOCK               (1)                                                     // 锁WIN
#define INIT_WIN_LOCK_NLOCK         (INIT_WIN_NLOCK)                                        // 不锁WIN

#define INIT_OFF_CHANGE             (0)                                                     // 不转换
#define INIT_ON_CHANGE              (1)                                                     // 转换
#define INIT_ON_OFF_CHANGE          (INIT_OFF_CHANGE)                                       // 不转换

#define INIT_LED_ON                 (0)                                                     // 开背光
#define INIT_LED_OFF                (1)                                                     // 不开背光
#define INIT_LED_ON_OFF             (INIT_LED_ON)                                           // 开背光

#define SLEEP_TIME_ONE              (60)                                                    // 休眠时间1分钟
#define SLEEP_TIME_TWO              (300)                                                   // 休眠时间5分钟
#define SLEEP_TIME_THREE            (600)                                                   // 休眠时间10分钟
#define SLEEP_TIME_FOUR             (1800)                                                  // 休眠时间30分钟
#define SLEEP_TIME_CLASS            (SLEEP_TIME_TWO)                                        // 默认休眠10分钟

#define DEBOUNCE_DELAY_ONE          (2)                                                     // 消抖等级1
#define DEBOUNCE_DELAY_TWO          (5)                                                     // 消抖等级2
#define DEBOUNCE_DELAY_CLASS        (DEBOUNCE_DELAY_TWO)

#define U_PWM                       (RGB_MATRIX_MAXIMUM_BRIGHTNESS)                         // 亮度

#define     BL_END_MODE             (46)            // 最后一个模式
#define     BL_MAX_COLOUR           (254)


#if LOGO_LED_ENABLE
#define LOGO_LED_PLAY_SPEED	        (0)                                                     // 灯光刷新速度
#define LOGO_LED_GROUP	            (4)                                                     // 灯光数量
#define LOGO_LED_SIZE	            (1)                                                     // 灯光数量

#define LOGO_LED_ON                 (0)                                                     // 灯光打开
#define LOGO_LED_OFF                (1)                                                     // 灯光关闭

#define LOGO_WAVE_RGB_MODE          (1)                                                     // 彩色波浪
#define LOGO_WAVE_DS_MODE           (2)                                                     // 单色波浪
#define LOGO_SPECTRUM_MODE          (3)                                                     // 光谱
#define LOGO_BREATH_MODE            (4)                                                     // 单色呼吸
#define LOGO_LIGHT_MODE             (5)                                                     // 单色常量
#define LOGO_OFF_MODE               (6)                                                     // 关闭

#define LOGO_MAX_COLOUR             (255)                                                   // 颜色最大
#define LOGO_MIN_COLOUR             (0)                                                     // 颜色最小
#define COLOUR_LEVEL                (15)                                                    // 颜色等级

#define LOGO_MAX_SATURATION         (0)                                                     // 饱和度最大
#define LOGO_MIN_SATURATION         (255)                                                   // 饱和度最小
#define SATURATION_LEVEL            (15)                                                    // 饱和度等级

#define LOGO_MAX_BRIGHTNESS         (80)                                                    // 亮度最大
#define LOGO_MIN_BRIGHTNESS         (0)                                                     // 亮度最小
#define BRIGHTNESS_LEVEL            (15)                                                    // 亮度等级

#define LOGO_MAX_SPEED              (4)                                                     // 速度最大
#define LOGO_MIN_SPEED              (0)                                                     // 速度最小
#define SPEED_LEVEL                 (1)                                                     // 速度等级

#define INIT_LOGO_ON_OFF            (LOGO_LED_ON)                                           // 灯光打开
#define INIT_LOGO_MODE              (LOGO_WAVE_RGB_MODE)                                    // 彩色波浪
#define INIT_LOGO_COLOUR            (LOGO_MIN_COLOUR)                                       // 颜色最小
#define INIT_LOGO_SATURATION        (LOGO_MAX_SATURATION)                                   // 饱和度最大
#define INIT_LOGO_BRIGHTNESS        (LOGO_MAX_BRIGHTNESS)                                   // 亮度最大
#define INIT_LOGO_SPEED             (2)                                                     // 速度居中

void User_Via_Qmk_Logo_Get_Value(uint8_t *data);
void User_Via_Qmk_Logo_Set_Value(uint8_t *data);
void User_Via_Qmk_Logo_Command(uint8_t *data, uint8_t length);

#endif
//--------------------------------------------------------------------------------------------------------
#if SIDE_LED_ENABLE
#define SIDE_LED_PLAY_SPEED	        (0)                                                     // 灯光刷新速度
#define SIDE_LED_SIZE	            (34)                                                    // 灯光数量

#define SIDE_LED_ON                 (0)                                                     // 灯光打开
#define SIDE_LED_OFF                (1)                                                     // 灯光关闭

#define SIDE_WAVE_RGB_MODE          (1)                                                     // 彩色波浪
#define SIDE_WAVE_DS_MODE           (2)                                                     // 单色波浪
#define SIDE_SPECTRUM_MODE          (3)                                                     // 光谱
#define SIDE_BREATH_MODE            (4)                                                     // 单色呼吸
#define SIDE_LIGHT_MODE             (5)                                                     // 单色常量
#define SIDE_OFF_MODE               (6)                                                     // 关闭

#define SIDE_MAX_COLOUR             (255)                                                   // 颜色最大
#define SIDE_MIN_COLOUR             (0)                                                     // 颜色最小
#define SIDE_COLOUR_LEVEL           (15)                                                    // 颜色等级



#define SIDE_MAX_SATURATION         (0)                                                     // 饱和度最大
#define SIDE_MIN_SATURATION         (255)                                                   // 饱和度最小
#define SIDE_SATURATION_LEVEL       (15)                                                    // 饱和度等级

#define SIDE_MAX_BRIGHTNESS         (RGB_MATRIX_MAXIMUM_BRIGHTNESS)                         // 亮度最大
#define SIDE_MIN_BRIGHTNESS         (0)                                                     // 亮度最小
#define SIDE_BRIGHTNESS_LEVEL       (15)                                                    // 亮度等级

#define SIDE_MAX_SPEED              (4)                                                     // 速度最大
#define SIDE_MIN_SPEED              (0)                                                     // 速度最小
#define SIDE_SPEED_LEVEL            (1)                                                     // 速度等级

#define INIT_SIDE_ON_OFF            (SIDE_LED_ON)                                           // 灯光打开
#define INIT_SIDE_MODE              (SIDE_WAVE_RGB_MODE)                                    // 彩色波浪
#define INIT_SIDE_COLOUR            (SIDE_MIN_COLOUR)                                       // 颜色最小
#define INIT_SIDE_SATURATION        (SIDE_MAX_SATURATION)                                   // 饱和度最大
#define INIT_SIDE_BRIGHTNESS        (SIDE_MAX_BRIGHTNESS)                                   // 亮度最大
#define INIT_SIDE_SPEED             (2)                                                     // 速度居中

void User_Via_Qmk_Side_Get_Value(uint8_t *data);
void User_Via_Qmk_Side_Set_Value(uint8_t *data);
void User_Via_Qmk_Side_Command(uint8_t *data, uint8_t length);

#endif

// #define APP_2G4_BUF_SIZE            (USER_KEYBOARD_LENGTH)
// #define APP_2G4_BUF_CNT             (20)
#define APP_2G4_BUF_SIZE            (24)
#define APP_2G4_BUF_CNT             (40)

#define USER_BATT_POWER_SCAN_COUNT  (10)
#define USER_BATT_SCAN_COUNT        (10)

/* 单节3.7V锂电分段阈值，ADC = Vbat * 4096 / 6.6（2:1分压，3.3V参考）
 * 电压取自电芯静置OCV减约0.07V板端压降，可按实测微调 USER_BATT_ADC_OFFSET */
#define USER_BATT_ADC_OFFSET        (10)

#define USER_BATT_100_NUM           (2575)        //4.1500  100
#define USER_BATT_090_NUM           (2494)        //4.0200  90
#define USER_BATT_080_NUM           (2444)        //3.9400  80
#define USER_BATT_070_NUM           (2407)        //3.8800  70
#define USER_BATT_060_NUM           (2370)        //3.8200  60
#define USER_BATT_050_NUM           (2339)        //3.7700  50
#define USER_BATT_040_NUM           (2308)        //3.7200  40
#define USER_BATT_030_NUM           (2271)        //3.6700  30
#define USER_BATT_020_NUM           (2202)        //3.5500  20
#define USER_BATT_010_NUM           (2133)        //3.4000  10
#define USER_BATT_005_NUM           (2074)        //3.3200  5
#define USER_BATT_000_NUM           (2017)        //3.2500  0

#define USER_BATT_HIGH_POWER        (2555)      //满电 2565 * 3.3 /4096 = 2.066 4.13V     实际电路存在压降。
#define USER_BATT_LOW_POWER         (2202)      //低电 2065 * 3.3 /4096 = 1.663 3.32V     即使键盘不开灯，电池满电4.2V
#define USER_BATT_STDOWN_POWER      (1865)      //关机 1865 * 3.3 /4096 = 1.502 3.04V     输入到板子也就只有4.1V左右

#define USER_BATT_LOW_POWER_NUM     (5) //低电电量百分比

#define USER_BATT_DELAY_TIME        (100 * 25)  //25S
#define USER_TIME_3S_TIME           (300)       //3S
#define USER_TIME_2S_TIME           (200)       //2S
#define USER_KEY_SHORT_LONG         (50)        //500mS

#define SPI_DELAY_RF_TIME           (100)
#define SPI_DELAY_USB_TIME          (500 * 3)

void User_Sleep(void);
void Emi_Read_Data(uint8_t *User_Data, uint8_t User_Length);
void Emi_Write_Data(uint8_t *User_Data, uint8_t User_Length);

#define MAX_NAME_LEN                (18)
#define USER_BlE_ID                 (0X20E0)
#define USER_BlE1_NAME              "TH108 V2 PM-1"
#define USER_BlE2_NAME              "TH108 V2 PM-2"
#define USER_BlE3_NAME              "TH108 V2 PM-3"

#define USER_DSLEEP_TIME            1800 //二级休眠时间 单位 S

#define KEYBAORD_COL                (16)
#define KEYBAORD_ROL                (6)
#define MATRIX_USER_COL_PINS        { D15, D14, C15, C14, C13, D3, D2, C12, C11, C10, A14, C9, C8, C7, C6, B15 }
#define MATRIX_USER_ROW_PINS        { B0, B3, B4, B5, B6, B7 }

#define WIN_COL                     (1)
#define WIN_ROL                     (3)

#define MAC_COL                     (2)
#define MAC_ROL                     (3)

#define KC_K29 	 KC_BACKSLASH
#define KC_K42 	 KC_NONUS_HASH
#define KC_K45 	 KC_NONUS_BACKSLASH
#define KC_K56 	 KC_INTERNATIONAL_1
#define KC_K14   KC_INTERNATIONAL_3
#define KC_K132	 KC_INTERNATIONAL_4
#define KC_K131	 KC_INTERNATIONAL_5
#define KC_K133	 KC_INTERNATIONAL_2
#define KC_K151	 KC_LANGUAGE_1
#define KC_K150	 KC_LANGUAGE_2

#define MD_24G	 QMK_KB_MODE_2P4G
#define MD_BLE1	 QMK_KB_MODE_BLE1
#define MD_BLE2	 QMK_KB_MODE_BLE2
#define MD_BLE3	 QMK_KB_MODE_BLE3
#define MD_USB	 QMK_KB_MODE_USB
#define QK_BAT   QMK_BATT_NUM
#define QK_WLO	 QMK_WIN_LOCK
#define SIX_N	 QMK_KB_SIX_N_CH
#define TEST_CL	 QMK_TEST_COLOUR
#define KEY_DEB	 QMK_DEBOUNCE
#define TIME_ST	 QMK_TIME_SET
#define TIME_DT	 QMK_DTIME_SET
#define L_HOME	 HOME_MODE
#define L_KEY	 KEY_MODE
#define L_GIF	 GIF_MODE
#define L_LOOP   LOOP_MODE
#define L_RLOOP  LOOP_RMODE
#define L_LLOOP  LOOP_LMODE
#define L_GIFCH	 GIF_CHAGE
#define L_SHUT   LVGL_SHUTDOWN
#define L_BOOT   LVGL_BOOT
#define L_RE_BO  LVGL_RESET_BOOT
#define L_NEXT	 LVGL_NEXT
#define L_PREV	 LVGL_PREV
#define L_ENT	 LVGL_ENT
#define L_OPEN	 LVGL_OPEN

#define WH_LFT   WHEEL_LEFT_SET
#define WH_RGT   WHEEL_RIGHT_SET
#define WH_KEY   WHEEL_DOWN_SET

#define UART_BUF_SIZE       8
#define UART_PACK_SIZE      4
#define UART_POWER_DELAY    20

#define USER_UART_COMMAND1  0x11
#define USER_UART_COMMAND2  0x22
#define USER_UART_COMMAND3  0x33
#define USER_UART_COMMAND4  0x44

#define UART_NUM_LOCK       0X001
#define UART_CAP_LOCK       0X002
#define UART_SCR_LOCK       0X004
#define UART_WIN_LOCK       0X008
#define UART_MAC_WIN        0X010

#define UART_BLE1_MODE          0X01
#define UART_BLE2_MODE          0X02
#define UART_BLE3_MODE          0X04
#define UART_2P4G_MODE          0X08
#define UART_USB_MODE           0X10


enum Custom_Uart_Busy_S {
    UART_IDLE,
    UART_BUSY
};

enum Custom_Uart_Modes {
    Uart_Home = 0,
    Uart_Key,
    Uart_Gif,
    Uart_Test
};

enum Language_Mode {
	English = 0,
	Chinese,
};

enum Time_Mode {
	Time_12h = 0,
	Time_24h,
};

enum Date_Mode {
	Date_DMY = 0,
	Date_MDY,
    Date_YMD,
};

enum Home_Mov_Layer_E {
    Home_Layer = 0,
    Func_Layer,
    Enter_Layer,
    Lcd_Action_OK
};

enum Home_Layer_E {
    Home_Default = 0,
    Home_Vold,
    Home_Volu
};

enum Func_Layer_E {
    Func_Mode_Change = 0,
    Func_Mode_MW
};

enum Enter_Layer_Mode_Change_E {
    Enter_Mode_Usb = 0,
    Enter_Mode_2P4G,
    Enter_Mode_Ble1,
    Enter_Mode_Ble2,
    Enter_Mode_Ble3,
    Enter_Mode_Win,
    Enter_Mode_Mac
};

enum Custom_Gif_Mode {
    GIF_MODE_1 = 0,
	GIF_MODE_2,
	GIF_MODE_3
};

enum Custom_Uart_Command {
    Command_Get_Error = 0X55,
    Command_Get_Status = 0XAA,
    Command_Ready_Ok = 0XBB,
    Command_Work_Mode_Data = 0XC0,
    Command_Led_Data = 0XC1,
    Command_Batt_Data = 0XC2,
    Command_Mode_Data = 0XC3,
    Command_Key_Mode_Data = 0XC4,
    Command_Home_Mov_Data = 0XC5,
    Command_Gif_Change_Data = 0XC6,
    Command_Test_Colour = 0XC7,
    Command_Usb_Data = 0XC8,
    Command_Light_Data = 0XC9,
    Command_Language_Data = 0XCA,
    Command_Date_Data = 0XCB,
    Command_Time_Data = 0XCC,
	Command_USB_DISABLE = 0XDD,
};

/**********************************/
/**********************************/
#define INIT_LCD_MODE       (Uart_Home)    // 默认屏幕工作模式

#define LCD_POWER_ON        (0)            // 打开屏幕
#define LCD_POWER_OFF       (1)            // 关闭屏幕
#define INIT_LCD_POWER      (LCD_POWER_ON) // 默认打开屏幕

#define LCD_USB_ON          (1)            // 枚举USB
#define LCD_USB_OFF         (0)            // 关闭USB
#define INIT_USB_POWER      (LCD_USB_OFF)  // 默认关闭USB

#define INIT_LCD_LANGUAGE   (English)      // 默认语言

#define INIT_LCD_TIME       (Time_24h)      // 默认时间格式
#define INIT_LCD_DATE       (Date_YMD)      // 默认日期格式

#define GIF_PIC_MAX         3              // 最大张数

#define BACKLIGHT_MAX       5              // 最大亮度等级
#define INIT_BACKLIGHT      3              // 默认亮度等级

uint8_t Get_Lcd_Usb_Work_Status(void);
void Lcd_Usb_Work_Init(uint8_t Reset, uint8_t Set);
void Lcd_Work_Sync_GIF(uint8_t Gif_Count);
void Reset_Power_Lvgl(void);

void Init_Home_Mov(void);

#ifdef MACRO_ASYNC_PLAY_ENABLE
    void user_macro_send(uint8_t id);
    void user_macro_task(void);
#endif

