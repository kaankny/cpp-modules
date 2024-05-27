#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	public:
		/* Constructors & Destructor */
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		virtual ~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &copy);

		/* Getters */
		std::string getName() const;
		int getGrade() const;

		/* Member Functions */
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &form) const;
		void executeForm(const AForm &form) const;

		/* Exceptions */
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		const std::string _name;
		int _grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif