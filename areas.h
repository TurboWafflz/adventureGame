area nowhere;
nowhere.description = "You see no path in that direction.";
nowhere.shortDescription = "You see no path in that direction.";
nowhere.invalid = true;
nowhere.function = &fixPosition;
area northPlace;
northPlace.description = "You find yourself in another example area. North of the first and similarly useless. You see a tunnel to the south.";
northPlace.shortDescription = "North example area";
area startingPoint;
startingPoint.description = "You are in an example area. It serves no purpose except as a place to be. You see a tunnel to the north, an exit to the south, and infinite recursion to the west.";
startingPoint.shortDescription = "Example area";
startingPoint.items.push_back(sword);
startingPoint.enemies.push_back(orc);
area exit;
exit.description = "You decide to leave the game. Goodbye!";
exit.shortDescription = "You decide to leave the game. Goodbye!";
exit.function = &leave;

//Map
///Starting Point
startingPoint.north = &northPlace;
startingPoint.east = &nowhere;
startingPoint.south = &exit;
startingPoint.west = &startingPoint;
///North Place
northPlace.north = &nowhere;
northPlace.east = &nowhere;
northPlace.south = &startingPoint;
northPlace.west = &nowhere;
