void setup(){
  pinMode(A0, INPUT);
  pinMode(3, OUTPUT);
}

void loop(){
  if (digitalRead(A0) == false) {
    digitalWrite(3,HIGH);

  } else {
    digitalWrite(3,LOW);

  }


}
