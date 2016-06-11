#ifndef ANIMALS_H
#define ANIMALS_H

#include <iostream>
#include <string>
#include "Habitat.h"

using namespace std;

class Animal {
 public:
	Animal(string name, string type, Habitat habitat);
	string getName() const;
	void speak(ostream & out = cout) const;
	virtual void move() const {};
 protected:
	string name;
	string type;
	Habitat habitat;
};

class Bird : public Animal {
 public:
	Bird(string name, Habitat habitat);
	void speak(ostream & out = cout) const;
	void move() const {cout << "flap flap" << endl;}
};

class Penguin : public Bird {
public:
	Penguin(string name);
	void move() const {cout << "waddle waddle" << endl;}
};

class Fish : public Animal {
public:
	Fish(string name);
	void move() const {cout << "splish splash" << endl;}
};

ostream & operator<<(ostream & out, const Animal & a);

#endif

