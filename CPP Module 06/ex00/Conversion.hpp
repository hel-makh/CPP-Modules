/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:06:52 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/24 14:45:43 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <sstream>
# include <iomanip>
# include <string>
# include <math.h>

class Conversion {
	private:
		std::string const	_input;
		double				_value;
		bool				_invalid;

		class InvalidType : public std::exception {
			char const *	what() const throw() {
				return "Invalid type.";
			}
		};

	public:
		Conversion(void);
		Conversion(std::string const & input);
		Conversion(Conversion const & rhs);
		~Conversion(void) {}

		Conversion &	operator=(Conversion const & rhs);

		std::string const &	getInput(void) const;
		char				toChar(void) const;
		int					toInt(void) const;
		float				toFloat(void) const;
		double				toDouble(void) const;
		bool				isInvalid(void) const;
};

std::ostream &  operator<<(std::ostream & o, Conversion const & rhs);

#endif