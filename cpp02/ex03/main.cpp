#include "Point.hpp"
#include "Fixed.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

void	test(Point const a, Point const b, Point const c, Point const point)
{
	if (bsp(a, b, c, point))
		std::cout << "Point " << point << " is\033[1;32m inside\033[1;0m the triangle." << std::endl;
	else
		std::cout << "Point " << point << " is\033[1;31m outside\033[1;0m the triangle." << std::endl;
}

int main( void )
{
	Point	a(2, 2);
	Point	b(3, 5);
	Point	c(5, 3);

	std::cout << "A" << a << std::endl;
	std::cout << "B" << b << std::endl;
	std::cout << "C" << c << std::endl;


	test(a, b, c, Point(3, 3)); // Inside
	test(a, b, c, Point(4, 4)); // Inside
	test(a, b, c, Point(5, 5)); // Inside
	test(a, b, c, Point(6, 6)); // Outside
	test(a, b, c, Point(7, 7)); // Outside
	test(a, b, c, Point(8, 8)); // Outside
	test(a, b, c, Point(9, 9)); // Outside
	test(a, b, c, Point(2.5f, 2.5f)); // Float
	test(a, b, c, Point(3.5f, 3.5f)); // Float inside
	test(a, b, c, Point(4.5f, 4.5f)); // Float outside
	test(a, b, c, Point(5.5, 2.5f)); // Float outside on the edge
}
