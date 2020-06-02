#!/bin/sh

ARDUINO_PATH=/usr/share/arduino
export ARDUINO_PATH
COMPILER_PATH=~/.arduino15/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/
export COMPILER_PATH
AVRDUDE=/usr/bin/avrdude
export AVRDUDE
AVRDUDE_CONF=/etc/avrdude.conf
export AVRDUDE_CONF

make $@
