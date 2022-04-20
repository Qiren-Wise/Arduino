void setup(){
  pinMode(4, INPUT);
  pinMode(3, OUTPUT);
}

void loop(){
  if (digitalRead(4) == LOW) {
    digitalWrite(3,HIGH);
    delay(1000);
    digitalWrite(3,LOW);

  }

}
