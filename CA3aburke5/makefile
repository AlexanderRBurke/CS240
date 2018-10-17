CC = g++
CFLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14

all:	LLC 

run: all
	./LLC

LLC: LLC.o Main.o
	$(CC) $(CFLAGS) LLC.o Main.o -o LLC 

LLC.o:	LLC.h LLC.cpp
	$(CC) $(CFLAGS) -c LLC.cpp -o LLC.o

Main.o:	Main.cpp
	$(CC) $(CFLAGS) -c Main.cpp -o Main.o

clean:
	rm -f *.o LLC
	
checkmem:
	valgrind ./LLC
