#include <SD.h>
#include <SPI.h>

File myFile;

#define PIN_SD_CS 10
#define FILEPATH "/PATH.CSV"

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

  // Delete PATH.CSV if exist.
  if(SD.exists(FILEPATH)) {
    SD.remove(FILEPATH);
  }
  
  

  // READING THE FILE
  myFile = SD.open(FILEPATH, FILE_WRITE);

  myFile.println("header_x,header_y");

  for (double x = -2; x <= 2; x = x + 0.001) {
    double y = compute_path(x);

    String str_y = String(y);
    if (str_y.equals(" NAN")) {
      // If y is not a number (divided by 0) then blank.
      str_y = "";
    }

    myFile.print(x);
    myFile.print(",");
    myFile.println(str_y);
  }

  myFile.close();
  
  Serial.println("Done writing path!");
}



void loop() {
  // Do nothing
}

double compute_path(double x) {

  double value = sqrt(cos(x)) * cos(200*x) + sqrt(abs(x)) - (PI/4) * pow((4 - pow(x, 2)), 0.01);

  return value;

}
