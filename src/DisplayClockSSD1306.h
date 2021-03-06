#ifndef DISPLAYCLOCK_SSD1306
#define DISPLAYCLOCK_SSD1306

#include <DisplayClock.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define CHAR_PIXEL 6 // x and y pixels of a char

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     LED_BUILTIN // Reset pin # (or -1 if sharing Arduino reset pin)

namespace Display
{
  class ClockSSD1306
  {
  public:
    ClockSSD1306();
    //˜ClockSSD1306(){}

    void begin();

    void renderTime();
    void renderStatus();
    void renderDebug();

    void clear();
    void render();

  private:
    ClockSSD1306(ClockSSD1306 const&) = delete;
    void operator=(ClockSSD1306 const&) = delete;

    Adafruit_SSD1306 _display;
  };
};

#endif
