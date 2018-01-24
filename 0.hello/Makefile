all: hello hello2 wrong-hello

hello: hello.c
	gcc -O2 hello.c -o hello

hello2: hello.c
	gcc -ggdb hello.c -o hello2

wrong-hello: wrong-hello.c
	gcc wrong-hello.c -o wrong-hello

clean:
	rm -f wrong-hello hello hello2
