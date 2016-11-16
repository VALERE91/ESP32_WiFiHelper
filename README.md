WiFi Helper
============

This is a simple class with some methods to help manage WiFi on ESP with ESP_IDF.

To test you can run : `make menuconfig` and `make flash` (with a proper ESP_IDF installation).

THIS IS A PROOF OF CONCEPT!!!! Never hesitate to report bugs on issues.

Usage
-----

To create the WIFIHelper : 
`WIFIHelper WIFI;`

First of all you must initialize the WIFIHelper :
`WIFI.Init()`

Then you can configure AP and station : 
```
WIFI.ConfigureAP("AP_SSID","password",WIFI_AUTH_WPA_WPA2_PSK);
WIFI.ConfigureSTA("STA_SSID","password",true);
```
Finally, you can start and connect :
```
WIFI.Start();
WIFI.Connect();
```

You can configure your WIFI by passing some paramters :
- At init :
`esp_err_t WIFIHelper::Init(wifi_mode_t mode = WIFI_MODE_APSTA)`

- At ConfigureSTA :
```esp_err_t WIFIHelper::ConfigureSTA(const char* ssid, 
                        const char* password = NULL, 
                        bool hidden = false);```

- At ConfigureAP :
```esp_err_t WIFIHelper::ConfigureAP(const char* ssid, 
                        const char* password = NULL, 
                        wifi_auth_mode_t auth = WIFI_AUTH_OPEN,
                        bool hidden = false, 
                        int channel = 11);```

TODO
----

This project is only a proof of concept and will be extend.

- A WiFI scanner
- A better error treatment
- You can ask for more feature in the issues

LICENSE
-------

Copyright 2016 VALERE91

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.