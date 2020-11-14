#include "Arduino.h"
#include "serial-display.hpp"
#include "serial-key.hpp"

void help()
{
  int aditionalDelay = 0;
  while (keyPressed(0)) {aditionalDelay=1000;}; // wait on key0
  while (keyPressed(1)) {aditionalDelay=1000;}; // wait on key1
  serialPlusOledDelayed("Led Commands");
  serialPlusOledDelayed("x = on");
  serialPlusOledDelayed("o = off");
  serialPlusOledDelayed("d = 100ms delay");
  serialPlusOledDelayed("p = 100ms puls");
  serialPlusOledDelayed("f = flash sequence 10 times fast");
  serialPlusOledDelayed("0..3 = select led (modal)");
  delay(200+aditionalDelay);
  while (keyPressed(0)) {}; // wait on key0
  while (keyPressed(1)) {}; // wait on key1
  serialPlusOledDelayed("Display Commands");
  serialPlusOledDelayed("\\ = switch to led command");
  serialPlusOledDelayed("@ = switch to oled output");
  serialPlusOledDelayed("# = big font");
  serialPlusOledDelayed("| = small font");
  serialPlusOledDelayed("& = clear display");
  serialPlusOledDelayed("h = this help");
}
