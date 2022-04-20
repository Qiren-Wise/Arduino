volatile int item;

float checkdistance_2_3() {
  digitalWrite(2, LOW);
  delayMicroseconds(2);
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);
  float distance = pulseIn(3, HIGH) / 58.00;
  delay(10);
  return distance;
}

void setup(){
  item = 0;
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(7, OUTPUT);
}

void loop(){
  item = checkdistance_2_3();
  Serial.println(String(item) + String("CM"));
  if (item > 0 && item < 20) {
    tone(7,131);
    delay((map(item, 0, 20, 0, 500)));
    tone(7,131);
    delay((map(item, 0, 20, 1, 500)));

  }

}
