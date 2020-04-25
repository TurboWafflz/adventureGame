#include <iostream>
#include <memory>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class item{
public:
	string name;
	string description;
	int attackDamage = 0;
	bool consumable = false;
	int healthEffect = 0;
};
class enemy{
public:
	string name;
	vector<item> inventory;
	int health = 100;
	item weapon;
};
class area{
public:
	string description;
	string shortDescription;
	area *north;
	area *east;
	area *south;
	area *west;
	bool visited = false;
	bool invalid = false;
	vector<item> items;
	vector<enemy> enemies;
	void (*function)(void *player);
};
class character{
public:
	area *location;
	string name;
	vector<item> inventory;
	int health = 100;
	area *oldLocation;
};
#include "functions.h"
int main() {
	//Clear screen
	cout << "\033[2J\033[1;1H";
	//Setup player;
	character player;
	cout << "Player name: ";
	getline(cin, player.name);
	#include "items.h"
	#include "characters.h"
	#include "areas.h"
	//Place player
	player.location = &startingPoint;
	//Start game
	bool running = true;
	while(running){
		if(player.health == 0){
			cout << "You died!" << endl;
			break;
		}
		if(player.location->invalid){
			cout << "You see no path in that direction." << endl;
			player.location = player.oldLocation;
		}
		//Display shortened description if player has already visited the area, otherwise, display full description
		if(not player.location->visited){
			cout << player.location->description << endl;
		} else{
			cout << player.location->shortDescription << endl;
		}
		//Set location to visited
		player.location->visited = true;
		//List items
		for(item thisItem : player.location->items){
			cout << "You see a " + thisItem.name << endl;
		}
		//List enemies
		for(enemy thisEnemy : player.location->enemies){
			cout << "You see a " + thisEnemy.name << endl;
		}
		//Run function for area
		player.location->function(&player);

	}
	return 0;
}