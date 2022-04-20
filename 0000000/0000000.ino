void setup(){
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  delay(5000);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  delay(2000);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
}

void loop(){

}
