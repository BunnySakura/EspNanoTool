/**
 * @file lv_port_indev_templ.c
 *
 */

/*Copy this file as "lv_port_indev.c" and set this value to "1" to enable content*/
#if 1

/*********************
 *      INCLUDES
 *********************/
#include "lv_port_indev.h"
#include "lvgl.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

// static void touchpad_init(void);
// static void touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
// static bool touchpad_is_pressed(void);
// static void touchpad_get_xy(lv_coord_t * x, lv_coord_t * y);
//
// static void mouse_init(void);
// static void mouse_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
// static bool mouse_is_pressed(void);
// static void mouse_get_xy(lv_coord_t * x, lv_coord_t * y);

static void keypad_init(void);
static void keypad_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data);
static uint32_t keypad_get_key(void);

// static void encoder_init(void);
// static void encoder_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
// static void encoder_handler(void);
//
// static void button_init(void);
// static void button_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
// static int8_t button_get_pressed_id(void);
// static bool button_is_pressed(uint8_t id);

/**********************
 *  STATIC VARIABLES
 **********************/
// lv_indev_t * indev_touchpad;
// lv_indev_t * indev_mouse;
lv_indev_t *indev_keypad;
// lv_indev_t * indev_encoder;
// lv_indev_t * indev_button;

// static int32_t encoder_diff;
// static lv_indev_state_t encoder_state;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_indev_init(void) {
  /**
   * Here you will find example implementation of input devices supported by LittelvGL:
   *  - Touchpad
   *  - Mouse (with cursor support)
   *  - Keypad (supports GUI usage only with key)
   *  - Encoder (supports GUI usage only with: left, right, push)
   *  - Button (external buttons to press points on the screen)
   *
   *  The `..._read()` function are only examples.
   *  You should shape them according to your hardware
   */

  static lv_indev_drv_t indev_drv;

  /*------------------
   * Touchpad
   * -----------------*/

  /*Initialize your touchpad if you have*/
  // touchpad_init();

  /*Register a touchpad input device*/
  // lv_indev_drv_init(&indev_drv);
  // indev_drv.type = LV_INDEV_TYPE_POINTER;
  // indev_drv.read_cb = touchpad_read;
  // indev_touchpad = lv_indev_drv_register(&indev_drv);

  /*------------------
   * Mouse
   * -----------------*/

  /*Initialize your mouse if you have*/
  // mouse_init();

  /*Register a mouse input device*/
  // lv_indev_drv_init(&indev_drv);
  // indev_drv.type = LV_INDEV_TYPE_POINTER;
  // indev_drv.read_cb = mouse_read;
  // indev_mouse = lv_indev_drv_register(&indev_drv);

  /*Set cursor. For simplicity set a HOME symbol now.*/
  // lv_obj_t * mouse_cursor = lv_img_create(lv_scr_act());
  // lv_img_set_src(mouse_cursor, LV_SYMBOL_HOME);
  // lv_indev_set_cursor(indev_mouse, mouse_cursor);

  /*------------------
   * Keypad
   * -----------------*/

  /*Initialize your keypad or keyboard if you have*/
  keypad_init();

  /*Register a keypad input device*/
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_KEYPAD;
  indev_drv.read_cb = keypad_read;
  indev_keypad = lv_indev_drv_register(&indev_drv);

  /*Later you should create group(s) with `lv_group_t * group = lv_group_create()`,
   *add objects to the group with `lv_group_add_obj(group, obj)`
   *and assign this input device to group to navigate in it:
   *`lv_indev_set_group(indev_keypad, group);`*/

  /*------------------
   * Encoder
   * -----------------*/

  /*Initialize your encoder if you have*/
  // encoder_init();

  /*Register a encoder input device*/
  // lv_indev_drv_init(&indev_drv);
  // indev_drv.type = LV_INDEV_TYPE_ENCODER;
  // indev_drv.read_cb = encoder_read;
  // indev_encoder = lv_indev_drv_register(&indev_drv);

  /*Later you should create group(s) with `lv_group_t * group = lv_group_create()`,
   *add objects to the group with `lv_group_add_obj(group, obj)`
   *and assign this input device to group to navigate in it:
   *`lv_indev_set_group(indev_encoder, group);`*/

  /*------------------
   * Button
   * -----------------*/

  /*Initialize your button if you have*/
  // button_init();

  /*Register a button input device*/
  // lv_indev_drv_init(&indev_drv);
  // indev_drv.type = LV_INDEV_TYPE_BUTTON;
  // indev_drv.read_cb = button_read;
  // indev_button = lv_indev_drv_register(&indev_drv);

  /*Assign buttons to points on the screen*/
  // static const lv_point_t btn_points[2] = {
  //     {10, 10},   /*Button 0 -> x:10; y:10*/
  //     {40, 100},  /*Button 1 -> x:40; y:100*/
  // };
  // lv_indev_set_button_points(indev_button, btn_points);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/*------------------
 * Touchpad
 * -----------------*/

