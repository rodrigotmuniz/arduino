
#define TRIGGER_PIN 11
#define ECHO_PIN 12

void trigPuls();

float pulse;
int dist_cm;
int numeroAmostras;

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  digitalWrite(TRIGGER_PIN, LOW);

  Serial.begin(115200);

  numeroAmostras = 3;
  dist_cm = 0;
}

void loop() {
  for(int i = 0; i < numeroAmostras; i++) {
    trigPulse();
    pulse = pulseIn(ECHO_PIN, HIGH);
    dist_cm += pulse / 58.82;
    delay(60);
  }
  dist_cm /= numeroAmostras;
  Serial.println(dist_cm);

  dist_cm = 0;
//  Serial.print(" I ");
//   Serial.println(pulse);
//  qtdePulsos++;
//  if(qtdePulsos == 10) {
//    Serial.println("=====");
//    Serial.println(dist_cm / qtdePulsos);
//    Serial.println("=====");
//
//    qtdePulsos = 0;
//    dist_cm = 0;
//  }
}


void trigPulse() {
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
}

