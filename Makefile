CC=gcc
adventureGame: adventureGame.cpp items.h characters.h areas.h
	g++ -o adventureGame adventureGame.cpp
	echo Done
