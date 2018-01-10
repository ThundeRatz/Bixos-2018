.PHONY: all clean

all: hello

%.o: %.c
	gcc -o $@ -c $^

clean:
	rm -f *.o hello

hello: hello.o main.o
	gcc -o $@ $^

main.o: main.c

hello.o: hello.c
