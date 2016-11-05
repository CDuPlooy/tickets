#!/bin/sh
#u16169532 Connor Armand Du Plooy
#Setups qt5 on a debian/arch system.
#Only run this if compilation fails on the qt build.

if (pacman --version 2> /dev/null); then
      sudo pacman -S qt5-default
fi
if (apt-get --version 123> /dev/null); then
      sudo apt-get install qt5-default
fi
