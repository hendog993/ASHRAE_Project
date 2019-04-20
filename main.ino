/* ==========================================================================
   =====================ASHRAE Senior Design Project=========================
   ======================Contributors: Henry Gilbert ========================
   ===================Yianni , Daniel Howard, Zach Newman ===================
   ==========================================================================
*/
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
 
// Declarations of thermocouple objects 1-8.
MAX6675 ktc1(ktc1CLK, ktc1CS, ktc1SO);
MAX6675 ktc2(ktc2CLK, ktc2CS, ktc2SO);
MAX6675 ktc3(ktc3CLK, ktc3CS, ktc3SO);
MAX6675 ktc4(ktc4CLK, ktc4CS, ktc4SO);
MAX6675 ktc5(ktc5CLK, ktc5CS, ktc5SO);
MAX6675 ktc6(ktc6CLK, ktc6CS, ktc6SO);
MAX6675 ktc7(ktc7CLK, ktc7CS, ktc7SO);
MAX6675 ktc8(ktc8CLK, ktc8CS, ktc8SO);

// Pointers and references for thermocouples. Used to address switch mode feature of compressors.
MAX6675 *ptrktc1 = &ktc1;
MAX6675 *ptrktc2 = &ktc2;
MAX6675 *ptrktc3 = &ktc3;
MAX6675 *ptrktc4 = &ktc4;
MAX6675 *ptrktc5 = &ktc5;
MAX6675 *ptrktc6 = &ktc6;
MAX6675 *ptrktc7 = &ktc7;
MAX6675 *ptrktc8 = &ktc8;

// Address by 0/1 row (scroll vs compressor) at the 0-3 index.
MAX6675 ptrKtc[2][4] = {
  {*ptrktc1, *ptrktc2, *ptrktc3, *ptrktc4},
  {*ptrktc5, *ptrktc6, *ptrktc7, *ptrktc8}
};

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
const short int capacitance_led = 9;
const short int power_led = 10;

// ========== BUTTON INPUTS ==========
// Buttons for high pressure and low pressure entry.
const short int high_pressure_switch = 12, low_pressure_switch = 11;

// ========== SWITCH input for recip vs scroll compressor
short int comp_mode_switch = 13;

// ========== CALCULATION VALUES ===========
// Variables for the interface and switch mode. 
int high_side_pressure = 0;
int low_side_pressure = 0;

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
  pinMode(capacitance_led, OUTPUT);
  pinMode(power_led, OUTPUT);

  // ======= BUTTON & SWITCH INPUTS ==========
  pinMode(high_pressure_switch, INPUT);
  pinMode(low_pressure_switch, INPUT);
  pinMode(comp_mode_switch, INPUT);
}

