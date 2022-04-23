/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:02:34 by hel-makh          #+#    #+#             */
/*   Updated: 2022/04/23 17:26:51 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <string>

class Zombie {
	public:
		Zombie(std::string zombieName);
		~Zombie(void);
		void	announce(void);
	private:
		std::string name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif