/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:13:05 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/24 14:43:00 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Conversion.hpp"

/*************************[ Constructors/Destructors ]*************************/

Conversion::Conversion(std::string const & input) :	_input(input),
													_value(0.0),
													_invalid(false)	{
	try {
		std::stringstream	ss;
		std::string			input2;

		input2 = input;
		if (input2.find('.') != std::string::npos
			&& (input2.at(input2.length() - 1) == 'f'
				|| input2.at(input2.length() - 1) == 'F'))
			input2.resize(input2.length() - 1);
		ss << input2;
		ss >> this->_value;
		if (ss.fail()) {
			if (input2.length() != 1) 
				throw InvalidType();
			this->_value = (double) input2[0];
		}
	} catch (Conversion::InvalidType & e) {
		this->_invalid = true;
	}
}

Conversion::Conversion(Conversion const & rhs) {
	if (this != &rhs) {
		new (this) Conversion(rhs.getInput());
	}
}

/****************************[ Operators overload ]****************************/

Conversion &	Conversion::operator=(Conversion const & rhs) {
	if (this != &rhs) {
		this->~Conversion();
		new (this) Conversion(rhs.getInput());
	}
	return (*this);
}

std::ostream &	operator<<(std::ostream & o, Conversion const & rhs) {
	if (rhs.isInvalid()) {
		o << rhs.getInput() << ": Type conversion is impossible." << std::endl;
		return (o);
	}

	if (!isascii(rhs.toInt()) || isnan(rhs.toFloat()) || isinf(rhs.toFloat()))
		o << "char: impossible" << std::endl;
	else if (!isprint(rhs.toInt()))
		o << "char: Non displayable" << std::endl;
	else
		o << "char: '" << rhs.toChar() << "'" << std::endl;

	if (isnan(rhs.toFloat()) || isinf(rhs.toFloat()))
		o << "int: impossible" << std::endl;
	else
		o << "int: " << rhs.toInt() << std::endl;

	if (isinf(rhs.toFloat()))
		o << std::showpos;
	
	o << "float: " << std::fixed << std::setprecision(1) << rhs.toFloat() << "f" << std::endl;
	
	o << "double: " << std::fixed << std::setprecision(1) << rhs.toDouble() << std::endl;

	return (o);
}

/*****************************[ Member Functions ]*****************************/

std::string const &	Conversion::getInput(void) const {
	return (this->_input);
}

char	Conversion::toChar(void) const {
	return (static_cast<char>(this->_value));
}

int	Conversion::toInt(void) const {
	return (static_cast<int>(this->_value));
}

float	Conversion::toFloat(void) const {
	return (static_cast<float>(this->_value));
}

double	Conversion::toDouble(void) const {
	return (static_cast<double>(this->_value));
}

bool	Conversion::isInvalid(void) const {
	return (this->_invalid);
}
