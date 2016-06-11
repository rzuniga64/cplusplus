 //This program demonstrates the use of
 //objects of derived classes.
 #include "inheritance1.h"
 #include <iostream>

 using namespace std;

 // These arrays of string are used to print
 // values of enumerated types
 const string dName[] = {"Archeology", "Biology", "Computer Science"};
 const string cName[] = {"Freshman", "Sophomore", "Junior", "Senior"};

 int main()
 {
	 // Create Faculty and Student objects
	 Faculty prof("Indiana Jones", ARCHEOLOGY);
	 Student st("Sean Bolster", ARCHEOLOGY, &prof);
	 cout << "Professor " << prof.getName() << " teaches "
	      << dName[prof.getDepartment()] << "." << endl;

	 // Get student's advisor
	 Person *pAdvisor = st.getAdvisor();
	 cout << st.getName() <<"\'s advisor is "
	      << pAdvisor->getName() << ".";

	 return 0;
 }
