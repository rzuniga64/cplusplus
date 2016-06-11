 // This program demonstrates the string class's
 // overloaded [] operator.
 #include <iostream>
 #include <string>
 using namespace std;

 int main()
 {
	 string name = "William";

	 cout << "Here are the letters in your name: \n";
	 for (int x=0; x < name.length(); x++)
		 cout << name[x] << ' ';
	 cout << "\nEnter a character and press Enter: ";
	 cin >> name[2];
	 cout << "Now, here are the letters in your name:\n";
	 for (int x=0; x < name.length(); x++)
		 cout << name[x] << ' ';

	 return 0;
}
