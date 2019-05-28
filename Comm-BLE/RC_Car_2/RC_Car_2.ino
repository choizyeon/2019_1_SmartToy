#include <SoftwareSerial.h>
 
SoftwareSerial BTSerial(4, 5);
 
int in1 = 9;
int in2 = 6;
int in3 = 10;
int in4 = 11;
 
int RSpeed = 212;
int LSpeed = 206;
 
char data;
 
void setup() {
  BTSerial.begin(9600);
  Serial.begin(9600);
}
 
void loop() {
  if (BTSerial.available()) {
    data = BTSerial.read();
 
    if (data == 'f') { //직진
      analogWrite(in1, RSpeed);
      analogWrite(in2, 0);
      analogWrite(in3, 0);
      analogWrite(in4, LSpeed); 
      Serial.println("직진");
    }
    if (data == 'r') { //우회전
      analogWrite(in1, 100);
      analogWrite(in2, 0);
      analogWrite(in3, 0);
      analogWrite(in4, LSpeed);
      Serial.println("우회전");
    }
    if (data == 'l') { //좌회전
      analogWrite(in1, RSpeed);
      analogWrite(in2, 0);
      analogWrite(in3, 0);
      analogWrite(in4,100);
      Serial.println("좌회전");
    }
    if (data == 'b') { //후진
      analogWrite(in1, 0);
      analogWrite(in2, RSpeed);
      analogWrite(in3, LSpeed);
      analogWrite(in4, 0);
      Serial.println("후진");
    }
    if (data == 's') { //정지
      analogWrite(in1, 0);
      analogWrite(in2, 0);
      analogWrite(in3, 0);
      analogWrite(in4, 0);
      Serial.println("정지");
    }
  }
}
 
