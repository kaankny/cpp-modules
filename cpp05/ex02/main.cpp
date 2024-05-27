#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat bureaucrat("bureaucrat", 26);
	PresidentialPardonForm form("target");
	try
	{
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}


	Bureaucrat bureaucrat2("bureaucrat2", 25);
	RobotomyRequestForm form2("target2");
	try
	{
		bureaucrat2.signForm(form2);
		bureaucrat2.executeForm(form2);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}


	Bureaucrat bureaucrat3("bureaucrat3", 24);
	ShrubberyCreationForm form3("target3");
	try
	{
		bureaucrat3.signForm(form3);
		bureaucrat3.executeForm(form3);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
