#include "EncryptableString.h"
#include <iostream>
#include <ctype.h>

using namespace std;

EncryptableString::EncryptableString (char * cstr)
: String(cstr) {}

/* Utility function for wrapping the array indices
 * around to the other side of the array */
char EncryptableString::wrap(int key, int min, int max) {
    return static_cast<char>(key < min ? (max -min%key) +1 : (key > max ? min + key%max : key));
}

void EncryptableString::encrypt(unsigned key){

	for (int i=0; i < size; i++) {
		if (isalpha(charArray[i])) {
			if ( (isupper(charArray[i])))
				charArray[i] = wrap(charArray[i] + key, 'A'-1, 'Z');
			else if ((islower(charArray[i])))
				charArray[i] = wrap(charArray[i] + key, 'a'-1, 'z');
		}
	}
}

void EncryptableString::decrypt(unsigned key) {
	for (int i=0; i < size; i++) {
		if (isalpha(charArray[i])) {
			if ( (isupper(charArray[i])))
				charArray[i] = wrap(charArray[i] - key,'A', 'Z');
			else if ((islower(charArray[i])))
				charArray[i] = wrap(charArray[i] - key, 'a', 'z');
		}
	}
}
