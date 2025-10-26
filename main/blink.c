#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

static const char* TAG = "MY_BLINK";

#define BLINK_GPIO 8

void configure_led(void){
    gpio_reset_pin(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_level(BLINK_GPIO, 0);
}

void app_main(void){
    ESP_LOGI(TAG, "Starting my very own blink project");
    ESP_LOGI(TAG, "Configuring GPIO %d for LED", BLINK_GPIO);
    
    configure_led();

    ESP_LOGI(TAG, "Setup Complete, starting blink:");

    int blink_count = 0;
    while(1){
        ESP_LOGI(TAG, "Turning LED ON, blink number: %d", blink_count);
        gpio_set_level(BLINK_GPIO, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);

        ESP_LOGI(TAG, "Turning LED ON, blink number: %d", blink_count);
        gpio_set_level(BLINK_GPIO, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);

        blink_count++;
    }
}