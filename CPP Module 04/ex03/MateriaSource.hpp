/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:59:00 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/15 11:55:50 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# include "IMateriaSource.hpp"

# define MAXSLOTS	4

class MateriaSource : public IMateriaSource {
	private:
		AMateria *	_inventory[MAXSLOTS];
	
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & rhs);
		~MateriaSource(void);

		MateriaSource &	operator=(MateriaSource const & rhs);
		
		void		learnMateria(AMateria * m);
		AMateria *	createMateria(std::string const & type);
};

#endif