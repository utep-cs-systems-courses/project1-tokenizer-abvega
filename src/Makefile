
CFLAGS=-g -O3

all: main

main: main.o
	cc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o main
run: main
	./main
