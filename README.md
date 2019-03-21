# ASHRAE_Project
Source codes for senior design ASHRAE trainer 
These codes work with the Arduino Genuino Uno board. 

How to navigate repository
- Senior_design.ino - final design implementation. In progress as of 3.20
- aFunctions.ino - contains more void functions to improve readability 

- master.ino : contains the void setup and void loop functions.
- Bread.ino : function file that links to master 
- ASHRAE.fzz : Arduino schematic and diagram for board. Possibly print a circuit board? 


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
- Better equipment. 
- Create custom void function to print to the LCD. 
