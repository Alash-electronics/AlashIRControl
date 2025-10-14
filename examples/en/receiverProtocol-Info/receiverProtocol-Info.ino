/*
 * This code uses the AlashIRControl library to work with an IR receiver.
 * In setup(), the serial port and IR receiver are initialized.
 * In loop(), it checks for data from the IR remote and outputs protocol information and encoding type of the pressed button.
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
    Serial.print("Protocol = ");
    Serial.println(irReceiver.protocol()); // Output the protocol of the pressed button

    Serial.print("Coding = ");
    switch (irReceiver.protocol(0)) { // Determine the encoding type
      case IR_PAUSE_LENGTH:
        Serial.println("pauseLength");
        break;
      case IR_PULSE_LENGTH:
        Serial.println("pulseLength");
        break;
      case IR_BIPHASIC:
        Serial.println("biphasic");
        break;
      case IR_BIPHASIC_INV:
        Serial.println("biphasic invert");
        break;
      case IR_NRC:
        Serial.println("NRC");
        break;
      case IR_RS5:
        Serial.println("RS5");
        break;
      case IR_RS5X:
        Serial.println("RS5X");
        break;
      case IR_RS6:
        Serial.println("RS6");
        break;
      default:
        Serial.println("undefined");
        break;
    }
    Serial.println("================");
  }
}
