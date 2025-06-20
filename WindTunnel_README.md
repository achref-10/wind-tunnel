
# 🌬️ Wind Tunnel Simulation for EV Aerodynamic Study

This project is part of our electric vehicle (EV) research. It simulates real aerodynamic conditions using a custom wind tunnel. The embedded system controls wind flow using a timed relay and measures the effect of wind on a scaled EV model using weight sensors.

This repository documents the **embedded control system**, developed using **Arduino** and a **Multifunction Trigger Delay Time Relay Module**.

---

## 🎯 Objective

- Simulate aerodynamic conditions to study airflow behavior on an EV model.
- Control wind flow duration using a timed relay module.
- Measure aerodynamic force in real time with load sensors.
- Display results on an LCD screen for immediate analysis.

---

## ⚙️ System Architecture

### 🧠 Controller: Arduino UNO

Responsible for:
- Reading data from **2 load cells** via **HX711 modules**
- Sending real-time data to an **LCD display**
- (Optional) Managing fan speed via **PWM** if needed

### 🌀 Wind Generation

- Controlled by a **Multifunction Trigger Delay Time Relay Module**
- The module allows for precise activation timing (e.g., delay + run duration)
- A **DC fan** is powered through the relay to simulate wind

### ⚖️ Force Measurement

- Two **load cells** are placed beneath the EV model
- Forces are converted to digital values using **HX711 modules**
- Results are averaged and displayed in grams or Newtons

### 📺 Display

- A **16x2 I2C LCD** shows:
  - Live aerodynamic force
  - Wind test status (running/stopped)
  - Optional: Timer countdown or test cycle info

---

## 📐 Physics Overview

The aerodynamic coefficients are calculated as follows:

```
Cl = (2 * Lift) / (ρ * V² * A)
Cd = (2 * Drag) / (ρ * V² * A)
```

Where:
- **Lift**, **Drag** = Measured in Newtons from load cells
- **ρ** = Air density (typically 1.225 kg/m³)
- **V** = Airspeed (m/s)
- **A** = Frontal area of model (m²)

---

## 🧪 How to Use

1. 📥 **Upload the code** to Arduino using the Arduino IDE.
2. 🖥️ Open the **Serial Monitor** at 9600 baud.
3. 🔌 Connect the fan and sensors, place the vehicle model in tunnel.
4. Send the following serial commands:

| Command | Action                            |
|---------|-----------------------------------|
| `s`     | Start fan speed test (measures RPM and air speed) |
| `d`     | Start aerodynamic test (measures lift/drag and calculates Cl/Cd) |
| `a`     | Export Cl and Cd repeatedly for MATLAB/Python logging |

---

## 📦 Bill of Materials

| Component                               | Qty | Description                          |
|----------------------------------------|-----|--------------------------------------|
| Arduino UNO                             | 1   | Microcontroller                      |
| HX711 Module                            | 2   | Amplifier for load cells             |
| Load Cell Sensor (strain gauge)         | 2   | For aerodynamic force measurement    |
| 16x2 LCD with I2C Adapter               | 1   | Display for sensor readings          |
| Multifunction Trigger Delay Relay Timer | 1   | For fan activation timing            |
| 12V DC Fan / Motor                      | 1   | Generates airflow                    |
| IR Sensor                               | 1   | Measures fan RPM                     |
| Power Supply (12V DC)                   | 1   | Powers fan and relay                 |
| Breadboard or Custom PCB                | 1   | Wiring and component placement       |
| Jumper Wires, Screws, Frame             | —   | For connections and support          |

---

## 📁 Files in This Repository

- `code/main.ino` – Arduino sketch for sensor reading and display
- `docs/schematic.png` – Wiring diagram
- `README.md` – Project documentation

---

## 🔭 Future Improvements

- Add **data logging to SD card** or via **Serial to PC**
- Implement **variable fan speed control via PWM**
- Plot live sensor values using **Python or MATLAB**
- Automate multi-cycle wind tests

---

## 📊 Sample Output (Serial Monitor)

```
Fan: 25.3 km/h
Air: 5.1 km/h
LIFT: 0.342 N
DRAG: 0.118 N
CL: 1.09
CD: 0.38
```

---

## 📃 License

Open-source project licensed under MIT License.

---

## 🤝 Credits

- **Hardware & Physical Wind Tunnel Setup:** salim ammar
- **Embedded System & Coding:** [Achref Abdellaoui](https://github.com/achrefabdellaoui)

---

## 📬 Contact

For inquiries or collaboration:

- Achref Abdellaoui – Embedded Systems Developer  
- 📧 achrefabdelloui809@gmail.com  
- GitHub: [github.com/achrefabdellaoui](https://github.com/achrefabdellaoui)
