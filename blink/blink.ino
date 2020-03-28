int pinNum=13;
int delTime=1000;

void setup(){
  pinMode(pinNum,OUTPUT);
  
}

void loop(){
  digitalWrite(pinNum,HIGH);
  delay(delTime);
  digitalWrite(pinNum,LOW);
  delay(delTime);
  
}
