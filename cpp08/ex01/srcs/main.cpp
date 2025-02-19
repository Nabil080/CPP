#include "Span.hpp"

#include <cstdlib>
#include <iostream>

static std::vector<int> generate_array(unsigned int capacity)
{
	std::vector<int>           array(capacity);
	std::vector<int>::iterator it;
	for (it = array.begin(); it != array.end(); it++)
		*it = rand();
	// *it = rand() % 100; // best to test low capacity
	return (array);
}

static void subject_test(unsigned int capacity)
{
	Span sp = Span(capacity);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp;
}

// does not check for overflows
static void capacity_test(unsigned int capacity)
{
	Span sp(capacity);

	for (unsigned int i = 0; i < capacity * 2; i++)
	{
		try
		{
			sp.addNumber(i);
			std::cout << "Successfully added " << i << std::endl;
		}
		catch (std::length_error e)
		{
			std::cout << "Couldn't add " << i << " because : " << e.what() << std::endl;
		}
	}
	std::cout << sp;
}

static void span_test(unsigned int capacity)
{
	Span             sp(capacity);
	std::vector<int> array = generate_array(capacity);
	sp.fill(array.begin(), array.end());
	std::cout << sp;
}

static void test(std::string name, void (*f)(unsigned int), unsigned int capacity)
{
	std::cout << std::endl << "--- " << name << " TEST (" << capacity << ") ---" << std::endl;
	f(capacity);
	std::cout << std::endl << std::endl;
}
int main()
{
	test("SUBJECT", subject_test, 5);
	test("CAPACITY", capacity_test, 2);
	test("CAPACITY", capacity_test, 10);
	// test("CAPACITY", capacity_test, 200);
	// test("CAPACITY", capacity_test, 20000);
	test("SPAN", span_test, 0);
	test("SPAN", span_test, 1);
	test("SPAN", span_test, 2);
	test("SPAN", span_test, 10);
	test("SPAN", span_test, 100);
	// test("SPAN", span_test, 10000);
	// test("SPAN", span_test, 100000);

	return (0);
}
