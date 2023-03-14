/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:01:27 by hel-makh          #+#    #+#             */
/*   Updated: 2023/03/15 00:10:22 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	RPN(const char * expression) {
	std::stack<int>	operands;
	std::string	str(expression);
	std::string::iterator it = str.begin();
	int	error = 0;
	
	while (it != str.end()) {
		if (*it != ' ') {
			if (std::isdigit(*it)) {
				operands.push(*it - 48);
				error = 1;
			} else {
				if (operands.size() != 2 || (*it != '+' && *it != '-' && *it != '/' && *it != '*')) {
					throw std::runtime_error("");
				}
				int op = operands.top();
				operands.pop();
				if (*it == '+') {
					op = operands.top() + op;
				}
				else if (*it == '-') {
					op = operands.top() - op;
				}
				else if (*it == '/') {
					op = operands.top() / op;
				}
				else if (*it == '*') {
					op = operands.top() * op;
				}
				operands.pop();
				operands.push(op);
				error = 0;
			}
		}
		++it;
	}
	
	if (error) {
		throw std::runtime_error("");
	}
	return (operands.top());
}
