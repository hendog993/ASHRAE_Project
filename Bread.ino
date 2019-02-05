// Function to convert the analog voltage to celsius temperature: used for analog temp not dht.
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
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
}

void print_led_2() {
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
}

void print_led_3() {
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, LOW);
}

void print_led_4() {
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, HIGH);
}

void led_off(){
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
}


void lcd_print_2line(char statement) {
  
}
