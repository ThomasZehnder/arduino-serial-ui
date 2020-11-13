#include "Arduino.h"
#include "serial-display.h"
#include "serial-keyhandling.h"

void help()
{
  while (keyPressed(0)) {}; // wait on key
  serialPlusOledDelayed("Led Commands");
  serialPlusOledDelayed("x = on");
  serialPlusOledDelayed("o = off");
  serialPlusOledDelayed("d = 100ms delay");
  serialPlusOledDelayed("p = 100ms puls");
  serialPlusOledDelayed("f = flash sequence 10 times fast");
  serialPlusOledDelayed("0..3 = select led (modal)");
  while (keyPressed(0)) {}; // wait on key
  delay(200);
  serialPlusOledDelayed("Display Commands");
  serialPlusOledDelayed("\\ = switch to led command");
  serialPlusOledDelayed("@ = switch to oled output");
  serialPlusOledDelayed("# = big font");
  serialPlusOledDelayed("| = small font");
  serialPlusOledDelayed("& = clear display");
  serialPlusOledDelayed("h = this help");
}
