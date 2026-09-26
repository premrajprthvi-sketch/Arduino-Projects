# 🤖 Obstacle Avoiding Robot

An autonomous mobile robot built using **Arduino Uno**, an **ultrasonic sensor**, and a **motor driver**. The robot continuously detects obstacles in its path and automatically changes direction to avoid collisions.

---

## 📌 Overview

This project demonstrates the fundamentals of autonomous robotics using embedded systems.

The ultrasonic sensor continuously measures the distance in front of the robot. When an obstacle is detected within a predefined distance, the Arduino stops the robot, changes its direction, and continues moving.

The system is designed to operate without manual control once started.

---

## ⚙️ How It Works

```text
        ┌─────────────────┐
        │  Ultrasonic     │
        │     Sensor      │
        └────────┬────────┘
                 │ Distance
                 ▼
        ┌─────────────────┐
        │   Arduino Uno   │
        │  Decision Logic │
        └────────┬────────┘
                 │ Motor Commands
                 ▼
        ┌─────────────────┐
        │   Motor Driver  │
        └────────┬────────┘
                 │
          ┌──────┴──────┐
          ▼             ▼
       Motor L        Motor R
