// Library preprocessor
#include <LiquidCrystal.h>
#include <dht.h>   
#include <max6675.h>

// Constant declarations 
const int  DHT11_PIN = 13, ThermistorPin = A1, led1 = 6, led2 = 7, led3 = 8, led4 = 9; 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; 
const float c1 = 0.001129148, c2 = 0.000234125, c3 = 0.0000000876741; //steinhart-hart coeficients for thermistor
const int R1 = 10000; // value of R1 on board
int ktcSO = 6;
int ktcCS = 7;
int ktcCLK = 8;
 
// Creates an instance of the object lcd and dht 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 
MAX6675 ktc(ktcCLK, ktcCS, ktcSO);
dht DHT; 

void setup() { 
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  delay(500);
}

void loop() {
  // lcd_print("Temp in C:", temp_reading(analogRead(A1)));
  lcd_print("Temp in F:", ktc.readFahrenheit());
  Serial.print("Deg C = "); 
  Serial.print(ktc.readCelsius());
  Serial.print("\t Deg F = ");
  Serial.println(ktc.readFahrenheit());
  delay(500);
}
