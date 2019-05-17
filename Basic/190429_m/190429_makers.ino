int state = 1;
int cnt = 0;
int LED = 0;

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  digitalWrite(13, LED);
}

void loop() {
  int a = digitalRead(2);
  if(a == 0){
    if(state == 1) state = 0;
  }
  else if(a == 1){

    if(state == 0){
      cnt++;
      if(cnt == 2){
        digitalWrite(13, (LED^=1));
        cnt = 0; 
      }
      state = 1;
    }
    
  }

}
