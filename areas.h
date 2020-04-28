area nowhere;
nowhere.description = "You see no path in that direction.";
nowhere.shortDescription = "You see no path in that direction.";
nowhere.invalid = true;
nowhere.function = &fixPosition;
area northPlace;
northPlace.description = "You're in a bathroom, the floor is concerningly wet. You see an exit to the south.";
northPlace.shortDescription = "Bathroom";
area startingPoint;
startingPoint.description = "You find yourself in a basement, you're not sure how you got here. You see a Japanese thing and have an unreasonable urge to destroy it. You see  You see a tunnel to the north, an exit to the south, and infinite recursion to the west.";
startingPoint.shortDescription = "Basement";
startingPoint.items.push_back(tickler);
startingPoint.enemies.push_back(japaneseThing);
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
