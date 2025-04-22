#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_timer.h"
#include "esp_log.h"
#include "sdkconfig.h"
#define TEMP_MATRIX_SIZE 110


static const char* TAG = "P2_1_1";


void app_main(void)
{
    // Usamos el tamaño configurado en menuconfig
    int matrix_size = TEMP_MATRIX_SIZE;
    
    // Creamos matrices dinámicas para evitar problemas con tamaños grandes
    int* matrix1 = (int*)malloc(matrix_size * matrix_size * sizeof(int));
    int* matrix2 = (int*)malloc(matrix_size * matrix_size * sizeof(int));
    int* result = (int*)malloc(matrix_size * matrix_size * sizeof(int));

    if(!matrix1 || !matrix2 || !result) {
        ESP_LOGE(TAG, "Error al asignar memoria para las matrices");
        return;
    }

    ESP_LOGI(TAG, "Multiplicando matrices de %dx%d", matrix_size, matrix_size);

    // Inicializa las matrices con valores aleatorios
    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            matrix1[i * matrix_size + j] = rand() % 10; // Valores aleatorios entre 0 y 9
            matrix2[i * matrix_size + j] = rand() % 10;
        }
    }

    // Tiempo inicial
    uint64_t start_time = esp_timer_get_time();

    // Multiplicación de las matrices
    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            result[i * matrix_size + j] = 0;
            for (int k = 0; k < matrix_size; k++) {
                result[i * matrix_size + j] += matrix1[i * matrix_size + k] * matrix2[k * matrix_size + j];
            }
        }
    }

    // Tiempo final
    uint64_t end_time = esp_timer_get_time();

    // Tiempo transcurrido en microsegundos
    double elapsed_time = (double)(end_time - start_time);

    ESP_LOGI(TAG, "Matrix multiplication completed in %.2f µs\n", elapsed_time);

    // Liberamos la memoria
    free(matrix1);
    free(matrix2);
    free(result);
}