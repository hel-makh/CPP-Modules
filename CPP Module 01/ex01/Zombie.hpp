/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:11:06 by hel-makh          #+#    #+#             */
/*   Updated: 2022/04/23 19:03:37 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <string>

class Zombie {
	public:
		Zombie(std::string zombieName);
		Zombie(void);
		~Zombie(void);
		Zombie& operator=(std::string zombieName) {
			this->name = zombieName;
			return (*this);
		}
		void	announce(void);
	private:
		std::string name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif