#include "NtpClock.h"

NtpClock::NtpClock()
:
_ntpUDP(),
_timeClient(_ntpUDP, "europe.pool.ntp.org", 7200, 60000),
_display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET)
{
  pinMode(LED_BLINK, OUTPUT);

  _h = 0xFFU;
  _m = 0xFFU;
  _s = 0xFFU;

  _rtcSyncCycle = 1U; // 1s rtc sync cycle
  _ntpSyncCycle = 3600U; // 1h ntp sync cycle

  _syncEpoch = 0U;
  _syncRTC = 0U;
  _syncError = 0U;

  _status = "";

  return;
}

void NtpClock::setWiFi(String ssid, const String password)
{
  _ssid = ssid;
  _pwd = password;
  return;
}

void NtpClock::setCycles(uint16_t rtcSyncCycle, uint16_t ntpSyncCycle)
{
  _rtcSyncCycle = rtcSyncCycle;
  _ntpSyncCycle = ntpSyncCycle;
  return;
}

void NtpClock::begin(void)
{
  _display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  _display.display();
  delay(1000);

  displaySetStatus("connecting ...");
  displayRefresh();

  WiFi.begin(_ssid, _pwd);

  delay(500);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
  }

  _timeClient.begin();
  delay(1000);

  displaySetStatus("connected!");
  timeNTPSync();
  displayRefresh();
  delay(2000);

  displaySetStatus("");
  displayRefresh();

  return;
}

void NtpClock::update(void)
{
  displaySetDebug("Debug");

  if (timeUpdate())
  {
    //displaySetStatus(String(millis()));
    displayRefresh();
  }

  return;
}

void NtpClock::wait(void)
{
  delay(_rtcSyncCycle);
  return;
}

void NtpClock::blink(void)
{
  digitalWrite(LED_BLINK, HIGH);
  delay(500);
  digitalWrite(LED_BLINK, LOW);

  return;
}

void NtpClock::timeNTPSync(void)
{
  unsigned long syncRTC = millis()/1000U;
  unsigned long syncEpoch = 0U;
  long syncError = 0U;

  _timeClient.update();
  delay(2000);
  syncEpoch = _timeClient.getEpochTime();

  if (_syncRTC != 0U)
  {
    syncError = syncEpoch - _syncEpoch;
    syncError -= (long) (syncRTC - _syncRTC);
    _syncError += abs(syncError);
  }

  displaySetStatus(String(_syncError));

  _syncEpoch = syncEpoch;
  _syncRTC = syncRTC;

  return;
}

bool NtpClock::timeUpdate(void)
{
  bool ret = false;
  unsigned long ts;
  unsigned long rtcPeriod = millis()/1000U - _syncRTC;

  if (rtcPeriod >= _ntpSyncCycle)
  {
    timeNTPSync();
  }

  ts = _syncEpoch - _syncRTC + millis()/1000U;

  uint8_t h = getEpochHours(ts);
  uint8_t m = getEpochMinutes(ts);
  uint8_t s = getEpochSeconds(ts);

  if (_h != h || _m != m || _s != s)
  {
    displaySetTime(h, m, s);
    ret = true;
  }

  return ret;
}

void NtpClock::displaySetTime(uint8_t h, uint8_t m)
{
  _h = h;
  _m = m;
  _s = 0xFFU;

  return;
}
void NtpClock::displaySetTime(uint8_t h, uint8_t m, uint8_t s)
{
  _h = h;
  _m = m;
  _s = s;

  return;
}

void NtpClock::displaySetStatus(String status)
{
  _status = status;

  return;
}

void NtpClock::displaySetDebug(String debug)
{
  _debug = debug;

  return;
}


void NtpClock::displayTime(void)
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
}

void NtpClock::displayStatus(void)
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

void NtpClock::displayDebug(void)
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

void NtpClock::displayRefresh(void)
{
  _display.clearDisplay();

  #ifdef DEBUG
  String debug;
  debug = "ntp sync:";
  debug += String(getEpochHours(_syncEpoch),3);
  debug += ":";
  debug += getEpochMinutes(_syncEpoch);
  debug += ":";
  debug += getEpochSeconds(_syncEpoch);
  displaySetDebug(debug);
  displayDebug();
  #endif
  displayTime();
  displayStatus();

  // render
  _display.display();
  delay(50);

  return;
}

uint8_t NtpClock::getHours(void)
{
  return _h;
}
uint8_t NtpClock::getMinutes(void)
{
  return _m;
}
uint8_t NtpClock::getSeconds(void)
{
  return _s;
}

uint8_t NtpClock::getEpochHours(unsigned long epoch)
{
  return (epoch / 3600) % 24;
}
uint8_t NtpClock::getEpochMinutes(unsigned long epoch)
{
  return (epoch / 60) % 60;
}
uint8_t NtpClock::getEpochSeconds(unsigned long epoch)
{
  return epoch % 60;
}
