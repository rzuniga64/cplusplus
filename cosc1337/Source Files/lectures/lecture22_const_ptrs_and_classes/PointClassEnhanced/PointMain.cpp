#include "Point.h"

int main()
{
	const Point ORIGIN(0, 0);
    Point p1(0,0);
    Point p2(3,4);
    
    p1.display();
    p2.display();
	ORIGIN.display();
    
    system("PAUSE");
    return 0;
}
