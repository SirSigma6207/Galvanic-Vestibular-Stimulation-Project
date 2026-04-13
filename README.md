# 🧠 Wireless GVS Simulation System

A wireless control system that demonstrates the principles of galvanic vestibular stimulation (GVS) using an ESP32, op-amp circuitry, and real-time input control.


## 🚀 Overview

This project implements a real-time system that converts user input into a controlled analog signal, which is then used to generate bidirectional current through an op-amp circuit, which furthur allows us to demonstrate the effects of Galvanic Vestibular Stimulation.

### Biological Aspect of GVS

GVS involves applying a small electrical signal near the mastoid areas behind the ears, where the vestibular nerves are located. These nerves carry balance and orientation information from the inner ear to the brain. The electrical signal changes the firing rates of the nerve endings—making one side more active and the other less active. This creates a mismatch in the signals sent to the brain, which it interprets as movement or a change in direction. As a result, the body may feel like it is tilting or shifting, showing how electrical stimulation can influence the balance system.

---
## 🧠 Working Principle

The ESP32 receives control input over WiFi and converts it into an analog voltage using its built-in DAC (GPIO 25).

A reference voltage of 1.65V is used as a virtual ground, representing the neutral state of the system. The op-amp (LM358), configured with negative feedback, continuously adjusts its output to keep its inputs balanced. In doing so, it converts the difference between the input voltage and the reference into a controlled current through the circuit.

A dual supply of ±9V is used to power the op-amp, providing sufficient headroom for the output to swing both above and below the reference level. This allows current to flow in both directions, which is essential for bidirectional operation.

During testing, the direction of this current determines the output:
- One LED lights up when the current flows in one direction 
- The other LED lights up when the current reverses
  
This behavior demonstrates controlled bidirectional current flow, analogous to the operation of a GVS system.

---

## ⚙️ System Architecture
Keyboard → Python (UDP) → WiFi → ESP32 → DAC → Op-Amp → LEDs


- **Input Layer**: Keyboard control (A/D keys)
- **Communication Layer**: UDP over WiFi
- **Embedded System**: ESP32
- **Analog Processing**: Op-amp (LM358)
- **Output Layer**: Directional LED indication



## 🔌 Hardware Components

- ESP32
- LM358 Op-Amp
- Resistors (500Ω)
- LEDs (2)  //testing purpouses
- Power Supply (±9V)
- Breadboard & wiring
- ECG patches
- Conductive Gel




## 💻 Software Components

### 🔹 Python Controller
- Reads keyboard input
- Sends real-time UDP packets

### 🔹 ESP32 Firmware
- Receives UDP data
- Outputs analog signal via DAC


## 📸 Demo

YOUTUBE: https://www.youtube.com/watch?v=t6M_l-YdFlc


## 🧠 Key Concepts

- Wireless embedded systems
- UDP communication
- Digital-to-Analog Conversion (DAC)
- Op-amp negative feedback
- Bidirectional current control

---

## ⚠️ Disclaimer

This project is a **simulation and demonstration system** intended for educational purposes.

It is **not a medical device**.  
Any real-world application involving human subjects must be conducted under proper supervision and safety protocols must be strictly adhered to when interfacing with biological systems.




