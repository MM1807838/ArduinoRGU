int foo[] = {3, 5, 6, 9, 10};

void setup() {

  for (int i = 0; i < sizeof(foo) - 1; i++)
  {
    pinMode(foo[i], OUTPUT);
  }
}

void loop() {
  analogWrite(3,30);
  delay(100);
  analogWrite(3, 60);
  analogWrite(5, 30);
  delay(100);
  analogWrite(3, 30);
  analogWrite(5, 60);
  analogWrite(6, 30);
  delay(100);
  analogWrite(3, 0);
  analogWrite(5, 30);
  analogWrite(6, 60);
  analogWrite(9, 30);
  delay(100);
  analogWrite(5, 0);
  analogWrite(6, 30);
  analogWrite(9, 60);
  analogWrite(10, 30);
  delay(100);
  analogWrite(6, 0);
  analogWrite(9, 30);
  analogWrite(10, 60);
  delay(100);
  analogWrite(9, 0);
  analogWrite(10, 30);
  delay(100);
  analogWrite(10, 0);
}
