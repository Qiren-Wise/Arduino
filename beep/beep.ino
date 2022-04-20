void setup(){
  pinMode(4, INPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop(){
  if (digitalRead(4) == false) {
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    delay(1000);

  } else {
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    delay(1000);

  }

}
