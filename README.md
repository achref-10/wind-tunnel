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

## 🔁 Working Principle

1. The operator sets the desired delay and run time on the relay module.
2. The module activates the fan after the delay and runs it for the configured time.
3. During fan activation, the Arduino reads force values from the sensors.
4. Data is displayed in real time on the LCD screen.

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
| Power Supply (12V DC)                   | 1   | Powers fan and relay                 |
| Breadboard or Custom PCB                | 1   | Wiring and component placement       |
| Jumper Wires, Screws, Frame             | —   | For connections and support          |

---

## 🛠️ Setup Instructions

### Hardware

- Connect fan power line through the relay switch
- Use Arduino to read both HX711 modules
- Mount load cells under a base holding the EV model
- Power the relay module using 12V
- Adjust relay timing using onboard buttons or serial commands (if supported)

### Software

1. Upload the Arduino sketch `main.ino`
2. Calibrate the HX711 load cells
3. Use the serial monitor to debug or test output

---

## 🧪 Test Procedure

1. Place the scaled EV model on the platform above load cells
2. Set relay delay (e.g., 3 seconds) and run time (e.g., 10 seconds)
3. Activate the system
4. Observe real-time force readings on the LCD
5. Compare wind-off and wind-on values for analysis

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

## 🤝 Credits

- **Hardware & Physical Wind Tunnel Setup:** [salim ammar]
- **Embedded System & Coding:** [Achref Abdellaoui](https://github.com/achrefabdellaoui)

---

## 📄 License

Open-source project licensed under MIT License.

---

## 📬 Contact

For inquiries or collaboration:

- Achref Abdellaoui – Embedded Systems Developer  
- 📧 [achrefabdelloui809@gmail.com](mailto:your.email@example.com)
- GitHub: [github.com/achrefabdellaoui](https://github.com/achrefabdellaoui)
