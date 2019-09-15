#ifndef DISPLAYCLOCK
#define DISPLAYCLOCK

#include <ArduinoMisw.h>

namespace Display
{

  class Clock
  {
  public:
    Clock();
    //˜Clock(){}

    void begin() = 0;

    void setTime(uint8_t h, uint8_t m, uint8_t s);
    void setTime(uint8_t h, uint8_t m);
    void setStatus(String status);
    void setDebug(String debug);

    uint8_t getHours(void);
    uint8_t getMinutes(void);
    uint8_t getSeconds(void);

    void renderTime() = 0;
    void renderStatus() = 0;
    void renderDebug() = 0;

    void clear() = 0;
    void display() = 0;

    void refresh();

  private:
    Clock(Clock const&)     = delete;
    void operator=(Clock const&) = delete;

    uint8_t _h,_m,_s;

    String _status;
    String _debug;
  };

};

#endif
