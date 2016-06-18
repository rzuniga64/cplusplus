package java_lessons.lesson2_classes;

using namespace std;

/**
 * ClassIntCell
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
 * };
 */

class ClassIntCell
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
}

int main() {

    ClassIntCell obj;
    ClassIntCell temp(37);
    obj = temp;

	return 0;
}