/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:10:39 by nprljic           #+#    #+#             */
/*   Updated: 2023/04/01 14:01:38 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.class.hpp"
#include <limits.h>

PhoneBook::PhoneBook( void )
{
    this->i = 0;
    this->count = 0;
    return ;
}

void PhoneBook::add( Contact *Contact )
{
    if(this->i == 8)
        this->i = 0;
    Contact->MakeContact(this->_Contacts[this->i]);
    this->i++;
    if(this->count < 8)
        this->count++;
    return ;
}

int input_test( std::string input, int i )
{
    if (input[0] < '1')
        std::cout << "!!! Index must be bigger than 0 !!! : ";
    else if ( input[0] > i + '0' && i < 9)
        std::cout << "!!! This Index doesn't exist but you can add it !!! : ";
    else if( input.size() > 1 )
        std::cout << "!!! Index can't be bigger than 8 !!! : ";
    else
        return (0);
    return (1);
}

void PhoneBook::search_menu( Contact *Contact )
{
    std::string input;

    while(true)
    {
        std::cout << std::endl << "   ||   Type return to go back.   ||";
        std::cout << std::endl << "   ||   Type in the index :  ";
        std::cin >> input;
        if(std::cin.eof() || input == "return")
            return ;
        std::cout << std::endl;
        if(input_test( input, i ))
            std::cout << input << std::endl;
        else
            Contact->ShowOne(this->_Contacts[(input[0] - 48) - 1]);
    }
    return ;
}

void PhoneBook::search_contacts( Contact *Contact )
{
    if(this->i < 1)
    {
        std::cout << "  Warning ! || Phonebook is empty <.< ||" << std::endl << std::endl;
        return ;
    }
    for(int len = 0; len < this->count; len++)
    {
        std::cout << "         " << len + 1;
        Contact->ShowContact(this->_Contacts[len]);
    }
    search_menu(Contact);
    return ;
}
