//************************************************************************
//
//	Assignment:		Lab 5
//	File:			lab5.c
//	Author:			Raul Zuniga
//	Due Date:		February 28, 2000
//	Description:	Write the following functions:
// 
//	STRCPY	
//	Prototype:		char *STRCPY( char *target, char *source )
//	Description:	Copies string 'source' to 'target', stopping after
//					the terminating null character.
// 	Return Value:	returns target.
//	
//	STRCHR			
//	Prototype:		char *STRCHR( char *str, int c);
//	Description:	Scan a string for the first occurence of a given
//					character.  STRCHR scans a string in the forward
//					direction, looking for a specific character.  STRCHR
//					finds the first occurence of the character c in the
//					string s.
//	Return Value:	A pointer to the first occurence of the character 
//					c in S.  If c does not occur in s, STRCHR returns 
//					null.
//
//	STRSET
//	Prototype:		char *STRSET( char *s, int c);
//	Description:	Sets all the characters in a string to a given character.
//					STRSET sets al characters in the string to the character
//					c.  It quits when the terminating null character is found.
//	Return Value:	returns an s.
//
//	STRCMP
//	Prototype:		int STRCMP( char *s1, char *s2 );
//	Description:	Compares one string to another. Strcmp performs a 
//					comparison of s1 to s2, starting with the first
//					character in each string and continuing with subsequent
//					characters until the corresponding characters differ
//					or until the end of the string is reached.
//	Return Value:	If s1 is ...STRCMP returns a value that is...
//						Less than s2	< 0
//						Same as s2		== 0
//						Greater than s2	> 0
//	
//	STRREV		
//	Prototype:		char *STRREV( char *s )
//	Description:	Reverses a string. STRREV changes all characters in a string
//					to reverse order, except the terminating null character.
//					(For example, it would change string\0 to gnirts\0.)
//	Return Value:	A pointer to the reversed string.
//
//	STRUPR			
//	Prototype:		char *STRUPR
//	Description:	Converts lowercase letters in a string to uppercase. STRUPR
//					converts lowercase letters in a string s to uppercase. The
//					conversion is from lowercase letters (a to z) to uppercase
//					letters(A to Z). No other characters are changed.
// 	Return Value:	returns s.
//
//	STRCAT	
//	Prototype:		char *STRCAT( chat *target, char *source)
//	Description:	Appends one string to another. STRCAT appends a copy
//					of source to the end of target.  The length of the
//					resulting string is strlen(target)+strlen(src).
//	Return Value:	STRCAT returns a pointer to the concateneted string.
//
//	STRSTR			
//	Prototype:		char *STRSTR( char *str, char *pat);
//	Description:	Scans a string for the occurence of a given substring.
//					STRSTR scans s1 for the first occurence of the 
//					substring s2.
//	Return Value:	STRSTR returns a pointer to the element in str, where
//					pat begins ( points to pat in str ). If pat does not occur
//					in str, STRSTR returns null.
//	
//	STRLEN			
//	Prototype:		int STRLEN( char *s );
// 	Description:	Determine the length of a string s.
//	Return Value:	the number of characters in s, not counting the null
//					terminating character.	
//	Contraints:		
//					- Subscripts may not be used.
//					- Arrays may not be used.
//					- Calls to other functions may not be used.
//
//************************************************************************
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std; 	//introduces namespace std

char *STRCPY( char *target, char *source );			//STRCPY prototype
char *STRCHR( char *s, int c);						//STRCHR prototype
char *STRSET( char *s, char c);						//STRSET prototype
int STRCMP( char *target, char *source);			//STRCMP prototype
char *STRREV( char *s );							//STRREV prototype
char *STRUPR( char *s );							//STRUPR prototype
char *STRCAT( char *target, const char *source);	//STRCAT prototype
char *STRSTR( char *str, char *pat);				//STRSTR prototype
int STRLEN ( char *s );								//STRLEN prototype

