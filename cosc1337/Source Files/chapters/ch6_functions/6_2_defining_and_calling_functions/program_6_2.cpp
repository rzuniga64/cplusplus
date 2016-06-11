// The function displayMessage is repeatedly called from within a loop.
 #include <iostream>
 using namespace std;

 /***************************************
 * displayMessage *
 * This function displays a greeting. *
 ***************************************/
 void displayMessage()
 {
 cout << "Hello from the function displayMessage.\n";
 }
 /***************************************
 * main *
 ***************************************/
 int main()
 {
 cout << "Hello from main.\n";

 for (int count = 0; count < 3; count++)
 displayMessage(); // Call displayMessage

 cout << "Back in function main again.\n";
 return
}
