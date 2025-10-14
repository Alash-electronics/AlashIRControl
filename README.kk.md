# AlashIRControl

AlashIRControl - бұл Arduino микроконтроллерлерімен жұмыс істеуге арналған инфрақызыл (ИҚ) таратқыштар мен қабылдағыштарды оңай басқару үшін әзірленген кітапхана. Бұл кітапхана ИҚ сигналдарын жіберу және қабылдау үдерісін жеңілдетеді, сіздің жобаларыңызда ИҚ қашықтықтан басқару мүмкіндіктерін оңай енгізуге мүмкіндік береді.

## Ерекшеліктері

- ИҚ таратқыштарды басқару
- ИҚ қабылдағыштармен жұмыс
- Қолданушының ИҚ хаттамаларын анықтау
- Бірнеше мысалдар мен хаттамалар қолдауы

## Орнату

### Орнату

1. `AlashIRControl` кітапханасын жүктеп алыңыз.
2. Жүктелген файлды Arduino IDE кітапхана директориясына орналастырыңыз.

## Құжаттама

### AlashIRControlRX

ИҚ-қабылдағышты пайдалану үшін:

```cpp
#include <AlashIRControlRX.h>

AlashIRControlRX irReceiver(7); // 7 - ИҚ-қабылдағыштың пині

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

ИҚ-таратқышты пайдалану үшін:

```cpp
#include <AlashIRControlTX.h>

AlashIRControlTX irTransmitter(2); // 2 - ИҚ-таратқыштың пині

void setup() {
  irTransmitter.begin();
}

void loop() {
  irTransmitter.send(0x00FFA25D); // ИҚ кодын жіберу
  delay(1000); // 1 секундтық кідіріс
}
```

## Мысалдар

Кітапханаға кіретін мысалдар арқылы әртүрлі қолдану сценарийлерін зерттеңіз.

Мысалдар `examples/` қалтасында үш тілде қолжетімді:
- `examples/en/` - Ағылшын тіліндегі түсініктемелері бар мысалдар
- `examples/ru/` - Орыс тіліндегі түсініктемелері бар мысалдар
- `examples/kk/` - Қазақ тіліндегі түсініктемелері бар мысалдар

## Байланыс

Қосымша ақпарат пен қолдау үшін Alash Electronics сайтына кіріңіз: https://alash-electronics.kz/

## Лицензия

Бұл кітапхана MIT License лицензиясы бойынша таратылады. Толық ақпаратты LICENSE файлынан қараңыз.

## Автор

Alash Education үшін Айтен Бексултан әзірлеген.
