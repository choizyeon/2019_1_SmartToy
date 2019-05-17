/*
 * Double click toggle switch with click speed check
 * 더블클릭 빨리 했을 때만 LED 끄고 켜짐
 */

 int cnt = 0;
 int state = 1;
 int LED = 0;
 unsigned long cur_t = 0;
 unsigned long pre_t = 0;
 
void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  digitalWrite(13, LED);
  Serial.begin(9600);

}

void loop() {
  int a = digitalRead(2);
  
  if(a == 0){
    if(state == 1) state = 0;
  }
  else if(a == 1){
    if(state == 0){
      cnt++;
      if(cnt == 1)  pre_t = millis();
      if(cnt == 2){
        cur_t = millis();
        if(cur_t - pre_t < 500) digitalWrite(13, (LED^=1));
        cnt = 0;
        Serial.println(cur_t - pre_t);
      }
      state = 1;
    }   
  }
  
}
