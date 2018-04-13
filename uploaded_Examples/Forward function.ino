int LM1=4;
int LM2=5;
int RM1=6;
int RM2=7;
void setup() {
  pinMode(LM1,OUTPUT);
  pinMode (LM2,OUTPUT);
  pinMode(RM1,OUTPUT);
  pinMode(RM2,OUTPUT);

}

void forward() {
  digitalWrite (LM1,HIGH);
  digitalWrite(LM2,LOW);
  digitalWrite(RM1,HIGH);
  digitalWrite(RM2,LOW);
  
  
}
void loop() {
  forward ();
  

}
