/*
 * This code uses the AlashIRControl library to control an IR transmitter.
 * In setup(), button pins are configured and the IR transmitter is initialized.
 * In the loop(), button presses on pins 3, 4, and 5 are checked, and corresponding IR codes are sent.
 * When a button is held, repeat packets are transmitted.
*/
// AlashIRControl library for working with IR transceivers developed by https://alash-electronics.kz/
// For sending data, we recommend using an IR transmitter

#include <AlashIRControlTX.h> // Include the library for working with IR transmitter
AlashIRControlTX irTransmitter(2); // Declare irTransmitter object, specifying the pin connected to the IR transmitter

void setup() {
  pinMode(3, INPUT); // Configure pin 3, which is connected to the button, as input
  pinMode(4, INPUT); // Configure pin 4, which is connected to the button, as input
  pinMode(5, INPUT); // Configure pin 5, which is connected to the button, as input
  irTransmitter.begin(); // Initialize IR transmitter
}
void loop() {
  // If button connected to pin 3 is pressed, send code 0x00FFA25D and send repeat packets when held
  if (digitalRead(3)) {
    irTransmitter.send(0x00FFA25D, true);
  }
  // If button connected to pin 4 is pressed, send code 0x00FF629D and send repeat packets when held
  if (digitalRead(4)) {
    irTransmitter.send(0x00FF629D, true);
  }
  // If button connected to pin 5 is pressed, send code 0x00FFE21D and send repeat packets when held
  if (digitalRead(5)) {
    irTransmitter.send(0x00FFE21D, true);
  }
}
/*
 * By default, transmitted data is encoded by pause length.
 * You can change the encoding and protocol using the protocol() function.
 * See example transmitter_SetProtocol.
 */
