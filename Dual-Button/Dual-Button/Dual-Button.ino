int btnOn = 2;
int btnOff = 3;
int led = 4;
int buttonOnState = 0;
int buttonOffState = 0;

/*How the pinout works for dual-button:
 * - R1 & R2 go to gnd
 * - I(one) & I(one) go to power
 * - O(One) goes to D2
 * - O2 goes to D3
 */

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(btnOn, INPUT);
pinMode(btnOff, INPUT);
pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
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
