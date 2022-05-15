/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:46:21 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/14 16:27:30 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H

# include <string>

class ICharacter;

class AMateria {
	protected:
		std::string	_type;
		
	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const & rhs);
		virtual	~AMateria(void) {}

		AMateria &	operator=(AMateria const & rhs);
		
		std::string const &	getType(void) const;
		void				setType(std::string const & type);
		
		virtual AMateria *	clone(void) const = 0;
		virtual void		use(ICharacter & target);
};

#endif