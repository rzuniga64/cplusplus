/*
 * 	Purpose: This program calculates the average of a group of test scores, where the lowest
 * 			 score in the group is dropped.
 * 	Input: 	 A set of five test scores input from the user
 * 	Output:	 The lowest score of the all the test scores is dropped and then
 * 			 the average of the remaining scores is calculated in displayed.
 *
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Global constants
const int NUMSCORES = 4;

// Function prototypes
void getScore(int &);
int calcAverage(int, int, int, int, int);
int findLowest(int, int, int, int, int);

int main()
{
	int score1 = 0, score2 = 0, score3 = 0, score4 = 0, score5 = 0;
	int average = 0;

	cout << "Please enter five scores" << endl;
	getScore(score1);
	getScore(score2);
	getScore(score3);
	getScore(score4);
	getScore(score5);

	average = calcAverage(score1, score2, score3, score4, score5);
	cout << "The average of the four highest scores is: " << average << endl;

	return 0;
}

/*
 *	Purpose: Ask the user for a test score and validate it is between 0 and 100.
 *	Input: A test score which is of type int.
 *	Output: Store the score in a reference parameter variable if it is valid.
 *	        Otherwise print an error message and ask the user to input a valid number.
 */

void getScore(int &score)
{
	static int count = 0;
	int temp;
	cout << "Enter test score #" << ++count << " between 0 and 100 inclusive: ";
	cin >> temp;
	while (temp < 0 || temp > 100 )
	{
		cout << "You entered an invalid score. Please enter a score between 0 and 100 inclusive: ";
		cin >> temp;
	}
	score = temp;
}

 /*
  *	Purpose: Calculate and display the average of the four highest scores.
  *	Input: Five scores of type int.
  *	Output: An integer which is the average of the four high highest scores.
  */

int calcAverage(int score1, int score2, int score3, int score4, int score5)
{
	int average = 0;
	int lowestScore = findLowest(score1, score2, score3, score4, score5);

	if (lowestScore == score1 )
		average = (score2 + score3 + score4 + score5)/NUMSCORES;
	else if (lowestScore == score2)
		average = (score1 + score3 + score4 + score5)/NUMSCORES;
	else if (lowestScore == score3)
		average = (score1 + score2 + score4 + score5)/NUMSCORES;
	else if (lowestScore == score4)
		average = (score1 + score2 + score3 + score5)/NUMSCORES;
	else if (lowestScore == score5)
		average = (score1 + score2 + score3 + score4)/NUMSCORES;

	return average;
}

/*
 * Purpose: Find and return the lowest of five scores passed to it which are of type int.
 * Input: five scores each of type int.
 * Output: An int which is the lowest of the five scores
 */

int findLowest(int score1, int score2, int score3, int score4, int score5)
{
	int lowestScore = score1;
	lowestScore = score2 < lowestScore ? score2 : lowestScore;
	lowestScore = score3 < lowestScore ? score3 : lowestScore;
	lowestScore = score4 < lowestScore ? score4 : lowestScore;
	lowestScore = score5 < lowestScore ? score5 : lowestScore;

	return lowestScore;
}

