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

---

## how to build it

<details> <summary>📋 Click to Expand Markdown Snippet</summary>

## 🛠️ How to Build

This section walks you through assembling the hardware, uploading the code, and getting the ESP32 fan controller up and running.

---

### ⚙️ Hardware Required

| Component                    | Notes                                  |
|-----------------------------|----------------------------------------|
| ESP32-WROOM-32 (Dev Board)  | With USB connection                    |
| DHT11 Temperature Sensor    | 3-pin module (VCC, DATA, GND)          |
| 12V PWM Fan                 | 4-pin PC fan                           |
| N-channel MOSFET module     | Logic-level (e.g., IRF520 or IRLZ44N) |
| Push Button + 10kΩ resistor | For mode toggle                        |
| LED + 220Ω resistor         | Shows current mode (AUTO = ON)        |
| 12V Power Supply (5A)       | To power all fans                      |
| Breadboard + jumper wires   | For prototyping                        |

---

### 🪛 Wiring Overview

| ESP32 Pin | Connects To              | Description                     |
|-----------|--------------------------|---------------------------------|
| GPIO 23   | MOSFET Gate (PWM control)| Controls fan speed              |
| GPIO 4    | DHT11 Data Pin           | Reads temperature               |
| GPIO 2    | Button (with pull-down)  | Toggles auto/manual mode        |
| GPIO 13   | LED (+ 220Ω resistor)    | Mode indicator                  |
| GND       | GND on all components    | Common ground                   |
| VIN or 3.3V | DHT11 VCC               | Power the temperature sensor    |

> ⚠️ DHT11 typically runs at 3.3V or 5V depending on module. Use the appropriate ESP32 pin.

---

### 💻 How to Upload Code

#### Option A: Using Arduino IDE
1. Open [Arduino IDE](https://www.arduino.cc/en/software)
2. Install **ESP32 board support** via Board Manager
3. Install libraries:
   - `DHT sensor library by Adafruit`
   - `Adafruit Unified Sensor`
4. Open `main.ino` from `code/src/`
5. Select Board: **ESP32 Dev Module**
6. Select the correct COM port
7. Click **Upload**

#### Option B: Using PlatformIO (Recommended)
1. Install [VS Code](https://code.visualstudio.com/)
2. Install the [PlatformIO extension](https://platformio.org/install)
3. Open the `code/` folder as a project
4. Click **PlatformIO: Upload**
5. Use the Serial Monitor to view logs and temperature readings

---

### ✅ Expected Serial Output

When wired and uploaded correctly, the Serial Monitor should print:

```
System started. Waiting for sensor...
Temperature: 28.90 °C
PWM Output: 132
```

Pressing the button should toggle between modes and print:

```
Mode toggled to: MANUAL
Mode toggled to: AUTO
```
</details>


## License

MIT