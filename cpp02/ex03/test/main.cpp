/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:44:09 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/02 12:37:21 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>
#include <sstream>

bool	bsp( Point const a, Point const b, Point const c, Point const point);

float	str_to_float(char *str)
{
	std::istringstream iss1(str);
	float f1;
	iss1 >> f1;
	const float f1c = f1;
	return (f1c);
}

int main(int ac, char **av)
{
	if (ac != 9)
		return (0);


	Point a(str_to_float(av[1]), str_to_float(av[2]));
	Point b(str_to_float(av[3]), str_to_float(av[4]));
	Point c(str_to_float(av[5]), str_to_float(av[6]));
	Point point(str_to_float(av[7]), str_to_float(av[8]));
	bool is_in_abc = bsp(a, b, c, point);
	if (is_in_abc)
		std::cout << BHGREEN << "Le point appartient bien au triangle ABC !" << RESET << std::endl;
	else
		std::cout << BHRED << "Le point n'appartient pas au triangle ABC !" << RESET << std::endl;

	return (0);
}

// ./bsp 0.0 0.0 1.0 0.0 0.5 1.0 0.5 0.5
