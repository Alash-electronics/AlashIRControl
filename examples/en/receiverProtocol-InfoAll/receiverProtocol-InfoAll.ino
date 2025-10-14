/*
 * This code uses the AlashIRControl library to work with an IR receiver.
 * In setup(), the serial port and IR receiver are initialized.
 * In loop(), it checks for data from the IR remote
 * and outputs information about received data and protocol to the serial monitor.
*/
// AlashIRControl library for working with IR transceivers developed by https://alash-electronics.kz/
// For reading data from IR remote, we recommend using an IR receiver https://alash-electronics.kz/collection/sveta-i-tsveta/product/modul-ik-datchika-vs1838b-ky-022

#include <AlashIRControlRX.h>                                                 // Include the library for working with IR receiver
AlashIRControlRX irReceiver(7);                                               // Declare irReceiver object, specifying the pin connected to the IR receiver

void setup(){
  Serial.begin(9600);                                                       // Initialize serial communication at 9600 baud rate
  irReceiver.begin();                                                       // Initialize IR receiver
}
void loop(){
  if(irReceiver.check()){                                                   // If buffer contains data received from the remote (button was pressed)
    Serial.println("====================================");                 // Output separator
    Serial.print("Data     = "); Serial.print(irReceiver.data, HEX);         Serial.println("\t"); // Output data in hexadecimal format
    Serial.print("Length   = "); Serial.print(irReceiver.length);            Serial.println("\tbits"); // Output data length in bits
    Serial.println("====================================");
    Serial.println("PROTOCOL:");
    Serial.print("String   = "); Serial.print(irReceiver.protocol());        Serial.println("\t"); // Output protocol string representation
    Serial.print("Coding   = ");
    switch(irReceiver.protocol(0)){                                          // Determine encoding type
      case IR_PAUSE_LENGTH:      Serial.print("pause length");     break;
      case IR_PULSE_LENGTH:      Serial.print("pulse length");     break;
      case IR_BIPHASIC:          Serial.print("biphasic");         break;
      case IR_BIPHASIC_INV:      Serial.print("biphasic invert");  break;
      case IR_NRC:               Serial.print("NRC");              break;
      case IR_RS5:               Serial.print("RS5");              break;
      case IR_RS5X:              Serial.print("RS5X");             break;
      case IR_RS6:               Serial.print("RS6");              break;
      default:                   Serial.print("Undefined");        break;
    }
    Serial.println("\t");
    Serial.print("F        = "); Serial.print(irReceiver.protocol(1));       Serial.println("\tkHz"); // Output protocol frequency
    Serial.println("====================================");
    Serial.println("PACKET:");
    Serial.print("Inform   = "); Serial.print(irReceiver.protocol(2));       Serial.println("\tbits"); // Output packet information
    Serial.print("Repet    = "); Serial.print(irReceiver.protocol(3));       Serial.println("\tbits"); // Output repeat count
    Serial.print("RepType  = ");
    switch(irReceiver.protocol(19)){                                         // Determine repeat type
      case 0: Serial.print("No"); break;
      case 1: Serial.print("inverse bits"); break;
      case 2: Serial.print("identical"); break;
      case 3: Serial.print("unique"); break;
      default: Serial.print("undefined"); break;
    }
    Serial.println("\t");
    Serial.print("Pause    = "); Serial.print(irReceiver.protocol(4));       Serial.println("\tms"); // Output pause in milliseconds
    Serial.println("====================================");
    Serial.println("BIT START:");
    Serial.print("Pulse    = "); Serial.print(irReceiver.protocol(5));       Serial.println("\tµs"); // Output start pulse duration in microseconds
    Serial.print("Pause    = "); Serial.print(irReceiver.protocol(6));       Serial.println("\tµs"); // Output start pause duration in microseconds
    Serial.print("Present  = "); Serial.print(irReceiver.protocol(16) ? "true" : "false"); Serial.println("\t"); // Output start presence
    Serial.println("====================================");
    Serial.println("BIT STOP:");
    Serial.print("Pulse    = "); Serial.print(irReceiver.protocol(7));       Serial.println("\tµs"); // Output stop pulse duration in microseconds
    Serial.print("Pause    = "); Serial.print(irReceiver.protocol(8));       Serial.println("\tµs"); // Output stop pause duration in microseconds
    Serial.print("Present  = "); Serial.print(irReceiver.protocol(17) ? "true" : "false"); Serial.println("\t"); // Output stop presence
    Serial.println("====================================");
    Serial.println("BIT TOGGLE:");
    Serial.print("Pulse    = "); Serial.print(irReceiver.protocol(9));       Serial.println("\tµs"); // Output toggle pulse duration in microseconds
    Serial.print("Pause    = "); Serial.print(irReceiver.protocol(10));      Serial.println("\tµs"); // Output toggle pause duration in microseconds
    Serial.print("Position = "); Serial.print(irReceiver.protocol(11));      Serial.println("\tbit"); // Output toggle position
    Serial.print("Present  = "); Serial.print(irReceiver.protocol(18) ? "true" : "false"); Serial.println("\t"); // Output toggle presence
    Serial.println("====================================");
    Serial.println("BITS DATA:");
    Serial.print("PulseMax = "); Serial.print(irReceiver.protocol(12));      Serial.println("\tµs"); // Output maximum data pulse duration in microseconds
    Serial.print("PulseMin = "); Serial.print(irReceiver.protocol(13));      Serial.println("\tµs"); // Output minimum data pulse duration in microseconds
    Serial.print("PauseMax = "); Serial.print(irReceiver.protocol(14));      Serial.println("\tµs"); // Output maximum data pause duration in microseconds
    Serial.print("PauseMin = "); Serial.print(irReceiver.protocol(15));      Serial.println("\tµs"); // Output minimum data pause duration in microseconds
    Serial.println("====================================");
    Serial.println("####################################");
  }
}
