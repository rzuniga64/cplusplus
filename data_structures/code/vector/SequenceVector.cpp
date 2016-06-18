#include <vector>
#include <iostream>

using namespace std;

/**
 *  Some vector member functions
 *  size(): returns number of elements in the vector.
 *  push_back(x): inserts x at end of vector (increases size by 1)
 *  pop_back(): removes the last element from the vector (decreases size by 1)
 *  operator[i]: allows random access to specific element (i must be less than the size of the vector).
 *  begin(): returns an iterator pointing to the vector’s first element.
 *  end (): returns an iterator pointing to the vector’s pastthe- end element.
 *
 *  Vector member function using iterator
 *  erase(iter): Removes from the vector either the single element the iterator argument is referring to.
 *  erase reduces the vector size by 1.
 */

int main() {
    int count; // Loop counter
    // Define a vector of int object
    vector<int> vect;
    // Defines an   iterator object
    vector<int>::iterator iter;
    for (count = 0; count < 10; count++)
        vect.push_back(count);

    cout<<"Here are the values in vect: "<< endl;
    for (iter = vect.begin(); iter < vect.end();
         iter++) {
        cout << *iter << " ";
    }

    // Step the iterator thru the vector backwards.
    cout << "\nand here they are backwards: " << endl;
    for (iter = vect.end() - 1; iter >= vect.begin(); iter--) {
        cout << *iter << " ";
    }

    vector<int> myvector;
    // set some values (from 1 to 10)
    for (int i=1; i<=10; i++)
        // erase the 6th element
        myvector.push_back(i);
    //advances 5 times
    myvector.erase (myvector.begin()+5);

    cout << "\nmyvector contains:";
    for (int i=0; i<myvector.size(); i++)
        cout << ' ' << myvector[i];
    cout << endl;
}