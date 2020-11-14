#include "port.h"

//ESP32 = GPIO_PIN_INTR_DISABLE; ESP8266 = GPIO_INTR_DISABLE

#ifdef CONFIG_IDF_TARGET_ESP32

#include <driver/gpio.h>

void my_gpio_enable(uint8_t gpio, bool active_high){
    gpio_config_t io_conf = {0};
    
    io_conf.pin_bit_mask = (1ULL<<gpio);
    io_conf.mode = GPIO_MODE_INPUT;
    
    if (active_high) {
        io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
        io_conf.pull_down_en = GPIO_PULLDOWN_ENABLE;
    } else {
        io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
        io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    }
    
    io_conf.intr_type = GPIO_PIN_INTR_DISABLE;
    gpio_config(&io_conf);
}

uint8_t my_gpio_read(uint8_t gpio) {
    return gpio_get_level(gpio);
}

#elif CONFIG_IDF_TARGET_ESP8266

#include <driver/gpio.h>

void my_gpio_enable(uint8_t gpio, bool active_high){
    gpio_config_t io_conf = {0};
    
    io_conf.pin_bit_mask = (1ULL<<gpio);
    io_conf.mode = GPIO_MODE_INPUT;
    
    if (active_high) {
        io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
        io_conf.pull_down_en = GPIO_PULLDOWN_ENABLE;
    } else {
        io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
        io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    }
    
    io_conf.intr_type = GPIO_INTR_DISABLE;
    gpio_config(&io_conf);
}

uint8_t my_gpio_read(uint8_t gpio) {
    return gpio_get_level(gpio);
}

#else

//ESP-OPEN-RTOS part
#include <esp/gpio.h>

void my_gpio_enable(uint8_t gpio, bool active_high) {
    
    gpio_enable(gpio, GPIO_INPUT);
    
    if (active_high) {
        gpio_set_pullup(gpio, false, false);
    } else {
        gpio_set_pullup(gpio, true, true);
    }
}

uint8_t my_gpio_read(uint8_t gpio) {
    return gpio_read(gpio);
}

#endif
