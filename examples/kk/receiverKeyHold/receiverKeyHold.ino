/*
 * Бұл бағдарлама ИҚ-қабылдағышпен және AlashIRControl кітапханасымен жұмысты көрсетеді.
 * Пультте кез келген батырма басылып тұрғанда, батырма коды мен хабарлама ұзындығы сериялық мониторда көрсетіледі.
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
  if (irReceiver.check(true)) { // Пультінен қабылданған деректердің буферде бар-жоғын тексеру (батырма басылып тұр)
    Serial.println(irReceiver.data, HEX); // Батырма кодын он алтылық форматта шығару
    Serial.println(irReceiver.length); // Коддағы биттер санын шығару
  }
}
