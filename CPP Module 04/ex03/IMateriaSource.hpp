/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:59:00 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/15 10:09:20 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_H
# define IMATERIASOURCE_H

# include "AMateria.hpp"

class IMateriaSource {
	public:
		virtual	~IMateriaSource(void) {}
		
		virtual void		learnMateria(AMateria*) = 0;
		virtual AMateria *	createMateria(std::string const & type) = 0;
};

#endif