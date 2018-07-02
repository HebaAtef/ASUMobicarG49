#define IN1  22             
#define IN2  23              
#define IN3  24             
#define IN4  25             
#define EN1  4             
#define EN2  5 

#define wheelSensor 2
#define stepcount 28
const float wheel_Diameter = 64.5;

void setup() {
  Serial.begin(9600);
 }

char terminal_input[4]; 
char inChar; 
byte index = 0; 

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

void turn_left_90_degree(int pulses){
  slots_counts = 0;
  while(slots_counts < pulses ){
      turn_left(150);
      stateNew = digitalRead(wheelSensor);
      if (stateNew != stateOld){
        stateOld = stateNew;
        slots_counts ++;
        Serial.println(slots_counts);
        } 
      } 
  turn_left(0);
}

void forward_accurate_movement(int pulses){
  slots_counts = 0;
  while(slots_counts < pulses ){
      forward(200);
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

