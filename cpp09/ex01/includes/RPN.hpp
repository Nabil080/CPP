#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

#define ERR_EXPRESSION			"Invalid character inside the expression"
#define ERR_TOOLITTLE_OPERATORS "Not enough operators after a number"
#define ERR_TOOMANY_OPERATORS	"Too much operators after a number"

class RPN
{
	protected:
		static const std::string _tokens;
		static const std::string _base;
		std::string				 _expression;

	public:
		RPN();
		RPN(std::string expression);
		RPN(const RPN &other);
		~RPN();

		RPN		   &operator=(const RPN &other);

		std::string setExpression(std::string expression);
		int			getResult();
};

#endif
