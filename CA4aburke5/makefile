
CC = g++
CFLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14 -D_GLIBCXX_USE_CXX11_ABI=0

all:	war 

run: all
	./war

war: PlayingCard.o Player.o Game.o Tournament.o Main.o
	$(CC) $(CFLAGS) Game.o PlayingCard.o Player.o Tournament.o Main.o -o war  

#LLC.o:	LLC.h LLC.cpp
#	$(CC) $(CFLAGS) -c LLC.cpp -o LLC.o


PlayingCard.o: PlayingCard.h PlayingCard.cpp
	$(CC) $(CFLAGS) -c PlayingCard.cpp -o PlayingCard.o

Player.o: LLC.h Player.h Player.cpp
	$(CC) $(CFLAGS) -c Player.cpp -o Player.o

Game.o: LLC.h Player.h Game.h Game.cpp
	$(CC) $(CFLAGS) -c Game.cpp -o Game.o

Tournament.o: LLC.h Tournament.h Tournament.cpp
	$(CC) $(CFLAGS) -c Tournament.cpp -o Tournament.o

Main.o:	LLC.h Main.cpp
	$(CC) $(CFLAGS) -c Main.cpp -o Main.o

clean:
	rm -f *.o war 
	
checkmem:
	valgrind ./war

