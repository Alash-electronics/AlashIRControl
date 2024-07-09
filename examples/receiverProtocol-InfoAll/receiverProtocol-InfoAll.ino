/*
 * Этот код использует библиотеку AlashIRControl для работы с ИК-приёмником. 
 * В функции setup() инициализируются последовательный порт и ИК-приёмник. 
 * В функции loop() проверяется наличие данных от ИК-пульта 
 * и выводится информация о полученных данных и протоколе в монитор последовательного порта.
*/
// Библиотека AlashIRControl для работы с ИК приёмопередатчиками разработана https://alash-electronics.kz/
// Для считывания данных с ИК-пульта предлагаем воспользоваться ИК-приёмником https://alash-electronics.kz/collection/sveta-i-tsveta/product/modul-ik-datchika-vs1838b-ky-022

#include <AlashIRControlRX.h>                                                 // Подключаем библиотеку для работы с ИК-приёмником
AlashIRControlRX irReceiver(7);                                               // Объявляем объект irReceiver, с указанием вывода к которому подключён ИК-приёмник

void setup(){
  Serial.begin(9600);                                                       // Инициируем передачу данных в монитор последовательного порта, на скорости 9600 бит/сек
  irReceiver.begin();                                                       // Инициируем работу с ИК-приёмником
}
void loop(){
  if(irReceiver.check()){                                                   // Если в буфере имеются данные, принятые с пульта (была нажата кнопка)
    Serial.println("====================================");                 // Выводим разделитель
    Serial.print("Data     = "); Serial.print(irReceiver.data, HEX);         Serial.println("\t"); // Выводим данные в шестнадцатеричном формате
    Serial.print("Length   = "); Serial.print(irReceiver.length);            Serial.println("\tbits"); // Выводим длину данных в битах
    Serial.println("====================================");
    Serial.println("PROTOCOL:");
    Serial.print("String   = "); Serial.print(irReceiver.protocol());        Serial.println("\t"); // Выводим строковое представление протокола
    Serial.print("Coding   = "); 
    switch(irReceiver.protocol(0)){                                          // Определяем тип кодирования
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
    Serial.print("F        = "); Serial.print(irReceiver.protocol(1));       Serial.println("\tkHz"); // Выводим частоту протокола
    Serial.println("====================================");
    Serial.println("PACKET:");
    Serial.print("Inform   = "); Serial.print(irReceiver.protocol(2));       Serial.println("\tbits"); // Выводим информацию о пакете
    Serial.print("Repet    = "); Serial.print(irReceiver.protocol(3));       Serial.println("\tbits"); // Выводим количество повторов
    Serial.print("RepType  = "); 
    switch(irReceiver.protocol(19)){                                         // Определяем тип повторов
      case 0: Serial.print("No"); break;
      case 1: Serial.print("inverse bits"); break;
      case 2: Serial.print("identical"); break;
      case 3: Serial.print("unique"); break;
      default: Serial.print("undefined"); break;
    }
    Serial.println("\t");
    Serial.print("Pause    = "); Serial.print(irReceiver.protocol(4));       Serial.println("\tms"); // Выводим паузу в миллисекундах
    Serial.println("====================================");
    Serial.println("BIT START:");
    Serial.print("Pulse    = "); Serial.print(irReceiver.protocol(5));       Serial.println("\tµs"); // Выводим длительность импульса старта в микросекундах
    Serial.print("Pause    = "); Serial.print(irReceiver.protocol(6));       Serial.println("\tµs"); // Выводим длительность паузы старта в микросекундах
    Serial.print("Present  = "); Serial.print(irReceiver.protocol(16) ? "true" : "false"); Serial.println("\t"); // Выводим наличие старта
    Serial.println("====================================");
    Serial.println("BIT STOP:");
    Serial.print("Pulse    = "); Serial.print(irReceiver.protocol(7));       Serial.println("\tµs"); // Выводим длительность импульса стопа в микросекундах
    Serial.print("Pause    = "); Serial.print(irReceiver.protocol(8));       Serial.println("\tµs"); // Выводим длительность паузы стопа в микросекундах
    Serial.print("Present  = "); Serial.print(irReceiver.protocol(17) ? "true" : "false"); Serial.println("\t"); // Выводим наличие стопа
    Serial.println("====================================");
    Serial.println("BIT TOGGLE:");
    Serial.print("Pulse    = "); Serial.print(irReceiver.protocol(9));       Serial.println("\tµs"); // Выводим длительность импульса переключения в микросекундах
    Serial.print("Pause    = "); Serial.print(irReceiver.protocol(10));      Serial.println("\tµs"); // Выводим длительность паузы переключения в микросекундах
    Serial.print("Position = "); Serial.print(irReceiver.protocol(11));      Serial.println("\tbit"); // Выводим позицию переключения
    Serial.print("Present  = "); Serial.print(irReceiver.protocol(18) ? "true" : "false"); Serial.println("\t"); // Выводим наличие переключения
    Serial.println("====================================");
    Serial.println("BITS DATA:");
    Serial.print("PulseMax = "); Serial.print(irReceiver.protocol(12));      Serial.println("\tµs"); // Выводим максимальную длительность импульса данных в микросекундах
    Serial.print("PulseMin = "); Serial.print(irReceiver.protocol(13));      Serial.println("\tµs"); // Выводим минимальную длительность импульса данных в микросекундах
    Serial.print("PauseMax = "); Serial.print(irReceiver.protocol(14));      Serial.println("\tµs"); // Выводим максимальную длительность паузы данных в микросекундах
    Serial.print("PauseMin = "); Serial.print(irReceiver.protocol(15));      Serial.println("\tµs"); // Выводим минимальную длительность паузы данных в микросекундах
    Serial.println("====================================");
    Serial.println("####################################");
  }
}
