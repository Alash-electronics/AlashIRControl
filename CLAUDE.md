# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

AlashIRControl is an Arduino library for controlling infrared (IR) transmitters and receivers. It's designed for use with Arduino microcontrollers and simplifies sending and receiving IR signals for remote control applications (TVs, air conditioners, etc.).

**Language**: The codebase uses a mix of Russian and Kazakh comments. The library was developed by Alash Education for educational purposes.

## Architecture

### Core Components

The library is split into two main classes with distinct responsibilities:

1. **AlashIRControlRX** (src/AlashIRControlRX.h) - IR Receiver
   - Receives IR signals and decodes them
   - Automatically detects IR protocols or accepts user-defined protocols
   - Handles repeated packets (key hold detection)

2. **AlashIRControlTX** (src/AlashIRControlTX.h) - IR Transmitter
   - Sends IR signals with carrier frequency modulation
   - Supports custom protocols and repeat packets
   - Manages timing for IR pulse transmission

3. **AlashIRControl_VV** (src/AlashIRControl.h) - Volatile Variables Class
   - Contains all volatile variables used in timer interrupts
   - Shared state between ISR and main code

4. **AlashIRControl_XX** (src/AlashIRControl.h) - Common Functions Class
   - Timer configuration and management
   - Protocol decoding utilities

### Timer-Based Architecture

The library relies heavily on hardware timer interrupts for precise timing:

- **Timer callback function**: Processes IR signal timing in the background
- **Platform-specific timers**:
  - AVR boards (UNO, NANO, MEGA): Timer2
  - ESP32: Timer 2
  - ESP8266: Timer 1
  - Arduino UNO R4 (Renesas): FspTimer

Timer configuration is abstracted in `AlashIRControlTimer.h`, which handles all platform-specific timer setup.

### IR Protocol Support

The library supports multiple IR encoding schemes:

- `IR_PAUSE_LENGTH` (1) - Pause length encoding
- `IR_PULSE_LENGTH` (2) - Pulse width modulation
- `IR_BIPHASIC` (3) - Biphase encoding
- `IR_BIPHASIC_INV` (4) - Inverted biphase encoding
- `IR_NRC` (5) - Nokia protocol (biphase with special start/repeat packets)
- `IR_RS5` (6) - Philips RC5 (with toggle bit at position 3)
- `IR_RS5X` (7) - Philips RC5X (with toggle bit at position 2)
- `IR_RS6` (8) - Philips RC6 (with toggle bit at position 5 and start signal)

**Protocol Auto-Detection**: If no protocol is specified, the RX class automatically detects the protocol by analyzing signal characteristics (pulse/pause durations, start/stop bits, toggle bits).

### Key Implementation Details

1. **Timing Resolution**: All timing values are stored in units of 50 microseconds (µs/50) to save memory while maintaining sufficient precision for IR signals.

2. **Packet Reception States** (IRRX_uint_READ_STATUS):
   - 0: No packets
   - 1: Receiving first packet
   - 2: First packet received
   - 3: Receiving second packet
   - 4: Second packet received
   - 5: Receiving/received subsequent packets
   - 6: Pause after last packet exceeds IR_INTERVAL_PRESS

3. **Repeat Packet Types**:
   - 0: No repeat packet
   - 1: Inverted bits
   - 2: Identical to main packet
   - 3: Unique repeat packet

4. **Protocol String Format**: Protocols are encoded as 26-character strings where each character's lower 6 bits contain protocol parameters (frequency, timing, flags, etc.).

## Quick Start

### Receiver (minimal example)
```cpp
#include <AlashIRControlRX.h>

AlashIRControlRX irReceiver(7);  // Pin 7 connected to IR receiver

void setup() {
  Serial.begin(9600);
  irReceiver.begin();
}

void loop() {
  if (irReceiver.check()) {  // Check for received IR data
    Serial.println(irReceiver.data, HEX);    // Print received code
    Serial.println(irReceiver.length);       // Print data length in bits
    Serial.println(irReceiver.key_press);    // 1=new press, 0=key hold
  }
}
```

### Transmitter (minimal example)
```cpp
#include <AlashIRControlTX.h>

AlashIRControlTX irTransmitter(2);  // Pin 2 connected to IR LED

void setup() {
  irTransmitter.begin();
}

void loop() {
  irTransmitter.send(0x00FFA25D);        // Send IR code
  // irTransmitter.send(0x00FFA25D, true); // With repeat packets on hold
  delay(1000);
}
```

## Default Configuration

**Receiver (RX)**:
- Auto-detect IR protocol
- Default carrier frequency: 37 kHz
- Signal inversion: `true` (default, can be set via constructor 2nd parameter)
- Automatically handles repeat packets for key hold detection

**Transmitter (TX)**:
- Default encoding: `IR_PAUSE_LENGTH` (pause length encoding)
- Default carrier frequency: 37 kHz (`frequency` property)
- Default data length: 32 bits (`length` property)
- Default packet interval: 20 ms
- Start/Stop bits: enabled by default

**Timing Constants**:
- `IR_INTERVAL_PACK` = 7 ms (minimum interval between packets)
- `IR_INTERVAL_PRESS` = 150 ms (minimum interval between key presses)

## Development Commands

This is an Arduino library, so it's typically used within the Arduino IDE or PlatformIO. There are no build commands at the repository level.

### Installation

1. **Arduino IDE**: Place the `AlashIRControl` folder in `~/Documents/Arduino/libraries/`
2. **PlatformIO**: Add to `lib_deps` in `platformio.ini`:
   ```
   lib_deps =
     https://github.com/Alash-electronics/AlashIRControl.git
   ```

### Using the Library

Include appropriate headers:
```cpp
#include <AlashIRControlRX.h>  // For IR receiver
#include <AlashIRControlTX.h>  // For IR transmitter
```

