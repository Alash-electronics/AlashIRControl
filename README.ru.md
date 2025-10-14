# AlashIRControl

AlashIRControl - это библиотека, разработанная для простого управления инфракрасными (ИК) передатчиками и приёмниками с микроконтроллерами Arduino. Эта библиотека упрощает процесс отправки и приёма ИК-сигналов, позволяя легко интегрировать возможности дистанционного управления в ваши проекты.

## Особенности

- Управление ИК-передатчиками
- Работа с ИК-приёмниками
- Определение пользовательских ИК-протоколов
- Поддержка множества примеров и протоколов

## Установка

### Установка

1. Скачайте библиотеку `AlashIRControl`.
2. Поместите скачанный файл в директорию библиотек Arduino IDE.

## Документация

### AlashIRControlRX

Для использования ИК-приёмника:

```cpp
#include <AlashIRControlRX.h>

AlashIRControlRX irReceiver(7); // 7 - пин ИК-приёмника

void setup() {
  Serial.begin(9600);
  irReceiver.begin();
}

void loop() {
  if (irReceiver.check()) {
    Serial.print("Data = ");
    Serial.println(irReceiver.data, HEX);
    Serial.print("Length = ");
    Serial.println(irReceiver.length);
  }
}
```

### AlashIRControlTX

Для использования ИК-передатчика:

```cpp
#include <AlashIRControlTX.h>

AlashIRControlTX irTransmitter(2); // 2 - пин ИК-передатчика

void setup() {
  irTransmitter.begin();
}

void loop() {
  irTransmitter.send(0x00FFA25D); // Отправка ИК-кода
  delay(1000); // Задержка 1 секунда
}
```

## Примеры

Изучите различные сценарии использования через примеры, включённые в библиотеку.

Примеры доступны на трёх языках в папке `examples/`:
- `examples/en/` - Примеры с комментариями на английском
- `examples/ru/` - Примеры с комментариями на русском
- `examples/kk/` - Примеры с комментариями на казахском

## Контакты

Для получения дополнительной информации и поддержки посетите сайт Alash Electronics: https://alash-electronics.kz/

## Лицензия

Эта библиотека лицензирована под MIT License. Подробности см. в файле LICENSE.

## Автор

Разработано Айтен Бексултан для Alash Education.
