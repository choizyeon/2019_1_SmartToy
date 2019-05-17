int speakerpin = 3; //스피커가 연결된 디지털핀 설정
int incomingByte = 0;
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    
    if(incomingByte == '1'){
      tone(speakerpin,261,700);  //500: 음의 높낮이(주파수), 1000: 음의 지속시간(1초)
      Serial.print("도");
    }
    else if(incomingByte == '2'){
      tone(speakerpin,293,700);
      Serial.print("레");
    }
    else if(incomingByte == '3'){
      tone(speakerpin,329,700);
      Serial.print("미");
    }
    else if(incomingByte == '4'){
      tone(speakerpin,349,700);
      Serial.print("파");
    }
    else if(incomingByte == '5'){
      tone(speakerpin,392,700);
      Serial.print("솔");
    }
    else if(incomingByte == '6'){
      tone(speakerpin,440,700);
      Serial.print("라");
    }
    else if(incomingByte == '7'){
      tone(speakerpin,494,700);
      Serial.print("시");
    }
    
  }
}

