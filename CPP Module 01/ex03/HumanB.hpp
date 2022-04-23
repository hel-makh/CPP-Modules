/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 21:06:32 by hel-makh          #+#    #+#             */
/*   Updated: 2022/04/23 21:36:38 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB {
	public:
		HumanB(std::string init_name);
		void		setWeapon(Weapon& newWeapon);
		void		attack(void);
	private:
		std::string	name;
		Weapon		*weapon;
};

#endif