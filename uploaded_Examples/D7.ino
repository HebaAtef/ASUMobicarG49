int inputpins[] = {2,3,4,5};
int ledpins[] = {10,11,12,13};
void setup() {
  // put your setup code here, to run once:
  for(int index=0 ; index <4 ; index++ )
  {
    pinMode(ledpins[index], OUTPUT);
    pinMode(inputpins[index], INPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int index=0 ; index <4 ; index++ )
  {
     int val = digitalRead(inputpins[index]);
     digitalWrite (ledpins[index] , val);
  }
  

}
