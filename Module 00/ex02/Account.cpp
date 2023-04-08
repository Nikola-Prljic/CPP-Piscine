/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:34:33 by nprljic           #+#    #+#             */
/*   Updated: 2023/02/03 20:51:08 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;

int	Account::_totalNbWithdrawals = 0;

int	Account::_totalNbDeposits = 0;

int	Account::_totalAmount = 0;

Account::Account(int initial_deposit )
{    
	_nbWithdrawals = 0;
	_nbDeposits = 0;
    _accountIndex = getNbAccounts();
	_amount = initial_deposit;
    _totalAmount += initial_deposit;
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << checkAmount();
    std::cout << ";created" << std::endl;
    Account::_nbAccounts++;
    return ;
}

Account::~Account( void )
{
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << checkAmount();
    std::cout << ";closed" << std::endl;
    return ;
}

void	Account::_displayTimestamp(void)
{
	time_t	now;

	now = time(NULL);
	std::cout << std::put_time(localtime(&now), "[%Y%m%d_%H%M%S] ");
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return(Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return(Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return(Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount();
    std::cout << ";deposits:" << getNbDeposits() << ";withdrawals:";
    std::cout << getNbWithdrawals() << std::endl;
    return ;
}

int Account::checkAmount( void ) const
{
    return (this->_amount);
}

void Account::displayStatus( void ) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount();
    std::cout << ";deposits:" << this->_nbDeposits << ";withdrawals:" <<this->_nbWithdrawals << std::endl;
    return ;
}

void Account::makeDeposit( int deposit )
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->checkAmount();
    this->_nbDeposits++;
    this->_amount += deposit;
    std::cout << ";deposit:" << deposit << ";amount:" << this->_amount;
    std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
    Account::_totalNbDeposits++;
    Account::_totalAmount += deposit;
    return ;
}

bool Account::makeWithdrawal( int withdrawal )
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->checkAmount();
    std::cout << ";withdrawal:";
    if(this->_amount < withdrawal)
    {
        std::cout << "refused" << std::endl;
        return (false);
    }
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    std::cout << withdrawal << ";amount:" << this->_amount;
    std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    Account::_totalNbWithdrawals++;
    Account::_totalAmount -= withdrawal;
    return (true);
}