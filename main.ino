#include <LiquidCrystal.h>
#define LCD_COLUMNS 16
#define LCD_LINES 2

const int RW =  22;
const int E  =  21;
const int D4 =  5;
const int D5 =  18;
const int D6 =  23;
const int D7 =  19;

const int ANALOG_IN_PIN_V = 36;
const int buttonPin = 4;

float R1;
float R2;

const float maxVin = 12.0;
float vin = 0;
float vout = 0;
float valueV = 0;
float ave;

int ledState = LOW;
int lastState = LOW;
int count = 0;
int ledPin = 2;
LiquidCrystal lcd(RW,E,D4,D5,D6,D7);

void setup(){
  Serial.begin(9600);
  lcd.begin(LCD_COLUMNS, LCD_LINES);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}
void loop(){

  int currentState = digitalRead(buttonPin);
  if (currentState == LOW && lastState == HIGH){
    count ++;
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
  }
  lastState = currentState;
    if (count == 0) {
      lcd.setCursor(0,0);
      lcd.print("ADC-VOLTMETER &     ");
      lcd.setCursor(0,1);
      lcd.print("  CURRENTMETER");
    }
    // Measure voltage
    if (count == 1) {
      voltageCalculation(R1 = 39000.0, R2 = 37931);
    }
    // Measure current
    if (count == 2) {
      currentCalculation();
    }
    // Reset count
    if (count == 3) {
      count = 0;
    }
}

// Function to calculate voltage
void voltageCalculation(float resistor1, float resistor2) {
  valueV = analogRead(ANALOG_IN_PIN_V);
  uint8_t num_sample = 30;
  int sum = 0;
  while (0 < num_sample) {
    valueV = analogRead(ANALOG_IN_PIN_V);
    sum += valueV;
    num_sample --;
    delay(3);
  }
  ave = (float)sum / 30;
  vout = ave / 4095.0 * maxVin * R1 / R2;
  Serial.print(vout ,1);
  Serial.println("v");
  lcd.setCursor(0,0);
  lcd.print("Voltmeter               ");
  lcd.setCursor(0,1);
  lcd.print(vout, 1);
  lcd.print("V                        ");
  delay(50);
}
// Function to calculate current
void currentCalculation() {
    float current = vout / 139 * 1000;
    lcd.setCursor(0,0);
    lcd.print("Currentmeter               ");
    lcd.setCursor(0,1);
    lcd.print(current,3);
    lcd.print("mA");
    delay(50);
}


