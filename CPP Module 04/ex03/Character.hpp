/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:49:24 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/15 12:03:46 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

# include "ICharacter.hpp"

# define MAXSLOTS	4

class Character : public ICharacter {
	private:
		std::string	_name;
		AMateria *	_inventory[MAXSLOTS];
		AMateria **	_dropped;
		
		int		droppedSize(void) const;
		void	storeMateria(AMateria & Object);
	
	public:
		Character(std::string const name);
		Character(Character const & rhs);
		~Character(void);

		Character &	operator=(Character const & rhs);
		
		std::string const &	getName(void) const;
		void				setName(std::string const name);
		
		void	equip(AMateria * m);
		void	unequip(int idx);
		void	use(int idx, ICharacter & target);
};

#endif