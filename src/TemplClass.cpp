#include "TemplClass.h"

Templ::TemplClass::TemplClass()
{
  pinMode(LED_BLINK, OUTPUT);

  return;
}

void Templ::TemplClass::blink(void)
{
  digitalWrite(LED_BLINK, HIGH);
  delay(500);
  digitalWrite(LED_BLINK, LOW);

  return;
}
