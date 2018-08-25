#include <RmSR04.h>

RmSR04 ultrasonic(2, 4);

long soma = 0;
long qtde = 0;

void setup() {
  Serial.begin(115200);


}

void loop() {
  if(millis() > 10000) {
    Serial.println(soma / qtde);
  }
  else {
    soma += ultrasonic.getDistanceInMillimeters();
    qtde++;
  }

}

