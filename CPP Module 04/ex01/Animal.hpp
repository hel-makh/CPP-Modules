/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:19:54 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/10 18:30:10 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>
# include <string>

class Animal {
	protected:
		std::string	_type;
	
	public:
		Animal(void);
		Animal(std::string const type);
		Animal(Animal const & rhs);
		virtual	~Animal(void);

		Animal &	operator=(Animal const & rhs);

		std::string	getType(void) const;
		void		setType(std::string const type);
		
		virtual void	makeSound(void) const;
};

#endif