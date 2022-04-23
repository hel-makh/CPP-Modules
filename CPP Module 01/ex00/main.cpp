/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:22:40 by hel-makh          #+#    #+#             */
/*   Updated: 2022/04/23 17:30:59 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie	zombie1("zombie1");
	zombie1.announce();
	
	Zombie	*zombie2 = newZombie("zombie2");
	zombie2->announce();
	delete zombie2;

	randomChump("zombie3");

	return (EXIT_SUCCESS);
}
