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

    void blink(void);

  private:
    Clock(Clock const&)     = delete;
    void operator=(Clock const&) = delete;
  };

};

#endif
