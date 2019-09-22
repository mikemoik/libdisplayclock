#pragma once

#include <ArduinoMisw.h>

namespace Display
{
  class Clock
  {
  public:
    Clock();
    //˜Clock(){}

    virtual void begin() = 0;

    void update();

    void setTime(uint8_t h, uint8_t m, uint8_t s);
    void setTime(uint8_t h, uint8_t m);
    void setStatus(String status);
    void setDebug(String debug);

    uint8_t getHours(void);
    uint8_t getMinutes(void);
    uint8_t getSeconds(void);

    virtual void renderTime() = 0;
    virtual void renderStatus() = 0;
    virtual void renderDebug() = 0;

    virtual void clear() = 0;
    virtual void render() = 0;

  private:
    Clock(Clock const&)     = delete;
    void operator=(Clock const&) = delete;

  protected:
    uint8_t _h,_m,_s;

    String _status;
    String _debug;
  };

};
