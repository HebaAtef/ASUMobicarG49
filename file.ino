void setup()
{
  pinMode(7, OUTPUT);
}

void loop()
{
  digitalWrite(7, HIGH);
  delay(500); // Wait for 1000 millisecond(s)
  digitalWrite(7, LOW);
  delay(1500); // Wait for 1000 millisecond(s)
}
