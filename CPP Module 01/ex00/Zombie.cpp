/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:04:29 by hel-makh          #+#    #+#             */
/*   Updated: 2022/04/24 17:13:21 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string zombieName) : name(zombieName) {
}

Zombie::~Zombie(void) {
    std::cout << this->name << ": ate too much BraiiiiiiinnnzzzZ and died..." << std::endl;
}

void    Zombie::announce(void) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
