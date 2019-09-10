#include <SoftwareSerial.h>

#define PIN_BT_RX 2
#define PIN_BT_TX 3

SoftwareSerial btSerial(PIN_BT_RX, PIN_BT_TX);

void setup() {
  
  Serial.begin(9600);
  btSerial.begin(38400);

  while(!Serial);
  while(!btSerial);

  Serial.println("Ready to accept AT commands.");
  Serial.println();
}

void loop() {
  
  if (btSerial.available()) {
    char c = btSerial.read();
    Serial.print(c);
  }
  
  if (Serial.available()){
    char c = Serial.read();
    Serial.print(c);
    btSerial.print(c);
  }
}
