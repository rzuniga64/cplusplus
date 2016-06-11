//************************************************************************
//
//	Assignment:		Lab 5
//	File:			lab5.c
//	Author:			Raul Zuniga
//	Description:	A program that reads a student record from an input 
//					file into a table of student data structures until an
//					eof is encountered.  The student data structure consists
//					of
//					Last_name
//					First_name
//					Social_Security
//					Exams[4]
//					Average
//					Letter_Grade
//					
//					The program then computes the grade average and assigns
//					a letter grade for each student, computes the average
//					score for each exam, and stores the information to an
//					output file.
// Contraints:		main() will consist of variable declarations followed 
//					by a sequence of functions called. 
//
//************************************************************************

#include <fstream>
#include <iostream>
#include <iomanip>
#include "student.h"

using namespace std; 	//introduces namespace std

int load_student_info( char *filename, struct student *headlist, int size );
void compute_student_average( struct student *list, int numberOfElements, int *student_Average, char *grade_Average, int numberOfExams );
void compute_classExam_average(struct student *list, int numberOfElements, int *class_Average, int numberOfExams);
char assign_letter_grade( int averageScore );
void store_student_info(char *filename, struct student *list, int numberOfElements, int *class_Average, int *student_Average, char *grade_Average, int numberOfExams);
#define MAXNAME 20
#define MAXTEST 4

int main()
{
	#define MAXTEST 4
	#define MAXLIST 50
	
	int class_avg[MAXTEST]={0};
	int student_avg[MAXLIST]={0};
	char grade_avg[MAXLIST]={""};
	struct student list[MAXLIST];
	int classSize;
		
	classSize = load_student_info( "student.dat", list, MAXLIST );
	compute_student_average( list, classSize, student_avg, grade_avg, MAXTEST ); 
	compute_classExam_average( list, classSize, class_avg, MAXTEST );
	store_student_info( "student.txt", list, classSize, class_avg, student_avg, grade_avg, MAXTEST ); 
	
	return 0;
}

int load_student_info( char * filename, struct student * list, int size )
{
	struct student *ptr = list;
	int count = 0;
	
	
	ifstream infile( filename, ios::in);
	if (!infile)  {cerr << "Input file could not be opened" << endl;};
	while (!infile.eof())
	{
		infile >> ptr -> last
		       >> ptr -> first
		       >> ptr -> ssn;
		       
		for (int i=0; i < MAXTEST; i++ )
			infile >> ptr -> exam[i];
		count ++;
		ptr++;
		if ( ptr-list > size )
			break;
	}

	return count;
}

void compute_student_average( struct student *list, int numberOfElements, int *student_Average, char *grade_Average, int numberOfExams )
{
	struct student *ptr = list;
	int sumOfExams[MAXLIST]={0}; 
	
	for ( int i=0; i < numberOfElements; i++ )
	{
		for (int j=0; j < numberOfExams; j++ )
		{
			sumOfExams[i] += ptr -> exam[j];
			*(student_Average + i) = sumOfExams[i]/numberOfExams;
			*(grade_Average + i) = assign_letter_grade( *(student_Average + i ) );
		}
		ptr++;
	}

}

void compute_classExam_average(struct student *list, int numberOfElements, int *class_Average, int numberOfExams)
{
	struct student *ptr = list;
	int sumOfExams[MAXTEST]={0};
	
	for ( int i=0; i < numberOfElements; i++ )
	{
		for ( int j=0; j<numberOfExams; j++ )
			sumOfExams[j] += ptr -> exam[j];
	
		ptr++;
	} 
	
	for (int k=0; k<numberOfExams; k++)
	{
		*(class_Average+k) = sumOfExams[k]/numberOfElements;
	}
		
}

char assign_letter_grade( int averageScore )
{
	char letterGrade;
	
	if ( averageScore > 90 ) letterGrade = 'A';
	if ( averageScore >80 && averageScore < 89 ) letterGrade = 'B';
	if ( averageScore >70 && averageScore < 79 ) letterGrade = 'C';
	if ( averageScore >60 && averageScore < 69 ) letterGrade = 'D';
	if ( averageScore < 60 ) letterGrade = 'F';
	
	return letterGrade;
}
	
	
void store_student_info(char *filename, struct student *list, int numberOfElements, int *class_Average, int *student_Average, char *grade_Average, int numberOfExams)
{
	struct student * ptr = list;
	
	ofstream outfile( filename, ios::out);
	if (!outfile)  {cerr << "Output file could not be opened" << endl;};

	for (int i=0; i < numberOfElements; i++)
	{
		outfile << ptr-> last 	<< "\t";
		outfile << ptr -> first << "\t";
		outfile << ptr -> ssn 	<< "\t";
		       
		for (int i=0; i < MAXTEST; i++ )
			outfile << ptr -> exam[i] << " ";
			
		outfile << "\t" <<*(grade_Average + i) << "\t";
		outfile << *(student_Average + i) << "\n";
		ptr++;
	}
	
	outfile << "Class Exam Averages:" <<"\t\t";
	for ( int j =0; j < numberOfExams; j++ )
		outfile << *( class_Average + j ) << setw(3);
}
