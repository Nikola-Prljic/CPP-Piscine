/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:47:16 by nprljic           #+#    #+#             */
/*   Updated: 2023/03/31 20:18:31 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include <iostream>
#include "Contacts.class.hpp"

class Contact;

class PhoneBook
{

private:

    int i;
    std::string _Contacts[8][5];
    int         count;
    void search_menu( Contact *Contact );

public:

    PhoneBook( void );
    void add( Contact *Contact );
    void search_contacts( Contact *Contact );
    
};

#endif