int btnOn = 2;
int btnOff = 3;
int led = 4;
int buttonOnState = 0;
int buttonOffState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(btnOn, INPUT);
  pinMode(btnOff, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
 buttonOnState = digitalRead(btnOn);
 buttonOffState = digitalRead(btnOff);

 if(buttonOnState == HIGH)
 {
  digitalWrite(led, HIGH);
  Serial.println("On is pressed");
 }
 if(buttonOffState == HIGH)
 {
  digitalWrite(led, LOW);
  Serial.println("Off is pressed");
 }
}
