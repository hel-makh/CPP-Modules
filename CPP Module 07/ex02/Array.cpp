/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:37:27 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/28 19:19:46 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/*************************[ Constructors/Destructors ]*************************/

template <typename T>
Array<T>::Array(void) : _size(0) {
	this->_arr = nullptr;
}

template <typename T>
Array<T>::Array(unsigned int size) : _size(size) {
	this->_arr = new T[size];
}

template <typename T>
Array<T>::Array(Array<T> const & rhs) {
	if (this != &rhs) {
		this->_size = rhs.size();
		this->_arr = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i ++) {
			this->_arr[i] = rhs[i];
		}
	}
}

template <typename T>
Array<T>::~Array(void) {
	delete [] this->_arr;
}

/****************************[ Operators overload ]****************************/

template <typename T>
Array<T> &	Array<T>::operator=(Array<T> const & rhs) {
	if (this != &rhs) {
		this->~Array();
		new (this) Array(rhs);
	}
	return (*this);
}

template <typename T>
T &	Array<T>::operator[](unsigned int index) const {
	if (index >= 0 && index < this->size())
		return (this->_arr[index]);
	throw std::out_of_range("out of bounds.");
}

/*****************************[ Member Functions ]*****************************/

template <typename T>
unsigned int	Array<T>::size(void) const {
	return (this->_size);
}
