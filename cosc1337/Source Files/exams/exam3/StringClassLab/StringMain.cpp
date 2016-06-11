#include "String.h"

int main()
{

	String str("giraffe");
	//str.resize(10, 'a');
	str.resize(10);
	//str.insert(3,4,'h');

	String str1("giraffe");
    String str2 = str1;

	str1.erase(5);   // should make str1 'giraf'
	str2.erase(1,2); // should make str2 'gaffe'

	cout << "str1 (should be 'giraf'): " << str1 << endl;
	cout << "str2 (should be 'gaffe'): " << str2 << endl;

	/* for testing insert function */

    String str3("zebra");
	String str4 = str1;
    str3.insert(0, "wild ");
    str4.insert(str4.length(), "fish");
    String str5("gazelle");
    String str6("dog");
    str5.insert(3, str6);
    cout << "str3:" << str3 << endl;
    cout << "str4: " << str4 << endl;
    cout << "str5: " << str5 << endl;
    
    return 0;
}
