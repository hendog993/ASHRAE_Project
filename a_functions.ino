// Performance: gets all temperatures and pressures and calculates performance. 
// Conditional if statements to allow for selecting measurements with potentiometer. 
// Directly enters the switch statement in the mainloop function. 

// ============= DERIVED VALUES FROM DANIEL ==================


double calculate_power(double tempEvap, double tempCond) {
  double C[10] = {645.1275928, -2.295127832, -7.218567883, -0.005535838, 0.042861644,
                    0.076252192, 0.000563255, -0.000610193, 0.000112464, -0.000130886};
                    
  return C[0] + C[1]*tempCond + C[2]*tempEvap + C[3]*pow(tempCond, 2) + C[4]*tempEvap*tempCond + 
         C[5]*pow(tempEvap, 2) + C[6]*pow(tempCond, 3) + C[7]*tempEvap*pow(tempCond, 2) + C[8]*tempCond * pow(tempEvap, 2) +
         C[8]*tempCond*pow(tempEvap, 2) + C[9]*pow(tempEvap, 3);
}

double calculate_mass_flow(double tempEvap, double tempCond) {
  double C[10] = {40.15698882, 1.096371113, 0.14024549, 0.015865756, 0.002097207,
                -0.001690066, 9.03205E-05, -2.70756E-05, -1.35767E-05, 5.15408E-06};
                     
  return C[0] + C[1]*tempCond + C[2]*tempEvap + C[3]*pow(tempCond, 2) + C[4]*tempEvap*tempCond + 
         C[5]*pow(tempEvap, 2) + C[6]*pow(tempCond, 3) + C[7]*tempEvap*pow(tempCond, 2) + C[8]*tempCond * pow(tempEvap, 2) +
         C[8]*tempCond*pow(tempEvap, 2) + C[9]*pow(tempEvap, 3);
}

double calculate_capacity(double tempEvap, double tempCond) {
  double C[10] = {4433.99929, 107.9502108, -6.654767819, 2.002620595, -0.2210224213,
               -0.1026412673, 0.002942954154, -0.00968481191, -0.0006961641807, 0.0002807495071};

  return C[0] + C[1]*tempCond + C[2]*tempEvap + C[3]*pow(tempCond, 2) + C[4]*tempEvap*tempCond + 
         C[5]*pow(tempEvap, 2) + C[6]*pow(tempCond, 3) + C[7]*tempEvap*pow(tempCond, 2) + C[8]*tempCond * pow(tempEvap, 2) +
         C[8]*tempCond*pow(tempEvap, 2) + C[9]*pow(tempEvap, 3);
}

int calculate_efficiency(double power, double qin) {
  // Efficiency = Qout/Win 
  // mdot(h2-h1)/Win 
  return 0;
}


// ================ MENUS ==============
void high_pressure_menu() {
  while (digitalRead(high_pressure_button) == HIGH) {
    lcd.clear();
    lcd.print("Enter HIGH P");
    lcd.setCursor(0,2);
    lcd.print(resistance_to_integer(analogRead(A0)));
    delay(400);
  }
  high_side_pressure = resistance_to_integer(analogRead(A0));
}

void low_pressure_menu() {
  while (digitalRead(low_pressure_button) == HIGH) {
    lcd.clear();
    lcd.print("Enter LOW P");
    lcd.setCursor(0,2);
    lcd.print(resistance_to_integer(analogRead(A0)));
    delay(400);
    } 
  low_side_pressure = resistance_to_integer(analogRead(A0));
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
   lcd.setCursor(0,0);
   lcd.print("SYSTEM TEST");
   lcd.setCursor(0,1);
   lcd.print("HIGH P    ");
   lcd.print(digitalRead(11));
   lcd.setCursor(0,2);
   lcd.print("LOW P    ");
   lcd.print(digitalRead(12));
   lcd.setCursor(0,3);
   lcd.print("COMP SWITCH    ");
   lcd.print(digitalRead(13));
   write_compressor_out_led();
   delay(100);
   write_high_pressure_led();
   delay(100);
   write_condenser_out_led();
   delay(100);
   write_throttle_out_led();
   delay(100);
   write_low_pressure_led();
   delay(100);
   write_evaporator_out_led();
   delay(100);
   write_mass_flow_led();
   delay(100);
   write_power_led();
   delay(100);
   write_efficiency_led();
   delay(100);
   write_power_led();
   delay(100);
   write_mass_flow_led();
   delay(100);
   write_evaporator_out_led();
   delay(100);
   write_low_pressure_led();
   delay(100);
   write_throttle_out_led();
   delay(100);
   write_condenser_out_led();
   delay(100);
   write_high_pressure_led();
   delay(100);
   write_compressor_out_led();
} 
