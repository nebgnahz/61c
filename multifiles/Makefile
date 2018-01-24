all: libarithmetic.a main main2

%.o : %.c
	gcc -c $<

# add.o: add.c
# 	gcc -c add.c

# sub.o: sub.c
# 	gcc -c sub.c

# main.o: main.c
# 	gcc -c main.c

libarithmetic.a: add.o sub.o
	## Create library
	ar rcs libarithmetic.a add.o sub.o

main: main.o add.o sub.o
	## Link
	gcc -o main main.o add.o sub.o

main2: main.c libarithmetic.a
	## Link against the library
	gcc main.c libarithmetic.a -o main2

clean:
	rm -f add.o sub.o libarithmetic.a main
