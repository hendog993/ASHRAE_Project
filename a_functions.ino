// Performance: gets all temperatures and pressures and calculates performance. 

void print_lcd(const char* prompt, double value) {
  
}



// Conditional if statements to allow for selecting measurements with potentiometer. 
// Directly enters the switch statement in the mainloop function. 
int switch_knob(int main_resistance) {
    if (main_resistance < 100) return 1;
    else if (main_resistance < 200) return 2;
    else if (main_resistance < 300) return 3;
    else if (main_resistance < 400) return 4;
    else if (main_resistance < 500) return 5;
    else if (main_resistance < 600) return 6;
    else if (main_resistance < 700) return 7;
    else if (main_resistance < 800) return 8;
    else if (main_resistance < 900) return 9;
    else return 0;
}

int resistance_to_integer(int main_resistance) {
  // calculate slope values and relationship between expected P 
  return 0;
}

int menu_resistance_to_int(int main_resistance) {
  // calculate 
  return 0;
}

int calculate_power() {
  return 0;
}

int calculate_efficiency() {
  return 0;
}

int calculate_mass_flow() {
  return 0;
}


int high_pressure_menu() {
  
  return 0;
}

int low_pressure_menu() {
  return 0;
}

void write_lcd(const char * prompt, int measurement) {
  lcd.clear();
  lcd.println(prompt);
  lcd.println(measurement);
}


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
