/*
 * RmSR04
 * 
 * Author: Rodrigo Muniz
 * Date: May 2018 
 * 
 * Control the component SR04 withou using Arduino Delay.
 * 
 */

#include "Arduino.h"
#include "RmSR04.h"
#include "RunningTimeDelay.h"

RunningTimeDelay runDelay(4);
int erro = 0;
        
RmSR04::RmSR04(int triggerPin, int echoPin) {
	_triggerPin = triggerPin;
	_echoPin = echoPin;
	_echoPinHighLevelTime = 0;
	_startingTime = 0;
		
	pinMode(_triggerPin, OUTPUT);
	pinMode(_echoPin, INPUT);

	digitalWrite(_triggerPin, LOW);
}

int RmSR04::getDistanceInMillimeters() {
  	runDelay.microDigitalWrite(_triggerPin, HIGH, 120, 1);
	  runDelay.microDigitalWrite(_triggerPin, LOW, 120, 2);

	Serial.print(digitalRead(_triggerPin));
	Serial.print(" - ");
	Serial.println(digitalRead(_echoPin));

	if(runDelay.milli(19, 3)) {
		// Serial.println(digitalRead(_echoPin));
		if(_startingTime == 0 && digitalRead(_echoPin) == HIGH) {
			_startingTime = micros();
		}	
		if(_startingTime != 0 && digitalRead(_echoPin) == LOW) {
			_echoPinHighLevelTime = micros() - _startingTime;
			
			if(_startingTime != 0 ){
				runDelay.jumpToTheNext();
				_startingTime = 0;
        // Serial.println((int)_echoPinHighLevelTime * .017);
				return _echoPinHighLevelTime * .17;
			}
		}
	}

	if(runDelay.milli(40, 4)) {
		digitalWrite(_triggerPin, LOW);
    _startingTime = 0;
	}
  return 0;
}



