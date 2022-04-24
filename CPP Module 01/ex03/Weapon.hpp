/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:57:08 by hel-makh          #+#    #+#             */
/*   Updated: 2022/04/24 17:19:17 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <string>

class Weapon {
	public:
		Weapon(void);
		Weapon(std::string init_type);
		const std::string	getType();
		void				setType(std::string newType);
	private:
		std::string 		type;
};

#endif