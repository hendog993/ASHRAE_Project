/* ==========================================================================
 * =====================ASHRAE Senior Design Project=========================
 * ======================Contributors: Henry Gilbert ========================
 * ==========================================================================
 * ==========================================================================
 */ 


// Liquidcrystal.h  defines the LCD functions and classes.
// max6675.h defines the K-type thermocouple c
#include <LiquidCrystal.h>
#include <max6675.h>

// Thermocouple declarations for pins. 
const int ktc1SO = 22, ktc1CS = 24, ktc1CLK = 26;
const int ktc2SO = 23, ktc2CS = 25, ktc2CLK = 27;  
const int ktc3SO = 28, ktc3CS = 30, ktc3CLK = 32;  
const int ktc4SO = 29, ktc4CS = 31, ktc4CLK = 33;  
const int ktc5SO = 34, ktc5CS = 36, ktc5CLK = 38;  
const int ktc6SO = 35, ktc6CS = 37, ktc6CLK = 39;  
const int ktc7SO = 40, ktc7CS = 42, ktc7CLK = 44;
const int ktc8SO = 41, ktc8CS = 43, ktc8CLK = 45;

// LCD pinmode declaration. Bottom 3 set of pins on MEGA. 
const int rs = 48, en = 49, d4 = 50, d5 = 51, d6 = 52, d7 = 53;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);   // Object declaration of LCD  

// Declarations of thermocouples 1-8. 7-8 are optional. 
MAX6675 ktc1(ktc1CLK, ktc1CS, ktc1SO);
MAX6675 ktc2(ktc2CLK, ktc2CS, ktc2SO);    
MAX6675 ktc3(ktc3CLK, ktc3CS, ktc3SO);   
MAX6675 ktc4(ktc4CLK, ktc4CS, ktc4SO);    
MAX6675 ktc5(ktc5CLK, ktc5CS, ktc5SO);    
MAX6675 ktc6(ktc6CLK, ktc6CS, ktc6SO);    
MAX6675 ktc7(ktc7CLK, ktc7CS, ktc7SO); 
MAX6675 ktc8(ktc8CLK, ktc8CS, ktc8SO); 

// LED pins for pressure 
const int high_pressure_led = 2;
const int low_pressure_led = 3;

// LED pins for refrigerant. 
const int compressor_out = 4;
const int condenser_out = 5;
const int throttle_out = 6;
const int evaporator_out = 7;

// LED pins for performance
const int mass_flow_led = 8;
const int efficiency_led = 9; 

// Buttons for high pressure and low pressure entry. 
short int high_pressure_button = 46, low_pressure_button = 47;

// Variables for the interface. 
int main_resistance; 
int high_side_pressure;
int low_side_pressure;

// Derived values for the cycle. 
double mass_flow;
double efficiency;
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,4);
  lcd.clear();
  pinMode(high_pressure_led, OUTPUT);
  pinMode(low_pressure_led, OUTPUT);
  pinMode(compressor_out, OUTPUT);
  pinMode(condenser_out, OUTPUT);
  pinMode(throttle_out, OUTPUT);
  pinMode(evaporator_out, OUTPUT);
  pinMode(high_pressure_button, INPUT);
  pinMode(low_pressure_button, INPUT);
}

void loop() {
  main_resistance = analogRead(A0);
  // ktc.readCelsius(); reads celsius temperature. will be ktcx for different thermocouples 

  
  
  
  switch (switch_knob(main_resistance)) {
    case 1:
      // read compressor outlet, print compressor outlet thermocouple. 
      break;
    case 2:
      // Read high side from input: Possible interface? If not exists, prompt input. 
      break;
    case 3: 
          // Read condenser outlet, print condenser outlet thermocouple. 
      break;
    case 4:
          // Read throttle outlet, print throttle outlet thermocouple. 
      break;
    case 5: 
          // Read low side pressure outlet, flash LEDS, print to LCD. 
      break;
    case 6:
          // Read evaporator air outlet, print evaporator outlet thermocouple. 
      break;
    case 7: 
        // Display refrigeration efficiency to LCD. Flash central LED. 
      break;
    case 8:
        // Display refrigeration mass flow rate to LCD, flash central LED. 
      break;  
    case 9;
    break;
    case 10:
    break;
  } 
}
