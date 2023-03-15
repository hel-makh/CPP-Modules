/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:42:57 by hel-makh          #+#    #+#             */
/*   Updated: 2023/03/15 15:05:17 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <fstream>
# include <map>
# include <algorithm>

class BitcoinExchange {
	private:
		std::map< int, float, std::greater<int> >	database;

	public:
		BitcoinExchange(const char * database);
		BitcoinExchange(BitcoinExchange const & rhs);
		~BitcoinExchange(void) {}

		BitcoinExchange &	operator=(BitcoinExchange const & rhs);

		void	printValues(const char * input);
};

#endif