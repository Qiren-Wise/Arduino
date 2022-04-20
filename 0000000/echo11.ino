float checkdistance_A4_A5() {
  digitalWrite(A4, LOW);
  delayMicroseconds(2);
  digitalWrite(A4, HIGH);
  delayMicroseconds(10);
  digitalWrite(A4, LOW);
  float distance = pulseIn(A5, HIGH) / 58.00;
  delay(10);
  return distance;
}

void setup(){
  Serial.begin(9600);
  pinMode(A4, OUTPUT);
  pinMode(A5, INPUT);
}

void loop(){
  Serial.println(checkdistance_A4_A5());

}
