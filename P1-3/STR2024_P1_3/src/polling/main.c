#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
const char *TAG = "P1_3";
void app_main(void)
{
    gpio_config_t io_conf =
        {
            .intr_type = GPIO_INTR_DISABLE,
            .mode = GPIO_MODE_INPUT,
            .pin_bit_mask = (1ULL << CONFIG_GPIO_PIN),
            .pull_down_en = GPIO_PULLDOWN_DISABLE,
            .pull_up_en = GPIO_PULLUP_ENABLE};

    gpio_config(&io_conf);
    uint8_t gpio_value;
    
    while (1)
    {
        gpio_value = gpio_get_level(CONFIG_GPIO_PIN);
        if (gpio_value == 0)
        {
            ESP_LOGI(TAG, "Botón pulsado!");
        }
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}