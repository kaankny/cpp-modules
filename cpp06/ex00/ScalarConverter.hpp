#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
	public:
		/* Constructors & Destructor */
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		virtual ~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &copy);

		/* Member Functions */
		void convert(const std::string &str);

	private:
		/* Member Functions */
		void convertChar(const std::string &input);
		void convertInt(const std::string &input);
		void convertFloat(const std::string &input);
		void convertDouble(const std::string &input);
};

#endif