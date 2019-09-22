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
  char str_time[6];
  char str_sec[3];
  int textsize = 4;

  sprintf(str_time, "%02d:%02d", _h, _m);
  if (0xFF == _h || 0xFF == _m)
  {
    sprintf(str_time, "     ");
  }
  sprintf(str_sec, "%02d", _s);
  if (0xFF == _s)
  {
    sprintf(str_sec, "  ");
  }

  // hh:mm
  _display.setTextSize(textsize);
  _display.setTextColor(WHITE);
  _display.setCursor(SCREEN_WIDTH/2 - 5*textsize*CHAR_PIXEL/2, SCREEN_HEIGHT/2 - textsize*CHAR_PIXEL/2);
  _display.setCursor(5, 16);
  _display.println(str_time);

  // s
  _display.setTextSize(1);
  _display.setTextColor(WHITE);
  _display.setCursor(SCREEN_WIDTH - 4*CHAR_PIXEL/2, SCREEN_HEIGHT-CHAR_PIXEL*2);
  _display.println(str_sec);

  return;
  return;
}

void Display::DisplayClockSSD1306::renderStatus()
{
  if (0 == _status.length())
  {
    _status = "                     ";
  }
  _display.setTextSize(1);
  _display.setTextColor(WHITE);
  _display.setCursor(SCREEN_WIDTH/2 - _status.length()*CHAR_PIXEL/2, SCREEN_HEIGHT-CHAR_PIXEL*2);
  _display.println(_status);

  return;
}

void Display::DisplayClockSSD1306::renderDebug()
{
  if (0 == _debug.length())
  {
    _debug = "                     ";
  }
  _display.setTextSize(1);
  _display.setTextColor(WHITE);
  _display.setCursor(SCREEN_WIDTH/2 - _debug.length()*CHAR_PIXEL/2, CHAR_PIXEL/2);
  _display.println(_debug);

  return;
}

void Display::DisplayClockSSD1306::clear()
{
  _display.clearDisplay();

  return;
}

void Display::DisplayClockSSD1306::render()
{
  _display.display();

  return;
}
