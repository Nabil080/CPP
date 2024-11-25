#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed
{
	private:
		static const int	fractional_bits = 8;
		int					fixed_point_value;
	public:
		/*default constructor*/
		Fixed();
		/*copy constructor*/
		Fixed(const Fixed &other);
		/*copy operator*/
		Fixed &operator=(const Fixed &other);
		/*default destructor*/
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif