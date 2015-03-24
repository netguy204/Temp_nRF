all: test.hex

test.o: test.c
	avr-gcc -Os -mmcu=attiny88 -o $@ -c $<

test.elf: test.o
	avr-gcc -mmcu=attiny88 -o $@ $<

test.hex: test.elf
	avr-objcopy -j .text -j .data -O ihex $< $@
