   int green=13;
 
   int red=12;
 
  int yallow=11;
int blue=10;
  void setup() {
  
 pinMode(green,OUTPUT);
  
 pinMode(red,OUTPUT);

 pinMode(yallow,OUTPUT);

 pinMode(blue,OUTPUT);
}

void loop() {
  
digitalWrite(green,HIGH);

delay[5000];
digitalWrite(green,LOW);

  digitalWrite(red, HIGH);   
delay[5000];
digitalWrite(red,LOW);

digitalWrite(yallow,HIGH);
delay[5000];
digitalWrite(yallow,LOW);
digitalWrite(blue,HIGH);
delay[5000];
digitalWrite(blue,LOW);
}
