#include "Freenove_WS2812_Lib_for_ESP32.h"

#define LEDS_COUNT  20
#define LEDS_PIN	13
#define CHANNEL		0

enum direction {
  FORWARDS,
  BACKWARDS
};

Freenove_ESP32_WS2812 strip = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN, CHANNEL);

int pong_pos;
byte speed;
direction dir;

void setup() {
  strip.begin();
  pinMode(0, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(0), button_pressed, FALLING);
  pong_pos = 0;
  dir = FORWARDS;
}

void loop() {
  strip.setAllLedsColorData(0xFFFFFF);
  strip.set_pixel(pong_pos, 0, 255, 0);
  strip.setBrightness(128);
  strip.show();

  if (dir == FORWARDS) {
    pong_pos++;
    if (pong_pos >= LEDS_COUNT-1)
      dir = BACKWARDS;
  } else {
    pong_pos--;
    if (pong_pos <= 0)
      dir = FORWARDS;
  }
  
  delay((speed+1) * 20);
}

void button_pressed() {
  speed = (speed+1) % 4;
}