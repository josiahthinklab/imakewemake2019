#define PIN_LED 13

void setup() {
  Serial.begin(9600);

  pinMode(PIN_LED, OUTPUT);
}

void loop() {

  double product = multiply(1.5, 2);
  Serial.println(product);
  
  turnOnLED();
  delay(1000);
  turnOffLED();
  delay(1000);
}
