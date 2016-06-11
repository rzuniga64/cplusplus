/* Assume  the existence of the abstract Sorter class  below.
 *
 * The sortArray member function is a modified version of the selection sort algorithm
 * that relies on a compare  function to determine whether  one element  should go earlier
 * in the array  than the other. Write two subclasses of the Sorter class, called
 * IncreasingSorter and DecreasingSorter, which will each sort an array of doubles
 * in the order implied by the class  name . In each case, you need only define the compare
 * function. These classes should not override the sortArray function.
 *
 * This problem requires very little code; just a solid understanding of polymorphism.
 *
 */

class  Sorter {
public:
  virtual bool compare (double  x, double  y) = 0;
  void sortArray(double  * intArray, int  size);
};

void Sorter::sortArray(double  * dArray, int  size)
{
  int  startScan, minIndex;
  double  minValue;
  for (startScan = 0; startScan < size-1; startScan++)
  {
    minIndex = startScan;
    minValue = dArray[startScan];
    for (int  index = startScan + 1; index < size; index++)
    {
      if (compare(dArray[index], minValue))
      {
        minValue = dArray[index];
        minIndex = index;
      }
    }
    dArray[minIndex] = dArray[startScan];
    dArray[startScan] = minValue;
  }
}

class IncreasingSorter:public Sorter {
public:
	virtual bool compare(double arrayValue, double value) {
		return (arrayValue < value);
	}
};

class DecreasingSorter:public Sorter {
public:
	virtual bool compare(double arrayValue, double value) {
		return (arrayValue > value);
	}
};


