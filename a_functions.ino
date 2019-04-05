// Performance: gets all temperatures and pressures and calculates performance. 
// Conditional if statements to allow for selecting measurements with potentiometer. 
// Directly enters the switch statement in the mainloop function. 


// ============= DERIVED VALUES FROM DANIEL ==================
int calculate_power() {
  return 0;
}

int calculate_efficiency() {
  return 0;
}

int calculate_mass_flow() {
  return 0;
}

// ================ MENUS ==============
int high_pressure_menu() {
  
  return 0;
}

int low_pressure_menu() {
  return 0;
}

// Convert resistance to integer values for pressure menus. 
int resistance_to_integer(int resistance) {
  return .68*(resistance) + 100;
}

// Write the LCD with basic prompts. 
void write_lcd(const char* prompt, int measurement) {
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print(compressor_mode[digitalRead(comp_mode_switch)]);  // Reads the 0 or 1 value for switch to the compressor mode. 
  lcd.setCursor(0,2);
  lcd.print(prompt);
  lcd.setCursor(0,3);
  lcd.print(measurement);
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
  digitalWrite(efficiency_led, LOW);
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
  digitalWrite(efficiency_led, LOW);
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
  digitalWrite(efficiency_led, LOW);
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
  digitalWrite(efficiency_led, LOW);
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
  digitalWrite(efficiency_led, LOW);
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
  digitalWrite(efficiency_led, LOW);
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
  digitalWrite(efficiency_led, LOW);
  digitalWrite(power_led, LOW);
}

void write_efficiency_led() {
  digitalWrite(high_pressure_led, LOW);
  digitalWrite(low_pressure_led, LOW);
  digitalWrite(compressor_out, LOW);
  digitalWrite(condenser_out, LOW);
  digitalWrite(throttle_out, LOW);
  digitalWrite(evaporator_out, LOW);
  digitalWrite(mass_flow_led, LOW);
  digitalWrite(efficiency_led, HIGH);
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
  digitalWrite(efficiency_led, LOW);
  digitalWrite(power_led, HIGH);
}

// ========== TEST CASE FOR BUTTONS AND SWITCH ==============
void test_buttons() {
   lcd.clear();
   lcd.setCursor(0,1);
   lcd.print("HIGH P");
   lcd.print(digitalRead(11));
   lcd.setCursor(0,2);
   lcd.print("LOW P");
   lcd.print(digitalRead(12));
   lcd.setCursor(0,3);
   lcd.print("COMP SWITCH");
   lcd.print(digitalRead(13));
}
