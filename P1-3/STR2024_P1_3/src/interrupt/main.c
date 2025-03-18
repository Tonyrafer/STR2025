#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "esp_err.h"

const char* TAG="P1_3";
#define LED_GPIO GPIO_NUM_2

// Manejador de interrupción (ISR)
static void IRAM_ATTR gpio_isr_handler(void* arg) {
    ESP_DRAM_LOGI(TAG, "Botón pulsado! Ejecutando interrupcion");
    gpio_set_level(LED_GPIO, !gpio_get_level(CONFIG_GPIO_PIN));  // Invertir LED
}
void app_main(void) {
    gpio_config_t io_conf = \
    {
        .intr_type = GPIO_INTR_ANYEDGE,
        .mode = GPIO_MODE_INPUT,
        .pin_bit_mask = (1ULL<<CONFIG_GPIO_PIN),
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .pull_up_en = GPIO_PULLUP_ENABLE
    };

    // Configuración del LED (GPIO como salida)
    gpio_config_t led_conf = {
        .intr_type = GPIO_INTR_DISABLE,
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = (1ULL << LED_GPIO),
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .pull_up_en = GPIO_PULLUP_DISABLE
    };
    ESP_ERROR_CHECK(gpio_config(&led_conf));

    ESP_ERROR_CHECK(gpio_config(&io_conf));
    ESP_ERROR_CHECK(gpio_install_isr_service(ESP_INTR_FLAG_SHARED));
    ESP_ERROR_CHECK(gpio_isr_handler_add(CONFIG_GPIO_PIN, gpio_isr_handler, NULL));

    while (1) {
        //gpio_set_level(LED_GPIO, 1);  // Invertir LED
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}