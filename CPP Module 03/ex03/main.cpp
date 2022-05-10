/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:02:42 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/09 15:37:05 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "DiamondTrap.hpp"

static void	displayStatus(DiamondTrap &	ct) {
	std::cout << "Name: " << ct.getName() << std::endl;
	std::cout << "HitPoints: " << ct.getHitPoints() << std::endl;
	std::cout << "EnergyPoints: " << ct.getEnergyPoints() << std::endl;
	std::cout << "AttackDamage: " << ct.getAttackDamage() << std::endl << std::endl;
}

int	main(void) {
	DiamondTrap	clap1;
	DiamondTrap	clap2("clap2");

	clap1.setName("clap1");
	clap1.setHitPoints(10);

	clap2.setAttackDamage(5);
	clap2.setEnergyPoints(2);

	clap1.guardGate();
	clap2.highFivesGuys();

	displayStatus(clap1);
	displayStatus(clap2);

	clap1.whoAmI();

	clap1.setName("claptrap1");
	clap1.ClapTrap::setName("claptrap-1");

	clap1.whoAmI();
	
	clap2.attack(clap1.getName());
	displayStatus(clap2);

	return (EXIT_SUCCESS);
}
