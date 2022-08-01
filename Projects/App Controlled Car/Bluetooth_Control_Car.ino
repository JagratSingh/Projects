#include <AFMotor.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(9, 10);             //RX,TX

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

char value;
int led1=A0,led2=A1,led3=A2; 
int buzzpin=A3;

void setup() {
 bluetoothSerial.begin(9600);
 
 pinMode(led1,OUTPUT);
 pinMode(led2,OUTPUT);
 pinMode(led3,OUTPUT);
 pinMode(buzzpin,OUTPUT);
}

void loop() {
  if(bluetoothSerial.available()>0)
  {
    value = bluetoothSerial.read();
    bluetoothSerial.println(value);
  }

  if(value=='F')                                              //FORWARD
  {
    motor1.setSpeed(220);
    motor1.run(FORWARD);
    motor2.setSpeed(220);
    motor2.run(FORWARD);
    motor3.setSpeed(220);
    motor3.run(FORWARD);
    motor4.setSpeed(220);
    motor4.run(FORWARD);
  }
  if(value=='B')                                               //BACKWARD
  {
    motor1.setSpeed(220);
    motor1.run(BACKWARD);
    motor2.setSpeed(220);
    motor2.run(BACKWARD);
    motor3.setSpeed(220);
    motor3.run(BACKWARD);
    motor4.setSpeed(220);
    motor4.run(BACKWARD);
  }
  if(value=='R')                                                //RIGHT
  {
    motor1.setSpeed(220);
    motor1.run(BACKWARD);
    motor2.setSpeed(220);
    motor2.run(FORWARD);
    motor3.setSpeed(220);
    motor3.run(FORWARD);
    motor4.setSpeed(220);
    motor4.run(BACKWARD);
  }
  if(value=='L')                                                 //LEFT 
  {
    motor1.setSpeed(220);
    motor1.run(FORWARD);
    motor2.setSpeed(220);
    motor2.run(BACKWARD);
    motor3.setSpeed(220);
    motor3.run(BACKWARD);
    motor4.setSpeed(220);
    motor4.run(FORWARD);
  }

  if (value=='r')                                                 //NORTH-EAST
  {
    motor1.setSpeed(70);
    motor1.run(FORWARD);
    motor2.setSpeed(220);
    motor2.run(FORWARD);
    motor3.setSpeed(220);
    motor3.run(FORWARD);
    motor4.setSpeed(70);
    motor4.run(FORWARD);
  }

  if (value=='l')                                                   //NORTH-WEST
  {
    motor1.setSpeed(220);
    motor1.run(FORWARD);
    motor2.setSpeed(70);
    motor2.run(FORWARD);
    motor3.setSpeed(70);
    motor3.run(FORWARD);
    motor4.setSpeed(220);
    motor4.run(FORWARD);
  }

  if (value=='n')                                                 //SOUTH-EAST
  {
    motor1.setSpeed(70);
    motor1.run(BACKWARD);
    motor2.setSpeed(220);
    motor2.run(BACKWARD);
    motor3.setSpeed(220);
    motor3.run(BACKWARD);
    motor4.setSpeed(70);
    motor4.run(BACKWARD);
  }

  if (value=='m')                                                   //SOUTH-WEST
  {
    motor1.setSpeed(220);
    motor1.run(BACKWARD);
    motor2.setSpeed(70);
    motor2.run(BACKWARD);
    motor3.setSpeed(70);
    motor3.run(BACKWARD);
    motor4.setSpeed(220);
    motor4.run(BACKWARD);
  }
  
  if(value=='Y')                                           //LED ON
  {
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
  }
  if(value=='y')                                           //LED OFF
  {
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
  }
  if(value=='Z')
  {
    digitalWrite(buzzpin,HIGH);
  }
  if(value=='S')
  {
    digitalWrite(buzzpin,LOW);
    motor1.setSpeed(0);
    motor1.run(RELEASE);
    motor2.setSpeed(0);
    motor2.run(RELEASE);
    motor3.setSpeed(0);
    motor3.run(RELEASE);
    motor4.setSpeed(0);
    motor4.run(RELEASE);
  }
}
