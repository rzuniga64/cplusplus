#include "Animals.h"

ostream & operator<<(ostream & out, const Animal & a) {
	a.speak(out);
	return out;
}

Animal::Animal(string name, string type, Habitat habitat) {
	this->habitat = habitat;
	this->name = name;
	this->type = type;
}

string Animal::getName() const {
	return name;
}

void Animal::speak(ostream & out) const {
	out << "Hello, my name is " << name;
	out << ", I am a(n) " << type;
	out << " and I live in " << habitat;
	out << "." << endl;
}

Bird::Bird(string name, Habitat habitat) :
Animal(name, "bird", habitat) {
}

void Bird::speak(ostream & out) const {
	Animal::speak();
	out << "tweet tweet!" << endl;
}

Penguin::Penguin(string name) :
Bird(name, POLAR) {
}

Fish::Fish(string name) :
Animal(name, "fish", OCEAN) {
}
