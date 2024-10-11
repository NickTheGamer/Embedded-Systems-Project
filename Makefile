# File:   Makefile
# Authors: N. H. COETZEE, J. CERCADO
# Date:   9 October 2024
# Descr:  Makefile for Rock Paper Scissors

# Definitions.
CC = avr-gcc
CFLAGS = -mmcu=atmega32u2 -Os -Wall -Wstrict-prototypes -Wextra -g -I. -I../../utils -I../../fonts -I../../drivers -I../../drivers/avr
OBJCOPY = avr-objcopy
SIZE = avr-size
DEL = rm


# Default target.
all: game.out


# Compile: create object files from C source files.
game.o: game.c ../../drivers/avr/system.h display_char.h ir.h led.h nav.h scoring.h ../../utils/pacer.h
	$(CC) -c $(CFLAGS) $< -o $@

system.o: ../../drivers/avr/system.c ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

#DRIVERS WE USED
pacer.o: ../../utils/pacer.c ../../drivers/avr/system.h ../../drivers/avr/timer.h ../../utils/pacer.h
	$(CC) -c $(CFLAGS) $< -o $@

timer.o: ../../drivers/avr/timer.c ../../drivers/avr/system.h ../../drivers/avr/timer.h
	$(CC) -c $(CFLAGS) $< -o $@

#OUR FILES
display_char.o: display_char.c display_char.h
	$(CC) -c $(CFLAGS) $< -o $@

ir.o: ir.c ir.h
	$(CC) -c $(CFLAGS) $< -o $@

led.o: led.c led.h
	$(CC) -c $(CFLAGS) $< -o $@

nav.o: nav.c nav.h
	$(CC) -c $(CFLAGS) $< -o $@

scoring.o: scoring.c scoring.h
	$(CC) -c $(CFLAGS) $< -o $@

# Link: create ELF output file from object files.
game.out: game.o system.o display_char.o ir.o led.o nav.o scoring.o pacer.o timer.o
	$(CC) $(CFLAGS) $^ -o $@ -lm
	$(SIZE) $@


# Target: clean project.
.PHONY: clean
clean: 
	-$(DEL) *.o *.out *.hex


# Target: program project.
.PHONY: program
program: game.out
	$(OBJCOPY) -O ihex game.out game.hex
	dfu-programmer atmega32u2 erase; dfu-programmer atmega32u2 flash game.hex; dfu-programmer atmega32u2 start


