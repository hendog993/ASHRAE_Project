// Library preprocessor
#include <LiquidCrystal.h>
#include <dht.h>

// Constant declarations 
const int  DHT11_PIN = 13, ThermistorPin = A1, pin1 = 6, pin2 = 7, pin3 = 8, pin4 = 9;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const float c1 = 0.001129148, c2 = 0.000234125, c3 = 0.0000000876741; //steinhart-hart coeficients for thermistor
const int R1 = 10000; // value of R1 on board

// Creates an instance of the object lcd and dht 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
dht DHT;

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

  if (resistance < 180) {
    // This branch turns on the first LED, and prints to the LCD the quote and temp reading.
    // The temperature reading comes from pin A1, and gets converted from voltage to degrees C. 
    
    print_led_1();
    lcd_print("Temp in C:", temp_reading(analogRead(A1)));
  } 
  
  else if (resistance < 420) {
    // This branch turns on the second LED, and prints to the LCD the fahrenheit temp. 
    // Fahrenheit is obtained by grabbing the analog voltage from pin A1, and inputting 
    // that value into the "temp_reading" in the Bread.ino header file. Then, this 
    // Celsius value is converted to fahrenheit from another function in the Bread.ino.
  
    print_led_2();
    lcd_print("Temp in F:", celsius_to_fah(temp_reading(analogRead(A1))));  
  } 
  
  else if (resistance < 680) {
    // This branch turns on the third LED and prints the DHT sensor's temperature value. 
    // The chk value grabs the reading from pin 13 and gives the ability to use the 
    // DHT library function "temperature". 

    int chk = DHT.read11(DHT11_PIN);
    print_led_3();
    lcd_print("DHT Temp in C:", DHT.temperature);  
  }   
  
  else if (resistance < 900) {
    // This branch turns on the fourth LED and prints the DHT sensor's humidity value. 
    // The chk value grabs the reading from pin 13 and gives the ability to use the 
    // DHT library function "humidity". 
    
    int chk = DHT.read11(DHT11_PIN);
    print_led_4();
    lcd_print("Humidity:", DHT.humidity);  
  } 
  
  else { 
    led_off();
    lcd.clear();
    lcd.print("Idle");
    lcd.setCursor(0,1);
    lcd.print("BreadBoardBois");
  }
  delay(200);
}
