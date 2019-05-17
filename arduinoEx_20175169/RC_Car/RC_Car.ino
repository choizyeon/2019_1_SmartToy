
#include <SoftwareSerial.h>
 
SoftwareSerial BTSerial(4, 5);
 
int in1 = 9;
int in2 = 6;
int in3 = 10;
int in4 = 11;

int enA = 12;
int enB = 13;
 
int MSpeed = 255;
//int LSpeed = 255;
 
char data;
 
void setup() {
  BTSerial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
}
 
void loop() {
  //analogWrite(enA, MSpeed);
  //analogWrite(enB, MSpeed);

  
  if (BTSerial.available()) {
    data = BTSerial.read();
 
    if (data == 'f') { //직진
      analogWrite(in1, MSpeed);
      analogWrite(in2, 0);
      analogWrite(in3, 0);
      analogWrite(in4, MSpeed); 
    }
    if (data == 'r') { //우회전
      analogWrite(in1, 0);
      analogWrite(in2, 0);
      analogWrite(in3, 0);
      analogWrite(in4, MSpeed);
    }
    if (data == 'l') { //좌회전
      analogWrite(in1, MSpeed);
      analogWrite(in2, 0);
      analogWrite(in3, 0);
      analogWrite(in4, 0);
    }
    if (data == 'b') { //후진
      analogWrite(in1, 0);
      analogWrite(in2, MSpeed);
      analogWrite(in3, MSpeed);
      analogWrite(in4, 0);
    }
    if (data == 's') { //정지
      analogWrite(in1, 0);
      analogWrite(in2, 0);
      analogWrite(in3, 0);
      analogWrite(in4, 0);
    }
/*
    else if(data == 'w')
    {
      MSpeed += 10;

      if (MSpeed > 255) 
      {
        MSpeed = 255;
      }      
    }
    else if(data == 's')
    {
      MSpeed -= 10;
   
      if (MSpeed < 0) 
      {
        MSpeed = 0;
      }
    }
*/
    
  }
}
