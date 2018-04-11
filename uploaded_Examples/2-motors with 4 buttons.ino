const int M1f=11;
const int M1b=10;
const int M2f=5;
const int M2b=3;
const int button1=9;
const int button2=8;
const int button3=7;
const int button4=6;
int sw1; 
int sw2;
int sw3;
int sw4;

void setup(){
pinMode(M1f,OUTPUT);
pinMode(M1b,OUTPUT);
pinMode(M2f,OUTPUT);
pinMode(M2b,OUTPUT);
pinMode(button1,INPUT);
pinMode(button2,INPUT);
pinMode(button3,INPUT);
pinMode(button4,INPUT);


  // put your setup code here, to run once:

}

void loop() {
  sw1=digitalRead(button1);
  sw2=digitalRead(button2);
  sw3=digitalRead(button3);
  sw4=digitalRead(button4);

  if(sw1==1){
    analogWrite(M1f,255);
    digitalWrite(M1b,0);
    analogWrite(M2f,255);
    digitalWrite(M2b,0);
  }
  else if (sw2==1){
    analogWrite(M1f,50);
    digitalWrite(M1b,0);
    digitalWrite(M2f,0);
    analogWrite(M2b,50);
  }
  else if (sw3==1){
    digitalWrite(M1f,0);
    analogWrite(M1b,128);
    digitalWrite(M2f,0);
    analogWrite(M2b,128);
  }
  else if (sw4==1) {
    digitalWrite(M1f,0);
    analogWrite(M1b,50);
    analogWrite(M2f,50);
    digitalWrite(M2b,0);
  }
  else {
    digitalWrite(M1f,0);
    digitalWrite(M1b,0);
    digitalWrite(M2f,0);
    digitalWrite(M2b,0);
  }
  
    
    
  }
  
  // put your main code here, to run repeatedly:

