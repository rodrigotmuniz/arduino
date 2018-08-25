/*
 * RunningTimeDelay
 * 
 * Author: Rodrigo Muniz
 * Date: May 2018
 * 
 * Library to use micros() and millis() method to delay your software without pausing it;
 * 
 */

#include <RunningTimeDelay.h>

//RunningTimeDelay (Number of sequencies` quantity)
RunningTimeDelay runDelay(6); 

int qtde = 0;

void setup() {
  Serial.begin(115200);
  pinMode(13, OUTPUT);
}

void loop() {
  
  
  //runDelay.milli(Delay time in miliseconds (int), Sequency position (int))
  if(runDelay.milli(500, 1)) {
    digitalWrite(13, HIGH);
  }

  //runDelay.micro(Delay time in microseconds (int), Sequency position (int))
  if(runDelay.micro(50000, 2)) {
    digitalWrite(13, LOW);
  }

//  runDelay.milli(Delay time in miliseconds (int), Sequency position (int))
  if(runDelay.milli(2000, 3)) {
    //Pause
  }
//
  //runDelay.milliDigitalWrite(Pin (int), HIGH or LOW (boolean), Delay time in miliseconds (int), Sequency position (int))
  runDelay.milliDigitalWrite(13, HIGH, 500, 4);

  //runDelay.microDigitalWrite(Pin, HIGH or LOW (boolean), Delay time in miliseconds (int), Sequency position (int))
  runDelay.microDigitalWrite(13, LOW, 50000, 5);

  //runDelay.milli(Delay time in miliseconds (int), Sequency position (int))
  if(runDelay.milli(1000, 6)) {
    //Pause
  }
}