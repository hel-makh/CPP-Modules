/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:12:07 by hel-makh          #+#    #+#             */
/*   Updated: 2023/03/15 15:03:24 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/***********************************[ Utils ]**********************************/

static bool	isNumeric(std::string const & str) {
	std::string::const_iterator it = str.begin();
	
	if (*it == '-' || *it == '+')
		++it;
	while (it != str.end() && (std::isdigit(*it) || *it == '.'))
		++it;
	return (!str.empty() && it == str.end());
}

static int	dateToUnixTime(int y, int m, int d) {
	int			timestamp;
	time_t		rawtime;
	struct tm	tm;

	time(&rawtime);
	tm = *localtime(&rawtime);
	tm.tm_year = y - 1900;
	tm.tm_mon = m - 1;
	tm.tm_mday = d;
	timestamp = mktime(&tm);
	
	return (timestamp);
}

static bool	isValidDateFormat(std::string date) {
	if (std::count(date.begin(), date.end(), '-') != 2)
		return (false);
	std::string::const_iterator it = date.begin();
	while (it != date.end() && (std::isdigit(*it) || *it == '-'))
		++it;
	return (!date.empty() && it == date.end());
}

static bool	isValidDate(int y, int m, int d) {
	if (! (1 <= m && m <= 12) )
		return (false);
	if (! (1 <= d && d <= 31) )
		return (false);
	if ( (d == 31) && (m == 2 || m == 4 || m == 6 || m == 9 || m == 11) )
		return (false);
	if ( (d == 30) && (m == 2) )
		return (false);
	if ( (m == 2) && (d == 29) && (y % 4 != 0) )
		return (false);
	if ( (m == 2) && (d == 29) && (y % 400 == 0) )
		return (true);
	if ( (m == 2) && (d == 29) && (y % 100 == 0) )
		return (false);
	if ( (m == 2) && (d == 29) && (y % 4 == 0)  )
		return (true);
	return (true);
}

/*************************[ Constructors/Destructors ]*************************/

BitcoinExchange::BitcoinExchange(const char * database) {
	std::ifstream	db_file;

	db_file.open(database);
	if (!db_file.is_open()) {
		throw std::runtime_error("Could not open database file.");
	}

	std::string	line;
	while (std::getline(db_file, line)) {
		if (line == "date,exchange_rate")
			continue ;
		
		size_t comma = line.find(",");
  		if (comma == std::string::npos) {
			throw std::runtime_error(std::string("Error: bad input in database => ") + line);
		}
		
		int	year = 0;
		int	month = 0;
		int	day = 0;
		std::string	date = line.substr(0, comma);

		if (!isValidDateFormat(date)) {
			throw std::runtime_error(std::string("Error: invalid date format in database => ") + line);
		}
		
		std::replace(date.begin(), date.end(), '-', ' ');
		std::istringstream(date) >> year >> month >> day;

		if (!isValidDate(year, month, day)) {
			throw std::runtime_error(std::string("Error: invalid date in database => ") + line);
		}
		
		int	timestamp = dateToUnixTime(year, month, day);

		float 				exchange_rate;
		std::stringstream	ss;
		ss << line.substr(comma + 1);
		ss >> exchange_rate;

		if (!isNumeric(line.substr(comma + 1)) || exchange_rate < 0) {
			throw std::runtime_error(std::string("Error: invalid number => ") + line);
		}
		
		this->database.insert(std::pair<int, float>(timestamp, exchange_rate));
	}

	db_file.close();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & rhs) {
	this->database.insert(rhs.database.begin(), rhs.database.end());
}

/****************************[ Operators overload ]****************************/

BitcoinExchange &	BitcoinExchange::operator=(BitcoinExchange const & rhs) {
	if (this != &rhs) {
		this->~BitcoinExchange();
		new (this) BitcoinExchange(rhs);
	}
	return (*this);
}

/*****************************[ Member Functions ]*****************************/

void	BitcoinExchange::printValues(const char * input) {
	std::ifstream	in_file;

	in_file.open(input);
	if (!in_file.is_open()) {
		throw std::runtime_error("Could not open input file.");
	}

	std::string	line;
	while (std::getline(in_file, line)) {
		if (line == "date | value")
			continue ;

		size_t sep = line.find(" | ");
  		if (sep == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}

		int	year = 0;
		int	month = 0;
		int	day = 0;
		std::string	date = line.substr(0, sep);

		if (!isValidDateFormat(date)) {
			std::cerr << "Error: invalid date format => " << line << std::endl;
		}
		
		std::replace(date.begin(), date.end(), '-', ' ');
		std::istringstream(date) >> year >> month >> day;
		std::replace(date.begin(), date.end(), ' ', '-');

		if (!isValidDate(year, month, day)) {
			std::cerr << "Error: invalid date => " << line << std::endl;
			continue ;
		}

		int	timestamp = dateToUnixTime(year, month, day);

		float				value;
		std::stringstream	ss;
		
		if (!isNumeric(line.substr(sep + 3))) {
			std::cerr << "Error: not a number => " << line << std::endl;
			continue ;
		}

		ss << line.substr(sep + 3);
		ss >> value;
		
		if (value < 0) {
			std::cerr << "Error: not a positive number => " << line << std::endl;
			continue ;
		}
		else if (value > 1000) {
			std::cerr << "Error: too large number => " << line << std::endl;
			continue ;
		}

		std::map<int, float>::iterator it = this->database.lower_bound(timestamp);
		if(it == this->database.end()) {
			--it;
		}
		
		float	exchange_rate = it->second;
		std::cout << date << " => " << value << " = " << value * exchange_rate << std::endl;
	}

	in_file.close();
}
