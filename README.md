0.0237410071942446

ESP32 Voltage Measurement (12V Range)
Using an ESP32 to measure a range of DC voltages using a voltage divider add-on.

http://www.ohmslawcalculator.com/voltage-divider-calculator

                              ┌──────────────────
  ┌───────────────┐          ┌▼┐                │
  │               │          │ │                │  
  │     ESP32     │          │ │ 100 Ω          │
  │               │          └─┘                +
  │   GPIO 36/VP  │────────── │           ┌──▼─────▼───┐
  │               │           │           │   0 - 12V  │
  └───────────────┘          ┌▼┐          └────────────┘
         GND                 │ │                 _
          │                  │ │ 39 Ω            │
          │                  └─┘                 │
          │ ──────────────────│───────────────────

Vin = 12V
R1 = 100 Ω
R2 = 39 Ω

Vout = Vin X R2  
       ─────────
        (R1 + R2)
        
Vout = 12v X 39Ω      
       ─────────
      (100 Ω + 39Ω)
      
 Vout ≈ 3.368 ≈ 3.37V

       Vin
​  i = ────── 
      R1 + R2
