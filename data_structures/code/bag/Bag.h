#include <cstddef> // needed for NULL

class Bag {
	static const int INCREMENT = 20;
private:
	// concrete representation, implementation dependent
	int *data;		// pointer to bag array
	int capacity;	// size of the array
	int count;		// number of elemenets currently in array

public:
	//***********************************************************
	// Bag: default constructor
	// Preconditions: None.
	// Postconditions: bag is empty
	Bag();

	//***********************************************************
	// Bag: Copy constructor
	// Preconditions: None.
	// Postconditions: Contents of another bag is copied to this Bag
	Bag(const Bag &);

	//***********************************************************
	// Bag: destructor
	// Preconditions: None.
	// Postconditions: Contents of bag is deallocated
	~Bag();

    //***********************************************************
    // isEmpty():
    // Preconditions: none.
    // Postconditions: True if the bag is empty, false otherwise.

    void isEmpty(int element);

    //***********************************************************
	// add:
	// Preconditions: Bag is not full.
	// Postconditions: The item has been added to the bag and 
	//   the count is increased by one..
	void add(int element);

    //***********************************************************
	// remove:
	// Preconditions: none
	// Postconditions: The item  is removed from the bag and 
	//   the count is decreased by one.
	void remove(int element);

    //***********************************************************
	// occurrences(x):
	// Preconditions: none.
	// Postconditions: How many times is x in the bag.
	int occurrences(int element) const;

    //***********************************************************
	// isEmpty:
	// Preconditions: none
	// Postconditions: is the Bag empty
	bool isEmpty() const;

    //***********************************************************
	// size:
	// Preconditions: none.
	// Postconditions: returns the number of elements.
	int size() const;

    //***********************************************************
	// operator=:
	// Preconditions: none.
	// Postconditions: assigns the values of another bag to this bag.
	void operator=(int element);
};