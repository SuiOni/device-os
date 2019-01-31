/**
  Copyright (c) 2013-2018 Particle Industries, Inc.  All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation, either
  version 3 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, see <http://www.gnu.org/licenses/>.
  ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PLATFORM_CONFIG_H
#define __PLATFORM_CONFIG_H

#define NO_STATIC_ASSERT
#include "platforms.h"
#include "logging.h"

#ifndef PLATFORM_ID
#error "PLATFORM_ID not defined"
#endif

#define UI_TIMER_FREQUENCY                  100    /* 100Hz -> 10ms */
#define BUTTON_DEBOUNCE_INTERVAL            (1000 / UI_TIMER_FREQUENCY)

// QSPI Flash
#if PLATFORM_ID == PLATFORM_ARGON || PLATFORM_ID == PLATFORM_BORON ||  PLATFORM_ID == PLATFORM_XENON
#define QSPI_FLASH_SCK_PIN                  19
#define QSPI_FLASH_CSN_PIN                  17
#define QSPI_FLASH_IO0_PIN                  20
#define QSPI_FLASH_IO1_PIN                  21
#define QSPI_FLASH_IO2_PIN                  22
#define QSPI_FLASH_IO3_PIN                  23
#define QSPI_FLASH_IRQ_PRIORITY             7

#define USE_SERIAL_FLASH
#define sFLASH_PAGESIZE                     0x1000 /* 4096 bytes sector size that needs to be erased */
#define sFLASH_PAGECOUNT                    1024   /* 4MByte storage */
#endif

#define FLASH_UPDATE_MODULES

#define SYSTICK_IRQ_PRIORITY                7       //nRF52 Systick Interrupt

#if PLATFORM_ID == PLATFORM_ARGON || PLATFORM_ID == PLATFORM_BORON || PLATFORM_ID == PLATFORM_XENON
    #define INTERNAL_FLASH_SIZE             (0x100000)
#else
    #pragma message "PLATFORM_ID is " PREPSTRING(PLATFORM_ID)
    #error "Unknown PLATFORM_ID"
#endif

//Push Buttons, use interrupt HAL
#define BUTTON1_PIN                                 20
#define BUTTON1_PIN_MODE                            INPUT_PULLUP
#define BUTTON1_INTERRUPT_MODE                      FALLING
#define BUTTON1_PRESSED                             0x00
#define BUTTON1_MIRROR_SUPPORTED                    1
#define BUTTON1_MIRROR_PRESSED                      0x00
#define BUTTON1_MIRROR_PIN                          PIN_INVALID
#define BUTTON1_MIRROR_PIN_MODE                     INPUT_PULLUP
#define BUTTON1_MIRROR_INTERRUPT_MODE               FALLING

//RGB LEDs
#define LED_MIRROR_SUPPORTED                        1
#define LEDn                                        (4 * (LED_MIRROR_SUPPORTED + 1))
#define LED_RED                                     LED2  // RED Led
#define LED_GREEN                                   LED3  // GREEN Led
#define LED_BLUE                                    LED4  // BLUE Led
#define LED_PIN_USER                                7
#define LED_PIN_RED                                 21
#define LED_PIN_GREEN                               22
#define LED_PIN_BLUE                                23

/* Exported functions ------------------------------------------------------- */

#endif /* __PLATFORM_CONFIG_H */
