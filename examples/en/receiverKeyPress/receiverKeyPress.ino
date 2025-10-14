/*
 * This program demonstrates working with an IR receiver and the AlashIRControl library.
 * When any button is pressed on any remote control, the button code and message length are displayed in the serial monitor.
*/

// AlashIRControl library for working with IR transceivers developed by https://alash-electronics.kz/
// For reading data from IR remote, we recommend using an IR receiver https://alash-electronics.kz/collection/sveta-i-tsveta/product/modul-ik-datchika-vs1838b-ky-022

#include <AlashIRControlRX.h> // Include the library for working with IR receiver
AlashIRControlRX irReceiver(7); // Declare irReceiver object, specifying the pin connected to the IR receiver

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate
  irReceiver.begin(); // Initialize IR receiver
}
void loop() {
  if (irReceiver.check()) { // If buffer contains data received from the remote (button was pressed)
    Serial.println(irReceiver.data, HEX); // Output the button code in hexadecimal format
    Serial.println(irReceiver.length); // Output the number of bits in the code
  }
}
