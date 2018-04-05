# include<LiquidCrystal.h>
 LiquidCrystal lcd(8,9,4,5,6,7);
float temp;
int lm=A0;
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
temp=analogRead(lm);
temp=(5*temp*100)/1024;
lcd.setCursor(6,0);
lcd.print(temp);
}
