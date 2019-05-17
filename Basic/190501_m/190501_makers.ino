unsigned long pre_t = 0;
unsigned long pre_t2 = 0;
unsigned long cur_t = 0;

int LED = 0;
int LED2 = 0;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(11,OUTPUT);
  digitalWrite(13, LED);
  digitalWrite(11,LED2);
}

void loop() {
  cur_t = millis();
  if(cur_t - pre_t > 500){
    /*if(LED == 0) LED = 1;
    else         LED = 0;
    digitalWrite(13, LED);*/
    digitalWrite(13, LED^=1);
    pre_t = cur_t;
  }
  if(cur_t - pre_t2 > 800){
    digitalWrite(11, LED2^=1);
    pre_t2 = cur_t;
  }
}
