#ifndef LIBNTPCLOCK
#define LIBNTPCLOCK

#include <Arduino.h>

#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DEBUG
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define CHAR_PIXEL 6 // x and y pixels of a char

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     LED_BUILTIN // Reset pin # (or -1 if sharing Arduino reset pin)

#define LED_BLINK D7

class NtpClock
{
public:
  NtpClock();
  //˜NtpClock(){}

  void setWiFi(String ssid, String password);
  void setCycles(uint16_t rtcSyncCycle, uint16_t ntpSyncCycle);
  void begin(void);

  void update(void);
  void wait(void);

  void blink(void);

  void timeNTPSync(void);
  bool timeUpdate(void);

  void displaySetTime(uint8_t h, uint8_t m, uint8_t s);
  void displaySetTime(uint8_t h, uint8_t m);
  void displaySetStatus(String status);
  void displaySetDebug(String debug);
  void displayTime();
  void displayStatus();
  void displayDebug();
  void displayRefresh();

  uint8_t getHours(void);
  uint8_t getMinutes(void);
  uint8_t getSeconds(void);

  uint8_t getEpochHours(unsigned long epoch);
  uint8_t getEpochMinutes(unsigned long epoch);
  uint8_t getEpochSeconds(unsigned long epoch);


private:
  NtpClock(NtpClock const&)     = delete;
  void operator=(NtpClock const&) = delete;

  WiFiUDP _ntpUDP;
  NTPClient _timeClient;
  Adafruit_SSD1306 _display;

  uint16_t _rtcSyncCycle; // cycle time to sync with internal rtc [s]
  uint16_t _ntpSyncCycle; // cycle time to sync with ntp [s]

  unsigned long _syncEpoch;
  unsigned long _syncRTC;
  unsigned long _syncError;

  uint8_t _h,_m,_s;

  String _status;
  String _debug;

  String _ssid;
  String _pwd;
};

#endif