void loop() {
/*
 * How the loop works: all dependencies and methods. 
 */

  // Check the potentiometer for resistance input (0-1024)
  int main_resistance = analogRead(A0);
  Serial.println(main_resistance);
 
  // ============== MENU LOOP ==================
  // Check status of high pressure toggle switch. If high, open the menu.
  if (digitalRead(high_pressure_switch) == HIGH) {
    high_pressure_menu();
  }
  
  // Check status of low pressure toggle switch. If high, open the menu.
  if (digitalRead(low_pressure_switch) == HIGH) {
    low_pressure_menu();
  }

  // ============ MAIN LED LOOP ================
  // First potentiometer knob. Displays compressor mode and compressor outlet temperature.
  if (main_resistance < 100) {
    write_compressor_out_led();
    write_lcd("Compressor Temp", ptrKtc[digitalRead(comp_mode_switch)][0].readFahrenheit());
    lcd.print(" F");
  }

  // Displays high side pressure value, 0 if not input, and blue leds.
  else if (main_resistance < 213) {
    write_high_pressure_led();
    write_lcd("High Side P", high_side_pressure);
    lcd.print(" psi");
  }

  // Displays condenser outlet temerature and lights condenser out LED.
  else if (main_resistance < 327) {
    write_condenser_out_led();
    write_lcd("Condenser Out",  ptrKtc[digitalRead(comp_mode_switch)][1].readFahrenheit());
    lcd.print(" F");
  }

  // Displays metering device out temp and led
  else if (main_resistance < 446) {
    write_throttle_out_led();
    write_lcd("Throttle Out",  ptrKtc[digitalRead(comp_mode_switch)][2].readFahrenheit());
    lcd.print(" F");
  }

  // Lights low side pressure leds and displays, 0 if not entered, low side pressure.
  else if (main_resistance < 565) {
    write_low_pressure_led();
    write_lcd("Low Side P", low_side_pressure);
    lcd.print(" psi");
  }

  // Lights evaporator out LED, displays thermocouple temperature.
  else if (main_resistance < 684) {
    write_evaporator_out_led();
    write_lcd("Evaporator Out",  ptrKtc[digitalRead(comp_mode_switch)][3].readFahrenheit());
    lcd.print(" F");
  }

  // Writes MASS FLOW out and turns on first green light.
  else if (main_resistance < 803) {
    float MF_R[10] = {59.33840856, 1.006688227, 0.2030794489, 0.01488044391, 0.01294057197,
                  -0.00353467516, 4.25E-05, 3.13E-05, -6.69E-05, 8.47E-06 };
    float MF_SC[10] = {40.15698882, 1.096371113, 0.14024549, 0.015865756, 0.002097207,
                   -0.001690066, 9.03205E-05, -2.70756E-05, -1.35767E-05, 5.15408E-06 };
    float mass_flow_values[2] = {
      calculate(MF_R, ptrKtc[digitalRead(comp_mode_switch)][1].readFahrenheit(), ptrKtc[digitalRead(comp_mode_switch)][3].readFahrenheit()), 
      calculate(MF_SC, ptrKtc[digitalRead(comp_mode_switch)][1].readFahrenheit(),ptrKtc[digitalRead(comp_mode_switch)][3].readFahrenheit()) 
      };
    write_mass_flow_led();
    write_lcd("Mass Flow:", mass_flow_values[digitalRead(comp_mode_switch)]);
    lcd.print(" lbs/hr");
  }

  // Writes refrigerant CAPACITANCE out and lights second green led.
  else if (main_resistance < 919) {
    const float CAP_R[10] = {5897.679, 112.7528, 9.887627, 1.777997, 0.5887399, -0.4782697,
                   7.58E-04, -0.005700553, -0.00568108, 0.001614988 };
    const float CAP_SC[10] = {4433.99929, 107.9502108, -6.654767819, 2.002620595, -0.2210224213,
                    -0.1026412673, 0.002942954154, -0.00968481191, -0.0006961641807, 0.0002807495071 };
    write_capacitance_led();  
    float capacitance_values[2] = {
      calculate(CAP_R, ptrKtc[digitalRead(comp_mode_switch)][1].readFahrenheit(), ptrKtc[digitalRead(comp_mode_switch)][3].readFahrenheit()), 
      calculate(CAP_SC, ptrKtc[digitalRead(comp_mode_switch)][1].readFahrenheit(),ptrKtc[digitalRead(comp_mode_switch)][3].readFahrenheit()) 
      };
    // Named efficiency right now: Will change to capacitance, or whatever else down the road.
    write_lcd("Capacity:", capacitance_values[digitalRead(comp_mode_switch)]);
    lcd.print(" BTU/hr");
  }

  // Writes POWER output to LCD and lights third green LED.
  else if (main_resistance < 1000) {
    write_power_led();
    const float W_R[10] = {126.9581, -5.372865, 8.524027, -0.09801806, 0.1522044, -0.05396478,
                 -9.06E-04, 9.33E-04, -2.39E-04, 1.16E-04
                };
    const float W_SC[10] = {645.1275928, -2.295127832, -7.218567883, -0.005535838, 0.042861644,
                  0.076252192, 0.000563255, -0.000610193, 0.000112464, -0.000130886
                 };           
    float power_values[2] = {
      calculate(W_R, ptrKtc[digitalRead(comp_mode_switch)][1].readFahrenheit(), ptrKtc[digitalRead(comp_mode_switch)][3].readFahrenheit()), 
      calculate(W_SC, ptrKtc[digitalRead(comp_mode_switch)][1].readFahrenheit(),ptrKtc[digitalRead(comp_mode_switch)][3].readFahrenheit())
      };
    write_lcd("Power: ", power_values[digitalRead(comp_mode_switch)]);
    lcd.print(" Watts");
  }

  // Writes efficiency: 

  else if (main_resistance < 1024) {
        while (analogRead(A0) > 1005) {
      test_buttons();
    }
  }
  delay(450);
}
