#include <Servo.h>

int btnOn = 2;
int btnOff = 3;
Servo myservo;
int buttonOnState = 0;
int buttonOffState = 0;
int pos = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(btnOn, INPUT);
pinMode(btnOff, INPUT);
myservo.attach(4,0,180);
myservo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
buttonOnState = digitalRead(btnOn);
 buttonOffState = digitalRead(btnOff);

 if(buttonOnState == HIGH && pos < 180)
 {
  myservo.write(pos);
  delay(100);
  pos += 20;
  if(pos == 180)
  {
    buttonOnState = LOW;
  }
  Serial.print("Angle: ");
  Serial.print(pos);
  Serial.println("°");
 }
 if(buttonOffState == HIGH && pos > 0)
 {
  myservo.write(pos);
  delay(100);
  pos -= 20;
  if(pos == 0)
  {
    buttonOnState = LOW;
  }
  Serial.print("Angle: ");
  Serial.print(pos);
  Serial.println("°");
}
}
