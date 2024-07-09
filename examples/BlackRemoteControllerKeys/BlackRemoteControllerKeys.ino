// Библиотека AlashIRControl для работы с ИК приёмопередатчиками разработана https://alash-electronics.kz/
// Для считывания данных с ИК-пульта предлагаем воспользоваться ИК-приёмником https://alash-electronics.kz/collection/sveta-i-tsveta/product/modul-ik-datchika-vs1838b-ky-022

#include <AlashIRControlRX.h>                                                 // Подключаем библиотеку для работы с ИК-приёмником
AlashIRControlRX irReceiver(7);                                               // Объявляем объект irReceiver, с указанием вывода к которому подключён ИК-приёмник

void setup() {
  Serial.begin(9600);                                                       // Инициируем передачу данных в монитор последовательного порта, на скорости 9600 бит/сек
  irReceiver.begin();                                                       // Инициируем работу с ИК-приёмником
}

void loop() {
  if (irReceiver.check()) {                                                  // Если в буфере имеются данные, принятые с пульта (была нажата кнопка)
    Serial.print("Received code: ");                                         // Печатаем полученный код
    Serial.println(irReceiver.data, HEX);                                    // Выводим данные в шестнадцатеричном формате
    switch (irReceiver.data) {                                               // Обрабатываем полученный код
      case 0xFFA25D: Serial.println("Button: 1"); break;
      case 0xFF629D: Serial.println("Button: 2"); break;
      case 0xFFE21D: Serial.println("Button: 3"); break;
      case 0xFF22DD: Serial.println("Button: 4"); break;
      case 0xFF02FD: Serial.println("Button: 5"); break;
      case 0xFFC23D: Serial.println("Button: 6"); break;
      case 0xFFE01F: Serial.println("Button: 7"); break;
      case 0xFFA857: Serial.println("Button: 8"); break;
      case 0xFF906F: Serial.println("Button: 9"); break;
      case 0xFF6897: Serial.println("Button: *"); break;
      case 0xFF9867: Serial.println("Button: 0"); break;
      case 0xFFB04F: Serial.println("Button: #"); break;
      case 0xFF18E7: Serial.println("Button: UP"); break;
      case 0xFF10EF: Serial.println("Button: LEFT"); break;
      case 0xFF38C7: Serial.println("Button: OK"); break;
      case 0xFF5AA5: Serial.println("Button: RIGHT"); break;
      case 0xFF4AB5: Serial.println("Button: DOWN"); break;
      default: Serial.println("Button: UNKNOWN"); break;
    }
  }
}
