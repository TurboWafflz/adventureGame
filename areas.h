area nowhere;
nowhere.description = "You see no path in that direction.";
nowhere.invalid = true;
nowhere.function = &fixPosition;
area northPlace;
northPlace.description = "You find yourself in another example area. North of the first and similarly useless. You see a tunnel to the south.";
northPlace.shortDescription = "North example area [s]";
area startingPoint;
startingPoint.description = "You are in an example area. It serves no purpose except as a place to be. You see a tunnel to the north, and an exit to the south. You can move by typing the first letter of the direction you want to go (n,e,s,w)";
startingPoint.shortDescription = "Example area [n]";
startingPoint.items.push_back(sword);
startingPoint.enemies.push_back(orc);
area exit;
exit.description = "You decide to leave the game. Goodbye!";
exit.function = &leave;

//Map
///Starting Point
startingPoint.north = &northPlace;
startingPoint.east = &nowhere;
startingPoint.south = &exit;
startingPoint.west = &nowhere;
///North Place
northPlace.north = &nowhere;
northPlace.east = &nowhere;
northPlace.south = &startingPoint;
northPlace.west = &nowhere;
