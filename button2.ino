int led=12;
int button=13;
int sw;

void setup() {
  pinMode(led,OUTPUT);

pinMode(button,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  sw=digitalRead(13);
  if(sw==1)
  digitalWrite(led,HIGH);
else
digitalWrite(led,LOW);
}
