#include "Intern.hpp"

/* Constructors & Destructor */

Intern::Intern() {}

Intern::Intern(const Intern &copy) { (void)copy; }

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &copy)
{
	(void)copy;
	return *this;
}

/* Member Functions */

AForm *Intern::makeForm(std::string formName, std::string target)
{
	std::string formNames[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm *(Intern::*createForm[3])(std::string target) = {&Intern::createPresidentialPardonForm, &Intern::createRobotomyRequestForm, &Intern::createShrubberyCreationForm};

	for (int i = 0; i < 3; i++)
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*createForm[i])(target);
		}
	throw FormNotFoundException();
}

AForm *Intern::createPresidentialPardonForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::createRobotomyRequestForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createShrubberyCreationForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

const char *Intern::FormNotFoundException::what() const throw() { return "Form not found"; }