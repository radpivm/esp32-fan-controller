# ESP32 Fan Controller

This project is a microcontroller-based smart fan controller using an ESP32, a DHT11 temperature sensor, and a PWM-controlled 12V fan. The system automatically adjusts fan speed based on temperature and includes a manual override button with mode indicator LED.

## Features

- Temperature-based fan speed control (PWM)
- Manual override mode with fixed speed
- Mode LED indicator (AUTO = ON, MANUAL = OFF)
- Serial Monitor debugging output

## Hardware Used

- ESP32-WROOM-32U
- DHT11 Temperature Sensor Module (3-pin)
- 12V PWM Fan
- Logic-level MOSFET
- Push button
- LED + resistor
- Breadboard and jumper wires
- 12V Power Supply

## Wiring

Refer to the wiring diagrams in the `docs/` folder (not included in ZIP).

## PlatformIO Setup

```ini
[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino
monitor_speed = 115200
upload_speed = 921600
build_flags =
    -D LED_BUILTIN=2

lib_deps =
    adafruit/DHT sensor library@^1.4.4
    adafruit/Adafruit Unified Sensor@^1.1.6
```

## Roadmap

- [x] Basic PWM control
- [x] Auto vs Manual toggle button
- [x] Temp-based fan speed with DHT11
- [ ] Add OLED display (Next)
- [ ] Integrate with Home Assistant
- [ ] ESPHome version with YAML config
- [ ] Case design for 3D printing

## License

MIT