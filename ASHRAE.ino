// Library preprocessor
#include <LiquidCrystal.h>
#include <dht.h>

// Constant declarations 
const int  DHT11_PIN = 13;
const int pin1 = 6;
const int pin2 = 7;
const int pin3 = 8;
const int pin4 = 9;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int ThermistorPin = A1;
const float c1 = 0.001129148, c2 = 0.000234125, c3 = 0.0000000876741; //steinhart-hart coeficients for thermistor
const float R1 = 10000; // value of R1 on board

// Creates an instance of the object lcd and dht 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
dht DHT;

// Function to convert the analog voltage to celsius temperature: used for analog temp not dht.
float temp_reading(int num) {
  float logR2, R2, T;
  int Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0); //calculate resistance on thermistor
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2)); // temperature in Kelvin
  T = T - 273.15; // This is converted to kelvin
  return T;
}

// Function to convert celsius to fahrenheit 
float celsius_to_fah(float cel) {
  float F =  (cel*9/5)+32;
  return F;
}

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

void loop() {

  // These values are calculated each time and refresh constantly. 
  int resistance = analogRead(A0);
  
  if (resistance < 250) {
    float temp_in_C = temp_reading(analogRead(A1));
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, LOW);
    lcd.clear();
    lcd.print("Temp in C:");
    lcd.setCursor(0,1);
    lcd.print(temp_in_C);
  } 
  else if (resistance < 500) {
    float temp_in_C = temp_reading(analogRead(A1));
    float fahrenheit = celsius_to_fah(temp_in_C);
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, LOW); 
    lcd.clear();
    lcd.print("Temp in F:");   
    lcd.setCursor(0,1);
    lcd.print(fahrenheit);          
  } 
  else if (resistance < 780) {
    int chk = DHT.read11(DHT11_PIN);
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin4, LOW);
    lcd.clear();
    lcd.print("Temperature = ");
    lcd.setCursor(0,1);
    lcd.println(DHT.temperature);
  } 
  else if (resistance < 960) {
    int chk = DHT.read11(DHT11_PIN);
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, HIGH);
    lcd.clear();
    lcd.print("Humidity = ");
    lcd.setCursor(0,1);
    lcd.println(DHT.humidity);
  } 
  else { 
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, LOW);
    lcd.clear();
    lcd.print("Idle");
    lcd.setCursor(0,1);
    lcd.print("BreadBoardBois");
  }
  delay(200);
}
