/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:49:59 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/12 13:33:44 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include <iostream>
# include <string>

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat :	public AAnimal	{
	private:
		Brain	*_brain;
	
	public:
		Cat(void);
		Cat(std::string const type);
		Cat(Cat const & rhs);
		~Cat(void);

		Cat &	operator=(Cat const & rhs);

		Brain *	getBrain(void) const;
		void	setBrain(Brain *brain);
		
		void	makeSound(void) const;
};

#endif