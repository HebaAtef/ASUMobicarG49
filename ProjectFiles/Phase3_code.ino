#include <Wire.h>

#define IN1  22             
#define IN2  23              
#define IN3  24             
#define IN4  25             
#define EN1  4             
#define EN2  5

// demo shapes lengthes 
#define infinity_diagonale 50
#define rectangle_length 50

//Gyroscope variables.
const int MPU_addr = 0x68;  //gyroscope address
int16_t Gz ; //angular velocity

//Accurate Distance 
#define wheelSensor 2 //sensor pin 
#define stepcount 28  //no of slots in the wheel
const float wheel_Diameter = 64.5;


//functions interface 
void forward(int speeder);    // order motors to move forward given the PWM signal value
void backward(int speeder);   // order motors to move backward given the PWM signal value
void turn_left(int speeder);  // order motors to turn right given the PWM signal value
void turn_right(int speeder); // order motors to turn left given the PWM signal value
int CMtoSteps(float cm);      // translate the given distance to motor wheel slot number
void forward_accurate_movement(int pulses); // accurate forward function given the no of wheel slots to move
void backward_accurate_movement(int pulses); // accurate backward function given the no of wheel slots to move
void angle(float ra);         // accurate angel of rotation function given only the angel value (support +ve & -ve values)
void forward_accurate_movement_clock_wise(int pulses);


void setup() {
  Serial.begin(9600);
 }


void loop(){
     String in_str;  //intput string command form mobile app terminal
     while(Serial.available()){
      in_str = Serial.readString();  // read the command from mobile app
      Serial.println(in_str);        // print the input string on serial monitor 
      char mode = in_str[0];         // git the first char that select which accurate move option a: angel, f: forward, b:backward
      String required_str = in_str.substring(1,in_str.length());  // get the required value from string 
      float required_value = required_str.toFloat();                 // convert the required value to float value
      Serial.println(mode);                                 // print mode on serial monitor
      Serial.println(required_str);                         // print required value string on serial monitor
      Serial.println(required_str);                         // print required value float on serial monitor

      if(mode == 'f'){                                             // if the mode is forward then move forward and
         forward_accurate_movement(CMtoSteps(required_value));     // translate tha distance value to wheel slots value
        }else if( mode == 'b'){                                    // if the mode is backward then move backward and 
          backward_accurate_movement(CMtoSteps(required_value));   // translate tha distance value to wheel slots value
        }else if(mode == 'a'){                                     // if the mode is angel then with angel given from 
          angle(required_value);                                   // required value
        }else if( in_str == "demo"){
          demo_shapes();
        }

     } 
}

void demo_shapes(void){
      // infinty start
      angle (30) ;
      for (int i = 0 ; i < 30 ; i++) {
        forward_accurate_movement_clock_wise(2);
        forward(0);
        angle(-3) ;
      }
      forward_accurate_movement(CMtoSteps(infinity_diagonale));
      for (int i = 0 ; i < 30; i++) {
        forward_accurate_movement_anti_clock_wise(2);
        forward(0);
        angle(3) ;
      }
      forward_accurate_movement_anti_clock_wise_circular(CMtoSteps(infinity_diagonale), 210, 225);
      angle (-30) ;
      // ifinity done 
      // square start
        delay(1000) ;
      for (int i = 0 ; i < 4 ; i++) {
        forward_accurate_movement_anti_clock_wise_circular(CMtoSteps(rectangle_length), 210, 225);
        forward(0);
        angle(80) ; //90 degree
       }
      // square done
      delay(1000) ;
      // circle start
      for (int i = 0 ; i < 55 ; i++) {
        forward_accurate_movement_anti_clock_wise_circular(4, 210, 225);
        forward(0);
        angle(3) ;
      }
      forward(0);
     // circuile done  
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


void forward_accurate_movement_clock_wise(int pulses){
  slots_counts = 0;
  while(slots_counts < pulses ){
      forward_spec(190,140);
      stateNew = digitalRead(wheelSensor);
      if (stateNew != stateOld){
        stateOld = stateNew;
        slots_counts ++;
        Serial.println(slots_counts);
        } 
      } 
  forward(0); 
}

void forward_accurate_movement_anti_clock_wise(int pulses){
  slots_counts = 0;
  while(slots_counts < pulses ){
      forward_spec(140,190);
      stateNew = digitalRead(wheelSensor);
      if (stateNew != stateOld){
        stateOld = stateNew;
        slots_counts ++;
        Serial.println(slots_counts);
        } 
      } 
  forward(0); 
}

void forward_accurate_movement_anti_clock_wise_circular(int pulses, int right_speed, int left_speed){
  slots_counts = 0;
  while(slots_counts < pulses ){
      forward_spec(right_speed,left_speed);
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
void forward(int speeder){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(EN1,speeder);
    analogWrite(EN2,speeder);  
 }

 void backward(int speeder){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(EN1,speeder);
    analogWrite(EN2,speeder);
 }


 void turn_right(int speeder){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(EN1,speeder);
    analogWrite(EN2,speeder);
 }
 
 void turn_left(int speeder){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(EN1,speeder);
    analogWrite(EN2,speeder);
 }

void forward_spec(int right_speed , int left_speed){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(EN1, right_speed);
    analogWrite(EN2, left_speed);
}

void backward_spec(int right_speed , int left_speed){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(EN1, right_speed);
    analogWrite(EN2, left_speed);
}



