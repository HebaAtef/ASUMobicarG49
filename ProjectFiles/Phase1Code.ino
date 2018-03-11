#include <NewPing.h>
#include <Servo.h>

#define IN1  22     //the forward rotational direction pin of the right motors        
#define IN2  23     //the backward rotational direction pin of the right motors          
#define IN3  24     //the forward rotational direction pin of the left motors       
#define IN4  25     //the backward rotational direction pin of the left motors      
#define EN1  2      //Right Motors PWM Pin to control the speed      
#define EN2  3      //Left Motors PWM pin to control the speed
#define speed 127   //Set the Speed to half (255/2)


#define trig_pin A6           //ultrasonic transmitter pin
#define echo_pin A7           //ultrasonic receiver pin
#define maximum_distance 200  //define the maximum distance to start avoid obstcales
#define servoPin 6            //servo motor pin for ultrasonic navigattion to get left and right distances


/*__________________________obstcale avoiding______________________________________________*/
boolean goesForward = false;     //boolean flag for car forward going state
int distance = 100;
NewPing sonar(trig_pin, echo_pin, maximum_distance);  //Function from library <NewPing> to get ultrasonic configuration
Servo servo_motor;       //define servo motor
/*_________________________________________________________________________________________*/

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

 int turn_round(int speeder){
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
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
  analogWrite(EN1, obsp);
  analogWrite(EN2, obsp);
  }
}

void moveBackward(){

  goesForward=false;

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(EN1, obsp);
  analogWrite(EN2, obsp);
  
}

void turnRight(){

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(EN1, obsp);
  analogWrite(EN2, obsp);
  
  delay(500);
  
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

  delay(500);
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(EN1, obsp);
  analogWrite(EN2, obsp);
}

void setup() {
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(EN1,OUTPUT);
  pinMode(EN2,OUTPUT);
 
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

void loop() {
  while(Serial.available()){
            
                 int data = Serial.read();     //Save The Reciver Value From Bluetooth in Variable
           if(data == '1'){        //1 in Android APP tends to the UP Arrow                
                forward(255);                           
                delay(20);                               
                forward(0);                                                                
           }
            else if (data == '2'){   //2 in Android APP tends to the Down Arrow 
               backward(255);
               delay(20);
               backward(0);
           }
            else if (data=='4'){    //4 in Android APP tends to the Left Arrow
               turn_left(255);
               delay(20);
               turn_left(0);
            }else if(data=='3'){    //3 in Android APP tends to the Right Arrow
               turn_right(255);
               delay(20);
               turn_right(0);
           }else if (data == '9'){
  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);
   forward(110);
  if (distance <= 40){
    moveForward();
    delay(300);
    moveBackward();
    delay(400);
    moveStop();
    delay(300);
    
    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);

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
      }
}
