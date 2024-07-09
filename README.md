# AlashIRControl

AlashIRControl - бұл Arduino микроконтроллерлерімен жұмыс істеуге арналған инфрақызыл (IR) таратқыштар мен қабылдағыштарды оңай басқару үшін әзірленген кітапхана. Бұл кітапхана IR сигналдарын жіберу және қабылдау үдерісін жеңілдетеді, сіздің жобаларыңызда IR қашықтықтан басқару мүмкіндіктерін оңай енгізуге мүмкіндік береді.

## Ерекшеліктері

- IR таратқыштарды басқару
- IR қабылдағыштармен жұмыс
- Қолданушының IR хаттамаларын анықтау
- Бірнеше мысалдар мен хаттамалар қолдауы

## Қолдану

### Орнату

1. `AlashIRControl` кітапханасын жүктеп алыңыз.
2. Жүктелген файлды Arduino IDE кітапхана директориясына орналастырыңыз.

### Құжаттама

#### AlashIRControlRX

ИК-қабылдағышты пайдалану үшін:

```cpp
#include <AlashIRControlRX.h>

AlashIRControlRX irReceiver(7); // 7 - ИК-қабылдағыштың пині

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


#### AlashIRControlTX
ИК-таратқышты пайдалану үшін:

```cpp
#include <AlashIRControlTX.h>

AlashIRControlTX irTransmitter(2); // 2 - ИК-таратқыштың пині

void setup() {
  irTransmitter.begin();
}

void loop() {
  irTransmitter.send(0x00FFA25D); // IR кодын жіберу
  delay(1000); // 1 секундтық кідіріс
}
```
Мысалдар
Кітапханаға кіретін мысалдар арқылы әртүрлі қолдану сценарийлерін зерттеңіз.

Лицензия
Бұл жоба MIT лицензиясы бойынша лицензияланған. Қосымша ақпаратты LICENSE файлына қараңыз.

Байланыс
Қосымша ақпарат пен қолдау үшін Alash Electronics сайтына кіріңіз.
