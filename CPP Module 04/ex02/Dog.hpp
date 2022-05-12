/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:48:59 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/12 13:33:47 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include <iostream>
# include <string>

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog :	public AAnimal	{
	private:
		Brain	*_brain;
	
	public:
		Dog(void);
		Dog(std::string const type);
		Dog(Dog const & rhs);
		~Dog(void);

		Dog &	operator=(Dog const & rhs);

		Brain *	getBrain(void) const;
		void	setBrain(Brain *brain);

		void	makeSound(void) const;
};

#endif