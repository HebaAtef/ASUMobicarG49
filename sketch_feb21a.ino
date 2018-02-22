int a=13;
int b=12;
int c=11;
int d=10;
int e=9;
int f=8;
int g=7;
int sw;
int button=6;
void zero();void one();void two();void three();void four();void five();void six();void seven();void eight();void nine();
void setup() {
  // put your setup code here, to run once:
for(int i=7;i<=13;i++){
  pinMode(i,OUTPUT);
}
pinMode(button,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
sw=digitalRead(6);
if (sw==1){
  zero();
    delay(500);
  one();
  delay(500);
  two();
  delay(500);
 three();
    delay(500);
four();
  delay(500);
five();
  delay(500);
six();
  delay(500);
seven();
  delay(500);
eight();
  delay(500);
nine();
  delay(500);
}
}
void zero(){
   digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,1);
  digitalWrite(g,0);
}
void one(){
  digitalWrite(a,0);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,0);
}
void two(){
   digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,0);
  digitalWrite(d,1);
  digitalWrite(e,1);
 digitalWrite(f,0);
  digitalWrite(g,1);
}
void three(){
   digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,1);
}
void four(){
     digitalWrite(a,0);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,1);
  digitalWrite(g,1);
}
void five(){
     digitalWrite(a,1);
  digitalWrite(b,0);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,0);
  digitalWrite(f,1);
  digitalWrite(g,1);
}
void six(){
   digitalWrite(a,1);
  digitalWrite(b,0);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,1);
  digitalWrite(g,1);
}
void seven(){
   digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,0);
}
void eight(){
   digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,1);
  digitalWrite(g,1);
}
void nine(){
   digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,0);
  digitalWrite(f,1);
  digitalWrite(g,1);
}

