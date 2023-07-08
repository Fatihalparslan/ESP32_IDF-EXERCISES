# MQTT Publisher Example

This is an example code for an MQTT publisher using the ESP32 platform. It establishes a connection to an MQTT broker and publishes a message to a specified topic at regular intervals. The code also includes an MQTT event handler to handle various events such as connection, disconnection, subscription, and received data.

## Prerequisites

- ESP32 development board
- ESP-IDF framework installed
- MQTT broker accessible with the provided URI, username, and password

## Instructions

1. Ensure that the ESP-IDF framework is installed on your development environment.
2. Create a new project and include the necessary libraries and headers.
3. Copy and paste the provided code into your project.
4. Modify the MQTT broker URI, username, and password in the `mqtt_app_start` function to match your setup.
5. Build and flash the project to your ESP32 development board.
6. Monitor the output logs to check the MQTT connection status and message publishing.

## Code Explanation

- The `mqtt_event_handler` function handles various MQTT events, such as connection, disconnection, subscription, publication, and received data. It logs relevant information based on each event.
- The `mqtt_app_start` function initializes the MQTT client with the provided MQTT broker URI, username, and password. It also registers the event handler and starts the client.
- The `Publisher_Task` function is a FreeRTOS task that runs continuously. It checks if the MQTT client is connected and publishes a message to the specified topic at regular intervals.
- The `app_main` function is the entry point of the program. It initializes the NVS (Non-Volatile Storage) and starts the Wi-Fi station. It also creates the `Publisher_Task` task.

Feel free to modify the code according to your specific requirements, such as changing the MQTT broker details, topic names, or message contents.

Please note that this code assumes you have set up the necessary network configuration, such as Wi-Fi credentials, in the `WiFi_Start_Sta` function. Ensure that you have the appropriate network settings before running the code.

For more information on the ESP-IDF framework and MQTT library, refer to the respective documentation and examples provided by Espressif.

Happy coding!