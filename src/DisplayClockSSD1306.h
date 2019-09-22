#ifndef DISPLAYCLOCK_SSD1306
#define DISPLAYCLOCK_SSD1306

#include <DisplayClock.h>

namespace Display
{
  class ClockSSD1306
  {
  public:
    ClockSSD1306();
    //˜ClockSSD1306(){}

    void begin() = 0;

    void renderTime() = 0;
    void renderStatus() = 0;
    void renderDebug() = 0;

    void clear() = 0;
    void render() = 0;

  private:
    ClockSSD1306(ClockSSD1306 const&)     = delete;
    void operator=(ClockSSD1306 const&) = delete;
  };
};

#endif
