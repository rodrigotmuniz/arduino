/*
 *  toggle_button.cpp
 *  
 *  Autor: Rodrigo Muniz
 *  Abril de 2018
 */

 #include "Arduino.h"
 #include "toggle_button.h"

 toggle_button::toggle_button(int buttonPin, int ledPin) {
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);
 }

 void toggle_button:toggle_button(int bounceTime) {
  const int BOUNCE_TIME = bounceTime;
  
  static boolean buttonState = digitalRead(_buttonPin);
  static unsigned long millisTime = millis();
  static boolean inBounceTime = false;

  if(!inBounceTime && (buttonState != digitalRead(_buttonPin)) ) {
    millisTime = millis();
    inBounceTime = true;
  }
  if(inBounceTime && (millis() - millisTime > BOUNCE_TIME)) {
    digitalWrite(_ledPin, !digitalRead(ledPin));
    inBounceTime = false;
  }
  
 }
 
