# Bluetooth PWM-Controlled Arduino RC Car  
### Arduino Uno + L298N + HC-05 + PWM Speed Control

This project is a **Bluetooth-controlled RC car** built using:

- Arduino Uno  
- L298N Motor Driver  
- HC-05 Bluetooth Module  
- 2 DC motors (left & right) or 4 motors (2 per side, in parallel)  
- PWM speed control (three levels: 1, 2, 3)

Control commands are sent over Bluetooth using any Bluetooth Terminal app.

---

## 🧠 Features

- ✔️ Forward & backward with **PWM speed control**
- ✔️ Left & right turning
- ✔️ Bluetooth Serial control via **HC-05**
- ✔️ 3 speed levels: **Low (1), Medium (2), High (3)**
- ✔️ Uses `SoftwareSerial` so USB Serial is free for debugging

---

## 📡 Bluetooth Commands

Send **2-character commands**:

| Command | Action |
|--------|--------|
| `F1`   | Forward (slow) |
| `F2`   | Forward (medium) |
| `F3`   | Forward (fast) |
| `B1`   | Backward (slow) |
| `B2`   | Backward (medium) |
| `B3`   | Backward (fast) |
| `L` + any digit | Turn Left |
| `R` + any digit | Turn Right |
| `S?`  | Stop (any second char ignored) |

Example from phone Bluetooth terminal:  
F3
L1
S0


---

# 🛠 Hardware & Wiring

## 🧰 Required Components

- **Arduino Uno**
- **L298N Dual H-Bridge Motor Driver**
- **HC-05 Bluetooth Module**
- **2 or 4 Gear Motors**
- **Battery Pack** (7.4V–12V recommended for motors)
- Jumper wires

---

# 🔌 Wiring Diagram (Text Version)

### ## Arduino → L298N Connections

### Left Motor Control  
| Arduino Pin | L298N Pin | Function |
|-------------|-----------|----------|
| D5 (PWM)    | ENA       | Speed control (Left motor) |
| D8          | IN1       | Direction |
| D9          | IN2       | Direction |

### Right Motor Control  
| Arduino Pin | L298N Pin | Function |
|-------------|-----------|----------|
| D6 (PWM)    | ENB       | Speed control (Right motor) |
| D10         | IN3       | Direction |
| D11         | IN4       | Direction |

---

## ⚙️ Motor Output Wiring (L298N → Motors)

### Left side motors (1 or 2 motors)
- OUT1 → Left Motor +
- OUT2 → Left Motor −

### Right side motors (1 or 2 motors)
- OUT3 → Right Motor +
- OUT4 → Right Motor −

*(If using 2 motors per side, connect motors in parallel.)*

---

## 🔋 Power Wiring

| L298N Pin | Connection |
|-----------|------------|
| **12V**   | Battery + |
| **GND**   | Battery − |
| **5V OUT** | (Optional) Arduino 5V input **only if jumper is installed** |
| **GND**   | Must connect to Arduino GND |

⚠️ **COMMON GROUND IS REQUIRED**  
Battery GND → L298N GND → Arduino GND → HC-05 GND

---

# 📡 HC-05 Bluetooth Module Wiring

| HC-05 Pin | Arduino Pin |
|-----------|-------------|
| VCC       | 5V |
| GND       | GND |
| TXD       | D2 (SoftwareSerial RX) |
| RXD       | D3 (SoftwareSerial TX, via voltage divider) |

### 🔽 Voltage Divider for HC-05 RX  
Arduino D3 → 1 kΩ → HC-05 RX  
HC-05 RX → 2 kΩ → GND  

(Ensures safe 3.3V signal.)

---

