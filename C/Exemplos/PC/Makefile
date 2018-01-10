SOURCES = $(wildcard *.c)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))

.PHONY: all echo clean teste

all: teste

echo:
	@echo $(SOURCES)
	@echo $(OBJECTS)

%.o: %.c
	gcc -c -o $@ $<

teste: $(OBJECTS)
	gcc -o teste main.o helloworld.o

clean:
	rm *.o *.exe
