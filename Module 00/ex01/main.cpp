/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:38:08 by nprljic           #+#    #+#             */
/*   Updated: 2023/04/01 14:03:13 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "Contacts.class.hpp"

void add_and_search( std::string menu, PhoneBook *PhoneBook, Contact *Contact)
{
    if( menu == "EXIT" )
        return ;
    std::cout << std::endl;
    if( menu == "ADD")
        PhoneBook->add(Contact);
    else if( menu == "SEARCH")
        PhoneBook->search_contacts(Contact);
    return ;
}

int main( void )
{
    PhoneBook   PhoneBook;
    Contact     Contact;
    std::string menu;

    while( menu != "EXIT" )
    {
        if (std::cin.eof())
            return (0);
        std::cout << ">> USE: ADD || SEARCH || EXIT" << std::endl;
        std::cin >> menu;
        add_and_search(menu, &PhoneBook, &Contact);
    }
    return (0);
}