#define LEDS_PIN_OUT	13
#define LEDS_PIN_IN	12

void setup() {
  pinMode(LEDS_PIN_OUT, OUTPUT);
  pinMode(LEDS_PIN_IN, INPUT);
  attachInterrupt(digitalPinToInterrupt(LEDS_PIN_IN), toggle, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
}

void toggle() {
  if (digitalRead(LEDS_PIN_IN) == HIGH)
    digitalWrite(LEDS_PIN_OUT, 1);
  else
    digitalWrite(LEDS_PIN_OUT, 1);
}
