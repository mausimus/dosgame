##### Starter DOS Game Project

* Visual Studio Code + [dos-dev extension](https://marketplace.visualstudio.com/items?itemName=badlogicgames.dos-dev)
* DJGPP/GCC 12.1.0
* Allegro 4.2.3.1
* i586 target

###### Notes

Tweaks needed to cross-compile Allegro from Windows using GCC 12:

1. Add -fgnu89-inline to CFLAGS in makefile.dj

2. Comment out makefile.dj section which creates asmdef.inc; instead:

* run its compile command from CROSSCOMPILE branch by hand (will generate asmdef.s file)
* convert CRLF in asmdef.s to LF
* execute asmdef.sh line in WSL to generate asmdef.inc

3. In file src/misc/vbeafex.c, remove static modifier from saved\_ds declaration
