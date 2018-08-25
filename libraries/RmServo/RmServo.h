/*
 * RunningTimeDelay
 * 
 * Author: Rodrigo Muniz
 * Date: May 2018
 * 
 * Control the servo position and sonar cycle
 * 
 */

#ifndef RmServo_def
#define RmServo_def

#include "Arduino.h"
#include "RunningTimeDelay.h" 

   class RmServo {
  public: 
    RmServo(int servoPin, int dutyCycleMin, int dutyCycleMax, int pwmPeriod, int cycleTime, int speedPercentual);
    void goToDegreePosition(int degree, boolean holdPosition);
    void sonar();
	  int dutyCycleByDegree(int degree);
    void pwmCycle(int dutyCycle, int pwmPeriod, int servoPin);
	
  private: 
    int _servoPin; 
    int _dutyCycleMin;
    int _dutyCycleMax; 
    int _pwmPeriod;
    long _cycleTime;
    float _stepTime;
    float _steps;
    int _speedPercentual;
    float _angleStep;
    unsigned long _startingMicros;
    int _degree;
    int _signalTimes;
};

#endif
