#include <iostream>

using namespace std;

class String {
	friend ostream & operator<<(ostream & out, const String & s);
    public:
        String();
        String(char * cstr);
        String(const String &);
        ~String();
        String & operator=(const String & other);
        int length() const;
        void display() const;
        void append(const String & other);
        void erase(int startIndex);
        void erase(int startIndex, int numToErase);
        String  insert(int startIndex, const String & other);
        String insert(int startIndex, int times, char ch);
        String resize(int n, char ch=NULL);
        bool empty();
    private:
        char * charArray;
        int size;
};

