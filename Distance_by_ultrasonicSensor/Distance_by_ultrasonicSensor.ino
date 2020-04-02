#include<LiquidCrystal.h> // LCD library
LiquidCrystal LCD(2,3,4,5,6,7); // naming that LCD

int TrigPin=12; // integer for Trig pin
int EchoPin=11; // integer for echo pin
int ReqTime; // Float time for Requare time to travel sound
float Velocity=1422.08; // Float Integer for Velosity of sound in Km/hr
float distance; // Distance take in Inchi

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

 
  distance = (Velocity*ReqTime)/(2.54*10*60*60*2); // Calculating distance in inch

  LCD.setCursor(0,0);
  LCD.print("Distance is ="); // message 
  LCD.setCursor(0,1);
  LCD.print(distance); // Printing distance in LCD
  LCD.print("Inch"); // Message

  delay(200); // delay for 0.2 seconds

  
}
