/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:27:24 by nprljic           #+#    #+#             */
/*   Updated: 2023/03/31 20:12:02 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_CLASS_H
# define CONTACTS_CLASS_H

#include <iostream>
#include "PhoneBook.class.hpp"

class PhoneBook;

class Contact
{
private:

    std::string entry[5];

public:

    Contact( void );
    void MakeContact( std::string Contacts[5] );
    void ShowContact( std::string book[5] );
    void ShowOne( std::string book[5] );

};

#endif