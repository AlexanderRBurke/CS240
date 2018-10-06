#
# Specifiy the target
all:	LLC 

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Voter:	LLC.o VoterDB.o Main.o
	g++  Voter.o VoterDB.o Main.o -o Voter

# Specify how the object files should be created from source files
Voter.o:	Voter.cpp
	g++ -c Voter.cpp
	
VoterDB.o: VoterDB.cpp
		g++ -c VoterDB.cpp

Main.o: Main.cpp
	g++ -c Main.cpp
# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Voter
	
