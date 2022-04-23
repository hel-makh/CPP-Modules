/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 21:00:54 by hel-makh          #+#    #+#             */
/*   Updated: 2022/04/23 21:39:38 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string init_name, Weapon& init_weapon) : name(init_name), weapon(&init_weapon) {
}

void	HumanA::attack(void) {
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}
