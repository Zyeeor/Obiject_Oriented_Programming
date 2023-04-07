/* ================================ */
/* == By Meng QingJia 3200102825 == */
/* ================================ */

#include <string>
#include <vector>

/*class path that defines a path type with name and the target it leads to.*/
class Path{
	private:
	std::string name;
	int target;

	public:
	Path(std::string name, int target){
		this->name = name;
		this->target = target;
	}
	std::string Name(){
		return this->name;
	}
	int Target(){
		return this->target;
	}
};

// class Chamber defines a room type that has different paths.
class Chamber{
	private:
	std::string name;
	std::vector<Path> paths;
	bool isPrincess = false;
	bool isMonster = false;

	public:

	bool Death(){
		return isMonster;
	}

	bool secure(){
		return isPrincess;
	}

	// Called when player reached the princess room.
	void tobePrincess(){
		this->isPrincess = true;
	}

	// Called when player reached the princess room.
	void tobeMonster(){
		this->isMonster = true;
	}

	// Take no refs. Give out Paths' names. 
	std::vector<std::string> showPaths(){
		std::vector<std::string> ret;
		for(auto p: this->paths) ret.push_back(p.Name());
		return ret;
	}

	// Take no refs. Give out rooms' names.
	std::string Name(){
		return this->name;
	}

	// Take a ref with string type. Reset the name of the room.
	void Name(std::string name){
		this->name = name;
	}

	// Take a ref with string type. Return the target of a path with specific name.
	int find(std::string name){
        int i = 0;
        bool find = false;
        for (; i < paths.size(); i++) {
            if (paths[i].Name() == name) {
              	find = true;
			  	break;
            }
        }
        if (find) {
            return paths[i].Target();
        } else {
            return -1;
        }
    }
	
	// Take 2 refs with string and integer type. Add a path with specific name and target room to current room.
	void AddPath(std::string name, int target){
		this->paths.push_back(Path(name, target));
	}
	
	// Take no refs. Clear a Chamber instance when called.
	void Reset(){
		this->name = "";
		this->paths.clear();
		isMonster = false;
		isPrincess = false;
	}

	/*=====================================*/
	/*========== Types of rooms ===========*/
	void CellCorridor(int east, int west, int up, int south){
		Name("Cell Corridor");
		AddPath("east", east);
		AddPath("west", west);
		AddPath("up", up);
		AddPath("south", south);
	}

	void Lobby(int west, int east, int down) {
    	Name("Lobby");
    	AddPath("west", west);
    	AddPath("east", east);
    	AddPath("down", down);
  	}

	void Corridor(int west, int east){
		Name("Corridor");
		AddPath("west", west);
		AddPath("east", east);
	}

	void CollectionRoom(int west, int down){
		Name("Collection Room");
		AddPath("west", west);
		AddPath("down", down);
	}

	void Cellar(int up, int west){
		Name("Cellar");
		AddPath("up", up);
		AddPath("west", west);
	}

	void Cell(int north) {
		Name("Cell");
		AddPath("north", north);
	}

	void ExecutionRoom(int east) {
		Name("Execution Room");
		AddPath("east", east);
	}

	void DungeonEntrance(int east, int down){
		Name("Dungeon Entrance");
		AddPath("east", east);
		AddPath("down", down);
	}
	/*=====================================*/
};

#pragma once