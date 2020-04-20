#include <Arduino.h>

class K155NA1{
  private:
    byte pinA;
    byte pinB;
    byte pinC;
    byte pinD;
    
  public:
    K155NA1(byte pinA, byte pinB, byte pinC, byte pinD){
      this->pinA = pinA;
      this->pinB = pinB;
      this->pinC = pinC;
      this->pinD = pinD;
      init();
    }

    void init(){
      pinMode(pinA, OUTPUT);
      pinMode(pinB, OUTPUT);
      pinMode(pinC, OUTPUT);
      pinMode(pinD, OUTPUT);
      off();
    }
    
    void numb(int input) {
      switch (input) {
        case 0:
          digitalWrite(pinA, LOW);
          digitalWrite(pinB, LOW);
          digitalWrite(pinC, LOW);
          digitalWrite(pinD, LOW);
          break;
         case 9:
          digitalWrite(pinA, HIGH);
          digitalWrite(pinB, LOW);
          digitalWrite(pinC, LOW);
          digitalWrite(pinD, HIGH);
          break;
        case 8:
          digitalWrite(pinA, LOW);
          digitalWrite(pinB, LOW);
          digitalWrite(pinC, LOW);
          digitalWrite(pinD, HIGH);
          break;
        case 7:
          digitalWrite(pinA, HIGH);
          digitalWrite(pinB, HIGH);
          digitalWrite(pinC, HIGH);
          digitalWrite(pinD, LOW);
          break;
        case 6:
          digitalWrite(pinA, LOW);
          digitalWrite(pinB, HIGH);
          digitalWrite(pinC, HIGH);
          digitalWrite(pinD, LOW);
          break;
        case 5:
          digitalWrite(pinA, HIGH);
          digitalWrite(pinB, LOW);
          digitalWrite(pinC, HIGH);
          digitalWrite(pinD, LOW);
          break;
       case 4:
          digitalWrite(pinA, LOW);
          digitalWrite(pinB, LOW);
          digitalWrite(pinC, HIGH);
          digitalWrite(pinD, LOW);
          break;
       case 3:
          digitalWrite(pinA, HIGH);
          digitalWrite(pinB, HIGH);
          digitalWrite(pinC, LOW);
          digitalWrite(pinD, LOW);
          break;
       case 2:
          digitalWrite(pinA, LOW);
          digitalWrite(pinB, HIGH);
          digitalWrite(pinC, LOW);
          digitalWrite(pinD, LOW);
          break;
       case 1:
          digitalWrite(pinA, HIGH);
          digitalWrite(pinB, LOW);
          digitalWrite(pinC, LOW);
          digitalWrite(pinD, LOW);
          break;
      }
   }
   void off() {
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
   }
};
