# Automatic-High-Beam-Control-Using-Arduino-Uno


# 🚘 Automatic High Beam Control System with Camera Detection

This project is designed to control a car's headlight beams automatically using a camera and Arduino Uno. It uses **computer vision (OpenCV)** to detect other vehicles from a webcam feed and sends signals to the Arduino to switch between high and low beams accordingly.

---

## 🔧 Features

- 🚗 **Car Detection** using OpenCV and Template Matching
- 🌗 **Automatic High/Low Beam Control**
- 💡 Real-time **Arduino PWM control** for LEDs (headlights simulation)
- 🌙 Works even at **nighttime** with grayscale detection

---

## 📁 Project Structure

├── Arduino
│ └── high_beam_control.ino # Final Arduino code
├── Python
│ └── camera_detection.py # Webcam-based vehicle detection
├── target_image1.jpeg # Template image of car (to detect)
├── README.md # Project documentation


---

## 🧠 How it Works

1. The Python script captures real-time video from a webcam.
2. It uses **template matching** to detect the presence of another car in the frame.
3. If a car is detected on:
   - Left → Sends `'L'` to Arduino (reduce left beam brightness)
   - Right → Sends `'R'` to Arduino (reduce right beam brightness)
   - Not Detected → Sends `'N'` (restore full beam)
4. The Arduino receives the signal and uses `analogWrite` to adjust LED brightness accordingly.

---

## 🛠️ Hardware Requirements

- Arduino Uno
- 4 x LEDs (simulate car headlights)
- Resistors (220Ω recommended)
- Jumper Wires
- Breadboard
- USB Cable to connect Arduino

### Wiring
- `ledPinR1` → Pin 9  
- `ledPinR2` → Pin 10  
- `ledPinL1` → Pin 11  
- `ledPinL2` → Pin 6

---

## 💻 Software Requirements

- **Arduino IDE** (for uploading `.ino` file)
- **Python 3.x**
- **OpenCV**: `pip install opencv-python`
- **NumPy**: `pip install numpy`
- **PySerial**: `pip install pyserial`

---

## 🚀 Getting Started

### Step 1: Upload Code to Arduino

- Open `high_beam_control.ino` in the Arduino IDE.
- Select the correct board and COM port.
- Upload the sketch.

### Step 2: Run Python Script

1. Make sure your webcam is connected.
2. Replace `'target_image1.jpeg'` with your own car template if needed.
3. In Python, edit the serial port if different:
   ```python
   ser = serial.Serial('COM4', 9600)

Shaik Faaz Ahmed
Electronics and Communication Engineering
Projects: Automatic High Beam Control
