int cnt = 0;
int t = 0;
void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
}

void loop() {
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);
  int distance = pulseIn(3, HIGH) * 170/10000;
  
  if (distance < 50){
    if(t==0){
      cnt++;
    }
    t = 1;
  }
  else if(distance >= 50){
    t = 0;
  }
  
  Serial.println(distance);
  Serial.print("\t");
  Serial.println(cnt);
  delay(50);
}
