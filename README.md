# arduino-serial-ui
arduino UI with OLED display, leds and two keys


Arduino Nano works :-) for B&R PLC

## Connection to B&R USB - Serial Acces
FTDI is working fine, use 115200 Baud only 
CP210x is NOT working (tested with ESP Board and Seriell small USB Serial 5V adapter)
CH340 is NOT working (tested with ESPDuino)
EPS8266 CP2102  --> Does not work for B&R PLC's

Search to: Nano V3.0 FT232 Chip ATmega328 Atmega328p 16M 

Stand: 
* Simple interface 115200 Baud
* 4 Leds with commands x,o,d,f,p
BUILD IN LED  = 0


# OLED Display 
## on ESP8266
D1 = SCK
D2 = SDA

## on Arduino Nano



## work with GIT
push --> commit to GIT, / 
pull --> get from GIT

    git push --set-upstream https://github.com/ThomasZehnder/arduino-serial-ui.git master
    git pull https://github.com/ThomasZehnder/arduino-serial-ui.git master


## TIP avoid extensiv log during compilation in VScode

It seems the excessive debug logging is caused by running Java with -DDEBUG=true. Adding -DDEBUG=false to the C:\Program Files (x86)\Arduino\arduino_debug.l4j.ini fixes it for me.

https://github.com/microsoft/vscode-arduino/issues/891