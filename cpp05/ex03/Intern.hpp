#ifndef IRTEN_HPP
# define IRTEN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		/* Constructors & Destructor */
		Intern();
		Intern(const Intern &copy);
		virtual ~Intern();
		Intern &operator=(const Intern &copy);

		/* Member Functions */
		AForm *makeForm(std::string formName, std::string target);

		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		AForm *createPresidentialPardonForm(std::string target);
		AForm *createRobotomyRequestForm(std::string target);
		AForm *createShrubberyCreationForm(std::string target);
};

#endif