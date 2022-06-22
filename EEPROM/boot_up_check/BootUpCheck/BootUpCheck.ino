#include <EEPROM.h>
int mem = 0;

void setup() {
  // put your setup code here, to run once:
  byte data = EEPROM.read(mem);
Serial.begin(9600);
Serial.print("Booted for the ");
Serial.print(data);
Serial.print("th time.");
data++;
EEPROM.write(mem,data);
}

void loop() {
  // put your main code here, to run repeatedly:

}
