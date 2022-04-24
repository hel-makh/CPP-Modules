/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:59:22 by hel-makh          #+#    #+#             */
/*   Updated: 2022/04/24 17:21:49 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA {
	public:
		HumanA(std::string init_name, Weapon& init_weapon);
		void		attack(void);
	private:
		std::string	name;
		Weapon&		weapon;
};

#endif