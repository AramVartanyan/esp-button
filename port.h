#pragma once

#include <stdint.h>

#ifdef CONFIG_IDF_TARGET_ESP32

    #include <freertos/FreeRTOS.h>
    #include <freertos/semphr.h>
    #include <freertos/timers.h>

#elif CONFIG_IDF_TARGET_ESP8266

#include <freertos/FreeRTOS.h>
#include <freertos/semphr.h>
#include <freertos/timers.h>

#else
//ESP-OPEN-RTOS
    #include <FreeRTOS.h>
    #include <semphr.h>
    #include <timers.h>

#endif

void my_gpio_enable(uint8_t gpio, bool active_high);
uint8_t my_gpio_read(uint8_t gpio);
