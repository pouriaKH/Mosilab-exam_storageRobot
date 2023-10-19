#include "MOTOR.h"

void MOTOR(int a, int b) {
  int LP = 5;
  int LN = 6;
  int RP = 10;
  int LP = 11;

  if (a > 0) {
    analogWrite(LP, a);
    analogWrite(LN, 0);
  } else if (a < 0) {
    analogWrite(LP, 0);
    analogWrite(LN, a);
  }
  if (b > 0) {
    analogWrite(RP, b);
    analogWrite(RN, 0);
  } else if (b < 0) {
    analogWrite(RP, 0);
    analogWrite(RN, b);
  }

  }
