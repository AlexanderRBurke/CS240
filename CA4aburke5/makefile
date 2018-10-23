
CC = g++
CFLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14

all:	war 

run: all
	./war

war: LLC.o PlayingCard.o Main.o
	$(CC) $(CFLAGS) LLC.o PlayingCard.o Main.o -o LLC 

LLC.o:	LLC.h LLC.cpp
	$(CC) $(CFLAGS) -c LLC.cpp -o LLC.o

PlayingCard.o: PlayingCard.h PlayingCard.cpp
	$(CC) $(CFLAGS) -c PlayingCard.cpp -o PlayingCard.o

Main.o:	Main.cpp
	$(CC) $(CFLAGS) -c Main.cpp -o Main.o

clean:
	rm -f *.o LLC
	
checkmem:
	valgrind ./LLC

