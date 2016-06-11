#include <iostream>

using namespace std;

class MathTutor {
public:
    /* MathTutor constructor
       maxOperand: math problem operands will be 
          between 1 and maxOperand (inclusive)
       operatorsToTest: a string that includes all 
          of the operators to be used in the drills
       targetPercentCorrect: the target percent correct.
          used to determine whether drill results are
          satisfactory (in getDrillResults)
          should be a number b/w 0 and 1: 1.0 is 100%
    */
	MathTutor(int maxOperand, string operatorsToTest, 
			  double targetPercentCorrect);
	/* doDrill function
	   input: none
	   output: none
	   Displays drill, reads answer, records result
    */
	void doDrill();
	/* getDrillResults function
	   input: none
	   output: Boolean indicating whether the target percent 
          correct has been reached
	*/
	bool getDrillResults();
private:
    /* private functions used only internally */
	int displayDrill();
	void readAnswer(int answer);
	string ops; 
	int maxNum;
	double target;
	int numDrills;
	int numCorrect;
};
