#include <fstream>
#include <vector>
#include <string>
#include "Contestant.h"

int abs(int v);
//int getClosest(int * nums, int size, int target);
int getClosest(vector<Contestant> nums, int target);

int main() {

	vector<Contestant> contestants;
	int index;
	int actualNumberOfJellyBeans;

    ifstream inFile("guesses.txt");
    string first, last;
    int guess;
    
    if (inFile) {
        getline(inFile, last, '#');
        while(inFile) {
            getline(inFile, first, '#');
            inFile >> guess;
            inFile.ignore(); // ignore newline left by extraction operator
            cout << first << " " << last << " guessed " << guess << endl;
			Contestant contestant(first, last, guess);
			contestants.push_back(contestant);
            getline(inFile, last, '#');
        }
    }
    else
        cout << "Error opening guesses file.  Talk to Sarah." << endl;

// Verify vector contents
//	cout << endl;
//	for (int i = 0; i < contestants.size(); i++)
//		contestants[i].display();

	index = getClosest(contestants, 1400);
	cout << "\nThe person with the closest guess is: "; 
	contestants[index].display(); 
	cout << "Who guessed " <<  contestants[index].getGuess() << endl << endl;

	cout << "Enter actual number of jelly beans: ";
	cin >> actualNumberOfJellyBeans;

	index = getClosest(contestants, actualNumberOfJellyBeans);
	cout << "\nThe person with the closest guess is: "; 
	contestants[index].display(); 
	cout << "Who guessed " <<  contestants[index].getGuess();

    return 0;
}

int abs(int v) {
    return (v < 0 ? -v : v);
}

/*
int getClosest(int * nums, int size, int target) {
    int minDist = abs(nums[0]-target);
    int minIdx = 0;
    for (int i=1; i<size; i++) {
        if (abs(nums[i]-target) < minDist) {
            minDist = abs(nums[i]-target);
            minIdx = i;
        }
    }
    return minIdx;
}
*/

int getClosest(vector<Contestant> nums, int target) {
	int minDist = abs(nums[0].getGuess()-target);
    int minIdx = 0;
    for (int i=1; i<nums.size(); i++) {
		if (abs(nums[i].getGuess()-target) < minDist) {
			minDist = abs(nums[i].getGuess()-target);
            minIdx = i;
        }
    }
    return minIdx;
}

