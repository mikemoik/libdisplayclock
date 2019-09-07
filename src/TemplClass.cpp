#include "TemplClass.h"

Templ::TemplClass::TemplClass()
{
  pinMode(PIN_LED, OUTPUT);

  return;
}

void Templ::TemplClass::blink(void)
{
  digitalWrite(PIN_LED, HIGH);
  delay(100);
  digitalWrite(PIN_LED, LOW);

  return;
}
