/* MiniMacro */
// ESP32-Enabled Macro Keyboard

/* Buttons */
#include <Bounce2.h>                      // Bounce2 Library
int numButtons = 9;
const uint8_t buttonPins[9] = {22, 21, 19, 18, 17, 16, 5, 4, 2};     // List of GPIO pins
Bounce * buttons = new Bounce[9];         // Creates an array of Bounce objects

/* Bluetooth */
#include <BleKeyboard.h>                         // BleKeyboard Library          
BleKeyboard bleKeyboard("ur mom", "Rosa", 100);  // Device Name / Manufacturer / Battery


void setup() {
  Serial.begin(9600);
  initButtons();                      // Initialize Buttons on Startup
  initBattery();                      // Initialize Battery on Startup
  bleKeyboard.begin();                // Begin Bluetooth Connection
}

void loop() {
  if (bleKeyboard.isConnected()) {    // If Bluetooth is Connected
    readButtons();                    // Read State of Buttons and Perform Functions
    updateBattery();                  // Update Battery Status if Needed
  }
}
