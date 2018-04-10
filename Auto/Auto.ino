#include <Altino.h>

int speed = 700;
int detectionDistance = 300;
int delayAmount = 1250;

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
  int light = s.CDSSensor;
  
  if (light > 200) {
    
    if (irFrontR > detectionDistance) {
      
      Steering2(127, 0);
      Go(-speed, -speed);
      
      delay(delayAmount);
      
    } else if (irFrontL > detectionDistance) {
      
      Steering2(-127, 0);
      Go(-speed, -speed);
      
      delay(delayAmount);
      
    } else if (irFrontM > detectionDistance) {
      
      int choice = random(2);
      
      if (choice == 0) {
        
        Steering2(127, 0);
        Go(-speed, -speed);
        delay(delayAmount);
      } else {
        
        Steering2(-127, 0);
        Go(-speed, -speed);
        delay(delayAmount);
      }
      
    } else if (irBack > detectionDistance) {
      
      Steering2(0, 0);
      Go(speed, speed);
      
    } else {
      Steering2(0, 0);
      Go(speed, speed);
    }
  } else {
    Go(0, 0);
  }
}
