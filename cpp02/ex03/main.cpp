#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	Point	a(0, 0);
	Point	b(0, 10);
	Point	c(10 ,10);
	Point	test(a);

	a.print();
	b.print();
	c.print();
	std::cout << "Testing for : "; test.print();
	std::cout << (bsp(a, b, c, test) ? "Success" : "Failure") << std::endl;
}
