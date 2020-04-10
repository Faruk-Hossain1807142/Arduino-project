#include<LiquidCrystal.h>
LiquidCrystal LCD(2,3,4,5,6,7);

int TrigPin=8;// connect pin 8 of arduino to trig pin in sensor  
int EchoPin=9; // connect pin 9 of arduino to echo pin in sensor
float TimeReq; // Integer for Time requer to travel by sound
float distance; // distance object to sensor
float SpeedOfsound=1372.97; // speed of sound in km/hr
int lightPin=A0;// pin for light
int j,i; // integer for increment
int Min,Seconds;


void setup() {
  
  LCD.begin(16,2); // Start LCD display
  pinMode(TrigPin,OUTPUT); // pin mode of trig pin 
  pinMode(EchoPin,INPUT); // pin mode of echo pin

  LCD.setCursor(0,0);
  LCD.print("   Wait Please  ");
  delay(5000);
  LCD.clear();

}

//Function for HC-SR04 sensor
void DistanceSensor(){

        digitalWrite(TrigPin,LOW); // turning OFF trig
        delayMicroseconds(20); // delay for 20 micro-seconds
        digitalWrite(TrigPin,HIGH); // turning ON trig
        delayMicroseconds(10); // delay for 10 micro-seconds
        digitalWrite(TrigPin,LOW);// turning OFF trig
        TimeReq=pulseIn(EchoPin,HIGH); //Calculating time requre to travel sound
        
        distance=(SpeedOfsound*TimeReq)/(2.54*10*60*60*2);// calculating distance
}

void loop() {
  LCD.setCursor(0,0);
  LCD.print("Wave your Hand");
  LCD.setCursor(0,1);
  LCD.print(" Turn ON light"); 
  for(j=1;j<=2;j++) // 1st value of sensor came Zero that's why i used this loop
  {
    DistanceSensor(); // calling HC-SR04 function
  }
  
  
  delay(50);// delay for 250 mili-seconds

  if(distance<=3)// If distance less them 3 inch of object light will ON
  {
     
  
    delay(1000); // delay for one Seconds
    for(j=80;j>=1;j--) // how many Second I wanna to On light
    {
      Seconds=j;
      for(i=1;i<=2;i++)
      {
       DistanceSensor(); // Calling HC-SR04 sensor
      }
      
      
      if(distance<=3) // If again you wave a hand or anything then light will OFF
      {
        analogWrite(lightPin,0); // turn off light
         LCD.clear();
         LCD.setCursor(0,0);
         LCD.print("Status: Light OFF");
         LCD.setCursor(0,1);
         LCD.print("    Thank You");
        delay(3000);// delay 3 seconds
        goto LightOff; // Goto LightOff
        }
       if(distance>3) // IF nothing happen Light will on
       {
        analogWrite(lightPin,255); // light ON
         LCD.clear();
         LCD.setCursor(0,0);
         LCD.print("Status: Light ON");

         LCD.setCursor(0,1);
         LCD.print("Time remains:");
         LCD.print(Seconds);
         LCD.print("s");
        }
        
    delay(1000);// delay for One seconds
    }
    
  }
  
  LightOff:
  analogWrite(lightPin,0); // light off

  LCD.clear();
}
