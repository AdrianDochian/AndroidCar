// surse de inspirație
// 1) https://github.com/CytronTechnologies/Cytron-Shield2AMotor pentru determinarea pinilor de control
// 2) https://www.youtube.com/watch?v=jxnIclUFjJg&feature=youtu.be 

char command;

// LEFT MOTOR
int LEFT_MOTOR_DIRECTION  = 4;
int LEFT_MOTOR_SPEED = 5;

// RIGHT MOTOR
int RIGHT_MOTOR_DIRECTION  = 7;
int RIGHT_MOTOR_SPEED = 6;

int maxSpeed = 255;
int actualSpeed = maxSpeed;


void setup() {
  pinMode(LEFT_MOTOR_SPEED, OUTPUT);
  pinMode(LEFT_MOTOR_DIRECTION, OUTPUT);  
  pinMode(RIGHT_MOTOR_SPEED, OUTPUT);
  pinMode(RIGHT_MOTOR_DIRECTION, OUTPUT);

  Serial.begin(9600);
}


void goForward() {
  digitalWrite(LEFT_MOTOR_DIRECTION, HIGH);
  analogWrite(LEFT_MOTOR_SPEED, actualSpeed);

  digitalWrite(RIGHT_MOTOR_DIRECTION, HIGH);
  analogWrite(RIGHT_MOTOR_SPEED, actualSpeed);
}

void goBackward() {
  digitalWrite(LEFT_MOTOR_DIRECTION, LOW);
  analogWrite(LEFT_MOTOR_SPEED, actualSpeed);

  digitalWrite(RIGHT_MOTOR_DIRECTION, LOW);
  analogWrite(RIGHT_MOTOR_SPEED, actualSpeed);
}

void stopCar() {
  digitalWrite(LEFT_MOTOR_DIRECTION, LOW);
  digitalWrite(RIGHT_MOTOR_DIRECTION, LOW);
  analogWrite(LEFT_MOTOR_SPEED, LOW);
  analogWrite(RIGHT_MOTOR_SPEED, LOW);
}

void goForwardLeft() {
  digitalWrite(LEFT_MOTOR_DIRECTION, LOW);
  analogWrite(LEFT_MOTOR_SPEED, actualSpeed);

  digitalWrite(RIGHT_MOTOR_DIRECTION, HIGH);
  analogWrite(RIGHT_MOTOR_SPEED, actualSpeed);
}

void goForwardRight() {
  digitalWrite(LEFT_MOTOR_DIRECTION, HIGH);
  analogWrite(LEFT_MOTOR_SPEED, actualSpeed);

  digitalWrite(RIGHT_MOTOR_DIRECTION, LOW);
  analogWrite(RIGHT_MOTOR_SPEED, actualSpeed);
}

void goBackwardLeft() {
  digitalWrite(LEFT_MOTOR_DIRECTION, HIGH);
  analogWrite(LEFT_MOTOR_SPEED, actualSpeed);

  digitalWrite(RIGHT_MOTOR_DIRECTION, LOW);
  analogWrite(RIGHT_MOTOR_SPEED, actualSpeed);
}

void goBackwardRight() {
  digitalWrite(LEFT_MOTOR_DIRECTION, LOW);
  analogWrite(LEFT_MOTOR_SPEED, actualSpeed);

  digitalWrite(RIGHT_MOTOR_DIRECTION, HIGH);
  analogWrite(RIGHT_MOTOR_SPEED, actualSpeed);
}

void loop() {
  if (Serial.available()) {
    command = Serial.read();
    Serial.println(command);
    
    if (command == 'S') {
      stopCar();
    } else if (command == 'F') {
      goForward();
    } else if (command == 'B') {
      goBackward();
    } else if (command == 'G') {
      goForwardLeft();
    } else if (command == 'I') {
      goForwardRight();
    } else if (command == 'H') {
      goBackwardLeft();
    } else if (command == 'J') {
      goBackwardRight();
    } else {
      stopCar();
    }
  }
}
