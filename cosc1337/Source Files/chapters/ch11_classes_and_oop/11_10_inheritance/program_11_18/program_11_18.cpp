 // This program demonstrates the creation and use
 // of objects of derived classes.
 #include <iostream>
 #include "inheritance.h"

 using namespace std;

 // These arrays of string are used to print the
 // enumerated types.
 const string dName[] = {"Archeology", "Biology", "Computer Science"};
 const string cName[] = {"Freshman", "Sophomore", "Junior", "Senior"};

 int main()
 {
	 // Create a Faculty object
	 Faculty prof;

	 // Use a Person member function
	 prof.setName("Indiana Jones");

	 // Use a Faculty member function
	 prof.setDepartment(ARCHEOLOGY);
	 cout << "Professor " << prof.getName()
	      << " teaches in the " << "Department of ";

	 // Get department as an enumerated type
	 Discipline dept = prof.getDepartment();

	 // Print out the department in string form
	 cout << dName[dept] << endl;

	 return 0;
 }
