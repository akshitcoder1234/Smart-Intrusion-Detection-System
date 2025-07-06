# Smart-Intrusion-Detection-System
A simulation of a smart intrusion detection system using Wokwi and a cloud webhook.
# Smart Intrusion Detection System

This project is a simulation of a smart intrusion detection system that continuously detects human movement in a restricted area and sends real-time alerts.

## Aim

To design and simulate a smart security system that detects unauthorized human presence using a PIR motion sensor and immediately alerts security personnel via a cloud-based notification.

## Problem Statement

The objective is to simulate a smart intrusion detection system that:
a) Continuously detects human movement in a restricted area using a PIR sensor.
b) Provides real-time alerts to security personnel via the cloud when motion is detected, indicating unauthorized access.

## Scope of the Solution

* **Detection:** The system uses a Passive Infrared (PIR) sensor to detect motion.
* **Processing:** An ESP32 microcontroller processes the data from the sensor.
* **Alerting:** Upon detecting motion, the system sends a notification to a cloud service. For this simulation, we will use the Wokwi virtual environment to simulate a webhook trigger.
* **Indication:** An LED will light up to provide a local visual indication of motion detection.

## Required Components

### Hardware (Simulated)
* **ESP32 Microcontroller:** The main processor for the system.
* **PIR Motion Sensor:** To detect movement.
* **LED:** To act as a visual indicator.
* **Resistor:** A 220-ohm resistor for the LED.

### Software & Cloud Environment
* **Wokwi:** An online simulator for electronics and IoT projects.
* **Webhook.site (or similar):** To simulate a cloud endpoint that receives the alert from the ESP32.
* **Arduino IDE or PlatformIO:** For writing and compiling the C++ code for the ESP32.

---

## Flowchart of the Code
