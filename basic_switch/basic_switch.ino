#include "Freenove_WS2812_Lib_for_ESP32.h"

#define LEDS_COUNT  20
#define LEDS_PIN	13
#define CHANNEL		0

Freenove_ESP32_WS2812 strip = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN, CHANNEL);

int ind = 0;
int colors[] = {0,32,64,128,192,255};
int color_len = sizeof(colors) / sizeof(colors[0]);

void setup() {
  strip.begin();
  pinMode(0, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(0), button_pressed, FALLING);
}

void loop() {
  for (int j = 0; j < 255; j += 1) {
    if (ind < color_len) {
      strip.setAllLedsColorData(strip.Wheel(colors[ind]));
    } else {
      for (int i = 0; i < LEDS_COUNT; i++) {
        strip.setLedColorData(i, strip.Wheel((i * 256 / LEDS_COUNT + j) & 255));
      }
    }
    strip.show();
    delay(5);
  }  
}

void button_pressed() {
  ind++;
  if (ind > color_len)
    ind = 0;
}