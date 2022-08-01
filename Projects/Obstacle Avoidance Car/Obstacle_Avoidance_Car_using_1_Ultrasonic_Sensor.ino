#include <AFMotor.h>
#include <Servo.h> 

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
Servo myservo;

int trigPin=A4,echoPin=A5; 
long duration;
int distance,distanceR,distanceL;

void setup() {
  Serial.begin(9600);
  
  motor1.setSpeed(250);
  motor2.setSpeed(250);
  motor3.setSpeed(250);
  motor4.setSpeed(250);

  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  
  myservo.attach(10);  
  myservo.write(115);
}

void loop() {
  distance=readPing();

  if(distance<=15){
    Stop();
    delay(100);
    moveBackward();
    delay(500);
    Stop();
    delay(100);
    distanceR=lookRight();
    delay(200);
    distanceL=lookLeft();
    delay(200);

    if(distanceR > distanceL) {
      moveRight();
    }
    else moveLeft();
  }
  else moveForward();
}

int readPing() {
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}

void Stop() {
  motor1.run(RELEASE); 
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void moveForward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void moveBackward() {
  motor1.run(BACKWARD);      
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);  
}

void moveRight() {
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD); 
  motor4.run(BACKWARD);
  delay(500);

  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void moveLeft() {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
  delay(500);
  
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

int lookRight()
{
    myservo.write(50); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(115); 
    return distance;
}

int lookLeft()
{
    myservo.write(170); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(115); 
    return distance;
}
