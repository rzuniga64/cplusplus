#include <vector>
#include <iostream>

using namespace std;

int main() {
	vector<int> number,w(3), v(5,2);

	int s;

	s = number.size();

	for (int i=0; i<10; i++) {
		number.push_back(i/2);
		s = number.size();
	}

	for (int i=0; i<10; i++)
		cout << number[i] << " ";
	cout << endl;

	for (int i=0; i<6; i++)
		w.push_back(i/2);

	s = w.size();
	for (int i=0; i< w.size(); i++)
		cout << w[i] << " ";
	cout << endl;

	return 0;
}
