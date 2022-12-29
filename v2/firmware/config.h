#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x0002
#define DEVICE_VER 0x0001
#define PRODUCT Khada

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

#define MATRIX_ROW_PINS { A3, A4, A5, A6 }
#define MATRIX_COL_PINS { A15, B3, B4, B5, B6, B7 }
#define MATRIX_ROW_PINS_RIGHT  { A3, A4, A5, A6 }
#define MATRIX_COL_PINS_RIGHT { B7, B6, B5, B4, B3, A15 }

#define DIODE_DIRECTION COL2ROW

#define USE_SERIAL
#define SOFT_SERIAL_PIN A2
#define SELECT_SOFT_SERIAL_SPEED 1
#define SERIAL_USART_DRIVER SD2

#define MATRIX_IO_DELAY 5
#define TAP_CODE_DELAY 10

#define ENCODERS_PAD_A { B9 }
#define ENCODERS_PAD_B { B8 }
#define ENCODERS_PAD_A_RIGHT { B8 }
#define ENCODERS_PAD_B_RIGHT { B9 }

#define WS2812_PWM_DRIVER PWMD3
#define WS2812_PWM_CHANNEL 4
#define WS2812_PWM_PAL_MODE 2
#define WS2812_DMA_STREAM STM32_DMA1_STREAM2
#define WS2812_DMA_CHANNEL 5

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#define BOOTMAGIC_LITE_ROW	0
#define BOOTMAGIC_LITE_COLUMN	0

#define BOOTMAGIC_LITE_ROW_RIGHT	4
#define BOOTMAGIC_LITE_COLUMN_RIGHT	5
