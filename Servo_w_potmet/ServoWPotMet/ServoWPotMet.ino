#include <Servo.h>
int potmet = A0;
Servo myservo;
int pos = 0;
int analogValue = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(potmet, INPUT);
myservo.attach(4,0,180);
myservo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogValue = analogRead(potmet);
  pos = map(analogValue,0,1023,0,180);
  myservo.write(pos);
  Serial.print("Angle: ");
  Serial.print(pos);
  Serial.println("°");
}
