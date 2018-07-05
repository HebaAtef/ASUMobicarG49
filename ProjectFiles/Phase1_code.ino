#include <NewPing.h>
#include <Servo.h>
#define IN1  22             
#define IN2  23              
#define IN3  24             
#define IN4  25             
#define EN1  2             
#define EN2  3 

#define LS A4     // left line  sensor
#define RS A5     // right line sensor

#define obsp 200
#define obspFB 100

#define trig_pin A6
#define echo_pin A7
#define maximum_distance 200
#define servoPin 6

boolean goesForward = false;
int distance = 100;

/*___________________________Line Follower Variable _____________________________________________________________*/
int leftMotorSpeed = 80;   // start of Line Follower
int rightMotorSpeed = 80;
int IRthreshold = 300;    // end of Line Follower 


NewPing sonar(trig_pin, echo_pin, maximum_distance); 
Servo servo_motor; 



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

 int lookRight(){  
  servo_motor.write(20);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(90);
  return distance;
}

int lookLeft(){
  servo_motor.write(170);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(90);
  return distance;
  delay(100);
}

int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  return cm;
}
void moveStop(){
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(EN1, 0);
  analogWrite(EN2, 0);
}

void moveForward(){

  if(!goesForward){

    goesForward=true;
    
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(EN1, obspFB);
  analogWrite(EN2, obspFB);
  }
}

void moveBackward(){

  goesForward=false;

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(EN1, obspFB);
  analogWrite(EN2, obspFB);
  
}

void turnRight(){

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(EN1, obsp);
  analogWrite(EN2, obsp);
  
  delay(300);
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(EN1, obsp);
  analogWrite(EN2, obsp);
 
  
  
}

void turnLeft(){

 digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(EN1, obsp);
  analogWrite(EN2, obsp);

  delay(300);
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(EN1, obsp);
  analogWrite(EN2, obsp);
}

/*_____________________________Void Setup Function___________________________________________________________*/
void setup() {
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(EN1,OUTPUT);
  pinMode(EN2,OUTPUT);
  
  Serial.begin(9600);
  
  servo_motor.attach(servoPin); 
  servo_motor.write(90);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);    
}
/*__________________________Void Loop Function______________________________________________________________*/
void loop() 
{
      while (Serial.available()){
       int data = Serial.read();     
 if(data == '1')                     
 {
  forward(255);                           
  delay(20);                               
  forward(0);                                                                
 }
  else if (data == '2') 
 { 
 
  backward(255);
  delay(20);
  backward(0);
 
  
 }
  else if (data=='4') 
 {
  turn_left(255);
  delay(20);
  turn_left(0);

 }
  else if(data=='3') 
 {
  turn_right(255);
  delay(20);
  turn_right(0);
 }

  
  else if (data == '9'){
    
   int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);
   forward(80);
  if (distance <= 40){
    moveForward();
    delay(300);
    moveBackward();
    delay(400);
    moveStop();
    delay(300);
    
    distanceRight = lookRight();
    delay(600);
    distanceLeft = lookLeft();
    delay(600);

    if (distance >= distanceLeft){
      turnRight();
      moveStop(); 
      } 
      else{ 
        turnLeft();
        moveStop();
    }
  }
  else{
    moveForward(); 
  }
    distance = readPing();
  }
  
   else if (data == '8'){
        if((analogRead(LS) > IRthreshold)&&(analogRead(RS) >IRthreshold) ){
          forward(50);
        }
      
       if( (analogRead(LS) < IRthreshold)&&(analogRead(RS) >IRthreshold)){
         turn_left(140);
       }
      
       if((analogRead(LS) > IRthreshold)&&(analogRead(RS) <IRthreshold)){
          turn_right(140);
       }
      
      if((analogRead(LS) < IRthreshold)&&(analogRead(RS) <IRthreshold)){
         forward(0);
      }
   

   }
      }
}
