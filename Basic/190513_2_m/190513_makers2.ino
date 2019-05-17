#include <Stepper.h>
int res = 2038;
Stepper stepper(res, 11, 9, 10, 8); //per  4, 2, 3, 1

void setup() {
  stepper.setSpeed(15);
  
}

void loop() {
  stepper.step(res);
  delay(500);
  stepper.step(-res);
  delay(500);
}
