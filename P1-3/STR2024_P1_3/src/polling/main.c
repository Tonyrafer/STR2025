#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
const char *TAG = "P1_3";

#define LED_GPIO GPIO_NUM_2  // LED integrado en GPIO 2

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

    // Configuración del LED (GPIO como salida)
    gpio_config_t led_conf = {
        .intr_type = GPIO_INTR_DISABLE,
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = (1ULL << LED_GPIO),
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .pull_up_en = GPIO_PULLUP_DISABLE
    };
    ESP_ERROR_CHECK(gpio_config(&led_conf));

    uint8_t gpio_value;
    uint8_t gpio_value_prev = 1; 

    while (1)
    {
        gpio_value = gpio_get_level(CONFIG_GPIO_PIN);
        
        if (gpio_value == 0 && gpio_value_prev == 1)
        {
            ESP_LOGI(TAG, "Botón pulsado!");
        }

        gpio_set_level(LED_GPIO, gpio_value);

        gpio_value_prev = gpio_value;
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}