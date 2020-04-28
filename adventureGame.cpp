#include <iostream>
#include <memory>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <readline/readline.h>
using namespace std;
class area;
void actionParser(void* a);
class item{
public:
	string name;
	string description;
	int attackDamage = 0;
	bool consumable = false;
	int healthEffect = 0;
	string type = "ITEM";
	string article = "a";
};
class enemy{
public:
	string name;
	vector<item> inventory;
	int health = 100;
	item weapon;
};
class character{
public:
	area *location;
	string name;
	vector<item> inventory;
	int health = 100;
	area *oldLocation;
	bool running;
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
	void (*function)(void *player) = &actionParser;
};
#include "functions.h"
int main() {
	//Clear screen
	cout << "\033[2J\033[1;1H";
	//Setup player;
	character player;
	cout << "Player name: ";
	getline(cin, player.name);
	cout << "Loading items..." << endl;
	#include "items.h"
	cout << "Loading NPCs..." << endl;
	#include "characters.h"
	cout << "Loading map..." << endl;
	#include "areas.h"
	cout << "\033[2J\033[1;1H";
	//Place player
	player.location = &startingPoint;
	player.running = true;
	//Start game
	while(player.running){
		if(player.health == 0){
			cout << "You died!" << endl;
			break;
		}
		// if(player.location->invalid){
		// 	cout << "You see no path in that direction." << endl;
		// 	player.location = player.oldLocation;
		// }
		//Display shortened description if player has already visited the area, otherwise, display full description
		if(not player.location->visited){
			cout << player.location->description << endl;
		} else{
			cout << player.location->shortDescription << endl;
		}
		//Set location to visited
		player.location->visited = true;
		//List exits
		cout << "[Exits:";
		if(player.location->north != &nowhere){
			cout << " n ";
		}
		if(player.location->east != &nowhere){
			cout << " e ";
		}
		if(player.location->south != &nowhere){
			cout << " s ";
		}
		if(player.location->west != &nowhere){
			cout << " w ";
		}
		cout << "]\n";
		//List items
		for(item thisItem : player.location->items){
			cout << "[" + thisItem.type + "] You see " + thisItem.article + " " + thisItem.name << endl;
		}
		//List enemies
		for(enemy thisEnemy : player.location->enemies){
			cout << "[ENEMY] You see a " + thisEnemy.name << endl;
		}
		//Run function for area
		player.location->function(&player);

	}
	return 0;
}
