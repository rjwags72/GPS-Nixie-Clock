
#include <Wire.h>

#define D 10
#define C 11
#define B 12
#define pina 13


int zero = 0;

void setup() {
  pinMode(pina, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);


}

void loop() {
  writenumber(0, zero);
  zero = zero + 1;
  if(zero > 10){
    zero = 0;
  }
  delay(1000);

}

void writenumber(int a, int b) {
  switch (b) {
    case 0:
      digitalWrite(pina, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 9:
      digitalWrite(pina, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      break;
    case 8:
      digitalWrite(pina, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 7:
      digitalWrite(pina, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      break;
    case 6:
      digitalWrite(pina, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    case 5:
      digitalWrite(pina, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      break;
    case 4:
      digitalWrite(pina, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 3:
      digitalWrite(pina, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      break;
    case 2:
      digitalWrite(pina, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    case 1:
      digitalWrite(pina, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      break;
  }
}

void off(int a) {
  digitalWrite(pina, HIGH);

}
