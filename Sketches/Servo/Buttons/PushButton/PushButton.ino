#define BUTTON_PIN_RED 13
#define LED_PIN_RED 3

#define BUTTON_PIN_WHITE 12
#define LED_PIN_WHITE 2


void setup() {
  pinMode(BUTTON_PIN_RED, INPUT_PULLUP);
  pinMode(LED_PIN_RED, OUTPUT);
  pinMode(BUTTON_PIN_WHITE, INPUT_PULLUP);
  pinMode(LED_PIN_WHITE, OUTPUT);
  Serial.begin(115200);

}

void loop() {
//  toggleButtonRed(200, BUTTON_PIN_RED, LED_PIN_RED);
//  toggleButtonWhite(200, BUTTON_PIN_WHITE, LED_PIN_WHITE);
}


void toggleButtonRed(int bounceTime, int buttonPin, int ledPin) {
  const int BOUNCE_TIME = bounceTime;
  
  static boolean buttonState = digitalRead(buttonPin);
  static unsigned long millisTime = millis();
  static boolean inBounceTime = false;

  if(!inBounceTime && (buttonState != digitalRead(buttonPin)) ) {
    millisTime = millis();
    inBounceTime = true;
  }
  if(inBounceTime && (millis() - millisTime > BOUNCE_TIME)) {
    digitalWrite(ledPin, !digitalRead(ledPin));
    inBounceTime = false;
  }
}

void toggleButtonWhite(int bounceTime, int buttonPin, int ledPin) {
  const int BOUNCE_TIME = bounceTime;
  
  static boolean buttonState = digitalRead(buttonPin);
  static unsigned long millisTime = millis();
  static boolean inBounceTime = false;

  if(!inBounceTime && (buttonState != digitalRead(buttonPin)) ) {
    millisTime = millis();
    inBounceTime = true;
  }
  if(inBounceTime && (millis() - millisTime > BOUNCE_TIME)) {
    digitalWrite(ledPin, !digitalRead(ledPin));
    inBounceTime = false;
  }
}

