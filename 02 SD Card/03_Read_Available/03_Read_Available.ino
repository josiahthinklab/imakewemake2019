#include <SD.h>
#include <SPI.h>

#define FILEPATH "test.txt"
#define PIN_SD_CS 10

File myFile;

void setup() {
    
  Serial.begin(9600);
  pinMode(PIN_SD_CS, OUTPUT);
  
  // SD CARD INITIALIZATION
  if (SD.begin(PIN_SD_CS)) {
    Serial.println("SD card is ready to use.");
  } 
  else {
    Serial.println("SD card initialization failed");
    return;
  }

  // READING THE FILE
  myFile = SD.open(FILEPATH);
  
  if (myFile) {
    while (myFile.available()) {
      int numBytesLeft = myFile.available();
      
      char c = myFile.read();
      Serial.print(numBytesLeft);
      Serial.print("\t");
      Serial.print(c);
      Serial.print("\t");
      Serial.println(int(c));
    }
    myFile.close();
  }
  else {
    Serial.println("error opening test.txt");
  }
  
}

void loop() {
  // Do nothing
}
