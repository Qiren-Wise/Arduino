
#include <Stepper.h>

Stepper mystepper(100,1,2,3,4);

void setup(){
  pinMode(12, INPUT);
  mystepper.setSpeed(10);
}

void loop(){
  if (digitalRead(12) == false) {
    mystepper.step(100);

  } else {
    mystepper.step(0);

  }

}
