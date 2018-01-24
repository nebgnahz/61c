all: libarithmetic.a main main2

%.o : %.c
	gcc -c $<

# add.o: add.c
# 	gcc -c add.c

# sub.o: sub.c
# 	gcc -c sub.c

libarithmetic.a: add.o sub.o
	ar rcs libarithmetic.a add.o sub.o

main: main.c
	gcc main.c add.o sub.o -o main

main2: main.c libarithmetic.a
	gcc main.c libarithmetic.a -o main2

clean:
	rm -f add.o sub.o libarithmetic.a main
