# 🏎️ Super Bluetooth RC Car Project

Welcome to the **Bluetooth RC Car** project! This code helps you build a robot car that you can control with your smartphone. It uses an **Arduino**, an **L298N Motor Driver**, and a **Bluetooth Module**.

Ready to become a robotics engineer? Let's build! 

##  The Circuit Diagram
Here is the map to connect your wires. Be careful and follow the lines!

Motor Connection Circuit Diagram
![Motor_conection_circuit](https://raw.githubusercontent.com/ZAN-Tech-bd/RC-Car-Using-L298N-Motor-Driver/refs/heads/main/motor-connection.jpg)

![RC Car Circuit Diagram](https://raw.githubusercontent.com/ZAN-Tech-bd/RC-Car-Using-L298N-Motor-Driver/refs/heads/main/RC%20Car%20circuit%20diagrams.jpg)

##  What You Need (Parts List)
Before we start, make sure you have these parts:

- **Arduino Board** (Uno or Nano) - *The Brain* 
- **L298N Motor Driver** - *The Muscle*
- **Bluetooth Module** (HC-05 or HC-06) - *The Ears* 
- **4 x DC Motors** with Wheels - *The Legs* 
- **Battery Pack** (Li-ion or 9V) - *The Energy* 
- **Jumper Wires** - *The Nerves* 
- **Chassis** (The car body)

##  How to Connect (Pinout)

Use this table to connect the **L298N** to your **Arduino**:

| L298N Pin | Arduino Pin | What it does? |
| :--- | :--- | :--- |
| **ENA** | Pin **5** | Controls Speed (Motor A) |
| **IN1** | Pin **6** | Motor A Direction |
| **IN2** | Pin **7** | Motor A Direction |
| **IN3** | Pin **8** | Motor B Direction |
| **IN4** | Pin **9** | Motor B Direction |
| **ENB** | Pin **10** | Controls Speed (Motor B) |

**For the Bluetooth Module:**
* **VCC** -> 5V
* **GND** -> GND
* **TX** -> RX (Pin 0 on Arduino)
* **RX** -> TX (Pin 1 on Arduino)

> **⚠️ SUPER IMPORTANT TIP:** When you are uploading the code to the Arduino computer, **unplug the TX and RX wires**. Plug them back in after the upload is finished!

##  Secret Control Codes

You will need a **Bluetooth Car Controller App** on your phone. Set up the buttons to send these letters:

### Movement
| Key | Action | Icon |
| :--- | :--- | :--- |
| **F** | Move Forward | ⬆️ |
| **B** | Move Backward | ⬇️ |
| **L** | Turn Left | ⬅️ |
| **R** | Turn Right | ➡️ |
| **S** | Stop | 🛑 |

### Special Moves (Diagonals)
* **G** = Forward Left ↖️
* **I** = Forward Right ↗️
* **H** = Backward Left ↙️
* **J** = Backward Right ↘️

### Speed Control
* **1** (Slowest) to **9** (Fast)
* **q** = Maximum Speed (Turbo Mode!) 

## How to Install

1. Download and install the **Arduino IDE** on your computer.
2. Connect your Arduino board to the computer with a USB cable.
3. Copy the code from this repository.
4. Paste it into the Arduino IDE.
5. **Disconnect the Bluetooth TX/RX wires** (just for a second!).
6. Click the **Upload** (Arrow) button.
7. Reconnect the Bluetooth wires.
8. Power up your car using the batteries.

## Troubleshooting

* **The car isn't moving?** Check if your battery is charged. The L298N needs good power!
* **The wheels are spinning the wrong way?** Swap the wires on the motor that is spinning backwards.
* **The code won't upload?** Did you remember to unplug the Bluetooth TX/RX wires while uploading?


---

