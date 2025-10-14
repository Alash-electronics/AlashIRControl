// AlashIRControl library for working with IR transceivers developed by https://alash-electronics.kz/
// For reading data from IR remote, we recommend using an IR receiver https://alash-electronics.kz/collection/sveta-i-tsveta/product/modul-ik-datchika-vs1838b-ky-022

#include <AlashIRControlRX.h>                                                 // Include the library for working with IR receiver
AlashIRControlRX irReceiver(7);                                               // Declare irReceiver object, specifying the pin connected to the IR receiver

void setup() {
  Serial.begin(9600);                                                       // Initialize serial communication at 9600 baud rate
  irReceiver.begin();                                                       // Initialize IR receiver
}
void loop() {
  if (irReceiver.check(true)) {                                                  // If buffer contains data received from the remote (button was pressed)
    Serial.print("Received code: ");                                         // Print received code
    Serial.println(irReceiver.data, HEX);                                    // Output data in hexadecimal format
    switch (irReceiver.data) {                                               // Process the received code
      case 0xFFA25D: Serial.println("Button: CH-"); break;
      case 0xFF629D: Serial.println("Button: CH"); break;
      case 0xFFE21D: Serial.println("Button: CH+"); break;
      case 0xFF22DD: Serial.println("Button: PREV"); break;
      case 0xFF02FD: Serial.println("Button: NEXT"); break;
      case 0xFFC23D: Serial.println("Button: PLAY/PAUSE"); break;
      case 0xFFE01F: Serial.println("Button: -"); break;
      case 0xFFA857: Serial.println("Button: +"); break;
      case 0xFF906F: Serial.println("Button: EQ"); break;
      case 0xFF6897: Serial.println("Button: 0"); break;
      case 0xFF9867: Serial.println("Button: 100+"); break;
      case 0xFFB04F: Serial.println("Button: 200+"); break;
      case 0xFF30CF: Serial.println("Button: 1"); break;
      case 0xFF18E7: Serial.println("Button: 2"); break;
      case 0xFF7A85: Serial.println("Button: 3"); break;
      case 0xFF10EF: Serial.println("Button: 4"); break;
      case 0xFF38C7: Serial.println("Button: 5"); break;
      case 0xFF5AA5: Serial.println("Button: 6"); break;
      case 0xFF42BD: Serial.println("Button: 7"); break;
      case 0xFF4AB5: Serial.println("Button: 8"); break;
      case 0xFF52AD: Serial.println("Button: 9"); break;
      default: Serial.println("Button: UNKNOWN"); break;
    }
  }
}
