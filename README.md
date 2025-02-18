# **Embedded PWM Generator & Analyzer**

## 📌 Project Overview  
The **Embedded PWM Generator & Analyzer** is a system designed to **generate, capture, and analyze PWM signals** using an **ATmega32 microcontroller**. It provides **both software-based and hardware-based** implementations to measure and display the **Period Time** and **Duty Cycle** of a generated signal on an **LCD screen**.

## 🎯 Features  
- ✅ **PWM Signal Generation** using **Timer 0** (Fast PWM Mode).  
- ✅ **Signal Measurement & Analysis** using **Timer 1** and **External Interrupt 0**.  
- ✅ **LCD Display** showing **Period Time and Duty Cycle**.  
- ✅ **Interrupt-Based Capturing** for high-precision measurement.  
- ✅ **Two Versions Available**:  
  - **Software-Based Version** (ICU implemented using external interrupt).  
  - **Hardware-Based Version** (ICU using Timer1’s Input Capture Unit).  

---

## 🚀 **How It Works**  

### **1️⃣ PWM Signal Generation**  
- **Timer 0** operates in **Fast PWM Mode**.  
- The **PWM Period Time** is set to **256 µs**, with a **Duty Cycle of 25%**.  
- The generated **PWM signal is fed to INT0** for analysis.  

### **2️⃣ Signal Measurement & Analysis**  
The system provides **two approaches** for capturing and analyzing the signal:  

#### 🔹 **Software-Based (External Interrupt ICU)**  
- **External Interrupt 0 (EXT0)** triggers on each **rising and falling edge**.  
- **Timer 1** measures the **Period Time and ON Time**.  

#### 🔹 **Hardware-Based (Timer1 ICU)**  
- Uses **Timer1's Input Capture Unit (ICU)** for **automatic edge detection**.  
- Provides **higher accuracy** and **reduced CPU overhead**.  

### **3️⃣ Display on LCD**  
- The measured **Period Time** and **Duty Cycle** are displayed on a **16x2 LCD**.  

---

