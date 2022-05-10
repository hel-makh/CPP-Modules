/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:48:59 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/10 18:07:18 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include <iostream>
# include <string>

# include "Animal.hpp"

class Dog :	public Animal {
	public:
		Dog(void);
		Dog(std::string const type);
		Dog(Dog const & rhs);
		~Dog(void);

		Dog &	operator=(Dog const & rhs);
		
		void	makeSound(void) const;
};

#endif