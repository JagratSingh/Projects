#include <Keypad.h>
#include <Servo.h>

int servopin=10, servopos;
int buzzpin=13;
int position=0;
char* password="76783";
char kyprsd;

int redpin=11,greenpin=12;

const byte ROWS=4;
const byte COLS=4;

byte Keys[ROWS][COLS]{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowpins[ROWS]={9,8,7,6};
byte colpins[COLS]={5,4,3,2};

Servo myservo;
Keypad mykeypad=Keypad(makeKeymap(Keys),rowpins,colpins,ROWS,COLS);

void setup(){
  Serial.begin(9600);
  pinMode(redpin,OUTPUT);
  pinMode(greenpin,OUTPUT);
  pinMode(buzzpin,OUTPUT);
  myservo.attach(servopin);
  myservo.write(0);
  digitalWrite(redpin,HIGH);
}

void loop(){
  kyprsd=mykeypad.getKey();  
  if (kyprsd==password[position] ){
    position++;
  }
  
  if (position==5){
    myservo.write(100);
    digitalWrite(redpin,LOW);
    digitalWrite(greenpin,HIGH);
    digitalWrite(buzzpin,HIGH);
  }
  
  if(kyprsd=='*' || kyprsd=='#'){
    position=0;
    myservo.write(0);
    digitalWrite(redpin,HIGH);
    digitalWrite(greenpin,LOW);
    digitalWrite(buzzpin,LOW);
  }
  
  if(kyprsd=='1' || kyprsd=='4' || kyprsd=='5' || kyprsd=='2' || kyprsd=='9' || kyprsd=='0'){
    position=0;
    myservo.write(0);
    digitalWrite(redpin,HIGH);
    digitalWrite(greenpin,LOW);
    digitalWrite(buzzpin,LOW);
  }
  
  if(kyprsd=='A' || kyprsd=='B' || kyprsd=='C' || kyprsd=='D' ){
    digitalWrite(buzzpin,LOW);
  }
}
