#include <RunningTimeDelay.h>

#define ECHO_PIN 3
#define TRIG_PIN 2

boolean flag;
boolean flag2;
boolean flag3;
long tempo;
int bla;

RunningTimeDelay runDelay(4);
unsigned long duration;

void setup() {
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);

  digitalWrite(TRIG_PIN, LOW);
  Serial.begin(115200);

  delay(100);

  flag = true;
  tempo = 0;

  flag2 = true;
  flag3 = true;
}

void loop() {

  runDelay.microDigitalWrite(TRIG_PIN, LOW, 2, 1);
  runDelay.microDigitalWrite(TRIG_PIN, HIGH, 10, 2);

  digitalWrite(TRIG_PIN, LOW);
  
  if(runDelay.milli(40, 3)) {
    flag2 = true;
//    Serial.println(digitalRead(ECHO_PIN));
    if(flag && digitalRead(ECHO_PIN) == HIGH) {
      flag = false;
      tempo = micros();
    }
    if(!flag && digitalRead(ECHO_PIN) == LOW) {
//      Serial.println("===============================");
      flag = true;
      tempo = micros() - tempo;
    }
  }
  
  if(runDelay.milli(100, 4)) {
    if(flag2) {
      flag2 = false;
//      Serial.println("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
      Serial.println(tempo * .017);
//      Serial.println("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
//    if(tempo * .017 < 500) {
//     Serial.print("Micros: ");
//     Serial.print(micros());
//     Serial.print(" | ");
//     Serial.print("cm: ");
//     Serial.println(tempo * .017);
//    }
      
//      Serial.print(" | ");
//      Serial.print(tempo * 17);
//      Serial.print(" | ");
//      Serial.print(tempo * 17 / 1000);
//      Serial.print(" | ");
//      Serial.println(tempo);
//      Serial.println("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
    }
    
    
  }
//  digitalWrite(TRIG_PIN, LOW);
//  delayMicroseconds(2);
//  digitalWrite(TRIG_PIN, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(TRIG_PIN, LOW);
//  duration = pulseIn(ECHO_PIN, HIGH);
//  Serial.println(duration);

//  delay(400);
  
  
  

}
