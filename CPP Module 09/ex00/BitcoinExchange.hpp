/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:42:57 by hel-makh          #+#    #+#             */
/*   Updated: 2023/03/14 22:13:56 by hel-makh         ###   ########.fr       */
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
		std::multimap<int, float>	database;

	public:
		BitcoinExchange(const char * database);
		BitcoinExchange(BitcoinExchange const & rhs);
		~BitcoinExchange() {}

		BitcoinExchange &	operator=(BitcoinExchange const & rhs);

		void	printValues(const char * input);
};

#endif