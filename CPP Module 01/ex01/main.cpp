/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:22:40 by hel-makh          #+#    #+#             */
/*   Updated: 2022/04/23 19:03:49 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie	*zombies = zombieHorde(5, "zombieHorde");
	
	for (int i = 0; i < 5; i ++) {
		std::cout << i << " ";
		zombies->announce();
	}

	delete [] zombies;
	
	return (EXIT_SUCCESS);
}
