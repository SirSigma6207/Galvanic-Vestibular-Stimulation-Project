# 🧠 Wireless GVS Simulation System

A wireless control system that demonstrates the principles of galvanic vestibular stimulation (GVS) using an ESP32, op-amp circuitry, and real-time input control.

---

## 🚀 Overview

This project implements a real-time system that converts user input into a controlled analog signal, which is then used to generate bidirectional current through an op-amp circuit.

The system simulates the behavior of galvanic vestibular stimulation by producing directional current flow, visualized using LEDs.

---

## ⚙️ System Architecture
Keyboard → Python (UDP) → WiFi → ESP32 → DAC → Op-Amp → LEDs


- **Input Layer**: Keyboard control (A/D keys)
- **Communication Layer**: UDP over WiFi
- **Embedded System**: ESP32
- **Analog Processing**: Op-amp (LM358)
- **Output Layer**: Directional LED indication

---

## 🔌 Hardware Components

- ESP32
- LM358 Op-Amp
- Resistors (500Ω)
- LEDs (2)
- Power Supply (±9V)
- Breadboard & wiring

---

## 🧠 Working Principle

The ESP32 receives control input over WiFi and converts it into an analog voltage using its DAC.

A reference voltage of 1.65V is used as a virtual ground. The op-amp circuit, configured with negative feedback, converts the difference between the input voltage and the reference into a controlled current.

Depending on the direction of this current:
- One LED lights up for positive deviation
- The other LED lights up for negative deviation

This demonstrates bidirectional current flow similar to GVS systems.

---

## 💻 Software Components

### 🔹 Python Controller
- Reads keyboard input
- Sends real-time UDP packets

### 🔹 ESP32 Firmware
- Receives UDP data
- Outputs analog signal via DAC

---

## ⚠️ Disclaimer

This project is a **simulation and demonstration system** intended for educational purposes.

It is **not a medical device**.  
Any real-world application involving human subjects must be conducted under proper medical supervision and ethical approval.

---

## 📸 Demo

*(Add images or videos here)*

---

## 🧠 Key Concepts

- Wireless embedded systems
- UDP communication
- Digital-to-Analog Conversion (DAC)
- Op-amp negative feedback
- Bidirectional current control

---
