F_CPU = 8000000
MCU = attiny85
MODULES = main.o onewire.o usitwislave.o ds18b20.o
MODULE_ROMSEARCH = 

CC = avr-gcc
CFLAGS = -Wall -DF_CPU=$(F_CPU) -mmcu=$(MCU) -Os

LD = avr-ld
LDFLAGS =
PROGRAMMER = -c USBasp
AVRDUDE = avrdude $(PROGRAMMER) -p $(MCU)

all: ds18b20.o libds18b20.a main.hex

flash: all
	$(AVRDUDE) -U flash:w:main.hex:i

libds18b20.a: ds18b20.o
	avr-ar -cvq libds18b20.a ds18b20.o
	avr-ar -t libds18b20.a

main.o: main.c 	
	$(CC) $(CFLAGS) -c main.c -o main.o

usitwislave.o: usitwislave.c usitwislave.h	
	$(CC) $(CFLAGS) -c usitwislave.c -o usitwislave.o

onewire.o: onewire.c onewire.h
	$(CC) $(CFLAGS) -c onewire.c -o onewire.o

ds18b20.o: ds18b20.c ds18b20.h
	$(CC) $(CFLAGS) -c ds18b20.c -o ds18b20.o

romsearch.o: romsearch.c romsearch.h
	$(CC) $(CFLAGS) -c romsearch.c -o romsearch.o

usitwisalve.o: usitwislave.c usitwislave.h 
	$(CC) $(CFLAGS) -c usitwislave.c -o usitwislave.o 

clean:
	rm -f main.hex main.elf $(MODULES)

end:
	avr-size -C --mcu=$(MCU) ds18b20.o

main.elf: $(MODULES)
	$(CC) $(CFLAGS) -o main.elf $(MODULES)

main.hex: main.elf
	rm -f main.hex
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex
	avr-size --format=avr --mcu=$(MCU) main.elf


