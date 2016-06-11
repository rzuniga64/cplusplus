 #include <iostream>
 using namespace std;

 class NumberArray
 {
 private:
	 double *aPtr;
	 int arraySize;
 public:
	 NumberArray(int size, double value);
	 NumberArray(const NumberArray &);
	 ~NumberArray() { if (arraySize > 0) delete [] aPtr; }
	 void display() const;
	 void setValue(double value);
 };
