#include <SD.h>
#include <SPI.h>

File myFile;

#define PIN_SD_CS 10

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
  
  // WRITING TO FILE
  myFile = SD.open("test.txt", FILE_WRITE);   // Create/Open file 
  
  if (myFile) {
    // File Opened.
    Serial.println("Writing to file...");
    
    myFile.println("Testing text 1, 2 ,3...");  // Writing to file

    myFile.close(); // close the file
    Serial.println("Done.");
  }
  else {
    // File did not open, print error.
    Serial.println("error opening test.txt");
  }

  // READING THE FILE
  myFile = SD.open("test.txt");

  if (myFile) {
    Serial.println("Read:");
    // Reading the whole file
    while (myFile.available()) {
      Serial.write(myFile.read());
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
