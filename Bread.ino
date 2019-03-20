// Function to convert the analog voltage to celsius temperature: used for analog temp not dht.
// These values are initialized in the master.ino file, and defined in the scope here as well. 

float temp_reading(int num) {
  float logR2, R2, T;
  int Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0); //calculate resistance on thermistor
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2)); // temperature in Kelvin
  return T - 273.15; // This is converted to kelvin
}

// Function to convert celsius to fahrenheit 
float celsius_to_fah(float cel) {
  float F =  (cel*9/5)+32;
  return F;
}

// Functions to write a set of 4 LEDs. 
void print_led_1() {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}

void print_led_2() {
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}

void print_led_3() {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, LOW);
}

void print_led_4() {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
}

void led_off(){
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}

void lcd_print(const char* prompt, float value) {
  lcd.clear();
  lcd.print(prompt); // Not sure if println is needed for the first value. Test this. 
  lcd.setCursor(0,1);
  lcd.print(value);
}
