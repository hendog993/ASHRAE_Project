int enter_high_pressure() {
  int high_pressure = 0; //Read the value from the knob.
  return high_pressure;
}



// Performance: gets all temperatures and pressures and calculates performance. 

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
  int integer = 0;
  return integer;
}

void boolButton(int button1) {
  if (button1 == true) {
  } return 
}

void power_led(int input) {
  // Change led write configuration based on integer input. 
  // Possible create a void function to power off all leds. 
  digitalWrite(led_row1, HIGH);
}

void reset_led() {
  digitalWrite(led_row1, LOW);
  digitalWrite(led_row2, LOW);
  digitalWrite(led_row3, LOW);
  digitalWrite(led_row4, LOW);
}

}
