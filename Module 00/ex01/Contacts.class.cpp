/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:42:56 by nprljic           #+#    #+#             */
/*   Updated: 2023/02/02 22:52:57 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.class.hpp"

Contact::Contact( void ){
    
    return ;
}

void Contact::MakeContact( std::string Contacts[5] )
{
    std::string msg[] = {"First name:", "Last name:", "Nickname:", "Phone number:", "Darkest secret:"};
    
    for(int i = 0; i < 5; i++)
    {
        std::cout << msg[i] << std::endl;
        std::cin >> this->entry[i];
        Contacts[i] = this->entry[i];
    }
    return ;
}

void Contact::ShowOne( std::string Contacts[5] ){

    if(Contacts != NULL)
    {
        for(int i = 0; i < 5; i++)
            std::cout << Contacts[i] << std::endl;
    }
    return ;
}

void add_space(std::string Contacts)
{
    size_t len;
    std::string tmp;

    tmp = Contacts;
    len = 10 - tmp.size();
    for(int i = 0; i < len; i++)
        tmp = ' ' + tmp;
    std::cout << "|" << tmp;
    return ;
}

void add_dot(std::string Contacts)
{
    std::string tmp;
                
    tmp = Contacts.substr(0, 9);
    std::cout << "|" << tmp + '.';
    return ;
}

void Contact::ShowContact( std::string Contacts[5] ){

    if(Contacts == NULL)
        return ;
    for(int i = 0; i < 3; i++)
    {   
        if(Contacts[i].size() > 10)
            add_dot(Contacts[i]);
        else if(Contacts[i].size() == 10)
            std::cout << "|" << Contacts[i];
        else
            add_space(Contacts[i]);
    }
    std::cout << std::endl;
    return ;
}