#ifndef ENCRYPTABLESTRING_H_
#define ENCRYPTABLESTRING_H_

#include "String.h"

class EncryptableString : public String {
public:
	EncryptableString (char * cstr);
	char wrap(int key, int min, int max);
	void encrypt(unsigned key);
	void decrypt(unsigned key);
};

#endif /* ENCRYPTABLESTRING_H_ */
