/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:54:10 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/09 16:21:04 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include <iostream>
# include <string>

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap :	public ScavTrap,
					public FragTrap {
	private:
		std::string	_name;
		
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const & rhs);
		~DiamondTrap(void);
		
		DiamondTrap &	operator=(DiamondTrap const & rhs);

		std::string	getName(void) const;
		void		setName(std::string name);
		
		void	whoAmI(void);
};

#endif