#include <Arduino.h>
#include <TemplClass.h>

Templ::TemplClass _templ;

void setup() {
}

void loop() {
  _templ.blink();
  delay(2000);
}
