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
		Point(const Point&, const Point&);	//vector constructor
		~Point();

		Point&	operator=(const Point&);
		friend std::ostream &operator<<(std::ostream& output, const Point&);

	public:	
		void	print(void) const;
		Fixed	getX(void) const;
		Fixed	getY(void) const;
};

#endif
