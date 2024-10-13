#include "Point.hpp"

Fixed	calculate_cross_product(Point const a, Point const b, Point const point)
{
	Point	ab = Point(a, b);
	Point	ap = Point(a, point);
	return (ab.getX() * ap.getY() - ab.getY() * ap.getX());
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed cross_product = calculate_cross_product(a, b, point);
	if (cross_product == 0)
		return (false);
	bool	is_negative = cross_product < 0;
	cross_product = calculate_cross_product(b, c, point);
	if (cross_product == 0 || (is_negative != cross_product < 0))
		return (false);
	cross_product = calculate_cross_product(c, a, point);
	if (cross_product == 0 || (is_negative != cross_product < 0))
		return (false);
	return (true);
}

