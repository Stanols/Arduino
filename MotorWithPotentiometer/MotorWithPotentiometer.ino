void setup()
{
  pinMode(12, OUTPUT);
  pinMode(13, INPUT);
}

void loop()
{
  int value = digitalRead(13);
  digitalWrite(12, value);
}
