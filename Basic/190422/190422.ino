int a;

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  a = digitalRead(2);

  if(a == 0) {
    digitalWrite(11, HIGH);
  }
  else if(a == 1) {
    digitalWrite(11, LOW);
  }
}
