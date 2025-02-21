#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
class RPN
{
	private:
		static const std::string _tokens;
		static const std::string _base;
		std::stack<char>         _expr_stack;
		std::stack<int>          _result_stack;

	public:
		RPN();
		RPN(std::string expression);
		RPN(const RPN &other);
		~RPN();

		RPN             &operator=(const RPN &other);

		std::stack<char> setExpr(std::string expression);
		int              getResult() const;
};

#endif
