#include "WIFIHelper.h"

esp_err_t WIFIHelper::Init(wifi_mode_t mode){
    _started = false;
    esp_err_t err = ESP_OK;
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    err = esp_wifi_init(&cfg);
    err = esp_wifi_set_storage(WIFI_STORAGE_RAM);
    err = esp_wifi_set_mode(mode);
    return err;
}

esp_err_t WIFIHelper::ConfigureSTA(const char* ssid, const char* password, bool hidden){
    esp_err_t err = ESP_OK;

    wifi_config_t* wifi_config = (wifi_config_t*)malloc(sizeof(wifi_config_t));
    err = esp_wifi_get_config(WIFI_IF_AP,wifi_config);
    strcpy(wifi_config->sta.ssid,ssid);
    if(password != NULL){
        strcpy(wifi_config->sta.password,password);
    }

    wifi_config->sta.bssid_set = !hidden;

    err = esp_wifi_set_config(WIFI_IF_STA, wifi_config);
    free(wifi_config);

    return err;
}

esp_err_t WIFIHelper::ConfigureAP(const char* ssid, 
                                            const char* password, 
                                            wifi_auth_mode_t auth,
                                            bool hidden, 
                                            int channel){
    esp_err_t err = ESP_OK;
    wifi_config_t* wifi_config = (wifi_config_t*)malloc(sizeof(wifi_config_t));
    err = esp_wifi_get_config(WIFI_IF_AP,wifi_config);
    
    strcpy(wifi_config->ap.ssid,ssid);
    if(password != NULL){
        strcpy(wifi_config->ap.password,password);
    }

    wifi_config->ap.ssid_len = strlen(wifi_config->ap.ssid);
    wifi_config->ap.channel = channel;
    wifi_config->ap.authmode = auth;
    wifi_config->ap.ssid_hidden =hidden;
    wifi_config->ap.max_connection = 4;
    wifi_config->ap.beacon_interval = 100;
    
    err = esp_wifi_set_config(WIFI_IF_AP,wifi_config);
    free(wifi_config);
    return err;
}

esp_err_t WIFIHelper::Start(){
    esp_err_t err = ESP_OK;
    if(!_started){
        esp_err_t err = esp_wifi_start();
    }    
    if(err == ESP_OK){
        _started = true;
    }
    return err;
}

esp_err_t WIFIHelper::Connect(){
    return esp_wifi_connect();
}