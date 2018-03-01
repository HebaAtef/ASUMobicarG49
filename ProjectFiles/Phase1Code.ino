#define IN1  22     //the forward rotational direction pin of the right motors        
#define IN2  23     //the backward rotational direction pin of the right motors          
#define IN3  24     //the forward rotational direction pin of the left motors       
#define IN4  25     //the backward rotational direction pin of the left motors      
#define EN1  2      //Right Motors PWM Pin to control the speed      
#define EN2  3      //Left Motors PWM pin to control the speed
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

 int turn_round(int speeder){
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
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
  while(Serial.available()){
            
                 int data = Serial.read();     //Save The Reciver Value From Bluetooth in Variable
           if(data == '1')        //1 in Android APP tends to the UP Arrow                 
           {
            forward(255);                           
            delay(20);                               
            forward(0);                                                                
           }
            else if (data == '2')   //2 in Android APP tends to the Down Arrow
           { 
           backward(255);
           delay(20);
           backward(0);
           }
            else if (data=='4')    //4 in Android APP tends to the Left Arrow
           {
            turn_left(255);
            delay(20);
            turn_left(0);
          
           }
            else if(data=='3')     //3 in Android APP tends to the Right Arrow
           {
            turn_right(255);
            delay(20);
            turn_right(0);
           }
      }

}
