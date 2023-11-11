#include <Arduino.h>
#include <MeMCore.h>

MeRGBLed led(0,30);

MeDCMotor motor1(M1); // Right
MeDCMotor motor2(M2); // Left

void setup() {
  // put your setup code here, to run once:
  pinMode(A7, INPUT);
  while(analogRead(A7) !=0); //only starts when button is pressed.
  
  led.setpin(13);

  led.setColorAt(0,255,0,0);
  led.setColorAt(1,255,0,0);
  led.show();
  delay(2500);
  moveRobot(-100, 100, 2400); //forward
  moveRobot(-100, 0, 1150); //turn right 90 degrees
  moveRobot(-100, 100, 1920); //forward
  moveRobot(0, 100, 1150); //turn left 90 degrees
  moveRobot(-100, 100, 1995); //forward
  delay(3000); //delay
  moveRobot(-100,100,1330); //forward
  moveRobot(0,100,1150); //turn left 90 degrees
  moveRobot(-100,100,1197); //go forward
}

void loop() {
  // put your main code here, to run repeatedly:
}

void moveRobot(int leftMotor, int rightMotor, int delayTime){
  delay(500);
  led.setColorAt(0,0,255,0);
  led.setColorAt(1,0,255,0);
  led.show();
  motor2.run(leftMotor);
  motor1.run(rightMotor);
  delay(delayTime);
  led.setColorAt(0,255,0,0);
  led.setColorAt(1,255,0,0);
  led.show();
  motor1.stop();
  motor2.stop();
} 
