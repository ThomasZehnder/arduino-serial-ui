#include "Arduino.h"
#include "serial-display.hpp"

SSD1306AsciiWire oled;

void displaySetup(void) {
  Wire.begin();
  Wire.setClock(400000L);
  oled.begin(&Adafruit128x64, I2C_ADDRESS);
  oled.setScrollMode(SCROLL_MODE_AUTO);

  oled.setFont(fixed_bold10x15);
  oled.clear();
  oled.println("Serial UI");

  oled.setFont(System5x7);
  oled.print("Build: ");
  oled.println(__DATE__);
  oled.print(" / ");
  oled.println(__TIME__);
  oled.setFont(System5x7);
}

void serialPlusOled(char *s)
{
  Serial.println(s);
  oled.println(s);
}

void serialPlusOledDelayed(char *s)
{
  serialPlusOled(s);
  delay(50);
}


void displayShowCommand(char c)
{
  if (c != '\n') //avoid unnecessary line for LF
  {
    oled.print("Command: ");
    oled.print((int)c);
    oled.print(" > ");
    oled.println(c);
  }
}

bool displaySetting(char  c)
{
  if (c == '#')
  {
    oled.setFont(fixed_bold10x15);
    return true;
  }
  else if (c == '|')
  {
    oled.setFont(System5x7);
    return true;
  }

  else if (c == '&')
  {
    oled.clear();
    return true;
  }
  return false;
}
