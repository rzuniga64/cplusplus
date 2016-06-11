#include "String.h"

String::String() 
{
    charArray = new char[1];
	charArray[0] = '\0';
    size = 0;
}

String::String(char * cstr) 
{
	size = 0;
	while (cstr[size] != '\0')
		size++;
	charArray = new char[size+1];
	for (int i=0; i<=size; i++)
		charArray[i] = cstr[i];
}

// copy constructor removed so you can write it on the lab

String::~String() 
{
	delete[] charArray;
	charArray = NULL;
	size = 0;
}

String & String::operator=(const String & rhs)
{
	if (this != &rhs) 
	{
		delete[] charArray;
		charArray = new char[rhs.size+1];
		size = rhs.size;
		for(int i=0; i<=size; i++)
			charArray[i] = rhs.charArray[i];
	}
	return *this;
}

int String::length() const
{
    return size;
}

void String::display() const
{
    cout << charArray;
}

String & String::erase(int startIndex, int numToErase)
{
	// if the user is trying to erase more character than there are 
	// between the start index and the end of the string, cap the
	// the number to erase
	if (numToErase > size-startIndex) 
		numToErase = (size-startIndex);
	int newSize = size - numToErase;
	char * tempArray = new char[newSize+1];
	for (int i=0; i<startIndex; i++)
		tempArray[i] = charArray[i];
	for (int i=startIndex; i<=newSize; i++)
		tempArray[i] = charArray[i+numToErase];
	size = newSize;
	delete[] charArray;
	charArray = tempArray;
	return *this;
}

String & String::assign(int numChars, char charToRepeat)
{
	if (numChars > size) 
	{
		delete[] charArray;
		charArray = new char[numChars+1];
	}
	size = numChars;
	for (int i=0; i<size; i++)
		charArray[i] = charToRepeat;
	charArray[size] = '\0';
	return *this;
}

ostream & operator<<(ostream & out, const String & s) 
{
	out << s.charArray;
	return out;
}
