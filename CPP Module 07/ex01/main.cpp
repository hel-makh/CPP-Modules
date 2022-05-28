/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:01:52 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/28 17:08:06 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template <typename T>
void	funcIncrement(T & elem) {
	elem ++;
}

template <typename T>
void	funcDecrement(T & elem) {
	elem --;
}

template <typename T>
void	funcPrint(T & elem) {
	std::cout << elem << std::endl;
}

int	main(void) {
	int	arr[] = {1, 2, 3, 4, 5};
	int size = sizeof(arr) / sizeof(arr[0]);

	funcIter<int>(arr, size, funcPrint<int>);
	std::cout << std::endl;
	funcIter<int>(arr, size, funcIncrement<int>);
	funcIter<int>(arr, size, funcPrint<int>);
	std::cout << std::endl;
	funcIter<int>(arr, size, funcDecrement<int>);
	funcIter<int>(arr, size, funcPrint<int>);
	std::cout << std::endl;
}
