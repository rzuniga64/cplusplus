#include "MathTutor.h"
#include <cstdlib>

using namespace std;

MathTutor::MathTutor(int maxOperand, string operatorsToTest, 
					 double targetPercentCorrect) {
	ops = operatorsToTest;
	maxNum = maxOperand;
	target = targetPercentCorrect;
	numDrills = 0;
	numCorrect = 0;
}

void MathTutor::doDrill() {
	int answer = displayDrill();
	readAnswer(answer);
}

int MathTutor::displayDrill() {
	int num1 = rand()%maxNum+1;
	int num2 = rand()%maxNum+1;
	char op = ops[rand()%ops.length()];
	int answer = 0;
	bool error = false;
	switch(op) {
    	case '+':
    		answer = num1 + num2;
    		break;
    	case '-':
    		answer = num1 - num2;
    		break;
    	case '*':
    		answer = num1 * num2;
    		break;
    	case '/':
    		answer = num1 / num2;
    		break;
    	case '%':
    		answer = num1 % num2;
    		break;
    	default:
            cout << "Unknown operator: " << op << endl;
            error = true;
	}
	if (!error)
    	cout << num1 << " " << op << " " << num2 << "? ";
	return answer;
}

void MathTutor::readAnswer(int answer) {
	int guess;
	cin >> guess;
	numDrills++;
	if (guess == answer)
		numCorrect++;
}

bool MathTutor::getDrillResults() {
	if (numDrills == 0)
		return false;
	double percentCorrect = static_cast<double>(numCorrect) / numDrills;
	bool metGoal = false;
	if (percentCorrect >= target) {
		cout << "Congratulations!  You got " << percentCorrect*100;
		cout << "% correct and met your goal." << endl;
		metGoal = true;
	}
	else {
		cout << "I'm sorry, your goal was " << target*100;
		cout << "%, and you only got " << percentCorrect*100;
		cout << "% correct." << endl;
		cout << "Try again..." << endl;
	}
	numDrills = 0;
	numCorrect = 0;
	return metGoal;
}
