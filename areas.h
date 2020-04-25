area nowhere;
nowhere.description = "You find yourself in an invalid location. This should not be possible.";
nowhere.invalid = true;
area northPlace;
northPlace.description = "You find yourself in another example area. North of the first and similarly useless. You see a tunnel to the south.";
northPlace.shortDescription = "North example area [s]";
area startingPoint;
startingPoint.description = "You are in an example area. It serves no purpose except as a place to be. You see a tunnel to the north. You can move by typing the first letter of the direction you want to go (n,e,s,w)";
startingPoint.shortDescription = "Example area [n]";
startingPoint.items.push_back(sword);
startingPoint.enemies.push_back(orc);


//Map
///Starting Point
startingPoint.north = &northPlace;
startingPoint.east = &nowhere;
startingPoint.south = &nowhere;
startingPoint.west = &nowhere;
///North Place
northPlace.north = &nowhere;
northPlace.east = &nowhere;
northPlace.south = &startingPoint;
northPlace.west = &nowhere;
