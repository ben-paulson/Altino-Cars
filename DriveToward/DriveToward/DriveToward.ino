/*
  Car will drive toward objects detected by IR sensors
*/

#include <Altino.h>

int speed = 700;

void setup() {
  Serial.begin(115200);
}

void loop() {
  SensorData s = Sensor(1);
  int irBack = s.IRSensor[5];
  int irFrontR = s.IRSensor[2];
  int irFrontL = s.IRSensor[0];
  int irFrontM = s.IRSensor[1];
  int irSideL = s.IRSensor[4];
  
  if (irFrontR > 700) {
    Steering2(127, 0);
    Go(speed, speed);
  } else if (irFrontL > 700) {
    Steering2(-127, 0);
    Go(speed, speed);
  } else if (irFrontM > 700) {
    Steering2(0, 0);
    Go(speed, speed);
  } else if (irBack > 700) {
    Steering2(0, 0);
    Go(-speed, -speed);
  } else {
    Go(0, 0);
  }
}
