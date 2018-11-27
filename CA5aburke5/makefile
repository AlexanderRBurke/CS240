CC = g++
CFLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14 -D_GLIBCXX_USE_CXX11_ABI=0

all:	graphs 

run: all
	./war

graphs: Main.o
	$(CC) $(CFLAGS) Main.o -o graphs  

#LLC.o:	LLC.h LLC.cpp
#	$(CC) $(CFLAGS) -c LLC.cpp -o LLC.o


Main.o:	Edge.h Node.h Main.cpp
	$(CC) $(CFLAGS) -c Main.cpp -o Main.o

clean:
	rm -f *.o graphs 
	
checkmem:
	valgrind ./graphs

