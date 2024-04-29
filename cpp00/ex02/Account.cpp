/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:19:40 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/04/29 14:14:51 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

Account::Account( int initial_deposit )
{
	this->_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts += 1;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';'
			<< "amount:" << this->_amount << ';'
			<< "created" << std::endl;
	return ;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';'
			<< "amount:" << this->_amount << ';'
			<< "closed" << std::endl;
	return ;
}

void	Account::_displayTimestamp( void )
{
	time_t now = time(0);
	tm 		*t = localtime(&now);

	std::cout << '[' << 1900 + t->tm_year;
	if ((1 + t->tm_mon) < 10)
		std::cout << "0";
	std::cout << 1 + t->tm_mon;
	if ((1 + t->tm_mday) < 10)
		std::cout << "0";
	std::cout << t->tm_mday;
	std::cout << '_';
	if ((0 + t->tm_hour) < 10)
		std::cout << "0";
	std::cout << 0 + t->tm_hour;
	if ((0 + t->tm_min) < 10)
		std::cout << "0";
	std::cout << 0 + t->tm_min;
	if ((t->tm_sec) < 10)
		std::cout << "0";
	std::cout << t->tm_sec << "] ";

	return ;
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ';'
		<< "total:" << Account::_totalAmount << ';'
		<< "deposits:" << Account::_totalNbDeposits << ';'
		<< "withdrawals:" << Account::_totalNbWithdrawals
		<< std::endl;
	return ;
}

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';'
			<< "p_amount:" << this->_amount << ';'
			<< "deposit:" << deposit << ';';

	if (deposit > 0)
	{
		this->_amount += deposit;
		Account::_totalAmount += deposit;
		this->_nbDeposits += 1;
		Account::_totalNbDeposits += 1;
	}
	std::cout << "amount:" << this->_amount << ';'
			<< "nb_deposits:" << this->_nbDeposits
 			<< std::endl;
	return ;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex  << ';'
			<< "p_amount:" << this->_amount << ';';

	if (withdrawal > this->_amount)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	this->_nbWithdrawals += 1;
	Account::_totalNbWithdrawals += 1;

	std::cout << "withdrawal:" << withdrawal << ';'
			<< "amount:"  << this->_amount << ';'
			<< "nb_withdrawals:" << this->_nbWithdrawals
			<< std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';'
			<< "amount:" << this->_amount << ';'
			<< "deposits:" << this->_nbDeposits << ';'
			<< "withdrawals:" << this->_nbWithdrawals
 			<< std::endl;
	return ;
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// ************************************************************************** //
//                               Numbers in Blue                              //
// ************************************************************************** //

/*Account::Account( int initial_deposit )
{
	this->_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts += 1;
	Account::_displayTimestamp();
	std::cout << "index:" << "\033[1;34m" << this->_accountIndex << "\033[0m" << ';'
			<< "amount:" << "\033[1;34m" << this->_amount << "\033[0m" << ';'
			<< "created" << std::endl;
	return ;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << "index:" << "\033[1;34m" << this->_accountIndex << "\033[0m" << ';'
			<< "amount:" << "\033[1;34m" << this->_amount << "\033[0m" << ';'
			<< "closed" << std::endl;
	return ;
}

void	Account::_displayTimestamp( void )
{
	time_t now = time(0);
	tm 		*t = localtime(&now);

	std::cout << '[' << 1900 + t->tm_year << 1 + t->tm_mon << t->tm_mday
		<< '_' << 0+t->tm_hour << 0+t->tm_min << t->tm_sec << "] ";

	return ;
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << "\033[1;34m" << Account::_nbAccounts << "\033[0m" << ';'
		<< "total:" << "\033[1;34m" << Account::_totalAmount << "\033[0m" << ';'
		<< "deposits:" << "\033[1;34m" << Account::_totalNbDeposits << "\033[0m" << ';'
		<< "withdrawals:" << "\033[1;34m" << Account::_totalNbWithdrawals << "\033[0m"
		<< std::endl;
	return ;
}

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << "index:" << "\033[1;34m" << this->_accountIndex << "\033[0m" << ';'
			<< "p_amount:" << "\033[1;34m" << this->_amount << "\033[0m" << ';'
			<< "deposit:" << "\033[1;34m" << deposit << "\033[0m" << ';';

	if (deposit > 0)
	{
		this->_amount += deposit;
		Account::_totalAmount += deposit;
		this->_nbDeposits += 1;
		Account::_totalNbDeposits += 1;
	}
	std::cout << "amount:" << "\033[1;34m" << this->_amount << "\033[0m" << ';'
			<< "nb_deposits:" << "\033[1;34m" << this->_nbDeposits << "\033[0m"
 			<< std::endl;
	return ;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "index:" << "\033[1;34m" << this->_accountIndex << "\033[0m" << ';'
			<< "p_amount:" << "\033[1;34m" << this->_amount << "\033[0m" << ';';

	if (withdrawal > this->_amount)
	{
		std::cout << "withdrawal: refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	this->_nbWithdrawals += 1;
	Account::_totalNbWithdrawals += 1;

	std::cout << "withdrawal:" << "\033[1;34m" << withdrawal << "\033[0m" << ';'
			<< "amount:" << "\033[1;34m" << this->_amount << "\033[0m" << ';'
			<< "nb_withdrawals:" << "\033[1;34m" << this->_nbWithdrawals << "\033[0m"
			<< std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << "\033[1;34m" << this->_accountIndex << "\033[0m" << ';'
			<< "amount:" << "\033[1;34m" << this->_amount << "\033[0m" << ';'
			<< "deposits:" << "\033[1;34m" << this->_nbDeposits << "\033[0m" << ';'
			<< "withdrawals:" << "\033[1;34m" << this->_nbWithdrawals << "\033[0m"
 			<< std::endl;
	return ;
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
*/