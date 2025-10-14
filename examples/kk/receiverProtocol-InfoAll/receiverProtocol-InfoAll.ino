/*
 * Бұл код ИҚ-қабылдағышпен жұмыс істеу үшін AlashIRControl кітапханасын пайдаланады.
 * setup() функциясында сериялық порт пен ИҚ-қабылдағыш инициализацияланады.
 * loop() функциясында ИҚ-пультінен деректердің бар-жоғы тексеріледі
 * және қабылданған деректер мен хаттама туралы ақпарат сериялық мониторға шығарылады.
*/
// AlashIRControl кітапханасы ИҚ-қабылдағыштармен жұмыс үшін https://alash-electronics.kz/ дайындалған
// ИҚ-пультінен деректерді оқу үшін ИҚ-қабылдағышты пайдалануды ұсынамыз https://alash-electronics.kz/collection/sveta-i-tsveta/product/modul-ik-datchika-vs1838b-ky-022

#include <AlashIRControlRX.h>                                                 // ИҚ-қабылдағышпен жұмыс істеу үшін кітапхананы қосу
AlashIRControlRX irReceiver(7);                                               // irReceiver объектісін жариялау, ИҚ-қабылдағыш қосылған пинді көрсету

void setup(){
  Serial.begin(9600);                                                       // Сериялық портты 9600 бод жылдамдығында бастау
  irReceiver.begin();                                                       // ИҚ-қабылдағышты инициализациялау
}
void loop(){
  if(irReceiver.check()){                                                   // Егер буферде пультінен қабылданған деректер болса (батырма басылған)
    Serial.println("====================================");                 // Бөлгішті шығару
    Serial.print("Data     = "); Serial.print(irReceiver.data, HEX);         Serial.println("\t"); // Деректерді он алтылық форматта шығару
    Serial.print("Length   = "); Serial.print(irReceiver.length);            Serial.println("\tbits"); // Деректер ұзындығын биттерде шығару
    Serial.println("====================================");
    Serial.println("PROTOCOL:");
    Serial.print("String   = "); Serial.print(irReceiver.protocol());        Serial.println("\t"); // Хаттаманың жол түрінде көрінісін шығару
    Serial.print("Coding   = ");
    switch(irReceiver.protocol(0)){                                          // Кодтау түрін анықтау
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
    Serial.print("F        = "); Serial.print(irReceiver.protocol(1));       Serial.println("\tkHz"); // Хаттама жиілігін шығару
    Serial.println("====================================");
    Serial.println("PACKET:");
    Serial.print("Inform   = "); Serial.print(irReceiver.protocol(2));       Serial.println("\tbits"); // Пакет ақпаратын шығару
    Serial.print("Repet    = "); Serial.print(irReceiver.protocol(3));       Serial.println("\tbits"); // Қайталау санын шығару
    Serial.print("RepType  = ");
    switch(irReceiver.protocol(19)){                                         // Қайталау түрін анықтау
      case 0: Serial.print("No"); break;
      case 1: Serial.print("inverse bits"); break;
      case 2: Serial.print("identical"); break;
      case 3: Serial.print("unique"); break;
      default: Serial.print("undefined"); break;
    }
    Serial.println("\t");
    Serial.print("Pause    = "); Serial.print(irReceiver.protocol(4));       Serial.println("\tms"); // Үзілісті миллисекундтарда шығару
    Serial.println("====================================");
    Serial.println("BIT START:");
    Serial.print("Pulse    = "); Serial.print(irReceiver.protocol(5));       Serial.println("\tµs"); // Бастау импульсінің ұзақтығын микросекундтарда шығару
    Serial.print("Pause    = "); Serial.print(irReceiver.protocol(6));       Serial.println("\tµs"); // Бастау үзілісінің ұзақтығын микросекундтарда шығару
    Serial.print("Present  = "); Serial.print(irReceiver.protocol(16) ? "true" : "false"); Serial.println("\t"); // Бастаудың болуын шығару
    Serial.println("====================================");
    Serial.println("BIT STOP:");
    Serial.print("Pulse    = "); Serial.print(irReceiver.protocol(7));       Serial.println("\tµs"); // Тоқтату импульсінің ұзақтығын микросекундтарда шығару
    Serial.print("Pause    = "); Serial.print(irReceiver.protocol(8));       Serial.println("\tµs"); // Тоқтату үзілісінің ұзақтығын микросекундтарда шығару
    Serial.print("Present  = "); Serial.print(irReceiver.protocol(17) ? "true" : "false"); Serial.println("\t"); // Тоқтатудың болуын шығару
    Serial.println("====================================");
    Serial.println("BIT TOGGLE:");
    Serial.print("Pulse    = "); Serial.print(irReceiver.protocol(9));       Serial.println("\tµs"); // Ауыстыру импульсінің ұзақтығын микросекундтарда шығару
    Serial.print("Pause    = "); Serial.print(irReceiver.protocol(10));      Serial.println("\tµs"); // Ауыстыру үзілісінің ұзақтығын микросекундтарда шығару
    Serial.print("Position = "); Serial.print(irReceiver.protocol(11));      Serial.println("\tbit"); // Ауыстыру позициясын шығару
    Serial.print("Present  = "); Serial.print(irReceiver.protocol(18) ? "true" : "false"); Serial.println("\t"); // Ауыстырудың болуын шығару
    Serial.println("====================================");
    Serial.println("BITS DATA:");
    Serial.print("PulseMax = "); Serial.print(irReceiver.protocol(12));      Serial.println("\tµs"); // Деректер импульсінің максималды ұзақтығын микросекундтарда шығару
    Serial.print("PulseMin = "); Serial.print(irReceiver.protocol(13));      Serial.println("\tµs"); // Деректер импульсінің минималды ұзақтығын микросекундтарда шығару
    Serial.print("PauseMax = "); Serial.print(irReceiver.protocol(14));      Serial.println("\tµs"); // Деректер үзілісінің максималды ұзақтығын микросекундтарда шығару
    Serial.print("PauseMin = "); Serial.print(irReceiver.protocol(15));      Serial.println("\tµs"); // Деректер үзілісінің минималды ұзақтығын микросекундтарда шығару
    Serial.println("====================================");
    Serial.println("####################################");
  }
}
