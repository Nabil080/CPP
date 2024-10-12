#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

# define DEBUG 1

class	Fixed
{
	private: // attributes
		static const int	fractional_bits = 8;
		int					fixed_point_value;

	public: // constructors
		Fixed();
		Fixed(const Fixed&);
		Fixed(const int);
		Fixed(const float);
		~Fixed();

	public: // operators
		Fixed	&operator=(const Fixed&);

		Fixed	operator+(const Fixed&);
		Fixed	operator-(const Fixed&);
		Fixed	operator*(const Fixed&);
		Fixed	operator/(const Fixed&);

		bool	operator<(const Fixed&) const;
		bool	operator>(const Fixed&) const;
		bool	operator>=(const Fixed&) const;
		bool	operator<=(const Fixed&) const;
		bool	operator==(const Fixed&) const;
		bool	operator!=(const Fixed&) const;

		Fixed	operator++();
		Fixed	operator++(int);
		Fixed	operator--();
		Fixed	operator--(int);

		friend std::ostream &operator<<(std::ostream& output, const Fixed&);
		
	public : // methods
		void	setRawBits(int const);
		int		getRawBits(void) const;
		int		toInt(void) const;
		float	toFloat(void) const;

		static Fixed		&min(Fixed&, Fixed&);
		static const Fixed	&min(const Fixed&, const Fixed&);
		static Fixed		&max(Fixed&, Fixed&);
		static const Fixed	&max(const Fixed&, const Fixed&);
};

#endif
