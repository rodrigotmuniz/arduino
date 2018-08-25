/*
 * RunningTimeDelay
 * 
 * Author: Rodrigo Muniz
 * Date: May 2018
 * 
 * Control the servo position and sonar cycle
 * 
 */

#include "Arduino.h"
#include "RunningTimeDelay.h" 
#include "RmServo.h"

RunningTimeDelay pwmCycleDelay(2);
RunningTimeDelay positionDelay(1);

RmServo::RmServo(int servoPin, int dutyCycleMin, int dutyCycleMax, int pwmPeriod, int cycleTime, int speedPercentual) {
	
  
  _servoPin = servoPin;
  _dutyCycleMin = dutyCycleMin;
  _dutyCycleMax = dutyCycleMax; 
  _pwmPeriod = pwmPeriod;
  _cycleTime = cycleTime;

  _stepTime = _pwmPeriod * 1.1;
  _steps = _cycleTime * 1000 / 2.0 / _stepTime ;
  _speedPercentual = speedPercentual;
  _angleStep = 180 / _steps * (_speedPercentual / 100.0);
  _startingMicros = 0;
  _degree = -90;
  _signalTimes = 1;

  pinMode(_servoPin, OUTPUT);
  digitalWrite(_servoPin, LOW);
}

void RmServo::sonar() {
  if(micros() - _startingMicros < _stepTime) {
    int dutyCycle = dutyCycleByDegree(_degree);
    pwmCycle(dutyCycle, _pwmPeriod, _servoPin);
  }
  else {
    _startingMicros = micros();
        if(_degree >= -90 && _degree <= 90) {
      _degree += _signalTimes * _angleStep;
    }
    else {
      _signalTimes *= -1;
      _degree += _signalTimes * _angleStep;
    }
  }
}

void RmServo::pwmCycle(int dutyCycle, int pwmPeriod, int servoPin) {
  pwmCycleDelay.microDigitalWrite(servoPin, HIGH, dutyCycle, 1);
  pwmCycleDelay.microDigitalWrite(servoPin, LOW, pwmPeriod, 2);
}

int RmServo::dutyCycleByDegree(int degree) {
// int RmServo::dutyCycleByDegree(int degree, int dutyCycleMin, int dutyCycleMax) {
  // int dutyCycle = 1500;
  // if(degree < 0) {
  //   degree = degree < -90 ? -90 : degree;
  //   dutyCycle = (1500 - dutyCycleMin) / 90.000 * degree + 1500;
  // }
  // if(degree > 0) {
  //   degree = degree > 90 ? 90 : degree;
  //   dutyCycle = (dutyCycleMax - 1500) / 90.0 * degree + 1500;
  // }
  // return dutyCycle;
  return 1450 + 8.61 * degree + 0.00309 * degree * degree;
  // return 700;
}

void RmServo::goToDegreePosition(int degree, boolean holdPosition) {
  static boolean flag = true;

  // if(flag && positionDelay.milli(_cycleTime / 2, 1)) {
    int dutyCycle = dutyCycleByDegree(degree);
    // Serial.println(dutyCycle);
    pwmCycle(dutyCycle, _pwmPeriod, _servoPin);
    // pwmCycle(700, 20000, 5);
  // }
  // else {
  //   flag = holdPosition;
  // }
  
}
  
 
