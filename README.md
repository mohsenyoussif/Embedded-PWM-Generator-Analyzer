# Embedded PWM Generator & Analyzer

## 📌 Project Overview
The **Embedded PWM Generator & Analyzer** is a simple system designed to generate a PWM signal using **Timer 0** of the ATmega32 microcontroller and analyze it using **Timer 1** with the help of **External Interrupt 0 (EXT0)**. The system measures and displays the **Period Time** and **Duty Cycle** of the generated signal on an **LCD screen**.

## 🎯 Features
- ✅ **PWM Signal Generation** using **Timer 0** (Fast PWM Mode).
- ✅ **Signal Measurement & Analysis** using **Timer 1** and **External Interrupt 0**.
- ✅ **Display of Period Time and ON Time** on an **LCD**.
- ✅ **Interrupt-Based Capturing** for accurate measurement.
- ✅ **Modular Design**, allowing future enhancements like UART communication.

---

## 🚀 How It Works
### **1️⃣ PWM Signal Generation**
- **Timer 0** is configured in **Fast PWM Mode**.
- The **PWM Period Time** is set to **256 µs**, and the **Duty Cycle** is set to **25%**.

### **2️⃣ Signal Measurement & Analysis**
- **Timer 1** is used to measure the signal.
- **External Interrupt 0 (EXT0)** triggers on **each rising and falling edge**.
- The system calculates:
  - **Period Time** (total cycle duration).
  - **ON Time** (high-level duration).

### **3️⃣ Display on LCD**
- Measured **Period Time** and **ON Time** are displayed on a **16x2 LCD**.

---

