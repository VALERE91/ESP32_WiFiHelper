#ifdef __cplusplus
extern "C"{
#endif

#include "string.h"
#include "freertos/FreeRTOS.h"
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "nvs_flash.h"
#include "driver/gpio.h"

esp_err_t event_handler(void *ctx, system_event_t *event);
int app_main(void);

#ifdef __cplusplus
}
#endif

#include "WIFIHelper.h"

WIFIHelper WIFI;

esp_err_t event_handler(void *ctx, system_event_t *event)
{
    return ESP_OK;
}

int app_main(void)
{
    nvs_flash_init();
    tcpip_adapter_init();
    ESP_ERROR_CHECK( esp_event_loop_init(event_handler, NULL) );

    WIFI.Init();
    WIFI.ConfigureAP("SSID","PASSWORD",WIFI_AUTH_WPA_WPA2_PSK);
    WIFI.ConfigureSTA("SSID","PASSWORD",true);
    WIFI.Start();
    WIFI.Connect();


    gpio_set_direction(GPIO_NUM_5, GPIO_MODE_OUTPUT);
    int level = 0;
    while (true) {
        gpio_set_level(GPIO_NUM_5, level);
        level = !level;
        vTaskDelay(300 / portTICK_PERIOD_MS);
    }

    return 0;
}

