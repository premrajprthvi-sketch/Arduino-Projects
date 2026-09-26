🌐 Arduino Ultrasonic Radar System

A real-time radar scanner built using Arduino, HC-SR04 ultrasonic sensor, SG90 servo motor, and a Processing-based GUI.

📌 Project Overview
This project creates a radar-like scanning system using an ultrasonic sensor mounted on a servo motor.
The sensor sweeps from 15° to 165°, measures distance, sends the data to the computer via Serial, and a Processing app displays a live radar visualization.
<img width="936" height="562" alt="resized-web-88c3ba0f-3e59-4099-9376-f575fbb17caa" src="https://github.com/user-attachments/assets/47837289-8c97-48d3-b625-c2a71c885607" />
Perfect for:
Robotics
Object detection
Security scanning
School/college projects

Learning serial communication
🚀 Features
✔ Real-time distance measurement
✔ 180° radar sweep
✔ Clean Processing UI visualization
✔ Object detection display
✔ Smooth servo movement
✔ Arduino ↔ PC serial communication
✔ Fully customizable angles, speed UI colors
📦 Hardware Required
Arduino Uno / Nano / Mega
HC-SR04 Ultrasonic Sensor
SG90 Servo Motor
Jumper wires
USB cable


⚙ How It Works
Servo rotates from 15° → 165°
At every angle, Arduino measures distance using HC-SR04
Arduino sends angle,distance. over serial
Processing reads & visualizes the data in radar style
📸 Project Demo
🏁 How to Run
![HC_SR04_w_MG90S_radar_w_plot](https://github.com/user-attachments/assets/d6bfe98d-f854-4069-91ab-1c7aa26665ed)

1️⃣ Upload Arduino code
Open Arduino IDE
Select correct board & port
Upload the .ino file
2️⃣ Run Processing code
Install Processing IDE
Install processing.serial.* library
Set correct COM port
Run the sketch
🎛 Customization
You can modify:
Radar color
Scan angle
Text style
Object detection range
Sweep speed
UI design
Ask CG (me) if you want a custom radar UI redesign.
