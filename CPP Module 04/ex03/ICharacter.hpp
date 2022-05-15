/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:49:24 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/15 10:22:37 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_H
# define ICHARACTER_H

# include <string>

# include "AMateria.hpp"

class ICharacter {
	public:
		virtual ~ICharacter(void) {}
		
		virtual std::string const &	getName(void) const = 0;
		
		virtual void	equip(AMateria * m) = 0;
		virtual void	unequip(int idx) = 0;
		virtual void	use(int idx, ICharacter & target) = 0;
};

#endif