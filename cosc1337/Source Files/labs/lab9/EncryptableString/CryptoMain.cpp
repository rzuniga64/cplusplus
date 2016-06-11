#include "EncryptableString.h"

int main() {
    EncryptableString str1("this is a message.");
    str1.encrypt(30);
    cout << "encrypted: " << str1 << endl;
    
    str1.decrypt(30);
    cout << "decrypted: " << str1 << endl << endl;
    
    EncryptableString str2("THIS IS ANOTHER MESSAGE!");
    str2.encrypt(7);
    cout << "encrypted: " << str2 << endl;
    
    str2.decrypt(7);
    cout << "decrypted: " << str2 << endl << endl;
    
    EncryptableString str4("this IS another MESSAGE!");
    str4.encrypt(7);

    cout << "encrypted: " << str4 << endl;

    str4.decrypt(7);
    cout << "decrypted: " << str4 << endl << endl;


    EncryptableString str3("v pna'g jnvg gb cynl cbat!");

    // try all possible keys to decode str3
    for (int i=1; i < 26; i++) {
    	str3.decrypt(i);
    	cout << "decrypted: " << str3 << endl;
    	str3.encrypt(i);
    }
    
    return 0;
}
