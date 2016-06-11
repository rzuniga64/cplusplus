#include "BoundedLength.h"

int main() {
    // test of new Length features
	Length l1(1, "inches");
	Length l2(1, "cm");
	l1.addOther(l2);
	cout << "l1: " << l1 << endl;

    // test of new BoundedLength class
    BoundedLength bl1(1, "inches", 2);
    for (int i=0; i<5; i++) {
        bl1.addOther(l2);
        cout << "bl1: " << bl1 << endl;
    }

    BoundedLength bl2(1, "inches", 2);
    cout << endl << "bl2: " << bl2 << endl;
    bl2.convertTo("cm");
    cout << "converted bl2: " << bl2 << endl;
    bl2.setValue(10);
    cout << "bounded bl2: " << bl2 << endl;

    return 0;
}
