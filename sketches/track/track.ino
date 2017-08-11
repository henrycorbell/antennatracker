
  
void setup() {
  Serial.begin(9600);
}

void select() {
int rx1 = analogRead(A1);
int rx2 = analogRead(A2);
  float u1 = rx1 * (5.0 / 1023.0);
  float u2 = rx2 * (5.0 / 1023.0);//convert analog read to voltage 0-5v
  Serial.print("rx 1: ");
  Serial.print(u1);
  Serial.println("");
  Serial.print("rx 2: ");
  Serial.print(u2);
  Serial.println("");
  delay(3000);
}

void turn() {
  int rx1 = analogRead(A1);
  int rx2 = analogRead(A2);
  float u1 = rx1 * (5.0 / 1023.0);
  float u2 = rx2 * (5.0 / 1023.0);//convert analog read to voltage 0-5v
  if(u1 >= 1.05) {
    Serial.println("RX1 HIGH");
  }
  else if(u1 <= 0.5) {
    Serial.println("RX1 LOW");
  }
  else if(u2 >= 1.05) {
    Serial.println("RX2 HIGH");
  }
  else if(u2 <= 0.5) {
    Serial.println("RX2 LOW");
  }
}

void choose() {
  int rx1 = analogRead(A1);
  int rx2 = analogRead(A2);
  float u1 = rx1 * (5.0 / 1023.0);
  float u2 = rx2 * (5.0 / 1023.0);//convert analog read to voltage 0-5v
  int option = 0;

  if(u1>u2) {
    int option = 1;
    Serial.println("RX1");
  }
  else if(u1<u2) {
    int option = 2;
    Serial.println("RX2");
  }
}

void loop() {
  select();
  choose();
}
