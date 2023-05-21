# ESP32 FREERTOS TASK CREATION EXAMPLE

This project is an example for `xTaskCreatePinnedToCore()` function under `freertos\task.h` library.
It logs tick count with 1 second delay.

## Requirements

To run this code you need VSCode editor and ESP-IDF extention for VSCode

## Hardware Setup

ESP32 DevKit V4 board is used fot this project. There is no necessary for anothor part.


## Building and Flashing

To build and flash the code to your ESP32 microcontroller, follow these steps:

1. Download repository and extract it. 
2. Open Visual Studio Code (VSCode) and go to File → Open Folder. Choose the `ESP32_IDF-EXERCISES-main\ESP32-CREATE_TASK_PIN_CORE\`  folder.
3. Modify the `.vscode\settings.json` file with the following configuration:
```
{
    "idf.adapterTargetName": "esp32",
    "idf.portWin": "COM3",
    "idf.monitorBaudRate": "115200"
}
```
## References :

[1] https://esp32tutorials.com/esp32-esp-idf-freertos-tutorial-create-tasks/