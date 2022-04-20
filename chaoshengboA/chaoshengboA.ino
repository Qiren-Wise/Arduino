float checkdistance_A2_A3() {
  digitalWrite(A2, LOW);
  delayMicroseconds(2);
  digitalWrite(A2, HIGH);
  delayMicroseconds(10);
  digitalWrite(A2, LOW);
  float distance = pulseIn(A3, HIGH) / 58.00;
  delay(10);
  return distance;
}

void setup(){
  Serial.begin(9600);
  pinMode(A2, OUTPUT);
  pinMode(A3, INPUT);
}

void loop(){
  Serial.println(checkdistance_A2_A3());
  if (checkdistance_A2_A3() < 10) {
    analogWrite(3,255);

  } else {
    analogWrite(3,0);

  }
  if (checkdistance_A2_A3() > 10) {
    analogWrite(9,255);

  } else {
    analogWrite(9,0);

  }

}
