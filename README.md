# ESP32 Voltage and Current Measurement 

This project utilizes an ESP32 microcontroller to measure both voltage and current using a voltage divider circuit. It includes a simple user interface displayed on a 16x2 LCD screen.

## Description 
The ESP32 microcontroller measures voltage and current using a voltage divider circuit. A momentary push button allows switching between voltage and current measurements. The measured values are displayed on a Liquid Crystal Display (LCD).

# Voltage Divider Circuit 
The voltage divider circuit consists of two resistors (R1 and R2) connected in series. The voltage to be measured is applied across R1, and the output voltage is taken from the junction of R1 and R2.  


                                       V1 = 8.63V
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
            │                  └─┘     V2= 3.37V  │
            │ ──────────────────│─────────────────
              <------- I ≈ 0.086mA  

# Voltage Calculation Formula:
     Vout = Vin × R2 / (R1 + R2))
     
# Current Calculation
     I = Vout / R_total
# Components Used
    - ESP32 microcontroller
    - 16x2 LCD Screen
    - Resistors (R1, R2)
    - Momentary Push Button
# Usage
    1. Upload the provided code to your ESP32 microcontroller.
    2. Connect the components as per the wiring diagram.
    3. Power on the circuit.
    4. Press the push button to switch between voltage and current measurements.
    5. Read the measured values displayed on the LCD screen.
