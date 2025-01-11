#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

static Base *generate(void)
{
	switch (std::rand() % 3)
	{
	case 0:
		std::cout << "Creating A" << std::endl;
		return (new A());
	case 1:
		std::cout << "Creating B" << std::endl;
		return (new B());
	case 2:
		std::cout << "Creating C" << std::endl;
		return (new C());
	default:
		return (NULL);
	}
}

static void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A";
	else if (dynamic_cast<B *>(p))
		std::cout << "B";
	else if (dynamic_cast<C *>(p))
		std::cout << "C";
	else
		std::cout << "Unknown";
	std::cout << " Identified" << std::endl;
}

static void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A Identified" << std::endl;
		return;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B Identified" << std::endl;
		return;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C Identified" << std::endl;
		return;
	}
	catch (std::exception &e)
	{
	}
}

int main(void)
{
	srand(time(NULL));
	Base *obj_ptr = generate();
	if (!obj_ptr)
		return (1);
	identify(obj_ptr); // ptr identify
	delete obj_ptr;

	obj_ptr = generate();
	Base &obj_ref = *obj_ptr;
	identify(obj_ref); // ptr ref
	delete obj_ptr;

	return (0);
}