int main()
{
	char *string1 = "abcdefghijklmnopqrstuvwxyz";
	char *string2 = "Happy * New Year";
	char *string3 = "RoyZuniga";
	char *string4 = "Happy New Year";
	char *string5 = "Happy New Year";
	char *string6 = "Happy Holidays";
	char *string7 = "lowercase";
	char *string8 = "Happy ";
	char *string9 = "New Year";
	char *string10 = "tomato carrot onion";
	char *string11 = "on";
	char x[30];

	ofstream outfile("string_functions.txt",ios::out);
	if (!outfile) {cerr << "File could not be opened" << endl;}

	outfile << "1) STRCPY Example: " << endl
		 	<< "\nThe string in array 'source' is: " << string1
			<< "\nSTRCPY( x, string1 ) = " << STRCPY( x, string1 ) << endl;

	outfile << "\n2) STRCHR Example: " << endl
			<< "\nThe string to be searched is: " << string2
	 		<< "\nThe character to search is: " << '*'
		 	<< "\nSTRCHR( string2, '*') = " << STRCHR( string2, '*' ) << endl;

	outfile << "\n3) STRSET Example: " << endl
		 	<< "\nThe given string is 'Roy Zuniga'" 
		 	<< "\nThe character ch is: " << '&'
			<< "\nSTRSET( string3, '&' ) = " << STRSET( string3,'&') << endl;

	outfile << "\n4) STRCMP Example: "
			<< "\n\ns4 = " << string4 << "\ns5 = " << string5
			<< "\ns6 = " << string6 << "\n\nSTRCMP( s4, s5 ) = "
	   		<< setw ( 2 ) << STRCMP( string4, string5 ) 

			<< "\nSTRCMP( s5, s6 ) = " << setw( 2 )
			<< STRCMP( string5, string6 ) << "\nSTRCMP( s6, s5 ) = "
			<< setw( 2 ) << STRCMP( string6, string5 ) << endl;	
	
	outfile << "\n5) STRREV Example: " << endl
		   	<< "\nThe string to be reversed is 'abcdefghijklmnopqrstuvwxyz'"
		 	<< "\nSTRREV( char *s ) = " << STRREV( string1 ) << endl;

	outfile <<	"\n6) STRUPR Example: " << endl
		 	<< "\nThe given string is 'lowercase'"
		 	<< "\nSTRUPR( string7 ) = " << STRUPR( string7 ) << endl;
		
	outfile	<< "\n7) STRCAT Example: " << endl
	 	 	<< "\ns8 = 'Happy'" << "\ns9 = 'New Year'"
	 	 	<< "\nSTRCAT( s8, s9 ) = " << STRCAT( string8, string9) << endl;
		 
	outfile << "\n8) STRSTR Example: " << endl
	 		<< "\ns10 = " << string10 << "\ns11 = " << string11
	 		<< "\nSTRSTR( s10, s11) = " << STRSTR( string10, string11) << endl;
			 
	outfile << "\n9) STRLEN Example: " << endl		
			<< "\nThe length of \"" << string1 << "\" is " << STRLEN( string1 )<< endl;
			
	return 0;
}

char *STRCPY( char *target, char *source )
{
	char *headTarget = target;
	while ( *target++ = *source++ ) ;		//Looking for 'zero'
	return (headTarget);
}

char *STRCHR( char *s, int c)
{
	char *p = s;
	char chr = c;
	char ch;
	
	while(ch = *p++)
		if (ch == chr )
			return(( char * ) ( p-1 ));
	
	return(c ? 0 : (char *) (p-1));
}

char *STRSET( char *s, char c)
{
	char *headTarget = s;

	while ( *s ) 
	{
		*s = c;	
		*s++;
	}
	return (headTarget);
}

char *STRSTR( char *str, char *pat)
{
	char *s1 = (char * ) str;
	char *p1 = (char * ) pat;
	char firstc, c1, c2;
	
//if pat is a NULL pointer or an empty string return str *
	
	if ((pat == NULL) || (!(firstc = *p1++)))
		return (( char * ) str);
		
	while ( c1 = *s1++ )
		if ( c1 == firstc)
		{
			char * s2 = s1;
			char * p2 = p1;
			
			while (( c1 = *s2++ ) == (c2 = *p2++) && c1) ;
			
			if (!c2)
				return ((char *)s1 - 1);
		}
	return (NULL);

}

int STRCMP( char *target, char *source)
{
	while (*target == *source)				
		if ( *target )						//Compare until *target == NULL
			source++,target++;				//Increment both pointers
		else	
			return 0;
	return( *target - *source );
}

char *STRREV( char *s )
{
	int SmallIndex = 0;
	int BigIndex;
	char *ptr = s;
	
	int count;
	for (count = 0; *ptr != '\0'; ptr++,count++ ) ;
	
	BigIndex = count - 1;

	while (SmallIndex < BigIndex)
	{
		char Temp = s[SmallIndex];
		
		s[SmallIndex] = s[BigIndex];
		s[BigIndex] = Temp;
		
		SmallIndex++;
		BigIndex--;
	}
	return s;
	
}

char *STRUPR( char *s )
{
	char *headTarget = s;
	
	while (( *s )&&( *s > 'a' || *s < 'z' ))
	{
			*s++ = *s -32;
	}
	return headTarget;
}

char *STRCAT( char *target, const char *source)
{
	const char *p = source;
	char *q = target;
	
	while ( *q++ ) ;
	
	q--;
	
	while ( *q++ = *p++ ) ;
	
	return (target);
		
}

int STRLEN( char *s )
{
	int count;
	for (count = 0; *s != '\0'; s++,count++ ) ;

	return count;
		
}
