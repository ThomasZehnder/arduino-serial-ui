# arduino-serial-ui
arduino UI with OLED display, leds and two keys


Arduino Nano works :-)
FTDI-Chip or CH340/341 as USB-Seriell-Transmitter potentioli build in on Arduino Nano.

Connection to B&R USB - Serial Acces
FTDI is working fine, use 115200 Baud only 
CP210x is NOT working (tested with ESP Board and Seriell small USB Serial 5V adapter)
CH340 is NOT working (tested with ESPDuino)
EPS8266 CP2102  --> Does not work for B&R PLC's




Search to: Nano V3.0 FT232 Chip ATmega328 Atmega328p 16M 

Stand: 
* Simple interface 9600 Baud
* 4 Leds with commands x,o,d,f,p
BUILD IN LED  = 0


# OLED Display on ESP
D1 = SCK
D2 = SDA



## work with GIT
Un: ThomasZehnder
Pw: ...

push --> commit to GIT, / 
pull --> get from GIT

    git push --set-upstream https://github.com/ThomasZehnder/seriell-tool.git master
    git pull https://github.com/ThomasZehnder/seriell-tool.git master

## MaterialUI

Later include a WebInterface for "protocol and status"

## Post Build-Script
Diese koppiert den Build in den data-Folder vom Arduino Projekt und verkürzt die Dateinamen, und erstezt diese auch in den generierten Files.
Zusätzlich ersetz das Script auch Link-Pfade zu den Webservices auf lokale-relative Pfade so dass dies auf der Arduino-Umgebung funtioniert.
