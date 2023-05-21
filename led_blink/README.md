# LED BLINK EXAMPLE

This code demonstrates a simple LED Blink example using ESP-IDF(Espressif IoT Development Framework) for ESP32 microcontrollers.
It toggles a LED for every 1 seconds.

## Requirements

To run this code you need VSCode editor and ESP-IDF extention for VSCode

## Hardware Setup

Connect an LED and a 220-ohm resistor to GPIO 26 on your ESP32 DevKit V4 board. Refer to the pinout diagram below:

![Alt text](esp32-devkitC-v4-pinout.png?raw=true "Title")

## Building and Flashing

To build and flash the code to your ESP32 microcontroller, follow these steps:

1. Download repository and extract it. 
2. Open Visual Studio Code (VSCode) and go to File → Open Folder. Choose the `ESP32_IDF-EXERCISES-main\led_blink\`  folder.
3. Modify the `.vscode\settings.json` file with the following configuration:
```
{
    "idf.adapterTargetName": "esp32",
    "idf.portWin": "COM3",
    "idf.monitorBaudRate": "115200"
}
```

