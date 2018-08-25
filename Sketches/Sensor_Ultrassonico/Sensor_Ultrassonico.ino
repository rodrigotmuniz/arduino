#include <NewPing.h>

#define TRIGGER_PIN 11
#define ECHO_PIN 12
#define MAX_DISTANCE 250

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(115200);
}

void loop() {
  delay(50);
  Serial.print("Ping: ");
  long dist = sonar.ping_median(10);
  Serial.print(sonar.convert_cm(dist));
  Serial.println(" cm");
  Serial.println(dist);
}
