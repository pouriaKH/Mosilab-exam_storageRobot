#include <MOTOR.h>
#include <IR.H>
#include <ColorSensoreFilterChange.h>

#define TRC1 A1
#define TRC2 A2
#define TRC3 A3
#define TRC4 A4

#define ENA
#define ENB
#define MOTORA1
#define MOTORA2
#define MOTORB1
#define MOTORB2

#define UltraTriger
#define UltraEcho

//color Sensore A Pins
#define colorSensorAS0
#define colorSensorAS1
#define colorSensorAS2
#define colorSensorAS3


//Color Sensore B pins
#define colorSensorBS0
#define colorSensorBS1
#define colorSensorBS2
#define colorSensorBS3

#define FrontLed
#define Buzzer
#define Button
int UltraSonic() {
  digitalWrite(UltraTriger, LOW);
  delayMicroseconds(2);
  digitalWrite(UltraTriger, HIGH);
  delayMicroseconds(10);
  digitalWrite(UltraTriger, LOW);
  duration = pulseIn(UltraEcho, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}
void setup() {

  Serial.begin(9600);
  pinMode(TRC1, INPUT);
  pinMode(TRC2, INPUT);
  pinMode(TRC3, INPUT);
  pinMode(TRC4, INPUT);


  pinMode(colorSensorAS0, OUTPUT);
  pinMode(colorSensorAS1, OUTPUT);
  pinMode(colorSensorAS2, OUTPUT);
  pinMode(colorSensorAS3, OUTPUT);

  pinMode(colorSensorAS0, OUTPUT);
  pinMode(colorSensorAS1, OUTPUT);
  pinMode(colorSensorAS2, OUTPUT);
  pinMode(colorSensorAS3, OUTPUT);
  void waitTillRespons() {
    while (!Serial.available()) {}
  }



  int AmountOfPaths = 3;  // will declare how many paths are in the ficilty

  int Robotspath[AmountOfPaths];
  Serail.println("Plase input the path that you want to go : (1 = RED , 2 = BLUE , 3 = GREEN)");
  waitTillRespons();
  int response = Serial.purseInt();

  if (response <= 0 || response >= 4) {
    Serail.println("Plase input a valid Amount");
  } else {
    switch (response) {
      case 1:
        Robotspath[0] = 1;
        break;
      case 2:
        Robotspath[0] = 2;
        break;
      case 3:
        Robotspath[0] = 3;
        break;
    }
  }
  for (int i = 0; i > AmountOfPaths - 1; i++) {
    Serail.println("Plase input the next path that you want to go : (1 = RED , 2 = BLUE , 3 = GREEN)");
    waitTillRespons();
    response = Serial.purseInt();

    if (response <= 0 || response >= 4) {
      Serail.println("Plase input a valid Amount");
    } else {
      switch (response) {
        case 1:
          Robotspath[i] = 1;
          break;
        case 2:
          Robotspath[i] = 2;
          break;
        case 3:
          Robotspath[i] = 3;
          break;
      }
    }
  }
  Serial.println(Robotspath);
}
void loop() {

    if (UltraEcho() < 30) {
      MOTOR(0, 0);
      while (UltraEcho() < 30) {
        tone(buzzer, 1000);
        delay(1000);
        noTone(buzzer);
        delay(1000);
      }
    } else {
      if (GIRV[0] == 1 && GIRV[1] == 1 && GIRV[2] == 0 && GIRV[2] == 0) MOTOR(50, 50);
      else if (GIRV[0] == 1 && GIRV[1] == 1 && GIRV[2] == 1 && GIRV[2] == 0) MOTOR(0, 50);
      else if (GIRV[0] == 1 && GIRV[1] == 1 && GIRV[2] == 0 && GIRV[2] == 1) MOTOR(50, 0);
      else if (GIRV[0] == 0 && GIRV[1] == 0 && GIRV[2] == 0 && GIRV[2] == 0) MOTOR(-50, -50);

      if (Robotspath[AmountOfPaths] = 1) {
        ChangeFilter(0, 1);
        ChangeFilter(1, 1);
      } else if (Robotspath[AmountOfPaths] = 2) {
        ChangeFilter(0, 2);
        ChangeFilter(1, 2);
      } else if (Robotspath[AmountOfPaths] = 3) {
        ChangeFilter(0, 3);
        ChangeFilter(1, 3);
      } else if (Robotspath[AmountOfPaths] = 4) {
        ChangeFilter(0, 4);
        ChangeFilter(1, 4);
      }


      switch (GCS[1]) {
        case 1:
          MOTOR(100, 100);  // these number have to be set on the placement and pins of the robot later
          AmountOfPaths--;
          break;
        case 2:
          MOTOR(100, 100);  // these number have to be set on the placement and pins of the robot later
          AmountOfPaths--;
          break;
        case 3:
          MOTOR(100, 100);  // these number have to be set on the placement and pins of the robot later
          AmountOfPaths--;
          break;
        case 4:
          MOTOR(100, 100);  // these number have to be set on the placement and pins of the robot later
          AmountOfPaths--;
          break;
      }
      switch (GCS[2]) {
        case 1:
          MOTOR(100, 100);  // these number have to be set on the placement and pins of the robot later
          AmountOfPaths--;
          break;
        case 2:
          MOTOR(100, 100);  // these number have to be set on the placement and pins of the robot later
          AmountOfPaths--;
          break;
        case 3:
          MOTOR(100, 100);  // these number have to be set on the placement and pins of the robot later
          AmountOfPaths--;
          break;
        case 4:
          MOTOR(100, 100);  // these number have to be set on the placement and pins of the robot later
          AmountOfPaths--;
          break;
      }
    }
  if (AmountOfPaths >= 0) MOTOR(0,0);
}
