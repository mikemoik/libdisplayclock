#ifndef LIB_TEMPL
#define LIB_TEMPL

#include <ArduinoMisw.h>

#define BLINK_DELAY 100

namespace Templ
{

  class TemplClass
  {
  public:
    TemplClass();
    //˜TemplClass(){}

    void blink(void);

  private:
    TemplClass(TemplClass const&)     = delete;
    void operator=(TemplClass const&) = delete;
  };

};

#endif
