int IN1 = 9;
int IN2 = 6;
int IN3 = 10;
int IN4 = 11;
int enA = 12;
int enB = 13;

int motorSpeedA = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);  
  
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(IN1, OUTPUT);    
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);    
  pinMode(IN4, OUTPUT);

  // Set initial rotation direction
  // forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  // Initial speed
  motorSpeedA = 50;
  
}
 
void loop() {

  analogWrite(enB, motorSpeedA); 
  analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
}



void serialEvent() {
  while (Serial.available()) 
  {
    // get the new byte:
    char inChar = (char)Serial.read();
    
    if(inChar == '0')
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      
    }
    else if(inChar == 'f')
    {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);      
    }
    else if(inChar == 'b')
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);      
    }
    else if(inChar == 'w')
    {
      motorSpeedA = motorSpeedA + 10;
   
      if (motorSpeedA > 255) 
      {
        motorSpeedA = 255;
      }
      
      Serial.println(motorSpeedA);
      
    }
    else if(inChar == 's')
    {
      motorSpeedA = motorSpeedA - 10;
   
      if (motorSpeedA < 0) 
      {
        motorSpeedA = 0;
      }
      
      Serial.println(motorSpeedA);
      
    }




    
  }
}
