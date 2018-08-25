#include <RunningTimeDelay.h>

#define SERVO_PIN 4

RunningTimeDelay runDelay(2);

void setup() {
  pinMode(SERVO_PIN, OUTPUT);
  digitalWrite(SERVO_PIN, LOW);

  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  
  Serial.begin(115200);

}

void loop() {
  
  int dutyCycleMax = 2350;
  int dutyCycleMin = 710;
  int degree = -90;
//  int degree = 90;
  int dutyCycle = dutyCycleByDegree(degree, dutyCycleMin, dutyCycleMax);
  
  
  int pwmPeriod = 20000;
  long cycleTime = 1200;

//  pwmCycle(710, 20000, SERVO_PIN);
//  pwmCycle(dutyCycle, pwmPeriod, SERVO_PIN);

  radarCycle2(dutyCycleMin, dutyCycleMax, pwmPeriod, SERVO_PIN, cycleTime);
}

void pwmCycle(int dutyCycle, int pwmPeriod, int servoPin) {
  runDelay.microDigitalWrite(servoPin, HIGH, dutyCycle, 1);
  runDelay.microDigitalWrite(servoPin, LOW, pwmPeriod, 2);
}

void radarCycle2(int dutyCycleMin, int dutyCycleMax, int pwmPeriod, int servoPin, long cycleTime) {
  static float stepTime = pwmPeriod * 1.1;
  static float steps = cycleTime * 1000 / 2.0 / stepTime ;
  static int speedPercentual = 80;
  static float angleStep = 180 / steps * (speedPercentual / 100.0);
  static unsigned long startingMicros = micros();
  static int degree = -90;
  static int signalTimes = 1;

  if(micros() - startingMicros < stepTime) {
    int dutyCycle = dutyCycleByDegree(degree, dutyCycleMin, dutyCycleMax);
    pwmCycle(dutyCycle, pwmPeriod, SERVO_PIN);
  }
  else {
    startingMicros = micros();
    if(degree >= -90 && degree <= 90) {
      degree += signalTimes * angleStep;
    }
    else {
      signalTimes *= -1;
      degree += signalTimes * angleStep;
    }
  }
}


int dutyCycleByDegree(int degree, int dutyCycleMin, int dutyCycleMax) {
  int dutyCycle = 1500;
  if(degree < 0) {
    degree = degree < -90 ? -90 : degree;
    dutyCycle = (1500 - dutyCycleMin) / 90.000 * degree + 1500;
  }
  if(degree > 0) {
    degree = degree > 90 ? 90 : degree;
    dutyCycle = (dutyCycleMax - 1500) / 90.0 * degree + 1500;
  }
  
  return dutyCycle;
}

