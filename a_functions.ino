// Performance: gets all temperatures and pressures and calculates performance.
// Conditional if statements to allow for selecting measurements with potentiometer.
// =====================================================================================
// ORDER: MF, CAP, POWER, CURRENT. Recip 0 scr 1.
// Coeffients for Reciprocating


// Pointer tables for choosing the right coefficients in derived calculation.
// To calculate, input the correct coeff based on switch value, and TE and TC.
float calculate(float c[], float tc, float te) {
    return  c[0] + c[1]*te + c[2]*tc + c[3]*pow(te, 2) + c[4]*te*tc +
    c[5]*pow(tc, 2) + c[6]*pow(te, 3) + c[7]*tc*pow(te, 2) + c[8]*te*pow(tc, 2) + c[9]*pow(tc, 3);
  }

  // ================ MENUS ==============
void high_pressure_menu() {
    while (digitalRead(high_pressure_switch) == HIGH) {
      lcd.clear();
      lcd.print("Enter HIGH P");
      lcd.setCursor(0, 2);
      lcd.print(resistance_to_integer(analogRead(A0)));
      lcd.print(" psig");
      lcd.setCursor(0,3);
      lcd.print(resistance_to_integer(analogRead(A0)) + 14.7);
      lcd.print(" psia");
      delay(400);
    }
    high_side_pressure = resistance_to_integer(analogRead(A0));
  }

void low_pressure_menu() {
    while (digitalRead(low_pressure_switch) == HIGH) {
      lcd.clear();
      lcd.print("Enter LOW P");
      lcd.setCursor(0, 2);
      lcd.print(resistance_to_integer(analogRead(A0)));
      lcd.print(" psig");
      lcd.setCursor(0,3);
      lcd.print(resistance_to_integer(analogRead(A0)) + 14.7);
      lcd.print(" psia");
      delay(400);
    }
    low_side_pressure = resistance_to_integer(analogRead(A0));
  }

  // Convert resistance to integer values for pressure menus.
  int resistance_to_integer(int resistance) {
    return .68 * (resistance) + 100;
  }

  // Write the LCD with basic prompts.
  // Accepts two inputs and always outputs the compressor mode as the first line on screen. 
  void write_lcd(const char* prompt, int measurement) {
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print(compressor_mode[digitalRead(comp_mode_switch)]);  // Reads the 0 or 1 value for switch to the compressor mode.
    lcd.setCursor(0, 2);
    lcd.print(prompt);
    lcd.setCursor(0, 3);
    lcd.print(measurement);
  }

void all_off() {
    digitalWrite(high_pressure_led, LOW);
    digitalWrite(low_pressure_led, LOW);
    digitalWrite(compressor_out, LOW);
    digitalWrite(condenser_out, LOW);
    digitalWrite(throttle_out, LOW);
    digitalWrite(evaporator_out, LOW);
    digitalWrite(mass_flow_led, LOW);
    digitalWrite(capacitance_led, LOW);
    digitalWrite(power_led, LOW);
}

