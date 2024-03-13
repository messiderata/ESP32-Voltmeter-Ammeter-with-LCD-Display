# ESP32 Voltage and Current Measurement 

This project utilizes an ESP32 microcontroller to measure both voltage and current using a voltage divider circuit. It includes a simple user interface displayed on a 16x2 LCD screen.

## Description 
The ESP32 microcontroller measures voltage and current using a voltage divider circuit. A momentary push button allows switching between voltage and current measurements. The measured values, within the range of 0 - 12V, are displayed on a Liquid Crystal Display (LCD).


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

The voltage calculation in a voltage divider circuit is determined by the following formula:

     Vout = Vin × (R2 / (R1 + R2))

Where:
- \( V_{out} \) is the output voltage.
- \( V_{in} \) is the input voltage.
- \( R1 \) is the resistance of the first resistor.
- \( R2 \) is the resistance of the second resistor.

This formula is based on Ohm's Law and the voltage divider principle. It calculates the voltage across \( R2 \) based on the input voltage \( V_{in} \) and the ratio of \( R2 \) to the total resistance \( (R1 + R2) \).

You can use this formula to compute the output voltage in your voltage divider circuit. Additionally, online tools like the Voltage Divider Calculator at ohmslawcalculator.com/voltage-divider-calculator can provide convenient ways to calculate voltage values based on resistor values and input voltage.

https://ohmslawcalculator.com/voltage-divider-calculator  
     
     
# Current Calculation
     I = Vout / R_total
# Components Used
    - ESP32 microcontroller
    - 16x2 LCD Screen
    - Resistors (R1, R2)
    - Momentary Push Button

# Wiring Diagram
![Alt text](https://github.com/messiderata/ESP32-Voltmeter-Ammeter-with-LCD-Display/blob/main/Wire%20diagram.png)
# Usage
    1. Upload the provided code to your ESP32 microcontroller.
    2. Connect the components as per the wiring diagram.
    3. Power on the circuit.
    4. Press the push button to switch between voltage and current measurements.
    5. Read the measured values displayed on the LCD screen.
