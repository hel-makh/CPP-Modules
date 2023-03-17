/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:01:27 by hel-makh          #+#    #+#             */
/*   Updated: 2023/03/17 21:10:32 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	RPN(const char * expression) {
	std::stack<int>	operands;
	std::string	str(expression);
	std::string::iterator it = str.begin();
	
	while (it != str.end()) {
		if (*it != ' ') {
			if (std::isdigit(*it)) {
				operands.push(*it - 48);
			} else {
				if ((*it != '+' && *it != '-' && *it != '/' && *it != '*') || operands.size() < 2) {
					throw std::runtime_error("Error");
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
					if (op == 0) {
						throw std::runtime_error("Error");
					}
					op = operands.top() / op;
				}
				else if (*it == '*') {
					op = operands.top() * op;
				}
				operands.pop();
				operands.push(op);
			}
		}
		++it;
	}
	
	if (operands.size() != 1) {
		throw std::runtime_error("Error");
	}
	return (operands.top());
}
