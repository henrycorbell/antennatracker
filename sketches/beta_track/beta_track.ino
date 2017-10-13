#include <Servo.h>
Servo myservo;
int pos = 0;  
  
void setup() {
  Serial.begin(9600);
}

void select() {
  int rx1 = analogRead(A1);
  int rx2 = analogRead(A2);
  float u1 = rx1 * (5.0 / 1023.0);
  float u2 = rx2 * (5.0 / 1023.0);
  float v1 = u1 * 5.0;
  float v2 = u2 * 5.0;
//////////////////////////////////////

  Serial.print("rx 1: ");     ////
  Serial.print(v1);           //
  Serial.println("");         //
  Serial.print("rx 2: ");     //  print rx values
  Serial.print(v2);           //  
  Serial.println("");         ////
  delay(3000);
  
}

void choose() {
  int rx1 = analogRead(A1);
  int rx2 = analogRead(A2);
  float u1 = rx1 * (5.0 / 1023.0);
  float u2 = rx2 * (5.0 / 1023.0);
  float v1 = u1 * 5.0;
  float v2 = u2 * 5.0;
//////////////////////////////////////  

  if(v1 >= 1.05) {
    Serial.println("RX1 HIGH");
  }
  else if(v1 <= 0.5) {
    Serial.println("RX1 LOW");
  }
  else if(v2 >= 1.05) {
    Serial.println("RX2 HIGH");
  }
  else if(v2 <= 0.5) {
    Serial.println("RX2 LOW");
  }
  
}

void turn() {
  int rx1 = analogRead(A1);
  int rx2 = analogRead(A2);
  float u1 = rx1 * (5.0 / 1023.0);
  float u2 = rx2 * (5.0 / 1023.0);
  float v1 = u1 * 5.0;
  float v2 = u2 * 5.0;
//////////////////////////////////////

  int option = 0;
  if(v1>v2) {
    int option = 1;
    Serial.println("RX1");
    myservo.attach(9);
    pos = 175;
    myservo.write(pos);
    delay(500);
  }
  else if(v1<v2) {
    int option = 2;
    Serial.println("RX2");
    myservo.attach(9);
    pos = 5;
    myservo.write(pos);
    delay(500);
  }
  
}

void loop() {
  select();
  choose();
  turn();
}
