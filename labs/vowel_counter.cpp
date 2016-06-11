#include <iostream>
#include <fstream>

using namespace std; 	//introduces namespace std

int main()
{
	char ch,previous_ch='a',current_ch='a';
	int a_vowel_count = 0;
	int e_vowel_count = 0;
	int i_vowel_count = 0;
	int o_vowel_count = 0;
	int u_vowel_count = 0;
	int digit_count=0;
	int ucase_letter_count=0;
	int lcase_letter_count=0;
	int if_count=0;
	int blank_space_count=0;
	int line_count=0;
		
	ofstream outfile("vowel_counter.txt",ios::out);
	if (!outfile) {cerr << "File could not be opened" << endl; exit (-1);}
	ifstream  infile("vowel_counter.cpp",ios::in);
	if (!infile)  {cerr << "File could not be opened" << endl; exit (-1);}
	
	while ( (ch =infile.get())!=EOF)
	{
		switch(ch)
		{
			case 'a': a_vowel_count++; lcase_letter_count++; break;
			case 'A': a_vowel_count++; ucase_letter_count++; break;
			case 'e': e_vowel_count++; lcase_letter_count++; break;
			case 'E': e_vowel_count++; ucase_letter_count++; break;
			case 'i': i_vowel_count++; lcase_letter_count++; break;
			case 'I': i_vowel_count++; ucase_letter_count++; break;
			case 'o': o_vowel_count++; lcase_letter_count++; break;
			case 'O': o_vowel_count++; ucase_letter_count++; break;
			case 'u': u_vowel_count++; lcase_letter_count++; break;
			case 'U': u_vowel_count++; ucase_letter_count++; break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': digit_count++; break;
			case 'f': 
			case 'b': 
			case 'c':
			case 'd':	
			case 'g':
			case 'h':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z': lcase_letter_count++; break;
			case 'F':
			case 'B':
			case 'C':
			case 'D':
			case 'G':
			case 'H':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z': ucase_letter_count; break;
			case ' ': blank_space_count++;
			default : break;
		}
		
		previous_ch = current_ch;
		current_ch = ch;
		if ((previous_ch=='i'||previous_ch=='I')&&(current_ch=='f'||current_ch=='F')) if_count++;
	}
	
	outfile << "a vowel count           = " << a_vowel_count << "\n";
	outfile << "e vowel count           = " << e_vowel_count << "\n";
	outfile << "i vowel count           = " << i_vowel_count << "\n";
	outfile << "o vowel count           = " << o_vowel_count << "\n";
	outfile << "u vowel count           = " << u_vowel_count << "\n";
	outfile << "digit count             = " << digit_count   << "\n";
	outfile << "upper case letter count = " << ucase_letter_count << "\n";
	outfile << "lower case letter count = " << lcase_letter_count << "\n";
	outfile << "if count                = " << if_count << "\n";
	outfile << "blank space count       = " << blank_space_count << "\n";
	outfile << "number of lines         = " << line_count << "\n";
	
	return 0;
}
