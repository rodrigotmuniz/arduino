/*
 * RmSR04
 * 
 * Author: Rodrigo Muniz
 * Date: May 2018
 * 
 * Control the component SR04 withou using Arduino Delay.
 * 
 */

#ifndef RmSR04_def
#define RmSR04_def
 
#include "Arduino.h"
#include "RunningTimeDelay.h"

class RmSR04 {
    public:  
        RmSR04(int triggerPin, int echoPin);
        int getDistanceInMillimeters();
    private: 
        int _triggerPin;
        int _echoPin;
        unsigned long _echoPinHighLevelTime;
        unsigned long _startingTime;
};

#endif