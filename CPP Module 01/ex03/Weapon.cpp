/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:58:24 by hel-makh          #+#    #+#             */
/*   Updated: 2022/04/24 17:19:22 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) {
}

Weapon::Weapon(std::string init_type) : type(init_type) {
}

const std::string	Weapon::getType() {
	return (this->type);
}

void	Weapon::setType(std::string newType) {
	this->type = newType;
}
