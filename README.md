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
   
    Vin = 12V
    R1 = 100 Ω
    R2 = 39 Ω
    R_total = R1 + R2
            = 100Ω + 39Ω
            = 139Ω
    
    Vout = Vin X R2  
       ─────────
        (R1 + R2)
        
    Vout = 12v X 39Ω
       ─────────
      (100 Ω + 39Ω)
    ┌──────────────────────┐ 
    │ Vout ≈ 3.368 ≈ 3.37V │
    └──────────────────────┘
           Vout
    i = ─────────
         R_total
     
           12
    i = ─────────
           139Ω
    ┌──────────────────────┐ 
    │     I ≈ 0.086mA      │
    └──────────────────────┘

    V1 = (R1)(I)
    V1 = (100)(0.086)
    ┌──────────────────────┐ 
    │    V1 = 8.6V         │
    └──────────────────────┘

    V2 = (R2)(I)
    V2 = (39)(0.086)
    ┌──────────────────────┐ 
    │    V2 = 3.4          │
    └──────────────────────┘

    
    V = 8.6 + 3.4
    ┌──────────────────────┐ 
    │    V2 = 12           │
    └──────────────────────┘
    
