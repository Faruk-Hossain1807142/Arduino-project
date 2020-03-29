/*
 This code is base on an led which name is RGB.
 This led can creat any type of colour. 
 In this code I will make an code which can turn on any type of light 
 */
 

int redPin=2; // Integer of pin for RED line of RGB 
int greenPin=3; // Integer of pin for GREEN line of RGB
int bluePin=4; // Integer of pin for blue line of RGB

void setup()
{
  pinMode(redPin,OUTPUT); // pin mode for Red line of RGB 
  pinMode(greenPin,OUTPUT); // pin mode for green line of RGB
  pinMode(bluePin,OUTPUT); // pin mode for Blue line of RGB
}

void loop()
{
  digitalWrite(redPin,HIGH); // Turn ON RED line of RGB
  digitalWrite(greenPin,LOW); // Turn OFF green line of RGB
  digitalWrite(bluepin,LOW); // Turn OFF Blue line of RGB
}
