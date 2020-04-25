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
};
class character{
public:
	area *location;
	string name;
	vector<item> inventory;
	int health = 100;
	area *oldLocation;
};
int main() {
	//Clear screen
	cout << "\033[2J\033[1;1H";
	//Setup player;
	character player;
	cout << "Player name: ";
	cin >> player.name;
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
		string action;
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
		//Get action from player
		cin >> action;
		//Execute player action
		//Movement commands
		if(action == "n"){
			player.oldLocation = player.location;
			player.location = player.location->north;
		} else if(action == "e"){
			player.oldLocation = player.location;
			player.location = player.location->east;
		} else if(action == "s"){
			player.oldLocation = player.location;
			player.location = player.location->south;
		} else if(action == "w"){
			player.oldLocation = player.location;
			player.location = player.location->west;
		} else if(action == "die"){
			cout << "You decide that you will die now. Hopefully for testing or demonstration purposes." << endl;
			player.health = 0;
		} else if(action == "stats"){
			//Display player stats
			cout << "\n Player stats:" << endl;
			cout << "===============" << endl;
			cout << "Name: " + player.name << endl;
			cout << "HP: " + to_string(player.health) << endl << endl;
		} else if(action == "take"){
			//Pick up an item
			cout << "What would you like to take?" << endl;
			string requestedItem;
			cin >> requestedItem;
			bool found = false;
			int itemIndex = 0;
			for(item thisItem : player.location->items){
				if(thisItem.name == requestedItem){
					cout << "Taken" << endl;
					player.inventory.push_back(thisItem);
					player.location->items.erase(player.location->items.begin() + itemIndex);
					found = true;
				}
				itemIndex++;
			}
			if(!found){
				cout << "That item could not be found." << endl;
			}
		} else if(action == "inventory" or action == "i"){
			//Display player inventory
			cout << "\n Inventory" << endl;
			cout << "===========" << endl;
			int itemNumber = 1;
			for(item thisItem : player.inventory){
				cout << to_string(itemNumber) + ". " + thisItem.name + " - " + thisItem.description << endl;
				itemNumber++;
			}
			cout << endl;
		} else if(action == "examine"){
			string requestedItem;
			cout << "What item would you like to examine?" << endl;
			cin >> requestedItem;
			bool found = false;
			for(item thisItem : player.inventory){
				found = true;
				if(thisItem.name == requestedItem){
					cout << "\n Item details" << endl;
					cout << "==============" << endl;
					cout << "Name: " + thisItem.name << endl;
					cout << "Description: " + thisItem.description << endl;
					cout << "Attack Damage: " + to_string(thisItem.attackDamage) << endl;
					cout << endl;
					break;
				}
			}
			if(!found){
				cout << "You do not have that item." << endl;
			}
		} else if(action == "attack"){
			string requestedEnemy;
			cout << "What do you want to attack?" << endl;
			cin >> requestedEnemy;
			int enemyIndex = 0;
			bool found = false;
			for(enemy &thisEnemy : player.location->enemies){
				if(thisEnemy.name == requestedEnemy){
					found = true;
					string requestedItem;
					cout << "What do you want to attack it with?" << endl;
					cin >> requestedItem;
					bool found = false;
					for(item &thisItem : player.inventory){
						if(thisItem.name == requestedItem){
							found = true;
							thisEnemy.health = thisEnemy.health - thisItem.attackDamage;
							cout << "You did " + to_string(thisItem.attackDamage) + " damage." << endl;
							cout << "The " + thisEnemy.name + " now has " + to_string(thisEnemy.health) + " health." << endl;
							if(thisEnemy.health == 0 || thisEnemy.health < 0){
								cout << "You have slain the " + thisEnemy.name + "!" << endl;
								for(item drop : thisEnemy.inventory){
									player.location->items.push_back(drop);
								}
								player.location->enemies.erase(player.location->enemies.begin() + enemyIndex);
							} else {
								cout << "The " + thisEnemy.name + " attacks you!" << endl;
								cout << "You took " + to_string(thisEnemy.weapon.attackDamage) + " damage.";
								player.health = player.health - thisEnemy.weapon.attackDamage;
								cout << "You now have " + to_string(player.health) + " health." << endl;
							}
						}
					}
					if(!found){
						cout << "You do not have that item." << endl;
					}
				}
				enemyIndex++;
			}
			if(!found){
				cout << "That enemy could not be found." << endl;
			}
		}
	}
	return 0;
}