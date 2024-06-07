#ifndef BITCOINEXCHANGE_CPP
#define BITCOINEXCHANGE_CPP

#include <iostream>
#include <map>
#include <vector>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void readBTCData();
		void processData(std::string const &filename);


	private:
		std::map<std::string, float> _exchangeRates;
		bool checkFormat(std::string const &date, std::string const &rate);
		bool checkDate(std::string const &date);
		std::string minDate;
		std::string maxDate;
};

#endif