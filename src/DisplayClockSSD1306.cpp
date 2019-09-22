#include "DisplayClockSSD1306.h"

Display::DisplayClockSSD1306()
:
_display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET)
{
  return;
}

void Display::DisplayClockSSD1306::begin()
{
  _display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  _display.display();

  return;
}

//void Display::DisplayClockSSD1306::update()
//{
//  super::update();
//  return;
//}

void Display::DisplayClockSSD1306::renderTime()
{
  return;
}

void Display::DisplayClockSSD1306::renderStatus()
{
  return;
}

void Display::DisplayClockSSD1306::renderDebug()
{
  return;
}

void Display::DisplayClockSSD1306::clear()
{
  return;
}

void Display::DisplayClockSSD1306::render()
{
  return;
}
