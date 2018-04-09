int car1=11;
int car2=10;
int car3=9;
int car4=6;
int sw1,sw2,sw3,sw4;

void setup() {
  // put your setup code here, to run once:
pinMode(11,OUTPUT);

pinMode(10,OUTPUT); 
pinMode(9,OUTPUT);
pinMode(6,OUTPUT);
pinMode(0,INPUT);
pinMode(1,INPUT);
pinMode(2,INPUT);
pinMode(3,INPUT);
}

void loop() {
  
 // put your main code here, to run repeatedly:
sw1= digitalRead(0);
sw2= digitalRead(1);
sw3=digitalRead(2);
sw4=digitalRead(3);
if(sw1==1){
analogWrite(11,255);
analogWrite(10,0);
analogWrite(9,128);
analogWrite(6,0);
}
if(sw2==1){
analogWrite(11,255);
analogWrite(10,0);
analogWrite(9,128);
analogWrite(6,0);
}
if(sw3==1){
  analogWrite(11,255);
analogWrite(10,0);
analogWrite(9,128);
analogWrite(6,0);
}
if(sw4==1){
  analogWrite(11,255);
analogWrite(10,0);
analogWrite(9,128);
analogWrite(6,0);
}
else
{
analogWrite(11,0);
analogWrite(10,0);

analogWrite(9,0);

analogWrite(6,0);

}
}
