/*
 * This code uses the AlashIRControl library to control an IR transmitter.
 * In setup(), the transmitter is initialized and sends code 0x00FFA25D once at startup.
 * The loop() does nothing. By default, data is encoded by pause length,
 * but you can change the encoding and protocol using the protocol() function.
*/

// AlashIRControl library for working with IR transceivers developed by https://alash-electronics.kz/
// For sending data, we recommend using an IR transmitter

#include <AlashIRControlTX.h> // Include the library for working with IR transmitter
AlashIRControlTX irTransmitter(10); // Declare irTransmitter object, specifying the pin connected to the IR transmitter

void setup() {
  irTransmitter.begin(); // Initialize IR transmitter
  irTransmitter.send(0x00FFA25D); // Send code 0x00FFA25D once
}
void loop() {} // Empty loop, Arduino will send the code at startup
/*
 * By default, transmitted data is encoded by pause length.
 * You can change the encoding and protocol using the protocol() function.
 * See example transmitterSetProtocol.
 */
