char value;
int led1=8,led2=9,led3=10,led4=11,led5=12;

void setup() {
Serial.begin(9600);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
pinMode(led5,OUTPUT);
}

void loop() {
if(Serial.available())
{
 value = Serial.read();
 Serial.println(value); 
}
if(value=='A')
{
  digitalWrite(led1,HIGH);
}
if(value=='B')
{
  digitalWrite(led2,HIGH);
}
if(value=='C')
{
  digitalWrite(led3,HIGH);
}
if(value=='D')
{
  digitalWrite(led4,HIGH);
}
if(value=='E')
{
  digitalWrite(led5,HIGH);
}
if(value=='a')
{
  digitalWrite(led1,LOW);
}
if(value=='b')
{
  digitalWrite(led2,LOW);
}
if(value=='c')
{
  digitalWrite(led3,LOW);
}
if(value=='d')
{
  digitalWrite(led4,LOW);
}
if(value=='e')
{
  digitalWrite(led5,LOW);
}
}
