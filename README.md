# Bluetooth Controlled Arduino RC Car 

This project is a simple **Bluetooth-controlled RC car** built with:

- **Arduino Uno**
- **L298N dual H-bridge motor driver**
- **HC-05 Bluetooth module**
- **4 DC gear motors** (2 left, 2 right)
- **Battery pack** (for motors, and optionally the Arduino)

You can control the car from your phone (or any Bluetooth terminal app) using single-letter commands:
`F` = Forward, `B` = Backward, `L` = Left, `R` = Right, `S` = Stop.

---

## ✨ Features

- Control via **Bluetooth** (HC-05 + phone app)
- Simple **single-character commands**
- Uses `SoftwareSerial` so hardware serial (USB) is free for debugging
- Can drive **4 motors** using **L298N** (2 motors per side in parallel)
- Compatible with **Arduino Uno**

---

## 🧰 Hardware Required

- 1 × **Arduino Uno**
- 1 × **L298N motor driver module**
- 1 × **HC-05 Bluetooth module**
- 4 × **DC motors** (2 left side, 2 right side)
- 1 × **Battery pack** (e.g. 7.4–12 V for motors, depending on motor spec)
- Jumper wires
- Chassis, wheels, etc. (optional but recommended 😉)

---

## 🔌 Wiring / Circuit Diagram

### 1. Arduino ↔ L298N Motor Driver

**Control pins (Arduino → L298N)**

| Function            | Arduino Pin | L298N Pin |
|---------------------|------------:|-----------|
| Left motor IN1      | D8          | IN1       |
| Left motor IN2      | D9          | IN2       |
| Right motor IN3     | D10         | IN3       |
| Right motor IN4     | D11         | IN4       |

![RC Car Circuit Diagram](https://github.com/ZAN-Tech-bd/RC-Car-Using-L298N-Motor-Driver/blob/main/RC%20Car%20circuit%20diagrams.png?raw=true)

⚙️ **Speed control (optional)**  
If you want **full-speed always**, leave **ENA** and **ENB** jumpers in place on the L298N board.  
If you want **PWM speed control**, remove the jumpers and connect:

- ENA → any PWM pin (e.g. D5)
- ENB → any PWM pin (e.g. D6)

(Then you’d update the code to use `analogWrite()` on ENA/ENB.)

---

### 2. Motors ↔ L298N Outputs

We have **4 motors**: 2 on the left side, 2 on the right side.

You can connect them **in parallel** per side:

**Left side motors (2 motors):**

- Motor A (+) → L298N **OUT1**
- Motor A (–) → L298N **OUT2**
- Motor B (+) → L298N **OUT1** (same as A +)
- Motor B (–) → L298N **OUT2** (same as A –)

**Right side motors (2 motors):**

- Motor C (+) → L298N **OUT3**
- Motor C (–) → L298N **OUT4**
- Motor D (+) → L298N **OUT3** (same as C +)
- Motor D (–) → L298N **OUT4** (same as C –)

Make sure **left motors spin forward in the same direction**, and same for the right side.
If one motor spins backwards, reverse its two wires.

---

### 3. Power Connections

> ⚠️ Always **connect all grounds together**.

- Battery + (motors) → L298N **12V** (or +12V / V_IN, depending on board)
- Battery – → L298N **GND**
- L298N **GND** → Arduino **GND** (common ground)

You have 2 common options:

#### Option A: Separate Power
- Motors powered by battery (L298N 12V input).
- Arduino powered by **USB** or separate 5V source.
- L298N **5V_EN** jumper removed (depending on board).

#### Option B: L298N powers Arduino (only if your L298N supports 5V output)
- Battery to L298N 12V.
- L298N **5V OUT** → Arduino **5V** (or Vin depending on your board and module design).
- **Check your L298N board markings** before doing this.

---

### 4. HC-05 Bluetooth Module ↔ Arduino

| HC-05 Pin | Arduino Pin     | Notes                                                                 |
|-----------|------------------|-----------------------------------------------------------------------|
| VCC       | 5V               | Most HC-05 modules use 5V input                                      |
| GND       | GND              | Common ground                                                        |
| TXD       | D2 (Software RX) | Arduino **RX** for Bluetooth                                         |
| RXD       | D3 (Software TX) | Arduino **TX** for Bluetooth via a **voltage divider** recommended   |

> ⚠️ **Important:**  
> HC-05 RX is **3.3V logic**, Arduino D3 is **5V**.  
> Use a simple **voltage divider** (e.g. 1 kΩ + 2 kΩ) between **D3 → HC-05 RX**.

---

### 🧾 ASCII Circuit Overview (Logical)

```text
[ Phone ]
    │  Bluetooth
    ▼
[ HC-05 ]
   TX → Arduino D2 (BT RX)
   RX ← Arduino D3 (BT TX, via divider)

[ Arduino Uno ]
   D8  → L298N IN1
   D9  → L298N IN2
   D10 → L298N IN3
   D11 → L298N IN4
   GND ↔ L298N GND, HC-05 GND, Battery -

[ L298N ]
   OUT1/OUT2 → Left motors (2 in parallel)
   OUT3/OUT4 → Right motors (2 in parallel)
   12V  ← Battery +
   GND  ← Battery -, Arduino GND
   (5V OUT → Arduino 5V, *only if safe on your board*)



