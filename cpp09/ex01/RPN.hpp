#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <vector>

class RPN
{
	public:
		RPN();
		RPN(const RPN &rpn);
		RPN &operator=(const RPN &rpn);
		~RPN();

		void initStack(std::string const &str);
		void execute();
	
	private:
		std::vector<std::pair<char, char> > _stack;
};

#endif