#include <RmSR04.h>

RmSR04 ultrasonic(2, 3);

void setup() {
  Serial.begin(115200);


}

void loop() {
  ultrasonic.getDistanceInMillimeters();

}

