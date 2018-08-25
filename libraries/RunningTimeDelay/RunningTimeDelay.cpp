/*
 * RunningTimeDelay
 * 
 * Author: Rodrigo Muniz
 * Date: May 2018
 * 
 * Library to use micros() and millis() method to delay your software without pausing it;
 * 
 */
 
 #include "Arduino.h" 
 #include "RunningTimeDelay.h"

RunningTimeDelay::RunningTimeDelay(int delayQuantity) {
  _delayQuantity = delayQuantity;
  _firstTime  = true;
  _delayActual = 1;
}

void RunningTimeDelay::jumpToTheNext() {
  _firstTime = true;
  _delayQuantity == _delayActual ? _delayActual = 1 : _delayActual++; 
}

boolean RunningTimeDelay::micro(unsigned int microseconds, unsigned int delaySequence) {
  
  if(_delayActual == delaySequence) {
    if(_firstTime) {
      _firstTime = false;
      _startingTime = micros();
    }
    if(micros() - _startingTime > microseconds) {
      jumpToTheNext();
      return false;
    }
    return true;
  }
  return false;
}
 
boolean RunningTimeDelay::milli(unsigned int milliseconds, unsigned int delaySequence) {
  if(_delayActual == delaySequence) {
    if(_firstTime) {
      _firstTime = false;
      _startingTime = millis();
    }
    if(millis() - _startingTime > milliseconds) {
      jumpToTheNext();
      return false;
    }
    return true;
  }
  return false;
}

void RunningTimeDelay::microDigitalWrite(
	unsigned int pin, 
	boolean state, 
	unsigned int microseconds, 
	unsigned int delaySequence) {
		
	if(micro(microseconds, delaySequence)) {
    // Serial.println("%%%%%%%%%%%%%%%%%%%%");
		pinMode(pin, OUTPUT);
		digitalWrite(pin, state);
	}
}

void RunningTimeDelay::milliDigitalWrite(
	unsigned int pin, 
	boolean state, 
	unsigned int milliseconds, 
	unsigned int delaySequence) {
		
	if(milli(milliseconds, delaySequence)) {
		pinMode(pin, OUTPUT);
		digitalWrite(pin, state);
	}
}


