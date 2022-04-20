void setup(){
  Serial.begin(9600);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
}

void loop(){
  Serial.println(digitalRead(A4));
  if (digitalRead(A4) == false) {
    analogWrite(3,150);

  } else {
    analogWrite(3,0);

  }
  if (digitalRead(A5) == false) {
    analogWrite(9,200);

  } else {
    analogWrite(9,0);

  }

}
