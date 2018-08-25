#include<ToggleButton.h>

#define BUTTON_PIN 9
#define CONTROLLED_PIN 8

int BOUNCE_TIME_IN_MILLISECONDS = 200;

ToggleButton toggleButton(BUTTON_PIN, CONTROLLED_PIN);
void setup() {
}

void loop() {
  toggleButton.bounceTime(BOUNCE_TIME_IN_MILLISECONDS);
}
