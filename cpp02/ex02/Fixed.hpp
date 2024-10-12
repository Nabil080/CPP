#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

# define DEBUG 0

class	Fixed
{
	private: /*attributes*/
		static const int	fractional_bits = 8;
		int					fixed_point_value;
	public: /*constructors*/
		Fixed();
		Fixed(const Fixed&);
		Fixed(const int);
		Fixed(const float);
		~Fixed();
	public: /*operators*/
		/*copy*/
		Fixed	&operator=(const Fixed&);
		/*arithmetic*/
		Fixed	operator+(const Fixed&);
		Fixed	operator-(const Fixed&);
		Fixed	operator*(const Fixed&);
		Fixed	operator/(const Fixed&);
		/*comparison*/
		bool	operator<(const Fixed&);
		bool	operator>(const Fixed&);
		bool	operator>=(const Fixed&);
		bool	operator<=(const Fixed&);
		bool	operator==(const Fixed&);
		bool	operator!=(const Fixed&);
		/*crement*/
		Fixed	operator++();
		Fixed	operator++(int);
		Fixed	operator--();
		Fixed	operator--(int);
		/*iostream*/
		friend std::ostream &operator<<(std::ostream& output, const Fixed&);
	public : /*methods*/
		void	setRawBits(int const);
		int		getRawBits(void) const;
		int		toInt(void) const;
		float	toFloat(void) const;
};

#endif