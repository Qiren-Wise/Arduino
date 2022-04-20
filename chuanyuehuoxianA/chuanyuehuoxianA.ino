#define PIN_trig A5
#define PIN_echo A4

volatile long systick_ms_008;
volatile int distance;
volatile int dis_hold;
volatile int huoxian_mode;

#define DZFW "$DKT:1,1!"//低姿复位
#define DMSQJ "$DKT:9,0!"//低慢速前进
#define GMSQJ "$DKT:2,1!"//高慢速前进
float checkdistance_PIN_trig_PIN_echo() {
  digitalWrite(PIN_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_trig, LOW);
  float distance = pulseIn(PIN_echo, HIGH) / 58.00;
  //delay(10);
  return distance;
}

void my_008_chuanyue_huoxian() {
  if (millis() - systick_ms_008 > 50) {
    systick_ms_008 = millis();
    distance = checkdistance_PIN_trig_PIN_echo();
    if (distance > dis_hold) {
      if (huoxian_mode != 1) {
        huoxian_mode = 1;
        Serial.println(GMSQJ);

      }

    } else {
      Serial.println(DZFW);
      delay(1000);
      distance = checkdistance_PIN_trig_PIN_echo();
      if (distance > dis_hold) {
        Serial.println(DMSQJ);
        delay(1000);

      }
      huoxian_mode = 0;

    }

  }
}

void setup(){
  Serial.begin(115200); //串口初始化

  Serial.println("Init ok~");
  systick_ms_008 = 100;
  distance = 100;
  dis_hold = 15;
  huoxian_mode = 0;
  pinMode(PIN_trig, OUTPUT);
  pinMode(PIN_echo, INPUT_PULLUP);
}

void loop(){
  my_008_chuanyue_huoxian();

}
