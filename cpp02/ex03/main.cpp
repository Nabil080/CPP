#include "Point.hpp"
#include "Fixed.hpp"


bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	Point	a(2, 2);
	Point	b(3, 5);
	Point	c(5 ,3);
	Point	test(3, 3);

	std::cout << "A" << a << std::endl;
	std::cout << "B" << a << std::endl;
	std::cout << "C" << a << std::endl;

	std::cout << "Testing for : " << test << std::endl;
	std::cout << (bsp(a, b, c, test) ? "Success" : "Failure") << std::endl;
}
