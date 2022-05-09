/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:02:42 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/09 13:33:47 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "FragTrap.hpp"

static void	displayStatus(FragTrap &	ct) {
	std::cout << "Name: " << ct.getName() << std::endl;
	std::cout << "HitPoints: " << ct.getHitPoints() << std::endl;
	std::cout << "EnergyPoints: " << ct.getEnergyPoints() << std::endl;
	std::cout << "AttackDamage: " << ct.getAttackDamage() << std::endl << std::endl;
}

int	main(void) {
	FragTrap	clap1;
	FragTrap	clap2("clap2");
	FragTrap	clap3(clap2);

	clap1.setName("clap1");
	clap1.setHitPoints(10);

	clap2.setAttackDamage(5);
	clap2.setEnergyPoints(2);

	clap3.highFivesGuys();

	displayStatus(clap1);
	displayStatus(clap2);
	displayStatus(clap3);

	clap2.attack(clap1.getName());
	displayStatus(clap2);

	clap1.takeDamage(clap2.getAttackDamage());
	displayStatus(clap1);

	clap1.beRepaired(clap2.getAttackDamage());
	displayStatus(clap1);
	
	clap2.attack(clap1.getName());
	clap1.takeDamage(clap2.getAttackDamage());
	displayStatus(clap2);
	displayStatus(clap1);
	
	clap2.attack(clap1.getName());
	clap1.takeDamage(clap2.getAttackDamage());
	clap1.takeDamage(clap2.getAttackDamage());
	displayStatus(clap2);
	displayStatus(clap1);

	return (EXIT_SUCCESS);
}
