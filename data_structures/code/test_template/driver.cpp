#include <iostream>
#include <string>
#include "vector.h"

using namespace std;

int main() {

	vector<string> v(2);
	v.push_back("Randy");
	v.push_back("Cinnamon");
	v.push_back("Mau Mau");
	v.push_back("Raul");
	string str = v.operator[](3);
	v.pop_back();

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;

	return 0;
}