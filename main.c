#include <Arduino.h>
#include <MeMCore.h>

MeRGBLed led(0,30);

MeDCMotor motor1(M1); // Right
MeDCMotor motor2(M2); // Left

void setup() {
  // put your setup code here, to run once:
  pinMode(A7, INPUT);
  while(analogRead(A7) !=0);
  
  led.setpin(13);
}

void loop() {
  // put your main code here, to run repeatedly:
  led.setColorAt(0,255,0,0);
  led.setColorAt(1,255,0,0);
  led.show();
  delay(2500);
  moveRobot(-100, 100, 2400);
  moveRobot(-100, 0, 1150);
  moveRobot(-100, 100, 1920); //2400 is around 18 inches (Found through several tests). This means that 133 milliseconds is enough to move the robot 1 inch at a speed of 100. Changed because turn moved the robot. First test: 1862. Second Test: 1995. 2228
  moveRobot(0, 100, 1150); //Test 90 Degrees: 603 at 100. Second test: 602 at 100. Third test: 601 at 100. Fourth test: 599 at 100. Problem was: Wheels were not well adjusted. 90 degrees is around 599 milliseconds. Tried making one wheel turn. Have to switch delay value. 1st test: 599, 2nd: 1000. Turning on the wrong side. Need to make left positive. 3rd test:1198. Wheel went backwards, need to change to move the other wheel. 90 degrees is turning at 100 speed with the right motor, with a delay of 1198.
  moveRobot(-100, 100, 1995);
  delay(3000);
  moveRobot(-100,100,1330);
  moveRobot(0,100,1150);
  moveRobot(-100,100,1197);
  delay(10000);
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
