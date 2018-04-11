#define LED 13
#define BUTTON 7
void setup() {
pinMode(LED,OUTPUT);
pinMode(BUTTON,INPUT);
digitalWrite(BUTTON , HIGH);
}

void loop() {
  int value = digitalRead(BUTTON);
  digitalWrite(LED,value);
  
}
