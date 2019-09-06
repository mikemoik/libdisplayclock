#include <Arduino.h>
#include <NtpClock.h>

NtpClock _clock;

void setup() {
  _clock.setWiFi("mySSID", "myPassphrase");
  _clock.begin();
}

void loop() {
  _clock.refresh();
  //_clock.blink(); // for alive signal
  delay(2000);
}
