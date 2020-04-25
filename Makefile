CC=g++
adventureGame: adventureGame.cpp items.h characters.h areas.h
	echo "Building..."
	g++ -o adventureGame adventureGame.cpp
	echo Done
