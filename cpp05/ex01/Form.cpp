#include "Form.hpp"

Form::Form() : _name("default"), _gradeToSign(150), _gradeToExecute(150), _isSigned(false)
{
}

Form::~Form()
{
}

Form::Form(std::string const name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form const &other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute), _isSigned(other._isSigned)
{
}

Form &Form::operator=(Form const &other)
{
    _isSigned = other._isSigned;
    return *this;
}

std::string Form::getName() const
{
    return _name;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

bool Form::getIsSigned() const
{
    return _isSigned;
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw Form::GradeTooLowException();
    _isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
    out << "Form " << form.getName() << " requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute. It is currently " << (form.getIsSigned() ? "" : "not ") << "signed.";
    return out;
}
