#include <SoftwareSerial.h>

#define PIN_LED 13

#define PIN_BT_RX 2
#define PIN_BT_TX 3

SoftwareSerial btSerial(PIN_BT_RX, PIN_BT_TX);

void setup() {
  pinMode(PIN_LED, OUTPUT);
  
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

    if (c == 'a') {
      digitalWrite(PIN_LED, HIGH);
    }
    else if (c == 'b') {
      digitalWrite(PIN_LED, LOW);
    }
  }
  
  if (Serial.available()){
    char c = Serial.read();
    Serial.print(c);
    btSerial.print(c);
  }
}
