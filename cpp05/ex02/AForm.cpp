#include "AForm.hpp"

/* Constructors & Destructor */

AForm::AForm() : _name("default"), _signed(false), _signGrade(150), _execGrade(150) {}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _execGrade(copy._execGrade) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &copy)
{
	if (this == &copy)
		return *this;
	_signed = copy._signed;
	return *this;
}

/* Getters */

std::string AForm::getName() const { return _name; }

bool AForm::getSigned() const { return _signed; }

int AForm::getSignGrade() const { return _signGrade; }

int AForm::getExecGrade() const { return _execGrade; }

/* Member Functions */

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
        throw AForm::GradeTooLowException();
    _signed = true;
}

/* Exceptions */

const char *AForm::GradeTooHighException::what() const throw() { return "Grade is too high"; }

const char *AForm::GradeTooLowException::what() const throw() { return "Grade is too low"; }

const char *AForm::FormNotSignedException::what() const throw() { return "Form is not signed"; }

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << "Form: " << form.getName() << ", Sign Grade: " << form.getSignGrade() << ", Exec Grade: " << form.getExecGrade() << ", Signed: " << form.getSigned();
	return out;
}
