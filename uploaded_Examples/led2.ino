int led=13;
int ldr=10; 
int sw;
void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
pinMode(ldr,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
sw=digitalRead(ldr);
if(sw==1)
digitalWrite(led,1);

else 
digitalWrite(led,0);
}
