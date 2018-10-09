CC = g++
CFLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14

all:	LLC 

run: all
	./LLC

LLC: LLC.o
	$(CC) $(CFLAGS) LLC.o -o LLC 

LLC.o:	LLC.h
	$(CC) $(CFLAGS) -c LLC.cpp -o LLC.o


clean:
	rm -f *.o LLC
	
checkmem:
	valgrind ./LLC
