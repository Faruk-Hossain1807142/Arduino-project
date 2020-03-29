/*This code only for led on arduino which is 
 added to pin 13. 
 For blink the light */
 
int pinNum=13; // Creating an integer for pin 13
int delTime=1000; // Creating an integer for delay time

void setup(){
  pinMode(pinNum,OUTPUT); // pin mode for pin 13
  
}

void loop(){
  digitalWrite(pinNum,HIGH); // turn ON the led
  delay(delTime); // wait for 1 seconds 
  digitalWrite(pinNum,LOW); // turn OFF the led
  delay(delTime); // OFF for 1 seconds 
  
}
