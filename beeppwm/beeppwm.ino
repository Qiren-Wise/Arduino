void setup(){
  pinMode(4, INPUT);
  pinMode(4, OUTPUT);
}

void loop(){
  if (digitalRead(4) == false) {
    tone(4,131);
    delay(1000);

  } else {
    noTone(4);

  }

}
