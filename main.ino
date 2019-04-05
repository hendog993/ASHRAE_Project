/* ==========================================================================
   =====================ASHRAE Senior Design Project=========================
   ======================Contributors: Henry Gilbert ========================
   ===================Yianni , Daniel Howard, Zach Newman ===================
   ==========================================================================
*/

// Liquidcrystal.h  defines the LCD functions and classes.
// max6675.h defines the K-type thermocouple c
#include <LiquidCrystal.h>
#include <max6675.h>

// ========== THERMOCOUPLE VALUES ==========
// Thermocouple declarations for pins.
const short int ktc1SO = 22, ktc1CS = 24, ktc1CLK = 26;
const short int ktc2SO = 23, ktc2CS = 25, ktc2CLK = 27;
const short int ktc3SO = 28, ktc3CS = 30, ktc3CLK = 32;
const short int ktc4SO = 29, ktc4CS = 31, ktc4CLK = 33;
const short int ktc5SO = 34, ktc5CS = 36, ktc5CLK = 38;
const short int ktc6SO = 35, ktc6CS = 37, ktc6CLK = 39;
const short int ktc7SO = 40, ktc7CS = 42, ktc7CLK = 44;
const short int ktc8SO = 41, ktc8CS = 43, ktc8CLK = 45;

// Declarations of thermocouples 1-8. 7-8 are optional.
MAX6675 ktc1(ktc1CLK, ktc1CS, ktc1SO);
MAX6675 ktc2(ktc2CLK, ktc2CS, ktc2SO);
MAX6675 ktc3(ktc3CLK, ktc3CS, ktc3SO);
MAX6675 ktc4(ktc4CLK, ktc4CS, ktc4SO);
MAX6675 ktc5(ktc5CLK, ktc5CS, ktc5SO);
MAX6675 ktc6(ktc6CLK, ktc6CS, ktc6SO);
MAX6675 ktc7(ktc7CLK, ktc7CS, ktc7SO);
MAX6675 ktc8(ktc8CLK, ktc8CS, ktc8SO);

// ========== LCD SECTION ============
// Pin declarations and instance creation.
const short int rs = 48, en = 49, d4 = 50, d5 = 51, d6 = 52, d7 = 53;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// ========== LED SECTION ==========
// LED pins for pressure
const short int low_pressure_led = 4;
const short int high_pressure_led = 5;

// LED pins for refrigerant.
const short int compressor_out = 3;
const short int condenser_out = 6;
const short int evaporator_out = 7;
const short int throttle_out = 2;

// LED pins for performance
const short int mass_flow_led = 8;
const short int efficiency_led = 9;
const short int power_led = 10;

// ========== BUTTON INPUTS ==========
// Buttons for high pressure and low pressure entry.
const short int high_pressure_button = 11, low_pressure_button = 12;


// ========== SWITCH input for recip vs scroll compressor
short int comp_mode_switch = 13;

// ========== CALCULATION VALUES ===========
// Variables for the interface.
int high_side_pressure = 0;
int low_side_pressure = 0;

// Derived values for the cycle.
double mass_flow = 0;
double efficiency = 0;
double power = 0;

// ============= COMPRESSOR MODE ===============
// 2D array for refrigeration modes
char * compressor_mode[] = {"Reciprocating", "Scroll"};

void setup() {
  Serial.begin(9600);
  lcd.begin(20, 4);
  lcd.clear();

  //======== LED OUTPUTS ========
  pinMode(high_pressure_led, OUTPUT);
  pinMode(low_pressure_led, OUTPUT);
  pinMode(compressor_out, OUTPUT);
  pinMode(condenser_out, OUTPUT);
  pinMode(throttle_out, OUTPUT);
  pinMode(evaporator_out, OUTPUT);
  pinMode(mass_flow_led, OUTPUT);
  pinMode(efficiency_led, OUTPUT);
  pinMode(power_led, OUTPUT);

  // ======= BUTTON & SWITCH INPUTS ==========
  pinMode(high_pressure_button, INPUT);
  pinMode(low_pressure_button, INPUT);
  pinMode(comp_mode_switch, INPUT);
}

void loop() {
  // Check the potentiometer for rotary input.
  int main_resistance = analogRead(A0);


  // ============== MENU LOOP ==================
  // Check the status of the high pressure killswitch. If low, open the menu.
  if (digitalRead(high_pressure_button) == LOW) {
    high_side_pressure = high_pressure_menu();
  }

  // Check the status of the low pressure killswitch. If low, open the menu.
  if (digitalRead(low_pressure_button) == LOW) {
    low_side_pressure = low_pressure_menu();
  }


  // ============ MAIN LED LOOP ================
  // First potentiometer knob. Displays compressor mode and compressor outlet temperature.
  if (main_resistance < 5) {
    write_compressor_out_led();
    write_lcd("Compressor Temp", ktc1.readCelsius());
    lcd.print("C");
  }

  else if (main_resistance < 45) {
    write_high_pressure_led();
    write_lcd("High Side P", high_side_pressure);
  }

  else if (main_resistance < 160) {
    write_condenser_out_led();
    write_lcd("Condenser Out", ktc2.readCelsius());
    lcd.print("C");
  }

  else if (main_resistance < 270) {
    write_throttle_out_led();
    write_lcd("Throttle Out", ktc3.readCelsius());
    lcd.print("C");
  }

  else if (main_resistance < 400) {
    write_low_pressure_led();
    write_lcd("Low Side P", low_side_pressure);
    lcd.print("kPa");
  }

  else if (main_resistance < 515) {
    write_evaporator_out_led();
    write_lcd("Evaporator Out", ktc4.readCelsius());
  }

  else if (main_resistance < 635) {
    write_mass_flow_led();
    write_lcd("Mass flow", mass_flow);
    lcd.print("kg/s");
  }

  else if (main_resistance < 760) {
    write_efficiency_led();
    write_lcd("Efficiency:", efficiency);
  }

  else if (main_resistance < 880) {
    write_power_led();
    write_lcd("Power", power);
    lcd.print("KW");
  }

  else if (main_resistance < 1024) {
    test_buttons();
  }

  delay(200);
}
