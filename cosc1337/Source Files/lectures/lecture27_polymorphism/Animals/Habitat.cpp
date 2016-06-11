#include "Habitat.h"

Habitat::Habitat() {
	type = INVALID;
}

Habitat::Habitat(HabitatType t) {
	type = t;
}

ostream & operator<<(ostream & out, const Habitat & h) {
	switch(h.type) {
		case FOREST:
			out << "a forest";
			break;
		case OCEAN:
			out << "the ocean";
			break;
		case RIVER: 
			out << "a river";
			break;
		case DESERT:
			out << "a desert";
			break;
		case PLAINS:
			out << "the plains";
			break;
		case POLAR:
			out << "a very cold place";
			break;
		case TV_SHOW:
			out << "the TV";
			break;
		default:
			out << "invalid habitat";
	}
	return out;
}
