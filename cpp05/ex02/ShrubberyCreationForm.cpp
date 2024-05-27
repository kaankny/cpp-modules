#include "ShrubberyCreationForm.hpp"
#include <fstream>

/* Constructors & Destructor */

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	if (this == &copy)
		return *this;
	AForm::operator=(copy);
	return *this;
}

/* Member Functions */

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename);
	if (!file.is_open())
		throw FileNotOpenException();

	file << "       ###\n";
	file << "      #o###\n";
	file << "    #####o###\n";
	file << "   #o#\\#|#/###\n";
	file << "    ###\\|/#o#\n";
	file << "     # }|{  #\n";
	file << "       }|{";
	file << std::endl;
	file.close();
}

/* Exceptions */

const char *ShrubberyCreationForm::FileNotOpenException::what() const throw()
{
	return "File could not be opened";
}
