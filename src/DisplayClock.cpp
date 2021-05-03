#include "DisplayClock.h"

Display::Clock::Clock()
{
  _h = 0xFFU;
  _m = 0xFFU;
  _s = 0xFFU;

  _status = "";
  _debug = "";

  return;
}

void Display::Clock::update()
{
  clear();
  renderDebug();
  renderStatus();
  renderTime();
  render();

  return;
}

void Display::Clock::splashscreen()
{
  clear();
  renderSplashscreen();
  render();

  return;
}

void Display::Clock::setTime(uint8_t h, uint8_t m)
{
  _h = h;
  _m = m;
  _s = 0xFFU;

  return;
}
void Display::Clock::setTime(uint8_t h, uint8_t m, uint8_t s)
{
  _h = h;
  _m = m;
  _s = s;

  return;
}

void Display::Clock::setStatus(String status)
{
  _status = status;

  return;
}

void Display::Clock::setDebug(String debug)
{
  _debug = debug;

  return;
}

uint8_t Display::Clock::getHours(void)
{
  return _h;
}
uint8_t Display::Clock::getMinutes(void)
{
  return _m;
}
uint8_t Display::Clock::getSeconds(void)
{
  return _s;
}
