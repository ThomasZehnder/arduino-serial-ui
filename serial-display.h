#ifndef serial-display_h
#define serial-display_h

#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C

extern SSD1306AsciiWire oled;

void displaySetup(void);

void serialPlusOled(char *s);
void serialPlusOledDelayed(char *s);

void displayShowCommand(char  c);

bool displaySetting(char  c);

#endif //serial-display_h
