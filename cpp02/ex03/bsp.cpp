#include "Point.hpp"

bool	is_on_edge(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	x = point.getX();
	Fixed	y = point.getY();

	if (x == a.getX() || x == b.getX() || x == c.getX())
		return (true);
	if (y == a.getY() || y == b.getY() || y == c.getY())
		return (true);
	return (false);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (is_on_edge(a, b, c, point))
		return (false);
	return (true);
}
