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
    else if (main_resistance < 1000) return 10;
    else return 0;
}

int resistance_to_integer(int main_resistance) {
  // calculate slope values and relationship between expected P 
  return 0;
}

int menu_resistance_to_int(int main_resistance) {
  // calcula
  return 0;
}

int high_pressure_menu() {
  
  return 0;
}

int low_pressure_menu() {
  return 0;
}
