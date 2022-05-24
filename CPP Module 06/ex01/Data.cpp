/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:22:38 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/24 15:35:59 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

/*************************[ Constructors/Destructors ]*************************/

Data::Data(void) :	_c('c'),
					_i(42),
					_f(3.14f),
					_d(42.42) {
	return;
}

/*****************************[ Member Functions ]*****************************/

char	Data::getChar(void) const {
	return (this->_c);
}

int	Data::getInt(void) const {
	return (this->_i);
}

float	Data::getFloat(void) const {
	return (this->_f);
}

double	Data::getDouble(void) const {
	return (this->_d);
}
