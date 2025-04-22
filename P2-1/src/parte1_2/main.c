#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_timer.h"
#include "esp_log.h"
static const char *TAG = "P2_1_2";


// Callback function for the timer that occurs every second
void timer_callback_1(void *arg)
{
    int* timer1_ticks = (int*)arg;
    (*timer1_ticks)++;
    char _str[50];
    sprintf(_str, "Timer 1 Tick nº %i. \n" ,*timer1_ticks);
    ESP_DRAM_LOGI(TAG,"%s", _str); // ESP_DRAM_LOGI(TAG,"%s", str);
}
// Callback function for the timer that occurs every 5 seconds
void timer_callback_2(void *arg)
{

    int* timer2_ticks = (int*)arg;
    (*timer2_ticks)++;
    char _str[50];
    sprintf(_str, "Timer 2 Tick nº %i . \n" ,*timer2_ticks);
    ESP_DRAM_LOGI(TAG,"%s", _str); // ESP_DRAM_LOGI(TAG,"%s", str);
}

void app_main(void)
{
    int timer1_ticks = 0;
    int timer2_ticks = 0;

    // Timer 1: estructuras manejador y configurador
    esp_timer_handle_t timer1;
    esp_timer_create_args_t timer_args1 =
        {
            .callback = &timer_callback_1, // callback de interrupción
            .name = "timer_1",
            .arg = &timer1_ticks
        };
    // creación del timer 1, se pasa manejador y configurador. Al terminar este método, el manejador ya no es NULL
    esp_timer_create(&timer_args1, &timer1);
    // Uso del timer 1: interrupción periódica cada segundo (los timers están implementados en microsegundos)
    esp_timer_start_periodic(timer1, 1000000); // 1 second in microseconds

    // Timer 2 configurado de forma análoga
    esp_timer_handle_t timer2;
    esp_timer_create_args_t timer_args2 =
        {
            .callback = &timer_callback_2,
            .name = "timer_2",
            .arg = &timer2_ticks
        };
    esp_timer_create(&timer_args2, &timer2);
    esp_timer_start_periodic(timer2, 5000000); // 5 segundos
    // Un bucle, para que la ejecución no se detenga
    while (1)
    {
        while (1);
    }
    // Lo que habría que hacer al finalizar con los timers de forma controlada.

    // No es necesario aquí porque la ejecución no llegará nunca a estas líneas
    // esp_timer_delete(timer1);
    // esp_timer_delete(timer2);
}