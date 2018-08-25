#include <RunningTimeDelay.h>

#define WAVE1_PIN 13
#define WAVE2_PIN 12
#define WILDCARD_PIN 11

RunningTimeDelay wave1Delay(2);
RunningTimeDelay wave2Delay(2);

boolean primeiraVez = true;
int wave1Counter = 0;
int wave2Counter = 0;

void setup()
{
  Serial.begin(115200);
  pinMode(WAVE1_PIN, OUTPUT);
  pinMode(WAVE2_PIN, OUTPUT);
  pinMode(WILDCARD_PIN, OUTPUT);

  attachInterrupt(0, testeAttachInterrupt, CHANGE);

  //Clean the timer1
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1B |= (1 << WGM12);

  //Pre Scale to 1024
  TCCR1B |= (1 << CS10);
  TCCR1B |= (1 << CS12);

  //Enable Output Compare Register
  //  TIMSK1 |= (1 << OCIE1A);

  //Set the interrupt cycle
  OCR1A = 15624 + 24; //adjust by myself
}

ISR(TIMER1_COMPA_vect) {
  //  Serial.println(millis());
  OCR1A = 15624;
}

void loop() {
  if (primeiraVez) {
    primeiraVez = false;
  }
  wave1();
    wave2();
}

void setWildcardPin(boolean state) {
  digitalWrite(WILDCARD_PIN, state);
}

void wave1() {
  if (wave1Delay.milli(500, 1)) {
    boolean state = HIGH;
    digitalWrite(WAVE1_PIN, state);
    setWildcardPin(state);
  }

  if (wave1Delay.milli(500, 2)) {
    boolean state = LOW;
    digitalWrite(WAVE1_PIN, state);
    setWildcardPin(state);
  }

  //  wave1Delay.milliDigitalWrite(WAVE1_PIN, HIGH, 500, 1);
  //  wave1Delay.milliDigitalWrite(WAVE1_PIN, LOW, 500, 2);
}

void wave2() {
  if (wave2Delay.milli(200, 1)) {
    boolean state = HIGH;
    digitalWrite(WAVE2_PIN, state);
    setWildcardPin(state);
  }

  if (wave2Delay.milli(200, 2)) {
    boolean state = LOW;
    digitalWrite(WAVE2_PIN, state);
    setWildcardPin(state);
  }
  //  wave2Delay.milliDigitalWrite(WAVE2_PIN, HIGH, 200, 1);
  //  wave2Delay.milliDigitalWrite(WAVE2_PIN, LOW, 200, 2);
}


void testeAttachInterrupt() {
  //  wave1Print();
  wave2Print();
}

void wave1Print() {
  if (digitalRead(WAVE1_PIN)) {
    wave1Counter = millis();
  }
  else {
    Serial.print("Wave 01: ");
    Serial.println(millis() - wave1Counter);
    wave1Counter = 0;
  }
}

void wave2Print() {
  if (digitalRead(WAVE2_PIN)) {
    wave2Counter = millis();
  }
  else {
    Serial.print("Wave 02: ");
    Serial.println(millis() - wave2Counter);
    wave2Counter = 0;
  }
}

