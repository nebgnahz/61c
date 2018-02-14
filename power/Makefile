# CC=gcc
CC=/opt/riscv/toolchain/bin/riscv64-unknown-elf-gcc

TARGET=main

all: $(TARGET)

power.o: power.c power.h
	$(CC) -c $<

main.o: main.c
	$(CC) -c $<

$(TARGET): main.o power.o
	$(CC) -o $(TARGET) main.o power.o

clean:
	rm -f *.o $(TARGET)
