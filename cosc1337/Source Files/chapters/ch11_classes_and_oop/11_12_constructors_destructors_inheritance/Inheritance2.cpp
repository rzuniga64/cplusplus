 #include "inheritance2.h"
 //*********************************************
 // Constructor for the Student class. *
 //*********************************************
 Student::Student(string sname, Discipline d, Person *adv)
 : Person(sname) // Base constructor initialization
 {
	 major = d;
	 advisor = adv;
 }
