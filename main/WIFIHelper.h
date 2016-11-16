#ifndef _WIFI_HELPER_H
#define _WIFI_HELPER_H

#ifdef __cplusplus
extern "C"{
#endif

#include "string.h"
#include "esp_wifi.h"
#include "esp_system.h"

#ifdef __cplusplus
}
#endif

class WIFIHelper{
public:
    esp_err_t Init(wifi_mode_t mode = WIFI_MODE_APSTA);

    esp_err_t ConfigureSTA(const char* ssid, 
                        const char* password = NULL, 
                        bool hidden = false);

    esp_err_t ConfigureAP(const char* ssid, 
                        const char* password = NULL, 
                        wifi_auth_mode_t auth = WIFI_AUTH_OPEN,
                        bool hidden = false, 
                        int channel = 11);
    esp_err_t Start();
    esp_err_t Connect();

private:
    bool _started;
};

#endif