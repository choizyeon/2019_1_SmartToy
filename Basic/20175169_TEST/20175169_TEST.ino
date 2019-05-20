

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(11, 0);
  digitalWrite(12, 0);
}

void loop() {
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);
  int dis = pulseIn(3, HIGH) * 170/10000;

  if (dis < 30){ //LED 2개 킴
    digitalWrite(11, 1);
    digitalWrite(12, 1);
  }
  else if (dis >= 30 && dis <=60 ){ //LED 1개 킴
    digitalWrite(11, 1);
    digitalWrite(12, 0);
  }
  else if (dis > 60){ //LED 끔
    digitalWrite(11, 0);
    digitalWrite(12, 0);
  }
  Serial.println(dis);
  delay(50);
}
