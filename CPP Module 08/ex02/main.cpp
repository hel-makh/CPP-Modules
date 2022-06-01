/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:56:03 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/01 13:49:08 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	mstack.push(1);
	mstack.push(2);

	std::cout << "mstack.top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "mstack.size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(4);
	mstack.push(5);
	mstack.push(6);

	MutantStack<int>::iterator mbegin = mstack.begin();
	MutantStack<int>::iterator mend = mstack.end();

	++mbegin;
	--mbegin;
	
	std::cout << "mstack iteration: " << std::endl;
	while (mbegin != mend)
		std::cout << *mbegin++ << std::endl;

	MutantStack<int>::reverse_iterator mrbegin = mstack.rbegin();
	MutantStack<int>::reverse_iterator mrend = mstack.rend();

	++mrbegin;
	--mrbegin;
	
	std::cout << "mstack reverse iteration: " << std::endl;
	while (mrbegin != mrend)
		std::cout << *mrbegin++ << std::endl;

	/*** Copy construction & assignement ***/

	MutantStack<int> mstack2(mstack);
	mstack = mstack2;

	mbegin = mstack.begin();
	mend = mstack.end();

	++mbegin;
	--mbegin;
	
	std::cout << "mstack iteration 2: " << std::endl;
	while (mbegin != mend)
		std::cout << *mbegin++ << std::endl;

	mrbegin = mstack.rbegin();
	mrend = mstack.rend();

	++mrbegin;
	--mrbegin;
	
	std::cout << "mstack reverse iteration 2: " << std::endl;
	while (mrbegin != mrend)
		std::cout << *mrbegin++ << std::endl;

	/*** Copy construction to std::stack<int> ***/
	
	std::stack<int> stack(mstack);

	stack.push(7);
	stack.push(8);

	std::cout << "stack.top: " << stack.top() << std::endl;
	std::cout << "stack.size: " << stack.size() << std::endl;

	return (EXIT_SUCCESS);
}
