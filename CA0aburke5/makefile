#
# Specifiy the target
all:	BurkeAlex-aburke5-Hello

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
BurkeAlex-aburke5-Hello:	BurkeAlex-aburke5-Hello.o Hello_Class.o
	g++  BurkeAlex-aburke5-Hello.o Hello_Class.o -o BurkeAlex-aburke5-Hello.exe

# Specify how the object files should be created from source files
BurkeAlex-aburke5-Hello.o:	BurkeAlex-aburke5-Hello.cpp
	g++ -c BurkeAlex-aburke5-Hello.cpp
	
Hello_Class.o: Hello_Class.cpp
		g++ -c Hello_Class.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o BurkeAlex-aburke5-Hello.exe
	rm -f Hello_Class.exe
