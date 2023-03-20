/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:30:00 by hel-makh          #+#    #+#             */
/*   Updated: 2023/03/17 17:13:04 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/***********************************[ Utils ]**********************************/

static bool	isNumeric(std::string const & str) {
	std::string::const_iterator it = str.begin();
	
	while (it != str.end() && std::isdigit(*it))
		++it;
	return (!str.empty() && it == str.end());
}

std::vector<int>	createVector(char **numbers, int size) {
	std::vector<int>	vec;

	for (int i = 0; i < size; i++) {
		std::stringstream	ss;
		int nb;

		if (!isNumeric(std::string(numbers[i]))) {
			throw std::runtime_error(std::string("Error: only positive integers are allowed => ") + std::string(numbers[i]));
		}
		
		ss << numbers[i];
		ss >> nb;
		vec.push_back(nb);
	}

	return (vec);
}

std::list<int>	createList(char **numbers, int size) {
	std::list<int>	lst;

	for (int i = 0; i < size; i++) {
		std::stringstream	ss;
		int nb;

		if (!isNumeric(std::string(numbers[i]))) {
			throw std::runtime_error(std::string("Error: only positive integers are allowed => ") + std::string(numbers[i]));
		}
		
		ss << numbers[i];
		ss >> nb;
		lst.push_back(nb);
	}

	return (lst);
}

void	printVector(std::vector<int> vec, std::string str) {
	std::vector<int>::iterator it = vec.begin();
	std::cout << str << ":\t";
	for (; it != vec.end(); ++it) {
		std::cout << *it << (it + 1 == vec.end() ? "" : " ");
	}
	std::cout << "\n";
}

/**********************************[ Vector ]**********************************/

void	vectorInsertionSort(std::vector<int> & vec, int p, int r) {
	if (p == r) return ;
	std::vector<int>::iterator	it;
	for (it = vec.begin() + p; it != vec.begin() + r + 1; ++it) {
		std::vector<int>::iterator	it2;
		for (it2 = it; it2 != vec.begin() + p && *it2 < *(it2 - 1); --it2) {
			std::iter_swap(it2, it2 - 1);
		}
	}
}

void	vectorMerge(std::vector<int> & vec, int p, int q, int r) {
	std::vector<int> subvec1;
	std::vector<int> subvec2;

	subvec1.insert(subvec1.begin(), vec.begin() + p, vec.begin() + q + 1);
	subvec2.insert(subvec2.begin(), vec.begin() + q + 1, vec.begin() + r + 1);
	
	std::vector<int>::iterator	it = vec.begin() + p;
	std::vector<int>::iterator	it1 = subvec1.begin();
	std::vector<int>::iterator	it2 = subvec2.begin();

	while (it1 != subvec1.end() && it2 != subvec2.end()) {
		if (*it1 <= *it2) {
			*it = *it1;
			++it1;
		} else {
			*it = *it2;
			++it2;
		}
		++it;
	}

	while (it1 != subvec1.end()) {
		*it = *it1;
		++it1;
		++it;
	}

	while (it2 != subvec2.end()) {
		*it = *it2;
		++it2;
		++it;
	}
}

void	vectorSort(std::vector<int> & vec, int p, int r) {
	if (r - p > K) {
		int	q = (p + r) / 2;
		vectorSort(vec, p, q);
		vectorSort(vec, q + 1, r);
		vectorMerge(vec, p, q, r);
	} else {
		vectorInsertionSort(vec, p, r);
	}
}

/***********************************[ List ]***********************************/

void	listInsertionSort(std::list<int> & lst, int p, int r) {
	if (p == r) return ;
	std::list<int>::iterator	it;
	for (it = std::next(lst.begin(), p); it != std::next(lst.begin(), r + 1); ++it) {
		std::list<int>::iterator	it2;
		for (it2 = it; it2 != std::next(lst.begin(), p) && *it2 < *std::next(it2, - 1); --it2) {
			std::iter_swap(it2, std::next(it2, - 1));
		}
	}
}

void	listMerge(std::list<int> & lst, int p, int q, int r) {
	std::list<int> sublst1;
	std::list<int> sublst2;

	sublst1.insert(sublst1.begin(), std::next(lst.begin(), p), std::next(lst.begin(), q + 1));
	sublst2.insert(sublst2.begin(), std::next(lst.begin(), q + 1), std::next(lst.begin(), r + 1));
	
	std::list<int>::iterator	it = std::next(lst.begin(), p);
	std::list<int>::iterator	it1 = sublst1.begin();
	std::list<int>::iterator	it2 = sublst2.begin();

	while (it1 != sublst1.end() && it2 != sublst2.end()) {
		if (*it1 <= *it2) {
			*it = *it1;
			++it1;
		} else {
			*it = *it2;
			++it2;
		}
		++it;
	}

	while (it1 != sublst1.end()) {
		*it = *it1;
		++it1;
		++it;
	}

	while (it2 != sublst2.end()) {
		*it = *it2;
		++it2;
		++it;
	}
}

void	listSort(std::list<int> & lst, int p, int r) {
	if (r - p > K) {
		int	q = (p + r) / 2;
		listSort(lst, p, q);
		listSort(lst, q + 1, r);
		listMerge(lst, p, q, r);
	} else {
		listInsertionSort(lst, p, r);
	}
}

/*********************************[ PmergeMe ]*********************************/

void	PmergeMe(char **numbers, int size) {
	std::vector<int>	vec;
	std::list<int>		lst;

	clock_t	begin, end;
	double	elapsed_secs;
	
	vec = createVector(numbers, size);
	printVector(vec, "Before");
	
	begin = clock();
	vec = createVector(numbers, size);
	vectorSort(vec, 0, vec.size() - 1);
	end = clock();

	printVector(vec, "After");
	
	elapsed_secs = (double(end - begin) / CLOCKS_PER_SEC) * 1000000;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector :\t" << std::fixed << elapsed_secs << " us" << std::endl;

	begin = clock();
	lst = createList(numbers, size);
	listSort(lst, 0, lst.size() - 1);
	end = clock();

	elapsed_secs = (double(end - begin) / CLOCKS_PER_SEC) * 1000000;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::list   :\t" << std::fixed << elapsed_secs << " us" << std::endl;
}
