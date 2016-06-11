#include <iostream>

using namespace std;

class String {
	friend ostream & operator<<(ostream & out, const String & s);
public:
    String();
    String(char * cstr);
	// copy constructor removed so you can write it on the lab
    ~String();
	String & operator=(const String & rhs);
    int length() const;
    void display() const;
    String & erase(int startIdx, int numToErase);
    String & assign(int num, char charToRepeat);
private:
    char * charArray;
    int size;
};
