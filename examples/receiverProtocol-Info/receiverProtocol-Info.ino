/*
 * Этот код использует библиотеку AlashIRControl для работы с ИК-приёмником. 
 * В функции setup() инициализируются последовательный порт и ИК-приёмник. 
 * В функции loop() проверяется наличие данных от ИК-пульта и выводится информация о протоколе и типе кодировки нажатой кнопки.
*/

// Библиотека AlashIRControl для работы с ИК приёмопередатчиками разработана https://alash-electronics.kz/
// Для считывания данных с ИК-пульта предлагаем воспользоваться ИК-приёмником https://alash-electronics.kz/collection/sveta-i-tsveta/product/modul-ik-datchika-vs1838b-ky-022

#include <AlashIRControlRX.h> // Подключаем библиотеку для работы с ИК-приёмником
AlashIRControlRX irReceiver(7); // Объявляем объект irReceiver, с указанием вывода, к которому подключён ИК-приёмник

void setup() {
  Serial.begin(9600); // Инициируем передачу данных в монитор последовательного порта, на скорости 9600 бит/сек
  irReceiver.begin(); // Инициируем работу с ИК-приёмником
}
void loop() {
  if (irReceiver.check()) { // Если в буфере имеются данные, принятые с пульта (была нажата кнопка)
    Serial.print("Protocol = "); 
    Serial.println(irReceiver.protocol()); // Выводим протокол нажатой кнопки
    
    Serial.print("Coding = "); 
    switch (irReceiver.protocol(0)) { // Определяем тип кодировки
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
