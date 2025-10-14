# AlashIRControl

[English](#english) | [Русский](#русский) | [Қазақша](#қазақша)

---

## English

AlashIRControl is a library developed for easy control of infrared (IR) transmitters and receivers with Arduino microcontrollers. This library simplifies the process of sending and receiving IR signals, allowing you to easily integrate IR remote control capabilities into your projects.

### Features

- Control IR transmitters
- Work with IR receivers
- Detect custom IR protocols
- Support for multiple examples and protocols

### Quick Start

```cpp
#include <AlashIRControlRX.h>

AlashIRControlRX irReceiver(7);

void setup() {
  Serial.begin(9600);
  irReceiver.begin();
}

void loop() {
  if (irReceiver.check()) {
    Serial.println(irReceiver.data, HEX);
  }
}
```

### Examples

Examples are available in three languages in the `examples/` folder:
- `examples/en/` - Examples with English comments
- `examples/ru/` - Examples with Russian comments
- `examples/kk/` - Examples with Kazakh comments

**[Full documentation in English →](README.en.md)**

---

## Русский

AlashIRControl - это библиотека, разработанная для простого управления инфракрасными (ИК) передатчиками и приёмниками с микроконтроллерами Arduino. Эта библиотека упрощает процесс отправки и приёма ИК-сигналов, позволяя легко интегрировать возможности дистанционного управления в ваши проекты.

### Особенности

- Управление ИК-передатчиками
- Работа с ИК-приёмниками
- Определение пользовательских ИК-протоколов
- Поддержка множества примеров и протоколов

### Быстрый старт

```cpp
#include <AlashIRControlRX.h>

AlashIRControlRX irReceiver(7);

void setup() {
  Serial.begin(9600);
  irReceiver.begin();
}

void loop() {
  if (irReceiver.check()) {
    Serial.println(irReceiver.data, HEX);
  }
}
```

### Примеры

Примеры доступны на трёх языках в папке `examples/`:
- `examples/en/` - Примеры с комментариями на английском
- `examples/ru/` - Примеры с комментариями на русском
- `examples/kk/` - Примеры с комментариями на казахском

**[Полная документация на русском →](README.ru.md)**

---

## Қазақша

AlashIRControl - бұл Arduino микроконтроллерлерімен жұмыс істеуге арналған инфрақызыл (ИҚ) таратқыштар мен қабылдағыштарды оңай басқару үшін әзірленген кітапхана. Бұл кітапхана ИҚ сигналдарын жіберу және қабылдау үдерісін жеңілдетеді, сіздің жобаларыңызда ИҚ қашықтықтан басқару мүмкіндіктерін оңай енгізуге мүмкіндік береді.

### Ерекшеліктері

- ИҚ таратқыштарды басқару
- ИҚ қабылдағыштармен жұмыс
- Қолданушының ИҚ хаттамаларын анықтау
- Бірнеше мысалдар мен хаттамалар қолдауы

### Жылдам бастау

```cpp
#include <AlashIRControlRX.h>

AlashIRControlRX irReceiver(7);

void setup() {
  Serial.begin(9600);
  irReceiver.begin();
}

void loop() {
  if (irReceiver.check()) {
    Serial.println(irReceiver.data, HEX);
  }
}
```

### Мысалдар

Мысалдар `examples/` қалтасында үш тілде қолжетімді:
- `examples/en/` - Ағылшын тіліндегі түсініктемелері бар мысалдар
- `examples/ru/` - Орыс тіліндегі түсініктемелері бар мысалдар
- `examples/kk/` - Қазақ тіліндегі түсініктемелері бар мысалдар

**[Қазақ тіліндегі толық құжаттама →](README.kk.md)**

---

## Installation / Установка / Орнату

### Arduino IDE

1. Download this library
2. Place it in your Arduino libraries folder: `~/Documents/Arduino/libraries/`

### PlatformIO

```ini
lib_deps =
    https://github.com/Alash-electronics/AlashIRControl.git
```

---

## Links / Ссылки / Сілтемелер

- **Website / Сайт / Веб-сайт**: https://alash-electronics.kz/
- **GitHub**: https://github.com/Alash-electronics/AlashIRControl
- **Documentation / Документация / Құжаттама**: [CLAUDE.md](CLAUDE.md)

---

## License / Лицензия / Лицензия

MIT License

Copyright (c) 2024 Alash Electronics

**Author / Автор / Автор**: Айтен Бексултан
**Maintainer / Поддержка / Қолдау**: Alash Education
