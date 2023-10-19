#include "Arduino.h"
#include "ColorSensoreFilterChange.h"


int ChangeFilter(int AOrB, int ColorChannel) {  // A == 0 | B == 1
  byte SensoreAS2 = 0;                          //must be defined //ColorChannel             1 == RED  2==Blue 3==Green
  byte SensoreAS3 = 0;
  byte SensoreBS2 = 0;
  byte SensoreBS3 = 0;



  if (AOrB == 0) {
    switch (ColorChannel) {
      case 1:
        digitalWrite(SensoreAS2, 0);  //red
        digitalWrite(SensoreAS3, 0);
        Mode[0] = 1;
        break;
      case 2:
        digitalWrite(SensoreAS2, 0);  //blue
        digitalWrite(SensoreAS3, 1);
        Mode[0] = 2;
        break;
      case 3:
        digitalWrite(SensoreAS2, 1);  //green
        digitalWrite(SensoreAS3, 1);
        Mode[0] = 3;
        break;
      default:
        digitalWrite(SensoreAS2, 1);  //nofilter
        digitalWrite(SensoreAS3, 0);
        Mode[0] = 4;
    }
  } else {
    switch (ColorChannel) {
      case 1:
        digitalWrite(SensoreBS2, 0);
        digitalWrite(SensoreBS3, 0);
        Mode[1] = 1;
        break;
      case 2:
        digitalWrite(SensoreBS2, 0);
        digitalWrite(SensoreBS3, 1);
        Mode[1] = 2;
        break;
      case 3:
        digitalWrite(SensoreBS2, 1);
        digitalWrite(SensoreBS3, 1);
        Mode[1] = 3;
        break;
      default:
        digitalWrite(SensoreBS2, 1);
        digitalWrite(SensoreBS3, 0);
        Mode[1] = 4;
    }
  }
}
void UpadteValues() {
  byte SensoreAS2 = 0;  //must be defined //ColorChannel
  byte SensoreAS3 = 0;
  byte SensoreBS2 = 0;
  byte SensoreBS3 = 0;
  int = redFrequency = pulseIn(9, LOW);
  int = BredFrequency = pulseIn(10, LOW);
  if (Mode[0] == 1) {  //red
    if (redFrequency > 40) GCS[0] = 1;
    else GCS[0] = 0;
  } else if (Mode[0] == 2) {  //Bule
    if (redFrequency > 40) GCS[0] = 2;
    else GCS[0] = 0;
  } else if (Mode[0] == 3) {  //Green
    if (redFrequency > 40) GCS[0] = 3;
    else GCS[0] = 0;
  }


  if (Mode[1] == 1) {//red
    if (redFrequency > 40) GCS[1] = 1;
    else GCS[1] = 0;
  } else if (Mode[0] == 2) {  //Bule
    if (redFrequency > 40) GCS[1] = 2;
    else GCS[1] = 0;
  } else if (Mode[0] == 3) {  //Green
    if (redFrequency > 40) GCS[1] = 3;
    else GCS[1] = 0;
  }
}
