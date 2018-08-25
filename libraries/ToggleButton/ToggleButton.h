#ifndef ToggleButton_n
#define ToggleButton_n

#include "Arduino.h"

class ToggleButton {
  public: 
    ToggleButton(int buttonPin, int controlledPin);
    void bounceTime(int milliseconds);
  private: 
    int _buttonPin;
    int _controlledPin;
	boolean _buttonState;
	unsigned long _millisTime;
	boolean _inBounceTime;
};

#endif
