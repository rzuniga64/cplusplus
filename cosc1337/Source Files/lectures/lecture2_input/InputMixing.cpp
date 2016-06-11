#include <iostream>

using namespace std;

int main() {
	double score = 0.0;
	string name = "";

	cout << "Enter score: ";
	cin >> score;
	cin.ignore();
	cout << "Enter name: ";
	getline(cin, name);

	cout << "Score for " << name << ": ";
	cout << score << endl;

	return 0;
}
