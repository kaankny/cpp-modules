#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
        Form();
        ~Form();
        Form(std::string const name, int gradeToSign, int gradeToExecute);
        Form(Form const &other);
        Form &operator=(Form const &other);

        std::string getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool getIsSigned() const;

        void beSigned(Bureaucrat const &bureaucrat);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

    private:
        const std::string _name;
        const int _gradeToSign;
        const int _gradeToExecute;
        bool _isSigned;
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif