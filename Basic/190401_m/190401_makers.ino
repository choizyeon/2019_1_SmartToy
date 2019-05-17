void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT); //13번 핀 output으로 정해서 사용(led와 연결)
  digitalWrite(13, 0); //13번 핀 출력 결정
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, 1);
  delay(500); //0.5초
  digitalWrite(13, 0);
  delay(500);
}
