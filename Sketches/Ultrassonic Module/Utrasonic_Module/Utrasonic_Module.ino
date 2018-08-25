#include <RunningTimeDelay.h>

#define ECHO_PIN 2
#define TRIG_PIN 5

int ajuste = 50;

unsigned long startingTime = 0;
boolean interruptFlag = false;
boolean onceFlag = true;
RunningTimeDelay rmDelay(3);

void setup() {
  Serial.begin(115200);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);

  attachInterrupt(0, interruption, CHANGE);
  

}

void loop() {
  // delay(ajuste);
  // Serial.print(digitalRead(ECHO_PIN));
  // Serial.print(" - ");
  // Serial.println(digitalRead(TRIG_PIN));
    sr04();
    // teste();
    if(interruptFlag) {
      Serial.println(millis());
      startingTime = millis();

    }
    if(startingTime != 0 && !interruptFlag) {
      startingTime = 0;
      Serial.println(startingTime);
      
    }
    
    
    
  
}


void teste() {
  rmDelay.milliDigitalWrite(ECHO_PIN, HIGH, 50 * ajuste, 1);
  rmDelay.milliDigitalWrite(ECHO_PIN, LOW, 50 * ajuste, 2);
}

void interruption() {
  Serial.println(1111);
  interruptFlag = !interruptFlag;
}


void sr04() {
  rmDelay.microDigitalWrite(TRIG_PIN, HIGH, 10, 1);
  rmDelay.microDigitalWrite(TRIG_PIN, LOW, 10, 2);
  if(rmDelay.milli(500, 3)) {
    // Serial.print(flag);
    // Serial.print(" - ");
    // Serial.println(flag2);
    // if(flag && flag2) {
    //    Serial.println(millis() - startingTime);
    //   startingTime = millis();
    //   flag2 = false;
    // }
    // if(!flag2) {
    //   flag2 = true;
    //   Serial.println(millis() - startingTime);
    //   startingTime = 0;
    // }
  }

}


// void echoPinActiveRising() {
//   flag = true;
//   attachInterrupt(0, echoPinActiveFalling, CHANGE);
// }

// void echoPinActiveFalling() {
//   // flag = false;
//   attachInterrupt(0, echoPinActiveRising, RISING);
// }


int rmRound(float n) {
  int parteInteira = (int) n;
  int primeiroNumeroDecimal = (n - parteInteira) * 10;
  return primeiroNumeroDecimal >= 5 ? ++parteInteira : parteInteira;
}

int medium(int lista[]) {
  int soma = 0;
  for (int i = 0; i < 3; i++) {
    soma += lista[i];
  }
  return soma / 3;
}




