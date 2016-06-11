#include "String.h"

String::String() 
{
    charArray = NULL;
    size = 0;
}

String::String(char * cstr) 
{
    size = 0;
    while(cstr[size] != '\0')
        size++;
    charArray = new char[size+1];
    for (int i=0; i<=size; i++)
        charArray[i] = cstr[i];
}

String::String(const String & str) {
	//copy constructor:
	//1. allocate memory
	//2. copy right hand side's data

	size = 0;
	while(str.charArray[size] != '\0')
		size++;
	charArray = new char[size+1];
	for (int i=0; i <= size; i++)
		charArray[i] = str.charArray[i];
}

String::~String() 
{
    if (charArray) {
        delete[] charArray;
        charArray = NULL;
    }
}

String & String::operator=(const String & other) {
    if (this != &other) {
        if (size != other.size) {
            size = other.size;
            delete[] charArray;
            charArray = new char[size+1];
        }
        for (int i=0; i<=size; i++)
            charArray[i] = other.charArray[i];
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

void String::append(const String & other) {
    char * newArray = new char[size+other.size+1];
    for (int i=0; i<size; i++)
        newArray[i] = charArray[i];
    for (int i=size; i<=size+other.size; i++)
        newArray[i] = other.charArray[i-size];
    delete[] charArray;  
    charArray = newArray;
    size += other.size;
}

void String::erase(int startIndex) {
    erase(startIndex, size-startIndex);
}

void String::erase(int startIndex, int numToErase) {
	// We could allocate a new array here, but since the old one
	// is long enough, let's not.
    for (int i=startIndex+numToErase; i<=size; i++)
        charArray[i-numToErase] = charArray[i];
    size -= numToErase;
}

String  String::insert(int startIndex, const String & other) {
    char * newArray = new char[size+other.size+1];

    // Get the original string up to the startIndex
     for (int i=0; i< startIndex; i++)
     	newArray[i] = this->charArray[i];
     // insert the new string
     for (int i=0; i < other.size; i++)
     	newArray[i+startIndex] = other.charArray[i];
     // Add the rest of the original string
     for (int i=startIndex; i < this->size ; i++)
     	newArray[i+other.size] = this->charArray[i];

    // deallocate the old chararray
    delete this->charArray;
    // charArray is newArray
    charArray = newArray;
    size += other.size;
    charArray[size] = '\0';

    // return a copy of this
    return *this;
}

String String::insert(int startIndex, int times, char ch) {
    char * newArray = new char[size + times + 1];
    // Get the original string up to the startIndex
     for (int i=0; i< startIndex; i++)
     	newArray[i] = this->charArray[i];
     for (int i=0; i < times; i++)
     	newArray[i+startIndex] = ch;
     // Add the rest of the original string
     for (int i=startIndex; i < this->size ; i++)
     	newArray[i+times] = this->charArray[i];

     // deallocate the old chararray
     delete this->charArray;
     // charArray is newArray
     charArray = newArray;
     size += times;
     charArray[size] = '\0';

     // return a copy of this
     return *this;
 }

// Changes the size of the allocation in theString to n. If n
// is less than the current size of the string, the string is
// truncated to n characters. If n is greater, the string is
// expanded and the character ch is appended at the end
// enough times to fill the new spaces.

String String::resize(int n, char ch){

	char * newArray = new char[n];
	if (size < n) {
		for (int i=0; i < size; i++)
			newArray[i] = charArray[i];
		for (int i=0; i < n-size; i++)
			newArray[i + size] = ch;
	}
	else if (size >= n) {
		for (int i=0; i < n; i++)
			newArray[i] = charArray[i];
	}

	delete [] charArray;
	charArray = newArray;
	size = n;
	charArray[n] = '\0';

	return * this;
}

bool String::empty() {
	return (charArray[0] == '\0');
}

ostream & operator<<(ostream & out, const String & s) {
	out << s.charArray;
	return out;
}
