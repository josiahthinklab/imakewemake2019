#include <SoftwareSerial.h>

#define PIN_SIM800_RX 2
#define PIN_SIM800_TX 3

#define DEBUG_TRUE true
#define DEBUG_FALSE false

SoftwareSerial sim800Serial(PIN_SIM800_RX, PIN_SIM800_TX);

void setup() {
  Serial.begin(38400);
  sim800Serial.begin(9600);

  while(!Serial);
  while(!sim800Serial);

  delay(1000);

  initGSM();

  //sendMessage("222", "BAL");   // Globe Check Balance
  
  //send_msg("214", "?1515"); // Smart Check Balance
}

void loop() {
  
  if(Serial.available()) {
    // Sending commands to GSM Module
    String serial_data = Serial.readString();
    sim800Serial.println(serial_data);
  }

  checkGsmResponse(); 
}
