#include <Servo.h>

Servo sv;

void setup() {
  sv.attach(2); //pin
  //pinMode(2, OUTPUT);
}

void loop() {
  /*digitalWrite(2, HIGH);
  delay(2);
  digitalWrite(2, LOW);
  delay(18);*/
  sv.write(0); //원하는 각도로 만들어줌 (0~180도)
}
