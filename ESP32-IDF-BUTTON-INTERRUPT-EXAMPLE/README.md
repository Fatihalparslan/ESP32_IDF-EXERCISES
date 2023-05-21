# ESP32 EXTERNAL INTERRUPT EXAMPLE WITH BUTTON

This is a project sample demonstrating the usage of interrupts and GPIO handling with FreeRTOS on an ESP32 microcontroller.
The project provides an example of how to use interrupts to handle button presses and control an LED using GPIO pins. When the button is pressed, an interrupt is triggered, and an interrupt service routine (ISR) suspends the main task to toggle the LED state. The code utilizes FreeRTOS tasks and the ESP32's GPIO driver.

## Requirements

- ESP32 development board or a compatible microcontroller.
- VSCode editor and ESP-IDF extention for VSCode.
- 1x220 ohm resistor
- 1x10 kohm resistor
- 10uF electrolytic Capacitor
## Hardware Setup
ESP32 DevKit V4 board is used fot this project wire components as the picture below:
![alt text](ESP32-IDF-BUTTON-INTERRUPT-EXAMPLE\BT1.png)
## Usage

1. Connect an LED to GPIO pin 26 (LedPin) and a button to GPIO pin 33 (ButtonPin).
2. Include the required header files and libraries.
3. Define the LED and button GPIO pin numbers.
4. Implement the ISR for the button press event.
5. Create the interrupt task to handle LED toggling.
6. Configure GPIO for the LED and button.
7. Install the ISR service and add the ISR handler for the button pin.
8. Create the interrupt task and set the interrupt task handler.
9. Initialize and start the FreeRTOS scheduler.
10. The LED will toggle each time the button is pressed.

## Code Structure

- `app_main`: Entry point of the application.
- `SetGPIO4LED`: Configures the specified GPIO pin for the LED.
- `SetGPIO4Button`: Configures the specified GPIO pin for the button and sets up the interrupt handling.
- `ButtonInterruptServiceHandler`: Interrupt service routine (ISR) for button press events.
- `InterrupTaskFunc`: Task function for handling LED toggling.

## Building and Flashing

To build and flash the code to your ESP32 microcontroller, follow these steps:

1. Download repository and extract it. 
2. Open Visual Studio Code (VSCode) and go to File → Open Folder. Choose the `ESP32_IDF-EXERCISES-main\ESP32-IDF-BUTTON-INTERRUPT-EXAMPLE\`  folder.
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