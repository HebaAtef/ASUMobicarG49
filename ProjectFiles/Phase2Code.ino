#define IN1  22             
#define IN2  23              
#define IN3  24             
#define IN4  25             
#define EN1  2             
#define EN2  3 

#define rightIRSensor 8
#define centerIRSensor 9
#define leftIRSensor 10

boolean IRSensorReadings[3] = {0, 0, 0};


void setup() {
 pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(EN1,OUTPUT);
  pinMode(EN2,OUTPUT);

  pinMode(rightIRSensor ,INPUT);
  pinMode(centerIRSensor ,INPUT);
  pinMode(leftIRSensor ,INPUT);

}

void loop() {
 
   IRSensorReadings[0]= digitalRead(leftIRSensor);
   IRSensorReadings[1]= digitalRead(centerIRSensor);
   IRSensorReadings[2]= digitalRead(rightIRSensor);
   
   Serial.print("LEFT: ");
   Serial.print(IRSensorReadings[0]);
   Serial.print("CENTER: ");
   Serial.print(IRSensorReadings[1] );
   Serial.print("RIGHT:");
   Serial.println(IRSensorReadings[2]);
 
   if(IRSensorReadings[0] == 0 && IRSensorReadings[1] == 0 && IRSensorReadings[2] == 0) 
        forward(0);
   if(IRSensorReadings[0] == 0 && IRSensorReadings[1] == 0 && IRSensorReadings[2] == 1) 
        forward_left();
   if(IRSensorReadings[0] == 0 && IRSensorReadings[1] == 1 && IRSensorReadings[2] == 0) 
        forward(130); 
   if(IRSensorReadings[0] == 0 && IRSensorReadings[1] == 1 && IRSensorReadings[2] == 1) 
        turn_left(220);
   if(IRSensorReadings[0] == 1 && IRSensorReadings[1] == 0 && IRSensorReadings[2] == 0)   
        forward_right();
   if(IRSensorReadings[0] == 1 && IRSensorReadings[1] == 1 && IRSensorReadings[2] == 0) 
        turn_right(220);
}


int forward(int speeder){
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    analogWrite(EN1,speeder);
    analogWrite(EN2,speeder);  
 }

 int backward(int speeder){
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(EN1,speeder);
    analogWrite(EN2,speeder);
    
 }

 int turn_right(int speeder){
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    analogWrite(EN1,speeder- (0.7*speeder));
    analogWrite(EN2,speeder);
 }
 
 int turn_left(int speeder){
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(EN1,speeder);
    analogWrite(EN2,speeder-(0.7*speeder));
 }

 void forward_left () { 
     digitalWrite(IN1 ,HIGH);
     digitalWrite(IN2, LOW);  
     digitalWrite(IN3, HIGH);
     digitalWrite(IN4, LOW);   
     analogWrite(EN1, 200);
     analogWrite(EN2, 80); 
 }

 void forward_right () {
     digitalWrite(IN1, HIGH);
     digitalWrite(IN2, LOW);  // setting the motors to go forward right 
     digitalWrite(IN3, HIGH);
     digitalWrite(IN4, LOW);   // setting the motors to go forward right
     analogWrite(EN1, 80);
     analogWrite(EN2, 200);
 }

