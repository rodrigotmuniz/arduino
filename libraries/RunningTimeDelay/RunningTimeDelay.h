/*
 * RunningTimeDelay
 * 
 * Author: Rodrigo Muniz
 * Date: May 2018
 * 
 * Library to use micros() and millis() method to delay your software without pausing it;
 * 
 */

#ifndef RunningTimeDelay_def
#define RunningTimeDelay_def

#include "Arduino.h"

class RunningTimeDelay {
  public:
    RunningTimeDelay(int delayQuantity);
    boolean micro(unsigned int microseconds, unsigned int delaySequence);
    boolean milli(unsigned int milliseconds, unsigned int delaySequence);
	  void microDigitalWrite(unsigned int pin, boolean state , unsigned int milliseconds, unsigned int delaySequence);
	  void milliDigitalWrite(unsigned int pin, boolean state , unsigned int milliseconds, unsigned int delaySequence);
    void jumpToTheNext();
	
  private: 
    int _delayQuantity;
    int _delayActual;
    boolean _firstTime;
    unsigned long _startingTime;
};

#endif
 