void all_on(){
  digitalWrite(high_pressure_led, HIGH);
    digitalWrite(low_pressure_led, HIGH);
    digitalWrite(compressor_out, HIGH);
    digitalWrite(condenser_out, HIGH);
    digitalWrite(throttle_out, HIGH);
    digitalWrite(evaporator_out, HIGH);
    digitalWrite(mass_flow_led, HIGH);
    digitalWrite(capacitance_led, HIGH);
    digitalWrite(power_led, HIGH);
}


  // ================= LCD WRITING AND CANCELLING ===============
  void write_high_pressure_led() {
    digitalWrite(high_pressure_led, HIGH);
    digitalWrite(low_pressure_led, LOW);
    digitalWrite(compressor_out, LOW);
    digitalWrite(condenser_out, LOW);
    digitalWrite(throttle_out, LOW);
    digitalWrite(evaporator_out, LOW);
    digitalWrite(mass_flow_led, LOW);
    digitalWrite(capacitance_led, LOW);
    digitalWrite(power_led, LOW);
  }

  void write_low_pressure_led() {
    digitalWrite(high_pressure_led, LOW);
    digitalWrite(low_pressure_led, HIGH);
    digitalWrite(compressor_out, LOW);
    digitalWrite(condenser_out, LOW);
    digitalWrite(throttle_out, LOW);
    digitalWrite(evaporator_out, LOW);
    digitalWrite(mass_flow_led, LOW);
    digitalWrite(capacitance_led, LOW);
    digitalWrite(power_led, LOW);
  }

  void write_compressor_out_led() {
    digitalWrite(high_pressure_led, LOW);
    digitalWrite(low_pressure_led, LOW);
    digitalWrite(compressor_out, HIGH);
    digitalWrite(condenser_out, LOW);
    digitalWrite(throttle_out, LOW);
    digitalWrite(evaporator_out, LOW);
    digitalWrite(mass_flow_led, LOW);
    digitalWrite(capacitance_led, LOW);
    digitalWrite(power_led, LOW);
  }

  void write_condenser_out_led() {
    digitalWrite(high_pressure_led, LOW);
    digitalWrite(low_pressure_led, LOW);
    digitalWrite(compressor_out, LOW);
    digitalWrite(condenser_out, HIGH);
    digitalWrite(throttle_out, LOW);
    digitalWrite(evaporator_out, LOW);
    digitalWrite(mass_flow_led, LOW);
    digitalWrite(capacitance_led, LOW);
    digitalWrite(power_led, LOW);
  }

  void write_throttle_out_led() {
    digitalWrite(high_pressure_led, LOW);
    digitalWrite(low_pressure_led, LOW);
    digitalWrite(compressor_out, LOW);
    digitalWrite(condenser_out, LOW);
    digitalWrite(throttle_out, HIGH);
    digitalWrite(evaporator_out, LOW);
    digitalWrite(mass_flow_led, LOW);
    digitalWrite(capacitance_led, LOW);
    digitalWrite(power_led, LOW);
  }

  void write_evaporator_out_led() {
    digitalWrite(high_pressure_led, LOW);
    digitalWrite(low_pressure_led, LOW);
    digitalWrite(compressor_out, LOW);
    digitalWrite(condenser_out, LOW);
    digitalWrite(throttle_out, LOW);
    digitalWrite(evaporator_out, HIGH);
    digitalWrite(mass_flow_led, LOW);
    digitalWrite(capacitance_led, LOW);
    digitalWrite(power_led, LOW);
  }

  void write_mass_flow_led() {
    digitalWrite(high_pressure_led, LOW);
    digitalWrite(low_pressure_led, LOW);
    digitalWrite(compressor_out, LOW);
    digitalWrite(condenser_out, LOW);
    digitalWrite(throttle_out, LOW);
    digitalWrite(evaporator_out, LOW);
    digitalWrite(mass_flow_led, HIGH);
    digitalWrite(capacitance_led, LOW);
    digitalWrite(power_led, LOW);
  }

  void write_capacitance_led() {
    digitalWrite(high_pressure_led, LOW);
    digitalWrite(low_pressure_led, LOW);
    digitalWrite(compressor_out, LOW);
    digitalWrite(condenser_out, LOW);
    digitalWrite(throttle_out, LOW);
    digitalWrite(evaporator_out, LOW);
    digitalWrite(mass_flow_led, LOW);
    digitalWrite(capacitance_led, HIGH);
    digitalWrite(power_led, LOW);
  }

  void write_power_led() {
    digitalWrite(high_pressure_led, LOW);
    digitalWrite(low_pressure_led, LOW);
    digitalWrite(compressor_out, LOW);
    digitalWrite(condenser_out, LOW);
    digitalWrite(throttle_out, LOW);
    digitalWrite(evaporator_out, LOW);
    digitalWrite(mass_flow_led, LOW);
    digitalWrite(capacitance_led, LOW);
    digitalWrite(power_led, HIGH);
  }

  void blink_greens() {
    digitalWrite(high_pressure_led, LOW);
    digitalWrite(low_pressure_led, LOW);
    digitalWrite(compressor_out, LOW);
    digitalWrite(condenser_out, LOW);
    digitalWrite(throttle_out, LOW);
    digitalWrite(evaporator_out, LOW);
    digitalWrite(mass_flow_led, LOW);
    digitalWrite(capacitance_led, LOW);
    digitalWrite(power_led, LOW);
    digitalWrite(mass_flow_led, LOW);
    delay(50);
    digitalWrite(mass_flow_led, HIGH);
    delay(50);
    digitalWrite(capacitance_led, HIGH);
    delay(50);
    digitalWrite(power_led, HIGH);
    delay(50);
    digitalWrite(mass_flow_led, LOW);
    digitalWrite(capacitance_led, LOW);
    digitalWrite(power_led, LOW);
  }

  // ========== TEST CASE FOR BUTTONS AND SWITCH ==============
  void test_buttons() {
    int t = 400; // miliseconds
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("SYSTEM TEST");
    lcd.setCursor(0, 1);
    lcd.print("HIGH P    ");
    lcd.print(digitalRead(high_pressure_switch));
    lcd.setCursor(0, 2);
    lcd.print("LOW P    ");
    lcd.print(digitalRead(low_pressure_switch));
    lcd.setCursor(0, 3);
    lcd.print("COMP SWITCH    ");
    lcd.print(digitalRead(13));
    all_on();
    delay(t);
    all_off();
    delay(t);
    
  }