/*Initialize your touchpad*/
// static void touchpad_init(void)
// {
//     /*Your code comes here*/
// }

/*Will be called by the library to read the touchpad*/
// static void touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
// {
//     static lv_coord_t last_x = 0;
//     static lv_coord_t last_y = 0;
//
//     /*Save the pressed coordinates and the state*/
//     if(touchpad_is_pressed()) {
//         touchpad_get_xy(&last_x, &last_y);
//         data->state = LV_INDEV_STATE_PR;
//     }
//     else {
//         data->state = LV_INDEV_STATE_REL;
//     }
//
//     /*Set the last pressed coordinates*/
//     data->point.x = last_x;
//     data->point.y = last_y;
// }

/*Return true is the touchpad is pressed*/
// static bool touchpad_is_pressed(void)
// {
//     /*Your code comes here*/
//
//     return false;
// }

/*Get the x and y coordinates if the touchpad is pressed*/
// static void touchpad_get_xy(lv_coord_t * x, lv_coord_t * y)
// {
//     /*Your code comes here*/
//
//     (*x) = 0;
//     (*y) = 0;
// }

/*------------------
 * Mouse
 * -----------------*/

/*Initialize your mouse*/
// static void mouse_init(void)
// {
//     /*Your code comes here*/
// }

/*Will be called by the library to read the mouse*/
// static void mouse_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
// {
//     /*Get the current x and y coordinates*/
//     mouse_get_xy(&data->point.x, &data->point.y);
//
//     /*Get whether the mouse button is pressed or released*/
//     if(mouse_is_pressed()) {
//         data->state = LV_INDEV_STATE_PR;
//     }
//     else {
//         data->state = LV_INDEV_STATE_REL;
//     }
// }

/*Return true is the mouse button is pressed*/
// static bool mouse_is_pressed(void)
// {
//     /*Your code comes here*/
//
//     return false;
// }

/*Get the x and y coordinates if the mouse is pressed*/
// static void mouse_get_xy(lv_coord_t * x, lv_coord_t * y)
// {
//     /*Your code comes here*/
//
//     (*x) = 0;
//     (*y) = 0;
// }

/*------------------
 * Keypad
 * -----------------*/
#include "common.h"

#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"
#include "sys/time.h"

// GPIO key
enum { kKeyLEFT = 39, kKeyRight = 37, kKeyCenter = 38 };
enum { kNaviMode, kEditMode } key_mode;

#define GPIO_INPUT_PIN_SEL ((1ULL << kKeyLEFT) | (1ULL << kKeyRight) | (1ULL << kKeyCenter))
#define ESP_INTR_FLAG_DEFAULT 0

/**
 * \brief GPIO中断事件
 */
typedef struct GpioEvt {
    uint32_t gpio_num;        // 引脚号
    struct timeval timestamp; // 中断时间
} GpioEvt;

static QueueHandle_t gpio_evt_queue = NULL;
static const size_t gpio_evt_queue_max_len = 8;

static void gpio_isr_handler(void *arg) {
  GpioEvt evt = {.gpio_num = (uint32_t) arg};
  gettimeofday(&evt.timestamp, NULL);
  xQueueSendFromISR(gpio_evt_queue, &evt, NULL);
}

// static esp_adc_cal_characteristics_t adc1_chars;
/*Initialize your keypad*/
static void keypad_init(void) {
  /*Your code comes here*/
  // zero-initialize the config structure.
  gpio_config_t io_conf = {};
  // interrupt of falling edge
  io_conf.intr_type = GPIO_INTR_POSEDGE;
  // bit mask of the pins, use keypad gpio here
  io_conf.pin_bit_mask = GPIO_INPUT_PIN_SEL;
  // set as input mode
  io_conf.mode = GPIO_MODE_INPUT;
  // enable pull-up mode
  io_conf.pull_up_en = 1;
  gpio_config(&io_conf);

  // change gpio interrupt type for one pin
  // gpio_set_intr_type(kKeyLEFT, GPIO_INTR_POSEDGE);
  // gpio_set_intr_type(kKeyRight, GPIO_INTR_POSEDGE);
  // gpio_set_intr_type(kKeyCenter, GPIO_INTR_POSEDGE);

  // create a queue to handle gpio event from isr
  gpio_evt_queue = xQueueCreate(gpio_evt_queue_max_len, sizeof(GpioEvt));

  // install gpio isr service
  gpio_install_isr_service(ESP_INTR_FLAG_DEFAULT);
  // hook isr handler for specific gpio pin
  gpio_isr_handler_add(kKeyLEFT, gpio_isr_handler, (void *) kKeyLEFT);
  gpio_isr_handler_add(kKeyRight, gpio_isr_handler, (void *) kKeyRight);
  gpio_isr_handler_add(kKeyCenter, gpio_isr_handler, (void *) kKeyCenter);
}

