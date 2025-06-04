#include <FastLED.h>

#define LED_PIN 2
#define BUTTON_PIN 3
#define NUM_LEDS 60

CRGB leds[NUM_LEDS];

int currentHour = 0;
int currentMinute = 0;
int currentSecond = 0;
unsigned long lastUpdate = 0;
bool buttonPressed = false;
unsigned long buttonPressStart = 0;
bool buttonHeld = false;

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), incrementHour, FALLING);
}

void loop() {
  unsigned long currentMillis = millis();

  // Check button state
  handleButton();

  // Update time every second
  if (currentMillis - lastUpdate >= 1000) {
    lastUpdate = currentMillis;
    incrementTime();
    updateLEDs();
  }
}

void handleButton() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    if (!buttonHeld) {
      if (buttonPressStart == 0) {
        buttonPressStart = millis(); // Start timing the button press
      } else if (millis() - buttonPressStart > 1500) {
        // Button held for more than 1.5 seconds
        buttonHeld = true;
      }
    } else {
      // Rapidly increment minutes while button is held
      if (millis() - buttonPressStart >= 333) { // ~3 minutes per second
        buttonPressStart = millis();
        incrementMinute();
      }
    }
  } else {
    if (buttonPressStart > 0 && !buttonHeld) {
      // Short press detected
      incrementMinute();
    }
    // Reset button state
    buttonPressStart = 0;
    buttonHeld = false;
  }
}

void incrementMinute() {
  currentMinute++;
  if (currentMinute >= 60) {
    currentMinute = 0;
    currentHour++;
    if (currentHour > 12) {
      currentHour = 1; // Wrap around for 12-hour clock
    }
  }
}

void incrementTime() {
  currentSecond++;
  if (currentSecond >= 60) {
    currentSecond = 0;
    incrementMinute();
  }
}

void incrementHour() {
  currentHour = (currentHour + 1) % 24; // Increment hour and wrap around at 24
}

void updateLEDs() {
  // Clear all LEDs
  FastLED.clear();

  // Map seconds to green
  leds[currentSecond] = CRGB::Green;

  // Map minutes to blue
  leds[currentMinute] = CRGB::Blue;

  // Map hours to red (every 5 LEDs for 12-hour clock)
  int hourLED = (currentHour % 12) * 5; // Map 1-12 to LEDs 0, 5, 10, ..., 55
  leds[hourLED] = CRGB::Red;

  // Show the updated LEDs
  FastLED.show();
}
