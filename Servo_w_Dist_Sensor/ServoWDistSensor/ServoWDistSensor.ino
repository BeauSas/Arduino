#include <Servo.h>
int trigPin = 2;
int echoPin = 3;
int duration = 0;
float distance = 0;
Servo myservo;
int pos = 0;
int state = 0;
int servoSpeed = 20;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
myservo.attach(4,0,180);
myservo.write(0);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration/2*0.0343;
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(100);
  if(distance > 10)
  {
    if(state == 0)
    {
      pos += servoSpeed;
      if(pos == 180)
    {
      state = 1;
    }
    }
    if(state == 1)
    {
      pos -= servoSpeed;
      if(pos == 0)
    {
      state = 0;
    }
    }
  }
  else
  {
    Serial.println("Object too close");
  }
  myservo.write(pos);
}
