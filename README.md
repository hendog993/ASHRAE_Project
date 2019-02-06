# ASHRAE_Project
Source codes for senior design ASHRAE trainer 
These codes work with the Arduino Genuino Uno board. 

2/5/19
Inputs:
1. Potentiometer: This pot varies with resistance and acts as a switch between readings. 
2. The unit has two sensors: An analog temperature sensor, and a DLT Humidity + Temp sensor.
Outputs: 
1. Analog temperature in Celsius
2. Analog temperature in Fahrenheit 
3. Digital Temperature in Celsius 
4. Digital Humidity in percentage. 


How to code is organized:
master.ino : This holds the void setup() and void loop() functions.
Bread.ino  : Holds the functions. 

Ideas:
- Make error messages
- Better equipment
- Change formatting with DHT with "Temp = 22 {}{}" , where {}{} are errors/blocks. 
- Create custom void function to print to the LCD. 
