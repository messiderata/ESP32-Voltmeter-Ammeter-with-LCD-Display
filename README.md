# ESP32 Voltage and Current Measurement 

This project utilizes an ESP32 microcontroller to measure both voltage and current using a voltage divider circuit. It includes a simple user interface displayed on a 16x2 LCD screen.

## Description 
The ESP32 microcontroller measures voltage and current using a voltage divider circuit. A momentary push button allows switching between voltage and current measurements. The measured values are displayed on a Liquid Crystal Display (LCD).

# Voltage Divider Circuit 
The voltage divider circuit consists of two resistors (R1 and R2) connected in series. The voltage to be measured is applied across R1, and the output voltage is taken from the junction of R1 and R2.  
 
                                ┌───────────────────  
    ┌───────────────┐          ┌▼┐                 │  
    │               │          │ │                 │  
    │     ESP32     │          │ │ 100 Ω           │
    │               │          └─┘                 +          
    │   GPIO 36/VP  │────────── │            ┌──▼─────▼───┐
    │               │           │            │   0 - 12V  │
    └───────────────┘          ┌▼┐           └────────────┘
           GND                 │ │                _
            │                  │ │ 39 Ω           │
            │                  └─┘                │
            │ ──────────────────│─────────────────
