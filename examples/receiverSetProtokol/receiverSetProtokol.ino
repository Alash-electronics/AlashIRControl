/*
 * Программа использует библиотеку AlashIRControl для работы с ИК-приёмопередатчиками. 
 * При удержании кнопки на пульте код кнопки и длина сообщения отображаются в мониторе последовательного порта. 
 * Код также включает установку протокола передачи данных для правильного распознавания сигналов.
*/

// Библиотека AlashIRControl для работы с ИК приёмопередатчиками разработана https://alash-electronics.kz/
// Для считывания данных с ИК-пульта предлагаем воспользоваться ИК-приёмником https://alash-electronics.kz/collection/sveta-i-tsveta/product/modul-ik-datchika-vs1838b-ky-022

#include <AlashIRControlRX.h> // Подключаем библиотеку для работы с ИК-приёмником

AlashIRControlRX irReceiver(7); // Объявляем объект irReceiver, указывая вывод, к которому подключён ИК-приёмник

void setup() {
  Serial.begin(9600); // Инициализация передачи данных в монитор последовательного порта на скорости 9600 бит/сек
  irReceiver.begin(); // Инициализация работы с ИК-приёмником
  irReceiver.protocol("Ae`@gxYL@L`|LK`I@@@@@BPCp"); // Установка протокола передачи данных, на который следует реагировать
}

void loop() {
  if (irReceiver.check(true)) { // Проверка наличия данных в буфере, принятых с пульта (удерживается кнопка)
    Serial.println(irReceiver.data, HEX); // Вывод кода нажатой кнопки в шестнадцатеричном формате
    Serial.println(irReceiver.length); // Вывод количества бит в коде
  }
}
