#include <FastLED.h>

// Constants
#define LED_PIN 12
#define NUM_LEDS 60
#define BRIGHTNESS 40
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define BUTTON_PIN 3 // Pin for the button

CRGB leds[NUM_LEDS];
int currentColorMap = 0; // Index of the current color map
bool lastButtonState = LOW;
int sweepPosition = 0; // Current position of the sweeping animation

// Updated color maps
const CRGB colorMaps[][3] = {
  {CRGB::Red, CRGB::Orange, CRGB::Yellow},    // Default fire colors
  {CRGB::Blue, CRGB::Aqua, CRGB::White},     // Cool flame colors
  {CRGB::Purple, CRGB::Pink, CRGB::White},   // Fantasy flame colors
  {CRGB::Green, CRGB::Lime, CRGB::Yellow},   // Nature-inspired colors
  {CRGB::Cyan, CRGB::Blue, CRGB::Purple},    // Ocean-inspired colors
  {CRGB::Gold, CRGB::Orange, CRGB::Red},     // Sunset colors
  {CRGB::White, CRGB::Gray, CRGB::Black},    // Monochrome gradient
  {CRGB::Teal, CRGB::Aqua, CRGB::Green}      // Tropical colors
};

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Configure button pin
}

void loop() {
  handleButtonPress();
  flameAnimation(); // Replace with the flame animation
  FastLED.show();
  delay(50); // Animation speed
}

void handleButtonPress() {
  bool buttonState = digitalRead(BUTTON_PIN);
  if (buttonState == LOW && lastButtonState == HIGH) {
    // Button pressed, switch to the next color map
    currentColorMap = (currentColorMap + 1) % (sizeof(colorMaps) / sizeof(colorMaps[0]));
  }
  lastButtonState = buttonState;
}

// Flame-like animation using noise
void flameAnimation() {
  static uint16_t noise[NUM_LEDS]; // Array to store noise values
  static uint16_t time = 0;        // Time variable for noise evolution

  // Generate noise values
  for (int i = 0; i < NUM_LEDS; i++) {
    noise[i] = inoise8(i * 20, time); // Perlin noise
  }

  // Map noise values to colors in the current color map
  for (int i = 0; i < NUM_LEDS; i++) {
    uint8_t index = map(noise[i], 0, 255, 0, 2); // Map noise to color map indices
    leds[i] = blend(
      colorMaps[currentColorMap][index],
      colorMaps[currentColorMap][(index + 1) % 3],
      noise[i] % 128
    );
  }

  // Increment time for evolving noise
  time += 10;
}
