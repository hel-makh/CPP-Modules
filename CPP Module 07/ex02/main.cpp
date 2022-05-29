/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:14:25 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/29 14:59:12 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

class Test {
	private:
		int	_x;
		int	_y;
		int	_z;

	public:
		Test(void) : _x(1337), _y(42), _z(21) {}
		~Test(void) {}

		Test &	operator=(Test const & rhs) {
			this->_x = rhs.getX();
			this->_y = rhs.getY();
			this->_z = rhs.getZ();

			return (*this);
		}

		int	getX(void) const { return this->_x; }
		int	getY(void) const { return this->_y; }
		int	getZ(void) const { return this->_z; }
};

std::ostream &	operator<<(std::ostream & o, Test const & test) {
	o << "x: " << test.getX() << " - ";
	o << "y: " << test.getY() << " - ";
	o << "z: " << test.getZ() << std::endl;

	return (o);
}

int	main(void) {
	Array<Test>	arr(5);
	
	std::cout << "size: " << arr.size() << std::endl;
	try {
		for (unsigned int i = 0; i < arr.size() + 1; i++) {
			std::cout << "arr[" << i << "]: " << arr[i];
		}
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	
	Array<Test>	arr2(arr);
	
	std::cout << "size: " << arr2.size() << std::endl;
	try {
		for (unsigned int i = 0; i < arr2.size() + 1; i++) {
			std::cout << "arr2[" << i << "]: " << arr2[i];
		}
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return (EXIT_SUCCESS);
}
