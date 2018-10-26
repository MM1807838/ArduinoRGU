void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int val = analogRead(0);
  analogWrite(3, val/4);
}
