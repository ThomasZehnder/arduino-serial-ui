#include "Arduino.h"
#include "serial-led.hpp"
#include "serial-display.hpp"

void ledInit(void)
{
  int i;
  // initialize digital pin LED_BUILTIN as an output.
  for (i = 0; i < 4; i++)
  {
    pinMode(pinArray[i], OUTPUT);
    digitalWrite(pinArray[i], LOW); // turn the LED off by making the voltage LOW

    // initial demo flashing
    ledPulse();
    selectetPin = (1+i)%4;
  }
}

void ledPulse(void)
{
  digitalWrite(pinArray[selectetPin], HIGH); // turn the LED on (HIGH is the voltage level)
  delay(100);                                // wait
  digitalWrite(pinArray[selectetPin], LOW);  // turn the LED on (HIGH is the voltage level)
  delay(100);
}
void ledFlash(void)
{
  int i;
  for (i = 1; i < 10; i++)
  {
    ledPulse();
  }
}

void ledCommand(char c)
{
  if (c == 'f')
  {
    ledFlash();
    serialPlusOled("f = flash sequence 10 times fast");
  }
  else if (c == 'o')
  {
    digitalWrite(pinArray[selectetPin], HIGH); // turn the LED on (HIGH is the voltage level)
    serialPlusOled("o = off");
  }
  else if (c == 'x')
  {
    digitalWrite(pinArray[selectetPin], LOW); // turn the LED on (HIGH is the voltage level)
    serialPlusOled("x = on");
  }
  else if (c == 'p')
  {
    ledPulse();
    serialPlusOled("p = 100ms puls");
  }
  else if (c == 'd')
  {
    delay(100);
    serialPlusOled("d = 100ms delay");
  }
  else if (c == '0')
  {
    serialPlusOled("select led 0");
    selectetPin = 0;
  }
  else if (c == '1')
  {
    serialPlusOled("select led 1");
    selectetPin = 1;
  }
  else if (c == '2')
  {
    serialPlusOled("select led 2");
    selectetPin = 2;
  }
  else if (c == '3')
  {
    serialPlusOled("select led 3");
    selectetPin = 3;
  }
  else if (c == '\r')
  {
    //Serial.println(".r.\r");
  }
  else if (c == '\n')
  {
    ///Serial.println(".n.\n");
  }
  else
  {
    Serial.print("Command: ");
    Serial.print(c);
    Serial.print(",");
    Serial.print(c, HEX);
    Serial.println(" not implemented");
  }
}
