void setup() {
  pinMode(2, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  int val = digitalRead(0);
  if (digitalRead(2) == HIGH){
      digitalWrite(6, LOW);
      digitalWrite(5, HIGH);
      delay(2000);

      digitalWrite(5, LOW);
      digitalWrite(4, HIGH);
      delay(5000);

      digitalWrite(5, HIGH);
      delay(2000);

      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);

  } else {
      digitalWrite(6, HIGH);
  }
}
