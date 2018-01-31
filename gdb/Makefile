TARGET=gdb-demo

all: $(TARGET)

$(TARGET): $(TARGET).c
	gcc -ggdb3 $< -o $@

clean:
	rm -rf *.o *.dSYM $(TARGET)
