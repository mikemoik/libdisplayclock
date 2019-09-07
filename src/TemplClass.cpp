#include "TemplClass.h"

Templ::TemplClass::TemplClass()
{
  pinMode(PIN_LED, OUTPUT);

  return;
}

void Templ::TemplClass::blink(void)
{
  digitalWrite(PIN_LED, HIGH);
  delay(BLINK_DELAY);
  digitalWrite(PIN_LED, LOW);
  delay(BLINK_DELAY);

  return;
}
