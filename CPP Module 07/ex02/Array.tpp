/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:29:24 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/28 19:24:11 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <stdexcept>

template <typename T>
class Array {
	private:
		T				*_arr;
		unsigned int	_size;
	
	public:
		Array(void) : _size(0) {
			this->_arr = nullptr;
		}

		Array(unsigned int size) : _size(size) {
			this->_arr = new T[size];
		}

		Array(Array<T> const & rhs) {
			if (this != &rhs) {
				this->_size = rhs.size();
				this->_arr = new T[this->_size];
				for (unsigned int i = 0; i < this->_size; i ++) {
					this->_arr[i] = rhs[i];
				}
			}
		}

		~Array(void) {
			if (this->_size > 0)
				delete [] this->_arr;
		}

		Array<T> &	operator=(Array<T> const & rhs) {
			if (this != &rhs) {
				this->~Array();
				new (this) Array(rhs);
			}
			return (*this);
		}

		T &			operator[](unsigned int index) const {
			if (index >= 0 && index < this->size())
				return (this->_arr[index]);
			throw std::out_of_range("out of bounds.");
		}

		unsigned int	size(void) const {
			return (this->_size);
		}
};
