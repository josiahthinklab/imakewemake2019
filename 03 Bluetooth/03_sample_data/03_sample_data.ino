#define PIN_LED 13

void setup() {
  Serial.begin(38400);
}

void loop() {

  if (Serial.available()) {
    char c = Serial.read();

    if (c == 'a') {

      double sample_value = getSample();
      Serial.println(sample_value);
      
    }
  }
}

double getSample() {
  double sample_value = 98.5;

  return sample_value;
}
