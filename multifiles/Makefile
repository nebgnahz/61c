all: libarithmetic.a main main_static
# CC=gcc -O0
# AR=ar
CC=/opt/riscv/toolchain/bin/riscv64-unknown-elf-gcc -O0
AR=/opt/riscv/toolchain/bin/riscv64-unknown-elf-ar

%.o : %.c
	$(CC) -c -fPIC $<

%.s : %.c
	$(CC) -c $< -S -o $@

# gcc -c add.c -S -o add.s


# add.o: add.c
# 	gcc -c add.c

# sub.o: sub.c
# 	gcc -c sub.c

# main.o: main.c
# 	gcc -c main.c

libarithmetic.a: add.o sub.o mul.o
	## Create library
	$(AR) rcs libarithmetic.a add.o sub.o mul.o

libarithmetic.so: add.o sub.o mul.o
	$(CC) -shared -fPIC -o libarithmetic.so add.o sub.o mul.o

main: main.o add.o sub.o mul.o
	## Link
	$(CC) -o main main.o add.o sub.o mul.o

main_static: main.c libarithmetic.a
	## Link against the library
	$(CC) main.c libarithmetic.a -o main_static

main_dynamic: main.c libarithmetic.so
	## Link against the dynamic
	PWD=$(shell pwd)
	$(CC) -fPIC main.c -o main_dynamic -L$(PWD) -larithmetic

clean:
	rm -f *.o *.s libarithmetic.* main main_static main_dynamic
