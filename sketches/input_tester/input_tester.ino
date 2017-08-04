void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A1);
  float voltage = sensorValue * (5.0 / 1023.0); //convert analog read to voltage 0-5v
  Serial.println(voltage);
  delay(500);
}
