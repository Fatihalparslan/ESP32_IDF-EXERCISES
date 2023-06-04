
idf_component_register(SRCS "WiFiManager.c" "MqttManager.c"
                       INCLUDE_DIRS  "include"
                       REQUIRES esp_wifi nvs_flash mqtt)