### Example Locations

The `examples/` directory is organized by language for international accessibility:

```
examples/
├── README.md (overview in 3 languages)
├── en/ (English examples)
├── ru/ (Russian examples)
└── kk/ (Kazakh examples)
```

Each language folder contains 10 identical examples with translated comments:
- **Basic receiver usage**: `receiverKeyPress`, `receiverKeyHold`
- **Protocol detection**: `receiverProtocol-Info`, `receiverProtocol-InfoAll`
- **Custom protocol setup**: `receiverSetProtokol`, `transmitterSetProtokol`
- **Transmitter usage**: `transmitterWithRetries`, `transmitterWithoutRetries`
- **Remote controller decoding**: `BlackRemoteControllerKeys`, `GrayRemoteControllerKeys`

**Note**: When creating new examples, add them to all three language folders with appropriate translations.

## Common Issues and Solutions

### 1. No Data Received
**Symptoms**: `irReceiver.check()` always returns false

**Solutions**:
- Verify wiring: IR receiver should have 5V, GND, and signal connected to correct pin
- Check signal inversion: Some IR receivers output inverted signals
  ```cpp
  AlashIRControlRX irReceiver(7, false);  // Try false instead of true
  ```
- Test with a known working remote control
- Verify the receiver is VS1838B or compatible (38 kHz carrier)

### 2. Timer Conflicts
**Symptoms**: Library doesn't work or causes other libraries to malfunction

**Problem**: The library uses hardware timers that may conflict with other libraries:
- **AVR** (UNO, NANO, MEGA): Uses Timer2 - conflicts with `tone()`, `Servo` library
- **ESP32**: Uses Timer 2
- **ESP8266**: Uses Timer 1

**Solutions**:
- Avoid using conflicting libraries simultaneously
- Use software alternatives (e.g., SoftwareServo instead of Servo)
- Modify other libraries to use different timers

### 3. Incorrect Decoding
**Symptoms**: Received codes are incorrect or inconsistent

**Solutions**:
- Allow auto-detection to run (don't set protocol manually unless necessary)
- If using custom protocol, verify protocol string is correct (26 characters, all starting with 0x4X)
- Check carrier frequency matches your remote (usually 36-38 kHz)
- Ensure adequate power supply (IR receivers are sensitive to voltage fluctuations)

### 4. Transmission Not Working
**Symptoms**: Remote devices don't respond to transmitted IR signals

**Solutions**:
- Verify IR LED polarity (cathode to GND, anode to pin through resistor)
- Check carrier frequency matches device: `irTransmitter.frequency = 38;` (in kHz)
- Ensure data length matches protocol: `irTransmitter.length = 32;`
- Test LED with visible light camera (phone camera) - should see purple/white glow
- Use appropriate current-limiting resistor (typically 100-330 Ω)

### 5. Platform-Specific Issues

**ESP32**: If compilation fails, ensure ESP32 board package is up to date (2.0.0+)

**ESP8266**: Timer conflicts are more common - avoid using alongside other interrupt-heavy libraries

**Arduino UNO R4**: Requires FspTimer library (included in board package)

## Important Notes for Modifications

1. **Interrupt Safety**: When modifying code that interacts with volatile variables in `AlashIRControl_VV`, ensure proper handling of race conditions. The timer interrupt runs at 20 kHz during reception.

2. **Memory Constraints**: The library is designed for memory-limited Arduino boards. Be mindful of:
   - Array sizes (IRRX_mass_PACK is 2x68 bytes)
   - Using 8-bit types where possible
   - The 50µs timing unit to compress values

3. **Platform Compatibility**: When adding features, test across platforms (AVR, ESP32, ESP8266, Renesas). Timer-related changes require updates in `AlashIRControlTimer.h`.

4. **Protocol Extensions**: To add new IR protocols:
   - Define new constant in AlashIRControl.h (like IR_NRC)
   - Add encoding/decoding logic in IRRX_func_DECODE() and IRTX_func_SEND()
   - Update protocol detection in IRRX_func_PROTOCOL()

5. **Comments**: The codebase extensively uses Russian comments. When adding features, maintain consistency with existing comment style and language.

## Known Code Issues

The following issues exist in the codebase and should be considered when making modifications:

### Critical Bugs

1. **Assignment vs Comparison Operator** (src/AlashIRControl.cpp:40) - ✅ **FIXED in v1.0.7**
   ```cpp
   // Was: IRRX_uint_CODING==IR_BIPHASIC; (comparison)
   // Fixed: IRRX_uint_CODING=IR_BIPHASIC; (assignment)
   ```
   **Impact**: Protocol now correctly switches to IR_BIPHASIC when NRC check fails.

### Code Quality Issues

2. **Blocking Busy-Wait Loops**
   - Line 20: `while(IRVV.IRRX_uint_READ_STATUS<4){}`
   - Line 373: `while(micros()<=k){}`

   **Impact**: Blocks program execution, wastes CPU cycles. Consider non-blocking alternatives or document this as expected behavior for timing precision.

3. **Extremely Long Lines**
   - Maximum line length: 674 characters
   - Many lines exceed 200+ characters

   **Impact**: Reduces code readability. Consider refactoring complex expressions.

4. **Complex Single-Line Logic**
   - Multiple nested ternary operators and conditions on single lines
   - Example: Line 241 contains a for loop, if statement, ternary operators, and bit operations all in one line

   **Recommendation**: Break complex logic into multiple lines for maintainability.

### Development Considerations

- These issues have been identified but not yet fixed to avoid breaking existing functionality
- When refactoring, ensure extensive testing across all supported platforms (AVR, ESP32, ESP8266, Renesas)
- The busy-wait loops may be intentional for timing precision - verify before changing
