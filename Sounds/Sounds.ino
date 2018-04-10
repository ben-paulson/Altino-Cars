/*
  Play sound when an object is detected by IR sensors
*/

#include <Altino.h>

int speed = 300;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  SensorData s = Sensor(1);
  int ir_back = s.IRSensor[5];
  int irFrontR = s.IRSensor[2];
  int irFrontL = s.IRSensor[0];
  int irFrontM = s.IRSensor[1];
  int irSideL = s.IRSensor[4];
  
  
  if (irFrontL > 700) {
    Sound(41);
  } else if (irFrontM > 700) {
    Sound(39);
  } else if (irFrontR > 700) {
    Sound(37);
  } else if (irSideL > 700) {
    Sound(44);
  } else {
    Sound(0);
  }
  
  

}
