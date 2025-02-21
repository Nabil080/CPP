#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
class RPN
{
	private:
		static const std::string _tokens;
		static const std::string _base;
		std::string              _expression;

	public:
		RPN();
		RPN(std::string expression);
		RPN(const RPN &other);
		~RPN();

		RPN        &operator=(const RPN &other);

		std::string setExpression(std::string expression);
		int         getResult();
};

#endif
