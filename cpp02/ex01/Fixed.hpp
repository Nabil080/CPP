#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		static const int fractional_bits = 8;
		int				 fixed_point_value;

	public:
		/*default constructor*/
		Fixed();
		/*copy constructor*/
		Fixed(const Fixed &other);
		/*int constructor*/
		Fixed(const int nbr);
		/*float constructor*/
		Fixed(const float nbr);
		/*copy operator*/
		Fixed &operator=(const Fixed &other);
		/*output operator*/
		/*default destructor*/
		~Fixed();
		void  setRawBits(int const raw);
		int	  getRawBits(void) const;
		int	  toInt(void) const;
		float toFloat(void) const;
};
std::ostream &operator<<(std::ostream &out, const Fixed &other);

#endif
