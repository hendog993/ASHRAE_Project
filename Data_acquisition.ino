// Library preprocessor
#include <LiquidCrystal.h>

// Variable declarations 
int pin1 = 6;
int pin2 = 7;
int pin3 = 8;
int pin4 = 9;
int resistance = 0; // changes 
int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Creates an instance of the object lcd 

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  
}

// the loop function runs over and over again forever
void loop() {
  resistance = analogRead(A0);
  
  if (resistance < 250) {
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, LOW);
    lcd.clear();
    lcd.print("Pin 1");
  } 
  else if (resistance < 500) {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, LOW); 
    lcd.clear();
    lcd.print("Pin 2");             
  } 
  else if (resistance < 780) {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin4, LOW);
    lcd.clear();
    lcd.print("Pin 3");
  } 
  else if (resistance < 960) {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, HIGH);
    lcd.clear();
    lcd.print("Pin 4");
  } 
  else { 
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, LOW);
    lcd.clear();
    lcd.print("Idle");
  }
  delay(100);
}
