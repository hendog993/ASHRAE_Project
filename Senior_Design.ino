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

int ktcSO = 6, ktcCS = 7, ktcCLK = 8;  // Declaration of thermocouple pins 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; // Declaration of LCD pins 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);   // Object declaration of LCD 
MAX6675 ktc(ktcCLK, ktcCS, ktcSO);    // Thermocouple declaration

// Initializations for the LEDs. (Might change this later and use diagram instead). 
short int led_row1 = 30, led_row2 = 32, led_row3 = 34, led_row4 = 36;
short int led_col1 = 31, led_col2 = 33, led_col3 = 35, led_col4 = 37;
// Buttons for high pressure and low pressure entry. 
short int high_pressure_button = 2, low_pressure_button = 3;

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
