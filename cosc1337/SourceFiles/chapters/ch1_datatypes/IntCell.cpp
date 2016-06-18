#include <iostream>
using namespace std;

/**
 * IntCell
 * A class in C++ is similar to a structure. A class contains:
 * - variables (members) AND
 * - functions (member functions or methods)
 *
 * 1. Default parameter: This constructor has an optional parameter. If no argument is specified, initialValue will be 0.
 * 2. Constant member function; const after param-list declares function will not change any member values signifies
 *    function is an accessor (not a mutator)
 * 3. Initializer list
 *    - placed before the constructor body,
 *    - assigns the value of the parameter initialValue to storedValue.
 *    - if storedValue is an object, uses its one-argument constructor to initialize storedValue.
 * 4. “explicit” constructor
 * - applies to one-argument constructors only
 * - Prevents compiler from doing this implicit conversion:
 *
 * The BIG THREE: copy constructor, destructor, and operator=
 * DESTRUCTOR
 * - called when object is destroyed (goes out of scope or deleted, explicitly deallocated)
 * - responsible for freeing resources used by object
 *
 * COPY CONSTRUCTOR
 * - Special constructor, constructs new object from existing one.
 * Called
 * - for a declaration with initialization
 * - when object is passed by value
 * - when object is returned (by value)
 * default copy constructor
 * - uses assignment for prmititve-type data members
 * - uses copy constructor for object-type data memebers
 *
 * OPERATOR=
 * - called when = operator is used on existing object:
 * - default operator = applies = to each member (aka member-wise assignment)
 *
 * When do the defaults not work?  Generally, when oe of the members is dyanamically allocated by the class
 * (via a pointer)
 *
 * Why are they all changed to 4?
 * - Default copy constructor and operator= do a shallow copy.  They coy the pointer instead of what the pointer points
 *   t0. As a result, all 3 objects point to the same memory location.
 */

class IntCell
{
private:
    // member variables
    int storedValue;
public:
    // explicit constructor with default parameter and initializer list
    explicit IntCell (int initialValue = 0)
    : storedValue (initialValue){ }

    //function
    int read () const { return storedValue; }
    void write (int x) { storedValue = x; }
};

int main() {

    IntCell obj;
    IntCell temp(37);
    obj = temp;

    IntCell a(2);
    IntCell b = a; // copy constructor
    IntCell c;
    c = b; //operator=
    a.write(4);
    cout << a.read() << endl;
    cout << b.read() << endl;
    cout << c.read() << endl;

    // Output 4 4 4 is wrong!
	return 0;
}