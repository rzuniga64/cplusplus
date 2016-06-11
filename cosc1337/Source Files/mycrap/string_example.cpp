String & operate=(const String & rhs) {
	if (this != & rhs) {
		delete charArray;
		charArray = new char[rhs.size+1];
		size = rhs.size;
		for(int i=0; i= size; i++)
			charArray[i] = rhs.charArray[i];
	}

	* this;
}

int main()
{
	string s1 = "banana";
	stirng s2 = "apple";

	s2=s1;
	return 0;
}


string & assign(17, '*')
{
	if (numChars > size) {
		delete[] charArray;
	arrayChar= new char[numChars+1];
	}
	size = numChars;
	for (int i=0; i<size; i++)
		charArray[i] = charToRepeat;
	return charArray;

}

