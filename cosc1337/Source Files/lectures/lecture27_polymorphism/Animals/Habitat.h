#include <iostream>

using namespace std;

enum HabitatType {INVALID = -1, FOREST, OCEAN, RIVER, DESERT, PLAINS, POLAR, TV_SHOW};

class Habitat {
public:
	Habitat();
	Habitat(HabitatType t);
	friend ostream & operator<<(ostream & out, const Habitat & h);
private:
	HabitatType type;
};
