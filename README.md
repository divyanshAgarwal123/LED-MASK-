# 🎭 LED Mask Project  

This is an **Arduino-powered LED mask** inspired by [BoyWithUke](https://boywithuke.com/) 🎶. It features animated **LED eyes** and a **smile**, activated using an **ultrasonic sensor**.

## 🛠️ Components Used  
- **Arduino Nano**  
- **5 LED Matrix Displays (8x8)**  
- **Ultrasonic Sensor**  
- **Jump Wires & Resistors**

## 🔌 Wiring Diagram  
<img width="313" alt="Screenshot 2025-02-07 at 10 09 49 PM" src="https://github.com/user-attachments/assets/be36f49c-3193-4275-8c4c-176da091de9b" />
	•	Connect VCC of MAX7219 & Ultrasonic Sensor to 5V on Nano
	•	Connect GND of MAX7219 & Ultrasonic Sensor to GND on Nano
 
 ##🚀 How to Upload & Run
	1.	Install Arduino IDE.
	2.	Add MD_Parola and MD_MAX72XX libraries in Arduino IDE.
	3.	Connect Arduino Nano to your PC.
	4.	Open LED_Matrix_Eyes2.ino → Select Nano Board & Port → Click Upload.
	5.	Open LED_Matrix_Smile1.ino → Upload it the same way.
	6.	Power the setup → Enjoy your LED Mask!

## 🚀 Features  
✅ **Dynamic LED eyes** 👀  
✅ **Animated smile** 😀  
✅ **Auto-activation with ultrasonic sensor** 🛑  
✅ **USB-powered** 🔌  

## 🖼️ Preview  
![LED Mask] https://github.com/divyanshAgarwal123/LED-MASK-/blob/main/eyes_working.mp4

## 🔧 How It Works  
1. The **LED_Matrix_Eyes2.ino** code controls the LED matrices for eye animations.  
2. The **LED_Matrix_Smile1.ino** handles the smile animation.  
3. The **ultrasonic sensor** detects when someone is near and **turns on/off the mask**.  

## 📜 Code  
- `LED_Matrix_Eyes2.ino` → Handles **eye movement**  
- `LED_Matrix_Smile1.ino` → Controls **smile animations**  

## 💡 Inspiration  
Inspired by **BoyWithUke**, an artist known for wearing a unique LED mask. This project brings his signature look to life using **Arduino and electronics**.  

## 📥 Installation  
1. Clone the repo:  
   ```sh
   git clone https://github.com/divyanshAgarwal123/LED-Mask.git
