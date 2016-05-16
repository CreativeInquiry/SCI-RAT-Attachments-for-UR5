const int DIR = 2;
const int PWM = 3;

void setup() {
  //Connect to serial
  Serial.begin(9600);

  //Initialize motor controller
  Serial.print("Initializing motor controller. \n");
      
  pinMode(DIR,OUTPUT);
  pinMode(PWM,OUTPUT);

  digitalWrite(DIR,HIGH);
  analogWrite(PWM,0);
}

void loop() {

  //Control Ryobi with char commands
  if(Serial.available()) {
    char c = Serial.read();
    switch(c) {
    //Switching direction
    case '<':
      digitalWrite(DIR,HIGH);
      Serial.print("Direction 1 (<). \n");
      break;
    case '>':
      digitalWrite(DIR,LOW);
      Serial.print("Direction 2 (>). \n");
      break;
    //Adjustable Speed
    case '0':
      analogWrite(PWM,0);
      Serial.print("Speed 0. \n");
      break;
    case '1':
      analogWrite(PWM,64);
      Serial.print("Speed 1. \n");
      break;
    case '2':
      analogWrite(PWM,128);
      Serial.print("Speed 2. \n");
      break;
    case '3':
      analogWrite(PWM,192);
      Serial.print("Speed 3. \n");
      break;
    case '4':
      analogWrite(PWM,255);
      Serial.print("Speed 4. \n");
      break;
    default:
      Serial.print("Bad command. \n");
      break;
    }
  }
 
}
