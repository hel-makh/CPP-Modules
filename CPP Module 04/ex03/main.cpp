/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:11:12 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/15 13:07:55 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int	main(void) {
	IMateriaSource *	src = new MateriaSource();
	
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *	me = new Character("me");
	
	AMateria* tmp;
	if ((tmp = src->createMateria("ice")))
		me->equip(tmp);
	if ((tmp = src->createMateria("cure")))
		me->equip(tmp);
	if ((tmp = src->createMateria("ice")))
		me->equip(tmp);
	if ((tmp = src->createMateria("cure")))
		me->equip(tmp);

	ICharacter *	bob = new Character("bob");
	*bob = *me;

	me->use(0, *bob);
	me->use(1, *bob);

	// me->unequip(0);
	me->unequip(1);

	me->use(0, *bob);
	me->use(1, *bob);

	delete me;
	delete bob;
	delete src;
	
	return 0;
}
