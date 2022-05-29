/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:01:52 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/29 14:43:02 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

class Test {
	public:
		Test(void) : _n(42) { return; } 
		int	get(void) const { return this->_n; }
		
	private:
		int	_n; 
};

std::ostream &	operator<<(std::ostream & o, Test const & rhs) {
	o << rhs.get();
	return o;
}

template <typename T>
void	funcPrint(T const & elem) {
	std::cout << elem << std::endl;
}

int	main(void) {
	int	arr[] = {1, 2, 3, 4, 5};
	int size = sizeof(arr) / sizeof(arr[0]);
	Test arr2[5];

	iter<int>(arr, size, funcPrint<int>);
	std::cout << std::endl;
	iter<Test>(arr2, 5, funcPrint<Test>);
}
