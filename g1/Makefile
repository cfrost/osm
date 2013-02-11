CC=gcc
CFLAGS=-g -pedantic -std=c99 -Wall -Wextra

all: queue.o queuetest.o test

test: queue.o queuetest.o
	$(CC) $(CFLAGS) queue.o queuetest.o -o test
	
queuetest.o: queuetest.c queue.h
	$(CC) $(CFLAGS) -c queuetest.c

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c

clean:
	rm -f *.o
