/*
 * This code uses the AlashIRControl library to control an IR transmitter.
 * In setup(), button pins are configured and the IR transmitter is initialized with a protocol.
 * In loop(), button presses on pins 6, 7, and 8 are checked, and corresponding IR codes are sent.
*/

// AlashIRControl library for working with IR transceivers developed by https://alash-electronics.kz/
// For sending data, we recommend using an IR transmitter

#include <AlashIRControlTX.h> // Include the library for working with IR transmitter
AlashIRControlTX irTransmitter(2); // Declare irTransmitter object, specifying the pin connected to the IR transmitter

void setup() {
  irTransmitter.begin(); // Initialize IR transmitter
  pinMode(6, INPUT); // Configure pin 6, which is connected to the button, as input
  pinMode(7, INPUT); // Configure pin 7, which is connected to the button, as input
  pinMode(8, INPUT); // Configure pin 8, which is connected to the button, as input
  irTransmitter.protocol("AeQQV~zK]Kp^KJp[@@@@@@@Bp"); // Set the data transmission protocol for ELENBERG remote
}
void loop() {
  if (digitalRead(6)) {
    irTransmitter.send(0x417, true); // If button on pin 6 is pressed, send ON/OFF signal with repeat packets
  }
  if (digitalRead(7)) {
    irTransmitter.send(0x425, true); // If button on pin 7 is pressed, send VOL- signal with repeat packets
  }
  if (digitalRead(8)) {
    irTransmitter.send(0x427); // If button on pin 8 is pressed, send VOL+ signal without repeat packets
  }
}

/*
 * By default, transmitted data is encoded by pause length.
 * You can change the encoding and protocol using the protocol() function.
 * See example transmitter_SetProtocol.
 */
