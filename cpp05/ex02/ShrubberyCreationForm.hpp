#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		/* Constructors & Destructor */
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);

		/* Member Functions */
		virtual void execute(const Bureaucrat &executor) const;

		/* Exceptions */
		class FileNotOpenException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		const std::string _target;
};

#endif