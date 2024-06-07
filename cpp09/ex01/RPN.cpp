#include "RPN.hpp"
#include <stack>

RPN::RPN() {}

RPN::RPN(const RPN &rpn)
{
	*this = rpn;
}

RPN &RPN::operator=(const RPN &rpn)
{
	this->_stack = rpn._stack;
	return (*this);
}

RPN::~RPN() {}

void RPN::initStack(std::string const &str)
{
	if (str.empty())
		throw std::runtime_error("Empty string");
	std::string::const_iterator it = str.begin();
	while (it != str.end())
	{
		if (*it == ' ')
		{
			++it;
			continue;
		}
		else if (std::isdigit(*it))
			this->_stack.push_back(std::make_pair(*it, 'd'));
		else if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
			this->_stack.push_back(std::make_pair(*it, 'o'));
		else
			throw std::runtime_error("Invalid character");
		++it;
	}
}

void RPN::execute()
{
	std::vector<std::pair<char, char> >::iterator it = this->_stack.begin();
	std::stack<int> stack;

	while (it != this->_stack.end())
	{
		if (it->second == 'd')
			stack.push(it->first - '0');
		else if (it->second == 'o')
		{
			if (stack.size() < 2)
				throw std::runtime_error("Not enough operands");
			int a = stack.top();
			stack.pop();
			int b = stack.top();
			stack.pop();
			if (it->first == '+')
				stack.push(b + a);
			else if (it->first == '-')
				stack.push(b - a);
			else if (it->first == '*')
				stack.push(b * a);
			else if (it->first == '/')
			{
				if (a == 0)
					throw std::runtime_error("Division by zero");
				stack.push(b / a);
			}
		}
		++it;
	}
	if (stack.size() != 1)
		throw std::runtime_error("Invalid expression");
	std::cout << stack.top() << std::endl;
}