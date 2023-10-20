#include <FastLED.h>

#define NUM_LEDS 60
#define DATA_PIN 6

CRGB leds[NUM_LEDS];

int potPin = A0;
int toggleButtonPin = 2;
bool lightsaberActivated = false;
int currentHue = 0;

void setup() {
  pinMode(toggleButtonPin, INPUT_PULLUP);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
}

void activateLightsaber(){
  for(int i = 0; i < NUM_LEDS; i++){
    leds[i] = CHSV(currentHue, 255, 255);
    FastLED.show();
    delay(20);
  }
  lightsaberActivated = true;
}

void deactivateLightsaber() {
  // Gradually turn off the lightsaber
  for (int i = NUM_LEDS - 1; i >= 0; i--) {
    leds[i] = CRGB::Black; // Turn off the LEDs
    FastLED.show();
    delay(10); // Adjust the delay to control the deactivation speed
  }
  lightsaberActivated = false;
}

void loop() {
  int buttonState = digitalRead(toggleButtonPin);

  if (buttonState == LOW) {
    if(lightsaberActivated){
      deactivateLightsaber();}
    else{
      activateLightsaber();
    }
    delay(500);
  }

  int potValue = analogRead(potPin);

  int targetHue = map(potValue, 0, 1023, 0, 255);

  while(currentHue != targetHue){
    if(currentHue < targetHue){
      currentHue++;
    }
    else{
      currentHue--;
    }
    if(lightsaberActivated){
      fill_solid(leds, NUM_LEDS, CHSV(currentHue, 255, 255));
      FastLED.show();
      delay(1);
    }
  }
}
