/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-18 13:21:14 by root              #+#    #+#             */
/*   Updated: 2025-06-18 13:21:14 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

// static member variables 
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// static member function (getters)
int Account::getNbAccounts() { return _nbAccounts; }

int Account::getTotalAmount() { return _totalAmount; }

int Account::getNbDeposits() { return _totalNbDeposits; }

int Account::getNbWithdrawals() { return _totalNbWithdrawals; }

void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
			  << ";total:" << getTotalAmount()
			  << ";deposits:" << getNbDeposits()
			  << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

// Constructor with initial deposit
Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	_nbAccounts++;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
			  << ";amount:" << _amount
			  << ";created" << std::endl;
}

// Destructor
Account::~Account() {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
			  << ";amount:" << _amount
			  << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
			  << ";p_amount:" << _amount
			  << ";deposit:" << deposit;

	// individual increment   
	_amount += deposit;
	_nbDeposits++;

	// overall increment 
	_totalAmount += deposit;
	_totalNbDeposits++;

	std::cout << ";amount:" << _amount 
			  << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
			  << ";p_amount:" << _amount;
	
			  if (_amount < withdrawal) {
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}

	_amount -= withdrawal;
	_nbWithdrawals++;

	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	std::cout << ";withdrawal:" << withdrawal
			  << ";amount:" << _amount 
			  << ";nb_withdrawals:" << _nbWithdrawals << std::endl;

	return true;
}

int Account::checkAmount() const {
	return _amount;
}

void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp() {
	// std::time(nullptr) returns the current time
	std::time_t now = std::time(0);
	// converts time_t into local time structure
	// std::tm holds broken-down values like year, month, day, hour
	std::tm *cur_time = std::localtime(&now);
	
	char buffer[17];
	// format date and time into a string
	std::strftime(buffer, sizeof(buffer), "[%y%m%d_%H%M%S]", cur_time);
	std::cout << buffer << " ";
}
