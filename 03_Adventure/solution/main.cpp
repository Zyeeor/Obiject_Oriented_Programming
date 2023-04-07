/* ================================ */
/* == By Meng QingJia 3200102825 == */
/* ================================ */
#include "Chamber.hpp"
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <random>

// The function used to initialize the rooms and randomly set a monster room and a princess room.
std::vector<Chamber> Initialize();

// The main game play loops function.
void Play(std::vector<Chamber>& rooms);

int main(){
	std::vector<Chamber> rooms = Initialize();
	Play(rooms);
}

std::vector<Chamber> Initialize() {
	std::vector<Chamber> Maze;
	Chamber current;

	/* ================================================== */
	/* ============ Initialize the game map. ============ */
	// Room 0;
	current.Reset();
	current.Lobby(2, 3, 1);
	Maze.push_back(current);

	// Room 1;
	current.Reset();
	current.CellCorridor(5, 6, 0, 8);
	Maze.push_back(current);

	// Room 2;
	current.Reset();
	current.DungeonEntrance(0, 6);
	Maze.push_back(current);

	// Room 3;
	current.Reset();
	current.Corridor(0, 4);
	Maze.push_back(current);

	// Room 4;
	current.Reset();
	current.CollectionRoom(3, 5);
	Maze.push_back(current);

	// Room 5;
	current.Reset();
	current.Cellar(4, 1);
	Maze.push_back(current);

	// Room 6;
	current.Reset();
	current.CellCorridor(1, 9, 2, 7);
	Maze.push_back(current);

	// Room 7;
	current.Reset();
	current.Cell(6);
	Maze.push_back(current);

	// Room 8;
	current.Reset();
	current.Cell(1);
	Maze.push_back(current);

	// Room 9;
	current.Reset();
	current.ExecutionRoom(6);
	Maze.push_back(current);

	/* ================================================== */

	/* Randomly select the princess room and the monster room. */
	std::random_device rand;
	std::mt19937 gen(rand());
	std::uniform_int_distribution<int> dis(1, 9);
	int princess = dis(gen);
	int monster = princess;
	while(monster == princess) monster = dis(gen);
	Maze[princess].tobePrincess();
	Maze[monster].tobeMonster();
	/* ====================================================== */

	return Maze;
}

void Play(std::vector<Chamber>& rooms){
	
	// Begin from room 0, also the Lobby.
	Chamber current = rooms[0];
	// When princess is found, toEscape will be set true.
	bool toEscape = false;
	while(1){
		// Clear the terminal.
		std::cout << "\033c";
		
		std::cout << "Welcome to " << current.Name() << "! There are " \
		<< current.showPaths().size() << " exits: ";
		for(int i = 0; i < current.showPaths().size(); i++)
			std::cout << " "<< current.showPaths()[i] << ",";
		std::cout << std::endl;

		// If find the princess room.
		if(current.secure()){
			std::cout << "You find the princess! Escape!" << std::endl;
			toEscape = true;
		}

		// If secured the princess and return to the entrance.
		if(toEscape && current.Name() == "Lobby"){
			std::cout << "You Win!!!!" << std::endl;
			std::cin.ignore();
			break;
		}

		// If get into the monster's room.
		if(current.Death()){
			std::cout << "The Monster is here! Game Over! You LOSE!" << std::endl;
			std::cin.ignore();
			break;
		}


		std::cout << "Enter your command" << std::endl;

		std::string go, command;

		// Input loop till commands are input correctly.
		while(1){
			std::cin >> go >> command;
        	if (go != "go"){
            	std::cout << "Wrong Command!" << std::endl;
				continue;
			}else if (current.find(command) == -1){
				std::cout << "No such direction!" << std::endl;
				continue;
			}else{
				break;
			}
    	}

		// Reset the current.
		current = rooms[current.find(command)];
	}
}