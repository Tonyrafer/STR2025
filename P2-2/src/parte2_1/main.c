#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
static const char *TAG = "P2_2_1";
// Código de la tarea
void task_function(void *pvParameters)
{
    char buffer_grande[10000]; 
    ESP_LOGI(TAG, "task_function: inicio de la tarea");
    while (1)
    {
        ESP_LOGI(TAG, "task_function: tick");
        buffer_grande[0] = 'A'; // Usamos el buffer para evitar la optimización       
         vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void app_main()
{
    ESP_LOGI(TAG, "app_main: despliegue de la tarea.");
    // Función para crear tareas
    xTaskCreate(task_function, "Task", 2048, NULL, 1, NULL);
    // Un bucle, para que la ejecución no se detenga
    while (1)
    {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}