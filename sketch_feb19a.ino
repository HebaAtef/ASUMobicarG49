int led1=4;
int led2=5;
int led3=6;
int led4=7;
void setup() {
  // put your setup code here, to run once:
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(led1,1);
delay(1000);
digitalWrite(led1,0);
digitalWrite(led2,1);
delay(1000);
digitalWrite(led2,0);
digitalWrite(led3,1);
delay(1000);
digitalWrite(led3,0);
digitalWrite(led4,1);
delay(1000);
digitalWrite(led4,0);
delay(200);
digitalWrite(led4,1);
delay(1000);
digitalWrite(led4,0);
digitalWrite(led3,1);
delay(1000);
digitalWrite(led3,0);
digitalWrite(led2,1);
delay(1000);
digitalWrite(led2,0);
digitalWrite(led1,1);
delay(1000);
digitalWrite(led1,0);
}