/*Will be called by the library to read the mouse*/
static void keypad_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data) {
  static uint32_t last_key = 0;

  /*Get the current x and y coordinates*/
  // mouse_get_xy(&data->point.x, &data->point.y);

  /*Get whether the key is pressed and save the pressed key*/
  uint32_t act_key = keypad_get_key();
  if (act_key != 0) {
    data->state = LV_INDEV_STATE_PR;

    /*Translate the keys to LVGL control characters according to your key definitions*/
    switch (act_key) {
      case kKeyLEFT: {
        ESP_LOGI(ESP_LOG_TAG, "Pressed key %s gpio: %lu.", "LV_KEY_LEFT", act_key);
        act_key = key_mode == kNaviMode ? LV_KEY_PREV : LV_KEY_LEFT;
        break;
      }
      case kKeyRight: {
        ESP_LOGI(ESP_LOG_TAG, "Pressed key %s gpio: %lu.", "LV_KEY_RIGHT", act_key);
        act_key = key_mode == kNaviMode ? LV_KEY_NEXT : LV_KEY_RIGHT;
        break;
      }
      case kKeyCenter: {
        ESP_LOGI(ESP_LOG_TAG, "Pressed key %s gpio: %lu.", "LV_KEY_ENTER", act_key);
        act_key = LV_KEY_ENTER;
        break;
      }
      default: {
        ESP_LOGW(ESP_LOG_TAG, "Pressed invalid key gpio: %lu.", act_key);
        break;
      }
    }

    last_key = act_key;
  } else {
    data->state = LV_INDEV_STATE_REL;
  }

  data->key = last_key;
}

/*Get the currently being pressed key.  0 if no key is pressed*/
static uint32_t keypad_get_key(void) {
  /*Your code comes here*/
  static GpioEvt last_evt = {0};
  GpioEvt evt;

  if (xQueueReceive(gpio_evt_queue, &evt, pdMS_TO_TICKS(0)) == pdFALSE) {
    return 0;
  }

  time_t last_time_us = last_evt.timestamp.tv_sec * 1000 * 1000 + last_evt.timestamp.tv_usec;
  time_t current_time_us = evt.timestamp.tv_sec * 1000 * 1000 + evt.timestamp.tv_usec;
  time_t time_interval = current_time_us - last_time_us;
  if (evt.gpio_num == last_evt.gpio_num && time_interval < 10 * 1000) {
    // 触发的按键GPIO引脚相同且时间极短，则进行消抖
    return 0;
  }

  if (evt.gpio_num == last_evt.gpio_num && evt.gpio_num == kKeyCenter && time_interval < 200 * 1000) {
    // 双击中键切换编辑和导航模式
    key_mode = key_mode == kNaviMode ? kEditMode : kNaviMode;
    ESP_LOGI(ESP_LOG_TAG, "Key mode switch to: %s", key_mode == kNaviMode ? "Navi Mode" : "Edit Mode");
    return 0; // 如果是双击，则第二次不视为按键，避免重复触发
  }

  last_evt = evt;
  return evt.gpio_num;
}

/*------------------
 * Encoder
 * -----------------*/

/*Initialize your keypad*/
// static void encoder_init(void)
// {
//     /*Your code comes here*/
// }

/*Will be called by the library to read the encoder*/
// static void encoder_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
// {
//
//     data->enc_diff = encoder_diff;
//     data->state = encoder_state;
// }

/*Call this function in an interrupt to process encoder events (turn, press)*/
// static void encoder_handler(void)
// {
//     /*Your code comes here*/
//
//     encoder_diff += 0;
//     encoder_state = LV_INDEV_STATE_REL;
// }

/*------------------
 * Button
 * -----------------*/

/*Initialize your buttons*/
// static void button_init(void)
// {
//     /*Your code comes here*/
// }

/*Will be called by the library to read the button*/
// static void button_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
// {
//
//     static uint8_t last_btn = 0;
//
//     /*Get the pressed button's ID*/
//     int8_t btn_act = button_get_pressed_id();
//
//     if(btn_act >= 0) {
//         data->state = LV_INDEV_STATE_PR;
//         last_btn = btn_act;
//     }
//     else {
//         data->state = LV_INDEV_STATE_REL;
//     }
//
//     /*Save the last pressed button's ID*/
//     data->btn_id = last_btn;
// }

/*Get ID  (0, 1, 2 ..) of the pressed button*/
// static int8_t button_get_pressed_id(void)
// {
//     uint8_t i;
//
//     /*Check to buttons see which is being pressed (assume there are 2 buttons)*/
//     for(i = 0; i < 2; i++) {
//         /*Return the pressed button's ID*/
//         if(button_is_pressed(i)) {
//             return i;
//         }
//     }
//
//     /*No button pressed*/
//     return -1;
// }

/*Test if `id` button is pressed or not*/
// static bool button_is_pressed(uint8_t id)
// {
//
//     /*Your code comes here*/
//
//     return false;
// }

#else /*Enable this file at the top*/

/*This dummy typedef exists purely to silence -Wpedantic.*/
typedef int keep_pedantic_happy;
#endif
