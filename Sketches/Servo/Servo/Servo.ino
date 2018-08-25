#include <Servo.h>
#include <NewPing.h>

#define PIN_SERVO 8
#define TRIGGER_PIN 11
#define ECHO_PIN 12
#define MAX_DISTANCE 250
boolean a;

Servo servo;
NewPing ultra(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  servo.attach(PIN_SERVO);
  Serial.begin(115200);
  a = true;

//  pinMode(PIN_SERVO, OUTPUT);
//  digitalWrite(PIN_SERVO, LOW);
}



void loop() {
//  delay(50);
//  sonar(100, 0, 180, 2, true);
//  ultraMethod();
servo.write(20);
delay(1000);
servo.write(180);
delay(1000);

//if(a) {
//  a = false;
//  servo.write(20);
//  delay(1000);
//}

}

void ultraMethod() {
//  delay(50);
  Serial.print("Ping: ");
  long dist = ultra.ping_cm();
  Serial.print(dist);
  Serial.println(" cm");
}

void sonar(int delayTime, int minAngle, int maxAngle, int rotationPerCycle, boolean showLog) {
  
  for(int i = minAngle; i < maxAngle; i += rotationPerCycle) {
    servo.write(i);
//    ultraMethod();
    delay(delayTime);
    if(showLog) {
      Serial.print("Sonar Angle: ");
      Serial.println(i);
    }
  }

  for(int i = maxAngle; i > minAngle; i -= rotationPerCycle) {
    servo.write(i);
//    ultraMethod();
    delay(delayTime);
    if(showLog) {
      Serial.print("Sonar Angle: ");
      Serial.println(i);
    }
  }
}
