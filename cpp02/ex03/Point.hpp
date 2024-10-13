#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point
{
	private:
		static const bool	debug = false;
		Fixed const	x;
		Fixed const	y;
	public:		//constructors
		Point();
		Point(const Point&);
		Point(const float, const float);
		~Point();

	public:		//operators
		Point&	operator=(const Point&);
		void	print(void) const;
};

#endif
