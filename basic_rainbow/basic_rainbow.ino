#include "Freenove_WS2812_Lib_for_ESP32.h"

#define LEDS_COUNT  20
#define LEDS_PIN	13
#define CHANNEL		0

Freenove_ESP32_WS2812 strip = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN, CHANNEL);

void setup() {
  strip.begin();
}

void loop() {
  for (int j = 0; j < 255; j += 1) {
    for (int i = 0; i < LEDS_COUNT; i++) {
      strip.setLedColorData(i, strip.Wheel((i * 256 / LEDS_COUNT + j) & 255));
    }
    strip.show();
    delay(5);
  }  
}
