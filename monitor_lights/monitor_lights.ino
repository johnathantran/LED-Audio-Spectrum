#include <FastLED.h>
#define brightness 100
#define num_leds 60
#define pin 13

CRGB leds[num_leds];

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2811, pin, GRB>(leds, num_leds);
  FastLED.setBrightness(brightness);
}

void loop() {
    
  int midpoint = 60; // the midpoint LED of the strip
  // ex: if you are using 120 LEDs the midpoint would be 60

  for (int i = 0; i < num_leds; i++ ) {
    // the main value you need to change (depending on what
    // color you want your monitor backlight to be
    leds[(midpoint)] = CRGB(117,199,169);
  }
  FastLED.show();

  for (int z = num_leds; z > (midpoint); z--) {
    leds[z] = leds[z - 1]; 
  }
  for (int z = 0; z < (midpoint); z++) {
    leds[z] = leds[z + 1];
  }
}
