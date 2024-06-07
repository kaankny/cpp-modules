#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>

float ft_stof(const std::string &str)
{
	float result;
	std::istringstream(str) >> result;
	return (result);
}

int ft_stoi(const std::string &str)
{
	int result;
	std::istringstream(str) >> result;
	return (result);
}

bool BitcoinExchange::checkFormat(std::string const &date, std::string const &rate)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	for (size_t i = 0; i < date.size(); i++)
		if (i != 4 && i != 7 && !std::isdigit(date[i]))
			return (false);
	for (size_t i = 0; i < rate.size(); i++)
		if (!std::isdigit(rate[i]) && rate[i] != '.')
			if (i != 0 || rate[i] != '-')
				return (false);
	return (true);

}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	_exchangeRates = other._exchangeRates;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::readBTCData()
{
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw std::runtime_error("Could not open file");
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		std::string date;
		std::string rate;
		std::getline(ss, date, ',');
		std::getline(ss, rate, ',');
		if (minDate.size() == 0 || date < minDate)
			minDate = date;
		if (maxDate.size() == 0 || date > maxDate)
			maxDate = date;
		if (std::count(line.begin(), line.end(), ',') != 1)
			throw std::runtime_error("Invalid line");
		if (!checkFormat(date, rate))
			throw std::runtime_error("Invalid line");
		if (_exchangeRates.find(date) != _exchangeRates.end())
			throw std::runtime_error("Duplicate date");
		_exchangeRates[date] = ft_stof(rate);
	}
}

bool BitcoinExchange::checkDate(std::string const &date)
{
	int year = ft_stoi(date.substr(0, 4));
	int month = ft_stoi(date.substr(5, 2));
	int day = ft_stoi(date.substr(8, 2));
	int maxYear = ft_stoi(maxDate.substr(0, 4));
	int minYear = ft_stoi(minDate.substr(0, 4));
	if (year < minYear || year > maxYear)
		return (false);
	int maxMonth = ft_stoi(maxDate.substr(5, 2));
	int minMonth = ft_stoi(minDate.substr(5, 2));
	if (year == minYear && month < minMonth)
		return (false);
	if (year == maxYear && month > maxMonth)
		return (false);
	int maxDay = ft_stoi(maxDate.substr(8, 2));
	int minDay = ft_stoi(minDate.substr(8, 2));
	if (year == minYear && month == minMonth && day < minDay)
		return (false);
	if (year == maxYear && month == maxMonth && day > maxDay)
		return (false);
	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > 31)
		return (false);
	if (month == 2)
	{
		if (year % 4 == 0 && year % 100 != 0)
		{
			if (day > 29)
				return (false);
		}
		else
		{
			if (day > 28)
				return (false);
		}
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			return (false);
	}	
	return (true);
}

void BitcoinExchange::processData(std::string const &filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
		throw std::runtime_error("Could not open file");
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		std::string date;
		std::string amount;
		std::getline(ss, date, '|');
		std::getline(ss, amount, '|');
		date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
		amount.erase(std::remove(amount.begin(), amount.end(), ' '), amount.end());
		if (date.size() == 0 || amount.size() == 0)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (checkDate(date) == false)
		{
			std::cout << "Error: bad date => " << date << std::endl;
			continue;
		}
		if (std::count(line.begin(), line.end(), '|') != 1)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (!checkFormat(date, amount))
		{
			std::cout << "Invalid line" << std::endl;
			continue;
		}
		if (ft_stof(amount) < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (ft_stof(amount) > 1000)
		{
			std::cout << "Error: too large number." << std::endl;
			continue;
		}
		if (_exchangeRates.find(date) == _exchangeRates.end())
		{
			std::string closestDate;
			for (std::map<std::string, float>::iterator it = _exchangeRates.begin(); it != _exchangeRates.end(); it++)
			{
				if (it->first < date)
					closestDate = it->first;
				else
					break;
			}
			if (closestDate.size() == 0)
			{
				std::cout << date << " => " << amount << " = " << "N/A" << std::endl;
				continue;
			}
			std::cout << date << " => " << amount << " = " << std::fixed << std::setprecision(2) << _exchangeRates[closestDate] * ft_stof(amount) << std::endl;
			continue;
		}
		std::cout << date << " => " << amount << " = " << std::fixed << std::setprecision(2) << _exchangeRates[date] * ft_stof(amount) << std::endl;
	}
}