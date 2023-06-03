# ESP32 Basic_WiFi_STA_Example1

This is a project sample demonstrating the usage of WiFi Station Mode on an ESP32 microcontroller.

## Requirements

- ESP32 development board or a compatible microcontroller.
- VSCode editor and ESP-IDF extention for VSCode.
## Building and Flashing

To build and flash the code to your ESP32 microcontroller, follow these steps:

1. Download repository and extract it. 
2. Open Visual Studio Code (VSCode) and go to File → Open Folder. Choose the `ESP32_IDF-EXERCISES-main\WiFiSTA__1_\`  folder.
3. Modify the `.vscode\settings.json` file with the following configuration:
```
{
    "idf.adapterTargetName": "esp32",
    "idf.portWin": "COM3",
    "idf.monitorBaudRate": "115200"
}
```
## References :

[1] https://esp32tutorials.com/esp32-esp-idf-connect-wifi-station-mode-example/
