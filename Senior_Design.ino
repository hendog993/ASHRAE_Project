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

 /* Goals: Acquire 2 sets of 6 temperatures from refrigerants.
 *        Allow manual pressure input using knobs (pots or rotary) and a button. 
 *        Display interactive menu on LCD
 *        Calculate performance data on the LCD screen. 
 *        Switch to alternate between scroll compressor and reciprocating. 
 *        Wire an LED matrix of  lights to show which measurements are being taken. 
 *        INPUTS: Thermocouple temperatures, manual pressures, knobs for tuning digits, buttons for P. 
 *        OUTPUTS: LCD performance, LED matrix, 
 */

int ktc1SO = 30, ktc1CS = 31, ktc1CLK = 32;  // Declaration of thermocouple pins 
int ktc2SO = 33, ktc2CS = 34, ktc2CLK = 35;  // Declaration of thermocouple pins 
int ktc3SO = 36, ktc3CS = 37, ktc3CLK = 38;  // Declaration of thermocouple pins 
int ktc4SO = 39, ktc4CS = 40, ktc4CLK = 41;  // Declaration of thermocouple pins 
int ktc5SO = 42, ktc5CS = 43, ktc5CLK = 44;  // Declaration of thermocouple pins 
int ktc6SO = 45, ktc6CS = 46, ktc6CLK = 47;  // Declaration of thermocouple pins 

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; // Declaration of LCD pins 
LiquidCrystal lcd1(rs, en, d4, d5, d6, d7);   // Object declaration of LCD  
MAX6675 ktc1(ktc1CLK, ktc1CS, ktc1SO);    // Thermocouple declaration
MAX6675 ktc2(ktc2CLK, ktc2CS, ktc2SO);    // Thermocouple declaration
MAX6675 ktc3(ktc3CLK, ktc3CS, ktc3SO);    // Thermocouple declaration
MAX6675 ktc4(ktc4CLK, ktc4CS, ktc4SO);    // Thermocouple declaration
MAX6675 ktc5(ktc5CLK, ktc5CS, ktc5SO);    // Thermocouple declaration
MAX6675 ktc6(ktc6CLK, ktc6CS, ktc6SO);    // Thermocouple declaration

// Initializations for the LEDs. (Might change this later and use diagram instead). 
short int led_row1 = 2, led_row2 = 3, led_row3 = 4, led_row4 = 5;
short int led_col1 = 6, led_col2 = 7, led_col3 = 8, led_col4 = 9;
// Buttons for high pressure and low pressure entry. 
short int high_pressure_button = 10, low_pressure_button = 11;

// Main resistance knob input. Must go to analog input. 
int main_resistance; 
int high_side_pressure;
int low_side_pressure;
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
  // Setup for LED Matrix:
  pinMode(led_row1, OUTPUT);
  pinMode(led_row2, OUTPUT);
  pinMode(led_row3, OUTPUT);
  pinMode(led_row4, OUTPUT);
  pinMode(led_col1, OUTPUT);
  pinMode(led_col2, OUTPUT);
  pinMode(led_col3, OUTPUT);
  pinMode(led_col4, OUTPUT);
  pinMode(high_pressure_button, INPUT);
  pinMode(low_pressure_button, INPUT);
}

void loop() {
  main_resistance = analogRead(A0);
  // ktc.readCelsius(); reads celsius temperature. will be ktcx for different thermocouples 
  
  switch (switch_knob(main_resistance)) {
    case 1:
      break;
    case 2:
      break;
    case 3: 
      break;
    case 4:
      break;
    case 5: 
      break;
    case 6:
      break;
    case 7: 
      break;
    case 8:
      break;  
  } 
}
