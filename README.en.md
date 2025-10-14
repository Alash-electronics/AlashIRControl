# AlashIRControl

AlashIRControl is a library developed for easy control of infrared (IR) transmitters and receivers with Arduino microcontrollers. This library simplifies the process of sending and receiving IR signals, allowing you to easily integrate IR remote control capabilities into your projects.

## Features

- Control IR transmitters
- Work with IR receivers
- Detect custom IR protocols
- Support for multiple examples and protocols

## Installation

### Installation

1. Download the `AlashIRControl` library.
2. Place the downloaded file in the Arduino IDE library directory.

## Documentation

### AlashIRControlRX

To use the IR receiver:

```cpp
#include <AlashIRControlRX.h>

AlashIRControlRX irReceiver(7); // 7 - IR receiver pin

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

To use the IR transmitter:

```cpp
#include <AlashIRControlTX.h>

AlashIRControlTX irTransmitter(2); // 2 - IR transmitter pin

void setup() {
  irTransmitter.begin();
}

void loop() {
  irTransmitter.send(0x00FFA25D); // Send IR code
  delay(1000); // 1 second delay
}
```

## Examples

Explore various use cases through the examples included with the library.

The examples are available in three languages in the `examples/` folder:
- `examples/en/` - Examples with English comments
- `examples/ru/` - Examples with Russian comments
- `examples/kk/` - Examples with Kazakh comments

## Contact

For more information and support, visit the Alash Electronics website: https://alash-electronics.kz/

## License

This library is licensed under the MIT License. See the LICENSE file for details.

## Author

Developed by Айтен Бексултан for Alash Education.
