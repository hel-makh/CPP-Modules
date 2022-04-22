/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 23:44:29 by hel-makh          #+#    #+#             */
/*   Updated: 2022/04/22 02:04:03 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int	Account::t::_nbAccounts = 0;
int	Account::t::_totalAmount = 0;
int	Account::t::_totalNbDeposits = 0;
int	Account::t::_totalNbWithdrawals = 0;

int	Account::t::getNbAccounts(void) {
	return (Account::t::_nbAccounts);
}

int	Account::t::getTotalAmount(void) {
	return (Account::t::_totalAmount);
}

int	Account::t::getNbDeposits(void) {
	return (Account::t::_totalNbDeposits);
}

int	Account::t::getNbWithdrawals(void) {
	return (Account::t::_totalNbWithdrawals);
}

void	Account::t::displayAccountsInfos(void) {
	Account::t::_displayTimestamp();
	std::cout << " ";
	std::cout << "accounts:" << Account::t::getNbAccounts() << ";";
	std::cout << "total:" << Account::t::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::t::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::t::getNbWithdrawals() << std::endl;
}

Account::t::Account(int initial_deposit) : _accountIndex(Account::t::getNbAccounts()),
										_amount(initial_deposit),
										_nbDeposits(0),
										_nbWithdrawals(0) {
	Account::t::_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";created" << std::endl;
	Account::t::_nbAccounts ++;
	Account::t::_totalAmount += initial_deposit;
}

Account::t::Account(void) : _accountIndex(Account::t::getNbAccounts()),
										_amount(0),
										_nbDeposits(0),
										_nbWithdrawals(0) {
	Account::t::_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";created" << std::endl;
	Account::t::_nbAccounts ++;
}

Account::t::~Account(void) {
	Account::t::_nbAccounts --;
	Account::t::_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";closed" << std::endl;
}

void	Account::t::makeDeposit(int deposit) {
	Account::t::_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->checkAmount() << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	std::cout << "amount:" << this->checkAmount() << ";";
	this->_nbDeposits ++;
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
	Account::t::_totalAmount += deposit;
	Account::t::_totalNbDeposits ++;
}

bool	Account::t::makeWithdrawal(int withdrawal) {
	Account::t::_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->checkAmount() << ";";
	std::cout << "withdrawal:";
	if (this->checkAmount() - withdrawal < 0)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal << ";";
	this->_amount -= withdrawal;
	std::cout << "amount:" << this->checkAmount() << ";";
	this->_nbWithdrawals ++;
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	Account::t::_totalAmount -= withdrawal;
	Account::t::_totalNbWithdrawals ++;
	return (true);
}

int	Account::t::checkAmount(void) const {
	return (this->_amount);
}

void	Account::t::displayStatus(void) const {
	Account::t::_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::t::_displayTimestamp(void) {
	time_t now = time(0);

	tm *ltm = localtime(&now);
	std::cout << "[";
	std::cout << ltm->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << ltm->tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2) << ltm->tm_mday;
	std::cout << "_";
	std::cout << std::setfill('0') << std::setw(2) << ltm->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << ltm->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << ltm->tm_sec;
	std::cout << "]";
}
