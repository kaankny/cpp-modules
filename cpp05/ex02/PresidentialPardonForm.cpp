#include "PresidentialPardonForm.hpp"

/* Constructors & Destructor */

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), _target(copy._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	if (this == &copy)
		return *this;
	AForm::operator=(copy);
	return *this;
}

/* Member Functions */

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
