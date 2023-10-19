#include "IR.h"

void IRCheak() {
  int IR1;
  int IR2;
  int IR3;
  int IR4;


  int MinBlackAmount = 900 ; 
  int IRReturnp[4];
  IRReturn[0] = analogRead(IR1);
  IRReturn[1] = analogRead(IR2);
  IRReturn[2] = analogRead(IR3);
  IRReturn[3] = analogRead(IR4);

  for (int i = 0; i < 3; i++) {
    if (IRReturn[i] > 900) {
      GIRV[i] = 1 ;
    }else {
      GIRV[i] = 0 ; 
    }
  }
}