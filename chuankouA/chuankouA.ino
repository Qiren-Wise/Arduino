volatile char Light;

void setup(){
  Serial.begin(9600);
  Light = '0';
  pinMode(13, OUTPUT);
}

void loop(){
  //串口，板间的互控
  if (Serial.available() > 0) {
    Light = Serial.read();

  }
  switch (Light) {
   case '1':
    digitalWrite(13,HIGH);
    break;
   case '0':
    digitalWrite(13,LOW);
    break;
  }

}
