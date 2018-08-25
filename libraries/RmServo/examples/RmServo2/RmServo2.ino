/*
 * RunningTimeDelay
 * 
 * Author: Rodrigo Muniz
 * Date: May 2018
 * 
 * Control the servo position and sonar cycle
 * 
 */

#include <RmServo.h>     

#define SERVO_PIN 5
int DUTY_CYCLE_MIN = 710;   // in microseconds
int DUTY_CYCLE_MAX = 2350;  // in microseconds
int PWM_PERIOD = 20000;     // in microseconds
int CYCLE_TIME = 1200;      // in milliseconds
int SPEED_PERCENTUAL = 100;  // 0 -> 100. Better use for 60 -> 100

RmServo servo(SERVO_PIN, DUTY_CYCLE_MIN, DUTY_CYCLE_MAX, PWM_PERIOD, CYCLE_TIME, SPEED_PERCENTUAL);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  servo.sonar();

}
