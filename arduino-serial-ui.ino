/*
  Switch on build in LED with serial input 9600 Baud:
  o = off
  x = on
  p = 100ms puls
  f = flash sequence 10 times fast

  ## First config Board: ArduinoWLAN 1202: Board Config, does not work with B&R USB, device is not recogniced
    NodeMCU 1.0
    Flash Size: 4M(3M SPIFFS)
   I2C Bus:
   SDA = D1 = GPIO 5
   SCL = D2 = GPIO 4

  ESP8266 ESP-13 Reset Method V1.0 --> Grosses Arduino Board does not work with B&R USB, device is not recogniced


  Arduino Nano --> kleines Board, geht für RS232 Emulation auf B&R Steuerung
    Old Boot loader !!!
   I2C Bus:
   SDA = A4
   SCL = A5

  // initialize serial: baud rate fix to 115200, B&R PLC works with USB support and FRM- Library, othed baud rates are not supportde.


*/

#include "serial-help.h"
#include "serial-key.h"
#include "serial-display.h"
#include "serial-led.h"


SSD1306AsciiWire oled;

char c = 0;

char pinArray[4];
char selectetPin  = 0;

bool serielToOledOn = false;

bool valKey[2];
bool valKey_old[2];
int pinKey[2];


void setup()
{
  // setup OLED display
  displaySetup();

  // initialize serial: baud rate fix to 115200, B&R PLC works with USB support and FRM- Library, othed baud rates are not supportde.

  Serial.begin(115200);
  Serial.println("###############################################################");
  Serial.println(" Serial Interface to Leds, Oled Display and keys (115200 Baud )");
  Serial.println("###############################################################");
  Serial.print(__DATE__);
  Serial.print(" / ");
  Serial.println(__TIME__);

  //Default settings IO mapping

#if defined(ARDUINO_AVR_UNO)
  // Uno pin assignments
  serialPlusOled("ARDUINO_AVR_UNO");

#elif defined(ARDUINO_AVR_NANO)
  // NANO
  serialPlusOled("ARDUINO_AVR_NANO");

  pinArray[0] = LED_BUILTIN;
  pinArray[1] = PD5;
  pinArray[2] = PD6;
  pinArray[3] = PD7;
  pinKey[0] = 11; //D11;
  pinKey[1] = 12; //D12;


#elif defined(ARDUINO_ESP8266_NODEMCU)
  // ESP8266_NODEMCU
  serialPlusOled("ESP8266_NODEMCU");

  pinArray[0] = LED_BUILTIN;
  pinArray[1] = D5;
  pinArray[2] = D6;
  pinArray[3] = D7;
  pinKey[0] = D11;
  pinKey[1] = D12;

#elif defined(ARDUINO_ESP8266_ESP13)
  // ESP8266_ESP13 not tested
  Serial.println("ARDUINO_ESP8266_ESP13");

#else
#error Unsupported board selection. Stop compilation.
#endif

  // initialize leds
  ledInit();

  // initialize keys
  keyInit();

  //INTRO Help (also accessable with \h)
  Serial.println("###############################################################");
  help();
  Serial.println("###############################################################");

  oled.print("Boot finished!!!");
}

void loop()
{
  keyEdgeDetect();

  // if there's any serial available, read it:
  while (Serial.available() > 0)
  {
    // look wait on input
    c = Serial.read();


    if (c == '\\')
    {
      serielToOledOn = false;
      Serial.println("@ send off to OLED");
      oled.setFont(System5x7);
    }

    else if (c == '@')
    {
      serielToOledOn = true;
      Serial.println("@ send character to OLED without interpretating until \\");
    }

    else if (displaySetting(c)) {
      // if char is consumed return Value is true

    }
    
    else if (serielToOledOn) {
      oled.print(c);
    }
    
    else
    {

      displayShowCommand(c);

      if (c == 'h')
      {
        help();
      }
      else
      {
        ledCommand(c);
      }

    }
  }
}
