/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:51:35 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/24 16:17:38 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Classes.hpp"
#include "Identify.hpp"

int	main(void) {
	Base *	b;

	b = generate();
	identify(b);
	identify(*b);

	delete b;
	
	return (EXIT_SUCCESS);
}
