#include <AFMotor.h>
#include <Servo.h>

int trigpin=A0,echopin=A1;
int left=A3,right=A2;
int right_val,left_val;
long duration;
int distance;

AF_DCMotor Motor1(1);
AF_DCMotor Motor2(2);
AF_DCMotor Motor3(3);
AF_DCMotor Motor4(4);

Servo myservo;

void setup() {
  Serial.begin(9600);
  myservo.attach(10);
  
  pinMode(right, INPUT);
  pinMode(left, INPUT);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
}

void loop() {
  digitalWrite(trigpin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigpin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  
  right_val=digitalRead(right);
  left_val=digitalRead(left);

  if((right_val==1) && (distance>=10 && distance<=25)&&(left_val==1)){     // MOVE FORWARD
    Motor1.setSpeed(150);
    Motor1.run(FORWARD);
    Motor2.setSpeed(150);
    Motor2.run(FORWARD);
    Motor3.setSpeed(150);
    Motor3.run(FORWARD);
    Motor4.setSpeed(150);
    Motor4.run(FORWARD);
  }

  else if((right_val==0) && (left_val==1)) {                               // MOVE LEFT
    Motor1.setSpeed(200);
    Motor1.run(FORWARD);
    Motor2.setSpeed(100);
    Motor2.run(BACKWARD);
    Motor3.setSpeed(100);
    Motor3.run(BACKWARD);
    Motor4.setSpeed(200);
    Motor4.run(FORWARD);  
  }

  else if((right_val==1)&&(left_val==0)) {                                 //MOVE RIGHT
    Motor1.setSpeed(100);
    Motor1.run(BACKWARD); 
    Motor2.setSpeed(200);
    Motor2.run(FORWARD);
    Motor3.setSpeed(200);
    Motor3.run(FORWARD);
    Motor4.setSpeed(100);
    Motor4.run(BACKWARD);
  }

  else if(distance > 1 && distance < 10) {                                 //STOP
    Motor1.setSpeed(0);
    Motor1.run(RELEASE);
    Motor2.setSpeed(0);
    Motor2.run(RELEASE);
    Motor3.setSpeed(0);
    Motor3.run(RELEASE);
    Motor4.setSpeed(0);
    Motor4.run(RELEASE);
  }

  else {
    Motor1.setSpeed(0);
    Motor1.run(RELEASE);
    Motor2.setSpeed(0);
    Motor2.run(RELEASE);
    Motor3.setSpeed(0);
    Motor3.run(RELEASE);
    Motor4.setSpeed(0);
    Motor4.run(RELEASE);
  }
}
