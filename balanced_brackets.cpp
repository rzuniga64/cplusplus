//*****************************************************************************
//
//	Assignment:		Lab 3
//	File:			lab3.cpp
//	Author:			Raul Zuniga
//	Description:	A C++ program that will check for balanced brackets in
//					a C++ program.
// Contraints:		1. Accept the name of the .C file being checked as a
//					   command-line argument.
//					2. Conclude whether all delimeters are properly matched, or
//					3. Conclude that an error occurs (report the line
//					   number on which the mismatch occurs.)
//					
//					The delimeters being considered are:
//	
//					1. { and } begin-end brackets used for blocks of code.
//
//*****************************************************************************
#include <iostream>
#include <fstream>

using namespace std; 	//introduces namespace std

int main()
{
	char ch, previous_ch = 'a', current_ch='a';

	int line_number 				= 1;		//current line number
	int single_quote_flag 			= 0;		//flag to check for '{}'
	int double_quote_flag 			= 0;		//flag to check for "{}"
	int c_comment_flag 				= 0;		//flag to check for /*{}*/
	int cpp_comment_flag 			= 0;		//flag to check for //{}
	int open_brace_count			= 0;		//counts # of open braces
	int close_brace_mismatch_count	= 0;		//counts # of close braces not properly matched
	int total_error 				= 0;		//total number of open/close brace errors
	int line_count_array[100];					//keeps track of line numbers for open braces
	
	//read the test file

	ifstream  infile( "balanced_brackets.cpp", ios::in);
	if (!infile)  {cerr << "File could not be opened" << endl; exit (-1);};	
	
	while ( (ch = infile.get())!=EOF)								//while not end-of-file
		{	
			if ((ch == '\'')&&( single_quote_flag == 0))			//check for '{', '}','{}'
				single_quote_flag = 1;		
			else
				if (ch == '\'') single_quote_flag = 0;
			
			if ((ch == '\"')&&( double_quote_flag == 0))			//check for "{", "}","{}"
				double_quote_flag = 1;
			else
				if (ch == '\"') double_quote_flag = 0;		
					
			previous_ch = current_ch;
			current_ch = ch;
			
			if ((previous_ch == '/')&&(current_ch == '*'))			//check for braces in comments
				c_comment_flag = 1;
			else
			  if ((previous_ch == '*')&&(current_ch == '/'))
				  c_comment_flag = 0;
			
			if ((previous_ch == '/')&&(current_ch == '/'))			//check for braces in comment
				cpp_comment_flag = 1;
				
			if (ch == '\n') {line_number++; cpp_comment_flag = 0;}; //check for end-of-line
																	//signals end of cpp comment
																	
			//check if any of the quote flags or comment flags are set.  If they are go to next character.
							
			if ((single_quote_flag || double_quote_flag || c_comment_flag || cpp_comment_flag) == 1)
				continue;
				
			//check for open/close brace mismatch at this point.
							
			if (ch == '{')
			{			
				line_count_array[open_brace_count] = line_number;
				open_brace_count++;				
			}	
			//check for close brace mismatch errors.

			if (ch == '}')							
			{
				if (open_brace_count == 0) 
				{
					close_brace_mismatch_count++;
					cout << "Close brace mismatch error at line " << line_number << "\n";	
				}
				else open_brace_count--;   
			}
		}

		//check for open brace mismatch errors.

		if (open_brace_count != 0)
		{	
			for (int i=0; i<open_brace_count; i++)
				cout << "Open brace mismatch error at line " << line_count_array[i] << "\n";
		}
		
		//check if all delimiters are properly matched.

		total_error = close_brace_mismatch_count + open_brace_count;
		if (total_error == 0) cout << "All delimiters are properly matched!";
	
return 0;
}
