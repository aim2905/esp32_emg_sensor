# Design of an EMG System | IEEE EMBS Project

## Project Overview
The project was developed during my freshman year at the **University of Patras** as a collaborative effort within the **IEEE EMBS Student Branch Chapter**.

While the overall project involved a team of three, this repository specifically showcases my contribution: **the software architecture and real-time digital signal processing.** The project serves as a practical application of biomedical engineering principles, focusing on real-time muscle activity monitoring.

## Team & Roles
The project was a result of a team collaboration:
* **Software & Firmware (My Role):** Developed the C/C++ logic for signal acquisition, rectification, and envelope detection on the ESP32.
* **Hardware & PCB Design:** Designed by team members, focusing on the analog front-end and signal amplification.
* **Systems Integration:** Collaborative testing and validation of the end-to-end system.

## Technical Features (Firmware)
The code implements a real-time processing pipeline for raw analog bio-signals:
* **ADC Scaling:** Converts 12-bit raw ADC values from the ESP32 (0-4095) to actual voltage levels (0-3.3V).
* **Full-Wave Rectification:** Pure C implementation of signal rectification using `fabsf`.
* **Envelope Detection (LPF):** Implemented a **Low-Pass Filter (LPF)** using an exponential moving average (Alpha-filter) to extract the signal envelope.
* **Modular Design:** The processing logic is decoupled from the main hardware loop (`emg_proc.h/c`), allowing for easy testing and scalability.

## 🛠️ Code Structure
* `emg_main.c`: The main entry point (Arduino-based) that handles sensor sampling and data visualization.
* `emg_proc.c`: Core signal processing algorithms (Rectifier, Envelope Detector).
* `emg_proc.h`: Header file defining the `ProcessedEMG` data structure and function prototypes.
  
## Signal Processing Pipeline
```mermaid
graph LR
    A[Raw Analog Signal] --> B[12-bit ADC Conversion]
    B --> C[Voltage Scaling]
    C --> D[Full-Wave Rectification]
    D --> E[Envelope Detection - LPF]
    E --> F[Serial Plotter Output]
```

## Media
![photo_5780647426753498296_w](https://github.com/user-attachments/assets/816d605a-2332-457d-9ded-953f7cdcc3ff)


## About Me
**Aimilia Saranti**
Undergraduate ECE Student @ University of Patras
**HR Head** at IEEE Student Branch UPatras
*Passionate about the intersection of Engineering and Medicine.*

Connect with me on [LinkedIn](https://www.linkedin.com/in/aimilia-saranti-733180390)!

---
*Developed under the auspices of IEEE EMBS University of Patras Student Branch.*
