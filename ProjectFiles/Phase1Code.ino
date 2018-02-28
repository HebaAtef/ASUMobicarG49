#define IN1  22     //Left Motors Forward Direction Control Pin         
#define IN2  23     //Left Motors Backward Direction Control Pin          
#define IN3  24     //Right Motors Forward Direction Control Pin         
#define IN4  25     //Right Motors Backward Direction Control Pin         
#define EN1  2      //Left Motors PWM Pin to control the speed      
#define EN2  3      //Right Motors PWM pin to control the speed
#define speed 127   //Set the Speed to half (255/2)


int forward(int speeder)    
 {
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    analogWrite(EN1,speeder);
    analogWrite(EN2,speeder);  
 }

 int backward(int speeder)     
 {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(EN1,speeder);
    analogWrite(EN2,speeder);
 }

int turn_right(int speeder)  
 {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    analogWrite(EN1,speeder);
    analogWrite(EN2,speeder);
 }
 
 int turn_left(int speeder)  
 {
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
    analogWrite(EN1,speeder);
    analogWrite(EN2,speeder);
 }

void setup() {
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(EN1,OUTPUT);
  pinMode(EN2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

}
