# arduino-serial-ui
arduino UI with OLED display, 4 leds and two keys

![Intro image](images/arduino-serial-ui.jpg)
<img src="images/arduino-serial-ui.jpg" alt="drawing" width="200"/>

Arduino Nano V3.0 with FTDI UART works :-) for B&R PLC

## Connection to B&R USB - serial access
FTDI is working fine for B&R USB conectetion
CP210x is NOT working for B&R PLC (tested with ESP Board and Seriell small USB Serial 5V adapter)  
CH340 is NOT working for B&R PLC (tested with ESPDuino)  
EPS8266 CP2102  --> Does not work for B&R PLC's  

Search for if you try to rebuild: Nano V3.0 FT232 Chip ATmega328 Atmega328p 16M  
Check there is not a CH340 build in.

## Connection to B&R USB - serial access
For Linux or Windows all variants are working without any problems.

# UART Settings: 
* 115200 Baud, n, 1

Serial Commands:
* 4 Leds with commands x,o,d,f,p
BUILD IN LED  = 0


# OLED Display Wirering
## on ESP8266
D1 = SCK
D2 = SDA

## on Arduino Nano



## work with GIT
push --> commit to GIT, / 
pull --> get from GIT

use commandos in VScode :-)


## TIP avoid extensiv logs during compilation arduino project in VScode

It seems the excessive debug logging is caused by running Java with -DDEBUG=true. Adding -DDEBUG=false to the C:\Program Files (x86)\Arduino\arduino_debug.l4j.ini fixes it for me.

https://github.com/microsoft/vscode-arduino/issues/891