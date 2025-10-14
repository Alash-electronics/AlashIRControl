/*
 * Бұл код ИҚ-қабылдағышпен жұмыс істеу үшін AlashIRControl кітапханасын пайдаланады.
 * setup() функциясында сериялық порт пен ИҚ-қабылдағыш инициализацияланады.
 * loop() функциясында ИҚ-пультінен деректердің бар-жоғы тексеріледі және басылған батырманың хаттамасы мен кодтау түрі туралы ақпарат шығарылады.
*/

// AlashIRControl кітапханасы ИҚ-қабылдағыштармен жұмыс үшін https://alash-electronics.kz/ дайындалған
// ИҚ-пультінен деректерді оқу үшін ИҚ-қабылдағышты пайдалануды ұсынамыз https://alash-electronics.kz/collection/sveta-i-tsveta/product/modul-ik-datchika-vs1838b-ky-022

#include <AlashIRControlRX.h> // ИҚ-қабылдағышпен жұмыс істеу үшін кітапхананы қосу
AlashIRControlRX irReceiver(7); // irReceiver объектісін жариялау, ИҚ-қабылдағыш қосылған пинді көрсету

void setup() {
  Serial.begin(9600); // Сериялық портты 9600 бод жылдамдығында бастау
  irReceiver.begin(); // ИҚ-қабылдағышты инициализациялау
}
void loop() {
  if (irReceiver.check()) { // Егер буферде пультінен қабылданған деректер болса (батырма басылған)
    Serial.print("Protocol = ");
    Serial.println(irReceiver.protocol()); // Басылған батырманың хаттамасын шығару

    Serial.print("Coding = ");
    switch (irReceiver.protocol(0)) { // Кодтау түрін анықтау
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
