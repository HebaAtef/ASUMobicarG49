#include <Wire.h>

#define IN1  22             
#define IN2  23              
#define IN3  24             
#define IN4  25             
#define EN1  4             
#define EN2  5
 
//Gyroscope pins

//Gyroscope variables.
const int MPU_addr = 0x68;
int16_t Gz ;

//Accurate Distance 
#define wheelSensor 2
#define stepcount 28
const float wheel_Diameter = 64.5;


void angle(float ra);

void setup() {
  Serial.begin(9600);
 }


void loop(){
     String str;
     while(Serial.available()){
      str = Serial.readString();
      Serial.println(str);
      char dir = str[0];
      String dis = str.substring(1,str.length());
      float distance = dis.toFloat();
      Serial.println(dir);
      Serial.println(dis);
      Serial.println(distance);

      if(dir == 'f'){
         forward_accurate_movement(CMtoSteps(distance));
        }else if( dir == 'b'){
          backward_accurate_movement(CMtoSteps(distance));
        }else if(dir == 'a'){
          angle(distance);
        }

     } 
}



void angle (float ra){
  Serial.print("Angel mode on with angel = ");
  Serial.println(ra);
  float t , tp , gs , a = 0;
  if( abs(ra) >= 90){
    ra = ra - (0.11 * ra);
  }else if(abs(ra) <= 60 || abs(ra) > 45){
    ra = ra - (0.18 * ra);
  }else if(abs(ra) <= 45 || abs(ra) >= 30){
    ra = ra - (0.21 * ra);
  }
   
  
   Wire.begin(); // disabling sleep mode of the gyro
   Wire.beginTransmission(MPU_addr);
   Wire.write(0x6B);
   Wire.write(0);
   Wire.endTransmission(true);

  while ((ra > 180) || (ra < -180)) { // making ra between -180 , 180
    if (ra < -180) {
      ra = ra + 360 ;
    }
    if (ra > 180) {
      ra = ra - 360 ;
    }
  }
  if (ra > 0) {
    turn_left(100);
  } else if (ra < 0) {
    turn_right(100);
  } else {
    turn_right(0);
  }
  t = millis() ; // taking initial value of time
  while (1) {
    tp = t ;
    t = millis() ;
    Wire.beginTransmission(0b1101000); //I2C address of the MPU
    Wire.write(0x47); //Starting register for Gyro Readings
    Wire.endTransmission();
    Wire.requestFrom(0b1101000,6); //Request Gyro Registers (43 - 48)
    Gz = Wire.read() << 8 | Wire.read(); // Gz is the angular velocity
    
    gs = Gz / 120.0 ; // 131 is the gyro scale
    a = a + gs * ((t - tp) / 1000) ;
    
    if (a >= 360) {
      a = a - 360 ;
    } else if (a <= -360) {
      a = a + 360 ;
    }
    Serial.println(a);
    if (ra > 0) {
      if (a >= ra) {
        forward(0);
        break ;
      }
    } else if (ra < 0) {
      if (a <= ra) {
        forward(0);
        break ;
      }
    } else {
      break ;
    }
  }
}



int CMtoSteps(float cm){
  int result;
  float circumference = (wheel_Diameter * 3.14) / 10;
  float cm_step = circumference / stepcount;
  float f_result = cm / cm_step;
  result = (int) f_result; 
  return result; 
}

volatile int slots_counts = 0;
boolean stateNew = LOW;
boolean stateOld = LOW;

void forward_accurate_movement(int pulses){
  slots_counts = 0;
  while(slots_counts < pulses ){
      forward(80);
      stateNew = digitalRead(wheelSensor);
      if (stateNew != stateOld){
        stateOld = stateNew;
        slots_counts ++;
        Serial.println(slots_counts);
        } 
      } 
  forward(0);
  
}

void backward_accurate_movement(int pulses){
  slots_counts = 0;
  while(slots_counts < pulses ){
      backward(80);
      stateNew = digitalRead(wheelSensor);
      if (stateNew != stateOld){
        stateOld = stateNew;
        slots_counts ++;
        Serial.println(slots_counts);
        } 
      } 
  forward(0);
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
    analogWrite(EN1,speeder);
    analogWrite(EN2,speeder);
 }
 
 int turn_left(int speeder){
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(EN1,speeder);
    analogWrite(EN2,speeder);
 }



