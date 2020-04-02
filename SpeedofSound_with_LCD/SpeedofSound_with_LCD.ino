#include<LiquidCrystal.h> // LCD library
LiquidCrystal LCD(2,3,4,5,6,7); // naming that LCD

int TrigPin=12; // integer for Trig pin
int EchoPin=11; // integer for echo pin
int ReqTime; // Float time for Requare time to travel sound
float Velocity; // Float Integer for Velosity of sound
int distance=5; // Distance take in Inchi

void setup(){
  Serial.begin(9600); // Starting the serial port
  LCD.begin(16,2); // Starting the LCD display

  pinMode(TrigPin,OUTPUT); // Pin mode for Tiger pin
  pinMode(EchoPin,INPUT); // Pin mode for Echo pin 

 
}

void loop(){
  LCD.clear(); //Clearing LCD display
  
  digitalWrite(TrigPin,LOW); // Turning off the Triger Sensore
  delayMicroseconds(1000); // delay for 10000 MocroSeconds
  digitalWrite(TrigPin,HIGH); // Turning on the Triger pin
  delayMicroseconds(10); // delay for 10 micro seconds
  digitalWrite(TrigPin,LOW); // turning off the Triger pin 

  ReqTime= pulseIn(EchoPin,HIGH); // reading the requre time to sound traveling

  Serial.println(ReqTime); // printing Requre time in Serial monitor
  LCD.setCursor(0,0); // where the print will start in LCD
  LCD.print("Time Requred"); // this will print in 1st row
  LCD.setCursor(0,1);
  LCD.print(ReqTime);// printing Requre time of Sound to travel on LCD
  LCD.print(" Micro-Sec"); // Printing Micro-Sec in LCD
  
  delay(3000); // delay for One minute 

  LCD.clear(); // Clearing LCD dispaly

  Velocity = (2.54*10*60*60*2*distance)/ReqTime; // Calculating Velocity in km/hr

  LCD.setCursor(0,0);
  LCD.print("Speed of Sound"); // message 
  LCD.setCursor(0,1);
  LCD.print(Velocity); // Printing Velocity in LCD
  LCD.print("Km/hr"); // Message

  delay(5000); // delay for 5 seconds

  
}
