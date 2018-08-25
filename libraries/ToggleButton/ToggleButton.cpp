#include "Arduino.h"
#include "ToggleButton.h"

ToggleButton::ToggleButton(int buttonPin, int controlledPin) {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(controlledPin, OUTPUT);
  _buttonPin = buttonPin;
  _controlledPin = controlledPin;
  
  _buttonState = digitalRead(_buttonPin);
  _millisTime = millis();
  _inBounceTime = false;
}

void ToggleButton::bounceTime(int milliseconds) {
  if(!_inBounceTime && (_buttonState != digitalRead(_buttonPin)) ) {
	_millisTime = millis();
    _inBounceTime = true;
  }
  
  if(_inBounceTime && (millis() - _millisTime > milliseconds)) {
	 
    digitalWrite(_controlledPin, !digitalRead(_controlledPin));
    _inBounceTime = false;
  }
}

