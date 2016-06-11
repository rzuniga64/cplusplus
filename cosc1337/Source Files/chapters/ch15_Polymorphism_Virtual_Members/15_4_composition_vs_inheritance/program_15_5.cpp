 // This program demonstrates the is-a
 // relation in inheritance.
 #include <iostream>
 using namespace std;

 // Base class
 class Dog
 {
 protected:
	 double weight;
 public:
	 Dog(double w)
 	 { weight = w; }
	 virtual void bark( ) const {
		 cout << "I am a dog weighing "
		      << weight << " pounds." << endl;
	 }
 };

 // A SheepDog is a special type of Dog
 class SheepDog:public Dog
 {
	 int numberSheep;
 public:
	 SheepDog(double w, int nSheep) : Dog(w) {
		 numberSheep = nSheep;
	 }
 virtual void bark( ) const {
	 cout << "I am a sheep dog weighing "
	      << weight << " pounds \n and guarding "
	      << numberSheep << " sheep." << endl;
	 }
 };

 int main( )
 {
	 // Create an array of dogs
	 const int NUM_DOGS = 3;
	 Dog *kennel[ ] = { new Dog(40.5), new SheepDog(45.3, 50), new Dog(24.7) };

	 // Walk by each kennel and make the dog bark
	 for (int k = 0; k < NUM_DOGS; k++)
	 {
		 cout << k+1 << ": ";
		 kennel[k]->bark( );
	 }

	 return 0;
 }
