// Performance: gets all temperatures and pressures and calculates performance. 
// Conditional if statements to allow for selecting measurements with potentiometer. 
// Directly enters the switch statement in the mainloop function. 

int encoder() {
    aState = digitalRead(encoderA); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aState != aLastState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(encoderB) != aState) counter ++;
     else counter --;
   }
     
     if (counter > 75) counter = 0;
     if (counter < 0) counter = 75;
   aLastState = aState; // Updates the previous state of the outputA with the current state
  
  if      (counter < 8)  return 1;
  else if (counter < 16) return 2;
  else if (counter < 24) return 3;
  else if (counter < 32) return 4;
  else if (counter < 40) return 5;
  else if (counter < 48) return 6;
  else if (counter < 56) return 7;
  else if (counter < 64) return 8;
  else if (counter < 72) return 9;
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
