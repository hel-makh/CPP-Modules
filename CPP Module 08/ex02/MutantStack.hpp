/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:30:08 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/01 13:49:03 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack(void) { return ; }
		MutantStack(MutantStack const & rhs) { *this = rhs; }
		~MutantStack(void) { return ; }

		MutantStack &	operator=(MutantStack const & rhs) {
			if (this != &rhs) {
				std::stack<T>::operator=(rhs);
			}
			return (*this);
		}
		
		typedef typename std::stack<T>::container_type::iterator
				iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator
				reverse_iterator;

		iterator	begin(void) { return (this->c.begin()); }
		iterator	end(void) { return (this->c.end()); }

		reverse_iterator	rbegin(void) { return (this->c.rbegin()); }
		reverse_iterator	rend(void) { return (this->c.rend()); }
};

#endif