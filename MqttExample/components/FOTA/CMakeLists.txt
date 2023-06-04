
idf_component_register(SRCS "WiFiFunction.c" "MqttFunction.c"
                       INCLUDE_DIRS  "include"
                       REQUIRES esp_wifi nvs_flash mqtt)