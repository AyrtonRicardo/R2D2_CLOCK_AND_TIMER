#include <Arduino.h>
#include <WiFiManager.h>
#include <NTPClient.h>
#include <TM1637Display.h>
#include <DFRobotDFPlayerMini.h>
#include <AiEsp32RotaryEncoder.h>

//========================USEFUL VARIABLES=============================
uint16_t notification_volume = 15;
int UTC = 2;               // UTC + value in hour - Summer time
int Display_backlight = 3; // Set displays brightness 0 to 7;
const char *ntpServer = "europe.pool.ntp.org";
const char *wifimanagerSSID = "R2D2"; // ssid used in case you wanna use wifimanager, ignored otherwise.
const char *wifimanagerPASS = "landshover"; // pass used in case you wanna use wifimanager, ignored otherwise.
const int intervalToUpdateTime = 60000; // interval in milliseconds to re-check if the time has drifted.
const char *dnsIpAddress = "8.8.8.8";
const bool areEncoderPinsPulldownforEsp32 = false; // in case using rotary encoder without pcb, set to false.
const long utcOffsetInSeconds = 3600; // UTC + 1H / Offset in second
int volume = 30;

// Change if you wanna use different settings
const char *ssid     = ""; // put your SSID between the quotes mark IF YOU WANT TO HARDCODE YOUR WIFI SETTINGS
const char *password = ""; // put your wifi password between the quotes mark IF YOU WANT TO HARDCODE YOUR WIFI SETTINGS
//=====================================================================

#define ROTARY_ENCODER_B_PIN 26
#define ROTARY_ENCODER_A_PIN 25
#define ROTARY_ENCODER_BUTTON_PIN 27
#define ROTARY_ENCODER_STEPS 4
#define ROTARY_ENCODER_VCC_PIN -1

#define RED_LED 32
#define WHITE_LED 33
#define FPSerial Serial1

const byte RXD2 = 16;                 // Connects to module's TX
const byte TXD2 = 17;                 // Connects to module's RX

//> Function declaration

void printDetail(uint8_t type, int value);

void waitMilliseconds(uint16_t msWait);

void Setup_timer();

void Countdown(float timer_counter);

void IRAM_ATTR readEncoderISR();
//< Function declaration
