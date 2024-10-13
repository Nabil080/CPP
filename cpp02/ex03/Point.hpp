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
		Point&	operator=(const Point&);

	public:	
		void		print(void) const;
		Fixed const	getX(void) const;
		Fixed const	getY(void) const;
};

#endif
