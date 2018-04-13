#define pwmPin 2 //using Arduino Mega 2560

void setup() { // here we define the type of the pin if its input or output. in this example we are going to
  pinMode(pwmPin,OUTPUT);  // output the PWM signal so its Defined OUTPUT
}

void loop() {
/*The analog write value varies from 0--->255 then 255 means 100% duty cycle and 0 % means 0% duty cycle respectively 50% means 255/2 so far
check https://www.arduino.cc/en/uploads/Tutorial/pwm.gif to read more about this and it contains image that explain this visualy*/

  analogWrite(pwmPin,64); //255 is 100% duty cycle && 127 is 50% duty cycle && 64 is 25% duty cycle
                          //check this  https://www.arduino.cc/en/uploads/Tutorial/pwm.gif for more information
  delay(2000);            //Delay for 2 seconds with msec unit
  analogWrite(pwmPin,0);
}
