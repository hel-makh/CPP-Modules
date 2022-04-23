/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:11:10 by hel-makh          #+#    #+#             */
/*   Updated: 2022/04/23 19:03:20 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {
	Zombie	*zombieHorde;

	zombieHorde = new Zombie[N];
	for (int i = 0; i < N; i ++)
		zombieHorde[i] = name;
	return (zombieHorde);
}
