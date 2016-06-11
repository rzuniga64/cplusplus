#include "Animals.h"

void makeAnimalMove(Animal & a) {
	a.move();
}

int main() {
	//Animal a("animal", "muppet", TV_SHOW);
	//makeAnimalMove(a);

	Bird b("tweetie", FOREST);
	//b.speak();
	makeAnimalMove(b);
	
	Penguin p("pengo");
	//p.speak();
	makeAnimalMove(p);
	
	Fish f("nemo");
	//f.speak();
	makeAnimalMove(f);
	
	return 0;
}
