#include <IRremote.h>

long ir_item;
IRrecv irrecv_9(9);
decode_results results_9;

float checkdistance_A4_A5() {
  digitalWrite(A4, LOW);
  delayMicroseconds(2);
  digitalWrite(A4, HIGH);
  delayMicroseconds(10);
  digitalWrite(A4, LOW);
  float distance = pulseIn(A3, HIGH) / 58.00;
  delay(10);
  return distance;
}



void setup(){
  irrecv_9.enableIRIn();
    Serial.begin(9600);
  pinMode(A4, OUTPUT);
  pinMode(A5, INPUT);
}

void loop(){
  if (irrecv_9.decode(&results_9)) {
    ir_item=results_9.value;
    String type="UNKNOWN";
    String typelist[14]={"UNKNOWN", "NEC", "SONY", "RC5", "RC6", "DISH", "SHARP", "PANASONIC", "JVC", "SANYO", "MITSUBISHI", "SAMSUNG", "LG", "WHYNTER"};
    if(results_9.decode_type>=1&&results_9.decode_type<=13){
      type=typelist[results_9.decode_type];
    }
    Serial.print("IR TYPE:"+type+"  ");
    Serial.println(ir_item,HEX);
    irrecv_9.resume();
  } else {
  }
Serial.println(checkdistance_A4_A5());

}
